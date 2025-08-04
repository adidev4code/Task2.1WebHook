# Task2.1WebHook

Embedded Systems Development – Task 2.1P
Sending Sensor Data to the Web with Arduino Nano 33 IoT and ThingSpeak

📘 Task Description
This task focuses on the core concept of Internet of Things (IoT) development: sending real-time data from a physical device to a web service. For this assignment, we were tasked with connecting a sensor to an Arduino Nano 33 IoT board and pushing the collected data to the ThingSpeak cloud platform using webhooks.

🔹 Hardware and Software
To complete this task, the following components and services were used:

Hardware:

Arduino Nano 33 IoT

DHT22 Temperature and Humidity Sensor

Breadboard and Jumper Wires

Software & Services:

Arduino Web Editor / IDE

ThingSpeak Platform

GitHub for version control

🔹 Project Implementation
The implementation was a step-by-step process involving hardware assembly, software development, and cloud platform configuration.

1. Circuit Assembly:
The DHT22 sensor was connected to the Arduino Nano 33 IoT board. The sensor's VCC pin was connected to the Arduino's 3.3V pin, and the GND pin was connected to a GND pin. The data pin of the DHT22 was wired to the D2 digital pin on the Arduino to read sensor output.

2. ThingSpeak Channel Setup:
A new data channel was created on ThingSpeak with two fields named 'temp' and 'humidity'. A unique Write API Key was generated for this channel, which was essential for authenticating our device when sending data.

3. Code Development:
The Arduino sketch was developed to perform the following actions:

Connect to a specified WiFi network using the WiFiNINA library.

Read both temperature and humidity values from the DHT22 sensor.

Construct and send an HTTP POST request to the ThingSpeak API. This request included the Write API Key and the sensor data.

The code was configured to send this data every 30 seconds, demonstrating a basic periodic data logging system.

📌 Outcome
By successfully completing this task, we gained a foundational understanding of key IoT concepts:

IoT Device-Cloud Integration: The process of connecting a physical device to a cloud service.

Sensor Interfacing: Reading data from an external sensor (DHT22) using an Arduino microcontroller.

HTTP Requests: Implementing an HTTP POST request to send data over a network.

API Communication: Using an API key to securely send data to a web service like ThingSpeak.

This task serves as a practical demonstration of how embedded systems can be used to collect and share data online.
