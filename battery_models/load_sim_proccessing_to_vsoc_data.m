%script to create voltage vs soc curves from battery models
LoadCurrent_Max = 40;
LoadCurrent_Step = .5;
SimulationTime = 3600; 
LogSimData_FileName = "model_sim_12_v_vs_soc_";
hiddenLayerSize = 10;
Load_Simulation = 'Load_Simulation_07';

% Array of Neural Net Structures containing performance data
NNs = {};

% Run battery models for every discharge current
for i=1:LoadCurrent_Step:LoadCurrent_Max

    % Pass discharge current signal to battery models
    LoadCurrent_Signal = timeseries(ones(1,SimulationTime)*i);
    
    % Run Model
    simOut = sim(Load_Simulation);

    % Get Model Output
    dv1=simOut.get('V1');
    dv2=simOut.get('V2');
    dv3=simOut.get('V3');
    ds1=simOut.get('S1');
    ds2=simOut.get('S2');
    ds3=simOut.get('S3');
    
    % Save outputs to a file
    M=[dv1,ds1,dv2,ds2,dv3,ds3];
    str_id = replace(string(i),".","p");
    filename= LogSimData_FileName+ str_id + ".txt";
    dlmwrite(filename,M);   
    
    %A = [dv1',dv2',dv3';ds1',ds2',ds3'];
    % Train network style ='10' ; trainscg, with cross entropy
    %NNs{en+1}= nn_training(A,10);
    
end

%Post Processing NNs 
% send to a file.