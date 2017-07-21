
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

Direction :
1. Use a two layer neural net and a radial basis neural net . compare the differences in these different NN functions
    - what is the difference in error?
    - this is a measure of a discharge over an hour at a constant rate. 
    - will a 4C or 2C discharge rate allow for more accurate results?
    - rerun the simulations for all NN functions can we determine better error results?

2. Deeper analysis of the make up of the battery model
    - try to use the shannon equation in order to model the battery using the constants in the matlab model
    - describe each battery model, assumptions and characteristis
    - Understand the battery models and provide real life manufacturer curve estimates.

3. Capture enough data for the classifcation models and the error associated with it. 
    - create a controller that can use the chemistry detection and 



SHow a new neural net with diravative information recorded?
diravtive of v-soc , combine with the v-soc curve data 

run the neural net , and the rbf neural ne ton the 3 different battery techs. 