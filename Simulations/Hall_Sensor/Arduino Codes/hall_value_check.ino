/*

int SensorA = 8;    // 3 hall sensors on port D8,D9,D10
int SensorB = 9;
int SensorC = 10;
int fase =1;
int a,b,c;
int counter=0;
void setup() {  
  DDRD  |= B11111111;  
  DDRB  |= B00000000; // Sets D2, D3, D4, D5, D6 and D7 as OUTPUT 1=output
  PORTD &= B00000000;  // D2-D7 LOW
  PORTB &= B00000000;
pinMode(SensorA,INPUT_PULLUP);
pinMode(SensorB,INPUT_PULLUP);
pinMode(SensorC,INPUT_PULLUP);
Serial.begin(9600);
}
void loop() 
{  
if(a=digitalRead(SensorB) == LOW)
counter ++;
else 
{
counter--; 
}
if(b=digitalRead(SensorC)== HIGH)
{
digitalWrite(13, HIGH);
}
else 
{
digitalWrite(13, LOW); 
}
if(c=digitalRead(SensorC)== HIGH)
digitalWrite(53, HIGH);
else 
{
digitalWrite(53, LOW); 
}
Serial.println(a);
//Serial.print(counter);
//Serial.println(c);
 }  // end of sw              
 */
