rainfall counting algorithm

The rainflow cycle counting algorithm is widely used while
fatigue life assessment of machine components or structures under non-constant amplitude
loading. Usually, the algorithm extract cycles from load, stress or strain
history obtained from measurement or simulation. As a results of the counting
several cycles and half-cycles with different amplitude and mean value are
obtained. With the advantage of fatigue damage accumulation hypothesis, like
Miners rule, the algorithm gives possibility to compute the expected fatigue
life under random loading conditions. Theoretically, of course ;-)



Li-ion batteries have an unmatchable combination of high energy and power density, making it the technology of choice for portable electronics, power tools, and hybrid/full electric vehicles [1]. If electric vehicles (EVs) replace the majority of gasoline powered transportation, Li-ion batteries will significantly reduce greenhouse gas emissions [2]. The high energy efficiency of Li-ion batteries may also allow their use in various electric grid applications, including improving the quality of energy harvested from wind, solar, geo-thermal and other renewable sources, thus contributing to their more widespread use and building an energy-sustainable economy. Therefore Li-ion batteries are of intense interest from both industry and government funding agencies, and research in this field has abounded in the recent years.

LiNiO2 (LNO) has same crystal structure with LiCoO2 and a similar theoretical specific capacity of 275 mAh g−1. Its relatively high energy density and lower cost compared to Co based materials are the main research driving forces. However, pure LNO cathodes are not favorable because the Ni2+ ions have a tendency to substitute Li+ sites during synthesis and delithiation, blocking the Li diffusion pathways [59]. LNO is also even more thermally unstable than LCO because Ni3+ is more readily reduced than Co3+[60]. Partial substitution of Ni with Co was found to be an effective way to reduce cationic disorder [61]. Insufficient thermal stability at high state-of-charge (SOC) can be improved via Mg doping [62], and adding a small amount of Al can improve both thermal stability and electrochemical performance [63].

As a result, the LiNi0.8Co0.15Al0.05O2 (NCA) cathode has found relatively widespread commercial use, for example, in Panasonic batteries for Tesla EVs. NCA has high usable discharge capacity (∼200 mAh g−1) and long storage calendar life compared to conventional Co-based oxide cathode. However it was reported that capacity fade may be severe at elevated temperature (40–70°C) due to solid electrolyte interface (SEI) growth and micro-crack growth at grain boundaries [64] ;  [65].

LFP/FEP
n exploring new cathode materials, researchers have developed a new class of compounds called polyanions. Large (XO4)3− (X = S, P, Si, As, Mo, W) polyanions occupy lattice positions and increase cathode redox potential while also stabilizing its structure [97]. LiFePO4 (LFP) is the representative material for the olivine structure, known for its thermal stability [51] and high power capability. In LFP, Li+ and Fe2+ occupy octahedral sites, while P is located in tetrahedral sites in a slightly distorted hexagonal close-packed (HCP) oxygen array (Fig. 4c). The major weaknesses of the LiFePO4 cathode include its relatively low average potential (Fig. 4e, Table 1) and low electrical and ionic conductivity. Intensive research over the last decade resulted in significant improvements in both performance and mechanistic understanding of LFP. Reduction in particle size in combination with carbon coating [98] and cationic doping [99] were found to be effective in increasing the rate performance. It is noteworthy that good electrochemical performance can also be achieved without carbon coating if particles are uniformly nano-sized and conductive nanocarbons are used within the cathodes [100]. Virus-templated amorphous anhydrous FP/CNT composite, for example, demonstrated promising results [101]. It was reported that the facile redox reaction in non-conducting LFP could be due to a curved one-dimensional lithium diffusion path through the [0 1 0] direction [102]. In general, however, the low density of nanostructured LFP electrodes and their low average potential limit the energy density of LFP cells. Recently, a novel non-olivine allaudite LFP was reported and showed fundamentally different electrochemical behavior from that of olivine LFP [103].


Questions:
* [ ] What are the different battery types that are in demand.

Controller ->  Battery ->
<--

Equivelent circuit for battery
- nonlinear and specific to the battery type.
- parameter estimation: combination of smulink and matlab optimization functions

1. Parameterize a battery model

    model(a,b,c) --> out 
in->                       --> =? (then feedbck to model())
     experiment --> out

then excite both the model and the Experimental
and check the outputs

- experiment has to be done. 
- use a library called simscape*

open voltage source- measurement i get when i put leads on the battery
rc circuitshandles the curve in voltage drop
a parasidic branch is the self discharge



PHEV-type graphite/Ni-Co-Al cell
 A123 2.3Ah 26650 graphite/iron-phosphate cell




Reference Papers 

1. Battery Charging and Discharging kit with DAQ to aid SOC Estimation
2. Lead-Acid Battery for HEC using Fuzzy Controller and Ultracapacitor
3. Generic Battery Model Covering Self-discharge and Internal Resistance Variation
3. Simulink Based Performance Analysis of Lead Acid Batteries with the Variation of Load Current and Temperature
4. Applicatoins of Pulse Width Modulation to LEDs,Fuel CELLS and Battery Technology

TODO:
1. Summarize thesis [4]
2. Simulink Model for Battery 
    - Copy FPL battery model 
    - build a simulink project with powersim
3. Life of battery what are different parameters and disturbances ?
    - Average Temperature
    - Depth of discharge
    - Exposure to long periods of discharge
    - Charging Current
    - Load Current
    - Areas under charging/discharging phases
    - Self-discharging (internal chemical reactions) battery characteristic
    - cycle number
    - Internal heat generation
    - Internal Resistance
    - State of Charge
    - Ambient temperature effects
    - Terminal voltage and capacity effected by load and temp.
    - Voltage
    - Discharging current
    - Depth of Charge
    - Capacity
    - High Specific Energy 

Fuzzy Controller
? can a fuzzy controller be implemented on the battery charging/discharging models?



Battery Characterization

The first step in the development of an accurate battery model is to build and parameterize an equivalent circuit that reflects the battery’s nonlinear behavior and dependencies on temperature, SOC, SOH, and current. These dependencies are unique to each battery’s chemistry and need to be determined using measurements performed on battery cells of exactly the same type as those for which the controller is being designed. 

SOC Estimation

One common application of battery models is to develop algorithms for SOC estimation. Open-circuit voltage (OCV) measurement and current integration (coulomb counting) may give reasonable estimates for SOC. However, to estimate the SOC in modern battery chemistries that have flat OCV-SOC discharge signatures, you need to use a different approach, such as Kalman filtering.

Degradation

Batteries degrade over time due to their calendar life and charge-discharge cycles, showing a gradual loss in reserve capacity and an increase in internal resistance. The battery management system (BMS) needs to adapt to these changes for effective control of the battery. Battery models can help you develop a BMS that accounts for degradation.

High Fidelity Electrical Model with Thermal Dependence for Characterization and Simulation of High Power Lithium Battery Cells - IEEE 2012
Lithium Battery Model with Thermal Effects for System-Level Analysis (24:05) - Webinar
Battery Model Parameter Estimation Using a Layered Technique - SAE 2013
Automating Battery Model Parameter Estimation using Experimental Data (25:28) - Webinar
Simplified Extended Kalman Filter Observer for Battery SOC Estimation - SAE 2013
Model-Based Parameter Identification of Healthy and Aged Li-ion Batteries for Electric Vehicle Applications - SAE 2015
Battery Pack Modeling, Simulation, and Deployment on a Multicore Real Time Target  - SAE 2014
Real-Time Simulation of Battery Packs Using Multicore Computers (22:57) - Webinar
Battery Simulation and Controls - MathWorks Consulting