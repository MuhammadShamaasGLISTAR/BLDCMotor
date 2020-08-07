int frequency = 1000; //Set frequency in Hertz

double delayTime = 1000 / (frequency * 2);

void setup()
{
pinMode(2, OUTPUT);  
pinMode(3, OUTPUT);
}

void loop()
{
 digitalWrite(2, LOW);
 digitalWrite(3, HIGH);
 delay(delayTime);

 digitalWrite(2, HIGH);
 digitalWrite(3, LOW);
 delay(delayTime);
}
