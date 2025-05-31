# 🌬️ Breezy - IoT Environmental Monitor

[![Platform](https://img.shields.io/badge/Platform-ESP32-blue)](https://www.espressif.com)
[![Sensor](https://img.shields.io/badge/Sensor-DHT11%20%7C%20MQ135-green)](https://www.arduino.cc)
[![Cloud](https://img.shields.io/badge/Cloud-ThingSpeak-orange)](https://thingspeak.com)

A compact IoT-based system for real-time monitoring of temperature, humidity, and air quality (AQI) with cloud data visualization.

![System Diagram]
![Schimatic(Mkaes use of an mq-6 instead of an mq135](https://github.com/user-attachments/assets/56fa2952-5849-4612-bd11-9bbbdc06f1b4)


## 📌 Abstract
Design and fabrication of a custom PCB integrating ESP32 microcontroller with DHT11 (temperature/humidity) and MQ135 (AQI) sensors. Data is transmitted via Wi-Fi to cloud platforms for real-time visualization and analysis. Features low-power design supporting both stationary and battery-powered deployments.

## ✨ Features
- Real-time environmental monitoring
- Custom low-noise PCB design
- Wi-Fi connectivity (HTTP/MQTT)
- Cloud integration (ThingSpeak/Blynk)
- Power-optimized for battery operation
- Threshold-based alerts

## 📦 Hardware Components
| Component                 | Specification       |
|---------------------------|--------------------|
| Microcontroller           | ESP32-C3-DevKitM-1 |
| Temperature/Humidity Sensor | DHT11              |
| Air Quality Sensor        | MQ135              |
| Pull-up Resistor          | 10kΩ               |
| Power Supply              | Micro USB/Type-C   |

## 🔌 Pin Connections
| ESP32 Pin | Connection             |
|-----------|------------------------|
| GPIO4     | DHT11 Data            |
| GPIO34    | MQ135 Analog Output   |
| 5V        | Sensor VCC            |
| GND       | Sensor GND            |

*(Pull-up resistor between DHT11 Data and VCC)*

## ⚙️ Firmware Setup
1. Install required libraries:
   ```bash
   pio lib install "Adafruit DHT Unified" "HTTPClient"
