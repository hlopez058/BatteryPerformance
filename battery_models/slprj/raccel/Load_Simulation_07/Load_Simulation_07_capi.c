#include "__cf_Load_Simulation_07.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "Load_Simulation_07_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "Load_Simulation_07.h"
#include "Load_Simulation_07_capi.h"
#include "Load_Simulation_07_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 34 , TARGET_STRING
(
"Load_Simulation_07/Trained Neural Net Discharge Curve  Classifier Function"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 1 , 0 , TARGET_STRING (
"Load_Simulation_07/From Workspace" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0
, 0 } , { 2 , 0 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Current Measurement/do not delete this gain"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 3 , 0 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Data Type Conversion1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 4 , 0 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Data Type Conversion2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 5 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Fcn1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 6 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Fcn6" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 7 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Gain" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 8 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Gain2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 9 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/R1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 10 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/R2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 11 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/R3" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 12 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/R4" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 13 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/int(i)" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 14 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/it init" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 15 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Product" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 16 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Product1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 17 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Product2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 18 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Saturation" ) ,
TARGET_STRING ( "SOC (%)" ) , 0 , 0 , 0 , 0 , 0 } , { 19 , 0 , TARGET_STRING
( "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Add" ) ,
TARGET_STRING ( "Voltage (V)" ) , 0 , 0 , 0 , 0 , 0 } , { 20 , 0 ,
TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Add2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 21 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Add3" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 22 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Sum" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 23 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Switch" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 24 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Switch1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 25 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Switch2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 26 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Switch3" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 27 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Switch4" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 28 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Switch5" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 29 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Switch6" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 30 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Current filter"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 31 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Current filter1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 32 , 0 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Current Measurement/do not delete this gain"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 33 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Data Type Conversion1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 34 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Data Type Conversion2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 35 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Fcn1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 36 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Fcn6" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 37 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Gain" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 38 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Gain2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 39 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/R1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 40 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/R2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 41 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/R3" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 42 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/R4" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 43 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/int(i)" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 44 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/it init" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 45 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Product" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 46 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Product1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 47 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Product2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 48 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Saturation" ) ,
TARGET_STRING ( "SOC (%)" ) , 0 , 0 , 0 , 0 , 0 } , { 49 , 0 , TARGET_STRING
( "Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Add" ) ,
TARGET_STRING ( "Voltage (V)" ) , 0 , 0 , 0 , 0 , 0 } , { 50 , 0 ,
TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Add2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 51 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Add3" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 52 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Sum" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 53 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Switch" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 54 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Switch1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 55 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Switch2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 56 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Switch3" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 57 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Switch4" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 58 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Switch5" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 59 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Switch6" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 60 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Current filter" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 61 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Current filter1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 62 , 0 , TARGET_STRING (
 "Load_Simulation_07/12v, 10Ah  LiFePO4 /Current Measurement/do not delete this gain"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 63 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Data Type Conversion1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 64 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Data Type Conversion2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 65 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Fcn1" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 66 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Fcn6" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 1 } , { 67 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Gain" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 68 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Gain2" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 69 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/R1" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 70 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/R2" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 71 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/R3" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 72 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/R4" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 73 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/int(i)" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 74 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/it init" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 1 } , { 75 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Product" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 76 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Product1" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 77 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Product2" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 78 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Saturation" ) , TARGET_STRING (
"SOC (%)" ) , 0 , 0 , 0 , 0 , 0 } , { 79 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Add" ) , TARGET_STRING (
"Voltage (V)" ) , 0 , 0 , 0 , 0 , 0 } , { 80 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Add2" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 81 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Add3" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 82 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Sum" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 2 } , { 83 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Switch" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 84 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Switch1" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 85 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Switch2" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 86 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Switch3" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 2 } , { 87 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Switch4" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 2 } , { 88 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Switch5" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 1 } , { 89 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Switch6" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 2 } , { 90 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Current filter" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 91 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Current filter1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 92 , 0 , TARGET_STRING (
"Load_Simulation_07/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 93 , 0 , TARGET_STRING (
"Load_Simulation_07/powergui/EquivalentModel2/State-Space" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 94 , 0 , TARGET_STRING (
"Load_Simulation_07/powergui/EquivalentModel3/State-Space" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 95 , 0 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/E_dyn Charge/Multiport Switch1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 96 , 6 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/E_dyn Charge/Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 97 , 4 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/E_dyn Charge/Product1"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 98 , 5 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/E_dyn Charge/Product2"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 99 , 7 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/E_dyn Charge/Product3"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 100 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Exp/Abs" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 101 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Exp/Gain1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 102 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Exp/Gain4" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 103 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Exp/Integrator2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 104 , 0 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Exp/Multiport Switch1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 105 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Exp/Divide" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 106 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Exp/Add3" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 107 , 0 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Power loss estimation/Abs"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 108 , 0 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Power loss estimation/Abs1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 109 , 0 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Power loss estimation/Fcn3"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 110 , 0 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Power loss estimation/Gain"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 111 , 0 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Power loss estimation/Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 112 , 0 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Power loss estimation/Add"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 113 , 0 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Saturation Dynamic/LowerRelop1"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 1 } , { 114 , 0 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Saturation Dynamic/UpperRelop"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 1 } , { 115 , 9 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Saturation Dynamic/Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 116 , 0 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Saturation Dynamic/Switch2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 117 , 0 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Saturation Dynamic1/LowerRelop1"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 1 } , { 118 , 0 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Saturation Dynamic1/UpperRelop"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 1 } , { 119 , 10 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Saturation Dynamic1/Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 120 , 0 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Saturation Dynamic1/Switch2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 121 , 0 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Saturation Dynamic2/LowerRelop1"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 1 } , { 122 , 0 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Saturation Dynamic2/UpperRelop"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 1 } , { 123 , 11 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Saturation Dynamic2/Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 124 , 0 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Saturation Dynamic2/Switch2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 125 , 0 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Thermal Model/Gain"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 126 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Thermal Model/Sum"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 127 , 0 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Thermal Model/Transfer Fcn1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 128 , 0 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/E_dyn Charge/Multiport Switch1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 129 , 17 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/E_dyn Charge/Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 130 , 15 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/E_dyn Charge/Product1"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 131 , 16 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/E_dyn Charge/Product2"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 132 , 18 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/E_dyn Charge/Product3"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 133 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Exp/Abs" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 134 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Exp/Gain1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 135 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Exp/Gain4" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 136 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Exp/Integrator2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 137 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Exp/Multiport Switch1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 138 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Exp/Divide" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 139 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Exp/Add3" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 140 , 0 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Power loss estimation/Abs"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 141 , 0 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Power loss estimation/Abs1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 142 , 0 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Power loss estimation/Fcn3"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 143 , 0 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Power loss estimation/Gain"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 144 , 0 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Power loss estimation/Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 145 , 0 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Power loss estimation/Add"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 146 , 0 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Saturation Dynamic/LowerRelop1"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 1 } , { 147 , 0 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Saturation Dynamic/UpperRelop"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 1 } , { 148 , 20 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Saturation Dynamic/Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 149 , 0 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Saturation Dynamic/Switch2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 150 , 0 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Saturation Dynamic1/LowerRelop1"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 1 } , { 151 , 0 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Saturation Dynamic1/UpperRelop"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 1 } , { 152 , 21 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Saturation Dynamic1/Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 153 , 0 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Saturation Dynamic1/Switch2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 154 , 0 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Saturation Dynamic2/LowerRelop1"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 1 } , { 155 , 0 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Saturation Dynamic2/UpperRelop"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 1 } , { 156 , 22 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Saturation Dynamic2/Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 157 , 0 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Saturation Dynamic2/Switch2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 158 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Thermal Model/Gain"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 159 , 0 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Thermal Model/Sum" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 160 , 0 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Thermal Model/Transfer Fcn1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 161 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/E_dyn Charge/Multiport Switch1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 162 , 28 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/E_dyn Charge/Product" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 163 , 26 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/E_dyn Charge/Product1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 164 , 27 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/E_dyn Charge/Product2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 165 , 29 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/E_dyn Charge/Product3" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 166 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Exp/Abs" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 167 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Exp/Gain1" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 168 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Exp/Gain4" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 169 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Exp/Integrator2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 170 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Exp/Multiport Switch1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 171 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Exp/Divide" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 172 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Exp/Add3" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 173 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Power loss estimation/Abs" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 174 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Power loss estimation/Abs1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 175 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Power loss estimation/Fcn3" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 176 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Power loss estimation/Gain" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 177 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Power loss estimation/Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 178 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Power loss estimation/Add" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 179 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Saturation Dynamic/LowerRelop1"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 1 } , { 180 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Saturation Dynamic/UpperRelop"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 1 } , { 181 , 31 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Saturation Dynamic/Switch" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 182 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Saturation Dynamic/Switch2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 183 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Saturation Dynamic1/LowerRelop1"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 1 } , { 184 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Saturation Dynamic1/UpperRelop"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 1 } , { 185 , 32 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Saturation Dynamic1/Switch" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 186 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Saturation Dynamic1/Switch2" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 187 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Saturation Dynamic2/LowerRelop1"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 1 } , { 188 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Saturation Dynamic2/UpperRelop"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 1 } , { 189 , 33 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Saturation Dynamic2/Switch" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 190 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Saturation Dynamic2/Switch2" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 191 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Thermal Model/Gain" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 192 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Thermal Model/Sum" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 193 , 0 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Thermal Model/Transfer Fcn1" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 194 , 0 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Thermal Model/Transfer Fcn (with initial outputs)/State Space"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 195 , 0 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Thermal Model/Transfer Fcn (with initial outputs)/State Space"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 196 , 0 , TARGET_STRING (
 "Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Thermal Model/Transfer Fcn (with initial outputs)/State Space"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL
) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 197 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery " ) , TARGET_STRING (
"BatType" ) , 0 , 0 , 0 } , { 198 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery " ) , TARGET_STRING (
"SOC" ) , 0 , 0 , 0 } , { 199 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery" ) , TARGET_STRING (
"BatType" ) , 0 , 0 , 0 } , { 200 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery" ) , TARGET_STRING ( "SOC"
) , 0 , 0 , 0 } , { 201 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 " ) , TARGET_STRING ( "BatType" ) , 0
, 0 , 0 } , { 202 , TARGET_STRING ( "Load_Simulation_07/12v, 10Ah  LiFePO4 "
) , TARGET_STRING ( "SOC" ) , 0 , 0 , 0 } , { 203 , TARGET_STRING (
"Load_Simulation_07/  2" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 204
, TARGET_STRING ( "Load_Simulation_07/From Workspace" ) , TARGET_STRING (
"Time0" ) , 0 , 2 , 0 } , { 205 , TARGET_STRING (
"Load_Simulation_07/From Workspace" ) , TARGET_STRING ( "Data0" ) , 0 , 2 , 0
} , { 206 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Ta" ) , TARGET_STRING
( "Value" ) , 0 , 0 , 0 } , { 207 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Ta" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 208 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Ta" ) , TARGET_STRING ( "Value" ) , 0
, 0 , 0 } , { 209 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Current Measurement/do not delete this gain"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 210 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 211 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Constant1" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 212 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Constant10" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 213 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Constant11" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 214 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Constant12" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 215 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Constant13" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 216 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Constant14" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 217 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Constant15" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 218 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Constant16" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 219 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Constant2" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 220 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Constant3" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 221 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Constant4" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 222 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Constant5" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 223 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Constant6" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 224 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Constant7" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 225 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Constant8" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 226 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Constant9" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 227 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 228 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Gain2" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 229 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/R" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 230 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/R1" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 231 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/R2" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 232 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/R3" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 233 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/R4" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 234 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/int(i)" ) ,
TARGET_STRING ( "UpperSaturationLimit" ) , 0 , 0 , 0 } , { 235 ,
TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/int(i)" ) ,
TARGET_STRING ( "LowerSaturationLimit" ) , 0 , 0 , 0 } , { 236 ,
TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/it init1" ) ,
TARGET_STRING ( "X0" ) , 0 , 0 , 0 } , { 237 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Saturation" ) ,
TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 238 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Saturation" ) ,
TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } , { 239 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Saturation2" )
, TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 240 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Saturation2" )
, TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } , { 241 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Saturation3" )
, TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 242 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Saturation3" )
, TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } , { 243 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Switch" ) ,
TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 244 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Switch1" ) ,
TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 245 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Switch2" ) ,
TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 246 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Switch3" ) ,
TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 247 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Switch4" ) ,
TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 248 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Switch5" ) ,
TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 249 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Switch6" ) ,
TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 250 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Current filter"
) , TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 251 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Current filter"
) , TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 252 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Current filter1"
) , TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 253 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Current filter1"
) , TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 254 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Current Measurement/do not delete this gain"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 255 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 256 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Constant1" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 257 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Constant10" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 258 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Constant11" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 259 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Constant12" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 260 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Constant13" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 261 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Constant14" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 262 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Constant15" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 263 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Constant16" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 264 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Constant2" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 265 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Constant3" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 266 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Constant4" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 267 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Constant5" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 268 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Constant6" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 269 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Constant7" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 270 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Constant8" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 271 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Constant9" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 272 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 273 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Gain2" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 274 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/R" ) , TARGET_STRING
( "Gain" ) , 0 , 0 , 0 } , { 275 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/R1" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 276 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/R2" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 277 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/R3" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 278 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/R4" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 279 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/int(i)" ) ,
TARGET_STRING ( "UpperSaturationLimit" ) , 0 , 0 , 0 } , { 280 ,
TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/int(i)" ) ,
TARGET_STRING ( "LowerSaturationLimit" ) , 0 , 0 , 0 } , { 281 ,
TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/it init1" ) ,
TARGET_STRING ( "X0" ) , 0 , 0 , 0 } , { 282 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Saturation" ) ,
TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 283 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Saturation" ) ,
TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } , { 284 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Saturation2" ) ,
TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 285 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Saturation2" ) ,
TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } , { 286 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Saturation3" ) ,
TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 287 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Saturation3" ) ,
TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } , { 288 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Switch" ) ,
TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 289 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Switch1" ) ,
TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 290 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Switch2" ) ,
TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 291 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Switch3" ) ,
TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 292 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Switch4" ) ,
TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 293 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Switch5" ) ,
TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 294 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Switch6" ) ,
TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 295 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Current filter" ) ,
TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 296 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Current filter" ) ,
TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 297 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Current filter1" ) ,
TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 298 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Current filter1" ) ,
TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 299 , TARGET_STRING (
 "Load_Simulation_07/12v, 10Ah  LiFePO4 /Current Measurement/do not delete this gain"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 300 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Constant" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 301 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Constant1" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 302 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Constant10" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 303 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Constant11" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 304 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Constant12" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 305 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Constant13" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 306 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Constant14" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 307 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Constant15" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 308 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Constant16" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 309 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Constant2" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 310 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Constant3" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 311 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Constant4" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 312 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Constant5" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 313 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Constant6" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 314 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Constant7" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 315 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Constant8" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 316 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Constant9" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 317 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Gain" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 318 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Gain2" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 319 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/R" ) , TARGET_STRING ( "Gain" )
, 0 , 0 , 0 } , { 320 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/R1" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 321 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/R2" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 322 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/R3" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 323 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/R4" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 324 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/int(i)" ) , TARGET_STRING (
"UpperSaturationLimit" ) , 0 , 0 , 0 } , { 325 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/int(i)" ) , TARGET_STRING (
"LowerSaturationLimit" ) , 0 , 0 , 0 } , { 326 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/it init1" ) , TARGET_STRING (
"X0" ) , 0 , 0 , 0 } , { 327 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Saturation" ) , TARGET_STRING (
"UpperLimit" ) , 0 , 0 , 0 } , { 328 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Saturation" ) , TARGET_STRING (
"LowerLimit" ) , 0 , 0 , 0 } , { 329 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Saturation2" ) , TARGET_STRING
( "UpperLimit" ) , 0 , 0 , 0 } , { 330 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Saturation2" ) , TARGET_STRING
( "LowerLimit" ) , 0 , 0 , 0 } , { 331 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Saturation3" ) , TARGET_STRING
( "UpperLimit" ) , 0 , 0 , 0 } , { 332 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Saturation3" ) , TARGET_STRING
( "LowerLimit" ) , 0 , 0 , 0 } , { 333 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Switch" ) , TARGET_STRING (
"Threshold" ) , 0 , 0 , 0 } , { 334 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Switch1" ) , TARGET_STRING (
"Threshold" ) , 0 , 0 , 0 } , { 335 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Switch2" ) , TARGET_STRING (
"Threshold" ) , 0 , 0 , 0 } , { 336 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Switch3" ) , TARGET_STRING (
"Threshold" ) , 0 , 0 , 0 } , { 337 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Switch4" ) , TARGET_STRING (
"Threshold" ) , 0 , 0 , 0 } , { 338 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Switch5" ) , TARGET_STRING (
"Threshold" ) , 0 , 0 , 0 } , { 339 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Switch6" ) , TARGET_STRING (
"Threshold" ) , 0 , 0 , 0 } , { 340 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Current filter" ) ,
TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 341 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Current filter" ) ,
TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 342 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Current filter1" ) ,
TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 343 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Current filter1" ) ,
TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 344 , TARGET_STRING (
"Load_Simulation_07/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING
( "P1" ) , 0 , 3 , 0 } , { 345 , TARGET_STRING (
"Load_Simulation_07/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING
( "P2" ) , 0 , 4 , 0 } , { 346 , TARGET_STRING (
"Load_Simulation_07/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING
( "P4" ) , 0 , 5 , 0 } , { 347 , TARGET_STRING (
"Load_Simulation_07/powergui/EquivalentModel2/State-Space" ) , TARGET_STRING
( "P1" ) , 0 , 3 , 0 } , { 348 , TARGET_STRING (
"Load_Simulation_07/powergui/EquivalentModel2/State-Space" ) , TARGET_STRING
( "P2" ) , 0 , 4 , 0 } , { 349 , TARGET_STRING (
"Load_Simulation_07/powergui/EquivalentModel2/State-Space" ) , TARGET_STRING
( "P4" ) , 0 , 6 , 0 } , { 350 , TARGET_STRING (
"Load_Simulation_07/powergui/EquivalentModel3/State-Space" ) , TARGET_STRING
( "P1" ) , 0 , 3 , 0 } , { 351 , TARGET_STRING (
"Load_Simulation_07/powergui/EquivalentModel3/State-Space" ) , TARGET_STRING
( "P2" ) , 0 , 4 , 0 } , { 352 , TARGET_STRING (
"Load_Simulation_07/powergui/EquivalentModel3/State-Space" ) , TARGET_STRING
( "P4" ) , 0 , 7 , 0 } , { 353 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Compare To Zero/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 354 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Compare To Zero2/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 355 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/E_dyn Charge/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 356 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/E_dyn Charge/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 357 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/E_dyn Charge/Constant3"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 358 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/E_dyn Charge/Constant4"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 359 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Exp/Gain1" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 360 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Exp/Gain4" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 361 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Power loss estimation/Gain"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 362 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Thermal Model/Gain"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 363 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Thermal Model/Transfer Fcn1"
) , TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 364 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Thermal Model/Transfer Fcn1"
) , TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 365 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Compare To Zero/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 366 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Compare To Zero2/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 367 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/E_dyn Charge/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 368 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/E_dyn Charge/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 369 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/E_dyn Charge/Constant3"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 370 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/E_dyn Charge/Constant4"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 371 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Exp/Gain1" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 372 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Exp/Gain4" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 373 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Power loss estimation/Gain"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 374 , TARGET_STRING (
"Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Thermal Model/Gain"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 375 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Thermal Model/Transfer Fcn1"
) , TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 376 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Thermal Model/Transfer Fcn1"
) , TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 377 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Compare To Zero/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 378 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Compare To Zero2/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 379 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/E_dyn Charge/Constant1" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 380 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/E_dyn Charge/Constant2" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 381 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/E_dyn Charge/Constant3" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 382 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/E_dyn Charge/Constant4" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 383 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Exp/Gain1" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 384 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Exp/Gain4" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 385 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Power loss estimation/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 386 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Thermal Model/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 387 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Thermal Model/Transfer Fcn1" )
, TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 388 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Thermal Model/Transfer Fcn1" )
, TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 389 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Exp/Compare To Zero2/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 390 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Power loss estimation/Compare To Zero2/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 391 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Thermal Model/Transfer Fcn (with initial outputs)/State Space"
) , TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 392 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Thermal Model/Transfer Fcn (with initial outputs)/State Space"
) , TARGET_STRING ( "B" ) , 0 , 0 , 0 } , { 393 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Thermal Model/Transfer Fcn (with initial outputs)/State Space"
) , TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 394 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Lead Acid battery /Model/Thermal Model/Transfer Fcn (with initial outputs)/State Space"
) , TARGET_STRING ( "X0" ) , 0 , 0 , 0 } , { 395 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Exp/Compare To Zero2/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 396 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Power loss estimation/Compare To Zero2/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 397 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Thermal Model/Transfer Fcn (with initial outputs)/State Space"
) , TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 398 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Thermal Model/Transfer Fcn (with initial outputs)/State Space"
) , TARGET_STRING ( "B" ) , 0 , 0 , 0 } , { 399 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Thermal Model/Transfer Fcn (with initial outputs)/State Space"
) , TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 400 , TARGET_STRING (
 "Load_Simulation_07/12 volts, 10 Ah  Ni-MH battery/Model/Thermal Model/Transfer Fcn (with initial outputs)/State Space"
) , TARGET_STRING ( "X0" ) , 0 , 0 , 0 } , { 401 , TARGET_STRING (
"Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Exp/Compare To Zero2/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 402 , TARGET_STRING (
 "Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Power loss estimation/Compare To Zero2/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 403 , TARGET_STRING (
 "Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Thermal Model/Transfer Fcn (with initial outputs)/State Space"
) , TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 404 , TARGET_STRING (
 "Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Thermal Model/Transfer Fcn (with initial outputs)/State Space"
) , TARGET_STRING ( "B" ) , 0 , 0 , 0 } , { 405 , TARGET_STRING (
 "Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Thermal Model/Transfer Fcn (with initial outputs)/State Space"
) , TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 406 , TARGET_STRING (
 "Load_Simulation_07/12v, 10Ah  LiFePO4 /Model/Thermal Model/Transfer Fcn (with initial outputs)/State Space"
) , TARGET_STRING ( "X0" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0
, 0 } } ; static const rtwCAPI_ModelParameters rtModelParameters [ ] = { { 0
, ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . hoa4ffors0 , & rtB . mzsf40mopc ,
& rtB . ml5sunf4wl , & rtB . ksvnvluruk , & rtB . hbrgffmmwb , & rtB .
ebzvvcw0uj , & rtB . djwy2mdgcr , & rtB . jm35sgpar2 , & rtB . jce4jecbbp , &
rtB . gi1zeejtvl , & rtB . eafza0ignh , & rtB . mfjtrcfybp , & rtB .
cu3rpzq1ir , & rtB . iu235cbed5 , & rtB . ffdlej0esm , & rtB . pmxqn1j2n3 , &
rtB . lpwludxfnb , & rtB . losq44zfsw , & rtB . nvl5qjckkv , & rtB .
kgwpzskznu , & rtB . kypwxy50kw , & rtB . abmbri4rct , & rtB . lzetnopoo3 , &
rtB . p4h4wunzca , & rtB . bb25sco2fm , & rtB . msdjbx4ftv , & rtB .
jru2iqrfmm , & rtB . pvwijbyxkr , & rtB . gu5rsica4y , & rtB . fgkxbpykg1 , &
rtB . mo0fhfwjbn , & rtB . cb1nnepflz , & rtB . aepfzat2ah , & rtB .
dg1ivic2cv , & rtB . fmkuq1m3bb , & rtB . adxkajg20f , & rtB . mdkcdrc1dj , &
rtB . poeuuptz0e , & rtB . etpdoa2xuk , & rtB . b4dywjx5hn , & rtB .
ik21zuu0w2 , & rtB . dgq5far14c , & rtB . awto1smfy3 , & rtB . hwk4furfbr , &
rtB . brt0odp1ig , & rtB . nisapdp2vu , & rtB . j2m1rxr1a0 , & rtB .
foxxmgfp1n , & rtB . p5iut1x42c , & rtB . bb0v5z1gyy , & rtB . g4hw1qgbdv , &
rtB . ecaohy0st5 , & rtB . koz3cqzv1c , & rtB . n0ykw2xnss , & rtB .
prq1vlt5vx , & rtB . bzhvuobncb , & rtB . mfmapc1zif , & rtB . n5c0k4fbwb , &
rtB . m4i5mlkre0 , & rtB . i0dlbs1b2l , & rtB . jqky25xmle , & rtB .
ffql2fnkid , & rtB . btbyo2vcmz , & rtB . j5n5fyudax , & rtB . f3yztw02af , &
rtB . bybpkn3fg3 , & rtB . hesfhsyv0h , & rtB . lgl3sevxjx , & rtB .
h2cdsbamjg , & rtB . mkgovfegci , & rtB . kjbniesfcu , & rtB . dltlpyqxxt , &
rtB . bfx2u5xgpq , & rtB . ascuylmfea , & rtB . ebadym5xni , & rtB .
opjh3hy4jh , & rtB . gx3vfbmrpy , & rtB . poiu0irxc0 , & rtB . gqdjkmiehk , &
rtB . mqfk5v4diy , & rtB . ommpg3cgpv , & rtB . olb0grj3j3 , & rtB .
nfweyj1qvq , & rtB . hrgapvp0ps , & rtB . i1k1tidl2o , & rtB . ei5r5a5pav , &
rtB . p4pflkgeyq , & rtB . hrenjgvsp2 , & rtB . ded05j4tle , & rtB .
nwx1m5flyz , & rtB . kcia4oomek , & rtB . gre3fyyedb , & rtB . oben2eao5k , &
rtB . ltqlujcfbs , & rtB . mj03tas4fg , & rtB . b4dvnbx2z0 , & rtB .
cgcsvraqod [ 0 ] , & rtB . hp4pbsppeu [ 0 ] , & rtB . amabyxe2q5 [ 0 ] , &
rtB . gayccjz0g2 [ 0 ] , & rtB . bb0be3gnia , & rtB . j4gfvflild , & rtB .
hqpcpdn5qa , & rtB . ia1kg5fvtb , & rtB . on5jb3go3s , & rtB . nf3rdcvax5 , &
rtB . jbhxgjw5cy , & rtB . dwb42stmvv , & rtB . pgudi1oete , & rtB .
gu3qbji4xc , & rtB . fmw5kmtm1r , & rtB . bwvje3ihiw , & rtB . m0yglvlyme , &
rtB . l5k4v4pkri , & rtB . bbvpjaqjcj , & rtB . jl0as1i1kv , & rtB .
brqcacx4dy , & rtB . p3hqh0p1ve , & rtB . gibfnm5yif , & rtB . gucbgg34uu , &
rtB . o4aync4hqi , & rtB . h5yixci3b5 , & rtB . iu45wsrpul , & rtB .
chxlnefiu2 , & rtB . bn5kz230z1 , & rtB . e3cqouyy3w , & rtB . dcqdhsbevr , &
rtB . aesu3l5yyk , & rtB . o2w0cdwc0f , & rtB . lwryrfr1np [ 0 ] , & rtB .
dhz0gnwoz2 [ 0 ] , & rtB . dehp52jxod [ 0 ] , & rtB . psc1bdwm0e [ 0 ] , &
rtB . o3lepigeif , & rtB . dabeiiy4xg , & rtB . d5351zjf4x , & rtB .
guy2kz5ncd , & rtB . fzutsooicn , & rtB . dfbrmr4pqz , & rtB . eoju45gqpq , &
rtB . jaquvxw41i , & rtB . lvkqstzrdf , & rtB . oaqch21uel , & rtB .
lmk5yid3hu , & rtB . grozn2da0l , & rtB . dzqkvxhkd1 , & rtB . ewa4jwoiei , &
rtB . h54wfmqlk0 , & rtB . b3jprbo2ch , & rtB . offgvp1su2 , & rtB .
druqytbldp , & rtB . kjxguscvc3 , & rtB . pjy23u5hnz , & rtB . kyxi4xk5b1 , &
rtB . f142q2bocw , & rtB . b1tb4rlksj , & rtB . oiiyyqltbq , & rtB .
g3fahebeoh , & rtB . n0r3f03erl , & rtB . e0dl0dglhu , & rtB . lwlovbyzf2 , &
rtB . iirqhbasaw , & rtB . egi1glv2iz [ 0 ] , & rtB . dpzsk0fv2e [ 0 ] , &
rtB . aufyna3xwp [ 0 ] , & rtB . g03b5ho0xb [ 0 ] , & rtB . j3xdv1bkdg , &
rtB . brdas51kj1 , & rtB . maqw5opry0 , & rtB . fzd1h5apha , & rtB .
m12jzkvpeg , & rtB . ffgdskx2hu , & rtB . acjy0wcx33 , & rtB . njpjxwiwga , &
rtB . eajyu4e2gg , & rtB . mc3kmonqyw , & rtB . csv1q2rmqm , & rtB .
hap1ivasmg , & rtB . o0zujw030w , & rtB . hvjsipjvee , & rtB . nj4n1mxjv0 , &
rtB . btonwzxytu , & rtB . dfjf12bep4 , & rtB . c33k25rpdh , & rtB .
pm3wjc2bv1 , & rtB . dl2oj2hwn5 , & rtB . i2cij1nsan , & rtB . kvprg4ppnw , &
rtB . eqm015gtbx , & rtB . p5bxowhy3u , & rtB . dz2enm0ww0 , & rtB .
oepc1i4s5o , & rtB . gnxuzeutps , & rtB . agnwtijpiy , & rtB . a4eiiet2o0 , &
rtB . lad2rbhq0d , & rtB . cy2mdsactk , & rtP .
u2volts10AhLeadAcidbattery_BatType , & rtP . u2volts10AhLeadAcidbattery_SOC ,
& rtP . u2volts10AhNiMHbattery_BatType , & rtP . u2volts10AhNiMHbattery_SOC ,
& rtP . u2v10AhLiFePO4_BatType , & rtP . u2v10AhLiFePO4_SOC , & rtP . u_Value
, & rtP . FromWorkspace_Time0 [ 0 ] , & rtP . FromWorkspace_Data0 [ 0 ] , &
rtP . Ta_Value , & rtP . Ta_Value_grpxumhhux , & rtP . Ta_Value_ko1cwv42q0 ,
& rtP . donotdeletethisgain_Gain , & rtP . Constant_Value , & rtP .
Constant1_Value , & rtP . Constant10_Value , & rtP . Constant11_Value , & rtP
. Constant12_Value , & rtP . Constant13_Value , & rtP . Constant14_Value , &
rtP . Constant15_Value , & rtP . Constant16_Value , & rtP .
Constant2_Value_cdqfgwpsti , & rtP . Constant3_Value_iqsu23z4ce , & rtP .
Constant4_Value , & rtP . Constant5_Value , & rtP . Constant6_Value , & rtP .
Constant7_Value , & rtP . Constant8_Value , & rtP . Constant9_Value , & rtP .
Gain_Gain , & rtP . Gain2_Gain , & rtP . R_Gain , & rtP . R1_Gain , & rtP .
R2_Gain , & rtP . R3_Gain , & rtP . R4_Gain , & rtP . inti_UpperSat , & rtP .
inti_LowerSat , & rtP . itinit1_X0 , & rtP . Saturation_UpperSat , & rtP .
Saturation_LowerSat , & rtP . Saturation2_UpperSat , & rtP .
Saturation2_LowerSat , & rtP . Saturation3_UpperSat , & rtP .
Saturation3_LowerSat , & rtP . Switch_Threshold , & rtP . Switch1_Threshold ,
& rtP . Switch2_Threshold , & rtP . Switch3_Threshold , & rtP .
Switch4_Threshold , & rtP . Switch5_Threshold , & rtP . Switch6_Threshold , &
rtP . Currentfilter_A , & rtP . Currentfilter_C , & rtP . Currentfilter1_A ,
& rtP . Currentfilter1_C , & rtP . donotdeletethisgain_Gain_cnrap2hfmr , &
rtP . Constant_Value_irl5fvnkc1 , & rtP . Constant1_Value_nxh5i5seoh , & rtP
. Constant10_Value_lc4vxfnhde , & rtP . Constant11_Value_fwpcd5xjtn , & rtP .
Constant12_Value_ir3wdqdic4 , & rtP . Constant13_Value_mqbxzfv4z4 , & rtP .
Constant14_Value_badjrarjmp , & rtP . Constant15_Value_crqj5fw4c3 , & rtP .
Constant16_Value_idauo5rtab , & rtP . Constant2_Value_idziu2npmy , & rtP .
Constant3_Value_jbt5o32vyc , & rtP . Constant4_Value_hx5xprji3v , & rtP .
Constant5_Value_mdyfw3r2se , & rtP . Constant6_Value_kkiebpd3zp , & rtP .
Constant7_Value_fs50zyrehf , & rtP . Constant8_Value_kzavomyluf , & rtP .
Constant9_Value_e4pjobvupn , & rtP . Gain_Gain_f4berbk0ip , & rtP .
Gain2_Gain_b1lukokzr1 , & rtP . R_Gain_gmkimg2vno , & rtP .
R1_Gain_lxoje1sbcn , & rtP . R2_Gain_lmwx4sb00n , & rtP . R3_Gain_h2tjvli4op
, & rtP . R4_Gain_grw2mkmlr5 , & rtP . inti_UpperSat_m5funkuur3 , & rtP .
inti_LowerSat_hwyc0llog5 , & rtP . itinit1_X0_auy3ty1z4l , & rtP .
Saturation_UpperSat_mo1jv0phgx , & rtP . Saturation_LowerSat_dggvwabw03 , &
rtP . Saturation2_UpperSat_ppqdia3avp , & rtP .
Saturation2_LowerSat_jhnens0jar , & rtP . Saturation3_UpperSat_ntsul5erig , &
rtP . Saturation3_LowerSat_b5p1gj4cuc , & rtP . Switch_Threshold_c01jx1rxkb ,
& rtP . Switch1_Threshold_id0sltlw43 , & rtP . Switch2_Threshold_dcfkmijqkz ,
& rtP . Switch3_Threshold_dyzy5hn0uo , & rtP . Switch4_Threshold_laodusaory ,
& rtP . Switch5_Threshold_aipebitqdl , & rtP . Switch6_Threshold_jp4ffub4pb ,
& rtP . Currentfilter_A_cwwxbi13u0 , & rtP . Currentfilter_C_mskf05lo23 , &
rtP . Currentfilter1_A_a05epnrbo3 , & rtP . Currentfilter1_C_nx2vxymlgz , &
rtP . donotdeletethisgain_Gain_hql5qzrmqi , & rtP . Constant_Value_b2oae4kl4u
, & rtP . Constant1_Value_p0nk0e4k4t , & rtP . Constant10_Value_b4me2hmi3i ,
& rtP . Constant11_Value_k5i3bqlkzv , & rtP . Constant12_Value_ooh2hzd22c , &
rtP . Constant13_Value_bofm4evjtq , & rtP . Constant14_Value_mkv5pnyukp , &
rtP . Constant15_Value_ad54pn3wr2 , & rtP . Constant16_Value_cjh5ma2c3k , &
rtP . Constant2_Value_hvybrtqmxz , & rtP . Constant3_Value_n51n10aq0o , & rtP
. Constant4_Value_jum4bwpjax , & rtP . Constant5_Value_fafteqsipq , & rtP .
Constant6_Value_hd4fth2fjz , & rtP . Constant7_Value_ncodhoosuz , & rtP .
Constant8_Value_ojzmwgq5pn , & rtP . Constant9_Value_jc35dhdc3v , & rtP .
Gain_Gain_fvqpvk3pvf , & rtP . Gain2_Gain_oxevkaekqr , & rtP .
R_Gain_leocntiara , & rtP . R1_Gain_frm0s5nenw , & rtP . R2_Gain_bxxpczbi0a ,
& rtP . R3_Gain_bqq4aa4t3o , & rtP . R4_Gain_gi4xenlaa1 , & rtP .
inti_UpperSat_dal2xymi3h , & rtP . inti_LowerSat_plajszqohf , & rtP .
itinit1_X0_izz5uwg0q1 , & rtP . Saturation_UpperSat_mtqq4gsywh , & rtP .
Saturation_LowerSat_gwhczn143q , & rtP . Saturation2_UpperSat_kllm5hrnuw , &
rtP . Saturation2_LowerSat_lf1dgltu2n , & rtP .
Saturation3_UpperSat_matxumbq22 , & rtP . Saturation3_LowerSat_ikhjztqrap , &
rtP . Switch_Threshold_abfzybubnv , & rtP . Switch1_Threshold_mcownc3hf5 , &
rtP . Switch2_Threshold_l01luurl0n , & rtP . Switch3_Threshold_f11xead0ed , &
rtP . Switch4_Threshold_abb0upiodf , & rtP . Switch5_Threshold_gd4feiqqyu , &
rtP . Switch6_Threshold_htoqtnapgo , & rtP . Currentfilter_A_hpeprc3wrq , &
rtP . Currentfilter_C_ghxfrv2shu , & rtP . Currentfilter1_A_cqp1aqrh0k , &
rtP . Currentfilter1_C_o13iba3s0t , & rtP . StateSpace_P1_lgsdqm3bih [ 0 ] ,
& rtP . StateSpace_P2_lhxftost1h [ 0 ] , & rtP . StateSpace_P4_ah0hhhtenk [ 0
] , & rtP . StateSpace_P1 [ 0 ] , & rtP . StateSpace_P2 [ 0 ] , & rtP .
StateSpace_P4 [ 0 ] , & rtP . StateSpace_P1_gcbokynfeb [ 0 ] , & rtP .
StateSpace_P2_jtefz4j2hs [ 0 ] , & rtP . StateSpace_P4_jnl2tr4gcu [ 0 ] , &
rtP . Constant_Value_alteb1itig , & rtP . Constant_Value_ox3fg1go0h , & rtP .
Constant1_Value_ena3bvbnod , & rtP . Constant2_Value , & rtP .
Constant3_Value , & rtP . Constant4_Value_baux3n4syi , & rtP . Gain1_Gain , &
rtP . Gain4_Gain , & rtP . Gain_Gain_dwzn0ogzht , & rtP .
Gain_Gain_npmm5mmnhb , & rtP . TransferFcn1_A , & rtP . TransferFcn1_C , &
rtP . Constant_Value_ezg4nv1jai , & rtP . Constant_Value_i12rhgm4ll , & rtP .
Constant1_Value_a1rhrhkbfn , & rtP . Constant2_Value_a5vfpd3gf4 , & rtP .
Constant3_Value_cy3b2kpr1c , & rtP . Constant4_Value_nfrrjffypp , & rtP .
Gain1_Gain_fytmd1ajrp , & rtP . Gain4_Gain_l2e2nzph1g , & rtP .
Gain_Gain_mavdcgl3fv , & rtP . Gain_Gain_ocmxl2t2zp , & rtP .
TransferFcn1_A_a3pzcnto0r , & rtP . TransferFcn1_C_nct1hyfwyw , & rtP .
Constant_Value_o5texc1pzk , & rtP . Constant_Value_mscbjvxnfy , & rtP .
Constant1_Value_e3wa3mydbv , & rtP . Constant2_Value_fa544zy0zf , & rtP .
Constant3_Value_f2btqjtsos , & rtP . Constant4_Value_db1mnqkkob , & rtP .
Gain1_Gain_pji14mxcuf , & rtP . Gain4_Gain_bwxmd45ipv , & rtP .
Gain_Gain_ig2ewsw3sm , & rtP . Gain_Gain_k3wfy1rzcq , & rtP .
TransferFcn1_A_izgygp24sn , & rtP . TransferFcn1_C_omqc4vdzkc , & rtP .
Constant_Value_blwrb2w0qh , & rtP . Constant_Value_dn32sdoil4 , & rtP .
StateSpace_A , & rtP . StateSpace_B , & rtP . StateSpace_C , & rtP .
StateSpace_X0 , & rtP . Constant_Value_mexjddav50 , & rtP .
Constant_Value_ce0ilwr0v4 , & rtP . StateSpace_A_aeig1o2grk , & rtP .
StateSpace_B_ggzos4rhxs , & rtP . StateSpace_C_flmaxlhzmm , & rtP .
StateSpace_X0_fdo1l0da13 , & rtP . Constant_Value_fk15mpo45m , & rtP .
Constant_Value_cvgmtz023a , & rtP . StateSpace_A_lj2d3hqe0x , & rtP .
StateSpace_B_mjohccgfqz , & rtP . StateSpace_C_iee0yjqzes , & rtP .
StateSpace_X0_hyto3shui2 , } ; static int32_T * rtVarDimsAddrMap [ ] = { (
NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 } , {
"unsigned char" , "boolean_T" , 0 , 0 , sizeof ( boolean_T ) , SS_BOOLEAN , 0
, 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } , { rtwCAPI_VECTOR , 6 , 2 , 0 } , {
rtwCAPI_VECTOR , 8 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 10 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 12 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 14 , 2
, 0 } } ; static const uint_T rtDimensionArray [ ] = { 1 , 1 , 4 , 1 , 3600 ,
1 , 3 , 1 , 1 , 4 , 3 , 50 , 3 , 66 , 3 , 61 } ; static const real_T
rtcapiStoredFloats [ ] = { 0.0 , 1.0 } ; static const rtwCAPI_FixPtMap
rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , 0 }
, } ; static const rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const
void * ) & rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [
0 ] , 0 , 0 } , { ( const void * ) & rtcapiStoredFloats [ 0 ] , ( const void
* ) & rtcapiStoredFloats [ 1 ] , 1 , 0 } , { ( NULL ) , ( NULL ) , 2 , 0 } }
; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 197
, ( NULL ) , 0 , ( NULL ) , 0 } , { rtBlockParameters , 210 ,
rtModelParameters , 0 } , { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap
, rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float"
, { 562528118U , 4015142401U , 125993725U , 1970498346U } , ( NULL ) , 0 , 0
} ; const rtwCAPI_ModelMappingStaticInfo *
Load_Simulation_07_GetCAPIStaticMap ( ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void Load_Simulation_07_InitializeDataMapInfo ( ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void Load_Simulation_07_host_InitializeDataMapInfo (
Load_Simulation_07_host_DataMapInfo_T * dataMap , const char * path ) {
rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap ->
mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
