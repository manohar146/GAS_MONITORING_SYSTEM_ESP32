# GAS_MONITORING_SYSTEM_ESP32
This project continuously monitors gas concentration using an MQ2 sensor, displays real-time readings on a 16x2 LCD and the Blynk IoT cloud dashboard, and triggers LED and buzzer alerts when gas levels exceed predefined thresholds
# 🛢️ Gas Monitoring System

## Overview
This project implements a gas detection and alert system using embedded sensors and microcontroller logic. It includes real-time monitoring, pin mapping, circuit design, and thorough documentation to support replication and understanding.

## Tech Stack
- Arduino (gas_monitoring_system.ino)
- Gas sensor (e.g., MQ series)
- Buzzer or alert module
- Excel for pin configuration
- Word documentation for system overview

## Files Included
- `gas_monitoring_system.ino`: Arduino sketch for gas detection and alert logic
- `Gas_Monitoring_System_documentation.docx`: Detailed write-up of system design and operation
- `Gas_Monitoring_System_pinouts.xlsx`: Pin configuration and hardware mapping
- `gasmonitoring_system_image.jpg`: Photo of the physical setup
- `circuit_image (21).png`: Circuit diagram
- `README.md`: Project overview and instructions

## Highlights
- Real-time gas detection with threshold-based alerting
- Modular code for easy adaptation to other sensor types
- Clear documentation and pin mapping for reproducibility
- Visual assets for hardware setup and circuit layout

## How It Works
- The gas sensor detects concentration levels and sends data to the microcontroller
- If levels exceed a set threshold, an alert is triggered via buzzer or output module
- Circuit and pin mapping ensure accurate signal flow and control

## Author
**Manohar** – Embedded Systems Enthusiast  
📫 [GitHub Profile](https://github.com/manohar146)
