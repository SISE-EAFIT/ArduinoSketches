/**
Fecha de Funcionamiento: 20151010
Nombre del Colaborador: Sergio Monsalve
Tarjeta en las que funciona: Galileo Gen 1
Dependencias: N/A
Funte del Codigo:  https://communities.intel.com/thread/56165
**/

#define trigPin 3
#define echoPin 2

void setup() {
     Serial.begin (9600);
     pinMode(trigPin, OUTPUT_FAST);
     pinMode(echoPin, INPUT_FAST);
}
 
void loop() {
     long duration, distance;

     digitalWrite(trigPin, LOW);
     delayMicroseconds(2);
     digitalWrite(trigPin, HIGH);
     delayMicroseconds(10);
     digitalWrite(trigPin, LOW);
 
     duration = pulseIn(echoPin, HIGH);
     distance = (duration/2) / 29.1;
     if (distance >= 100 || distance <= 0){
          Serial.println("Fuera de Rango");
     }else {
          Serial.print(Distancia);
          Serial.println(" cm");
     }
     delay(500);
}