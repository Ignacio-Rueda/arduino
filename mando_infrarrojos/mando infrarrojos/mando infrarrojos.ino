#include <IRremote.h>

const byte IR_RECEIVE_PIN = 12;

void setup()
{
   Serial.begin(9600);
   Serial.println("IR Receive test");
   IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);//inicializa la recepción de datos
}

void loop()
{
   if (IrReceiver.decode())//Consultamos primero si hay datos disponibles decodificados por la libreria. (El control remoto envía 12 bits del protocolo de forma seria a un bit x b
   {
      Serial.println(IrReceiver.decodedIRData.command, HEX);//HEX sirve para que el número lo muestre en formato hexadecimal; HEXADECIMAL (base 16): 0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F. DECIMAL(base 10) :0,1,2,3,4,5,6,7,8,9. (represento el 12 en formato decimal=12, en sistema hexadecimal "12" = c
      IrReceiver.resume();
   }
}
