double frequency = 1000.0; //Set frequency in Hertz
 
double delayTime = 1000000.0 / (frequency);

unsigned int dutyCycle=500;

void setup()
{
  
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
 delay(1);
 if(!digitalRead(4)){digitalWrite(5,HIGH);}else{digitalWrite(5,LOW);}
 
for (int u=0;u<=1000;u++)
{
 digitalWrite(2, LOW);
 digitalWrite(3, LOW);
 delayMicroseconds(0.5*(1000-dutyCycle));
 
 digitalWrite(2, LOW);
 digitalWrite(3, HIGH);
 delayMicroseconds(dutyCycle);
 if(digitalRead(4)){digitalWrite(5,HIGH);}else{digitalWrite(5,LOW);}
 
 digitalWrite(2, LOW);
 digitalWrite(3, LOW);
 delayMicroseconds(0.5*(1000-dutyCycle));
 
}
 digitalWrite(2, LOW);
 digitalWrite(3, LOW);
 delay(250);
 
}
