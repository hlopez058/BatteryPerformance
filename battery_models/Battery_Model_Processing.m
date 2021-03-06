%------------------------------------------------------------------
% Read the data from the battery models

batt1_soc = LiFeMgPO4_Signals.SOC____.data';
batt1_voltage = LiFeMgPO4_Signals.Voltage__V_.data';
batt1_current = LiFeMgPO4_Signals.Current__A_.data';

batt2_soc = LeadAcid_Signals.SOC____.data';
batt2_voltage = LeadAcid_Signals.Voltage__V_.data';
batt2_current = LeadAcid_Signals.Current__A_.data';

batt3_soc =NiMH_Signals.SOC____.data';
batt3_voltage = NiMH_Signals.Voltage__V_.data';
batt3_current = NiMH_Signals.Current__A_.data';

%------------------------------------------------------------------
% Create the input matrix for the NN, sort v/soc relationship head to tail
% for each battery output.
batt_input = [batt1_voltage,batt2_voltage,batt3_voltage;
                                            batt1_soc,batt2_soc,batt3_soc];

%------------------------------------------------------------------
% Create the target matrix for the NN, keep same order and assign value of
% 0 or 1 for each battery associated with input data
asize = length(batt1_soc);
batt1_lbl = [ones(1,asize),zeros(1,asize),zeros(1,asize)];
batt2_lbl = [zeros(1,asize),ones(1,asize),zeros(1,asize)];
batt3_lbl = [zeros(1,asize),zeros(1,asize),ones(1,asize)];

batt_target = [batt1_lbl;batt2_lbl;batt3_lbl];


%------------------------------------------------------------------
% Create the voltage vs soc curves for each battery model
% 
% batt1_vsoc = [batt1_voltage;batt1_soc];
% batt2_vsoc = [batt2_voltage;batt2_soc];
% batt3_vsoc = [batt3_voltage;batt3_soc];
% 
% plot(batt1_soc,batt1_voltage);
