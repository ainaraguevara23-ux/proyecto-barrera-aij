# 🚧 Smart Barrier — Sistema de Barrera Automática para Estacionamiento

Sistema de control de acceso vehicular automatizado mediante sensor ultrasónico, servomotor e indicadores lumínicos LED, desarrollado sobre Arduino UNO.

---

## 👥 Integrantes del Equipo
* **Ainara Guevara** — Scrum Master
* **Jazmín Banes** — Developer / Hardware Specialist
* **Ignacio Demo** — Developer / Software Specialist

---

## 📋 Requerimientos Funcionales (5)
1. **RF01 - Detección de Vehículos:** El sensor ultrasónico HC-SR04 mide continuamente la distancia y detecta un vehículo si la distancia es menor o igual a 15 cm.
2. **RF02 - Apertura Automática:** Al detectar presencia, el servomotor gira a 90° levantando la barrera.
3. **RF03 - Señalización Lumínica:** Durante la apertura, el LED verde se enciende y el LED rojo se apaga.
4. **RF04 - Cierre Automático con Retardo:** La barrera se mantiene abierta durante 3 segundos antes de volver a bajar (0°).
5. **RF05 - Estado de Reposo:** En ausencia de vehículos, la barrera permanece cerrada (0°) con LED rojo encendido y verde apagado.

---

## ⚙️ Requerimientos No Funcionales (5)
1. **RNF01 - Tiempo de Respuesta:** La reacción y apertura ocurre en menos de 500 ms tras la detección.
2. **RNF02 - Visibilidad e Intuitividad:** Los indicadores LED son visibles y distinguibles desde más de 3 metros de distancia.
3. **RNF03 - Mantenibilidad:** Código modular en C++ con comentarios descriptivos y variables claras.
4. **RNF04 - Simulabilidad en Wokwi:** Circuito 100% simulable en Wokwi e instalable en hardware real.
5. **RNF05 - Eficiencia del Microcontrolador:** Control de ciclos del procesador mediante retardos optimizados.

---

## 📊 Diagrama de Flujo del Sistema

```mermaid
graph TD
    A[Inicio: setup] --> B[Inicializar Servo a 0°]
    B --> C[LED Rojo ON / LED Verde OFF]
    C --> D[Emitir pulso ultrasónico Trig]
    D --> E[Medir tiempo de respuesta Echo]
    E --> F[Calcular distancia en cm]
    F --> G{¿Distancia <= 15 cm?}
    G -- Sí --> H[LED Rojo OFF / LED Verde ON]
    H --> I[Girar Servo a 90° - Abrir Barrera]
    I --> J[Esperar 3 segundos]
    J --> D
    G -- No --> K[Girar Servo a 0° - Cerrar Barrera]
    K --> C
¡Pegá eso en el `README.md`, guardalo y ya te queda perfecto con tu simulación enlazada! 🚀
