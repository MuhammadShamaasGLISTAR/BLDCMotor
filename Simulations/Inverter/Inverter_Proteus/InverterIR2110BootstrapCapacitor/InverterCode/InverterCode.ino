double frequency = 1000.0; //Set frequency in Hertz
 
double delayTime = 1000000.0 / (frequency);

unsigned int dutyCycle=10;

void setup()
{
  
pinMode(2, OUTPUT);  
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);  
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);  
pinMode(7, OUTPUT);

digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(7, LOW);

pinMode(22, INPUT);
pinMode(24, INPUT);
pinMode(26, INPUT);
}

void loop()
{

 digitalWrite(2, HIGH);
 digitalWrite(3, LOW);
 digitalWrite(4, HIGH);
 digitalWrite(5, LOW);
 digitalWrite(6, HIGH);
 digitalWrite(7, LOW);


 delay(1);
 
for (int u=0;u<=1000;u++)
{
 digitalWrite(2, LOW);
 digitalWrite(3, LOW);
 digitalWrite(4, LOW);
 digitalWrite(5, LOW);
 digitalWrite(6, LOW);
 digitalWrite(7, LOW);

 delayMicroseconds(0.5*(1000-dutyCycle));
 
 digitalWrite(2, LOW);
 digitalWrite(3, HIGH);
 digitalWrite(4, LOW);
 digitalWrite(5, HIGH);
 digitalWrite(6, LOW);
 digitalWrite(7, HIGH);

 delayMicroseconds(dutyCycle);
 
 
 digitalWrite(2, LOW);
 digitalWrite(3, LOW);
 digitalWrite(4, LOW);
 digitalWrite(5, LOW);
 digitalWrite(6, LOW);
 digitalWrite(7, LOW);

 delayMicroseconds(0.5*(1000-dutyCycle));
 
}
 digitalWrite(2, LOW);
 digitalWrite(3, LOW);
 digitalWrite(4, LOW);
 digitalWrite(5, LOW);
 digitalWrite(6, LOW);
 digitalWrite(7, LOW);
 delay(250);
 
}
