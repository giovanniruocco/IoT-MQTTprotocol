### IoT 2020 course - Sapienza - MSc Engineering in Computer Science

Videos available on: https://www.youtube.com/channel/UCYqfsypgUyIXnKJCOo0tnqA/videos

Linkedin posts available on: https://www.linkedin.com/in/giovanniruocco07/

1st Assignment post: https://www.linkedin.com/pulse/cloud-based-iot-system-collects-information-from-set-virtual-ruocco/

2nd Assignment post: https://www.linkedin.com/pulse/publish-virtual-telemetries-from-riot-os-thingsboard-iot-ruocco/

3rd Assignment post: https://www.linkedin.com/pulse/publish-virtual-real-world-telemetries-from-riot-os-via-ruocco/


Repository structure:
```
1ST ASSIGNMENT

├── Publisher                        #Python scripts
│   │   
│   ├── algthingsboard1.py           #Random values sent to thingsboard(1st device)
|   └── algthingsboard1.py           #Random values sent to thingsboard(2nd device)



2ND ASSIGNMENT

├── Gateway                         #Gateway configuration and mosquitto bridge
│   │   
│   ├── mosquitto_bridge.conf
|   └── gateway.conf
│      
|
└── Riot-OS                         #Riot OS devices
│       |
|       ├── 1stStation              #Random values sent via mosquitto_bridge(1st device)
|       |      ├── Makefile
|       |      └── main.c
|       └── 2ndStation              #Random values sent via mosquitto_bridge(2nd device)
|       |      ├── Makefile
|       |      └── main.c



3RD ASSIGNMENT

├── Lorawan                           
│       |
|       ├── First_random            #Random values sent via LoRaWAN(1st device)
|       |      ├── Makefile
|       |      ├── main.c
|       |      └── lorawan.elf
|       ├── Second_random           #Random values sent via LoRaWAN(2nd device)
|       |      ├── Makefile
|       |      ├── main.c
|       |      └── lorawan.elf
|       ├── First_real              #Real data sensor sent via LoRaWAN(1st device)
|       |      ├── Makefile
|       |      ├── main.c
|       |      └── lorawan.elf
|       ├── Second_real             #Real data sensor sent via LoRaWAN(2nd device)
|       |      ├── Makefile
|       |      ├── main.c
|       |      └── lorawan.elf



4ST ASSIGNMENT

├── Activity_Recognition                       
│   │   
│   ├── Cloud          #Cloud development html page
|   |       ├── wb.html
|   |       └── main.css
|   ├── Edge           #Edge development html page
|   |       ├── index.html
|   |       └── main.css


WEB PAGE

├── WebPage                         #Web Page that contains tables for the first 3 assignment          
│   │   
│   ├── main.css          
|   └── wb.html           

```
