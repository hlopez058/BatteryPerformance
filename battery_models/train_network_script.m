path = "model_vsoc_sweep_p5a_to_40a_03\model_sim_v_vs_soc_";
D={};
    
for i=1:0.5:40

    str_id = replace(string(i),".","p");
    filename= path + str_id + ".txt";
    
    
    %read data from file
    data = csvread(filename);
    dv1 = data(:,1);
    ds1 = data(:,2);
    dv2 = data(:,3);
    ds2 = data(:,4);
    dv3 = data(:,5);
    ds3 = data(:,6);
    
    A = [dv1',dv2',dv3';ds1',ds2',ds3'];

    net1 = nn_training_scg(A,10,'mse');
    net2 = nn_training_scg(A,[10 10],'mse');
    %net3 = nn_training_scg_rbf(A,10,'mse');
    %net2 = nn_training_rbp(A,10,'mse');
    %net3 = nn_training_rbp(A,[10 10],'mse');
    %net4 = nn_training_rbp_rbf(A,10,'mse');
    m =[i,net1.performance,net2.performance,net1.testperformance,net2.testperformance] ;
    D{end+1} = m;
end
dlmwrite("model_vsoc_sweep_p5a_to_40a_03_trained_network_data",D);   
 