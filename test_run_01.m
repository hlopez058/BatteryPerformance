%% Battery Data Set Conditioning
%derive the rate of change in the voltage-soc curve
%the dv/dsoc can provide the time independent variable
%this would lead to a more unique input for the 
%nn training set

data=csvread('data_set.csv');
nn_inputs=[];nn_targets=[];tr=1;
for i=[1,3,5]
    v=data(:,i);
    soc=data(:,i+1);
    
    %read in the v-soc curve and apply polyfit
    poly_vsoc = polyfit(soc,v,5);
    poly_dv_dsoc = polyder(poly_vsoc);

    %create the array for the input data
    dv_dsoc = polyval(poly_dv_dsoc,1:1:size(data));

    %build a dv/dt array
    dv_dt = diff(v);
    dv_dt(end+1) = v(end); %add sample to resize vector
    
    %final input data for neural net training
    input = [v';soc';dv_dsoc;dv_dt'];
    nn_inputs = [nn_inputs,input];
    
    trg = [0;0;0];
    trg(tr) = 1;
    nn_targets = [nn_targets,trg * ones([1 length(input)])];
    tr=tr+1;
end;




%% Neural Net Training
%feedforward netowrk with a single hidden layer
%10 neurons. Use different training methods
% 1. rbf, radial basiss function training
% 2. scg, scaled conjugate gradient, backpropogation
% 3. rp, resilient backpropogation

% Create a Pattern Recognition Network
hiddenLayerSize = 10;
net = patternnet(hiddenLayerSize,'trainscg');

% Set up Division of Data for Training, Validation, Testing
net.divideParam.trainRatio = 70/100;
net.divideParam.valRatio = 15/100;
net.divideParam.testRatio = 15/100;
% limit epochs
net.trainParam.epochs = 100;
% Train the Network
[net,tr] = train(net,nn_inputs,nn_targets);

% Test the Network
outputs = net(nn_inputs);
errors = gsubtract(nn_targets,outputs);
performance = perform(net,nn_targets,outputs);
L2_performance = norm(errors);
Linf_performance = norm(errors,'inf');


%rbf
rbf_net = newrbe(nn_inputs,nn_targets);
rbf_outputs = rbf_net(nn_inputs);
rbf_errors = gsubtract(nn_targets,rbf_outputs);
rbf_L2_performance = norm(rbf_errors);
rbf_Linf_performance = norm(rbf_errors,'inf');

% View the Network
%view(net);

% Plots
% Uncomment these lines to enable various plots.
% figure, plotperform(tr)
% figure, plottrainstate(tr)
% figure, plotconfusion(targets,outputs)
% figure, ploterrhist(errors)

%net_rbf = nn_training_rbp_rbf(nn_inputs,10);


%% Evaluating Neural Net Performance

