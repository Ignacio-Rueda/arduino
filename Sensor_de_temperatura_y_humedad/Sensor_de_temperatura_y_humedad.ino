/*
La patilla más próxima a la "S" va conectada al pin digital(PIN 13);
La del centro a 5v;
La última a tierra;
*/
#include <DHT.h>

int sensor=11;//vinculamos el sensor al pin 13, que es a la salida a la que la conectamos;
int temperatura,humedad;//declaramos dos varibles;
DHT dht(sensor,DHT11);//Es necesario para indicar a la librería el modelo de sensor que estamos utilizando;
void setup()
{
  Serial.begin(9600);
  dht.begin(); 
    humedad=dht.readHumidity();
    temperatura=dht.readTemperature();
  
    
  
}
  void loop()
  {
      Serial.print("Humedad");
    Serial.print(humedad);
    Serial.println("%");
    Serial.print("Temperatura");
    Serial.print(temperatura);
    Serial.println("º");
    delay(500);
  
    
  }
