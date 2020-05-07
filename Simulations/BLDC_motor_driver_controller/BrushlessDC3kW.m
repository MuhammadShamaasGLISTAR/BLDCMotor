Prated=3000;
Vphase=48;
Nrated=3000;
Irated=Prated/Vphase;
efficiency=0.9;
Ploss=(1-efficiency)*Prated;
Rs=Ploss/(3*Irated*Irated);
Trated=10;

% Rs=2.875;
% Ls=8.5e-3;
% lamda=0.175;
% VoltageConstant=14.;
% TorqueConstant=1.4;
% Inertia=0.8e-3;
% damping=1e-3;
% polepairs=4;

% 0.1
% 1e-3
% 0.01
% 1e-3 1e-3 4


% 0.01
% 1e-4
% 0.01
% 1e-3 1e-3 4