function [ output ] = nn_training_scg(A,hiddenLayerSize,error_type)
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here

% NN Training
%------------------------------------------------------
% Create NN Inputs; Voltage vs. SOC for each battery  
inputs = A;

% Create NN Targets; 3xN array where 1's on each row show 
% relationship with the battery class in the input array
t_z = zeros(length(A)/3,1)';
t_o = ones(length(A)/3,1)';
targets = [t_o,t_z,t_z;t_z,t_o,t_z;t_z,t_z,t_o];

% Create a Pattern Recognition Network
% Use cross entropy performance and scaled conjugate gradient

    net = patternnet(hiddenLayerSize);
    
    net.performFcn = error_type;

% Set up Division of Data for Training, Validation, Testing
net.divideParam.trainRatio = 70/100;
net.divideParam.valRatio = 15/100;
net.divideParam.testRatio = 15/100;

% Train the Network
[net,tr] = train(net,inputs,targets);

% Test the Network
outputs = net(inputs);
errors = gsubtract(targets,outputs);
performance = perform(net,targets,outputs);

% Performance of just the Test 
tInd = tr.testInd;
tstOutputs = net(inputs(:,tInd));
tstPerform = perform(net,targets(:,tInd),tstOutputs);

%Write error to file
output = struct('net',net,'testperformance',tstPerform,'performance',performance,'errors',errors);

% View the Network
%view(net)

% Plots
% Uncomment these lines to enable various plots.
% figure, plotperform(tr)
% figure, plottrainstate(tr)
% figure, plotconfusion(targets,outputs)
% figure, ploterrhist(errors)

end

