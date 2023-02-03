
#include <IRremote.h>
#include <LiquidCrystal.h>
int V0=3;
int RS=4;
int E=5;
int D4=6;
int D5=7;
int D6=8;
int D7=9;
LiquidCrystal lcd(RS,E,D4,D5,D6,D7);
const byte IR_RECEIVE_PIN = 12;
int a=0;
int resultado1=0;
int seNal=0;
int numero=0;
int suma=0;
int contador=0;
void setup()
{
   Serial.begin(9600);
   /*Serial.println("IR Receive test");*/
   IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);//Inciamos la recepcion de datos;
   analogWrite(V0,50);//REGULAMOS EL CONTRASTE (EN 50 YA ESTÁ BIEN)
  lcd.begin(16, 2);//indicamos tamaño de la lcd, columnas y filas;
  lcd.setCursor(0,0);

  
}

void loop()
{
    if (IrReceiver.decode())//Consultamos primero si hay datos disponibles decodificados por la libreria. (El control remoto envía 12 bits del protocolo de forma seria a un bit x b
   {
      
      a=IrReceiver.decodedIRData.command, HEX;
      IrReceiver.resume();
      if(a==22)
      {
       numero=0; 
       lcd.print (numero);
       
      }
     if(a==12)
      { 
       numero=1; 
       lcd.print(numero);
      }
      if(a==24)
      { 
        numero=2; 
        lcd.print(numero);
      }
      if(a==94)
      { 
        numero=3;
        lcd.print(numero);
      }
      if(a==8)
      { 
        numero=4;
        lcd.print(numero);
      }
      if(a==28)
      { 
        numero=5;
        lcd.print(numero);    
      }
      if(a==90)
      { 
        numero=6;
        lcd.print(numero); 
      }
      if(a==66)
      { 
        numero=7;
        lcd.print(numero); 
      }
      if(a==82)
      { 
        numero=8;
        lcd.print(numero); 
      }
      if(a==74)
      {
        numero=9;
        lcd.print(numero);   
      }
    
      
      
      contador++;
      if(a==22||a==12||a==24||a==94||a==8||a==28||a==90||a==66||a==82||a==74)
        {
          if(contador>1)
          {
          suma*=10;
          suma+=numero;
          }
          else 
          {
          suma+=numero;
          }
        }
        
        if(a==64&&seNal==0)//suma;
        { 
          lcd.print("+");
          resultado1=suma;
          suma=0;
          contador=0;
          seNal=1;
        }
        
        if(a==25)
        {
         lcd.print("=");
          lcd.print(suma+resultado1);
        }
     
     }
}
