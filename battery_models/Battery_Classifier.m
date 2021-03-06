function [y1] = Battery_Classifier(x1)
%MYNEURALNETWORKFUNCTION neural network simulation function.
%
% Generated by Neural Network Toolbox function genFunction, 22-Jun-2017 23:26:16.
%
% [y1] = myNeuralNetworkFunction(x1) takes these arguments:
%   x = 2xQ matrix, input #1
% and returns:
%   y = 3xQ matrix, output #1
% where Q is the number of samples.

%#ok<*RPMT0>

% ===== NEURAL NETWORK CONSTANTS =====

% Input 1
x1_step1.xoffset = [-4.88498130835069e-15;0];
x1_step1.gain = [0.135281194245916;0.02];
x1_step1.ymin = -1;

% Layer 1
b1 = [-4.9723971089746204;-6.0425328476212199;3.9828303904197644;6.6263980582286459;2.7922373881878837;1.9550854467195964;3.4486842604544594;2.2359633679077939;-3.0157630388703396;4.1955206334339321];
IW1_1 = [7.718129574740777 1.2278390640458778;1.014037430327323 -6.7788500299566952;-4.3948891985021579 -3.4017167798718955;-13.458187944358141 3.3241074128344725;0.49624115912686872 5.1999656431008487;3.7426380970950111 -4.8974971128408544;4.0573224304125661 -0.69083048926580792;2.6820500291932743 -4.3890872138609529;-2.2235090817492269 4.8072889108358865;2.4550667942010991 -3.8205720181833911];

% Layer 2
b2 = [1.9923809508773795;-2.0492753903382268;1.5448453741298611];
LW2_1 = [5.9867391203891342 6.2715675516586105 -2.2958368196439167 -9.1872282145571376 -4.7442808362480378 5.0897449843356206 -2.5755515788481471 2.6724182879657943 -1.6872797571269791 2.0969944826650964;-5.0176867348666576 -0.37478413354727802 4.1476853339032402 11.830364524780684 7.9142305602239684 -3.5645718480025264 3.109731195958839 -2.4926646081806871 3.6104838517823961 -3.4978478970131643;0.22282166819283239 -5.6065206221154007 -2.3568094829260815 -3.0189523626924943 -3.2182644447691025 -1.844338370281968 0.0013248351134321117 0.32575890209746999 -1.1404537539262503 -0.20389448774230298];

% ===== SIMULATION ========

% Dimensions
Q = size(x1,2); % samples

% Input 1
xp1 = mapminmax_apply(x1,x1_step1);

% Layer 1
a1 = tansig_apply(repmat(b1,1,Q) + IW1_1*xp1);

% Layer 2
a2 = softmax_apply(repmat(b2,1,Q) + LW2_1*a1);

% Output 1
y1 = a2;
end

% ===== MODULE FUNCTIONS ========

% Map Minimum and Maximum Input Processing Function
function y = mapminmax_apply(x,settings)
y = bsxfun(@minus,x,settings.xoffset);
y = bsxfun(@times,y,settings.gain);
y = bsxfun(@plus,y,settings.ymin);
end

% Competitive Soft Transfer Function
function a = softmax_apply(n,~)
if isa(n,'gpuArray')
    a = iSoftmaxApplyGPU(n);
else
    a = iSoftmaxApplyCPU(n);
end
end
function a = iSoftmaxApplyCPU(n)
nmax = max(n,[],1);
n = bsxfun(@minus,n,nmax);
numerator = exp(n);
denominator = sum(numerator,1);
denominator(denominator == 0) = 1;
a = bsxfun(@rdivide,numerator,denominator);
end
function a = iSoftmaxApplyGPU(n)
nmax = max(n,[],1);
numerator = arrayfun(@iSoftmaxApplyGPUHelper1,n,nmax);
denominator = sum(numerator,1);
a = arrayfun(@iSoftmaxApplyGPUHelper2,numerator,denominator);
end
function numerator = iSoftmaxApplyGPUHelper1(n,nmax)
numerator = exp(n - nmax);
end
function a = iSoftmaxApplyGPUHelper2(numerator,denominator)
if (denominator == 0)
    a = numerator;
else
    a = numerator ./ denominator;
end
end

% Sigmoid Symmetric Transfer Function
function a = tansig_apply(n,~)
a = 2 ./ (1 + exp(-2*n)) - 1;
end