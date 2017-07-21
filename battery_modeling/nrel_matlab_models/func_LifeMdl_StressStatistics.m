function cycle = func_LifeMdl_StressStatistics(lifeMdl,perfMdl,cycle)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Adds to "cycle" structure additional aging stress statistics.
%  Scalars:
%   cycle.Crate_rms,Crate_disrms,Crate_chgrms
%  Vectors: (using rainflow algorithm)
%   cycle.dsoc_i,ncyc_i,Crate_dis_i,Crate_chg_i,TavgK_i,socavg_i...
%
% Copyright Kandler Smith & Ying Shi, NREL 6/2013
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
cycle.TdegK = cycle.TdegC+273.15;

% call rainflow algorithm. Outputs are:
%     rf(1,:) Cycles amplitude,
%     rf(2,:) Cycles mean value,
%     rf(3,:) Number of cycles (0.5 or 1.0),
%     rf(4,:) Begining time (when input includes dt or extt data),
%     rf(5,:) Cycle period (when input includes dt or extt data),
rf = rainflow(cycle.soc, [1:length(cycle.tsec)]);  

% get outputs from rainflow output matrix
nonzerorows    = find(rf(1,:)>0.5e-10);  % microcycle must be larger than some threshold to bother counting it
cycle.dsoc_i   = 2*rf(1,nonzerorows);    % delta soc swing is 2x amplitude
cycle.socavg_i = rf(2,nonzerorows);      % average SOC
cycle.ncycle_i = rf(3,nonzerorows);      % number of cycles for each delta soc (0.5 for half cycle or 1 for full cycle)
n0_i           = rf(4,nonzerorows);      % starting indice of microcycle
nf_i           = rf(4,nonzerorows)+cycle.ncycle_i.*rf(5,nonzerorows);  % ending indice of microcycle

% calculate additional outputs of average Crate and temperature for each microcycle
for i=1:length(cycle.dsoc_i)
    if nf_i(i) > length(cycle.tsec) % in case a half cycle has an out-of-range final indice
        nf_i(i) = length(cycle.tsec);
    end
    nn     = n0_i(i):nf_i(i);  % indices from time array corresponding to microcycle "i"
    dthr_i = (cycle.tsec(nf_i(i))-cycle.tsec(n0_i(i)))/3600;  % (hours) elapsed time of microcycle "i"
    
    % min/max/avg temperature of each microcycle
    cycle.TavgK_i(i)    = mean( cycle.TdegK(nn) );
    cycle.TmaxK_i(i)    = max ( cycle.TdegK(nn) );
    cycle.TminK_i(i)    = min ( cycle.TdegK(nn) );
    
    % grab current and delta time data for each microcycle
    II   = [cycle.I(nn)];
    tt   = [cycle.tsec(nn)];
    dt   = [0; diff(tt)];
    Idis =  II(find(II>0));
    dtdis=  dt(find(II>0));
    Ichg = -II(find(II<0));
    dtchg=  dt(find(II<0));

    % get time-weighted average of charge & discharge currents
    Ahdis_avg = sum(dtdis.*Idis) / 3600;
    Ahchg_avg = sum(dtchg.*Ichg) / 3600;
    % estimate average discharge & charge C-rates (does this estimate hold when there are rest periods in the cycle?)
    eps = 1e-20;
    cycle.Crate_dis_i(i) = cycle.dsoc_i(i) / (dthr_i+eps) * Ahdis_avg / (Ahdis_avg+Ahchg_avg+eps);
    cycle.Crate_chg_i(i) = cycle.dsoc_i(i) / (dthr_i+eps) * Ahchg_avg / (Ahdis_avg+Ahchg_avg+eps);
end

dt   =  [0; diff(cycle.tsec)];
Idis =  cycle.I(find(cycle.I>0));
dtdis=  dt(find(cycle.I>0));
Ichg = -cycle.I(find(cycle.I<0));
dtchg=  dt(find(cycle.I<0));

% Add scalar outputs
cycle.TavgK  = mean(cycle.TdegK);
cycle.TmaxK  = max (cycle.TdegK);
cycle.TminK  = min (cycle.TdegK);
cycle.Crate_rms   = sqrt( sum(dt    .* cycle.I.^2)/sum(dt) ) / perfMdl.Ahcapacity;
cycle.Crate_disrms= sqrt( sum(dtdis .* Idis.^2)/sum(dtdis) ) / perfMdl.Ahcapacity;
cycle.Crate_chgrms= sqrt( sum(dtchg .* Ichg.^2)/sum(dtchg) ) / perfMdl.Ahcapacity;

if 0 % set to 1 to produce plot
    figure; 
    subplot(2,2,1); plot(cycle.dsoc_i,'+');      ylabel('cycle.dsoc i')
    title('Rainflow Algorithm Output from func__LifeMdl__StressStatistics')
    subplot(2,2,2); plot(cycle.ncycle_i,'+');    ylabel('cycle.ncycle i')
    subplot(2,2,3); plot(cycle.Crate_dis_i,'+'); ylabel('cycle.Crate dis i')
    subplot(2,2,4); plot(cycle.Crate_chg_i,'+'); ylabel('cycle.Crate chg i')
end
