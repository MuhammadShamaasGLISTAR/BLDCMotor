double frequency = 2500.0; //Set frequency in Hertz

double delayTime = (1000000.0 / (frequency * 2.0));//Half Period in microseconds


void setup()
{
pinMode(2, OUTPUT);  
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);  
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);  
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);  
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);  
pinMode(11, OUTPUT);
pinMode(12, OUTPUT);  
pinMode(13, OUTPUT);

digitalWrite(2, HIGH);
digitalWrite(3, HIGH);
digitalWrite(4, HIGH);
digitalWrite(5, HIGH);
digitalWrite(6, HIGH);
digitalWrite(7, HIGH);

}

void loop()
{
digitalWrite(8, LOW);
digitalWrite(9, HIGH);
delayMicroseconds(delayTime/3);
digitalWrite(12, HIGH);
digitalWrite(13, LOW);
delayMicroseconds(delayTime/3);
digitalWrite(10, LOW);
digitalWrite(11, HIGH);
delayMicroseconds(delayTime/3);
digitalWrite(8, HIGH);
digitalWrite(9, LOW);
delayMicroseconds(delayTime/3);
digitalWrite(12, LOW);
digitalWrite(13, HIGH);
delayMicroseconds(delayTime/3);
digitalWrite(10, HIGH);
digitalWrite(11, LOW);
delayMicroseconds(delayTime/3);
}
