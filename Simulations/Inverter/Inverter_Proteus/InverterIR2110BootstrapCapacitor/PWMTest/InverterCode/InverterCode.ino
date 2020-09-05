#include <PWM.h>

 
//double delayTime = 1000000.0 / (frequency);

unsigned int dutyCycle=500;

int32_t frequency = 50; //frequency (in Hz)


void setup()
{
 pinMode(6, OUTPUT);
   
    InitTimersSafe(); 

  bool success = SetPinFrequencySafe(3, frequency);
 if(success) {
    digitalWrite(6, HIGH);    
  }

pinMode(2, OUTPUT);  
pinMode(3, OUTPUT);
pinMode(4, INPUT);  
pinMode(5, OUTPUT);

digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(5, LOW);

}

void loop()
{

 digitalWrite(2, HIGH);
 digitalWrite(3, LOW);
 delay(1000);
 if(!digitalRead(4)){digitalWrite(5,HIGH);}else{digitalWrite(5,LOW);}
 
 digitalWrite(2, LOW);
 //analogWrite(3, 1);
   pwmWrite(3, 200);

 delay(1000);
 
 
}
