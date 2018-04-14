/** @file    Taller-PushButton.ino
 *  @author  Jorge Villalobos Carvajal (jorgemvc@gmail.com)
 *  @date    07.Feb.2018  
 *  @version 1.0 
 *  
 *  @brief   Uso de un pulsador.
 *
 *  @licence  MIT License
 */
// ---- Variables
int
  led = 3,   // Puerto utilizado para el led
  bot = 2;   // Puerto utilizado por el botón

void setup() {
  pinMode(bot, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}  // setup

void loop() {
  if (digitalRead(bot) == HIGH) {
    digitalWrite(led, HIGH);
    Serial.println("Entró");
  } else {
    digitalWrite(led, LOW);
  }
  // Se agrega un tiempo de espera para mejorar
  // la simulación.
  delay(10); 
}  // loop
