# Industrial Machine State Monitoring System

## Project Overview

The **Industrial Machine State Monitoring System** is a real-time IoT-based monitoring solution developed using the **ESP32 Wi-Fi module** and industrial sensors to continuously track machine operational states such as:

* Running State
* Idle State
* Fault State

The system collects live sensor data from industrial machines and uploads it to the **ThingSpeak Cloud Platform** using REST API communication. The collected data is visualized as real-time graphs and analytics dashboards for monitoring machine performance, predictive maintenance, and downtime reduction.

This project helps industries improve operational efficiency by enabling remote monitoring and early fault detection.

---

# Features

## Real-Time Machine Monitoring

* Continuously monitors machine states
* Detects:

  * Running condition
  * Idle condition
  * Fault condition

## Cloud Data Integration

* Sends live machine data to ThingSpeak cloud
* Uses REST API for communication
* Enables remote monitoring from anywhere

## Real-Time Data Visualization

* Displays machine data using live graphs
* Helps in analyzing machine behavior
* Supports predictive maintenance

## Additional Functionalities

* Wi-Fi based communication
* Low power embedded system
* Fast response monitoring
* Reliable cloud connectivity
* Scalable for multiple machines

---

# Technologies Used

* ESP32 Wi-Fi Module
* Industrial Sensors
* ThingSpeak Cloud API
* Embedded C
* Arduino IDE
* REST API Integration
* IoT Communication Protocols
* Real-Time Data Visualization

---

# Project Structure

```bash id="v8m1de"
Industrial_Machine_State_Monitoring_System/
│
├── main.ino
├── sensor_readings.c
├── wifi_connection.c
├── thingspeak_api.c
├── config.h
├── libraries/
├── circuit_diagram/
└── README.md
```

---

# Hardware Requirements

* ESP32 Development Board
* Vibration / Current / Temperature Sensors
* Breadboard & Connecting Wires
* Power Supply
* Wi-Fi Network

---

# Software Requirements

* Arduino IDE
* ThingSpeak Cloud Account
* Embedded C Knowledge
* USB Drivers for ESP32

---

# System Workflow

1. Sensors collect machine operational data.
2. ESP32 processes sensor inputs.
3. Machine state is identified:

   * Running
   * Idle
   * Fault
4. Data is transmitted to ThingSpeak cloud using Wi-Fi.
5. ThingSpeak visualizes data as real-time graphs.
6. Users monitor machine status remotely.

---

# Uploading the Code

1. Open the project in Arduino IDE.
2. Select the ESP32 board.
3. Configure:

   * Wi-Fi SSID
   * Password
   * ThingSpeak API Key
4. Connect ESP32 using USB cable.
5. Upload the code to ESP32.

---

# Sample Output

## Serial Monitor Output

```bash id="3q0wlr"
Connecting to WiFi...
WiFi Connected

Machine State : RUNNING
Temperature   : 45°C
Vibration     : Normal

Uploading data to ThingSpeak...
Data Uploaded Successfully
```

---

# ThingSpeak Dashboard

The cloud dashboard displays:

* Live machine status
* Temperature graph
* Fault analysis
* Machine uptime trends
* Historical sensor data

---

# Objectives

* To implement industrial machine monitoring using IoT
* To enable real-time cloud-based monitoring
* To reduce machine downtime
* To support predictive maintenance
* To improve industrial automation efficiency

---

# Future Enhancements

* Mobile application integration
* SMS/Email fault alerts
* AI-based predictive maintenance
* Multi-machine centralized dashboard
* MQTT protocol implementation
* Data logging and analytics

---

# Error Handling

The system handles:

* Wi-Fi disconnection
* Sensor failures
* Cloud upload failures
* Invalid sensor readings
* Communication timeout errors

---

# Author

Ramanesh M

