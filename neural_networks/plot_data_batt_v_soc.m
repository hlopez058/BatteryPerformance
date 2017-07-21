%Convert model data to V-SOC curves for each battery

%dataset .5A to 40A @ 12v 10AH
path = "model_vsoc_sweep_p5a_to_40a_03";
file = "model_sim_v_vs_soc_";
MaxA=40;
MinA=0.5;

%loop through all text files
%group each dataset into battery sweeped array
figure;
hold on
for i=MinA:0.5:MaxA
    %create filname
    str_id = replace(string(i),".","p");
    filename= path +"\"+ file+str_id + ".txt";
    
    %read data from file
    data = csvread(filename);
    %LFP
    plot(data(:,2),data(:,1))
end
hold off

figure;
hold on
for i=MinA:0.5:MaxA
    %create filname
    str_id = replace(string(i),".","p");
    filename= path +"\"+ file+str_id + ".txt";
    
    %read data from file
    data = csvread(filename);
    %NIMH
    plot(data(:,4),data(:,3))
end
hold off

figure;
hold on
for i=MinA:0.5:MaxA
    %create filname
    str_id = replace(string(i),".","p");
    filename= path +"\"+ file+str_id + ".txt";
    
    %read data from file
    data = csvread(filename);
    %LEADACID
    plot(data(:,6),data(:,5))
end
hold off
