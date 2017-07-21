function [xx,dxxdt] = func_LifeMdl_UpdateStates(lifeMdl,perfMdl,cycle,dtdays_life,xx0)
% Calculates capacity fade & resistance growth rates & integrates rates 
%   forward in time to update states for a complex cycling profile
%   at a given state-of-life.
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
%   cycle   - structure containing duty-cycle & temperature variables, e.g.
%           cycle.tsec  - time stamp array
%           cycle.soc   - state-of-charge array corresponding to time stamps (0=empty, 1=full charge)
%           cycle.TdegC - temperature array corresponding to time stamps (or use a
%                         single value to represent constant temperature) (degrees Celcius)
%           cycle.dsoc_i- array of delta-state-of-charge swings encountered by
%                         the battery during cycling calulated by Rainflow algorithm
%           cycle.ncycle_i-array of number of cycles corresponding to each
%                         delta-state-of-charge calculated by Rainflow algorithm
%
%   dtdays_life - timestep between previous and present battery
%            state-of-life (days)
%
%   xx0  - vector of life model states at previous state-of-life
%
% Outputs:
%   xx    - vector of life model states integrated to next state-of-life
%
%   dxxdt - vector of life model states time rate of change
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Define constants
Rugc  = 8.314;                  % (J/K mol) universal gas constant
F     = 96485;                  % (C/mol) Faraday constant
TrefK = lifeMdl.TrefC+273.15;   % (K) reference temperature used when fitting life model

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
        
        % Calculate derived inputs
        cycle.TdegK   = cycle.TdegC + 273.15;         % (K) temperature
        cycle.ocv     = interp1(perfMdl.soc_index,perfMdl.ocv_index, cycle.soc, 'linear','extrap'); % open-circuit voltage (V)
        dtsec_cycprof = cycle.tsec(end)-cycle.tsec(1);  % (sec) length of cycling profile
        dtday_cycprof = dtsec_cycprof/24/3600;      % (days) length of cycling profile
        
        % Calculate voltage acceleration from given V & T profile (Tafel equation)
        Tfl_a1 = exp(lifeMdl.alp_a1*F/Rugc * (cycle.ocv./cycle.TdegK - lifeMdl.Vref/TrefK));
        Tfl_a2 = exp(lifeMdl.alp_a2*F/Rugc * (cycle.ocv./cycle.TdegK - lifeMdl.Vref/TrefK));
        Tfl_b1 = exp(lifeMdl.alp_b1*F/Rugc * (cycle.ocv./cycle.TdegK - lifeMdl.Vref/TrefK));
        Tfl_c2 = exp(lifeMdl.alp_c2*F/Rugc * (cycle.ocv./cycle.TdegK - lifeMdl.Vref/TrefK));
        
        % Calculate temperature acceleration from given T profile (Arrhenius equation)
        Arr_a1 = exp(-lifeMdl.Ea_a1/Rugc*(1./cycle.TdegK-1/TrefK));
        Arr_b1 = exp(-lifeMdl.Ea_b1/Rugc*(1./cycle.TdegK-1/TrefK));
        Arr_a2 = exp(-lifeMdl.Ea_a2/Rugc*(1./cycle.TdegK-1/TrefK));
        Arr_c2 = exp(-lifeMdl.Ea_c2/Rugc*(1./cycle.TdegK-1/TrefK));
        
        % Calculate DoD acceleration from given dDoD profile (Wohler equation)
        DoD_Woh_a1_i = (1+cycle.dsoc_i./lifeMdl.DoDref).^lifeMdl.pwr_a1;
        DoD_Woh_a2_i = (  cycle.dsoc_i./lifeMdl.DoDref).^lifeMdl.pwr_a2;
        DoD_Woh_b1_i = (1+cycle.dsoc_i./lifeMdl.DoDref).^lifeMdl.pwr_b1;
        DoD_Woh_c2_i = (  cycle.dsoc_i./lifeMdl.DoDref).^lifeMdl.pwr_c2;
        
        % Calculate degradation rates
        a1 = lifeMdl.a1_ref * trapz(cycle.tsec, Tfl_a1.*Arr_a1)/dtsec_cycprof * max(DoD_Woh_a1_i);
        a2 = lifeMdl.a2_ref * trapz(cycle.tsec, Tfl_a2.*Arr_a2)/dtsec_cycprof * sum(DoD_Woh_a2_i.*cycle.ncycle_i)/dtday_cycprof;
        b1 = lifeMdl.b1_ref * trapz(cycle.tsec, Tfl_b1.*Arr_b1)/dtsec_cycprof * max(DoD_Woh_b1_i);
        c2 = lifeMdl.c2_ref * trapz(cycle.tsec, Tfl_c2.*Arr_c2)/dtsec_cycprof * sum(DoD_Woh_c2_i.*cycle.ncycle_i)/dtday_cycprof;
        
        % unpack state vector
        dR1 = xx0(1);
        dR2 = xx0(2);
        dQ1 = xx0(3);
        dQ2 = xx0(4);
        
        % Calculate fade rate with time
        if dR1 == 0;
            if dtdays_life == 0
                dR1dt = 0;
            else
                dR1  = a1*sqrt(dtdays_life);
                dR1dt = dR1/dtdays_life;
            end
        else
            dR1dt = a1^2 / (2*dR1);
        end
        dR2dt = a2;
        
        if dQ1 == 0;
            if dtdays_life == 0
                dQ1dt = 0;
            else
                dQ1   = b1*sqrt(dtdays_life);
                dQ1dt = dQ1/dtdays_life;
            end
        else
            dQ1dt = ( b1 )^2 / (2*dQ1);
        end
        dQ2dt = c2;
        
        % pack state time derivatives into vector
        dxxdt = [dR1dt;
                 dR2dt;
                 dQ1dt;
                 dQ2dt];
        xx    = dxxdt*dtdays_life + xx0;
        
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

        % Calculate derived inputs
        cycle.TdegK   = cycle.TdegC + 273.15;           % (K) temperature
        cycle.ocv     = interp1(perfMdl.soc_index,perfMdl.ocv_index,  cycle.soc, 'linear','extrap'); % open-circuit voltage (V)
        cycle.Uneg    = interp1(perfMdl.soc_index,perfMdl.Uneg_index, cycle.soc, 'linear','extrap'); % negative electrode equilibrium potential (V)
        dtsec_cycprof = cycle.tsec(end)-cycle.tsec(1);  % (sec)  length of duty-cycle profile
        dtday_cycprof = dtsec_cycprof/24/3600;          % (days) length of duty-cycle profile
        
        % Calculate SOC acceleration (Tafel equation)
        Tfl_a1 = exp(lifeMdl.alp_a1*F/Rugc * (cycle.Uneg./cycle.TdegK - lifeMdl.Uneg_ref/TrefK));
        Tfl_b1 = exp(lifeMdl.alp_b1*F/Rugc * (cycle.Uneg./cycle.TdegK - lifeMdl.Uneg_ref/TrefK));
        
        % Calculate temperature acceleration from given T profile (Arrhenius equation)
        %   Note: "_i" in variable name indicates it is an array calculated from Rainflow alforithm microcycle statistics
        Arr_a1      = exp(-lifeMdl.Ea_a1   ./Rugc*(1./cycle.TdegK  - 1/TrefK));
        Arr_a3_i    = exp(-lifeMdl.Ea_a3   ./Rugc*(1./cycle.TavgK_i- 1/TrefK));              
        Arr_b1      = exp(-lifeMdl.Ea_b1   ./Rugc*(1./cycle.TdegK  - 1/TrefK));              
        Arr_b3_i    = exp(-lifeMdl.Ea_b3   ./Rugc*(1./cycle.TavgK_i- 1/TrefK));
        Arr_c2_i    = exp(-lifeMdl.Ea_c2   ./Rugc*(1./cycle.TavgK_i- 1/TrefK));
        Arr_Dsneg_i = exp(-lifeMdl.Ea_Dsneg./Rugc*(1./cycle.TavgK_i- 1/TrefK));
       
        % Calculate DoD & Crate acceleration
        DodCrate_a1_i  = 1;
        DodCrateT_a3_i = Arr_a3_i.*cycle.dsoc_i.^0.5.*cycle.Crate_dis_i.^0.5;
        DodCrate_b1_i  = 1+0.9551./Arr_Dsneg_i.*cycle.dsoc_i.^1.0*cycle.Crate_disrms.^1.0 + 0.3301.*cycle.dsoc_i;
        DodCrateT_b3_i = Arr_b3_i.*cycle.dsoc_i.^0.5.*cycle.Crate_dis_i.^0.5;
        DodCrateT_c2_i = 0.296*Arr_c2_i.*cycle.dsoc_i + (1-0.296)./Arr_Dsneg_i.*cycle.dsoc_i.^0.5.*cycle.Crate_dis_i.^0.5;
    
        % Calculate degradation rates (trapz/dt and sum(cycles)/dt provide time-weighted averages; max( ) gets the worst damage over the time period)
        a1     = lifeMdl.a1_ref * trapz(cycle.tsec, Tfl_a1.*Arr_a1)/dtsec_cycprof * max(DodCrate_a1_i);
        a3_max = lifeMdl.a3_ref * max( DodCrateT_a3_i );
        b1     = lifeMdl.b1_ref * trapz(cycle.tsec, Tfl_b1.*Arr_b1)/dtsec_cycprof * max(DodCrate_b1_i);
        b3_max = lifeMdl.b3_ref * max( DodCrateT_b3_i );
        c2     = lifeMdl.c2_ref * sqrt(sum( (DodCrateT_c2_i .* cycle.ncycle_i).^2 ) )/dtday_cycprof;
            
        % Unpack states
        dR1     = xx0(1);
        dR3     = xx0(2);
        dQLi1   = xx0(3);
        dQLi3   = xx0(4);
        dQsites2= xx0(5);
        
        % Calculate rates
        % trajectory eqn: R1=a1*t^p;  rate eqn: dR1dt=a1*p*( a1/R1 )^((1-p)/p))
        if dR1 == 0;
            if dtdays_life == 0
                dR1dt = 0;
            else
                dR1   = a1*(dtdays_life)^lifeMdl.p_a1;
                dR1dt = dR1/dtdays_life;
            end
        else
            dR1dt = a1*lifeMdl.p_a1 *(dR1 / a1) ^ ((lifeMdl.p_a1-1)/lifeMdl.p_a1);
        end
        % trajectory eqn: QLi1=b1*t^p;  rate eqn: dQLi1dt=b1*p*( b1/R1 )^((1-p)/p))
        if dQLi1 == 0;
            if dtdays_life == 0
                dQLi1dt = 0;
            else
                dQLi1   = b1*(dtdays_life)^lifeMdl.p_b1;
                dQLi1dt = dQLi1/dtdays_life;
            end
        else
            dQLi1dt = b1*lifeMdl.p_b1 *(dQLi1 / b1) ^ ((lifeMdl.p_b1-1)/lifeMdl.p_b1);
        end
        % rate eqn: dQSitesRemaining/dt = c2*(Qsites0/QsitesRemaining)^p
        if dQsites2 >= lifeMdl.c0 | dtdays_life == 0
            dQsites2dt = 0; % avoid divide by zero or power of negative number
        else
            dQsites2dt = c2*(lifeMdl.c0/(lifeMdl.c0-dQsites2))^lifeMdl.p_c2;
        end
        % trajectory eqn:   R3 = a3_max*(1-exp(-lambda_a3*t));  rate eqn:   dR3/dt = lambda_a3*(a3_max-t)
        dR3dt   = lifeMdl.lambda_a3*max(0.0,(a3_max - dR3  ));
        % trajectory eqn: QLi3 = b3_max*(1-exp(-lambda_b3*t));  rate eqn: dQLi3/dt = lambda_b3*(b3_max-t)
        dQLi3dt = lifeMdl.lambda_b3*max(0.0,(b3_max - dQLi3));
        
        % Pack up & integrate state vector forward in time
        dxxdt = [dR1dt,dR3dt,dQLi1dt,dQLi3dt,dQsites2dt]';
        xx    = xx0 + dxxdt*dtdays_life;
        xx(2) = min(xx(3),a3_max);
        xx(4) = min(xx(5),b3_max);
        xx(5) = min(xx(5),lifeMdl.c0);
      
    otherwise
        error('func_LifeMdl_UpdateStates: Specified life model "lifeMdl.model" is not available in this version. Check to ensure input to this function is correct.')
end

