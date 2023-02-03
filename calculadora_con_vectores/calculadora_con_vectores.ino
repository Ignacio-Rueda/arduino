
#include <IRremote.h>
#include <LiquidCrystal.h>
#include "ListLib.h"
#include <DHT.h>
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
int resultado=0;
int segundaOperacion=0;
int PosicionX;
long double suma=0;
long double suma2=0;
int contador=0;
int seNal=0;
int simbolo=0;
int simboloIgual=0;
int Rentero=0;
int fin=0;
int coma=0;
int sum=0;
int rest=0;
int mult=0;
int divi=0;
int operacion=0;
double Rdecimal=0;
int acceso=0;
int sensor=13;//vinculamos el sensor al pin 13, que es a la salida a la que la conectamos;
int temperatura,humedad;//declaramos dos varibles;
DHT dht(sensor,DHT11);//Es necesario para indicar a la librería el modelo de sensor que estamos utilizando;
List<double>vector;
void termometro()
{int a=0;
  if (IrReceiver.decode())//Consultamos primero si hay datos disponibles decodificados por la libreria. (El control remoto envía 12 bits del protocolo de forma seria a un bit x b
   {    lcd.setCursor(contador,0);
         a=IrReceiver.decodedIRData.command, HEX;
         IrReceiver.resume();
         if(a==12)
         {lcd.clear();
          lcd.print(temperatura);
          lcd.print("Grados");
         }
         if(a==24)
         {lcd.clear();
          lcd.print(humedad);
          lcd.print("%");
          lcd.print("humedad");
         }
              if(a==64)
          {
            
            resultado=0;
            segundaOperacion=0;
            PosicionX=0;
            suma=0;
            suma2=0;
            contador=0;
            seNal=0;
            simbolo=0;
            simboloIgual=0;
            Rentero=0;
            fin=0;
            Rdecimal=0;
            operacion=0;
            coma=0;
            vector.Clear();
            lcd.clear();
            acceso=0;
            menu();
          }
   }    

  
}
void calculadora()
{
  
    if (IrReceiver.decode())//Consultamos primero si hay datos disponibles decodificados por la libreria. (El control remoto envía 12 bits del protocolo de forma seria a un bit x b
   {    lcd.setCursor(contador,0);
         a=IrReceiver.decodedIRData.command, HEX;
         IrReceiver.resume();
       
         if(a==13)
         {
       
          if(coma==0)
          { a=13;
            vector.Add(a);
            lcd.print(',');
            contador++;
          }
          coma=1;
         }
             if(a==22)
          { a=0;
            vector.Add(a);
            lcd.print(a);
            contador++;
          }
        if(a==12)
          { a=1;
            vector.Add(a);
            lcd.print(a);
            contador++;
          }
        if(a==24)
          {
            a=2;
            vector.Add(a);
            lcd.print(a);
            contador++;
          }
            if(a==94)
          {
            a=3;
            vector.Add(a);
            lcd.print(a);
            contador++;
          }
            if(a==8)
          {
            a=4;
            vector.Add(a);
            lcd.print(a);
            contador++;
          }
            if(a==28)
          {
            a=5;
            vector.Add(a);
            lcd.print(a);
            contador++;
          }
            if(a==90)
          {
            a=6;
            vector.Add(a);
            lcd.print(a);
            contador++;
          }
            if(a==66)
          {
            a=7;
            vector.Add(a);
            lcd.print(a);
            contador++;
          }
            if(a==82)
          {
            a=8;
            vector.Add(a);
            lcd.print(a);
            contador++;
          }
            if(a==74)
          {
            a=9;
            vector.Add(a);
            lcd.print(a);
            contador++;
          }

        if(a==71&&fin==0)
          {
           vector.RemoveLast();
           contador=contador-1;
           lcd.setCursor(contador,0);
           lcd.print(" ");
           
          }   

      if(a==70&&sum==0)
      {
        operacion=1;
        
      }
      if(a==21&&rest==0)
      {
        operacion=2;
        
      }
      if(a==67&&mult==0)
      {
        operacion=3;
        
      }
      if(a==68&&divi==0)
      {
        operacion=4;
        
      }
      
        vector.Trim();
         if(a==70&&sum==0||a==21&&rest==0||a==67&&mult==0||a==68&&divi==0)
          {
            if (operacion==1&&sum==0)
            {
              lcd.print("+");
              sum=1;
              rest=1;
              mult=1;
              divi=1;
            }
            if (operacion==2&&rest==0)
            {
              lcd.print("-");
              rest=1;
              sum=1;
              mult=1;
              divi=1;
            }
            if (operacion==3&&mult==0)
            {
              lcd.print("x");
              mult=1;
              sum=1;
              rest=1;
              divi=1;
            }
            if (operacion==4&&divi==0)
            {
              lcd.print("/");
              divi=1;
              mult=1;
              sum=1;
              rest=1;
            }
            
            contador++;
            for(int x=0;x<vector.Capacity();x++)
            {
              if(x==0)
               { if(vector[x]==13)
                  {
                    vector[x+1]=vector[x+1]/10;
                    suma+=vector[x];
                    seNal=1;
                  }
  
                if(vector[x]!=13)
                  {
                    suma+=vector[x];
                  }
                 
               }
               if(x>0)
               {
                if(vector[x]==13)
                  {
                    vector[x+1]=vector[x+1]/10;
                    suma+=vector[x+1];
                    seNal=1;
                  }
  
                if(vector[x]!=13&&seNal==0)
                  {
                    suma*=10;
                    suma+=vector[x]; 
                  }
               }
              
                  PosicionX=x; 
               coma=0;
                }
                  simbolo=1; 
            }
          seNal=0;
          
          
          if(a==25&&simboloIgual==0)
          {
            
            for(int x=PosicionX+1;x<vector.Capacity();x++)
            {
              if(x==PosicionX+1)
                 { 
                  if(vector[x]==13)
                  {
                    vector[x+1]=vector[x+1]/10;
                    suma2+=vector[x];
                    seNal=1;
                  }
  
                  if(vector[x]!=13)
                  {
                    suma2+=vector[x];
                  }
                 }
                 
               if(x>PosicionX+1)
                 {
                if(vector[x]==13)
                  {
                    vector[x+1]=vector[x+1]/10;
                    suma2+=vector[x+1];
                    seNal=1;
                  }
  
                if(vector[x]!=13&&seNal==0)
                  {
                    suma2*=10;
                    suma2+=vector[x];
                    
                     
                  }
                  
               }
              
             } 
             lcd.print("=");
             contador++;
             
             if(operacion==1)
             {
             Rdecimal=suma+suma2;
             Rentero=Rdecimal;
             if(Rdecimal>Rentero)
             {lcd.print(Rdecimal);}
             else{lcd.print(Rentero);}
              contador++;
             }
             if(operacion==2)
             {
             Rdecimal=suma-suma2;
             Rentero=Rdecimal;
             if(Rdecimal>Rentero)
             {lcd.print(Rdecimal);}
             else{lcd.print(Rentero);}
              contador++;
             }
             if(operacion==3)
             {
             Rdecimal=suma*suma2;
             Rentero=Rdecimal;
             if(Rdecimal>Rentero)
             {lcd.print(Rdecimal);}
             else{lcd.print(Rentero);}
              contador++;
             }
             if(operacion==4)
             {
             Rdecimal=suma/suma2;
             Rentero=Rdecimal;
             if(Rdecimal>Rentero)
             {lcd.print(Rdecimal);}
             else{lcd.print(Rentero);}
              contador++;
             }
             simboloIgual=1;
             fin=1;
             lcd.setCursor(0,1);
             lcd.print("Volver a menu");
          }
          
          
            if(a==64)
          {
            
            resultado=0;
            segundaOperacion=0;
            PosicionX=0;
            suma=0;
            suma2=0;
            contador=0;
            seNal=0;
            simbolo=0;
            simboloIgual=0;
            Rentero=0;
            fin=0;
            Rdecimal=0;
            operacion=0;
            coma=0;
            sum=0;
            rest=0;
            divi=0;
            mult=0;
            vector.Clear();
            lcd.clear();
            acceso=0;
            menu();
          }
         
} 
  
}
void menu()
{
 int a=0;
 
  if (IrReceiver.decode())//Consultamos primero si hay datos disponibles decodificados por la libreria. (El control remoto envía 12 bits del protocolo de forma seria a un bit x b
   {    lcd.setCursor(0,0);
         a=IrReceiver.decodedIRData.command, HEX;
         IrReceiver.resume();
          
         if(acceso==0)
          { 
           lcd.print("1" "calculadora");
           lcd.setCursor(0,1);
           lcd.print("2" "temperatura");
          }
       
          if(a==12)
          {
            acceso=1;
            lcd.clear();
          }  
          if(a==24)
          {
            acceso=2;
            lcd.clear(); 
            lcd.print("1:Temperatura");
            lcd.setCursor(0,1);
            lcd.print("2:Humedad");
          
          }
        
            
   }
   
   while(acceso==1)
   {
   calculadora();
   }
   while(acceso==2)
   {
    termometro();
   }
   
}

void setup()
{
  
    dht.begin(); 
    humedad=dht.readHumidity();
    temperatura=dht.readTemperature();
  
   
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);//Inciamos la recepcion de datos;
   analogWrite(V0,50);//REGULAMOS EL CONTRASTE (EN 50 YA ESTÁ BIEN)EL CONTRASTE CON EL PWM NO FUNCIONA CREO QUE POR ESTA FUNCION (IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);)
  lcd.begin(16, 2);//indicamos tamaño de la lcd, columnas y filas;
  lcd.setCursor(0,0);
  lcd.print("Bienvenido");

  
}

void loop()
{  
  menu();
  
}
