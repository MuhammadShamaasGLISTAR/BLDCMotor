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
double Id,Iq,I0;
double Vd,Vq,V0;
double Ialpha,Ibeta;
double Valpha,Vbeta;
double Idref,Iqref,I0ref;
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
  Iqref=kps*SpeedErrorNew+kis*(0.5)*(SpeedErrorNew+SpeedErrorOld)*Ts;
  Idref=0;
  I0ref=0;
    
  IA=analogRead(IaPin);
  IB=analogRead(IbPin);
  IC=analogRead(IcPin);

  Id=(2/3)*((1)  *IA+(-1/2)     *IB+(-1/2)      *IC);
  Iq=(2/3)*((0)  *IA+(sqrt(3)/2)*IB+(-sqrt(3)/2)*IC);
  I0=(2/3)*((1/2)*IA+(1/2)      *IB+(1/2)       *IC);

  IAref=(1)   *(Idref*cos(thetae)-Iqref*sin(thetae))+(0)         *(Idref*sin(thetae)+Iqref*cos(thetae))+(1)*I0;
  IBref=(-1/2)*(Idref*cos(thetae)-Iqref*sin(thetae))+(sqrt(3)/2) *(Idref*sin(thetae)+Iqref*cos(thetae))+(1)*I0;
  ICref=(-1/2)*(Idref*cos(thetae)-Iqref*sin(thetae))+(-sqrt(3)/2)*(Idref*sin(thetae)+Iqref*cos(thetae))+(1)*I0;
  
  gatesignal=B000;
  if (IAref-IA>tolerance){gatesignal|=(1<<2);}
  if (-IAref+IA>tolerance){gatesignal|=(0<<2);}
  if (IBref-IB>tolerance){gatesignal|=(1<<1);}
  if (-IBref+IB>tolerance){gatesignal|=(0<<1);}
  if (ICref-IC>tolerance){gatesignal|=(1<<0);}
  if (-ICref+IC>tolerance){gatesignal|=(0<<0);}
  writeState(gatesignal);delayMicroseconds(Ts);
}
