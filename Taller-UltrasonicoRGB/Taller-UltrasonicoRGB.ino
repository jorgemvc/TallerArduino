/** @file    Taller-UltrasonicoRGB.ino
 *  @author  Jorge Villalobos Carvajal (jorgemvc@gmail.com)
 *  @date    28.Mar.2018  
 *  @version 1.0 
 *  
 *  @brief   Lectura de un sensor ultrasonico
 *
 *  @licence  MIT License
 */
// ---- Constantes
const int   trigPin = 9;     // Puerto de envío
const int   echoPin = 10;    // Puerto de recepción
const float factor  = 1.0;   // Factor de ajuste
const int
  redPin   = 3,
  greenPin = 5,
  bluePin  = 6;              // Puertos del led RGB (PWM)

// ---- Variables
float
  duration,                  // Tiempo de vuelo
  distance;                  // Distancia en cm
int brillo;

void setup() {
  pinMode(trigPin, OUTPUT);  // Establece el puerto como de salida
  pinMode(echoPin, INPUT);   // Establece el puerto como de entrada

  pinMode(redPin  , OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin , OUTPUT);

  Serial.begin(9600);        // Inicia la comunicación serial
}  // void setup

void loop() {
  //  Limpia el puerto de envío
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Pone el puerto de envío en HIGH por 5 microsegundos
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Lee la señal de regreso de la onda de sonido en microsegundos
  duration = pulseIn(echoPin, HIGH);
  
  // Calcula la distancia
  distance = ((duration / 2.0) / (29.4118*factor));

  distance = constrain(distance, 3, 300);

  brillo = constrain(distance, 5, 20);
  brillo = map(brillo, 5, 20, 0, 255);
  analogWrite(redPin, 255);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);
  
  // Muestra el resultado en el monitor serial
  Serial.print("Distancia en cm: ");
  Serial.print(distance);
  Serial.print(" - brillo: ");
  Serial.println(brillo);

  // Muestra el resultado para el Serial Plotter
//  Serial.print(distance);
//  Serial.print(",");
//  Serial.println(brillo);
}  // void loop
