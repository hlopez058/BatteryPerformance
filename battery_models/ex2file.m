function ex2file( filename,B1_V1,B1_SOC1,B1_V2,B1_SOC2,B1_V3,B1_SOC3)
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
M=[B1_V1,B1_SOC1,B1_V2,B1_SOC2,B1_V3,B1_SOC3];
dlmwrite(filename,M);
end

