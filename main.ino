#include <Servo.h>

Servo miServo;

const int trigPin = 9;
const int echoPin = 10;
const int ledVerde = 6;
const int ledRojo = 7;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledRojo, OUTPUT);

  miServo.attach(3);
  miServo.write(0); // Barrera cerrada en reposo
  digitalWrite(ledRojo, HIGH);
  digitalWrite(ledVerde, LOW);

  Serial.begin(9600);
}

void loop() {
  long duracion, distancia;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duracion = pulseIn(echoPin, HIGH);
  distancia = duracion * 0.034 / 2;

  if (distancia > 0 && distancia <= 15) {
    // Objeto detectado: abre la barrera
    digitalWrite(ledRojo, LOW);
    digitalWrite(ledVerde, HIGH);
    miServo.write(90); // Abre la barrera
    delay(3000);       // Espera 3 segundos
  } else {
    // Sin objetos: cierra la barrera
    digitalWrite(ledRojo, HIGH);
    digitalWrite(ledVerde, LOW);
    miServo.write(0);  // Cierra la barrera
  }

  delay(100);
}
