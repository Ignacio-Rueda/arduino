/*
 CONEXIONES:
 VSS > TIERRA;
 VDD > ALIMENTACIÓN;
 V0 > CONTRASTE (EVITAMOS USAR UN POTENCIOMETRO) PIN 3PWM (EN CASO DE USAR POTENCIOMETRO DEBE SER DE 10K);
 RS > ENVÍA INSTRUCCIONES, COMANDOS (PIN 4);
 RW > LECTURA/ESCRITURA > TIERRA;
 E > ACTIVAR LCD "ENABLE" PIN 5 DIGITAL (PWM);
 D0 > VACIO;
 D1 > VACIO;
 D2 > VACIO;
 D3 > VACIO;
 D4 >PIN 6;
 D5 >PIN 7; 
 D6 >PIN 8;
 D7 >PIN 9;
 PUERTO COMPLETO DE D0-D7. ENVIA DATOS DEL ARDUINO AL DISPLAY, CON 4 PINES NOS VALE;
 A > 5V;
 K > GND (TIERRA) 
*/
#include <LiquidCrystal.h>
int V0=11;
int RS=4;
int E=5;
int D4=6;
int D5=7;
int D6=8;
int D7=9;
LiquidCrystal lcd(RS,E,D4,D5,D6,D7);
void setup()
{
  analogWrite(V0,0);//REGULAMOS EL CONTRASTE (EN 50 YA ESTÁ BIEN)
  lcd.begin(16, 2);//indicamos tamaño de la lcd, columnas y filas;
  lcd.setCursor(0, 0);//cursor, donde quiero que empiece a escribir la primera linea;
  lcd.print("Laura guapa");//la funcion "print" me permite escribir texto, numeros enteros bytes;
  lcd.setCursor(0,1);
  lcd.print("HAZME EL AMOR!");
 }
void loop()
{
   }
