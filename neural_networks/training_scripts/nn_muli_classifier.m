

% Read values from file

filenamesId = ["0p5","1","1p5","2","2p5","3","3p5","4","4p5","5","5p5","6","6p5","7","7p5","8","8p5","9","9p5","10","10p5","11","11p5","12","12p5","13","13p5","14","14p5","15","15p5","16","16p5","17","17p5","18","18p5","19","19p5","20"];

BATT_NN_MAPE = zeros([40 2]);

for i= 1:40
    load = filenamesId(i);
    A = csvread('model_data_load_' +load+'A.txt');

    %create nn input from matrix
    %get the batt1 curve
    b1=A(:,[1,2]);
    b2=A(:,[3,4]);
    b3=A(:,[5,6]);
    %flatten
    b_input = [b1',b2',b3'];

    %create nn target from matrix
    b_target = [ones(length(A),1),zeros(length(A),1),zeros(length(A),1);
        zeros(length(A),1),ones(length(A),1),zeros(length(A),1);
        zeros(length(A),1),zeros(length(A),1),ones(length(A),1)]';

    %build the nn that will run the analysis
     x=b_input;
     t=b_target;

     %-- Double Layer FF NN
     %net = patternnet([10,10]);
     %net = train(net,x,t);
     
     %-- Single Layer FF NN
     %net = patternnet(10);
     %net = train(net,x,t);
     
     %-- Single Layer FF NN
     net = patternnet(20);
     net = train(net,x,t);
     
     
     %-- Radial Basis NN
     %net = newrbe(x,t,3);
     %net = train(net,x,t);
     
     %view(net)
     y = net(x);
     perf = perform(net,t,y);
     classes = vec2ind(y);
    % Calculate Mean Absolute Percentage Error
    err = t-y;
    errpct = abs(err)./t*100;
    MAE = mean(abs(err));
    MAPE = mean(errpct(~isinf(errpct)));

    % store teh load the models discharged at
    loadval = replace(load,"p",".");
    BATT_NN_MAPE(i,1)= loadval;
    BATT_NN_MAPE(i,2)= MAPE;
end
    