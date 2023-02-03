
 
#include <LiquidCrystal.h>
#include <DHT.h>
int V0=3;
int RS=4;
int E=5;
int D4=6;
int D5=7;
int D6=8;
int D7=9;
int sensor=13;//vinculamos el sensor al pin 13, que es a la salida a la que la conectamos;
int temperatura,humedad;//declaramos dos varibles;
DHT dht(sensor,DHT11);//Es necesario para indicar a la librería el modelo de sensor que estamos utilizando;

LiquidCrystal lcd(RS,E,D4,D5,D6,D7);
void setup()
{
  analogWrite(V0,50);//REGULAMOS EL CONTRASTE (EN 50 YA ESTÁ BIEN)
  lcd.begin(16, 2);//indicamos tamaño de la lcd, columnas y filas;

 }
void loop()
{ 
    humedad=dht.readHumidity();
    temperatura=dht.readTemperature();
  
  lcd.setCursor(0, 0);//cursor, donde quiero que empiece a escribir la primera linea;
  lcd.print("Humedad");//la funcion "print" me permite escribir texto, numeros enteros bytes;
  lcd.print(humedad);
  lcd.print("%");
  lcd.setCursor(0,1);
  lcd.print("Temperatura");
  lcd.print(temperatura);
  lcd.print("C");
  delay(2000);
  lcd.clear();
  lcd.print("prueba");
  delay(2000);
  lcd.clear();

   }

   /* 
    humedad=dht.readHumidity();
    temperatura=dht.readTemperature();
    Serial.print("Humedad");
    Serial.print(humedad);
    Serial.println("%");
    Serial.print("Temperatura");
    Serial.print(temperatura);
    Serial.println("º");
   
   
   
   */
