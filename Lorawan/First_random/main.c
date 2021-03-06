/*
 * Copyright (C) 2018 Inria
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

#include <string.h>
#include <time.h>
#include "xtimer.h"

#include "net/loramac.h"
#include "semtech_loramac.h"

#include "board.h"

/* Declare globally the loramac descriptor */
semtech_loramac_t loramac;

/* Device and application informations required for OTAA activation */
static const uint8_t deveui[LORAMAC_DEVEUI_LEN] = { 0x00, 0x2B, 0x64, 0x0E, 0x0D, 0xD1, 0xD4, 0x91 };
static const uint8_t appeui[LORAMAC_APPEUI_LEN] = { 0x70, 0xB3, 0xD5, 0x7E, 0xD0, 0x02, 0xD6, 0x26 };
static const uint8_t appkey[LORAMAC_APPKEY_LEN] = { 0x53, 0xE5, 0x45, 0x6E, 0xC1, 0xFA, 0xD6, 0x18, 0xCE, 0x1F, 0x90, 0x9A, 0x9B, 0x23, 0x7E, 0xDF };




int main(void)
{
    /* initialize the loramac stack */
    semtech_loramac_init(&loramac);

    /* use a fast datarate so we don't use the physical layer too much */
    semtech_loramac_set_dr(&loramac, 5);

    /* set the LoRaWAN keys */
    semtech_loramac_set_deveui(&loramac, deveui);
    semtech_loramac_set_appeui(&loramac, appeui);
    semtech_loramac_set_appkey(&loramac, appkey);


	srand(time(0));
    //int temperature = random_temp();

    //printf("%d", temperature);


    /* start the OTAA join procedure */
    puts("Starting join procedure");
    if (semtech_loramac_join(&loramac, LORAMAC_JOIN_OTAA) != SEMTECH_LORAMAC_JOIN_SUCCEEDED) {
        puts("Join procedure failed");
        return 1;
    }

    puts("Join procedure succeeded");


    while (1) {

            //I generate random values.
            int temp = ((rand()%99) - 49);
            int hum = (rand()%100);
            int winDir = (rand()%360);
            int winInt = (rand()%100);
            int rain = (rand()%50);
            int id=1;


            //we prepare the values to send in the correct format
            char message[200];
            sprintf(message, "{\"temperature\": \"%d.%d\", \"humidity\": \"%d.%d\", \"windDirection\": \"%d.%d\", \"windIntensity\": \"%d.%d\", \"rainHeight\": \"%d.%d\",\"device\": \"%d\"}", temp, (rand()%100), hum, (rand()%100), winDir, (rand()%100), winInt, (rand()%100), rain, (rand()%100),id);
            //Since IOT-LAB doesn't support float, I used an int and a random int from 0 to 99 to rappresent a float.

            xtimer_sleep(20); //publish values every 20 seconds


            /* send the LoRaWAN message */
            printf("Sending message: %s\n", message);
            uint8_t ret = semtech_loramac_send(&loramac, (uint8_t *)message,
                                                strlen(message));
            if (ret != SEMTECH_LORAMAC_TX_DONE) {
                printf("Cannot send message '%s', ret code: %d\n", message, ret);
            }


    }
    return 0; /* should never be reached */
}
