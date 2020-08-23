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
int VoltageOutputPin=12;
int SpeedrefPin=13;

int HALLA=LOW;
int HALLB=LOW;
int HALLC=LOW;

int oldstate, newstate;

double kp,ki, SpeedErrorNew, SpeedErrorOld;
double oldtime,newtime,dt;
double thetam, oldthetam, thetae, theta0=PI/6;
double newspeed, oldspeed, Speedref;
double Vref, Vdc, DutyCycle, Ts; 
double Poles=4;

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
  
  pinMode(VoltageOutputPin, OUTPUT);  
  
  pinMode(HallaPin, INPUT);
  pinMode(HallbPin, INPUT);
  pinMode(HallcPin, INPUT);
  pinMode(SpeedrefPin, INPUT);

  digitalWrite(PhaseaUpperPin, LOW);
  digitalWrite(PhaseaLowerPin, LOW);
  digitalWrite(PhasebUpperPin, LOW);
  digitalWrite(PhasebLowerPin, LOW);
  digitalWrite(PhasecUpperPin, LOW);
  digitalWrite(PhasecLowerPin, LOW);
}

void loop()
{
  oldstate=newstate;
  HALLA=digitalRead(HallaPin);
  HALLB=digitalRead(HallbPin);
  HALLC=digitalRead(HallcPin);
  newstate=(HALLC<<2)|(HALLB<<1)|(HALLA);
  
  if(newstate!=oldstate)
  {
    oldtime=newtime;
    newtime=millis();
    dt=newtime-oldtime;
    thetam=oldthetam+theta0;
    oldthetam=thetam;
    if(thetam>(2*PI))
    {
      thetam=thetam-(2*PI);
    }
    oldspeed=newspeed;
    newspeed=theta0/dt;
  }
  else
  {
    dt=millis()-newtime;
    thetam=thetam+newspeed*dt;
  }
  
  thetae=thetam*(Poles/2);

  Speedref=analogRead(SpeedrefPin);
  SpeedErrorOld=SpeedErrorNew;
  SpeedErrorNew=newspeed-Speedref;
  Vref=kp*SpeedErrorNew+ki*(0.5)*(SpeedErrorNew+SpeedErrorOld)*Ts;
  DutyCycle=Vref/Vdc;

  digitalWrite(VoltageOutputPin, HIGH);
  writeState(newstate);
  delayMicroseconds(DutyCycle*Ts);
  digitalWrite(VoltageOutputPin, LOW);
  delayMicroseconds((1-DutyCycle)*Ts);  

}
