double frequency = 2500.0; //Set frequency in Hertz

double delayTime = 1000000.0 / (frequency);

void setup()
{
pinMode(2, OUTPUT);  
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);  
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);  
pinMode(7, OUTPUT);

}

void loop()
{
 digitalWrite(2, HIGH);
 digitalWrite(3, LOW);
 digitalWrite(4, HIGH);
 digitalWrite(5, LOW);
 digitalWrite(6, HIGH);
 digitalWrite(7, LOW);

 delayMicroseconds(delayTime/4.0);

 digitalWrite(2, LOW);
 digitalWrite(3, LOW);
 digitalWrite(4, LOW);
 digitalWrite(5, LOW);
 digitalWrite(6, LOW);
 digitalWrite(7, LOW);

 delayMicroseconds(delayTime/4.0);

 
 digitalWrite(2, LOW);
 digitalWrite(3, HIGH);
 digitalWrite(4, LOW);
 digitalWrite(5, HIGH);
 digitalWrite(6, LOW);
 digitalWrite(7, HIGH);

 delayMicroseconds(delayTime/4.0);

 digitalWrite(2, LOW);
 digitalWrite(3, LOW);
 digitalWrite(4, LOW);
 digitalWrite(5, LOW);
 digitalWrite(6, LOW);
 digitalWrite(7, LOW);

 delayMicroseconds(delayTime/4.0);

}
