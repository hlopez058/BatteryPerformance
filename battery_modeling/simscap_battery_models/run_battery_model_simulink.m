Current =10;

t = (0:1:3600)';
u = Current*ones(size(t));

in = Simulink.SimulationInput('Battery_Model_Simulink');

%create variables to use in the model
%run the model
% read output variables
% create a discharge curve over time
% create a v/soc curve


%in.ExternalInput = [t, u];
in = in.setVariable('Current',10);
% Run Model
simOut = sim(in);

% Get Model Output
vt=simOut.get('outputvt');

