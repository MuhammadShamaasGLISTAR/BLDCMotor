int PhaseaUpperPin=2;
int PhaseaLowerPin=3;
int PhasebUpperPin=4;
int PhasebLowerPin=5;
int PhasecUpperPin=6;
int PhasecLowerPin=7;
int HallaPin=8;
int HallbPin=9;
int HallcPin=10;
int SpeedPin=11;
int CurrentPin=12;

int HALLA=LOW;
int HALLB=LOW;
int HALLC=LOW;

int oldstate, newstate;

double kp,ki, CurrentErrorNew, CurrentErrorOld, OpAmpOutput, Vref;
double oldtime,newtime,dt;
double Current, Currentref;
double Vtriangle, Ttriangle, slope=1, Ts, Vmax=100; 

void writeState (int s)
{
  if ((s&B100)>>2)
  {
    digitalWrite(PhaseaUpperPin, HIGH);digitalWrite(PhaseaLowerPin, LOW);
  }
  else
  {
    digitalWrite(PhaseaUpperPin, LOW);digitalWrite(PhaseaLowerPin, HIGH);
  }
  if ((s&B010)>>1)
  {
    digitalWrite(PhasebUpperPin, HIGH);digitalWrite(PhasebLowerPin, LOW);
  }
  else
  {
    digitalWrite(PhasebUpperPin, LOW);digitalWrite(PhasebLowerPin, HIGH);
  }
  if (s&B001)
  {
    digitalWrite(PhasecUpperPin, HIGH);digitalWrite(PhasecLowerPin, LOW);
  }
  else
  {
    digitalWrite(PhasecUpperPin, LOW);digitalWrite(PhasecLowerPin, HIGH);
  }
}

void setup()
{
  pinMode(PhaseaUpperPin, OUTPUT);
  pinMode(PhaseaLowerPin, OUTPUT);
  pinMode(PhasebUpperPin, OUTPUT);
  pinMode(PhasebLowerPin, OUTPUT);
  pinMode(PhasecUpperPin, OUTPUT);
  pinMode(PhasecLowerPin, OUTPUT);
  
  pinMode(CurrentPin, INPUT);  
  
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

  if((Vtriangle>Vmax)||(Vtriangle<(-Vmax)))
  {
    slope=slope*(-1);  
  }
  Vtriangle=Vtriangle+slope*Ts;
  
  Current=analogRead(CurrentPin);

  CurrentErrorOld=CurrentErrorNew;
  CurrentErrorNew=Current-Currentref;
  Vref=kp*CurrentErrorNew+ki*(0.5)*(CurrentErrorNew+CurrentErrorOld)*Ts;
  if(Vref>Vtriangle)
  {
    OpAmpOutput=1;
  }
  else
  {
    OpAmpOutput=0;
  }

  if (OpAmpOutput>0)
  {
    writeState(newstate);
  }
  else
  {
    writeState(B000);
  }
  delayMicroseconds(Ts);
  
}
