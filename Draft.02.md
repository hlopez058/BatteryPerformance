Battery Models with Simscape
----------------
Using the Matlab "Simscape Power Systems" Library.

The Battery block implements a generic dynamic model parameterized to represent most popular types of rechargeable batteries.

This figure shows the battery equivalent circuit that the block models.

![equivalent circuit](https://www.mathworks.com/help/physmod/sps/powersys/ref/batteryh.gif)

The Generic battery block can be used to model the following types of batteries. The models are then injected into a "Simscape" circuit for analysis.

Types of Batteries:
- lead-acid
- lithium-ion
- nickel-metal-hydride

### Charge and Discharge Characteristics
The parameters of the equivalent circuit can be modified to represent a particular battery type, based on its discharge characteristics. A typical discharge curve consists of three sections.

![](https://www.mathworks.com/help/physmod/sps/powersys/ref/batterynormcurve.gif)

The first section represents the exponential voltage drop when the battery is charged. The width of the drop depends on the battery type.

The second section represents the charge that can be extracted from the battery until the voltage drops below the battery nominal voltage.

Finally, the third section represents the total discharge of the battery, when the voltage drops rapidly.

When the battery current is negative, the battery recharges, following a charge characteristic.

![](https://www.mathworks.com/help/physmod/sps/powersys/ref/batterynormcurvecharge.gif)

The model parameters are derived from discharge characteristics and assumed to be the same for charging.

The Exp(s) transfer function represents the hysteresis phenomenon for the lead-acid, nickel-cadmium (NiCD), and nickel-metal hydride (NiMH) batteries during charge and discharge cycles. The exponential voltage increases when a battery is charging, regardless of the battery state of charge. When the battery is discharging, the exponential voltage decreases immediately.

### Modeling from Specifications

A specification sheet can be used to generate all the different parameters needed to model the battery.

### Model Assumptions
- The internal resistance is assumed constant during the charge and discharge cycles and does not vary with the amplitude of the current.
- The parameters of the model are derived from discharge characteristics and assumed to be the same for charging.
- The capacity of the battery does not change with the amplitude of current (No Peukert effect).
- The self-discharge of the battery is not represented. It can be represented by adding a large resistance in parallel with the battery terminals.
The battery has no memory effect.

### Model Validation
Experimental validation of the model shown a maximum error of 5% (when SOC is between 10% and 100%) for charge (current from 0 through 2 C) and discharge (current from 0 through 5 C) dynamics.

Circuit Simulation with Simscape
--------------------------------
