
Introduction
------------
Goal : Dynamic classification of battery chemistry
Future Usage :  Future smart grid applications or smart charging systems that would need to identify battery chemistry dynamically

Idea : Connect a battery to a circuit/grid the controller will run the battery and classify the battery chemistry based on pre-defined model simulations. 

Battery Models
1. LiFePO4
2. Lead Acid
3. Ni-MH
Each battery model is built using the mathworks matlab simscape libraries.
Not modeled with aging and temperature effects.


Procedure :
1. Create Battery Model 12v
2. Create simulation to run for 1 hour (3600s)
3. Sweep load current from 0 to 10A at .1A intervals and capture each Voltage vs. SOC discharge curve
4. There will be 100 discharge curves per battery. Create a stacked array of the current value and the voltage and soc [3,3600*100]   