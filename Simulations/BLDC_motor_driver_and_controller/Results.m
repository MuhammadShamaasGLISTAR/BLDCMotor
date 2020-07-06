clc;clear all;
Efficiency_Simulation=[99.01046084 99.40278699 98.90241469 98.43551028 96.84619816 93.29082884 93.09619913 95.06941463 95.39892621 93.52073476 93.38646602 93.33482442 92.80958722 92.98009783 92.00013634 92.01017003 91.28855561 91.4196779 89.0474354 86.64734999 85.34214358 80.43763235 73.06119584];
Pout_Simulation=[350.2 449.4 495.6 541.1 672.5 951.1 1107.1 1328.5 1528.1 1680.1 1886.5 2086.5 2300.1 2490.1 2699.1 2895.1 3116.5 3377.5 3463.5 3588.5 3810.1 3988.5 4163.1];
Speed_Simulation=[4420.5 4376.4 4354.2 4332.7 4268.4 4126.4 4050.1 3958.2 3870.5 3787.1 3691.5 3601.5 3500.2 3418.1 3313.2 3225.9 3125.5 2956.1 2812.1 2604.5 2357.8 2041.2 1715.1];
Torque_Simulation=[0.7 0.9 1 1.1 1.4 2.1 2.5 3 3.5 4 4.6 5.2 5.9 6.5 7.3 8 8.9 10 10.9 12.2 14 16.8 20.8];
Pin_Simulation=[353.7 452.1 501.1 549.7 694.4 1019.5 1189.2 1397.4 1601.8 1796.5 2020.1 2235.5 2478.3 2678.1 2933.8 3146.5 3413.9 3694.5 3889.5 4141.5 4464.5 4958.5 5698.1];
Iin_Simulation=[7.37 9.42 10.44 11.45 14.46 21.24 24.78 29.11 33.37 37.43 42.08 46.57 51.63 55.78 61.12 65.55 71.12 76.98 81.06 86.25 93.02 103.3 118.7];



Efficiency_Actual=[51.98 58.96 61.19 63.77 70.73 77.65 79.95 84.38 87.64 87.89 87.50 89.59 90.91 90.89 92.07 90.64 90.14 90.53 89.99 88.98 84.99 85.37 73.72];
Pout_Actual=[371.0 433.0 494.0 554.0 676.0 975.0 1152.0 1384.0 1615.0 1841.0 2061.0 2338.0 2610.0 2866.0 3180.0 3425.0 3773.0 4098.0 4084.0 4050.0 3859.0 3812.0 3284.0];
Speed_Actual=[4489 4487 4480 4472 4461 4421 4396 4366 4339 4308 4267 4234 4200 4159 4119 4078 4017 3914 3578 3170 2632 2167 1508];
Torque_Actual=[0.7 0.9 1.0 1.1 1.4 2.1 2.5 3.0 3.5 4.0 4.6 5.2 5.9 6.5 7.3 8.0 8.9 10.0 10.9 12.2 14.0 16.8 20.8];
Pin_Actual=[713.76 734.40 807.36 868.80 955.68 1255.68 1440.96 1640.16 1842.72 2094.72 2355.36 2609.76 2870.88 3153.12 3454.08 3778.56 4185.60 4526.88 4538.40 4551.84 4540.80 4465.44 4454.88];
Iin_Actual=[14.87 15.30 16.82 18.10 19.91 26.16 30.02 34.17 38.3 43.64 49.07 54.37 59.81 65.69 71.96 78.72 87.20 94.31 94.55 94.83 94.60 93.03 92.81];

subplot(3,2,1);
hold on;
plot(Torque_Simulation,Pin_Simulation);
plot(Torque_Actual,Pin_Actual,'r');
grid on;xlabel('Torque (N.m)');ylabel('Input Power (W)');legend('Simulation','Actual');

subplot(3,2,2);
hold on;
plot(Torque_Simulation,Pout_Simulation);
plot(Torque_Actual,Pout_Actual,'r');
grid on;xlabel('Torque (N.m)');ylabel('Output Power (W)');legend('Simulation','Actual');

subplot(3,2,3);
hold on;
plot(Torque_Simulation,Efficiency_Simulation);
plot(Torque_Actual,Efficiency_Actual,'r');
grid on;xlabel('Torque (N.m)');ylabel('Efficiency (%)');legend('Simulation','Actual');

subplot(3,2,4);
hold on;
plot(Torque_Simulation,Iin_Simulation);
plot(Torque_Actual,Iin_Actual,'r');
grid on;xlabel('Torque (N.m)');ylabel('Input Current (A)');legend('Simulation','Actual');

subplot(3,2,5);
hold on;
plot(Torque_Simulation,Speed_Simulation);
plot(Torque_Actual,Speed_Actual,'r');
grid on;xlabel('Torque (N.m)');ylabel('Speed (rpm)');legend('Simulation','Actual');
