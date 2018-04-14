/** @file    Taller-PuenteH.ino
 *  @author  Jorge Villalobos Carvajal (jorgemvc@gmail.com)
 *  @date    11.Abr.2018  
 *  @version 1.0 
 *  
 *  @brief   Uso de servo motor
 *
 *  @licence  MIT License
 */
void setup() {
  pinMode(13, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(9, OUTPUT);
  
  // Habilita el motor 1 del puente
  digitalWrite(13, HIGH);
}  // void setup

void loop() {
  // Gira en un sentido
  digitalWrite(11, HIGH);
  digitalWrite(9 , LOW);
  delay(2000);

  // Gira en sentido contrario
  digitalWrite(11, LOW);
  digitalWrite(9 , HIGH);
  delay(2000);
}  // void loop
