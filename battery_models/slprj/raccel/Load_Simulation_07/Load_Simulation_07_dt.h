#include "__cf_Load_Simulation_07.h"
#include "ext_types.h"
static uint_T rtDataTypeSizes [ ] = { sizeof ( real_T ) , sizeof ( real32_T )
, sizeof ( int8_T ) , sizeof ( uint8_T ) , sizeof ( int16_T ) , sizeof (
uint16_T ) , sizeof ( int32_T ) , sizeof ( uint32_T ) , sizeof ( boolean_T )
, sizeof ( fcn_call_T ) , sizeof ( int_T ) , sizeof ( pointer_T ) , sizeof (
action_T ) , 2 * sizeof ( uint32_T ) } ; static const char_T *
rtDataTypeNames [ ] = { "real_T" , "real32_T" , "int8_T" , "uint8_T" ,
"int16_T" , "uint16_T" , "int32_T" , "uint32_T" , "boolean_T" , "fcn_call_T"
, "int_T" , "pointer_T" , "action_T" , "timer_uint32_pair_T" } ; static
DataTypeTransition rtBTransitions [ ] = { { ( char_T * ) ( & rtB . jru2iqrfmm
) , 0 , 0 , 215 } , { ( char_T * ) ( & rtB . p3hqh0p1ve ) , 8 , 0 , 18 } , {
( char_T * ) ( & rtDW . jflxrokyki ) , 0 , 0 , 12 } , { ( char_T * ) ( & rtDW
. ixzxf22pdy . TimePtr ) , 11 , 0 , 77 } , { ( char_T * ) ( & rtDW .
nkl51yszn4 ) , 10 , 0 , 88 } , { ( char_T * ) ( & rtDW . e2bbi1copd ) , 8 , 0
, 30 } } ; static DataTypeTransitionTable rtBTransTable = { 6U ,
rtBTransitions } ; static DataTypeTransition rtPTransitions [ ] = { { (
char_T * ) ( & rtP . u2volts10AhLeadAcidbattery_BatType ) , 0 , 0 , 7975 } }
; static DataTypeTransitionTable rtPTransTable = { 1U , rtPTransitions } ;
