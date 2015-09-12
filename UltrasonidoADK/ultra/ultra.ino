/*
 Sensor Ultra Sonido: HC-SR04 Ping distancia sensor
 VCC a arduino 5v 
 GND a arduino GND
 Echo to Arduino pin 13 
 Trig to Arduino pin 12

  Sergio Monsalve
  Probado en Arduino Mega ADK
  20151012
  smonsalve@gmail.com
 */

#define trigPin 13
#define echoPin 12

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duracion, distancia;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duracion = pulseIn(echoPin, HIGH);
  distancia = (duracion/2) / 29.1;

  if (distancia >= 200 || distancia <= 0){
    Serial.println("Fuera de Rango");
  }else {
    Serial.print(distancia);
    Serial.println(" cm");
  }
  delay(500);
}
