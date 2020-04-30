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

int Ts=1e-3;
int vref=25;
int Vdc=50;
int Poles=4;


int IA,IB,IC
int IaPin,IbPin,IcPin
int Id,Iq,I0
int Idref,Iqref,I0ref
int Vd,Vq,V0
int IdErrorNew,IqErrorNew,I0ErrorNew
int IdErrorOld,IqErrorOld,I0ErrorOld
  
function writeState (s){
if ((s&100)>>2){digitalWrite(PhaseaUpperPin, HIGH);digitalWrite(PhaseaLowerPin, LOW);}
else{digitalWrite(PhaseaUpperPin, LOW);digitalWrite(PhaseaLowerPin, HIGH);}
if ((s&010)>>1){digitalWrite(PhasebUpperPin, HIGH);digitalWrite(PhasebLowerPin, LOW);}
else{digitalWrite(PhasebUpperPin, LOW);digitalWrite(PhasebLowerPin, HIGH);}
if (s&001){digitalWrite(PhasecUpperPin, HIGH);digitalWrite(PhasecLowerPin, LOW);}
else{digitalWrite(PhasecUpperPin, LOW);digitalWrite(PhasecLowerPin, HIGH);}
}

function getangle(HALLA,HALLB,HALLC){
  //This function calculates rotor angle using Hall Sensor Signals
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

thetae=getangle(HALLA,HALLB,HALLC)*(Poles/2);

  IA=digitalRead(IaPin);
  IB=digitalRead(IbPin);
  IC=digitalRead(IcPin);
  [Id,Iq,I0]=abctodq0(IA,IB,IC,thetae);  

  IqErrorOld=IqErrorNew;
  IdErrorOld=IqErrorNew;
  IqErrorNew=Iq-Iqref;
  IdErrorNew=Td-Idref;
  Vd=PI(IdErrorNew,IdErrorOld);
  Vq=PI(IqErrorNew,IqErrorOld);
  vref=sqrt(Vd*Vd+Vq*Vq);
  
sector=thetae/(pi/3);
thetae=thetae-(sector-1)*(pi/3);

T1=sqrt(3)*Ts*vref*(1/Vdc)*sin((pi/3)-thetae);
T2=sqrt(3)*Ts*vref*(1/Vdc)*sin(thetae);
T0=Ts-T1-T2;

if (sector==1)
{
writeState(000);delayMicroseconds(T0/2);
writeState(100);delayMicroseconds(T1);
writeState(110);delayMicroseconds(T2);
writeState(111);delayMicroseconds(T0);
writeState(110);delayMicroseconds(T2);
writeState(100);delayMicroseconds(T1);
writeState(000);delayMicroseconds(T0/2);
}

if (sector==2)
{
writeState(000);delayMicroseconds(T0/2);
writeState(010);delayMicroseconds(T2);
writeState(110);delayMicroseconds(T1);
writeState(111);delayMicroseconds(T0);
writeState(110);delayMicroseconds(T1);
writeState(010);delayMicroseconds(T2);
writeState(000);delayMicroseconds(T0/2);
}

if (sector==3)
{
writeState(000);delayMicroseconds(T0/2);
writeState(010);delayMicroseconds(T1);
writeState(011);delayMicroseconds(T2);
writeState(111);delayMicroseconds(T0);
writeState(011);delayMicroseconds(T2);
writeState(010);delayMicroseconds(T1);
writeState(000);delayMicroseconds(T0/2);
}

if (sector==4)
{
writeState(000);delayMicroseconds(T0/2);
writeState(001);delayMicroseconds(T2);
writeState(011);delayMicroseconds(T1);
writeState(111);delayMicroseconds(T0);
writeState(011);delayMicroseconds(T1);
writeState(001);delayMicroseconds(T2);
writeState(000);delayMicroseconds(T0/2);
}

if (sector==5)
{
writeState(000);delayMicroseconds(T0/2);
writeState(001);delayMicroseconds(T1);
writeState(101);delayMicroseconds(T2);
writeState(111);delayMicroseconds(T0);
writeState(101);delayMicroseconds(T2);
writeState(001);delayMicroseconds(T1);
writeState(000);delayMicroseconds(T0/2);
}

if (sector==6)
{
writeState(000);delayMicroseconds(T0/2);
writeState(001);delayMicroseconds(T2);
writeState(011);delayMicroseconds(T1);
writeState(111);delayMicroseconds(T0);
writeState(011);delayMicroseconds(T1);
writeState(001);delayMicroseconds(T2);
writeState(000);delayMicroseconds(T0/2);
}
}
