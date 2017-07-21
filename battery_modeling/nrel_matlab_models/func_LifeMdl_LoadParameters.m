function [lifeMdl,perfMdl] = func_LifeMdl_LoadParameters(model)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Defines baseline life model parameters, i.e. rate coefficients for 
%   resistance growth, capacity loss, as well as acceleration factors
%   for temperature, voltage, depth-of-discharge.
%
% Kandler Smith, NREL 6/25/10
%
% Revisions:
%  - Added new NCA model (KAS, 6/25/10)
%  - Added FeP model based on A123 2.3Ah 26650 cell (KAS, 4/28/15)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

switch model

    case 'V1_GrNCA_NRELphev'
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        % Life model originally developed for Saft ~PHEV-type graphite/Ni-Co-Al cell
        % ---------------------------------------------------------------------------
        % Relative resistance
        %   R = a0 + a1*t^0.5 + a2*N
        % Relative capacity
        %   QLi = b0 - b1*t^0.5
        %   Qsites = c0 - c2*N
        %   Q = min([1,QLi,Qsites])
        % ...where a1,a2,b1,c2 are functions of duty-cycle and temperature
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        % battery performance model parameters
        perfMdl.soc_index    = [0:0.1:1.0];  % ( ) state-of-charge index
        perfMdl.ocv_index    = [3.319 3.420 3.507  3.551  3.591  3.640  3.700  3.762  3.822  3.887 4.005];  % (V) Open-circuit voltage corresponding to soc index
        perfMdl.Ahcapacity   = 57.8;         % (Ah) nameplate capacity

        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%       
        % battery life model parameters
        lifeMdl.model        = model;
        lifeMdl.ref          = 'NREL - Smith,Markel,Pesaran/DOE Milestone Report, June 2010';
        lifeMdl.description  = 'Model fit to large composite data set from Boeing, NASA-JPL, & Saft.  Adjusted to match Idaho National Lab data for Saft HP12LC cell under HEV cycling and S. Calif. Edison data for Saft VL41M cell under PHEV cycling';
        lifeMdl.chemistry    = 'Graphite negative electrode, Nickel-Cobalt-Aluminum positive electrode';
        lifeMdl.names_states = {'dR1: Delta relative resistance-SEI growth contribution';...
                                'dR2: Delta relative resistance-site loss contribution';...
                                'dQ1: Delta relative capacity-Li loss';...
                                'dQ2: Delta relative capacity-site loss'};
        lifeMdl.names_outputs= {'R:   Overall relative resistance';...
                                'Q:   Overall relative capacity, Q  = min([1 Q1 Q2])';...
                                'Q1:  Relative capacity - Li limited';...
                                'Q2:  Relative capacity - Site limited';...
                                'R1:  Relative resistance-SEI growth contribution';...
                                'R2:  Relative resistance-site loss contribution'};
                            
        lifeMdl.n_states     = 4;           % number of states in model that are integrated with time or cycles
        lifeMdl.n_outputs    = 6;           % number of outputs in model
        lifeMdl.TrefC        = 20;          % (degC) reference temperature
        lifeMdl.Vref         = 3.6000;      % (V)    reference voltage
        lifeMdl.DoDref       = 1;           % ( )    reference depth-of-discharge (DoD)
        lifeMdl.a0_0         = 1.0000;      % ( ) relative resistance at beginning-of-life
        lifeMdl.b0_0         = 1.0400;      % ( ) relative capacity at beginning-of-life - cyclable Li
        lifeMdl.c0_0         = 1;           % ( ) relative capacity at beginning-of-life - active sites
        lifeMdl.a1_ref       = 0.001123;    % (1/day^1/2) rate constant for resistance growth - SEI
        lifeMdl.a2_ref       = 1.9673e-004; % (1/cycle)   rate constant for resistance growth - cycling
        lifeMdl.b1_ref       = 0.001794;    % (1/day^1/2) rate constant for capacity loss - cyclable Li
        lifeMdl.c2_ref       = 1.0737e-004; % (1/cycle)   rate constant for capacity loss - active sites
        lifeMdl.Ea_a1        = 7.0717e+004; % (J/mol K) activation energy for Arrhenius-temperature acceleration of a1, resistance growth - SEI
        lifeMdl.Ea_b1        = 3.8446e+004; % (J/mol K) activation energy for Arrhenius-temperature acceleration of d1, capacity loss - cycleable Li 
        lifeMdl.alp_a1       = 0.0620;      % ( ) coefficient for Tafel-voltage acceleration of a1, resistance growth - SEI
        lifeMdl.alp_a2       = 0.0558;      % ( ) coefficient for Tafel-voltage acceleration of a2, resistance growth - cycling
        lifeMdl.alp_b1       = 0.0505;      % ( ) coefficient for Tafel-voltage acceleration of b1, capacity loss - cyclable Li
        lifeMdl.alp_c2       = 0.0234;      % ( ) coefficient for Tafel-voltage acceleration of c1, capacity loss - cyclable Li
        lifeMdl.pwr_a1       = 0;           % ( ) exponent for Wohler-DoD acceleration of a1, resistance growth - SEI
        lifeMdl.pwr_a2       = 2.1748;      % ( ) exponent for Wohler-DoD acceleration of a2, resistance growth - cycling
        lifeMdl.pwr_b1       = 0.9947;      % ( ) exponent for Wohler-DoD acceleration of b1, capacity loss - cyclable Li
        lifeMdl.pwr_c2       = 2.6052;      % ( ) exponent for Wohler-DoD acceleration of c1, capacity loss - active sites
        lifeMdl.R_0          = lifeMdl.a0_0;
        lifeMdl.Q1_0         = lifeMdl.b0_0;
        lifeMdl.Q2_0         = lifeMdl.c0_0;
        lifeMdl.Ea_a2        = 35000; % (J/mol K) activation energy for Arrhenius-temperature acceleration of a2, resistance growth - cycling
        lifeMdl.Ea_c2        = 35000; % (J/mol K) activation energy for Arrhenius-temperature acceleration of c1, capacity loss - sites

    case 'V5_GrFeP_A123_2p3Ah'
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        % Life model originally developed for A123 2.3Ah 26650 graphite/iron-phosphate cell
        % ---------------------------------------------------------------------------------
        % Relative resistance
        %   R = a0 + a1*t^0.5 + a2/Qsites - a3*(1-exp(-t/200))
        % Relative capacity
        %   QLi = b0 - b1*t^0.5 - b3*(1-exp(-t/200))
        %   Qsites = [c0^(1+p) + c2*(c0^p)(1+p)*N]^(1/(1+p))
        %   Q = min([1,QLi,Qsites])
        % ...where a1,a3,b1,b3,c3 are functions of duty-cycle and temperature
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        % battery performance model parameters
        perfMdl.soc_index    = [0:0.1:1.0];  % ( ) state-of-charge index
        perfMdl.ocv_index    = [2.1434 3.2048 3.2593 3.2927 3.3068 3.3119 3.3223 3.3386 3.3447 3.3486 3.5291]; % (V) OCV, Open-circuit voltage corresponding to soc index from Safari & Delecourt "Modeling of a Commercial Graphite/LiFePO4 Cell" JES 158 (2011)
        perfMdl.Uneg_index   = [1.2868 0.2420 0.1818 0.1488 0.1297 0.1230 0.1181 0.1061 0.0925 0.0876 0.0859]; % (V) Uneg, equilibrium potential of negative electrode from Safari & Delecourt "Modeling of a Commercial Graphite/LiFePO4 Cell" JES 158 (2011).  Assumes neg. electrode stoichiometry is 0.8 at 100% soc
        perfMdl.Ahcapacity   = 2.3;         % (Ah) nameplate capacity

        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%       
        % battery life model parameters
        lifeMdl.model        = model;
        lifeMdl.ref          = 'NREL - Smith, Barai, Santhanagopalan, Pesaran; to be submitted to J. Echem. Soc. ~June 2015';
        lifeMdl.description  = 'Model fit to 45 aging conditions for A123 2.3Ah 26650 cell. Data from published specsheets and reports by A123, NASA-JPL, Safari& Delacourt, & HRL-Labs';
        lifeMdl.chemistry    = 'Graphite negative electrode, Iron-phosphate positive electrode';
        lifeMdl.names_states = {'dR1:     Delta relative resistance-SEI growth contribution';...
                                'dR3:     Delta relative resistance-Break-in mechanism causing initial resistance drop';...
                                'dQLi1:   Delta relative capacity-Li loss due to SEI growth';...
                                'dQLi3:   Delta relative capacity-Break-in mechanism causing initial Li loss or transport limitation';...
                                'dQsites: Delta relative capacity-site loss'};
        lifeMdl.names_outputs= {'R:      Overall relative resistance';...
                                'Q:      Overall relative capacity, Q  = min([1 QLi Qsites])';...
                                'QLi:    Relative capacity - Li limited';...
                                'Qsites: Relative capacity - Site limited';...
                                'R1:     Relative resistance-SEI growth contribution';...
                                'R2:     Relative resistance-Site loss contribution';...
                                'R3:     Relative resistance-Break-in mechanism contribution';...
                                'QLi1:   Relative capacity - Li limited, SEI growth contribution';...
                                'QLi3:   Relative capacity - Li limited, Break-in mechanism contribution'};

        lifeMdl.n_states = 5;      % number of states in model that are integrated with time or cycles
        lifeMdl.n_outputs= 9;      % number of outputs in model
        lifeMdl.Vref     = 3.3797; % (V) reference value of OCV at 50% SOC 
        lifeMdl.Uneg_ref = 0.0859; % (V) reference value of neg electrode equil potential at 50% SOC
        lifeMdl.TrefC    = 25;     % (degrees Celcius) reference temperature
        
        % fade rates at reference conditions
        lifeMdl.a1_ref  = 2.276e-3;%4.287e-4;
        lifeMdl.a2_ref  = 1.1261;%1.1435;
        lifeMdl.a3_ref  = 0.2376;%0.1580;
        lifeMdl.b1_ref  = 0.003305;
        lifeMdl.c2_ref  = 2.452e-05;
        lifeMdl.b3_ref  = 0.0344;
        
        % relative resistance (a0) and capacity (b0,c0) at beginning of life 
        lifeMdl.a0      = 1-lifeMdl.a2_ref;
        lifeMdl.b0      = 1.0075;
        lifeMdl.c0      = 1.0;
        
        % temperature sensitivity of fade rates
        lifeMdl.Ea_b1   = 35260;
        lifeMdl.Ea_b3   = -6398;
        lifeMdl.Ea_a1   = 35260;%71000;
        lifeMdl.Ea_a3   = lifeMdl.Ea_b3;
        lifeMdl.Ea_Dsneg= 39800;
        lifeMdl.Ea_c2   = 83150;
        % Uneg (indirectly, SOC) sensitivity of fade rates
        lifeMdl.alp_b1  = -0.1914;
        lifeMdl.alp_a1  = lifeMdl.alp_b1;
        % 1/time_constant of break-in mechanisms
        lifeMdl.lambda_b3 = 1/200;
        lifeMdl.lambda_a3 = lifeMdl.lambda_b3;
        % order of reaction (0.5 common for diffusion-controlled SEI growth, 1.0 common for site loss)
        lifeMdl.p_a1    = 0.5;
        lifeMdl.p_b1    = 0.5;
        lifeMdl.p_c2    = 1.0;

    otherwise
        error('func_LifeMdl_LoadParameters: Specified life model "lifeMdl.model" is not available in this version. Check to ensure input to this function is correct.')

end


