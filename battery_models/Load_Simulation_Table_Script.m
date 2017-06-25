% 1 hour worth of data sampled per second
% Convert to table of 3x36226
% add a table

% Inputs
% SOC     : <36226 col bat1> <36226 col bat2> <36226 col bat3> <36226 col bat4>   
% Voltage : <36226 col bat1> <36226 col bat2> <36226 col bat3> <36226 col bat4>
% Current : <36226 col bat1> <36226 col bat2> <36226 col bat3> <36226 col bat4>
batt1_soc = LiFeMgPO4_Signals.SOC____.data';
batt1_voltage = LiFeMgPO4_Signals.Voltage__V_.data';
batt1_current = LiFeMgPO4_Signals.Current__A_.data';

batt2_soc = LeadAcid_Signals.SOC____.data';
batt2_voltage = LeadAcid_Signals.Voltage__V_.data';
batt2_current = LeadAcid_Signals.Current__A_.data';

batt3_soc =NiMH_Signals.SOC____.data';
batt3_voltage = NiMH_Signals.Voltage__V_.data';
batt3_current = NiMH_Signals.Current__A_.data';

batt4_soc = LiFePO4_Signals.SOC____.data';
batt4_voltage = LiFePO4_Signals.Voltage__V_.data';
batt4_current = LiFePO4_Signals.Current__A_.data';

batt_m_soc = [batt1_soc,batt2_soc,batt3_soc,batt4_soc];
batt_m_voltage = [batt1_voltage,batt2_voltage,batt3_voltage,batt4_voltage];
batt_m_current = [batt1_current,batt2_current,batt3_current,batt4_current];

batt_inputs = [batt_m_soc;batt_m_voltage;batt_m_current];

% Target
% Battery1: <36226 col '1'> <36226 col '0'> <36226 col '0'> <36226 col '0'>
% Battery2: <36226 col '0'> <36226 col '1'> <36226 col '0'> <36226 col '0'>
% Battery3: <36226 col '0'> <36226 col '0'> <36226 col '1'> <36226 col '0'>
% Battery4: <36226 col '0'> <36226 col '0'> <36226 col '0'> <36226 col '1'>

asize = length(batt1_soc);
batt1_label = [ones(1,asize),zeros(1,asize),zeros(1,asize),zeros(1,asize)];
batt2_label = [zeros(1,asize),ones(1,asize),zeros(1,asize),zeros(1,asize)];
batt3_label = [zeros(1,asize),zeros(1,asize),ones(1,asize),zeros(1,asize)];
batt4_label = [zeros(1,asize),zeros(1,asize),zeros(1,asize),ones(1,asize)];

batt_targets = [batt1_label;batt2_label;batt3_label;batt4_label];

