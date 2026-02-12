# 25-26_MosfTest

Identificador y comprobación de estados de MOSFET con visualización en LCD 

![Python](https://img.shields.io/badge/ArduinoIDE-2.3.7-blue)

![Platform](https://img.shields.io/badge/Dispositivo-Arduino%20MEGA%202560%20Pro-green)

<img width="350" height="270" alt="mosfet" src="https://github.com/user-attachments/assets/9721afc6-2843-4b83-a83f-fb8f51a54d6b" />


## 📖 Descripción

Explicación general del proyecto:

- Proyecto para la identificación y comprobación de MOSFET mediante Arduino Mega y relés.  
- Reduce fallos en montajes de PCB mostrando el estado de los MOSFET en una pantalla LCD.  
- El montaje completo incluye PCB y carcasa impresa en 3D, con 9 relés controlados por Arduino.


## 🧩 Componentes del Proyecto

### 🔌 Electrónica

- Microcontrolador: Arduino Mega
- Relés 5V
- Resistencias
- Socket especializado en MOSFET
- Fuente de alimentación 12V
- Pantalla LCD

### 🖥️ Firmware

- Arduino IDE
- Lenguaje: C/C++ 
- Librerías utilizadas: Wire.h y LiquidCrystal_I2C.h

### 🏾 Diseño PCB

- PCB diseñadas en "Proteus"
- Capas de PCB "2 o 4"
  
### 🛠️ Diseño Mecánico

- Piezas diseñadas en "Sketchup 2017"
- Material recomendado "PLA"


## 📂 Estructura del Repositorio

- /arduino       → Código fuente del Arduino Mega
- /pcb           → Archivos de PCB (Eagle / KiCad)
- /Diseño 3D     → Modelos STL para impresión de carcasa
- /docs          → Diagramas, esquemas eléctricos e imágenes del montaje
