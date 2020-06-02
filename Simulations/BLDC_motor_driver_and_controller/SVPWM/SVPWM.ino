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

int HALLA=LOW;
int HALLB=LOW;
int HALLC=LOW;

int oldstate, newstate;

double Ts=1e-3;
double vref=25;
double Vdc=50;
double thetam, oldthetam, thetae;
double oldspeed,newspeed;
int Poles=4;

double IA,IB,IC;
double VA,VB,VC;
double Id,Iq,I0;
double Vd,Vq,V0;
double Ialpha,Ibeta;
double Valpha,Vbeta;
double Idref,Iqref,I0ref;
double Vdref,Vqref,V0ref;
double IdErrorNew,IqErrorNew,I0ErrorNew;
double IdErrorOld,IqErrorOld,I0ErrorOld;
double T1,T2,T0; 
int sector;
double kp,ki;
double oldtime,newtime,dt;
double theta0=PI/6;

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

  IA=analogRead(IaPin);
  IB=analogRead(IbPin);
  IC=analogRead(IcPin);

  Ialpha=(2/3)*((1)  *IA+(-1/2)     *IB+(-1/2)      *IC);
  Ibeta =(2/3)*((0)  *IA+(sqrt(3)/2)*IB+(-sqrt(3)/2)*IC);
  I0=    (2/3)*((1/2)*IA+(1/2)      *IB+(1/2)       *IC);

  Id=Ialpha*( cos(thetae))+Ibeta*(sin(thetae));
  Iq=Ialpha*(-sin(thetae))+Ibeta*(cos(thetae));
  
  IqErrorOld=IqErrorNew;
  IdErrorOld=IqErrorNew;
  IqErrorNew=Iq-Iqref;
  IdErrorNew=Id-Idref;
  Vd=kp*IdErrorNew+ki*(0.5)*(IdErrorNew+IdErrorOld)*Ts;
  Vq=kp*IqErrorNew+ki*(0.5)*(IqErrorNew+IqErrorOld)*Ts;;
  vref=sqrt(Vd*Vd+Vq*Vq);
  
  sector=(thetae/(PI/3))+1;
  thetae=thetae-(sector-1)*(PI/3);

  T1=sqrt(3)*Ts*vref*(1/Vdc)*sin((PI/3)-thetae);
  T2=sqrt(3)*Ts*vref*(1/Vdc)*sin(thetae);
  T0=Ts-T1-T2;
  
  if (sector==1)
  {
    writeState(B000);delayMicroseconds(T0/2);
    writeState(B100);delayMicroseconds(T1);
    writeState(B110);delayMicroseconds(T2);
    writeState(B111);delayMicroseconds(T0);
    writeState(B110);delayMicroseconds(T2);
    writeState(B100);delayMicroseconds(T1);
    writeState(B000);delayMicroseconds(T0/2);
  }

  if (sector==2)
  {
    writeState(B000);delayMicroseconds(T0/2);
    writeState(B010);delayMicroseconds(T2);
    writeState(B110);delayMicroseconds(T1);
    writeState(B111);delayMicroseconds(T0);
    writeState(B110);delayMicroseconds(T1);
    writeState(B010);delayMicroseconds(T2);
    writeState(B000);delayMicroseconds(T0/2);
  }
  
  if (sector==3)
  {
    writeState(B000);delayMicroseconds(T0/2);
    writeState(B010);delayMicroseconds(T1);
    writeState(B011);delayMicroseconds(T2);
    writeState(B111);delayMicroseconds(T0);
    writeState(B011);delayMicroseconds(T2);
    writeState(B010);delayMicroseconds(T1);
    writeState(B000);delayMicroseconds(T0/2);
  }
  
  if (sector==4)
  {
    writeState(B000);delayMicroseconds(T0/2);
    writeState(B001);delayMicroseconds(T2);
    writeState(B011);delayMicroseconds(T1);
    writeState(B111);delayMicroseconds(T0);
    writeState(B011);delayMicroseconds(T1);
    writeState(B001);delayMicroseconds(T2);
    writeState(B000);delayMicroseconds(T0/2);
  }
  
  if (sector==5)
  {
    writeState(B000);delayMicroseconds(T0/2);
    writeState(B001);delayMicroseconds(T1);
    writeState(B101);delayMicroseconds(T2);
    writeState(B111);delayMicroseconds(T0);
    writeState(B101);delayMicroseconds(T2);
    writeState(B001);delayMicroseconds(T1);
    writeState(B000);delayMicroseconds(T0/2);
  }
  
  if (sector==6)
  {
    writeState(B000);delayMicroseconds(T0/2);
    writeState(B001);delayMicroseconds(T2);
    writeState(B011);delayMicroseconds(T1);
    writeState(B111);delayMicroseconds(T0);
    writeState(B011);delayMicroseconds(T1);
    writeState(B001);delayMicroseconds(T2);
    writeState(B000);delayMicroseconds(T0/2);
  }
}
