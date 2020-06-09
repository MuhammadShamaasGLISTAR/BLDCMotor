int PhaseaUpperPin=2;
int PhaseaLowerPin=3;
int PhasebUpperPin=4;
int PhasebLowerPin=5;
int PhasecUpperPin=6;
int PhasecLowerPin=7;
int HallaPin=8;
int HallbPin=9;
int HallcPin=10;
int IaPin=11;
int IbPin=12;
int IcPin=13;
int SpeedrefPin=14;

int HALLA=LOW;
int HALLB=LOW;
int HALLC=LOW;

int oldstate, newstate, gatesignal;

double Ts=1e-3;
double vref=25;
double Vdc=50;
double thetam, oldthetam, thetae;
double oldspeed,newspeed, Speedref;
int Poles=4;

double IA,IB,IC;
double VA,VB,VC;
double EMFA,EMFB,EMFC;
double Id,Iq,I0;
double Vd,Vq,V0;
double Ialpha,Ibeta;
double Valpha,Vbeta;
double Iref;
double Vdref,Vqref,V0ref;
double IAref,IBref,ICref;
double IdErrorNew,IqErrorNew,I0ErrorNew;
double IdErrorOld,IqErrorOld,I0ErrorOld;
double SpeedErrorNew,SpeedErrorOld;
double T1,T2,T0; 
int sector;
double kps,kis;
double oldtime,newtime,dt;
double theta0=PI/6;
double tolerance=0.01;

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
  Iref=kps*SpeedErrorNew+kis*(0.5)*(SpeedErrorNew+SpeedErrorOld)*Ts;
    
  IA=analogRead(IaPin);
  IB=analogRead(IbPin);
  IC=analogRead(IcPin);

  if (newstate==B000){EMFA=0;EMFB=0;EMFC=0;}
  if (newstate==B001){EMFA=0;EMFB=-1;EMFC=1;}
  if (newstate==B010){EMFA=-1;EMFB=1;EMFC=0;}
  if (newstate==B011){EMFA=-1;EMFB=0;EMFC=1;}
  if (newstate==B100){EMFA=1;EMFB=0;EMFC=-1;}
  if (newstate==B101){EMFA=1;EMFB=-1;EMFC=0;}
  if (newstate==B110){EMFA=0;EMFB=1;EMFC=-1;}
  if (newstate==B111){EMFA=0;EMFB=0;EMFC=0;}

  IAref=EMFA*Iref;
  IBref=EMFB*Iref;
  ICref=EMFC*Iref;
  
  gatesignal=B000;
  if (IAref-IA>tolerance){gatesignal|=(1<<2);}
  if (-IAref+IA>tolerance){gatesignal|=(0<<2);}
  if (IBref-IB>tolerance){gatesignal|=(1<<1);}
  if (-IBref+IB>tolerance){gatesignal|=(0<<1);}
  if (ICref-IC>tolerance){gatesignal|=(1<<0);}
  if (-ICref+IC>tolerance){gatesignal|=(0<<0);}
  writeState(gatesignal);delayMicroseconds(Ts);
}
