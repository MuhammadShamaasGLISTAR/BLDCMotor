//Arduino Mega2560 


int PhaseaUpper=2;
int PhaseaLower=3;
void setup()
{

pinMode(PhaseaUpper, OUTPUT);
pinMode(PhaseaLower, OUTPUT);

digitalWrite(PhaseaUpper, HIGH);
digitalWrite(PhaseaLower, LOW);

}

void loop()
{

}
