clear all; close all; tic
path(path,'Functions')

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 0) Select model
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
model = 'V5_GrFeP_A123_2p3Ah';  % graphite/iron phosphate model
%model = 'V1_GrNCA_NRELphev';   % uncomment to run graphite/NCA model instead

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 1) Load model parameters for battery life (degradation) & performance (ocv relationships)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
[lifeMdl,perfMdl] = func_LifeMdl_LoadParameters(model);  % graphite/iron phosphate model

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 2) Load example battery cycling profile (time, soc, current, voltage, temperature)
%     * Requires 1 full day of data to correctly capture time/cycling interaction
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
cycledata  = xlsread('ExampleInput_VehicleDriveCycle.xlsx');
cycle.tsec = cycledata(:,1);  % (sec)
cycle.soc  = cycledata(:,2);  % (0 to 1), 0=fully discharged, 1=fully charged
cycle.I    = cycledata(:,3);  % (Amps)*, I>0 is discharge, I<0 is charge   * cycle.I not used in V1_GrNCA model
cycle.V    = cycledata(:,4);  % (Volts/cell)**                             **cycle.V not used in either V1_GrNCA or V5_GrFeP models
cycle.TdegC= cycledata(:,5);  % (degC)

% scale example current if simulating smaller A123 2.3Ah cell
if strcmp(model,'V5_GrFeP_A123_2p3Ah')
    cycle.I = cycle.I*2.3/57.8;
end

% plot the duty cycle and temperature
figure
  subplot(2,2,1); plot(cycle.tsec,cycle.I);     xlabel('cycle.tsec (s)'); ylabel('cycle.I (Amps)')
  title('Example 1-day Battery Duty-cycle: PHEV40 with Gr/NCA chemistry Li-ion battery, 16kWh/57.8Ah/75cells)')
  subplot(2,2,2); plot(cycle.tsec,cycle.soc);   xlabel('cycle.tsec (s)'); ylabel('cycle.soc')
  subplot(2,2,3); plot(cycle.tsec,cycle.V);     xlabel('cycle.tsec (s)'); ylabel('cycle.V (Volts)')
  subplot(2,2,4); plot(cycle.tsec,cycle.TdegC); xlabel('cycle.tsec (s)'); ylabel('cycle.TdegC (^oCelcius)')

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 3) Calculate additional stress statistics using Rainflow algorithm
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
cycle = func_LifeMdl_StressStatistics(lifeMdl,perfMdl,cycle);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 4) Timesteps for state-of-life simulation
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
lifeSim.tdays_life = [ 0 : 7 : 365*10 ]; % (days) simulation results are returned once-per-week over 10 years in this example

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% (Optional Examples) Uncomment lines below for different temperature, cycle, or sim time
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%cycle.TdegC= 20;                   % uncomment to simulate result for constant 20degC temperature
%cycle.dsoc_i=1; cycle.ncycle_i=1;  % uncomment to simulate result for one 100% DoD cycle/day
%lifeSim.tdays_life = 10*365;       % uncomment to return a single result at 10 years

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 5) Life simulation
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
xx0 = zeros(lifeMdl.n_states,1);                           % initialize life model states to zero at beginning of life
xx  = zeros(lifeMdl.n_states,length(lifeSim.tdays_life));  % initialize memory for storing states throughout life (useful for debugging)
yy  = zeros(lifeMdl.n_outputs,length(lifeSim.tdays_life)); % initialize memory for storing outputs throughout life
dtdays_life = lifeSim.tdays_life(1);                       % initialize first timestep

for j=1:length(lifeSim.tdays_life);  % time marching loop
  % integrate state equations to get updated states, xx
  [xx(:,j),dxxdt] = func_LifeMdl_UpdateStates(lifeMdl,perfMdl,cycle,dtdays_life,xx0);
  
  % calculate output equations to get life model outputs, yy
  yy(:,j)    = func_LifeMdl_UpdateOutput(lifeMdl,perfMdl,xx(:,j));
  
  xx0 = xx(:,j); % store states for next timestep
  if j<length(lifeSim.tdays_life); dtdays_life = lifeSim.tdays_life(j+1)-lifeSim.tdays_life(j); end; % calculate next timestep
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 6) Plot outputs 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
switch model
    case 'V1_GrNCA_NRELphev'
        % store outputs with meaningful names
        lifeSim.R      = yy(1,:);
        lifeSim.Q      = yy(2,:);
        lifeSim.QLi    = yy(3,:);
        lifeSim.Qsites = yy(4,:);
        lifeSim.R1     = yy(5,:);
        lifeSim.R2     = yy(6,:);
        figure
          plot(lifeSim.tdays_life/365,lifeSim.R1,'--',lifeSim.tdays_life/365,lifeSim.R2,'-',lifeSim.tdays_life(1:5:end)/365,lifeSim.R(1:5:end),'k.')
          legend('SEI growth/calendar contribution, R_1','Site loss/cycling contribution, R_2','Overall, R = R_0 + R_1 + R_2')
          xlabel('Time (years)'); ylabel('Relative Resistance'); axis([0 10 0.8 2.0])
        figure
          plot(lifeSim.tdays_life/365,lifeSim.QLi,'--',lifeSim.tdays_life/365,lifeSim.Qsites,'-',lifeSim.tdays_life(1:5:end)/365,lifeSim.Q(1:5:end),'k.')
          legend('Li-limited/calendar fade, Q_{Li}','Site-limited/cycling fade, Q_{sites}','Overall, Q=min(1,Q_{Li},Q_{Sites})')
          xlabel('Time (years)'); ylabel('Relative Capacity');  axis([0 10 0.5 1.0])

    case 'V5_GrFeP_A123_2p3Ah'
        % store outputs with meaningful names
        lifeSim.R      = yy(1,:);
        lifeSim.Q      = yy(2,:);
        lifeSim.QLi    = yy(3,:);
        lifeSim.Qsites = yy(4,:);
        lifeSim.R1     = yy(5,:);
        lifeSim.R2     = yy(6,:);
        lifeSim.R3     = yy(7,:);
        lifeSim.QLi1   = yy(8,:);
        lifeSim.QLi3   = yy(9,:);
        figure
          plot(lifeSim.tdays_life/365,lifeSim.R1,'--',lifeSim.tdays_life/365,lifeSim.R2,'-',lifeSim.tdays_life/365,lifeSim.R3,'-.',lifeSim.tdays_life(1:5:end)/365,lifeSim.R(1:5:end),'k.')
          legend('SEI growth/calendar contribution, 1+R_1','Site loss/cycling contribution, 1+R_2','Break-in mechanism/cycling contribution, 1+R_3','Overall, R = 1 + R_1 + R_2 + R_3')
          xlabel('Time (years)'); ylabel('Relative Resistance'); axis([0 10 0.8 2.0])
        figure
          plot(lifeSim.tdays_life/365,lifeSim.QLi,'--',lifeSim.tdays_life/365,lifeSim.Qsites,'-',lifeSim.tdays_life(1:5:end)/365,lifeSim.Q(1:5:end),'k.')
          legend('Li-limited/calendar fade, Q_{Li}','Site-limited/cycling fade, Q_{sites}','Overall, Q=min(1,Q_{Li},Q_{Sites})')
          xlabel('Time (years)'); ylabel('Relative Capacity');  axis([0 10 0.5 1.0])
end
          
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 7) Write outputs to Excel file 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
fname = 'ExampleOutput.xlsx';
delete(fname);
header = {'t_life (days)',lifeMdl.names_outputs{1:end}};
xlswrite(fname,header,'Sheet1','A1')
output = [lifeSim.tdays_life' yy'];
xlswrite(fname,output,'Sheet1','A2')
  
toc