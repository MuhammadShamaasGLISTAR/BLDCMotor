//Brushless DC Motor Current Control Drive
//Arduino Mega2560 

/*
int PhaseaUpper=2;
int PhaseaLower=3;
int PhasebUpper=4;
int PhasebLower=5;
int PhasecUpper=6;
int PhasecLower=7;

//These pins have attached interrupts 
int Halla=18;
int Hallb=19;
int Hallc=20;

//States of HALL Sensors 
volatile int HALLA = LOW;
volatile int HALLB = LOW;
volatile int HALLC = LOW;

void setup()
{

  Serial.begin(9600);
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

HALLA = digitalRead(Halla);
HALLB = digitalRead(Hallb);
HALLC = digitalRead(Hallc);

attachInterrupt(digitalPinToInterrupt(Halla), blinka, CHANGE);
attachInterrupt(digitalPinToInterrupt(Hallb), blinkb, CHANGE);
attachInterrupt(digitalPinToInterrupt(Hallc), blinkc, CHANGE);

}

void loop()
{

  HALLA=digitalRead(Halla);
  HALLB=digitalRead(Hallb);
  HALLC=digitalRead(Hallc);
  int newstate=(HALLC<<2)|(HALLB<<1)|(HALLA);
  Serial.println(newstate);

digitalWrite(PhaseaUpper, HALLA);
digitalWrite(PhaseaLower, !HALLA);
digitalWrite(PhasebUpper, HALLB);
digitalWrite(PhasebLower, !HALLB);
digitalWrite(PhasecUpper, HALLC);
digitalWrite(PhasecLower, !HALLC);



}

void blinka() {HALLA = !HALLA;}
void blinkb() {HALLB = !HALLB;}
void blinkc() {HALLC = !HALLC;}
*/



int PhaseaUpperPin=2;
int PhaseaLowerPin=3;
int PhasebUpperPin=4;
int PhasebLowerPin=5;
int PhasecUpperPin=6;
int PhasecLowerPin=7;

int HallaPin=18; int HallbPin=19; int HallcPin=20;

int HALLA=LOW;
int HALLB=LOW;
int HALLC=LOW;

int oldstate, newstate;

void writestate (double sa, double sb, double sc)
{
  if (sa==1)    {digitalWrite(PhaseaUpperPin, HIGH);digitalWrite(PhaseaLowerPin, LOW);}
  if (sa==(-1)) {digitalWrite(PhaseaUpperPin, LOW) ;digitalWrite(PhaseaLowerPin, HIGH);}
  if (sa==0)    {digitalWrite(PhaseaUpperPin, LOW) ;digitalWrite(PhaseaLowerPin, LOW);}
  if (sb==1)    {digitalWrite(PhasebUpperPin, HIGH);digitalWrite(PhasebLowerPin, LOW);}
  if (sb==(-1)) {digitalWrite(PhasebUpperPin, LOW) ;digitalWrite(PhasebLowerPin, HIGH);}
  if (sb==0)    {digitalWrite(PhasebUpperPin, LOW) ;digitalWrite(PhasebLowerPin, LOW);}
  if (sc==1)    {digitalWrite(PhasecUpperPin, HIGH);digitalWrite(PhasecLowerPin, LOW);}
  if (sc==(-1)) {digitalWrite(PhasecUpperPin, LOW) ;digitalWrite(PhasecLowerPin, HIGH);}
  if (sc==0)    {digitalWrite(PhasecUpperPin, LOW) ;digitalWrite(PhasecLowerPin, LOW);}
}


void setup()
{

Serial.begin(9600);

pinMode(PhaseaUpperPin, OUTPUT);
pinMode(PhaseaLowerPin, OUTPUT);
pinMode(PhasebUpperPin, OUTPUT);
pinMode(PhasebLowerPin, OUTPUT);
pinMode(PhasecUpperPin, OUTPUT);
pinMode(PhasecLowerPin, OUTPUT);  

pinMode(HallaPin, INPUT);
pinMode(HallbPin, INPUT);
pinMode(HallcPin, INPUT);

digitalWrite(PhaseaUpperPin, LOW);
digitalWrite(PhaseaLowerPin, LOW);
digitalWrite(PhasebUpperPin, LOW);
digitalWrite(PhasebLowerPin, LOW);
digitalWrite(PhasecUpperPin, LOW);
digitalWrite(PhasecLowerPin, LOW);

}

void loop()
{
  HALLA=digitalRead(HallaPin);
  HALLB=digitalRead(HallbPin);
  HALLC=digitalRead(HallcPin);
  newstate=(HALLC<<2)|(HALLB<<1)|(HALLA);
  Serial.println(newstate);
if (newstate==0){writestate(0,0,0);}
if (newstate==1){writestate(0,-1,1);}
if (newstate==2){writestate(-1,1,0);}
if (newstate==3){writestate(-1,0,1);}
if (newstate==4){writestate(1,0,-1);}
if (newstate==5){writestate(1,-1,0);}
if (newstate==6){writestate(0,1,-1);}
if (newstate==7){writestate(0,0,0);}
}
