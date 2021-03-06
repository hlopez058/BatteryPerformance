function [y1] = myNeuralNetworkFunction(x1)
%MYNEURALNETWORKFUNCTION neural network simulation function.
%
% Generated by Neural Network Toolbox function genFunction, 15-Jun-2017 21:23:18.
%
% [y1] = myNeuralNetworkFunction(x1) takes these arguments:
%   x = 3xQ matrix, input #1
% and returns:
%   y = 4xQ matrix, output #1
% where Q is the number of samples.

%#ok<*RPMT0>

% ===== NEURAL NETWORK CONSTANTS =====

% Input 1
x1_step1.xoffset = [0;2.04164526435579;2.3];
x1_step1.gain = [0.02;0.00862248941123391;0.0257400257400257];
x1_step1.ymin = -1;

% Layer 1
b1 = [2.5367693456334259;1.0991926021706144;-2.142882886253386;-0.75093372890659538;0.28587054217485053;1.4451012168539226;0.66248611030851934;-1.5357310151934687;1.7434340221947096;-3.3965212542055987];
IW1_1 = [-1.270901472294943 2.9095824650188731 -1.4849848976904405;-0.85874361463209714 -3.5326497808068731 0.69893269462602181;-0.34910207036065977 -1.0067629398939879 3.1242298635310726;2.9941734578314136 0.40570054080669393 0.60302164191520558;0.51957026675266604 3.1668599776155375 0.057622774198736793;-0.011333569426557614 -0.55299836036771222 3.8891396402500047;-0.018513419257692211 2.5177627537100955 3.5942884432438325;-1.1715335699736147 -0.17469923404470272 -2.9397890971533869;1.5262308230720405 -2.2610502208311614 2.239254591983812;-0.06042748654168667 -1.8471058722297333 -3.3489893480077426];

% Layer 2
b2 = [-0.56009005524797173;0.93937783979438805;1.4328041738650095;0.30016895762725626];
LW2_1 = [0.44392647079824032 0.17428115339945305 -1.0605103725570468 -0.77940888785305196 -0.63760204510308682 3.7480199428560783 -3.7063946333337441 -0.56669743842208964 0.47122048729243626 -1.792264116492077;-1.2715442003193165 1.1624168223454723 4.2639828241685347 -1.0062156480025835 -0.25309615206683 1.1340529202124614 4.7049095639047378 -0.80507871652320273 1.0034054347227208 -0.34263186686668923;1.5340716440060616 -1.905789338503127 -1.6309426771648583 -0.55834655918901288 2.8700707022323066 -0.72096056851937396 -0.46030002282196525 0.44604826041713574 -2.5444060337974341 -1.0382222495450153;0.21122970318024512 1.2716454083803255 -1.0381512664354311 -0.59228164357848423 -1.3641622697762348 -3.2521796234314428 -0.81327361227442607 1.4572735673079527 0.58314357908119674 4.078756773541647];

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
