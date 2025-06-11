## Automated-Hydroponics-System-with-Plant-disease-and-pest-detection

This repository contains the code and resources for a thesis capstone project that develops an automated hydroponics system using the Nutrient Film Technique (NFT). The system is designed to improve plant growth and efficiency by automating key aspects of hydroponic farming, including nutrient regulation and plant health monitoring.

**Key Features:**
- Automated regulation of electrical conductivity, pH, and water temperature to optimize plant growth.
- A Gantry Robot for 
- Machine learning-based plant health assessment using **AlexNet** and snail detection using **YOLOv8**, both integrated into a gantry robot for automated monitoring.

## Project Documentation

This section provides a visual and technical overview of the Automated Hydroponics System, emphasizing the integration of machine learning and automation for plant health and pest detection.

---

### 1. System Connection Overview

A diagram showing the overall connection and interaction of all system components, including sensors, controllers, actuators, and the gantry robot.

![Diagram components](/images_docs/Architectural_design.jpg)

---

### 2. Circuit Diagrams

Detailed electronic circuit diagrams illustrating the wiring of ArduinoMEGA, RaspberryPi, and power supply.

![ArduinoMEGA](/images_docs/arduino_mega_diagram.jpg)
![RaspberryPi](/images_docs/raspbery_pi_diagram.jpg)
![PowerSupply](/images_docs/power_supply_diagram.jpg)

---

### 3. 3D Model Views of the Prototype

Rendered images or screenshots of the 3D CAD model for the hydroponic system and gantry robot, highlighting mechanical design and spatial arrangement.

![GantryView](/images_docs/3d_model_views/gantry_view.jpg)
![GrowLightsView](/images_docs/3d_model_views/grow_lights_view.jpg)
![DownspoutsView](/images_docs/3d_model_views/downspouts_view.jpg)

---

### 4. Actual Prototype Photos

Real-life photographs of the assembled prototype, including wide shots and close-ups of key modules (e.g., plant trays, electronics enclosure, robotic arm).

---

### 5. Flowchart: Image Processing for Plant Health Assessment

A flowchart illustrating the image processing pipeline for plant health assessment, from image acquisition, preprocessing, AlexNet inference, to result reporting.

![PlantHealthAssessmentFlow](/images_docs/plant_health_assessment.jpg)
![SnailDetectionFlow](/images_docs/snails_detection_system.jpg)

---

### 6. Flowchart: Image Processing for Snail Detection

A flowchart depicting the process of snail detection, including data capture, preprocessing, YOLOv8 inference, alerting, and logging actions.

---

## 7. Flowchart: Training of Machine Learning Models

A flowchart showing the workflow for training both the AlexNet (plant health) and YOLOv8 (snail detection) models, covering dataset preparation, augmentation, model training, validation, and deployment steps.

---
