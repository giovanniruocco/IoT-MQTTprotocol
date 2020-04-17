### IoT 2020 course - Sapienza - MsC Engineering in Computer Science

Videos available on: https://www.youtube.com/channel/UCYqfsypgUyIXnKJCOo0tnqA/videos

Linkedin posts available on: https://www.linkedin.com/in/giovanniruocco07/

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


WEB PAGE

├── WebPage                         #Web Page that contains tables for each assignment          
│   │   
│   ├── main.css          
|   └── wb.html           

```
