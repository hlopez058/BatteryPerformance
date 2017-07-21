%model that will run a function
% the function wil request the following
% Inputs : E0, K, Q, A, B, R, Vnom,load current L
% Output : Vt(t)

SimTime = 3600;
%Initiate
% Equation
E0=1;
K=1;
Q=10;
A=1;
B=1;
R=1;
L=10;
Vnom = 12;
it=Q; %current current capacty

for t=1:SimTime
% first itteration 
E = E0 - K*(Q/(Q-it))+A*exp(-B*it);

i=(E/R)+L;

it = integrate(i,t);

Vt = (i*R) + Vnom;
end