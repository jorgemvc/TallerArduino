/** @file    Taller-Fade.ino
 *  @author  Jorge Villalobos Carvajal (jorgemvc@gmail.com)
 *  @date    07.Abr.2018  
 *  @version 1.0 
 *  
 *  @brief   Disminuir/aumentar la luminosidad de un led
 *           conectado a un puerto PWM
 *
 *  @licence  MIT License
 */
int led = 3;           // Puerto PWM del led
int brightness = 0;    // Brillo del led [0-255]
int fadeAmount = 5;    // Incremento del brillo

void setup() {
  // ---- Declara el puerto del led como salida
  pinMode(led, OUTPUT);
}  // void setup

void loop() {
  // ---- Se establece el brillo del led
  analogWrite(led, brightness);

  // ---- Se incrementa el brillo
  brightness += fadeAmount;

  // ---- Invierte el incremento si llega a algún
  //      límite de los valores posibles
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }

  // Espera 100 milisegundos
  delay(100);
}  // void setup
