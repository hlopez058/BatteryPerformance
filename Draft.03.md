Building a Li-Ion Battery in Simulink
=====================================
> Created by Hector Lopez 5/10/17

A circuit equivalent needs to be translated into Simulink components. Instead of using a circuit simulator like the Power Systems Simscape library that comes as a Matlab module. The same circuit can be modeled with Simulink blocks.

Before we look at the circuit to model the battery lets understand the response of what a generic battery looks like. The image below shows the response of a discharging battery. The discharging comprises of different sections.

![](https://www.mathworks.com/help/physmod/sps/powersys/ref/batterynormcurve.gif)

The first section represents the exponential voltage drop when the battery is charged. The width of the drop depends on the battery type.
The second section represents the charge that can be extracted from the battery until the voltage drops below the battery nominal voltage.
Finally, the third section represents the total discharge of the battery, when the voltage drops rapidly.

When the battery current is negative, the battery recharges, following a charge characteristic. We will explore the charging response later on.

A generic equivalent battery circuit is shown below. This is a simplified model. Each component can be manipulated to change the discharge characteristics of the battery.

![Fig.1](/images/LiIonEqCircuit.jpeg)

To simulate different battery models the equivalent circuit can be modified to a dynamic equivalent circuit. With a dynamic model we can adjust the parameters needed to manipulate the discharge curve.

![Fig.1](/images/LiIonDynEqCircuit.jpeg)

The dynamic model components are as follows :
5. SOC, State of charge is fed back to the OCV to change the open circuit voltage.
1. DC voltage source representing the Open Circuit Voltage (OCV) source of the battery.
2. Rs, is the batteries internal DC resistance. This is different for the battery type and typically does not change.
3. Transient responses of the system are created by several RC circuits in series.
4. (A self discharge effect is calculated by another resistor across the Vt terminals. Not modeled here.)


### Calculate SOC

State of charge equation :

![Fig.1](/images/soc_equation.jpeg)

where,
- 'I' is current
- ( alpha ^ U ) is the Rate Capacity
- SOC0 is the previous state of charge

The 3600 is the time interval the Rate Capacity is based on. the 100 multiplied by the current is to change the units of the current to match Rate Capacity


Rate Capacity Effect - Use a lookup table. This is defined by the manufacturer for the type of battery.
The usable capacity varies with the magnitude of the current.

A logical equivalent to the SOC calculation formula in Simulink is provided below :

![Fig.1](/images/soc_calc.jpeg)


The Rate capacity lookup table can be created using a continious discharge test result. The below shows the continious discharge test of a LiFePO4 batery.



### Calculate OCV

Open circuit voltage is the voltage of battery during equilibrium state. It is one of the important parameter to be realized. The value of OCV is dependent on SOC. The OCV- SOC relationship can be characterized with polynomial equation. Therefore, for this subsystem, a mathematical relationship between OCV and SOC is established as a block diagram shown :

![Fig.1](/images/soc_ocv_calc.jpeg)







----






## References
1. L. W. Yao, J. A. Aziz, P. Y. Kong and N. R. N. Idris, "Modeling of lithium-ion battery using MATLAB/simulink," IECON 2013 - 39th Annual Conference of the IEEE Industrial Electronics Society, Vienna, 2013, pp. 1729-1734.
doi: 10.1109/IECON.2013.6699393

1. M. Chen and G. A. Rincon-Mora "Accurate electrical battery model capable of predicting runtime and I-V performance " IEEE Transactions on Energy Conversion vol. 21 no. 2 pp. 504-511 June 2006.

2. C. Liao H. Li and L. Wang "A dynamic equivalent circuit model of LiFePO4 cathode material for lithium ion batteries on hybrid electric vehicles " IEEE Vehicle Power and Propulsion Conference pp. 1662-1665 September 2009.

3. O. Tremblay L.-A. Dessaint and A.-I. Dekkiche "A generic battery model for the dynamic simulation of hybrid electric vehicles " IEEE Vehicle Power and Propulsion Coference pp. 284-289 September 2007.

4. H. Zhang M.Y. Chow "Comprehensive dynamic battery modelling for PHEV applications " IEEE Power and Energy Society General Meeting pp. 1-6 July 2010.

5. M. Knauff J. McLaughlin C. Dafis D. Niebur P. Singh H. Kwatny and C. Nwankpa "Simulink model of a lithium-ion battery for the hybrid power system testbed " Proceedings of the ASNE Intelligent Ships Symposium 2007.

6. H. He R. Xiong X. Zhang F. Sun and J. Fan "State-of-charge estimation of the lithium-ion battery using an adaptive extended kalman filter based on an improved thevenin model " IEEE Transactions on Vehicular Technology vol. 60 no. 4 pp. 1461-1469 May 2011.

7. R. Rao S. Vrudhula and D. N. Rakhmatov "Battery modeling for energy aware system design " Computer vol. 36 no. 12 pp.77-87 December 2003.

8. M. R. Jongerden and B. R. Haverkort "Which battery model to use? " IET Software vol. 3 no. 6 pp. 445-457 December 2009

9. L. Long P. Bauer and E. Kelder "A practical circuit-based model for liion battery cells in electric vehicle applications " IEEE Telecommunications Energy Conference (INTELEC) pp. 1-9 October 2011.
