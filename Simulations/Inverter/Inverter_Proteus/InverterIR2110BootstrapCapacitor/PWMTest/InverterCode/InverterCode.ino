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
 delay(1000);
 if(!digitalRead(4)){digitalWrite(5,HIGH);}else{digitalWrite(5,LOW);}
 
 digitalWrite(2, LOW);
 analogWrite(3, 1);
 delay(1000);
 
 
}
