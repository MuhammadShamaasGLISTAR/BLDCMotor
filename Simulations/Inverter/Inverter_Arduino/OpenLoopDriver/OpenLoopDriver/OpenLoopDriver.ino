//Brushless DC Motor Open Loop Drive 

int PhaseaUpper=2;
int PhaseaLower=3;
int PhasebUpper=4;
int PhasebLower=5;
int PhasecUpper=6;
int PhasecLower=7;

int Halla=8
int Hallb=9
int Hallc=10

void setup()
{
pinMode(PhaseaUpper, OUTPUT);
pinMode(PhaseaLower, OUTPUT);
pinMode(PhasebUpper, OUTPUT);
pinMode(PhasebLower, OUTPUT);
pinMode(PhasecUpper, OUTPUT);
pinMode(PhasecLower, OUTPUT);  

pinMode(Halla, INPUT);
pinMode(Hallb, INPUT);
pinMode(Hallc, INPUT);

digitalWrite(PhaseaUpper, LOW);
digitalWrite(PhaseaLower, LOW);
digitalWrite(PhasebUpper, LOW);
digitalWrite(PhasebLower, LOW);
digitalWrite(PhasecUpper, LOW);
digitalWrite(PhasecLower, LOW);

}

void loop()
{
digitalWrite(PhaseaUpper, digitalRead(Halla));
digitalWrite(PhaseaLower, !digitalRead(Halla));
digitalWrite(PhasebUpper, digitalRead(Hallb));
digitalWrite(PhasebLower, !digitalRead(Hallb));
digitalWrite(PhasecUpper, digitalRead(Hallc));
digitalWrite(PhasecLower, !digitalRead(Hallc));
}
