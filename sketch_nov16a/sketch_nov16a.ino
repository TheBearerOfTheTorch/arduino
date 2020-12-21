#include <DS18B20.h>
#include <Wiegand.h>
#include <OneWire.h>


DS18B20 ds(2);
WIEGAND wg;

int buzzerPin = 12;
int ledPin = 13;
int data1 = 2;
int data2 = 3;

void setup() {
  Serial.begin(9600);  
  
  // default Wiegand Pin 2 and Pin 3 see image on README.md
  // for non UNO board, use wg.begin(pinD0, pinD1) where pinD0 and pinD1 
  // are the pins connected to D0 and D1 of wiegand reader respectively.

  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin,OUTPUT);
  pinMode(data1,INPUT);
  pinMode(data2,INPUT);
  wg.begin();
}

void loop() {
  while (ds.selectNext()) 
  {
    //get temperature thats more 30
    if(ds.getTempC() > 31.0)
    {
      Serial.println("Reading the temperature thats more 31 C` ....");
      Serial.println(ds.getTempC());
      tone(buzzerPin,700);
      digitalWrite(ledPin,HIGH);
      delay(1000);

      noTone(buzzerPin);
      digitalWrite(ledPin,LOW);
      delay(3000);
    }
    else
    {
      Serial.println("The temperature is low....");
      tone(buzzerPin,100);
      digitalWrite(ledPin,HIGH);
      delay(3000);
      noTone(buzzerPin);
      digitalWrite(ledPin,LOW);
      
    }
    
  }
  
}
