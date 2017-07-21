function yy = func_LifeMdl_UpdateOutput(lifeMdl,perfMdl, xx);
% Calculates capacity fade & resistance growth at a given state-of-life
%
%   - Author: Kandler Smith, NREL, Copyright 2010
%   - Based on paper by EVS-24 paper by Smith,Markel,Pesaran, 2009
%   - Modified for new NCA model, KAS 6/2010
%   - Added FeP model based on A123 2.3Ah 26650 cell (KAS, 4/28/15)
%
% Inputs:
%   perfMdl - structure containing battery performance model parameters
%
%   lifeMdl - structure containing battery life model parameters
%           * see func_LoadLifeParameters.m for definition of life-parameters
%
%   xx      - vector of life model states at present state-of-life
%
% Outputs:
%   yy      - vector of life model capacity fade and resistance growth
%
switch lifeMdl.model
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
        %lifeMdl.names_states = {'dR1: Delta relative resistance-SEI growth contribution';...
        %                        'dR2: Delta relative resistance-site loss contribution';...
        %                        'dQ1: Delta relative capacity-Li loss';...
        %                        'dQ2: Delta relative capacity-site loss'};
        %lifeMdl.names_outputs= {'R:   Overall relative resistance';...
        %                        'Q:   Overall relative capacity, Q  = min([1 Q1 Q2])';...
        %                        'Q1:  Relative capacity - Li limited';...
        %                        'Q2:  Relative capacity - site limited';...
        %                        'R1:  Relative resistance-SEI growth contribution';...
        %                        'R2:  Relative resistance-site loss contribution'};
        R1 = lifeMdl.R_0  + xx(1);
        R2 = lifeMdl.R_0  + xx(2);
        R  = lifeMdl.R_0  + xx(1) + xx(2);
        Q1 = lifeMdl.Q1_0 - xx(3);
        Q2 = lifeMdl.Q2_0 - xx(4);
        Q  = min(1,min(Q1,Q2));
        
        yy = [R Q Q1 Q2 R1 R2]';
        
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
        %lifeMdl.names_states = {'dR1:     Delta relative resistance-SEI growth contribution';...
        %                        'dR3:     Delta relative resistance-Break-in mechanism causing initial resistance drop';...
        %                        'dQLi1:   Delta relative capacity-Li loss due to SEI growth';...
        %                        'dQLi3:   Delta relative capacity-Break-in mechanism causing initial Li loss or transport limitation';...
        %                        'dQsites: Delta relative capacity-site loss'};
        %lifeMdl.names_outputs= {'R:      Overall relative resistance';...
        %                        'Q:      Overall relative capacity, Q  = min([1 QLi Qsites])';...
        %                        'QLi:    Relative capacity - Li limited';...
        %                        'Qsites: Relative capacity - Site limited';...
        %                        'R1:     Relative resistance-SEI growth contribution';...
        %                        'R2:     Relative resistance-Site loss contribution'};
        %                        'R3:     Relative resistance-Break-in mechanism contribution';...
        %                        'QLi1:   Relative capacity - Li limited, SEI growth contribution';...
        %                        'QLi3:   Relative capacity - Li limited, Break-in mechanism contribution'};
        QLi   = lifeMdl.b0 - xx(3) - xx(4);
        QLi1  = lifeMdl.b0 - xx(3);
        QLi3  = lifeMdl.b0 - xx(4);
        Qsites= lifeMdl.c0 - xx(5);
        Q     = min(1,min(QLi,Qsites));
        R     = lifeMdl.a0 + xx(1) + lifeMdl.a2_ref/Qsites - xx(2);
        R1    = lifeMdl.a0 + xx(1) + lifeMdl.a2_ref/lifeMdl.c0;
        R2    = lifeMdl.a0 + lifeMdl.a2_ref/Qsites;
        R3    = lifeMdl.a0 + lifeMdl.a2_ref/lifeMdl.c0 - xx(2);
        
        yy = [R Q QLi Qsites R1 R2 R3 QLi1 QLi3]';
        
    otherwise
        error('func_LifeMdl_UpdateOutput: Specified life model "lifeMdl.model" is not available in this version. Check to ensure input to this function is correct.')
end