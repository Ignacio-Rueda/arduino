/*5v cable rojo;
GND cable café
pulso cable naranja(recibir señal PWM)
4 servos:
rotacion=11
pinza=10
ejeY=6
desplazador2=3*/
#include <Servo.h>
Servo servoROTACION;
Servo servoPINZA;
Servo servoY;
Servo servoX;
int seNal=0;
void setup()
{
  Serial.begin(9600);
/*servoROTACION.attach(11,544,2400);//Sintaxis: servo.attach(pin)-servo.attach(pin,min,max) Parámetros : pin: el número del pin donde el servo está conectado. min(opcional)  el ancho de pulso, en microsegundos, correspondiente al ángulo minimo (0grados) del servo (por defecto 544) max(opcional) el ancho de pulso en microsegundos correspondiente al angulo maximo (180 grados) del servo( por defecto 2400)
servoPINZA.attach(10,544,2400);*/

servoX.attach(6,544,2400);
servoY.attach(3,544,2400);
servoROTACION.attach(11,544,2400);
servoPINZA.attach(10,544,2400);
servoX.write(0);
servoY.write(40);
servoROTACION.write(90);
servoPINZA.write(25);
} 
void loop()
{
  if(seNal==0)
  {
  delay(3500);
  }
  if(seNal==0)
  {
 for(int x=90;x>0;x--)//giramos de posicion inicial a 90
 {
  servoROTACION.write(x);
  delay(40);
 }
  }
  for(int x=25;x<40;x++)//Abrimos pinza
  {
    servoPINZA.write(x);
    delay(50);
  }
    for(int x=0;x<50;x++)//Nos aproximamos a caja
  {
    servoX.write(x);
    delay(50);
  }
  
  for(int x=40;x>0;x--)//cerramos pinza
  {
    servoPINZA.write(x);
    delay(50);
  }
     for(int x=50;x>0;x--)
  {
    servoX.write(x);
    delay(30);
  }
  
  for(int x=40;x<150;x++)//Subimos la pinza
  {
    servoY.write(x);
    delay(30);
  }
   for(int x=0;x<180;x++)//LLemvamos caja a 180
 {
  servoROTACION.write(x);
  delay(40);
 }
    for(int x=0;x<80;x++)//ALEJO CAJA
  {
    servoX.write(x);
    delay(30);
  }
   for(int x=150;x>80;x--)//BAJO CAJA
  {
    servoY.write(x);
    delay(30);
  }
  for(int x=0;x<40;x++)//ABRIMOS pinza
  {
    servoPINZA.write(x);
    delay(50);
  }
    for(int x=80;x>20;x--)//ALEJO CAJA
  {
    servoX.write(x);
    delay(30);
  }
    for(int x=40;x>0;x--)//CERRAMOS pinza
  {
    servoPINZA.write(x);
    delay(50);
  }
   for(int x=180;x>0;x--)//LLemvamos PINZAS VACIAS a 0
 {
  servoROTACION.write(x);
  delay(40);
 }
  for(int x=20;x<20;x--)//ALEJO CAJA
  {
    servoX.write(x);
    delay(30);
  }
   for(int x=80;x>40;x--)//BAJO CAJA
  {
    servoY.write(x);
    delay(30);
  }
  
  seNal=1;
}

 /*servo.write(180);
 delay (500);
 servo.write(90);
 delay (500);

 */
 /*
  for(int x=45;x>25;x--)
{
  servoPINZA.write(x);
  delay (100);
}
for(int x=25;x<45;x++)
{
  servoPINZA.write(x);
  delay (100);
}
for(int x=90;x>0;x--)
{
  servoROTACION.write(x);
  delay (100);
}
for(int x=0;x<180;x++)
{
  servoROTACION.write(x);
  delay (100);
}

for(int x=0;x<50;x++)
{
  servoY.write(x);
  delay(100);
}
for(int x=50;x>0;x--)
{
  servoY.write(x);
  delay(100);
}*/

 
  
