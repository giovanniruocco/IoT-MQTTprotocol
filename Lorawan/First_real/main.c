/*
 * Copyright (C) 2018 Inria
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

#include <string.h>

#include "xtimer.h"

#include "net/loramac.h"
#include "semtech_loramac.h"

#include "hts221.h"
#include "hts221_params.h"

#include "board.h"

/* Declare globally the loramac descriptor */
static semtech_loramac_t loramac;

/* Declare globally the sensor device descriptor */
static hts221_t hts221;

/* Device and application informations required for OTAA activation */
static const uint8_t deveui[LORAMAC_DEVEUI_LEN] = { 0x00, 0x05, 0x3D, 0x3C, 0xB0, 0x29, 0xBA, 0xC9 };
static const uint8_t appeui[LORAMAC_APPEUI_LEN] = { 0x70, 0xB3, 0xD5, 0x7E, 0xD0, 0x02, 0xD6, 0x26 };
static const uint8_t appkey[LORAMAC_APPKEY_LEN] = { 0x0A, 0x0D, 0xEA, 0x4C, 0x05, 0xB1, 0xA7, 0x44, 0x0A, 0x97, 0x6C, 0x64, 0x6C, 0xDF, 0x49, 0x93 };

static void sender(void)
{
    while (1) {
        char message[320];
        /* sleep 20 secs */
        xtimer_sleep(20);

        /* do some measurements */
        uint16_t id = 1;
        uint16_t humidity = 0;
        int16_t temperature = 0;
        if (hts221_read_humidity(&hts221, &humidity) != HTS221_OK) {
            puts(" -- failed to read humidity!");
        }
        if (hts221_read_temperature(&hts221, &temperature) != HTS221_OK) {
            puts(" -- failed to read temperature!");
        }
        //now we have the real world device's sensor.
        sprintf(message, "{\"humidity\": \"%u.%u\", \"temperature\": \"%u.%u\", \"device\": \"%u\"}",
                (humidity / 10), (humidity % 10),
                (temperature / 10), (temperature % 10), id);
        //what we receive is the int of our measure. So we need to divide it for 10, write a comma and append the decimal part.
        printf("Sending data: %s\n", message);

        /* send the LoRaWAN message */
        uint8_t ret = semtech_loramac_send(&loramac, (uint8_t *)message,
                                           strlen(message));
        if (ret != SEMTECH_LORAMAC_TX_DONE) {
            printf("Cannot send message '%s', ret code: %d\n", message, ret);
        }
    }

    /* this should never be reached */
    return;
}

int main(void)
{
    if (hts221_init(&hts221, &hts221_params[0]) != HTS221_OK) {
        puts("Sensor initialization failed");
        LED3_TOGGLE;
        return 1;
    }
    if (hts221_power_on(&hts221) != HTS221_OK) {
        puts("Sensor initialization power on failed");
        LED3_TOGGLE;
        return 1;
    }
    if (hts221_set_rate(&hts221, hts221.p.rate) != HTS221_OK) {
        puts("Sensor continuous mode setup failed");
        LED3_TOGGLE;
        return 1;
    }

    /* initialize the loramac stack */
    semtech_loramac_init(&loramac);

    /* use a fast datarate so we don't use the physical layer too much */
    semtech_loramac_set_dr(&loramac, 5);

    /* set the LoRaWAN keys */
    semtech_loramac_set_deveui(&loramac, deveui);
    semtech_loramac_set_appeui(&loramac, appeui);
    semtech_loramac_set_appkey(&loramac, appkey);

    /* start the OTAA join procedure */
    puts("Starting join procedure");
    if (semtech_loramac_join(&loramac, LORAMAC_JOIN_OTAA) != SEMTECH_LORAMAC_JOIN_SUCCEEDED) {
        puts("Join procedure failed");
        return 1;
    }

    puts("Join procedure succeeded");

    /* call the sender */
    sender();

    return 0; /* should never be reached */
}
