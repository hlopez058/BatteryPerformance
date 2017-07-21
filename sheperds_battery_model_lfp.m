% LFP 
%SHEPERDS_BATTERY_MODEL Summary of this function goes here
%   Detailed explanation goes here

SimTime = 3600;
%Initiate
% Equation
E0=13.8798; % Battery constant voltage(V)
K=0.012786; % Polarisation voltage (V)
Q=10; % Battery capacity (Ah)
A=1.0749; % Exponential zone amplitude (V)
B=8.1416; % Exponential zone time constant inverse (Ah)^-1
R=0.017067; % Internal Resitance 
L=10; % Load Current
Vnom = 12.8; % Nominal Voltage

it=Q-.5; %current current capacity
i =[] ;% active current
SOC = []; %state of charge
Vbatt = []; %battery voltage
for t=1:SimTime
    % first use sheperds approximation 
    E = E0 - K*(Q/(Q-it))+A*exp(-B*it);

    %use the load to caluclate the current draw
    i(end+1,:)=(E/R)+L;
    
    % Actual battery charge (Ah)
    % integrate current to this point in time
    it = trapz(i);
    
    % state of charge is the current capacity "it"
    SOC(end+1,:) = it;

    % battery terminal voltage can be calcualted with 
    % current draw from load and internal resistance
    Vbatt(end+1,:) = (i(end)*R) + (Vnom+2);
    
end
plot(SOC,Vbatt);


