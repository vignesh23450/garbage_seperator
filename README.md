# IoT-Enhanced Plastic and Non-Plastic Segregator using Deep Learning Model

### **Project Overview**
This project implements an **IoT-based automated waste segregation system** that classifies and sorts **plastic and non-plastic waste** using **deep learning (YOLO models)** for object detection. The system leverages **ESP32-CAM** for real-time video streaming, **YOLO (You Only Look Once) models** for waste classification, and **servo motors** for automated sorting. This solution is designed to enhance the efficiency of waste management by automating the process of waste segregation.

---

### **Features**
- **Real-time video streaming** using ESP32-CAM.
- **Object detection and classification** using YOLOv8, YOLOv5, and YOLOv10.
- **Automated sorting** of waste using servo motors controlled by classification results.
- **Communication via TCP/IP sockets** between the ESP32-CAM and the central processing unit (CPU).
- **Performance metrics** for YOLO models (precision, recall, mAP) to benchmark and compare their effectiveness.

---

### **System Components**
- **ESP32-CAM**: Captures live video of waste materials and streams it over Wi-Fi.
- **YOLO (You Only Look Once)**: Deep learning models for detecting and classifying waste as plastic or non-plastic.
- **Servo Motors**: Automated waste sorting mechanism based on classification results.
- **CPU (Laptop/Raspberry Pi)**: Processes the video stream using YOLO models and sends sorting commands to ESP32-CAM.

---

### **Project Structure**
```bash
.
├── esp32_cam
│   └── esp32_cam_video_stream.ino     # ESP32-CAM setup for video streaming
├── models
│   ├── yolov5.onnx                    # YOLOv5 model in ONNX format
│   ├── yolov8.onnx                    # YOLOv8 model in ONNX format
│   └── yolov10.onnx                   # YOLOv10 model in ONNX format
├── scripts
│   ├── yolo_classification.py         # Python script for object detection and classification
│   ├── motor_control.py               # Script to control servo motors based on classification
│   └── tcp_communication.py           # Handles TCP/IP communication between CPU and ESP32-CAM
└── README.md
```

---

### **Installation and Setup**
1. **Clone the Repository**
   ```bash
   git clone https://github.com/your-username/iot-waste-segregator.git
   cd iot-waste-segregator
   ```

2. **Install Dependencies**
   - Install **Python 3.7+** and the required Python libraries:
     ```bash
     pip install -r requirements.txt
     ```
     Required Libraries: `OpenCV`, `NumPy`, `socket`

3. **ESP32-CAM Setup**
   - Flash the ESP32-CAM with the **`esp32_cam_video_stream.ino`** file using the Arduino IDE.
   - Ensure that the ESP32-CAM is connected to the same Wi-Fi network as your CPU.

4. **Model Setup**
   - Download or convert your trained YOLO models to **ONNX format**.
   - Place the models in the `/models` directory.

---

### **How to Run**
1. **Start ESP32-CAM**
   - After flashing the ESP32-CAM, power it on. It will start streaming video on the local network.
   
2. **Run the Classification Script**
   - Use the YOLO model for real-time object detection and classification:
     ```bash
     python scripts/yolo_classification.py
     ```

3. **Control Servo Motors**
   - After the classification, the results are sent to the ESP32-CAM, which will trigger the servo motors to sort the waste:
     ```bash
     python scripts/motor_control.py
     ```

4. **Monitor Communication**
   - Ensure that the CPU and ESP32-CAM are communicating via the TCP/IP socket. You can monitor the data flow by running the communication script:
     ```bash
     python scripts/tcp_communication.py
     ```

---

### **Performance Comparison**
The following models are tested for their performance in waste classification:

| **Model**    | **Precision** | **Recall**  | **mAP50**  | **mAP50-95** |
| ------------ | ------------- | ----------- | ---------- | ------------ |
| YOLOv8       | 0.97852       | 0.97822     | 0.99500    | 0.94718      |
| YOLOv5       | 0.94633       | 1.00000     | 0.99045    | 0.91103      |
| YOLOv10      | 0.90910       | 0.98507     | 0.98167    | 0.92872      |

---

### **Contributing**
If you'd like to contribute to the project, feel free to open a pull request or issue on GitHub. Contributions are welcome!

---

### **License**
This project is licensed under the MIT License. See the LICENSE file for more details.



---

This **README** file provides all the necessary instructions for setting up, running, and contributing to the project, along with detailed descriptions of its functionalities and model performance.
