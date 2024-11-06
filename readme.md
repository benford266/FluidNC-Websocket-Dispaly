# ESP32 FluidNC WebSocket Client

This project connects an ESP32 to a FluidNC server via WebSocket and displays the alarm and work position on the serial monitor. Future work includes displaying the alarm and work position on a display.

## Author

Ben Ford

## Requirements

- ESP32 board
- Arduino IDE
- WiFi network

## Libraries

- [ArduinoWebsockets](https://github.com/gilmaimon/ArduinoWebsockets)
- [WiFi](https://www.arduino.cc/en/Reference/WiFi)

## Setup

1. Install the required libraries in the Arduino IDE.
2. Open the `RoundFNCDisp_ino.ino` file in the Arduino IDE.
3. Update the `ssid`, `password`, and `websockets_server_host` variables with your WiFi credentials and server IP.

## Usage

1. Upload the code to your ESP32 board.
2. Open the Serial Monitor in the Arduino IDE.
3. The ESP32 will connect to the WiFi network and then to the WebSocket server.
4. The alarm and work position will be displayed on the Serial Monitor.

## Code Overview

### Global Variables

- `ssid`: WiFi SSID.
- `password`: WiFi password.
- `websockets_server_host`: WebSocket server IP.
- `websockets_server_port`: WebSocket server port.

### Functions

- `setup()`: Initializes the serial communication, connects to WiFi, and connects to the WebSocket server.
- `loop()`: Sends a message to the WebSocket server and checks for incoming messages.

## Future Work

- Display the alarm and work position on a display.
