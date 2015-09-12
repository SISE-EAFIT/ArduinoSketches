/**
Fecha de Funcionamiento: 20151010
Nombre del Colaborador: Sergio Monsalve
Tarjeta en las que funciona: Galileo Gen 1
Dependencias: N/A
Funte del Codigo:  https://communities.intel.com/thread/56165
**/

#define trigPin 3
#define echoPin 2
int val;
void setup() {
     Serial.begin (9600);
     pinMode(trigPin, OUTPUT_FAST);
     pinMode(echoPin, INPUT_FAST);
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
     if (distancia >= 100 || distancia <= 0){
          Serial.println("Fuera de Rango");
     }else {
          val = map(distancia, 0, 30, 0, 1024);
          Serial.println(val);
       //   Serial.println(val);
     }
     delay(500);
}
