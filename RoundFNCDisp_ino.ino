// ESP32 code to connect to a fluidNC server and display the alarm and work position to serial
// Future work: Display the alarm and work position on a display.
// Author: Ben Ford
#include <ArduinoWebsockets.h>
#include <WiFi.h>
#include <iostream>
#include <cstdio>
#include <cstring>

const char *ssid = "FluidNC";                       // Enter SSID
const char *password = "123456789";                 // Enter Password
const char *websockets_server_host = "192.168.0.1"; // Enter server IP
const uint16_t websockets_server_port = 81;         // Enter server port

// Default string to parse
const char *str = "<Alarm|WPos:0.000,0.000,0.0007,0.000|Bf:15,128|FS:0,0>";
char alarm[10];
float wposX, wposY, wposZ, wposA;
int bf1, bf2, fs1, fs2;

using namespace websockets;

WebsocketsClient client;
void setup()
{
    Serial.begin(9600);
    //
    Serial.print("Booting...");
    // Connect to wifi
    WiFi.begin(ssid, password);

    // Wait some time to connect to wifi
    for (int i = 0; i < 10 && WiFi.status() != WL_CONNECTED; i++)
    {
        Serial.print(".");
        delay(1000);
    }

    // Check if connected to wifi
    if (WiFi.status() != WL_CONNECTED)
    {
        Serial.println("No Wifi!");
        return;
    }

    Serial.println("Connected to Wifi, Connecting to server.");
    // try to connect to Websockets server
    bool connected = client.connect(websockets_server_host, websockets_server_port, "/");
    if (connected)
    {
        Serial.println("Connected!");
        client.send("?");
    }
    else
    {
        Serial.println("Not Connected!");
    }

    // run callback when messages are received
    client.onMessage([&](WebsocketsMessage message)
                     {
        str = message.data()
        sscanf(str, "<%[^|]|WPos:%f,%f,%f,%f|Bf:%d,%d|FS:%d,%d>", alarm, &wposX, &wposY, &wposZ, &wposA, &bf1, &bf2, &fs1, &fs2);
        Serial.printf("X: %s\n", wposX);
        Serial.printf("Y: %s\n", wposY);
        Serial.printf("Z: %s\n", wposZ); });
}

void loop()
{
    // let the websockets client check for incoming messages
    client.send("?");
    if (client.available())
    {
        client.poll();
    }
    delay(1000);
}
