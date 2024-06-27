# Secure_MQTT_Client-TLS
This sketch for ESP32 connects to a secure MQTT server over WiFi using the WiFiClientSecure and PubSubClient libraries. It uses a Certificate Authority (CA) certificate for secure communication. The ESP32 subscribes to an MQTT topic and publishes messages, handling incoming messages with a callback function.


# ESP32 Secure MQTT Client

This project demonstrates how to create an ESP32-based secure MQTT client that:
- Connects to a WiFi network.
- Connects securely to an MQTT server using a CA certificate.
- Subscribes to and publishes messages to MQTT topics.

## Features
- Connects to a WiFi network.
- Connects securely to an MQTT server using SSL/TLS.
- Subscribes to an MQTT topic and handles incoming messages.
- Publishes messages to an MQTT topic.

## Applications in IoT and Landslide Early Warning Systems (LEWS)
This ESP32 secure MQTT client can be adapted for various IoT applications, including a Landslide Early Warning System (LEWS). Here’s how:

### IoT Environment
In an IoT environment, this project can serve as a foundational element for secure communication between sensors and a central server. For example:
- **Data Collection:** Use the ESP32 to collect data from various sensors (temperature, humidity, pressure, etc.) and send this data securely to an MQTT broker.
- **Remote Monitoring:** Deploy multiple ESP32 devices to different locations for remote monitoring of environmental conditions.
- **Automation:** Integrate with other IoT devices to trigger actions based on sensor data, such as turning on cooling systems when temperature exceeds a threshold.

### Landslide Early Warning System (LEWS)
For a Landslide Early Warning System, the ESP32 secure MQTT client can be a critical component for monitoring and alerting. Here’s how it can be used:
- **Sensor Integration:** Connect the ESP32 to sensors that measure soil moisture, ground movement, rainfall, and other relevant parameters.
- **Data Transmission:** Securely transmit sensor data to a central MQTT server where it can be analyzed in real-time.
- **Alerts and Notifications:** Subscribe to critical topics to receive early warning notifications. The ESP32 can trigger alarms or send notifications to authorities and residents when thresholds are exceeded, indicating potential landslides.
- **Distributed Monitoring:** Deploy multiple ESP32 units across a landslide-prone area to create a distributed monitoring network. Each unit can act as a node in the LEWS, providing comprehensive coverage and redundancy.

## Requirements
- ESP32 board
- Arduino IDE
- WiFi network credentials
- MQTT broker (e.g., test.mosquitto.org)
- CA certificate for secure communication

## Libraries Used
- WiFiClientSecure.h
- PubSubClient.h

## Hardware Required
- ESP32 development board
- USB cable for programming and power
- WiFi network

## Installation
1. Clone this repository.
2. Open the `.ino` file in the Arduino IDE.
3. Update the `ssid` and `password` variables with your WiFi network credentials.
4. Update the `mqtt_server` variable with your MQTT broker address.
5. Install the required libraries (`WiFiClientSecure` and `PubSubClient`) through the Arduino Library Manager.
6. Connect your ESP32 to the computer via USB.
7. Select the appropriate board and port in the Arduino IDE.
8. Upload the sketch to your ESP32.

## Usage
1. Ensure your ESP32 is connected to the WiFi network.
2. The ESP32 will attempt to connect to the specified MQTT server using the provided CA certificate.
3. The ESP32 will subscribe to the MQTT topic "inTopic" and publish messages to "outTopic".
4. Incoming messages on the subscribed topic will be handled by the `callback` function.


