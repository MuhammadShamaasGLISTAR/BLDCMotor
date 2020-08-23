//Brushless DC Motor Open Loop Drive 

int PhaseaUpperPin=2;
int PhaseaLowerPin=3;
int PhasebUpperPin=4;
int PhasebLowerPin=5;
int PhasecUpperPin=6;
int PhasecLowerPin=7;

int HallaPin=8;
int HallbPin=9;
int HallcPin=10;

int HALLA=LOW;
int HALLB=LOW;
int HALLC=LOW;

int oldstate, newstate;

void writestate (int sa, int sb, int sc)
{
  if (sa==1)    {digitalWrite(PhaseaUpperPin, HIGH);digitalWrite(PhaseaLowerPin, LOW);}
  if (sa==(-1)){digitalWrite(PhaseaUpperPin, LOW) ;digitalWrite(PhaseaLowerPin, HIGH);}
  if (sa==0)    {digitalWrite(PhaseaUpperPin, LOW) ;digitalWrite(PhaseaLowerPin, LOW);}
  if (sb==1)    {digitalWrite(PhasebUpperPin, HIGH);digitalWrite(PhasebLowerPin, LOW);}
  if (sb==(-1)){digitalWrite(PhasebUpperPin, LOW) ;digitalWrite(PhasebLowerPin, HIGH);}
  if (sb==0)    {digitalWrite(PhasebUpperPin, LOW) ;digitalWrite(PhasebLowerPin, LOW);}
  if (sc==1)    {digitalWrite(PhasecUpperPin, HIGH);digitalWrite(PhasecLowerPin, LOW);}
  if (sc==(-1)){digitalWrite(PhasecUpperPin, LOW) ;digitalWrite(PhasecLowerPin, HIGH);}
  if (sc==0)    {digitalWrite(PhasecUpperPin, LOW) ;digitalWrite(PhasecLowerPin, LOW);}
}

void setup()
{
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

if (newstate==B000){writestate(0,0,0);}
if (newstate==B001){writestate(0,-1,1);}
if (newstate==B010){writestate(-1,1,0);}
if (newstate==B011){writestate(-1,0,1);}
if (newstate==B100){writestate(1,0,-1);}
if (newstate==B101){writestate(1,-1,0);}
if (newstate==B110){writestate(0,1,-1);}
if (newstate==B111){writestate(0,0,0);}
}
