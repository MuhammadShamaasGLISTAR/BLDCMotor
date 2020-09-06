#include <PWM.h>

 
//double delayTime = 1000000.0 / (frequency);

unsigned int dutyCycle=500;

int32_t frequency = 10000; //frequency (in Hz)


void setup()
{
   
    InitTimersSafe(); 

  bool success = SetPinFrequencySafe(6, frequency);
  success = SetPinFrequencySafe(7, frequency);
  success = SetPinFrequencySafe(8, frequency);
  success = SetPinFrequencySafe(9, frequency);
  success = SetPinFrequencySafe(10, frequency);
  success = SetPinFrequencySafe(11, frequency);
  success = SetPinFrequencySafe(12, frequency);
  success = SetPinFrequencySafe(13, frequency);
  success = SetPinFrequencySafe(14, frequency);
  success = SetPinFrequencySafe(15, frequency);
  success = SetPinFrequencySafe(16, frequency);
pinMode(2, OUTPUT);  
//pinMode(3, OUTPUT);
pinMode(4, INPUT);  
pinMode(5, OUTPUT);

digitalWrite(2, LOW);
//digitalWrite(3, LOW);
digitalWrite(5, LOW);

}

void loop()
{

 /*digitalWrite(2, HIGH);
 digitalWrite(3, LOW);
 pwmWrite(3, 0);
 delay(1000);
 if(!digitalRead(4)){digitalWrite(5,HIGH);}else{digitalWrite(5,LOW);}
 */
 digitalWrite(2, LOW);
 //analogWrite(3, 1);
   pwmWrite(6, 1);
   pwmWrite(7, 1);
   pwmWrite(8, 1);
   pwmWrite(9, 1);
   pwmWrite(10, 1);
   pwmWrite(11, 1);
   pwmWrite(12, 1);
   pwmWrite(13, 1);
 
 //delay(1000);
 
 
}
