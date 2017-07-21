#include "__cf_Load_Simulation_07.h"
#include "rt_logging_mmi.h"
#include "Load_Simulation_07_capi.h"
#include <math.h>
#include "Load_Simulation_07.h"
#include "Load_Simulation_07_private.h"
#include "Load_Simulation_07_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; extern boolean_T
gblExtModeStartPktReceived ; void raccelForceExtModeShutdown ( ) { if ( !
gblExtModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 2 , & stopRequested ) ; }
rtExtModeShutdown ( 2 ) ; } const int_T gblNumToFiles = 0 ; const int_T
gblNumFrFiles = 0 ; const int_T gblNumFrWksBlocks = 1 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 3 ; const char_T
* gbl_raccel_Version = "8.9 (R2017a) 16-Feb-2017" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const char * gblSlvrJacPatternFileName =
"slprj\\raccel\\Load_Simulation_07\\Load_Simulation_07_Jpattern.mat" ; const
int_T gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
const int_T gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [
] = { - 1 } ; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ;
#include "simstruc.h"
#include "fixedpoint.h"
B rtB ; X rtX ; DW rtDW ; PrevZCX rtPrevZCX ; static SimStruct model_S ;
SimStruct * const rtS = & model_S ; static void lyko2lffkf ( const real_T n [
6 ] , real_T a [ 6 ] ) ; static void k5tlp010j4 ( const real_T x1 [ 2 ] ,
real_T b_y1 [ 6 ] ) ; static void lyko2lffkf ( const real_T n [ 6 ] , real_T
a [ 6 ] ) { real_T nmax [ 2 ] ; real_T numerator [ 6 ] ; int32_T ak ; int32_T
bk ; int32_T ck ; real_T s ; boolean_T exitg1 ; ck = 1 ; s = n [ 0 ] ; if (
muDoubleScalarIsNaN ( n [ 0 ] ) ) { ak = 2 ; exitg1 = false ; while ( ( !
exitg1 ) && ( ak <= 3 ) ) { ck = ak ; if ( ! muDoubleScalarIsNaN ( n [ ak - 1
] ) ) { s = n [ ak - 1 ] ; exitg1 = true ; } else { ak ++ ; } } } if ( ck < 3
) { while ( ck + 1 <= 3 ) { if ( n [ ck ] > s ) { s = n [ ck ] ; } ck ++ ; }
} nmax [ 0 ] = s ; ck = 4 ; s = n [ 3 ] ; if ( muDoubleScalarIsNaN ( n [ 3 ]
) ) { ak = 5 ; exitg1 = false ; while ( ( ! exitg1 ) && ( ak <= 6 ) ) { ck =
ak ; if ( ! muDoubleScalarIsNaN ( n [ ak - 1 ] ) ) { s = n [ ak - 1 ] ;
exitg1 = true ; } else { ak ++ ; } } } if ( ck < 6 ) { while ( ck + 1 <= 6 )
{ if ( n [ ck ] > s ) { s = n [ ck ] ; } ck ++ ; } } nmax [ 1 ] = s ; ak = 0
; bk = 0 ; for ( ck = 0 ; ck <= 4 ; ck += 3 ) { numerator [ ck ] = n [ ak ] -
nmax [ bk ] ; numerator [ ck + 1 ] = n [ ak + 1 ] - nmax [ bk ] ; numerator [
ck + 2 ] = n [ ak + 2 ] - nmax [ bk ] ; ak += 3 ; bk ++ ; } for ( ak = 0 ; ak
< 6 ; ak ++ ) { numerator [ ak ] = muDoubleScalarExp ( numerator [ ak ] ) ; }
nmax [ 0 ] = ( numerator [ 0 ] + numerator [ 1 ] ) + numerator [ 2 ] ; s = (
numerator [ 3 ] + numerator [ 4 ] ) + numerator [ 5 ] ; nmax [ 1 ] = s ; if (
nmax [ 0 ] == 0.0 ) { nmax [ 0 ] = 1.0 ; } if ( s == 0.0 ) { nmax [ 1 ] = 1.0
; } ak = 0 ; bk = 0 ; for ( ck = 0 ; ck <= 4 ; ck += 3 ) { a [ ck ] =
numerator [ ak ] / nmax [ bk ] ; a [ ck + 1 ] = numerator [ ak + 1 ] / nmax [
bk ] ; a [ ck + 2 ] = numerator [ ak + 2 ] / nmax [ bk ] ; ak += 3 ; bk ++ ;
} } static void k5tlp010j4 ( const real_T x1 [ 2 ] , real_T b_y1 [ 6 ] ) {
real_T xp1 [ 4 ] ; int32_T ak ; real_T b [ 20 ] ; real_T x [ 20 ] ; real_T
b_b [ 6 ] ; int32_T b_ibtile ; static const real_T b_a [ 10 ] = { -
4.97239710897462 , - 6.04253284762122 , 3.9828303904197644 ,
6.6263980582286459 , 2.7922373881878837 , 1.9550854467195964 ,
3.4486842604544594 , 2.2359633679077939 , - 3.0157630388703396 ,
4.1955206334339321 } ; static const real_T d_a [ 30 ] = { 5.9867391203891342
, - 5.0176867348666576 , 0.22282166819283239 , 6.2715675516586105 , -
0.374784133547278 , - 5.6065206221154007 , - 2.2958368196439167 ,
4.14768533390324 , - 2.3568094829260815 , - 9.1872282145571376 ,
11.830364524780684 , - 3.0189523626924943 , - 4.7442808362480378 ,
7.9142305602239684 , - 3.2182644447691025 , 5.0897449843356206 , -
3.5645718480025264 , - 1.844338370281968 , - 2.5755515788481471 ,
3.109731195958839 , 0.0013248351134321117 , 2.6724182879657943 , -
2.4926646081806871 , 0.32575890209747 , - 1.6872797571269791 ,
3.6104838517823961 , - 1.1404537539262503 , 2.0969944826650964 , -
3.4978478970131643 , - 0.20389448774230298 } ; static const real_T e_a [ 20 ]
= { 7.718129574740777 , 1.014037430327323 , - 4.3948891985021579 , -
13.458187944358141 , 0.49624115912686872 , 3.7426380970950111 ,
4.0573224304125661 , 2.6820500291932743 , - 2.2235090817492269 ,
2.4550667942010991 , 1.2278390640458778 , - 6.7788500299566952 , -
3.4017167798718955 , 3.3241074128344725 , 5.1999656431008487 , -
4.8974971128408544 , - 0.69083048926580792 , - 4.3890872138609529 ,
4.8072889108358865 , - 3.8205720181833911 } ; real_T b_b_p [ 6 ] ; real_T b_p
[ 20 ] ; int32_T i ; real_T tmp ; xp1 [ 0 ] = ( x1 [ 0 ] - -
4.88498130835069E-15 ) * 0.135281194245916 ; xp1 [ 1 ] = x1 [ 0 ] * 0.02 ;
xp1 [ 2 ] = ( x1 [ 1 ] - - 4.88498130835069E-15 ) * 0.135281194245916 ; xp1 [
0 ] += - 1.0 ; xp1 [ 1 ] += - 1.0 ; xp1 [ 2 ] += - 1.0 ; xp1 [ 3 ] = x1 [ 1 ]
* 0.02 + - 1.0 ; for ( ak = 0 ; ak < 2 ; ak ++ ) { b_ibtile = ak * 10 ;
memcpy ( & b [ b_ibtile ] , & b_a [ 0 ] , 10U * sizeof ( real_T ) ) ; } for (
b_ibtile = 0 ; b_ibtile < 2 ; b_ibtile ++ ) { for ( ak = 0 ; ak < 10 ; ak ++
) { b_p [ ak + 10 * b_ibtile ] = ( xp1 [ ( b_ibtile << 1 ) + 1 ] * e_a [ ak +
10 ] + xp1 [ b_ibtile << 1 ] * e_a [ ak ] ) + b [ 10 * b_ibtile + ak ] ; } }
for ( b_ibtile = 0 ; b_ibtile < 2 ; b_ibtile ++ ) { for ( ak = 0 ; ak < 10 ;
ak ++ ) { x [ ak + 10 * b_ibtile ] = b_p [ 10 * b_ibtile + ak ] * - 2.0 ; } }
for ( ak = 0 ; ak < 20 ; ak ++ ) { x [ ak ] = muDoubleScalarExp ( x [ ak ] )
; } for ( ak = 0 ; ak < 2 ; ak ++ ) { b_ibtile = ak * 3 ; b_b [ b_ibtile ] =
1.9923809508773795 ; b_b [ b_ibtile + 1 ] = - 2.0492753903382268 ; b_b [
b_ibtile + 2 ] = 1.5448453741298611 ; for ( b_ibtile = 0 ; b_ibtile < 10 ;
b_ibtile ++ ) { b [ b_ibtile + 10 * ak ] = 2.0 / ( x [ 10 * ak + b_ibtile ] +
1.0 ) - 1.0 ; } } for ( b_ibtile = 0 ; b_ibtile < 2 ; b_ibtile ++ ) { for (
ak = 0 ; ak < 3 ; ak ++ ) { tmp = 0.0 ; for ( i = 0 ; i < 10 ; i ++ ) { tmp
+= d_a [ 3 * i + ak ] * b [ 10 * b_ibtile + i ] ; } b_b_p [ ak + 3 * b_ibtile
] = b_b [ 3 * b_ibtile + ak ] + tmp ; } } lyko2lffkf ( b_b_p , b_y1 ) ; }
void MdlInitialize ( void ) { rtDW . jflxrokyki = rtP . itinit1_X0 ; rtX .
awyk3jkmpp = 0.0 ; rtDW . gkgewmrthj = ( 1.0 - rtP .
u2volts10AhLeadAcidbattery_SOC / 100.0 ) * 11.562499999999885 /
1.109999999999989 * 3600.0 ; if ( ssIsFirstInitCond ( rtS ) ) { rtX .
geiqvotdgd = 0.0 ; } rtDW . nkl51yszn4 = 1 ; rtX . gjrr5rcl1i = rtP .
StateSpace_X0 ; rtX . emndqevlhi = muDoubleScalarExp ( ( 1.0 - rtP .
u2volts10AhLeadAcidbattery_SOC / 100.0 ) * - 90.0 * 11.562499999999885 ) *
0.8164542838428952 ; rtX . oobd5yyumt = 0.0 ; { SimStruct * rts =
ssGetSFunction ( rtS , 0 ) ; sfcnInitializeConditions ( rts ) ; if (
ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } rtDW . byrrqwbwuv = rtP .
itinit1_X0_izz5uwg0q1 ; rtX . gqep4i1he1 = 0.0 ; rtDW . ko2pp0cfqy = ( 1.0 -
rtP . u2v10AhLiFePO4_SOC / 100.0 ) * 10.339999999999973 / 1.0339999999999974
* 3600.0 ; if ( ssIsFirstInitCond ( rtS ) ) { rtX . lr2fon2uwe = 0.0 ; } rtDW
. fyfdvnwnzj = 1 ; rtX . plzaosk005 = rtP . StateSpace_X0_hyto3shui2 ; rtX .
femnmi0kft = muDoubleScalarExp ( ( 1.0 - rtP . u2v10AhLiFePO4_SOC / 100.0 ) *
- 6.1061990132382391 * 10.339999999999973 ) * 1.0263398315053873 ; rtX .
czasr4omxo = 0.0 ; { SimStruct * rts = ssGetSFunction ( rtS , 1 ) ;
sfcnInitializeConditions ( rts ) ; if ( ssGetErrorStatus ( rts ) != ( NULL )
) return ; } rtDW . knyijtosqg = rtP . itinit1_X0_auy3ty1z4l ; rtX .
cdhjf34fys = 0.0 ; rtDW . ft2nyeqcg1 = ( 1.0 - rtP .
u2volts10AhNiMHbattery_SOC / 100.0 ) * 11.221538461538424 /
1.0419999999999965 * 3600.0 ; if ( ssIsFirstInitCond ( rtS ) ) { rtX .
fgmli1n2fu = 0.0 ; } rtDW . gxhjb1iyjf = 1 ; rtX . drcq2lkoq2 = rtP .
StateSpace_X0_fdo1l0da13 ; rtX . cw5koqcmmd = muDoubleScalarExp ( ( 1.0 - rtP
. u2volts10AhNiMHbattery_SOC / 100.0 ) * - 1.5 * 11.221538461538424 ) *
1.1126870203198884 ; rtX . jaymf1z1oc = 0.0 ; { SimStruct * rts =
ssGetSFunction ( rtS , 2 ) ; sfcnInitializeConditions ( rts ) ; if (
ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } rtX . mlhiasidwv = 0.0 ;
rtX . lvhyb51zfr = 0.0 ; rtX . ic4xkivobu = 0.0 ; } void MdlStart ( void ) {
{ void * * slioCatalogueAddr = rt_slioCatalogueAddr ( ) ; void * r2 = ( NULL
) ; void * * pOSigstreamManagerAddr = ( NULL ) ; const char *
errorCreatingOSigstreamManager = ( NULL ) ; const char *
errorAddingR2SharedResource = ( NULL ) ; * slioCatalogueAddr =
rtwGetNewSlioCatalogue ( rt_GetMatSigLogSelectorFileName ( ) ) ;
errorAddingR2SharedResource = rtwAddR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) , 1 ) ; if (
errorAddingR2SharedResource != ( NULL ) ) { rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = ( NULL ) ; ssSetErrorStatus ( rtS
, errorAddingR2SharedResource ) ; return ; } r2 = rtwGetR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ) ;
pOSigstreamManagerAddr = rt_GetOSigstreamManagerAddr ( ) ;
errorCreatingOSigstreamManager = rtwOSigstreamManagerCreateInstance (
rt_GetMatSigLogSelectorFileName ( ) , r2 , pOSigstreamManagerAddr ) ; if (
errorCreatingOSigstreamManager != ( NULL ) ) { * pOSigstreamManagerAddr = (
NULL ) ; ssSetErrorStatus ( rtS , errorCreatingOSigstreamManager ) ; return ;
} } { FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1
, sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "LoadCurrent_Signal" ; fromwksInfo ->
origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo ->
origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo
-> data = ( void * ) rtP . FromWorkspace_Data0 ; fromwksInfo -> nDataPoints =
3600 ; fromwksInfo -> time = ( double * ) rtP . FromWorkspace_Time0 ; rtDW .
ixzxf22pdy . TimePtr = fromwksInfo -> time ; rtDW . ixzxf22pdy . DataPtr =
fromwksInfo -> data ; rtDW . ixzxf22pdy . RSimInfoPtr = fromwksInfo ; } rtDW
. j4pqvee5xt . PrevIndex = 0 ; } { SimStruct * rts = ssGetSFunction ( rtS , 0
) ; sfcnStart ( rts ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ;
} { RTWLogSignalInfo rt_ScopeSignalInfo ; static int_T rt_ScopeSignalWidths [
] = { 1 , 1 , 1 } ; static int_T rt_ScopeSignalNumDimensions [ ] = { 1 , 1 ,
1 } ; static int_T rt_ScopeSignalDimensions [ ] = { 1 , 1 , 1 } ; static void
* rt_ScopeCurrSigDims [ ] = { ( NULL ) , ( NULL ) , ( NULL ) } ; static int_T
rt_ScopeCurrSigDimsSize [ ] = { 4 , 4 , 4 } ; static const char_T *
rt_ScopeSignalLabels [ ] = { "<Voltage (V)>" , "<SOC (%)>" , "<Current (A)>"
} ; static char_T rt_ScopeSignalTitles [ ] =
"<Voltage (V)><SOC (%)><Current (A)>" ; static int_T
rt_ScopeSignalTitleLengths [ ] = { 13 , 9 , 13 } ; static boolean_T
rt_ScopeSignalIsVarDims [ ] = { 0 , 0 , 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 0 , 0 , 0 } ; BuiltInDTypeId dTypes [ 3 ] =
{ SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
"Load_Simulation_07/LeadAcid" ; static int_T rt_ScopeFrameData [ ] = { 0 , 0
, 0 } ; rt_ScopeSignalInfo . numSignals = 3 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . labels . cptr =
rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles = rt_ScopeSignalTitles ;
rt_ScopeSignalInfo . titleLengths = rt_ScopeSignalTitleLengths ;
rt_ScopeSignalInfo . plotStyles = rt_ScopeSignalPlotStyles ;
rt_ScopeSignalInfo . blockNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo . crossMdlRef = ( NULL ) ;
rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ; rtDW . ifo13hvcar .
LoggedData [ 0 ] = rt_CreateStructLogVar ( ssGetRTWLogInfo ( rtS ) ,
ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS
) ) , "ScopeData2" , 1 , 0 , 1 , 0.0 , & rt_ScopeSignalInfo ,
rt_ScopeBlockName ) ; if ( rtDW . ifo13hvcar . LoggedData [ 0 ] == ( NULL ) )
return ; } { SimStruct * rts = ssGetSFunction ( rtS , 1 ) ; sfcnStart ( rts )
; if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } { RTWLogSignalInfo
rt_ScopeSignalInfo ; static int_T rt_ScopeSignalWidths [ ] = { 1 , 1 , 1 } ;
static int_T rt_ScopeSignalNumDimensions [ ] = { 1 , 1 , 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 1 , 1 , 1 } ; static void *
rt_ScopeCurrSigDims [ ] = { ( NULL ) , ( NULL ) , ( NULL ) } ; static int_T
rt_ScopeCurrSigDimsSize [ ] = { 4 , 4 , 4 } ; static const char_T *
rt_ScopeSignalLabels [ ] = { "<Voltage (V)>" , "<SOC (%)>" , "<Current (A)>"
} ; static char_T rt_ScopeSignalTitles [ ] =
"<Voltage (V)><SOC (%)><Current (A)>" ; static int_T
rt_ScopeSignalTitleLengths [ ] = { 13 , 9 , 13 } ; static boolean_T
rt_ScopeSignalIsVarDims [ ] = { 0 , 0 , 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 0 , 0 , 0 } ; BuiltInDTypeId dTypes [ 3 ] =
{ SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
"Load_Simulation_07/LiFeMgPO4" ; static int_T rt_ScopeFrameData [ ] = { 0 , 0
, 0 } ; rt_ScopeSignalInfo . numSignals = 3 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . labels . cptr =
rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles = rt_ScopeSignalTitles ;
rt_ScopeSignalInfo . titleLengths = rt_ScopeSignalTitleLengths ;
rt_ScopeSignalInfo . plotStyles = rt_ScopeSignalPlotStyles ;
rt_ScopeSignalInfo . blockNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo . crossMdlRef = ( NULL ) ;
rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ; rtDW . dyo1jajuwp .
LoggedData [ 0 ] = rt_CreateStructLogVar ( ssGetRTWLogInfo ( rtS ) ,
ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS
) ) , "ScopeData4" , 1 , 0 , 1 , 0.0 , & rt_ScopeSignalInfo ,
rt_ScopeBlockName ) ; if ( rtDW . dyo1jajuwp . LoggedData [ 0 ] == ( NULL ) )
return ; } { SimStruct * rts = ssGetSFunction ( rtS , 2 ) ; sfcnStart ( rts )
; if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } { RTWLogSignalInfo
rt_ScopeSignalInfo ; static int_T rt_ScopeSignalWidths [ ] = { 1 , 1 , 1 } ;
static int_T rt_ScopeSignalNumDimensions [ ] = { 1 , 1 , 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 1 , 1 , 1 } ; static void *
rt_ScopeCurrSigDims [ ] = { ( NULL ) , ( NULL ) , ( NULL ) } ; static int_T
rt_ScopeCurrSigDimsSize [ ] = { 4 , 4 , 4 } ; static const char_T *
rt_ScopeSignalLabels [ ] = { "<Voltage (V)>" , "<SOC (%)>" , "<Current (A)>"
} ; static char_T rt_ScopeSignalTitles [ ] =
"<Voltage (V)><SOC (%)><Current (A)>" ; static int_T
rt_ScopeSignalTitleLengths [ ] = { 13 , 9 , 13 } ; static boolean_T
rt_ScopeSignalIsVarDims [ ] = { 0 , 0 , 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 0 , 0 , 0 } ; BuiltInDTypeId dTypes [ 3 ] =
{ SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
"Load_Simulation_07/NiMH" ; static int_T rt_ScopeFrameData [ ] = { 0 , 0 , 0
} ; rt_ScopeSignalInfo . numSignals = 3 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . labels . cptr =
rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles = rt_ScopeSignalTitles ;
rt_ScopeSignalInfo . titleLengths = rt_ScopeSignalTitleLengths ;
rt_ScopeSignalInfo . plotStyles = rt_ScopeSignalPlotStyles ;
rt_ScopeSignalInfo . blockNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo . crossMdlRef = ( NULL ) ;
rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ; rtDW . chubbvu0th .
LoggedData [ 0 ] = rt_CreateStructLogVar ( ssGetRTWLogInfo ( rtS ) ,
ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS
) ) , "ScopeData1" , 1 , 0 , 1 , 0.0 , & rt_ScopeSignalInfo ,
rt_ScopeBlockName ) ; if ( rtDW . chubbvu0th . LoggedData [ 0 ] == ( NULL ) )
return ; } MdlInitialize ( ) ; { bool externalInputIsInDatasetFormat = false
; void * pISigstreamManager = rt_GetISigstreamManager ( ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} } void MdlOutputs ( int_T tid ) { boolean_T resetIntg ; ZCEventType zcEvent
; real_T x [ 6 ] ; real_T y [ 3 ] ; real_T mtmp ; int32_T itmp ; int32_T
ixstart ; int32_T ix ; real_T tmp ; real_T tmp_p [ 2 ] ; real_T tmp_e [ 6 ] ;
boolean_T exitg1 ; rtB . mo0fhfwjbn = 0.0 ; rtB . mo0fhfwjbn += rtP .
Currentfilter_C * rtX . awyk3jkmpp ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
rtB . gu5rsica4y = rtDW . jflxrokyki ; rtB . eafza0ignh = rtP . R2_Gain * rtB
. gu5rsica4y ; if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . e2bbi1copd = ( rtB .
mo0fhfwjbn > rtP . Constant_Value_alteb1itig ) ; } rtB . hbrgffmmwb = rtDW .
e2bbi1copd ; rtB . ffdlej0esm = rtDW . gkgewmrthj ; } if ( ssIsMajorTimeStep
( rtS ) ) { resetIntg = false ; zcEvent = rt_ZCFcn ( RISING_ZERO_CROSSING , &
rtPrevZCX . oz2emx0tx4 , ( rtB . hbrgffmmwb ) ) ; if ( ( zcEvent !=
NO_ZCEVENT ) || ( rtDW . nkl51yszn4 != 0 ) ) { resetIntg = true ; rtX .
geiqvotdgd = rtB . ffdlej0esm ; } if ( resetIntg ) { ssSetSolverNeedsReset (
rtS ) ; } if ( rtX . geiqvotdgd >= rtP . inti_UpperSat ) { rtX . geiqvotdgd =
rtP . inti_UpperSat ; } else { if ( rtX . geiqvotdgd <= rtP . inti_LowerSat )
{ rtX . geiqvotdgd = rtP . inti_LowerSat ; } } } rtB . iu235cbed5 = rtX .
geiqvotdgd ; rtB . jm35sgpar2 = rtP . Gain_Gain * rtB . iu235cbed5 ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ssIsMajorTimeStep ( rtS ) ) { rtDW .
aroxcxqsxi = ( rtB . jm35sgpar2 > rtB . eafza0ignh ) ; rtDW . cgagzvjehp = (
rtB . jm35sgpar2 < rtP . Constant9_Value ) ; } rtB . p3hqh0p1ve = rtDW .
aroxcxqsxi ; rtB . gibfnm5yif = rtDW . cgagzvjehp ; } if ( rtB . p3hqh0p1ve )
{ rtB . o4aync4hqi = rtB . eafza0ignh ; } else { if ( rtB . gibfnm5yif ) {
rtB . gucbgg34uu = rtP . Constant9_Value ; } else { rtB . gucbgg34uu = rtB .
jm35sgpar2 ; } rtB . o4aync4hqi = rtB . gucbgg34uu ; } rtB . a4eiiet2o0 = 0.0
; rtB . a4eiiet2o0 += rtP . StateSpace_C * rtX . gjrr5rcl1i ; if ( rtP .
Constant5_Value > rtP . Switch_Threshold ) { rtB . p4h4wunzca =
muDoubleScalarExp ( ( 1.0 / rtB . a4eiiet2o0 - 0.0033540164346805303 ) * 0.0
) ; } else { rtB . p4h4wunzca = rtP . Constant4_Value ; } rtB . lpwludxfnb =
- 0.035738607275251556 * rtB . gu5rsica4y / ( rtB . gu5rsica4y - rtB .
o4aync4hqi ) * rtB . o4aync4hqi * rtB . p4h4wunzca ; rtB . pmxqn1j2n3 = - rtB
. hbrgffmmwb * 0.035738607275251556 * rtB . mo0fhfwjbn * rtB . gu5rsica4y / (
rtB . gu5rsica4y - rtB . o4aync4hqi ) * rtB . p4h4wunzca ; if ( ssIsSampleHit
( rtS , 1 , 0 ) ) { rtB . mfjtrcfybp = rtP . R3_Gain * rtB . gu5rsica4y ; if
( ssIsMajorTimeStep ( rtS ) ) { rtDW . nsqv1bhvah = ( rtB . jm35sgpar2 > rtB
. mfjtrcfybp ) ; } rtB . h5yixci3b5 = rtDW . nsqv1bhvah ; rtB . djwy2mdgcr =
- rtB . mfjtrcfybp * 0.999 * 0.1 * 0.9999 ; if ( ssIsMajorTimeStep ( rtS ) )
{ rtDW . oajahukjrq = ( rtB . jm35sgpar2 < rtB . djwy2mdgcr ) ; } rtB .
iu45wsrpul = rtDW . oajahukjrq ; if ( ssIsMajorTimeStep ( rtS ) ) { rtDW .
jq3tf3x1xs = ( rtB . mo0fhfwjbn < rtP . Constant_Value_ox3fg1go0h ) ; } rtB .
ksvnvluruk = rtDW . jq3tf3x1xs ; } if ( rtB . h5yixci3b5 ) { rtB . bn5kz230z1
= rtB . mfjtrcfybp ; } else { if ( rtB . iu45wsrpul ) { rtB . chxlnefiu2 =
rtB . djwy2mdgcr ; } else { rtB . chxlnefiu2 = rtB . jm35sgpar2 ; } rtB .
bn5kz230z1 = rtB . chxlnefiu2 ; } switch ( ( int32_T ) rtP .
u2volts10AhLeadAcidbattery_BatType ) { case 1 : rtB . gayccjz0g2 [ 0 ] = rtP
. Constant4_Value_baux3n4syi * rtB . bn5kz230z1 ; rtB . gayccjz0g2 [ 1 ] =
rtP . Constant4_Value_baux3n4syi * rtB . mo0fhfwjbn ; rtB . gayccjz0g2 [ 2 ]
= rtP . Constant4_Value_baux3n4syi * rtB . ksvnvluruk ; rtB . gayccjz0g2 [ 3
] = rtP . Constant4_Value_baux3n4syi * rtB . gu5rsica4y ; rtB . b4dvnbx2z0 =
- rtB . gayccjz0g2 [ 2 ] * 0.035738607275251556 * rtB . gayccjz0g2 [ 1 ] * (
11.562499999999885 / ( rtB . gayccjz0g2 [ 0 ] + 1.1562499999999885 ) ) ;
break ; case 2 : rtB . cgcsvraqod [ 0 ] = rtP . Constant1_Value_ena3bvbnod *
rtB . bn5kz230z1 ; rtB . cgcsvraqod [ 1 ] = rtP . Constant1_Value_ena3bvbnod
* rtB . mo0fhfwjbn ; rtB . cgcsvraqod [ 2 ] = rtP .
Constant1_Value_ena3bvbnod * rtB . ksvnvluruk ; rtB . cgcsvraqod [ 3 ] = rtP
. Constant1_Value_ena3bvbnod * rtB . gu5rsica4y ; rtB . b4dvnbx2z0 = - rtB .
cgcsvraqod [ 2 ] * 0.035738607275251556 * rtB . cgcsvraqod [ 1 ] * rtB .
cgcsvraqod [ 3 ] / ( rtB . cgcsvraqod [ 3 ] * 0.1 + rtB . cgcsvraqod [ 0 ] )
; break ; case 3 : rtB . amabyxe2q5 [ 0 ] = rtP . Constant3_Value * rtB .
bn5kz230z1 ; rtB . amabyxe2q5 [ 1 ] = rtP . Constant3_Value * rtB .
mo0fhfwjbn ; rtB . amabyxe2q5 [ 2 ] = rtP . Constant3_Value * rtB .
ksvnvluruk ; rtB . amabyxe2q5 [ 3 ] = rtP . Constant3_Value * rtB .
gu5rsica4y ; rtB . b4dvnbx2z0 = - rtB . amabyxe2q5 [ 2 ] *
0.035738607275251556 * rtB . amabyxe2q5 [ 1 ] * ( 11.562499999999885 / (
muDoubleScalarAbs ( rtB . amabyxe2q5 [ 0 ] ) + 1.1562499999999885 ) ) ; break
; default : rtB . hp4pbsppeu [ 0 ] = rtP . Constant2_Value * rtB . bn5kz230z1
; rtB . hp4pbsppeu [ 1 ] = rtP . Constant2_Value * rtB . mo0fhfwjbn ; rtB .
hp4pbsppeu [ 2 ] = rtP . Constant2_Value * rtB . ksvnvluruk ; rtB .
hp4pbsppeu [ 3 ] = rtP . Constant2_Value * rtB . gu5rsica4y ; rtB .
b4dvnbx2z0 = - rtB . hp4pbsppeu [ 2 ] * 0.035738607275251556 * rtB .
hp4pbsppeu [ 1 ] * ( 11.562499999999885 / ( muDoubleScalarAbs ( rtB .
hp4pbsppeu [ 0 ] ) + 1.1562499999999885 ) ) ; break ; } rtB . losq44zfsw =
rtB . b4dvnbx2z0 * rtB . p4h4wunzca ; rtB . ia1kg5fvtb = rtX . emndqevlhi ;
switch ( ( int32_T ) rtP . u2volts10AhLeadAcidbattery_BatType ) { case 1 :
rtB . on5jb3go3s = rtB . ia1kg5fvtb ; break ; case 2 : rtB . on5jb3go3s =
muDoubleScalarExp ( - 90.0 * rtB . o4aync4hqi ) * 0.8164542838428952 ; break
; case 3 : rtB . on5jb3go3s = rtB . ia1kg5fvtb ; break ; default : rtB .
on5jb3go3s = rtB . ia1kg5fvtb ; break ; } rtB . cb1nnepflz = 0.0 ; rtB .
cb1nnepflz += rtP . Currentfilter1_C * rtX . oobd5yyumt ; if ( rtP .
Constant7_Value > rtP . Switch2_Threshold ) { rtB . msdjbx4ftv =
muDoubleScalarExp ( ( 1.0 / rtB . a4eiiet2o0 - 0.0033540164346805303 ) * 0.0
) * - rtB . fgkxbpykg1 * rtB . cb1nnepflz + 0.012 * rtB . cb1nnepflz ; } else
{ rtB . msdjbx4ftv = rtP . Constant6_Value ; } rtB . kypwxy50kw = ( ( ( ( rtB
. lpwludxfnb + rtB . pmxqn1j2n3 ) + rtB . losq44zfsw ) + rtB . on5jb3go3s ) +
- 0.0 * rtB . o4aync4hqi ) + rtB . msdjbx4ftv ; if ( rtP .
Constant3_Value_iqsu23z4ce > rtP . Switch1_Threshold ) { rtB . bb25sco2fm = (
rtB . a4eiiet2o0 - 298.15 ) * 0.0 ; } else { rtB . bb25sco2fm = rtP .
Constant2_Value_cdqfgwpsti ; } rtB . abmbri4rct = ( rtB . jru2iqrfmm + rtB .
kypwxy50kw ) + rtB . bb25sco2fm ; rtB . gi1zeejtvl = rtP . R1_Gain * rtB .
mo0fhfwjbn ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ssIsMajorTimeStep (
rtS ) ) { rtDW . hvbgl0hgfc = ( rtB . abmbri4rct > rtP . Constant1_Value ) ;
} rtB . l5k4v4pkri = rtDW . hvbgl0hgfc ; if ( ssIsMajorTimeStep ( rtS ) ) {
rtDW . dvabjhaxc1 = ( rtB . abmbri4rct < rtB . gi1zeejtvl ) ; } rtB .
bbvpjaqjcj = rtDW . dvabjhaxc1 ; } if ( rtB . l5k4v4pkri ) { rtB . brqcacx4dy
= rtP . Constant1_Value ; } else { if ( rtB . bbvpjaqjcj ) { rtB . jl0as1i1kv
= rtB . gi1zeejtvl ; } else { rtB . jl0as1i1kv = rtB . abmbri4rct ; } rtB .
brqcacx4dy = rtB . jl0as1i1kv ; } { real_T * pDataValues = ( real_T * ) rtDW
. ixzxf22pdy . DataPtr ; real_T * pTimeValues = ( real_T * ) rtDW .
ixzxf22pdy . TimePtr ; int_T currTimeIndex = rtDW . j4pqvee5xt . PrevIndex ;
real_T t = ssGetTaskTime ( rtS , 0 ) ; int numPoints , lastPoint ; FWksInfo *
fromwksInfo = ( FWksInfo * ) rtDW . ixzxf22pdy . RSimInfoPtr ; numPoints =
fromwksInfo -> nDataPoints ; lastPoint = numPoints - 1 ; if ( t <=
pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else if ( t >= pTimeValues [
lastPoint ] ) { currTimeIndex = lastPoint - 1 ; } else { if ( t < pTimeValues
[ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ] ) {
currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex + 1 ]
) { currTimeIndex ++ ; } } } rtDW . j4pqvee5xt . PrevIndex = currTimeIndex ;
{ real_T t1 = pTimeValues [ currTimeIndex ] ; real_T t2 = pTimeValues [
currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1 ) { rtB . mzsf40mopc =
pDataValues [ currTimeIndex ] ; } else { rtB . mzsf40mopc = pDataValues [
currTimeIndex + 1 ] ; } } else { real_T f1 = ( t2 - t ) / ( t2 - t1 ) ;
real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex =
currTimeIndex ; d1 = pDataValues [ TimeIndex ] ; d2 = pDataValues [ TimeIndex
+ 1 ] ; rtB . mzsf40mopc = ( real_T ) rtInterpolate ( d1 , d2 , f1 , f2 ) ;
pDataValues += numPoints ; } } } { SimStruct * rts = ssGetSFunction ( rtS , 0
) ; sfcnOutputs ( rts , 0 ) ; } rtB . ml5sunf4wl = rtP .
donotdeletethisgain_Gain * rtB . ltqlujcfbs ; rtB . kgwpzskznu = rtB .
brqcacx4dy - rtP . R_Gain * rtB . ml5sunf4wl ; if ( ssIsSampleHit ( rtS , 1 ,
0 ) ) { rtB . cu3rpzq1ir = rtP . R4_Gain * rtB . gu5rsica4y ; } rtB .
ebzvvcw0uj = ( 1.0 - rtB . o4aync4hqi / rtB . cu3rpzq1ir ) * 100.0 ; if (
ssIsMajorTimeStep ( rtS ) ) { rtDW . ezytuzrwcm = rtB . ebzvvcw0uj >= rtP .
Saturation_UpperSat ? 1 : rtB . ebzvvcw0uj > rtP . Saturation_LowerSat ? 0 :
- 1 ; } rtB . nvl5qjckkv = rtDW . ezytuzrwcm == 1 ? rtP . Saturation_UpperSat
: rtDW . ezytuzrwcm == - 1 ? rtP . Saturation_LowerSat : rtB . ebzvvcw0uj ;
if ( ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW
. ifo13hvcar . LoggedData [ 0 ] ; LogVar * var = svar -> signals . values ; {
double locTime = ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * )
svar -> time , & locTime , 0 ) ; } { real_T up0 [ 1 ] ; up0 [ 0 ] = rtB .
kgwpzskznu ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; var = var ->
next ; } { real_T up1 [ 1 ] ; up1 [ 0 ] = rtB . nvl5qjckkv ; rt_UpdateLogVar
( ( LogVar * ) var , up1 , 0 ) ; var = var -> next ; } { real_T up2 [ 1 ] ;
up2 [ 0 ] = rtB . ml5sunf4wl ; rt_UpdateLogVar ( ( LogVar * ) var , up2 , 0 )
; } } rtB . kcia4oomek = 0.0 ; rtB . kcia4oomek += rtP .
Currentfilter_C_ghxfrv2shu * rtX . gqep4i1he1 ; if ( ssIsSampleHit ( rtS , 1
, 0 ) ) { rtB . ded05j4tle = rtDW . byrrqwbwuv ; rtB . kjbniesfcu = rtP .
R2_Gain_bxxpczbi0a * rtB . ded05j4tle ; if ( ssIsMajorTimeStep ( rtS ) ) {
rtDW . i3xk5pcc1t = ( rtB . kcia4oomek > rtP . Constant_Value_o5texc1pzk ) ;
} rtB . f3yztw02af = rtDW . i3xk5pcc1t ; rtB . ebadym5xni = rtDW . ko2pp0cfqy
; } if ( ssIsMajorTimeStep ( rtS ) ) { resetIntg = false ; zcEvent = rt_ZCFcn
( RISING_ZERO_CROSSING , & rtPrevZCX . g2jgodrbhp , ( rtB . f3yztw02af ) ) ;
if ( ( zcEvent != NO_ZCEVENT ) || ( rtDW . fyfdvnwnzj != 0 ) ) { resetIntg =
true ; rtX . lr2fon2uwe = rtB . ebadym5xni ; } if ( resetIntg ) {
ssSetSolverNeedsReset ( rtS ) ; } if ( rtX . lr2fon2uwe >= rtP .
inti_UpperSat_dal2xymi3h ) { rtX . lr2fon2uwe = rtP .
inti_UpperSat_dal2xymi3h ; } else { if ( rtX . lr2fon2uwe <= rtP .
inti_LowerSat_plajszqohf ) { rtX . lr2fon2uwe = rtP .
inti_LowerSat_plajszqohf ; } } } rtB . ascuylmfea = rtX . lr2fon2uwe ; rtB .
lgl3sevxjx = rtP . Gain_Gain_fvqpvk3pvf * rtB . ascuylmfea ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ssIsMajorTimeStep ( rtS ) ) { rtDW .
okwoxppsxh = ( rtB . lgl3sevxjx > rtB . kjbniesfcu ) ; rtDW . erby3qbuzu = (
rtB . lgl3sevxjx < rtP . Constant9_Value_jc35dhdc3v ) ; } rtB . c33k25rpdh =
rtDW . okwoxppsxh ; rtB . pm3wjc2bv1 = rtDW . erby3qbuzu ; } if ( rtB .
c33k25rpdh ) { rtB . i2cij1nsan = rtB . kjbniesfcu ; } else { if ( rtB .
pm3wjc2bv1 ) { rtB . dl2oj2hwn5 = rtP . Constant9_Value_jc35dhdc3v ; } else {
rtB . dl2oj2hwn5 = rtB . lgl3sevxjx ; } rtB . i2cij1nsan = rtB . dl2oj2hwn5 ;
} rtB . cy2mdsactk = 0.0 ; rtB . cy2mdsactk += rtP . StateSpace_C_iee0yjqzes
* rtX . plzaosk005 ; if ( rtP . Constant5_Value_fafteqsipq > rtP .
Switch_Threshold_abfzybubnv ) { rtB . hrgapvp0ps = muDoubleScalarExp ( ( 1.0
/ rtB . cy2mdsactk - 0.0034112229234180458 ) * 0.0 ) ; } else { rtB .
hrgapvp0ps = rtP . Constant4_Value_jum4bwpjax ; } rtB . gx3vfbmrpy = -
0.010689249086571083 * rtB . ded05j4tle / ( rtB . ded05j4tle - rtB .
i2cij1nsan ) * rtB . i2cij1nsan * rtB . hrgapvp0ps ; rtB . opjh3hy4jh = - rtB
. f3yztw02af * 0.010689249086571083 * rtB . kcia4oomek * rtB . ded05j4tle / (
rtB . ded05j4tle - rtB . i2cij1nsan ) * rtB . hrgapvp0ps ; if ( ssIsSampleHit
( rtS , 1 , 0 ) ) { rtB . dltlpyqxxt = rtP . R3_Gain_bqq4aa4t3o * rtB .
ded05j4tle ; if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . knppb5aj2r = ( rtB .
lgl3sevxjx > rtB . dltlpyqxxt ) ; } rtB . kvprg4ppnw = rtDW . knppb5aj2r ;
rtB . hesfhsyv0h = - rtB . dltlpyqxxt * 0.999 * 0.1 * 0.9999 ; if (
ssIsMajorTimeStep ( rtS ) ) { rtDW . ecnrycha4x = ( rtB . lgl3sevxjx < rtB .
hesfhsyv0h ) ; } rtB . eqm015gtbx = rtDW . ecnrycha4x ; if (
ssIsMajorTimeStep ( rtS ) ) { rtDW . dkqm0duv1u = ( rtB . kcia4oomek < rtP .
Constant_Value_mscbjvxnfy ) ; } rtB . j5n5fyudax = rtDW . dkqm0duv1u ; } if (
rtB . kvprg4ppnw ) { rtB . dz2enm0ww0 = rtB . dltlpyqxxt ; } else { if ( rtB
. eqm015gtbx ) { rtB . p5bxowhy3u = rtB . hesfhsyv0h ; } else { rtB .
p5bxowhy3u = rtB . lgl3sevxjx ; } rtB . dz2enm0ww0 = rtB . p5bxowhy3u ; }
switch ( ( int32_T ) rtP . u2v10AhLiFePO4_BatType ) { case 1 : rtB .
g03b5ho0xb [ 0 ] = rtP . Constant4_Value_db1mnqkkob * rtB . dz2enm0ww0 ; rtB
. g03b5ho0xb [ 1 ] = rtP . Constant4_Value_db1mnqkkob * rtB . kcia4oomek ;
rtB . g03b5ho0xb [ 2 ] = rtP . Constant4_Value_db1mnqkkob * rtB . j5n5fyudax
; rtB . g03b5ho0xb [ 3 ] = rtP . Constant4_Value_db1mnqkkob * rtB .
ded05j4tle ; rtB . iirqhbasaw = - rtB . g03b5ho0xb [ 2 ] *
0.010689249086571083 * rtB . g03b5ho0xb [ 1 ] * ( 10.339999999999973 / ( rtB
. g03b5ho0xb [ 0 ] + 1.0339999999999974 ) ) ; break ; case 2 : rtB .
egi1glv2iz [ 0 ] = rtP . Constant1_Value_e3wa3mydbv * rtB . dz2enm0ww0 ; rtB
. egi1glv2iz [ 1 ] = rtP . Constant1_Value_e3wa3mydbv * rtB . kcia4oomek ;
rtB . egi1glv2iz [ 2 ] = rtP . Constant1_Value_e3wa3mydbv * rtB . j5n5fyudax
; rtB . egi1glv2iz [ 3 ] = rtP . Constant1_Value_e3wa3mydbv * rtB .
ded05j4tle ; rtB . iirqhbasaw = - rtB . egi1glv2iz [ 2 ] *
0.010689249086571083 * rtB . egi1glv2iz [ 1 ] * rtB . egi1glv2iz [ 3 ] / (
rtB . egi1glv2iz [ 3 ] * 0.1 + rtB . egi1glv2iz [ 0 ] ) ; break ; case 3 :
rtB . aufyna3xwp [ 0 ] = rtP . Constant3_Value_f2btqjtsos * rtB . dz2enm0ww0
; rtB . aufyna3xwp [ 1 ] = rtP . Constant3_Value_f2btqjtsos * rtB .
kcia4oomek ; rtB . aufyna3xwp [ 2 ] = rtP . Constant3_Value_f2btqjtsos * rtB
. j5n5fyudax ; rtB . aufyna3xwp [ 3 ] = rtP . Constant3_Value_f2btqjtsos *
rtB . ded05j4tle ; rtB . iirqhbasaw = - rtB . aufyna3xwp [ 2 ] *
0.010689249086571083 * rtB . aufyna3xwp [ 1 ] * ( 10.339999999999973 / (
muDoubleScalarAbs ( rtB . aufyna3xwp [ 0 ] ) + 1.0339999999999974 ) ) ; break
; default : rtB . dpzsk0fv2e [ 0 ] = rtP . Constant2_Value_fa544zy0zf * rtB .
dz2enm0ww0 ; rtB . dpzsk0fv2e [ 1 ] = rtP . Constant2_Value_fa544zy0zf * rtB
. kcia4oomek ; rtB . dpzsk0fv2e [ 2 ] = rtP . Constant2_Value_fa544zy0zf *
rtB . j5n5fyudax ; rtB . dpzsk0fv2e [ 3 ] = rtP . Constant2_Value_fa544zy0zf
* rtB . ded05j4tle ; rtB . iirqhbasaw = - rtB . dpzsk0fv2e [ 2 ] *
0.010689249086571083 * rtB . dpzsk0fv2e [ 1 ] * ( 10.339999999999973 / (
muDoubleScalarAbs ( rtB . dpzsk0fv2e [ 0 ] ) + 1.0339999999999974 ) ) ; break
; } rtB . poiu0irxc0 = rtB . iirqhbasaw * rtB . hrgapvp0ps ; rtB . fzd1h5apha
= rtX . femnmi0kft ; switch ( ( int32_T ) rtP . u2v10AhLiFePO4_BatType ) {
case 1 : rtB . m12jzkvpeg = rtB . fzd1h5apha ; break ; case 2 : rtB .
m12jzkvpeg = muDoubleScalarExp ( - 6.1061990132382391 * rtB . i2cij1nsan ) *
1.0263398315053873 ; break ; case 3 : rtB . m12jzkvpeg = rtB . fzd1h5apha ;
break ; default : rtB . m12jzkvpeg = rtB . fzd1h5apha ; break ; } rtB .
gre3fyyedb = 0.0 ; rtB . gre3fyyedb += rtP . Currentfilter1_C_o13iba3s0t *
rtX . czasr4omxo ; if ( rtP . Constant7_Value_ncodhoosuz > rtP .
Switch2_Threshold_l01luurl0n ) { rtB . ei5r5a5pav = muDoubleScalarExp ( ( 1.0
/ rtB . cy2mdsactk - 0.0034112229234180458 ) * 0.0 ) * - rtB . nwx1m5flyz *
rtB . gre3fyyedb + 0.012 * rtB . gre3fyyedb ; } else { rtB . ei5r5a5pav = rtP
. Constant6_Value_hd4fth2fjz ; } rtB . ommpg3cgpv = ( ( ( ( rtB . gx3vfbmrpy
+ rtB . opjh3hy4jh ) + rtB . poiu0irxc0 ) + rtB . m12jzkvpeg ) + - 0.0 * rtB
. i2cij1nsan ) + rtB . ei5r5a5pav ; if ( rtP . Constant3_Value_n51n10aq0o >
rtP . Switch1_Threshold_mcownc3hf5 ) { rtB . i1k1tidl2o = ( rtB . cy2mdsactk
- 293.15 ) * 0.0 ; } else { rtB . i1k1tidl2o = rtP .
Constant2_Value_hvybrtqmxz ; } rtB . olb0grj3j3 = ( rtB . p4pflkgeyq + rtB .
ommpg3cgpv ) + rtB . i1k1tidl2o ; rtB . mkgovfegci = rtP . R1_Gain_frm0s5nenw
* rtB . kcia4oomek ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if (
ssIsMajorTimeStep ( rtS ) ) { rtDW . f4ellfbxmn = ( rtB . olb0grj3j3 > rtP .
Constant1_Value_p0nk0e4k4t ) ; } rtB . hvjsipjvee = rtDW . f4ellfbxmn ; if (
ssIsMajorTimeStep ( rtS ) ) { rtDW . guk1qwasso = ( rtB . olb0grj3j3 < rtB .
mkgovfegci ) ; } rtB . nj4n1mxjv0 = rtDW . guk1qwasso ; } if ( rtB .
hvjsipjvee ) { rtB . dfjf12bep4 = rtP . Constant1_Value_p0nk0e4k4t ; } else {
if ( rtB . nj4n1mxjv0 ) { rtB . btonwzxytu = rtB . mkgovfegci ; } else { rtB
. btonwzxytu = rtB . olb0grj3j3 ; } rtB . dfjf12bep4 = rtB . btonwzxytu ; } {
SimStruct * rts = ssGetSFunction ( rtS , 1 ) ; sfcnOutputs ( rts , 0 ) ; }
rtB . btbyo2vcmz = rtP . donotdeletethisgain_Gain_hql5qzrmqi * rtB .
oben2eao5k ; rtB . mqfk5v4diy = rtB . dfjf12bep4 - rtP . R_Gain_leocntiara *
rtB . btbyo2vcmz ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . bfx2u5xgpq =
rtP . R4_Gain_gi4xenlaa1 * rtB . ded05j4tle ; } rtB . bybpkn3fg3 = ( 1.0 -
rtB . i2cij1nsan / rtB . bfx2u5xgpq ) * 100.0 ; if ( ssIsMajorTimeStep ( rtS
) ) { rtDW . i5fsfrib41 = rtB . bybpkn3fg3 >= rtP .
Saturation_UpperSat_mtqq4gsywh ? 1 : rtB . bybpkn3fg3 > rtP .
Saturation_LowerSat_gwhczn143q ? 0 : - 1 ; } rtB . gqdjkmiehk = rtDW .
i5fsfrib41 == 1 ? rtP . Saturation_UpperSat_mtqq4gsywh : rtDW . i5fsfrib41 ==
- 1 ? rtP . Saturation_LowerSat_gwhczn143q : rtB . bybpkn3fg3 ; if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
dyo1jajuwp . LoggedData [ 0 ] ; LogVar * var = svar -> signals . values ; {
double locTime = ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * )
svar -> time , & locTime , 0 ) ; } { real_T up0 [ 1 ] ; up0 [ 0 ] = rtB .
mqfk5v4diy ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; var = var ->
next ; } { real_T up1 [ 1 ] ; up1 [ 0 ] = rtB . gqdjkmiehk ; rt_UpdateLogVar
( ( LogVar * ) var , up1 , 0 ) ; var = var -> next ; } { real_T up2 [ 1 ] ;
up2 [ 0 ] = rtB . btbyo2vcmz ; rt_UpdateLogVar ( ( LogVar * ) var , up2 , 0 )
; } } rtB . jqky25xmle = 0.0 ; rtB . jqky25xmle += rtP .
Currentfilter_C_mskf05lo23 * rtX . cdhjf34fys ; if ( ssIsSampleHit ( rtS , 1
, 0 ) ) { rtB . m4i5mlkre0 = rtDW . knyijtosqg ; rtB . ik21zuu0w2 = rtP .
R2_Gain_lmwx4sb00n * rtB . m4i5mlkre0 ; if ( ssIsMajorTimeStep ( rtS ) ) {
rtDW . d3wwahyjdv = ( rtB . jqky25xmle > rtP . Constant_Value_ezg4nv1jai ) ;
} rtB . fmkuq1m3bb = rtDW . d3wwahyjdv ; rtB . brt0odp1ig = rtDW . ft2nyeqcg1
; } if ( ssIsMajorTimeStep ( rtS ) ) { resetIntg = false ; zcEvent = rt_ZCFcn
( RISING_ZERO_CROSSING , & rtPrevZCX . ivgw3hbjew , ( rtB . fmkuq1m3bb ) ) ;
if ( ( zcEvent != NO_ZCEVENT ) || ( rtDW . gxhjb1iyjf != 0 ) ) { resetIntg =
true ; rtX . fgmli1n2fu = rtB . brt0odp1ig ; } if ( resetIntg ) {
ssSetSolverNeedsReset ( rtS ) ; } if ( rtX . fgmli1n2fu >= rtP .
inti_UpperSat_m5funkuur3 ) { rtX . fgmli1n2fu = rtP .
inti_UpperSat_m5funkuur3 ; } else { if ( rtX . fgmli1n2fu <= rtP .
inti_LowerSat_hwyc0llog5 ) { rtX . fgmli1n2fu = rtP .
inti_LowerSat_hwyc0llog5 ; } } } rtB . hwk4furfbr = rtX . fgmli1n2fu ; rtB .
poeuuptz0e = rtP . Gain_Gain_f4berbk0ip * rtB . hwk4furfbr ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ssIsMajorTimeStep ( rtS ) ) { rtDW .
bwnvfnkkdo = ( rtB . poeuuptz0e > rtB . ik21zuu0w2 ) ; rtDW . gurrglctsf = (
rtB . poeuuptz0e < rtP . Constant9_Value_e4pjobvupn ) ; } rtB . druqytbldp =
rtDW . bwnvfnkkdo ; rtB . kjxguscvc3 = rtDW . gurrglctsf ; } if ( rtB .
druqytbldp ) { rtB . kyxi4xk5b1 = rtB . ik21zuu0w2 ; } else { if ( rtB .
kjxguscvc3 ) { rtB . pjy23u5hnz = rtP . Constant9_Value_e4pjobvupn ; } else {
rtB . pjy23u5hnz = rtB . poeuuptz0e ; } rtB . kyxi4xk5b1 = rtB . pjy23u5hnz ;
} rtB . lad2rbhq0d = 0.0 ; rtB . lad2rbhq0d += rtP . StateSpace_C_flmaxlhzmm
* rtX . drcq2lkoq2 ; if ( rtP . Constant5_Value_mdyfw3r2se > rtP .
Switch_Threshold_c01jx1rxkb ) { rtB . n0ykw2xnss = muDoubleScalarExp ( ( 1.0
/ rtB . lad2rbhq0d - 0.0033540164346805303 ) * 0.0 ) ; } else { rtB .
n0ykw2xnss = rtP . Constant4_Value_hx5xprji3v ; } rtB . j2m1rxr1a0 = -
0.012604836390977644 * rtB . m4i5mlkre0 / ( rtB . m4i5mlkre0 - rtB .
kyxi4xk5b1 ) * rtB . kyxi4xk5b1 * rtB . n0ykw2xnss ; rtB . nisapdp2vu = - rtB
. fmkuq1m3bb * 0.012604836390977644 * rtB . jqky25xmle * rtB . m4i5mlkre0 / (
rtB . m4i5mlkre0 - rtB . kyxi4xk5b1 ) * rtB . n0ykw2xnss ; if ( ssIsSampleHit
( rtS , 1 , 0 ) ) { rtB . dgq5far14c = rtP . R3_Gain_h2tjvli4op * rtB .
m4i5mlkre0 ; if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . nrqdnhqrpx = ( rtB .
poeuuptz0e > rtB . dgq5far14c ) ; } rtB . f142q2bocw = rtDW . nrqdnhqrpx ;
rtB . mdkcdrc1dj = - rtB . dgq5far14c * 0.999 * rtInf * 0.9999 ; if (
ssIsMajorTimeStep ( rtS ) ) { rtDW . i0tbjbubdb = ( rtB . poeuuptz0e < rtB .
mdkcdrc1dj ) ; } rtB . b1tb4rlksj = rtDW . i0tbjbubdb ; if (
ssIsMajorTimeStep ( rtS ) ) { rtDW . ho5g2sdnaf = ( rtB . jqky25xmle < rtP .
Constant_Value_i12rhgm4ll ) ; } rtB . dg1ivic2cv = rtDW . ho5g2sdnaf ; } if (
rtB . f142q2bocw ) { rtB . g3fahebeoh = rtB . dgq5far14c ; } else { if ( rtB
. b1tb4rlksj ) { rtB . oiiyyqltbq = rtB . mdkcdrc1dj ; } else { rtB .
oiiyyqltbq = rtB . poeuuptz0e ; } rtB . g3fahebeoh = rtB . oiiyyqltbq ; }
switch ( ( int32_T ) rtP . u2volts10AhNiMHbattery_BatType ) { case 1 : rtB .
psc1bdwm0e [ 0 ] = rtP . Constant4_Value_nfrrjffypp * rtB . g3fahebeoh ; rtB
. psc1bdwm0e [ 1 ] = rtP . Constant4_Value_nfrrjffypp * rtB . jqky25xmle ;
rtB . psc1bdwm0e [ 2 ] = rtP . Constant4_Value_nfrrjffypp * rtB . dg1ivic2cv
; rtB . psc1bdwm0e [ 3 ] = rtP . Constant4_Value_nfrrjffypp * rtB .
m4i5mlkre0 ; rtB . o2w0cdwc0f = - rtB . psc1bdwm0e [ 2 ] *
0.012604836390977644 * rtB . psc1bdwm0e [ 1 ] * ( 11.221538461538424 / ( rtB
. psc1bdwm0e [ 0 ] + 1.1221538461538425 ) ) ; break ; case 2 : rtB .
lwryrfr1np [ 0 ] = rtP . Constant1_Value_a1rhrhkbfn * rtB . g3fahebeoh ; rtB
. lwryrfr1np [ 1 ] = rtP . Constant1_Value_a1rhrhkbfn * rtB . jqky25xmle ;
rtB . lwryrfr1np [ 2 ] = rtP . Constant1_Value_a1rhrhkbfn * rtB . dg1ivic2cv
; rtB . lwryrfr1np [ 3 ] = rtP . Constant1_Value_a1rhrhkbfn * rtB .
m4i5mlkre0 ; rtB . o2w0cdwc0f = - rtB . lwryrfr1np [ 2 ] *
0.012604836390977644 * rtB . lwryrfr1np [ 1 ] * rtB . lwryrfr1np [ 3 ] / (
rtB . lwryrfr1np [ 3 ] * 0.1 + rtB . lwryrfr1np [ 0 ] ) ; break ; case 3 :
rtB . dehp52jxod [ 0 ] = rtP . Constant3_Value_cy3b2kpr1c * rtB . g3fahebeoh
; rtB . dehp52jxod [ 1 ] = rtP . Constant3_Value_cy3b2kpr1c * rtB .
jqky25xmle ; rtB . dehp52jxod [ 2 ] = rtP . Constant3_Value_cy3b2kpr1c * rtB
. dg1ivic2cv ; rtB . dehp52jxod [ 3 ] = rtP . Constant3_Value_cy3b2kpr1c *
rtB . m4i5mlkre0 ; rtB . o2w0cdwc0f = - rtB . dehp52jxod [ 2 ] *
0.012604836390977644 * rtB . dehp52jxod [ 1 ] * ( 11.221538461538424 / (
muDoubleScalarAbs ( rtB . dehp52jxod [ 0 ] ) + 1.1221538461538425 ) ) ; break
; default : rtB . dhz0gnwoz2 [ 0 ] = rtP . Constant2_Value_a5vfpd3gf4 * rtB .
g3fahebeoh ; rtB . dhz0gnwoz2 [ 1 ] = rtP . Constant2_Value_a5vfpd3gf4 * rtB
. jqky25xmle ; rtB . dhz0gnwoz2 [ 2 ] = rtP . Constant2_Value_a5vfpd3gf4 *
rtB . dg1ivic2cv ; rtB . dhz0gnwoz2 [ 3 ] = rtP . Constant2_Value_a5vfpd3gf4
* rtB . m4i5mlkre0 ; rtB . o2w0cdwc0f = - rtB . dhz0gnwoz2 [ 2 ] *
0.012604836390977644 * rtB . dhz0gnwoz2 [ 1 ] * ( 11.221538461538424 / (
muDoubleScalarAbs ( rtB . dhz0gnwoz2 [ 0 ] ) + 1.1221538461538425 ) ) ; break
; } rtB . foxxmgfp1n = rtB . o2w0cdwc0f * rtB . n0ykw2xnss ; rtB . guy2kz5ncd
= rtX . cw5koqcmmd ; switch ( ( int32_T ) rtP .
u2volts10AhNiMHbattery_BatType ) { case 1 : rtB . fzutsooicn = rtB .
guy2kz5ncd ; break ; case 2 : rtB . fzutsooicn = muDoubleScalarExp ( - 1.5 *
rtB . kyxi4xk5b1 ) * 1.1126870203198884 ; break ; case 3 : rtB . fzutsooicn =
rtB . guy2kz5ncd ; break ; default : rtB . fzutsooicn = rtB . guy2kz5ncd ;
break ; } rtB . ffql2fnkid = 0.0 ; rtB . ffql2fnkid += rtP .
Currentfilter1_C_nx2vxymlgz * rtX . jaymf1z1oc ; if ( rtP .
Constant7_Value_fs50zyrehf > rtP . Switch2_Threshold_dcfkmijqkz ) { rtB .
bzhvuobncb = muDoubleScalarExp ( ( 1.0 / rtB . lad2rbhq0d -
0.0033540164346805303 ) * 0.0 ) * - rtB . i0dlbs1b2l * rtB . ffql2fnkid +
0.012 * rtB . ffql2fnkid ; } else { rtB . bzhvuobncb = rtP .
Constant6_Value_kkiebpd3zp ; } rtB . g4hw1qgbdv = ( ( ( ( rtB . j2m1rxr1a0 +
rtB . nisapdp2vu ) + rtB . foxxmgfp1n ) + rtB . fzutsooicn ) + - 0.0 * rtB .
kyxi4xk5b1 ) + rtB . bzhvuobncb ; if ( rtP . Constant3_Value_jbt5o32vyc > rtP
. Switch1_Threshold_id0sltlw43 ) { rtB . prq1vlt5vx = ( rtB . lad2rbhq0d -
298.15 ) * 0.0 ; } else { rtB . prq1vlt5vx = rtP . Constant2_Value_idziu2npmy
; } rtB . ecaohy0st5 = ( rtB . mfmapc1zif + rtB . g4hw1qgbdv ) + rtB .
prq1vlt5vx ; rtB . b4dywjx5hn = rtP . R1_Gain_lxoje1sbcn * rtB . jqky25xmle ;
if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ssIsMajorTimeStep ( rtS ) ) {
rtDW . ixmlzcolrr = ( rtB . ecaohy0st5 > rtP . Constant1_Value_nxh5i5seoh ) ;
} rtB . ewa4jwoiei = rtDW . ixmlzcolrr ; if ( ssIsMajorTimeStep ( rtS ) ) {
rtDW . fkqektwhpq = ( rtB . ecaohy0st5 < rtB . b4dywjx5hn ) ; } rtB .
h54wfmqlk0 = rtDW . fkqektwhpq ; } if ( rtB . ewa4jwoiei ) { rtB . offgvp1su2
= rtP . Constant1_Value_nxh5i5seoh ; } else { if ( rtB . h54wfmqlk0 ) { rtB .
b3jprbo2ch = rtB . b4dywjx5hn ; } else { rtB . b3jprbo2ch = rtB . ecaohy0st5
; } rtB . offgvp1su2 = rtB . b3jprbo2ch ; } { SimStruct * rts =
ssGetSFunction ( rtS , 2 ) ; sfcnOutputs ( rts , 0 ) ; } rtB . aepfzat2ah =
rtP . donotdeletethisgain_Gain_cnrap2hfmr * rtB . mj03tas4fg ; rtB .
bb0v5z1gyy = rtB . offgvp1su2 - rtP . R_Gain_gmkimg2vno * rtB . aepfzat2ah ;
if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . awto1smfy3 = rtP .
R4_Gain_grw2mkmlr5 * rtB . m4i5mlkre0 ; } rtB . adxkajg20f = ( 1.0 - rtB .
kyxi4xk5b1 / rtB . awto1smfy3 ) * 100.0 ; if ( ssIsMajorTimeStep ( rtS ) ) {
rtDW . etgutsyzrf = rtB . adxkajg20f >= rtP . Saturation_UpperSat_mo1jv0phgx
? 1 : rtB . adxkajg20f > rtP . Saturation_LowerSat_dggvwabw03 ? 0 : - 1 ; }
rtB . p5iut1x42c = rtDW . etgutsyzrf == 1 ? rtP .
Saturation_UpperSat_mo1jv0phgx : rtDW . etgutsyzrf == - 1 ? rtP .
Saturation_LowerSat_dggvwabw03 : rtB . adxkajg20f ; if ( ssGetLogOutput ( rtS
) ) { StructLogVar * svar = ( StructLogVar * ) rtDW . chubbvu0th . LoggedData
[ 0 ] ; LogVar * var = svar -> signals . values ; { double locTime =
ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar -> time , &
locTime , 0 ) ; } { real_T up0 [ 1 ] ; up0 [ 0 ] = rtB . bb0v5z1gyy ;
rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; var = var -> next ; } {
real_T up1 [ 1 ] ; up1 [ 0 ] = rtB . p5iut1x42c ; rt_UpdateLogVar ( ( LogVar
* ) var , up1 , 0 ) ; var = var -> next ; } { real_T up2 [ 1 ] ; up2 [ 0 ] =
rtB . aepfzat2ah ; rt_UpdateLogVar ( ( LogVar * ) var , up2 , 0 ) ; } }
switch ( ( int32_T ) rtP . u_Value ) { case 1 : mtmp = rtB . mqfk5v4diy ; tmp
= rtB . gqdjkmiehk ; break ; case 2 : mtmp = rtB . kgwpzskznu ; tmp = rtB .
nvl5qjckkv ; break ; default : mtmp = rtB . bb0v5z1gyy ; tmp = rtB .
p5iut1x42c ; break ; } tmp_p [ 0 ] = tmp ; tmp_p [ 1 ] = mtmp ; k5tlp010j4 (
tmp_p , tmp_e ) ; for ( ixstart = 0 ; ixstart < 3 ; ixstart ++ ) { x [
ixstart << 1 ] = tmp_e [ ixstart ] ; x [ 1 + ( ixstart << 1 ) ] = tmp_e [
ixstart + 3 ] ; } y [ 0 ] = ( x [ 0 ] + x [ 1 ] ) / 2.0 ; y [ 1 ] = ( x [ 2 ]
+ x [ 3 ] ) / 2.0 ; y [ 2 ] = ( x [ 4 ] + x [ 5 ] ) / 2.0 ; ixstart = 1 ;
mtmp = y [ 0 ] ; itmp = 1 ; if ( muDoubleScalarIsNaN ( y [ 0 ] ) ) { ix = 2 ;
exitg1 = false ; while ( ( ! exitg1 ) && ( ix < 4 ) ) { ixstart = ix ; if ( !
muDoubleScalarIsNaN ( y [ ix - 1 ] ) ) { mtmp = y [ ix - 1 ] ; itmp = ix ;
exitg1 = true ; } else { ix ++ ; } } } if ( ixstart < 3 ) { while ( ixstart +
1 < 4 ) { if ( y [ ixstart ] > mtmp ) { mtmp = y [ ixstart ] ; itmp = ixstart
+ 1 ; } ixstart ++ ; } } rtB . hoa4ffors0 = itmp ; if ( ssIsMajorTimeStep (
rtS ) ) { rtDW . nn2v3m5mqb = ( rtB . ml5sunf4wl >= 0.0 ) ; } rtB .
bb0be3gnia = rtDW . nn2v3m5mqb > 0 ? rtB . ml5sunf4wl : - rtB . ml5sunf4wl ;
if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ssIsMajorTimeStep ( rtS ) ) {
rtDW . ieybpiozzj = ( rtB . ml5sunf4wl < rtP . Constant_Value_blwrb2w0qh ) ;
} rtB . hqpcpdn5qa = rtP . Gain4_Gain * ( real_T ) rtDW . ieybpiozzj ; } rtB
. jbhxgjw5cy = rtB . hqpcpdn5qa - rtB . ia1kg5fvtb ; rtB . nf3rdcvax5 = rtB .
bb0be3gnia * rtB . jbhxgjw5cy ; rtB . j4gfvflild = rtP . Gain1_Gain * rtB .
nf3rdcvax5 ; rtB . jce4jecbbp = rtP . Gain2_Gain * rtB . o4aync4hqi ; if (
ssIsMajorTimeStep ( rtS ) ) { rtDW . i4dp0latxw = ( rtB . cb1nnepflz >= 0.0 )
; } rtB . dwb42stmvv = rtDW . i4dp0latxw > 0 ? rtB . cb1nnepflz : - rtB .
cb1nnepflz ; rtB . gu3qbji4xc = 0.012 * rtB . cb1nnepflz + - rtB . kypwxy50kw
; if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . elzvn2clyn = ( rtB . gu3qbji4xc
>= 0.0 ) ; } rtB . pgudi1oete = rtDW . elzvn2clyn > 0 ? rtB . gu3qbji4xc : -
rtB . gu3qbji4xc ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if (
ssIsMajorTimeStep ( rtS ) ) { rtDW . e4tlndddzv = ( rtB . cb1nnepflz < rtP .
Constant_Value_dn32sdoil4 ) ; } rtB . fmw5kmtm1r = rtP . Gain_Gain_dwzn0ogzht
* ( real_T ) rtDW . e4tlndddzv ; } rtB . bwvje3ihiw = rtB . dwb42stmvv * rtB
. pgudi1oete ; rtB . m0yglvlyme = ( 0.0 * rtB . dwb42stmvv * rtB . a4eiiet2o0
+ rtB . fmw5kmtm1r ) + rtB . bwvje3ihiw ; rtB . aesu3l5yyk = 0.0 ; rtB .
aesu3l5yyk += rtP . TransferFcn1_C * rtX . mlhiasidwv ; rtB . e3cqouyy3w =
rtP . Gain_Gain_npmm5mmnhb * rtB . aesu3l5yyk ; rtB . dcqdhsbevr = rtB .
lzetnopoo3 + rtB . e3cqouyy3w ; if ( ssIsMajorTimeStep ( rtS ) ) { rtDW .
p4ho05td4b = ( rtB . aepfzat2ah >= 0.0 ) ; } rtB . o3lepigeif = rtDW .
p4ho05td4b > 0 ? rtB . aepfzat2ah : - rtB . aepfzat2ah ; if ( ssIsSampleHit (
rtS , 1 , 0 ) ) { if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . abjaxhp14q = (
rtB . aepfzat2ah < rtP . Constant_Value_mexjddav50 ) ; } rtB . d5351zjf4x =
rtP . Gain4_Gain_l2e2nzph1g * ( real_T ) rtDW . abjaxhp14q ; } rtB .
eoju45gqpq = rtB . d5351zjf4x - rtB . guy2kz5ncd ; rtB . dfbrmr4pqz = rtB .
o3lepigeif * rtB . eoju45gqpq ; rtB . dabeiiy4xg = rtP .
Gain1_Gain_fytmd1ajrp * rtB . dfbrmr4pqz ; rtB . etpdoa2xuk = rtP .
Gain2_Gain_b1lukokzr1 * rtB . kyxi4xk5b1 ; if ( ssIsMajorTimeStep ( rtS ) ) {
rtDW . okerpy1dzv = ( rtB . ffql2fnkid >= 0.0 ) ; } rtB . jaquvxw41i = rtDW .
okerpy1dzv > 0 ? rtB . ffql2fnkid : - rtB . ffql2fnkid ; rtB . oaqch21uel =
0.012 * rtB . ffql2fnkid + - rtB . g4hw1qgbdv ; if ( ssIsMajorTimeStep ( rtS
) ) { rtDW . ayr4ahfun4 = ( rtB . oaqch21uel >= 0.0 ) ; } rtB . lvkqstzrdf =
rtDW . ayr4ahfun4 > 0 ? rtB . oaqch21uel : - rtB . oaqch21uel ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ssIsMajorTimeStep ( rtS ) ) { rtDW .
ivlzoptp2y = ( rtB . ffql2fnkid < rtP . Constant_Value_ce0ilwr0v4 ) ; } rtB .
lmk5yid3hu = rtP . Gain_Gain_mavdcgl3fv * ( real_T ) rtDW . ivlzoptp2y ; }
rtB . grozn2da0l = rtB . jaquvxw41i * rtB . lvkqstzrdf ; rtB . dzqkvxhkd1 = (
0.0 * rtB . jaquvxw41i * rtB . lad2rbhq0d + rtB . lmk5yid3hu ) + rtB .
grozn2da0l ; rtB . lwlovbyzf2 = 0.0 ; rtB . lwlovbyzf2 += rtP .
TransferFcn1_C_nct1hyfwyw * rtX . lvhyb51zfr ; rtB . n0r3f03erl = rtP .
Gain_Gain_ocmxl2t2zp * rtB . lwlovbyzf2 ; rtB . e0dl0dglhu = rtB . koz3cqzv1c
+ rtB . n0r3f03erl ; if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . j220vn1p2t = (
rtB . btbyo2vcmz >= 0.0 ) ; } rtB . j3xdv1bkdg = rtDW . j220vn1p2t > 0 ? rtB
. btbyo2vcmz : - rtB . btbyo2vcmz ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if
( ssIsMajorTimeStep ( rtS ) ) { rtDW . bkvk3xox1d = ( rtB . btbyo2vcmz < rtP
. Constant_Value_fk15mpo45m ) ; } rtB . maqw5opry0 = rtP .
Gain4_Gain_bwxmd45ipv * ( real_T ) rtDW . bkvk3xox1d ; } rtB . acjy0wcx33 =
rtB . maqw5opry0 - rtB . fzd1h5apha ; rtB . ffgdskx2hu = rtB . j3xdv1bkdg *
rtB . acjy0wcx33 ; rtB . brdas51kj1 = rtP . Gain1_Gain_pji14mxcuf * rtB .
ffgdskx2hu ; rtB . h2cdsbamjg = rtP . Gain2_Gain_oxevkaekqr * rtB .
i2cij1nsan ; if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . e0tyil0jmq = ( rtB .
gre3fyyedb >= 0.0 ) ; } rtB . njpjxwiwga = rtDW . e0tyil0jmq > 0 ? rtB .
gre3fyyedb : - rtB . gre3fyyedb ; rtB . mc3kmonqyw = 0.012 * rtB . gre3fyyedb
+ - rtB . ommpg3cgpv ; if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . llbft42mya =
( rtB . mc3kmonqyw >= 0.0 ) ; } rtB . eajyu4e2gg = rtDW . llbft42mya > 0 ?
rtB . mc3kmonqyw : - rtB . mc3kmonqyw ; if ( ssIsSampleHit ( rtS , 1 , 0 ) )
{ if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . mwafatbfsb = ( rtB . gre3fyyedb <
rtP . Constant_Value_cvgmtz023a ) ; } rtB . csv1q2rmqm = rtP .
Gain_Gain_ig2ewsw3sm * ( real_T ) rtDW . mwafatbfsb ; } rtB . hap1ivasmg =
rtB . njpjxwiwga * rtB . eajyu4e2gg ; rtB . o0zujw030w = ( 0.0 * rtB .
njpjxwiwga * rtB . cy2mdsactk + rtB . csv1q2rmqm ) + rtB . hap1ivasmg ; rtB .
agnwtijpiy = 0.0 ; rtB . agnwtijpiy += rtP . TransferFcn1_C_omqc4vdzkc * rtX
. ic4xkivobu ; rtB . oepc1i4s5o = rtP . Gain_Gain_k3wfy1rzcq * rtB .
agnwtijpiy ; rtB . gnxuzeutps = rtB . nfweyj1qvq + rtB . oepc1i4s5o ;
UNUSED_PARAMETER ( tid ) ; } void MdlOutputsTID2 ( int_T tid ) { real_T u0 ;
if ( rtP . Constant10_Value > rtP . Switch3_Threshold ) { if ( rtP .
Constant_Value > rtP . Saturation3_UpperSat ) { rtB . jru2iqrfmm = rtP .
Saturation3_UpperSat ; } else if ( rtP . Constant_Value < rtP .
Saturation3_LowerSat ) { rtB . jru2iqrfmm = rtP . Saturation3_LowerSat ; }
else { rtB . jru2iqrfmm = rtP . Constant_Value ; } } else { rtB . jru2iqrfmm
= rtP . Constant_Value ; } if ( rtP . Constant15_Value > rtP .
Switch6_Threshold ) { rtB . fgkxbpykg1 = rtP . Constant14_Value ; } else {
rtB . fgkxbpykg1 = rtP . Constant16_Value ; } if ( rtP .
Constant10_Value_b4me2hmi3i > rtP . Switch3_Threshold_f11xead0ed ) { if ( rtP
. Constant_Value_b2oae4kl4u > rtP . Saturation3_UpperSat_matxumbq22 ) { rtB .
p4pflkgeyq = rtP . Saturation3_UpperSat_matxumbq22 ; } else if ( rtP .
Constant_Value_b2oae4kl4u < rtP . Saturation3_LowerSat_ikhjztqrap ) { rtB .
p4pflkgeyq = rtP . Saturation3_LowerSat_ikhjztqrap ; } else { rtB .
p4pflkgeyq = rtP . Constant_Value_b2oae4kl4u ; } } else { rtB . p4pflkgeyq =
rtP . Constant_Value_b2oae4kl4u ; } if ( rtP . Constant15_Value_ad54pn3wr2 >
rtP . Switch6_Threshold_htoqtnapgo ) { rtB . nwx1m5flyz = rtP .
Constant14_Value_mkv5pnyukp ; } else { rtB . nwx1m5flyz = rtP .
Constant16_Value_cjh5ma2c3k ; } if ( rtP . Constant10_Value_lc4vxfnhde > rtP
. Switch3_Threshold_dyzy5hn0uo ) { if ( rtP . Constant_Value_irl5fvnkc1 > rtP
. Saturation3_UpperSat_ntsul5erig ) { rtB . mfmapc1zif = rtP .
Saturation3_UpperSat_ntsul5erig ; } else if ( rtP . Constant_Value_irl5fvnkc1
< rtP . Saturation3_LowerSat_b5p1gj4cuc ) { rtB . mfmapc1zif = rtP .
Saturation3_LowerSat_b5p1gj4cuc ; } else { rtB . mfmapc1zif = rtP .
Constant_Value_irl5fvnkc1 ; } } else { rtB . mfmapc1zif = rtP .
Constant_Value_irl5fvnkc1 ; } if ( rtP . Constant15_Value_crqj5fw4c3 > rtP .
Switch6_Threshold_jp4ffub4pb ) { rtB . i0dlbs1b2l = rtP .
Constant14_Value_badjrarjmp ; } else { rtB . i0dlbs1b2l = rtP .
Constant16_Value_idauo5rtab ; } rtB . lzetnopoo3 = rtP . Ta_Value + rtP .
Constant8_Value ; if ( rtP . Constant11_Value > rtP . Switch4_Threshold ) {
u0 = ( rtB . lzetnopoo3 - 298.15 ) * 0.0 + 11.562499999999885 ; if ( u0 > rtP
. Saturation2_UpperSat ) { rtB . pvwijbyxkr = rtP . Saturation2_UpperSat ; }
else if ( u0 < rtP . Saturation2_LowerSat ) { rtB . pvwijbyxkr = rtP .
Saturation2_LowerSat ; } else { rtB . pvwijbyxkr = u0 ; } } else { rtB .
pvwijbyxkr = rtP . Constant12_Value ; } rtB . koz3cqzv1c = rtP .
Ta_Value_grpxumhhux + rtP . Constant8_Value_kzavomyluf ; if ( rtP .
Constant11_Value_fwpcd5xjtn > rtP . Switch4_Threshold_laodusaory ) { u0 = (
rtB . koz3cqzv1c - 298.15 ) * 0.0 + 11.221538461538424 ; if ( u0 > rtP .
Saturation2_UpperSat_ppqdia3avp ) { rtB . n5c0k4fbwb = rtP .
Saturation2_UpperSat_ppqdia3avp ; } else if ( u0 < rtP .
Saturation2_LowerSat_jhnens0jar ) { rtB . n5c0k4fbwb = rtP .
Saturation2_LowerSat_jhnens0jar ; } else { rtB . n5c0k4fbwb = u0 ; } } else {
rtB . n5c0k4fbwb = rtP . Constant12_Value_ir3wdqdic4 ; } rtB . nfweyj1qvq =
rtP . Ta_Value_ko1cwv42q0 + rtP . Constant8_Value_ojzmwgq5pn ; if ( rtP .
Constant11_Value_k5i3bqlkzv > rtP . Switch4_Threshold_abb0upiodf ) { u0 = (
rtB . nfweyj1qvq - 293.15 ) * 0.0 + 10.339999999999973 ; if ( u0 > rtP .
Saturation2_UpperSat_kllm5hrnuw ) { rtB . hrenjgvsp2 = rtP .
Saturation2_UpperSat_kllm5hrnuw ; } else if ( u0 < rtP .
Saturation2_LowerSat_lf1dgltu2n ) { rtB . hrenjgvsp2 = rtP .
Saturation2_LowerSat_lf1dgltu2n ; } else { rtB . hrenjgvsp2 = u0 ; } } else {
rtB . hrenjgvsp2 = rtP . Constant12_Value_ooh2hzd22c ; } UNUSED_PARAMETER (
tid ) ; } void MdlUpdate ( int_T tid ) { if ( ssIsSampleHit ( rtS , 1 , 0 ) )
{ rtDW . jflxrokyki = rtB . pvwijbyxkr ; rtDW . gkgewmrthj = rtB . jce4jecbbp
; } rtDW . nkl51yszn4 = 0 ; if ( rtX . geiqvotdgd == rtP . inti_UpperSat ) {
switch ( rtDW . j4qnczxkrf ) { case 3 : if ( rtB . ml5sunf4wl < 0.0 ) {
ssSetSolverNeedsReset ( rtS ) ; rtDW . j4qnczxkrf = 1 ; } break ; case 1 : if
( rtB . ml5sunf4wl >= 0.0 ) { rtDW . j4qnczxkrf = 3 ; ssSetSolverNeedsReset (
rtS ) ; } break ; default : ssSetSolverNeedsReset ( rtS ) ; if ( rtB .
ml5sunf4wl < 0.0 ) { rtDW . j4qnczxkrf = 1 ; } else { rtDW . j4qnczxkrf = 3 ;
} break ; } } else if ( rtX . geiqvotdgd == rtP . inti_LowerSat ) { switch (
rtDW . j4qnczxkrf ) { case 4 : if ( rtB . ml5sunf4wl > 0.0 ) {
ssSetSolverNeedsReset ( rtS ) ; rtDW . j4qnczxkrf = 2 ; } break ; case 2 : if
( rtB . ml5sunf4wl <= 0.0 ) { rtDW . j4qnczxkrf = 4 ; ssSetSolverNeedsReset (
rtS ) ; } break ; default : ssSetSolverNeedsReset ( rtS ) ; if ( rtB .
ml5sunf4wl > 0.0 ) { rtDW . j4qnczxkrf = 2 ; } else { rtDW . j4qnczxkrf = 4 ;
} break ; } } else { rtDW . j4qnczxkrf = 0 ; } { SimStruct * rts =
ssGetSFunction ( rtS , 0 ) ; sfcnUpdate ( rts , 0 ) ; if ( ssGetErrorStatus (
rts ) != ( NULL ) ) return ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtDW .
byrrqwbwuv = rtB . hrenjgvsp2 ; rtDW . ko2pp0cfqy = rtB . h2cdsbamjg ; } rtDW
. fyfdvnwnzj = 0 ; if ( rtX . lr2fon2uwe == rtP . inti_UpperSat_dal2xymi3h )
{ switch ( rtDW . cr3vas1c0t ) { case 3 : if ( rtB . btbyo2vcmz < 0.0 ) {
ssSetSolverNeedsReset ( rtS ) ; rtDW . cr3vas1c0t = 1 ; } break ; case 1 : if
( rtB . btbyo2vcmz >= 0.0 ) { rtDW . cr3vas1c0t = 3 ; ssSetSolverNeedsReset (
rtS ) ; } break ; default : ssSetSolverNeedsReset ( rtS ) ; if ( rtB .
btbyo2vcmz < 0.0 ) { rtDW . cr3vas1c0t = 1 ; } else { rtDW . cr3vas1c0t = 3 ;
} break ; } } else if ( rtX . lr2fon2uwe == rtP . inti_LowerSat_plajszqohf )
{ switch ( rtDW . cr3vas1c0t ) { case 4 : if ( rtB . btbyo2vcmz > 0.0 ) {
ssSetSolverNeedsReset ( rtS ) ; rtDW . cr3vas1c0t = 2 ; } break ; case 2 : if
( rtB . btbyo2vcmz <= 0.0 ) { rtDW . cr3vas1c0t = 4 ; ssSetSolverNeedsReset (
rtS ) ; } break ; default : ssSetSolverNeedsReset ( rtS ) ; if ( rtB .
btbyo2vcmz > 0.0 ) { rtDW . cr3vas1c0t = 2 ; } else { rtDW . cr3vas1c0t = 4 ;
} break ; } } else { rtDW . cr3vas1c0t = 0 ; } { SimStruct * rts =
ssGetSFunction ( rtS , 1 ) ; sfcnUpdate ( rts , 0 ) ; if ( ssGetErrorStatus (
rts ) != ( NULL ) ) return ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtDW .
knyijtosqg = rtB . n5c0k4fbwb ; rtDW . ft2nyeqcg1 = rtB . etpdoa2xuk ; } rtDW
. gxhjb1iyjf = 0 ; if ( rtX . fgmli1n2fu == rtP . inti_UpperSat_m5funkuur3 )
{ switch ( rtDW . l4pyajhrvl ) { case 3 : if ( rtB . aepfzat2ah < 0.0 ) {
ssSetSolverNeedsReset ( rtS ) ; rtDW . l4pyajhrvl = 1 ; } break ; case 1 : if
( rtB . aepfzat2ah >= 0.0 ) { rtDW . l4pyajhrvl = 3 ; ssSetSolverNeedsReset (
rtS ) ; } break ; default : ssSetSolverNeedsReset ( rtS ) ; if ( rtB .
aepfzat2ah < 0.0 ) { rtDW . l4pyajhrvl = 1 ; } else { rtDW . l4pyajhrvl = 3 ;
} break ; } } else if ( rtX . fgmli1n2fu == rtP . inti_LowerSat_hwyc0llog5 )
{ switch ( rtDW . l4pyajhrvl ) { case 4 : if ( rtB . aepfzat2ah > 0.0 ) {
ssSetSolverNeedsReset ( rtS ) ; rtDW . l4pyajhrvl = 2 ; } break ; case 2 : if
( rtB . aepfzat2ah <= 0.0 ) { rtDW . l4pyajhrvl = 4 ; ssSetSolverNeedsReset (
rtS ) ; } break ; default : ssSetSolverNeedsReset ( rtS ) ; if ( rtB .
aepfzat2ah > 0.0 ) { rtDW . l4pyajhrvl = 2 ; } else { rtDW . l4pyajhrvl = 4 ;
} break ; } } else { rtDW . l4pyajhrvl = 0 ; } { SimStruct * rts =
ssGetSFunction ( rtS , 2 ) ; sfcnUpdate ( rts , 0 ) ; if ( ssGetErrorStatus (
rts ) != ( NULL ) ) return ; } UNUSED_PARAMETER ( tid ) ; } void
MdlUpdateTID2 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void
MdlDerivatives ( void ) { XDot * _rtXdot ; XDis * _rtXdis ; _rtXdis = ( (
XDis * ) ssGetContStateDisabled ( rtS ) ) ; _rtXdot = ( ( XDot * ) ssGetdX (
rtS ) ) ; _rtXdot -> awyk3jkmpp = 0.0 ; _rtXdot -> awyk3jkmpp += rtP .
Currentfilter_A * rtX . awyk3jkmpp ; _rtXdot -> awyk3jkmpp += rtB .
ml5sunf4wl ; if ( ( rtDW . j4qnczxkrf != 3 ) && ( rtDW . j4qnczxkrf != 4 ) )
{ _rtXdot -> geiqvotdgd = rtB . ml5sunf4wl ; _rtXdis -> geiqvotdgd = false ;
} else { _rtXdot -> geiqvotdgd = 0.0 ; if ( ( rtDW . j4qnczxkrf == 3 ) || (
rtDW . j4qnczxkrf == 4 ) ) { _rtXdis -> geiqvotdgd = true ; } } _rtXdot ->
gjrr5rcl1i = 0.0 ; _rtXdot -> gjrr5rcl1i += rtP . StateSpace_A * rtX .
gjrr5rcl1i ; _rtXdot -> gjrr5rcl1i += rtP . StateSpace_B * rtB . dcqdhsbevr ;
_rtXdot -> emndqevlhi = rtB . j4gfvflild ; _rtXdot -> oobd5yyumt = 0.0 ;
_rtXdot -> oobd5yyumt += rtP . Currentfilter1_A * rtX . oobd5yyumt ; _rtXdot
-> oobd5yyumt += rtB . ml5sunf4wl ; _rtXdot -> gqep4i1he1 = 0.0 ; _rtXdot ->
gqep4i1he1 += rtP . Currentfilter_A_hpeprc3wrq * rtX . gqep4i1he1 ; _rtXdot
-> gqep4i1he1 += rtB . btbyo2vcmz ; if ( ( rtDW . cr3vas1c0t != 3 ) && ( rtDW
. cr3vas1c0t != 4 ) ) { _rtXdot -> lr2fon2uwe = rtB . btbyo2vcmz ; _rtXdis ->
lr2fon2uwe = false ; } else { _rtXdot -> lr2fon2uwe = 0.0 ; if ( ( rtDW .
cr3vas1c0t == 3 ) || ( rtDW . cr3vas1c0t == 4 ) ) { _rtXdis -> lr2fon2uwe =
true ; } } _rtXdot -> plzaosk005 = 0.0 ; _rtXdot -> plzaosk005 += rtP .
StateSpace_A_lj2d3hqe0x * rtX . plzaosk005 ; _rtXdot -> plzaosk005 += rtP .
StateSpace_B_mjohccgfqz * rtB . gnxuzeutps ; _rtXdot -> femnmi0kft = rtB .
brdas51kj1 ; _rtXdot -> czasr4omxo = 0.0 ; _rtXdot -> czasr4omxo += rtP .
Currentfilter1_A_cqp1aqrh0k * rtX . czasr4omxo ; _rtXdot -> czasr4omxo += rtB
. btbyo2vcmz ; _rtXdot -> cdhjf34fys = 0.0 ; _rtXdot -> cdhjf34fys += rtP .
Currentfilter_A_cwwxbi13u0 * rtX . cdhjf34fys ; _rtXdot -> cdhjf34fys += rtB
. aepfzat2ah ; if ( ( rtDW . l4pyajhrvl != 3 ) && ( rtDW . l4pyajhrvl != 4 )
) { _rtXdot -> fgmli1n2fu = rtB . aepfzat2ah ; _rtXdis -> fgmli1n2fu = false
; } else { _rtXdot -> fgmli1n2fu = 0.0 ; if ( ( rtDW . l4pyajhrvl == 3 ) || (
rtDW . l4pyajhrvl == 4 ) ) { _rtXdis -> fgmli1n2fu = true ; } } _rtXdot ->
drcq2lkoq2 = 0.0 ; _rtXdot -> drcq2lkoq2 += rtP . StateSpace_A_aeig1o2grk *
rtX . drcq2lkoq2 ; _rtXdot -> drcq2lkoq2 += rtP . StateSpace_B_ggzos4rhxs *
rtB . e0dl0dglhu ; _rtXdot -> cw5koqcmmd = rtB . dabeiiy4xg ; _rtXdot ->
jaymf1z1oc = 0.0 ; _rtXdot -> jaymf1z1oc += rtP . Currentfilter1_A_a05epnrbo3
* rtX . jaymf1z1oc ; _rtXdot -> jaymf1z1oc += rtB . aepfzat2ah ; _rtXdot ->
mlhiasidwv = 0.0 ; _rtXdot -> mlhiasidwv += rtP . TransferFcn1_A * rtX .
mlhiasidwv ; _rtXdot -> mlhiasidwv += rtB . m0yglvlyme ; _rtXdot ->
lvhyb51zfr = 0.0 ; _rtXdot -> lvhyb51zfr += rtP . TransferFcn1_A_a3pzcnto0r *
rtX . lvhyb51zfr ; _rtXdot -> lvhyb51zfr += rtB . dzqkvxhkd1 ; _rtXdot ->
ic4xkivobu = 0.0 ; _rtXdot -> ic4xkivobu += rtP . TransferFcn1_A_izgygp24sn *
rtX . ic4xkivobu ; _rtXdot -> ic4xkivobu += rtB . o0zujw030w ; } void
MdlProjection ( void ) { } void MdlZeroCrossings ( void ) { boolean_T
anyStateSaturated ; ZCV * _rtZCSV ; _rtZCSV = ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) ; _rtZCSV -> bqt044leqt = rtB .
mo0fhfwjbn - rtP . Constant_Value_alteb1itig ; if ( ( rtDW . j4qnczxkrf == 1
) && ( rtX . geiqvotdgd >= rtP . inti_UpperSat ) ) { _rtZCSV -> ewhwxebxoc =
0.0 ; } else { _rtZCSV -> ewhwxebxoc = rtX . geiqvotdgd - rtP . inti_UpperSat
; } if ( ( rtDW . j4qnczxkrf == 2 ) && ( rtX . geiqvotdgd <= rtP .
inti_LowerSat ) ) { _rtZCSV -> k4qoef5cni = 0.0 ; } else { _rtZCSV ->
k4qoef5cni = rtX . geiqvotdgd - rtP . inti_LowerSat ; } anyStateSaturated =
false ; if ( ( rtDW . j4qnczxkrf == 3 ) || ( rtDW . j4qnczxkrf == 4 ) ) {
anyStateSaturated = true ; } if ( anyStateSaturated ) { _rtZCSV -> nxkqgaevpl
= rtB . ml5sunf4wl ; } else { _rtZCSV -> nxkqgaevpl = 0.0 ; } _rtZCSV ->
hq4g4ipse5 = rtB . jm35sgpar2 - rtB . eafza0ignh ; _rtZCSV -> fn1a4gv4tp =
rtB . jm35sgpar2 - rtP . Constant9_Value ; _rtZCSV -> hyark1ffav = rtB .
jm35sgpar2 - rtB . mfjtrcfybp ; _rtZCSV -> nx1cmtrwmb = rtB . jm35sgpar2 -
rtB . djwy2mdgcr ; _rtZCSV -> gbmtqtlsls = rtB . mo0fhfwjbn - rtP .
Constant_Value_ox3fg1go0h ; _rtZCSV -> fbte5t1m0e = rtB . abmbri4rct - rtP .
Constant1_Value ; _rtZCSV -> bemgirumpk = rtB . abmbri4rct - rtB . gi1zeejtvl
; _rtZCSV -> aecravb3hs = rtB . ebzvvcw0uj - rtP . Saturation_UpperSat ;
_rtZCSV -> esljyrzmlw = rtB . ebzvvcw0uj - rtP . Saturation_LowerSat ;
_rtZCSV -> o14mfob1cz = rtB . kcia4oomek - rtP . Constant_Value_o5texc1pzk ;
if ( ( rtDW . cr3vas1c0t == 1 ) && ( rtX . lr2fon2uwe >= rtP .
inti_UpperSat_dal2xymi3h ) ) { _rtZCSV -> limtohtsdo = 0.0 ; } else { _rtZCSV
-> limtohtsdo = rtX . lr2fon2uwe - rtP . inti_UpperSat_dal2xymi3h ; } if ( (
rtDW . cr3vas1c0t == 2 ) && ( rtX . lr2fon2uwe <= rtP .
inti_LowerSat_plajszqohf ) ) { _rtZCSV -> csnqjhl3mu = 0.0 ; } else { _rtZCSV
-> csnqjhl3mu = rtX . lr2fon2uwe - rtP . inti_LowerSat_plajszqohf ; }
anyStateSaturated = false ; if ( ( rtDW . cr3vas1c0t == 3 ) || ( rtDW .
cr3vas1c0t == 4 ) ) { anyStateSaturated = true ; } if ( anyStateSaturated ) {
_rtZCSV -> kftxbk5pmm = rtB . btbyo2vcmz ; } else { _rtZCSV -> kftxbk5pmm =
0.0 ; } _rtZCSV -> nwalcj5gms = rtB . lgl3sevxjx - rtB . kjbniesfcu ; _rtZCSV
-> pdhvg12scp = rtB . lgl3sevxjx - rtP . Constant9_Value_jc35dhdc3v ; _rtZCSV
-> h3prldoayh = rtB . lgl3sevxjx - rtB . dltlpyqxxt ; _rtZCSV -> gjqeyfsj2x =
rtB . lgl3sevxjx - rtB . hesfhsyv0h ; _rtZCSV -> ab4lh402sw = rtB .
kcia4oomek - rtP . Constant_Value_mscbjvxnfy ; _rtZCSV -> jb2yhcno4b = rtB .
olb0grj3j3 - rtP . Constant1_Value_p0nk0e4k4t ; _rtZCSV -> fv4eegkotw = rtB .
olb0grj3j3 - rtB . mkgovfegci ; _rtZCSV -> evpb4rq3eh = rtB . bybpkn3fg3 -
rtP . Saturation_UpperSat_mtqq4gsywh ; _rtZCSV -> dbd0qhgqv4 = rtB .
bybpkn3fg3 - rtP . Saturation_LowerSat_gwhczn143q ; _rtZCSV -> n50h24fuoh =
rtB . jqky25xmle - rtP . Constant_Value_ezg4nv1jai ; if ( ( rtDW . l4pyajhrvl
== 1 ) && ( rtX . fgmli1n2fu >= rtP . inti_UpperSat_m5funkuur3 ) ) { _rtZCSV
-> jjioyrkmn0 = 0.0 ; } else { _rtZCSV -> jjioyrkmn0 = rtX . fgmli1n2fu - rtP
. inti_UpperSat_m5funkuur3 ; } if ( ( rtDW . l4pyajhrvl == 2 ) && ( rtX .
fgmli1n2fu <= rtP . inti_LowerSat_hwyc0llog5 ) ) { _rtZCSV -> inwacnnnt0 =
0.0 ; } else { _rtZCSV -> inwacnnnt0 = rtX . fgmli1n2fu - rtP .
inti_LowerSat_hwyc0llog5 ; } anyStateSaturated = false ; if ( ( rtDW .
l4pyajhrvl == 3 ) || ( rtDW . l4pyajhrvl == 4 ) ) { anyStateSaturated = true
; } if ( anyStateSaturated ) { _rtZCSV -> jokkaie0ca = rtB . aepfzat2ah ; }
else { _rtZCSV -> jokkaie0ca = 0.0 ; } _rtZCSV -> cvyhscvv1a = rtB .
poeuuptz0e - rtB . ik21zuu0w2 ; _rtZCSV -> lxzrkicv1c = rtB . poeuuptz0e -
rtP . Constant9_Value_e4pjobvupn ; _rtZCSV -> mb1gev2viv = rtB . poeuuptz0e -
rtB . dgq5far14c ; _rtZCSV -> mm3cy3skdk = rtB . poeuuptz0e - rtB .
mdkcdrc1dj ; _rtZCSV -> d55rudnyfq = rtB . jqky25xmle - rtP .
Constant_Value_i12rhgm4ll ; _rtZCSV -> mkqafvfyfz = rtB . ecaohy0st5 - rtP .
Constant1_Value_nxh5i5seoh ; _rtZCSV -> hkmvwa2w5q = rtB . ecaohy0st5 - rtB .
b4dywjx5hn ; _rtZCSV -> c5wc5exuel = rtB . adxkajg20f - rtP .
Saturation_UpperSat_mo1jv0phgx ; _rtZCSV -> a1g3zj5mxf = rtB . adxkajg20f -
rtP . Saturation_LowerSat_dggvwabw03 ; _rtZCSV -> fsu2d1koy1 = rtB .
ml5sunf4wl ; _rtZCSV -> gu2wzrl1df = rtB . ml5sunf4wl - rtP .
Constant_Value_blwrb2w0qh ; _rtZCSV -> aopqdltyuh = rtB . cb1nnepflz ;
_rtZCSV -> hxrnfhwyqp = rtB . gu3qbji4xc ; _rtZCSV -> pl2qli5qh3 = rtB .
cb1nnepflz - rtP . Constant_Value_dn32sdoil4 ; _rtZCSV -> ew2p2am1jo = rtB .
aepfzat2ah ; _rtZCSV -> htrknilzxi = rtB . aepfzat2ah - rtP .
Constant_Value_mexjddav50 ; _rtZCSV -> ip53nzovbl = rtB . ffql2fnkid ;
_rtZCSV -> pucajiwng3 = rtB . oaqch21uel ; _rtZCSV -> kv0mpvlxjk = rtB .
ffql2fnkid - rtP . Constant_Value_ce0ilwr0v4 ; _rtZCSV -> hcjekczuu2 = rtB .
btbyo2vcmz ; _rtZCSV -> hxi5trliim = rtB . btbyo2vcmz - rtP .
Constant_Value_fk15mpo45m ; _rtZCSV -> bwzvkocqq1 = rtB . gre3fyyedb ;
_rtZCSV -> dzuyaprajo = rtB . mc3kmonqyw ; _rtZCSV -> opg0fsvdib = rtB .
gre3fyyedb - rtP . Constant_Value_cvgmtz023a ; } void MdlTerminate ( void ) {
rt_FREE ( rtDW . ixzxf22pdy . RSimInfoPtr ) ; { SimStruct * rts =
ssGetSFunction ( rtS , 0 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( rtS , 1 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( rtS , 2 ) ; sfcnTerminate ( rts ) ; } { if (
rt_slioCatalogue ( ) != ( NULL ) ) { void * * slioCatalogueAddr =
rt_slioCatalogueAddr ( ) ; rtwCreateSigstreamSlioClient (
rt_GetOSigstreamManager ( ) , rtwGetPointerFromUniquePtr ( rt_slioCatalogue (
) ) ) ; rtwSaveDatasetsToMatFile ( rtwGetPointerFromUniquePtr (
rt_slioCatalogue ( ) ) , rt_GetMatSigstreamLoggingFileName ( ) ) ;
rtwOSigstreamManagerDestroyInstance ( rt_GetOSigstreamManager ( ) ) ;
rtwTerminateSlioCatalogue ( slioCatalogueAddr ) ; * slioCatalogueAddr = (
NULL ) ; } } } void MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS ,
18 ) ; ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ;
ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ;
ssSetNumSampleTimes ( rtS , 2 ) ; ssSetNumBlocks ( rtS , 427 ) ;
ssSetNumBlockIO ( rtS , 197 ) ; ssSetNumBlockParams ( rtS , 7975 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetSampleTime ( rtS , 1 , 0.0 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 1.0 ) ; } void raccel_set_checksum ( SimStruct *
rtS ) { ssSetChecksumVal ( rtS , 0 , 562528118U ) ; ssSetChecksumVal ( rtS ,
1 , 4015142401U ) ; ssSetChecksumVal ( rtS , 2 , 125993725U ) ;
ssSetChecksumVal ( rtS , 3 , 1970498346U ) ; } SimStruct *
raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo ; ( void )
memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void ) memset ( (
char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ; ssSetMdlInfoPtr (
rtS , & mdlInfo ) ; { static time_T mdlPeriod [ NSAMPLE_TIMES ] ; static
time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T mdlTaskTimes [
NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ; static int_T
mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T mdlTNextWasAdjustedPtr [
NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits [ NSAMPLE_TIMES *
NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [ NSAMPLE_TIMES ] ; {
int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) { mdlPeriod [ i ] = 0.0 ;
mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ; mdlTsMap [ i ] = i ;
mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS , & mdlPeriod [ 0 ] )
; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr (
rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , & mdlTaskTimes [ 0 ] ) ;
ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ; ssSetTNextWasAdjustedPtr
( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ; ssSetPerTaskSampleHitsPtr ( rtS ,
& mdlPerTaskSampleHits [ 0 ] ) ; ssSetTimeOfNextSampleHitPtr ( rtS , &
mdlTimeOfNextSampleHit [ 0 ] ) ; } ssSetSolverMode ( rtS ,
SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS , ( ( void * ) & rtB ) ) ;
( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof ( B ) ) ; { rtB .
jru2iqrfmm = 0.0 ; rtB . gu5rsica4y = 0.0 ; rtB . eafza0ignh = 0.0 ; rtB .
mo0fhfwjbn = 0.0 ; rtB . hbrgffmmwb = 0.0 ; rtB . ffdlej0esm = 0.0 ; rtB .
iu235cbed5 = 0.0 ; rtB . jm35sgpar2 = 0.0 ; rtB . o4aync4hqi = 0.0 ; rtB .
a4eiiet2o0 = 0.0 ; rtB . p4h4wunzca = 0.0 ; rtB . lpwludxfnb = 0.0 ; rtB .
pmxqn1j2n3 = 0.0 ; rtB . mfjtrcfybp = 0.0 ; rtB . djwy2mdgcr = 0.0 ; rtB .
bn5kz230z1 = 0.0 ; rtB . ksvnvluruk = 0.0 ; rtB . b4dvnbx2z0 = 0.0 ; rtB .
losq44zfsw = 0.0 ; rtB . ia1kg5fvtb = 0.0 ; rtB . on5jb3go3s = 0.0 ; rtB .
fgkxbpykg1 = 0.0 ; rtB . cb1nnepflz = 0.0 ; rtB . msdjbx4ftv = 0.0 ; rtB .
kypwxy50kw = 0.0 ; rtB . bb25sco2fm = 0.0 ; rtB . abmbri4rct = 0.0 ; rtB .
gi1zeejtvl = 0.0 ; rtB . brqcacx4dy = 0.0 ; rtB . mzsf40mopc = 0.0 ; rtB .
ltqlujcfbs = 0.0 ; rtB . ml5sunf4wl = 0.0 ; rtB . kgwpzskznu = 0.0 ; rtB .
cu3rpzq1ir = 0.0 ; rtB . ebzvvcw0uj = 0.0 ; rtB . nvl5qjckkv = 0.0 ; rtB .
p4pflkgeyq = 0.0 ; rtB . ded05j4tle = 0.0 ; rtB . kjbniesfcu = 0.0 ; rtB .
kcia4oomek = 0.0 ; rtB . f3yztw02af = 0.0 ; rtB . ebadym5xni = 0.0 ; rtB .
ascuylmfea = 0.0 ; rtB . lgl3sevxjx = 0.0 ; rtB . i2cij1nsan = 0.0 ; rtB .
cy2mdsactk = 0.0 ; rtB . hrgapvp0ps = 0.0 ; rtB . gx3vfbmrpy = 0.0 ; rtB .
opjh3hy4jh = 0.0 ; rtB . dltlpyqxxt = 0.0 ; rtB . hesfhsyv0h = 0.0 ; rtB .
dz2enm0ww0 = 0.0 ; rtB . j5n5fyudax = 0.0 ; rtB . iirqhbasaw = 0.0 ; rtB .
poiu0irxc0 = 0.0 ; rtB . fzd1h5apha = 0.0 ; rtB . m12jzkvpeg = 0.0 ; rtB .
nwx1m5flyz = 0.0 ; rtB . gre3fyyedb = 0.0 ; rtB . ei5r5a5pav = 0.0 ; rtB .
ommpg3cgpv = 0.0 ; rtB . i1k1tidl2o = 0.0 ; rtB . olb0grj3j3 = 0.0 ; rtB .
mkgovfegci = 0.0 ; rtB . dfjf12bep4 = 0.0 ; rtB . oben2eao5k = 0.0 ; rtB .
btbyo2vcmz = 0.0 ; rtB . mqfk5v4diy = 0.0 ; rtB . bfx2u5xgpq = 0.0 ; rtB .
bybpkn3fg3 = 0.0 ; rtB . gqdjkmiehk = 0.0 ; rtB . mfmapc1zif = 0.0 ; rtB .
m4i5mlkre0 = 0.0 ; rtB . ik21zuu0w2 = 0.0 ; rtB . jqky25xmle = 0.0 ; rtB .
fmkuq1m3bb = 0.0 ; rtB . brt0odp1ig = 0.0 ; rtB . hwk4furfbr = 0.0 ; rtB .
poeuuptz0e = 0.0 ; rtB . kyxi4xk5b1 = 0.0 ; rtB . lad2rbhq0d = 0.0 ; rtB .
n0ykw2xnss = 0.0 ; rtB . j2m1rxr1a0 = 0.0 ; rtB . nisapdp2vu = 0.0 ; rtB .
dgq5far14c = 0.0 ; rtB . mdkcdrc1dj = 0.0 ; rtB . g3fahebeoh = 0.0 ; rtB .
dg1ivic2cv = 0.0 ; rtB . o2w0cdwc0f = 0.0 ; rtB . foxxmgfp1n = 0.0 ; rtB .
guy2kz5ncd = 0.0 ; rtB . fzutsooicn = 0.0 ; rtB . i0dlbs1b2l = 0.0 ; rtB .
ffql2fnkid = 0.0 ; rtB . bzhvuobncb = 0.0 ; rtB . g4hw1qgbdv = 0.0 ; rtB .
prq1vlt5vx = 0.0 ; rtB . ecaohy0st5 = 0.0 ; rtB . b4dywjx5hn = 0.0 ; rtB .
offgvp1su2 = 0.0 ; rtB . mj03tas4fg = 0.0 ; rtB . aepfzat2ah = 0.0 ; rtB .
bb0v5z1gyy = 0.0 ; rtB . awto1smfy3 = 0.0 ; rtB . adxkajg20f = 0.0 ; rtB .
p5iut1x42c = 0.0 ; rtB . bb0be3gnia = 0.0 ; rtB . hqpcpdn5qa = 0.0 ; rtB .
jbhxgjw5cy = 0.0 ; rtB . nf3rdcvax5 = 0.0 ; rtB . j4gfvflild = 0.0 ; rtB .
lzetnopoo3 = 0.0 ; rtB . jce4jecbbp = 0.0 ; rtB . dwb42stmvv = 0.0 ; rtB .
gu3qbji4xc = 0.0 ; rtB . pgudi1oete = 0.0 ; rtB . fmw5kmtm1r = 0.0 ; rtB .
bwvje3ihiw = 0.0 ; rtB . m0yglvlyme = 0.0 ; rtB . pvwijbyxkr = 0.0 ; rtB .
aesu3l5yyk = 0.0 ; rtB . e3cqouyy3w = 0.0 ; rtB . dcqdhsbevr = 0.0 ; rtB .
o3lepigeif = 0.0 ; rtB . d5351zjf4x = 0.0 ; rtB . eoju45gqpq = 0.0 ; rtB .
dfbrmr4pqz = 0.0 ; rtB . dabeiiy4xg = 0.0 ; rtB . koz3cqzv1c = 0.0 ; rtB .
etpdoa2xuk = 0.0 ; rtB . jaquvxw41i = 0.0 ; rtB . oaqch21uel = 0.0 ; rtB .
lvkqstzrdf = 0.0 ; rtB . lmk5yid3hu = 0.0 ; rtB . grozn2da0l = 0.0 ; rtB .
dzqkvxhkd1 = 0.0 ; rtB . n5c0k4fbwb = 0.0 ; rtB . lwlovbyzf2 = 0.0 ; rtB .
n0r3f03erl = 0.0 ; rtB . e0dl0dglhu = 0.0 ; rtB . j3xdv1bkdg = 0.0 ; rtB .
maqw5opry0 = 0.0 ; rtB . acjy0wcx33 = 0.0 ; rtB . ffgdskx2hu = 0.0 ; rtB .
brdas51kj1 = 0.0 ; rtB . nfweyj1qvq = 0.0 ; rtB . h2cdsbamjg = 0.0 ; rtB .
njpjxwiwga = 0.0 ; rtB . mc3kmonqyw = 0.0 ; rtB . eajyu4e2gg = 0.0 ; rtB .
csv1q2rmqm = 0.0 ; rtB . hap1ivasmg = 0.0 ; rtB . o0zujw030w = 0.0 ; rtB .
hrenjgvsp2 = 0.0 ; rtB . agnwtijpiy = 0.0 ; rtB . oepc1i4s5o = 0.0 ; rtB .
gnxuzeutps = 0.0 ; rtB . hoa4ffors0 = 0.0 ; rtB . p5bxowhy3u = 0.0 ; rtB .
dl2oj2hwn5 = 0.0 ; rtB . btonwzxytu = 0.0 ; rtB . g03b5ho0xb [ 0 ] = 0.0 ;
rtB . g03b5ho0xb [ 1 ] = 0.0 ; rtB . g03b5ho0xb [ 2 ] = 0.0 ; rtB .
g03b5ho0xb [ 3 ] = 0.0 ; rtB . egi1glv2iz [ 0 ] = 0.0 ; rtB . egi1glv2iz [ 1
] = 0.0 ; rtB . egi1glv2iz [ 2 ] = 0.0 ; rtB . egi1glv2iz [ 3 ] = 0.0 ; rtB .
aufyna3xwp [ 0 ] = 0.0 ; rtB . aufyna3xwp [ 1 ] = 0.0 ; rtB . aufyna3xwp [ 2
] = 0.0 ; rtB . aufyna3xwp [ 3 ] = 0.0 ; rtB . dpzsk0fv2e [ 0 ] = 0.0 ; rtB .
dpzsk0fv2e [ 1 ] = 0.0 ; rtB . dpzsk0fv2e [ 2 ] = 0.0 ; rtB . dpzsk0fv2e [ 3
] = 0.0 ; rtB . oiiyyqltbq = 0.0 ; rtB . pjy23u5hnz = 0.0 ; rtB . b3jprbo2ch
= 0.0 ; rtB . psc1bdwm0e [ 0 ] = 0.0 ; rtB . psc1bdwm0e [ 1 ] = 0.0 ; rtB .
psc1bdwm0e [ 2 ] = 0.0 ; rtB . psc1bdwm0e [ 3 ] = 0.0 ; rtB . lwryrfr1np [ 0
] = 0.0 ; rtB . lwryrfr1np [ 1 ] = 0.0 ; rtB . lwryrfr1np [ 2 ] = 0.0 ; rtB .
lwryrfr1np [ 3 ] = 0.0 ; rtB . dehp52jxod [ 0 ] = 0.0 ; rtB . dehp52jxod [ 1
] = 0.0 ; rtB . dehp52jxod [ 2 ] = 0.0 ; rtB . dehp52jxod [ 3 ] = 0.0 ; rtB .
dhz0gnwoz2 [ 0 ] = 0.0 ; rtB . dhz0gnwoz2 [ 1 ] = 0.0 ; rtB . dhz0gnwoz2 [ 2
] = 0.0 ; rtB . dhz0gnwoz2 [ 3 ] = 0.0 ; rtB . chxlnefiu2 = 0.0 ; rtB .
gucbgg34uu = 0.0 ; rtB . jl0as1i1kv = 0.0 ; rtB . gayccjz0g2 [ 0 ] = 0.0 ;
rtB . gayccjz0g2 [ 1 ] = 0.0 ; rtB . gayccjz0g2 [ 2 ] = 0.0 ; rtB .
gayccjz0g2 [ 3 ] = 0.0 ; rtB . cgcsvraqod [ 0 ] = 0.0 ; rtB . cgcsvraqod [ 1
] = 0.0 ; rtB . cgcsvraqod [ 2 ] = 0.0 ; rtB . cgcsvraqod [ 3 ] = 0.0 ; rtB .
amabyxe2q5 [ 0 ] = 0.0 ; rtB . amabyxe2q5 [ 1 ] = 0.0 ; rtB . amabyxe2q5 [ 2
] = 0.0 ; rtB . amabyxe2q5 [ 3 ] = 0.0 ; rtB . hp4pbsppeu [ 0 ] = 0.0 ; rtB .
hp4pbsppeu [ 1 ] = 0.0 ; rtB . hp4pbsppeu [ 2 ] = 0.0 ; rtB . hp4pbsppeu [ 3
] = 0.0 ; } } ssSetDefaultParam ( rtS , ( real_T * ) & rtP ) ; { real_T * x =
( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ; ( void ) memset ( ( void *
) x , 0 , sizeof ( X ) ) ; } { void * dwork = ( void * ) & rtDW ;
ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork , 0 , sizeof ( DW )
) ; rtDW . jflxrokyki = 0.0 ; rtDW . gkgewmrthj = 0.0 ; rtDW . byrrqwbwuv =
0.0 ; rtDW . ko2pp0cfqy = 0.0 ; rtDW . knyijtosqg = 0.0 ; rtDW . ft2nyeqcg1 =
0.0 ; rtDW . my4ttjz2fk [ 0 ] = 0.0 ; rtDW . my4ttjz2fk [ 1 ] = 0.0 ; rtDW .
an5tlpibsu [ 0 ] = 0.0 ; rtDW . an5tlpibsu [ 1 ] = 0.0 ; rtDW . cnb4tdv1fb [
0 ] = 0.0 ; rtDW . cnb4tdv1fb [ 1 ] = 0.0 ; } { static DataTypeTransInfo
dtInfo ; ( void ) memset ( ( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ;
ssSetModelMappingInfo ( rtS , & dtInfo ) ; dtInfo . numDataTypes = 14 ;
dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = &
rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = & rtBTransTable ; dtInfo .
PTransTable = & rtPTransTable ; } Load_Simulation_07_InitializeDataMapInfo (
) ; ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS )
; ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"Load_Simulation_07" ) ; ssSetPath ( rtS , "Load_Simulation_07" ) ;
ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal ( rtS , 3600.0 ) ; { static
RTWLogInfo rt_DataLoggingInfo ; rt_DataLoggingInfo . loggingInterval = NULL ;
ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ; } { { static int_T
rt_LoggedStateWidths [ ] = { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
1 , 1 , 1 , 1 , 1 , 1 } ; static int_T rt_LoggedStateNumDimensions [ ] = { 1
, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 } ;
static int_T rt_LoggedStateDimensions [ ] = { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 } ; static boolean_T
rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 } ; static BuiltInDTypeId rt_LoggedStateDataTypeIds [
] = { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ;
static int_T rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static const char_T *
rt_LoggedStateLabels [ ] = { "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" }
; static const char_T * rt_LoggedStateBlockNames [ ] = {
"Load_Simulation_07/12 volts, 10 Ah\n Lead Acid battery /Model/Current filter"
, "Load_Simulation_07/12 volts, 10 Ah\n Lead Acid battery /Model/int(i)" ,
 "Load_Simulation_07/12 volts, 10 Ah\n Lead Acid battery /Model/Thermal Model/Transfer Fcn\n(with initial outputs)/State Space"
,
"Load_Simulation_07/12 volts, 10 Ah\n Lead Acid battery /Model/Exp/Integrator2"
,
"Load_Simulation_07/12 volts, 10 Ah\n Lead Acid battery /Model/Current filter1"
, "Load_Simulation_07/12v, 10Ah \nLiFePO4 /Model/Current filter" ,
"Load_Simulation_07/12v, 10Ah \nLiFePO4 /Model/int(i)" ,
 "Load_Simulation_07/12v, 10Ah \nLiFePO4 /Model/Thermal Model/Transfer Fcn\n(with initial outputs)/State Space"
, "Load_Simulation_07/12v, 10Ah \nLiFePO4 /Model/Exp/Integrator2" ,
"Load_Simulation_07/12v, 10Ah \nLiFePO4 /Model/Current filter1" ,
"Load_Simulation_07/12 volts, 10 Ah\n Ni-MH battery/Model/Current filter" ,
"Load_Simulation_07/12 volts, 10 Ah\n Ni-MH battery/Model/int(i)" ,
 "Load_Simulation_07/12 volts, 10 Ah\n Ni-MH battery/Model/Thermal Model/Transfer Fcn\n(with initial outputs)/State Space"
, "Load_Simulation_07/12 volts, 10 Ah\n Ni-MH battery/Model/Exp/Integrator2"
, "Load_Simulation_07/12 volts, 10 Ah\n Ni-MH battery/Model/Current filter1"
,
 "Load_Simulation_07/12 volts, 10 Ah\n Lead Acid battery /Model/Thermal Model/Transfer Fcn1"
,
 "Load_Simulation_07/12 volts, 10 Ah\n Ni-MH battery/Model/Thermal Model/Transfer Fcn1"
, "Load_Simulation_07/12v, 10Ah \nLiFePO4 /Model/Thermal Model/Transfer Fcn1"
} ; static const char_T * rt_LoggedStateNames [ ] = { "" , "" , "" , "" , ""
, "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" } ; static
boolean_T rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static RTWLogDataTypeConvert
rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 ,
1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } ,
{ 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static
RTWLogSignalInfo rt_LoggedStateSignalInfo = { 18 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , { rt_LoggedStateLabels } , ( NULL )
, ( NULL ) , ( NULL ) , { rt_LoggedStateBlockNames } , { rt_LoggedStateNames
} , rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert } ; static void *
rt_LoggedStateSignalPtrs [ 18 ] ; rtliSetLogXSignalPtrs ( ssGetRTWLogInfo (
rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . awyk3jkmpp ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . geiqvotdgd ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . gjrr5rcl1i ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtX . emndqevlhi ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) & rtX . oobd5yyumt ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) & rtX . gqep4i1he1 ;
rt_LoggedStateSignalPtrs [ 6 ] = ( void * ) & rtX . lr2fon2uwe ;
rt_LoggedStateSignalPtrs [ 7 ] = ( void * ) & rtX . plzaosk005 ;
rt_LoggedStateSignalPtrs [ 8 ] = ( void * ) & rtX . femnmi0kft ;
rt_LoggedStateSignalPtrs [ 9 ] = ( void * ) & rtX . czasr4omxo ;
rt_LoggedStateSignalPtrs [ 10 ] = ( void * ) & rtX . cdhjf34fys ;
rt_LoggedStateSignalPtrs [ 11 ] = ( void * ) & rtX . fgmli1n2fu ;
rt_LoggedStateSignalPtrs [ 12 ] = ( void * ) & rtX . drcq2lkoq2 ;
rt_LoggedStateSignalPtrs [ 13 ] = ( void * ) & rtX . cw5koqcmmd ;
rt_LoggedStateSignalPtrs [ 14 ] = ( void * ) & rtX . jaymf1z1oc ;
rt_LoggedStateSignalPtrs [ 15 ] = ( void * ) & rtX . mlhiasidwv ;
rt_LoggedStateSignalPtrs [ 16 ] = ( void * ) & rtX . lvhyb51zfr ;
rt_LoggedStateSignalPtrs [ 17 ] = ( void * ) & rtX . ic4xkivobu ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "tmp_raccel_xout" ) ; rtliSetLogXFinal (
ssGetRTWLogInfo ( rtS ) , "xFinal" ) ; rtliSetLogVarNameModifier (
ssGetRTWLogInfo ( rtS ) , "none" ) ; rtliSetLogFormat ( ssGetRTWLogInfo ( rtS
) , 2 ) ; rtliSetLogMaxRows ( ssGetRTWLogInfo ( rtS ) , 1000 ) ;
rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS ) , 1 ) ; rtliSetLogY (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogYSignalInfo ( ssGetRTWLogInfo (
rtS ) , ( NULL ) ) ; rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL
) ) ; } { static struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS ,
& statesInfo2 ) ; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 18 ] ; static
real_T absTol [ 18 ] = { 1.0000000000000001E-7 , 1.0000000000000001E-7 ,
1.0000000000000001E-7 , 1.0000000000000001E-7 , 1.0000000000000001E-7 ,
1.0000000000000001E-7 , 1.0000000000000001E-7 , 1.0000000000000001E-7 ,
1.0000000000000001E-7 , 1.0000000000000001E-7 , 1.0000000000000001E-7 ,
1.0000000000000001E-7 , 1.0000000000000001E-7 , 1.0000000000000001E-7 ,
1.0000000000000001E-7 , 1.0000000000000001E-7 , 1.0000000000000001E-7 ,
1.0000000000000001E-7 } ; static uint8_T absTolControl [ 18 ] = { 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
} ; static uint8_T zcAttributes [ 57 ] = { ( ZC_EVENT_ALL ) , ( 0xc0 |
ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_DN ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( 0xc0 |
ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_DN ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( 0xc0 |
ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_DN ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) } ; static ssNonContDerivSigInfo nonContDerivSigInfo [ 42 ] =
{ { 1 * sizeof ( real_T ) , ( char * ) ( & rtB . csv1q2rmqm ) , ( NULL ) } ,
{ 1 * sizeof ( real_T ) , ( char * ) ( & rtB . maqw5opry0 ) , ( NULL ) } , {
1 * sizeof ( real_T ) , ( char * ) ( & rtB . lmk5yid3hu ) , ( NULL ) } , { 1
* sizeof ( real_T ) , ( char * ) ( & rtB . d5351zjf4x ) , ( NULL ) } , { 1 *
sizeof ( real_T ) , ( char * ) ( & rtB . fmw5kmtm1r ) , ( NULL ) } , { 1 *
sizeof ( real_T ) , ( char * ) ( & rtB . hqpcpdn5qa ) , ( NULL ) } , { 1 *
sizeof ( boolean_T ) , ( char * ) ( & rtB . h54wfmqlk0 ) , ( NULL ) } , { 1 *
sizeof ( boolean_T ) , ( char * ) ( & rtB . ewa4jwoiei ) , ( NULL ) } , { 1 *
sizeof ( real_T ) , ( char * ) ( & rtB . dg1ivic2cv ) , ( NULL ) } , { 1 *
sizeof ( boolean_T ) , ( char * ) ( & rtB . b1tb4rlksj ) , ( NULL ) } , { 1 *
sizeof ( real_T ) , ( char * ) ( & rtB . mdkcdrc1dj ) , ( NULL ) } , { 1 *
sizeof ( boolean_T ) , ( char * ) ( & rtB . f142q2bocw ) , ( NULL ) } , { 1 *
sizeof ( real_T ) , ( char * ) ( & rtB . dgq5far14c ) , ( NULL ) } , { 1 *
sizeof ( boolean_T ) , ( char * ) ( & rtB . kjxguscvc3 ) , ( NULL ) } , { 1 *
sizeof ( boolean_T ) , ( char * ) ( & rtB . druqytbldp ) , ( NULL ) } , { 1 *
sizeof ( real_T ) , ( char * ) ( & rtB . fmkuq1m3bb ) , ( NULL ) } , { 1 *
sizeof ( real_T ) , ( char * ) ( & rtB . ik21zuu0w2 ) , ( NULL ) } , { 1 *
sizeof ( real_T ) , ( char * ) ( & rtB . m4i5mlkre0 ) , ( NULL ) } , { 1 *
sizeof ( boolean_T ) , ( char * ) ( & rtB . nj4n1mxjv0 ) , ( NULL ) } , { 1 *
sizeof ( boolean_T ) , ( char * ) ( & rtB . hvjsipjvee ) , ( NULL ) } , { 1 *
sizeof ( real_T ) , ( char * ) ( & rtB . j5n5fyudax ) , ( NULL ) } , { 1 *
sizeof ( boolean_T ) , ( char * ) ( & rtB . eqm015gtbx ) , ( NULL ) } , { 1 *
sizeof ( real_T ) , ( char * ) ( & rtB . hesfhsyv0h ) , ( NULL ) } , { 1 *
sizeof ( boolean_T ) , ( char * ) ( & rtB . kvprg4ppnw ) , ( NULL ) } , { 1 *
sizeof ( real_T ) , ( char * ) ( & rtB . dltlpyqxxt ) , ( NULL ) } , { 1 *
sizeof ( boolean_T ) , ( char * ) ( & rtB . pm3wjc2bv1 ) , ( NULL ) } , { 1 *
sizeof ( boolean_T ) , ( char * ) ( & rtB . c33k25rpdh ) , ( NULL ) } , { 1 *
sizeof ( real_T ) , ( char * ) ( & rtB . f3yztw02af ) , ( NULL ) } , { 1 *
sizeof ( real_T ) , ( char * ) ( & rtB . kjbniesfcu ) , ( NULL ) } , { 1 *
sizeof ( real_T ) , ( char * ) ( & rtB . ded05j4tle ) , ( NULL ) } , { 1 *
sizeof ( boolean_T ) , ( char * ) ( & rtB . bbvpjaqjcj ) , ( NULL ) } , { 1 *
sizeof ( boolean_T ) , ( char * ) ( & rtB . l5k4v4pkri ) , ( NULL ) } , { 1 *
sizeof ( real_T ) , ( char * ) ( & rtB . ksvnvluruk ) , ( NULL ) } , { 1 *
sizeof ( boolean_T ) , ( char * ) ( & rtB . iu45wsrpul ) , ( NULL ) } , { 1 *
sizeof ( real_T ) , ( char * ) ( & rtB . djwy2mdgcr ) , ( NULL ) } , { 1 *
sizeof ( boolean_T ) , ( char * ) ( & rtB . h5yixci3b5 ) , ( NULL ) } , { 1 *
sizeof ( real_T ) , ( char * ) ( & rtB . mfjtrcfybp ) , ( NULL ) } , { 1 *
sizeof ( boolean_T ) , ( char * ) ( & rtB . gibfnm5yif ) , ( NULL ) } , { 1 *
sizeof ( boolean_T ) , ( char * ) ( & rtB . p3hqh0p1ve ) , ( NULL ) } , { 1 *
sizeof ( real_T ) , ( char * ) ( & rtB . hbrgffmmwb ) , ( NULL ) } , { 1 *
sizeof ( real_T ) , ( char * ) ( & rtB . eafza0ignh ) , ( NULL ) } , { 1 *
sizeof ( real_T ) , ( char * ) ( & rtB . gu5rsica4y ) , ( NULL ) } } ;
ssSetSolverRelTol ( rtS , 0.0001 ) ; ssSetStepSize ( rtS , 0.0 ) ;
ssSetMinStepSize ( rtS , 0.0 ) ; ssSetMaxNumMinSteps ( rtS , - 1 ) ;
ssSetMinStepViolatedError ( rtS , 0 ) ; ssSetMaxStepSize ( rtS , 0.1 ) ;
ssSetSolverMaxOrder ( rtS , - 1 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ;
ssSetOutputTimes ( rtS , ( NULL ) ) ; ssSetNumOutputTimes ( rtS , 0 ) ;
ssSetOutputTimesOnly ( rtS , 0 ) ; ssSetOutputTimesIndex ( rtS , 0 ) ;
ssSetZCCacheNeedsReset ( rtS , 1 ) ; ssSetDerivCacheNeedsReset ( rtS , 0 ) ;
ssSetNumNonContDerivSigInfos ( rtS , 42 ) ; ssSetNonContDerivSigInfos ( rtS ,
nonContDerivSigInfo ) ; ssSetSolverInfo ( rtS , & slvrInfo ) ;
ssSetSolverName ( rtS , "ode23tb" ) ; ssSetVariableStepSolver ( rtS , 1 ) ;
ssSetSolverConsistencyChecking ( rtS , 0 ) ; ssSetSolverAdaptiveZcDetection (
rtS , 0 ) ; ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetAbsTolVector (
rtS , absTol ) ; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetSolverStateProjection ( rtS , 0 ) ; ssSetSolverMassMatrixType ( rtS , (
ssMatrixType ) 0 ) ; ssSetSolverMassMatrixNzMax ( rtS , 0 ) ;
ssSetModelOutputs ( rtS , MdlOutputs ) ; ssSetModelLogData ( rtS ,
rt_UpdateTXYLogVars ) ; ssSetModelLogDataIfInInterval ( rtS ,
rt_UpdateTXXFYLogVars ) ; ssSetModelUpdate ( rtS , MdlUpdate ) ;
ssSetModelDerivatives ( rtS , MdlDerivatives ) ; ssSetSolverZcSignalAttrib (
rtS , zcAttributes ) ; ssSetSolverNumZcSignals ( rtS , 57 ) ;
ssSetModelZeroCrossings ( rtS , MdlZeroCrossings ) ;
ssSetSolverConsecutiveZCsStepRelTol ( rtS , 2.8421709430404007E-13 ) ;
ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ; ssSetSolverConsecutiveZCsError
( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic ( rtS , 1 ) ;
ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ; ssSetSolverMaxConsecutiveMinStep
( rtS , 1 ) ; ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid (
rtS , INT_MIN ) ; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset (
rtS ) ; ssSetNumNonsampledZCs ( rtS , 54 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; } {
ZCSigState * zc = ( ZCSigState * ) & rtPrevZCX ; ssSetPrevZCSigState ( rtS ,
zc ) ; } { rtPrevZCX . oz2emx0tx4 = UNINITIALIZED_ZCSIG ; rtPrevZCX .
g2jgodrbhp = UNINITIALIZED_ZCSIG ; rtPrevZCX . ivgw3hbjew =
UNINITIALIZED_ZCSIG ; } ssSetChecksumVal ( rtS , 0 , 562528118U ) ;
ssSetChecksumVal ( rtS , 1 , 4015142401U ) ; ssSetChecksumVal ( rtS , 2 ,
125993725U ) ; ssSetChecksumVal ( rtS , 3 , 1970498346U ) ; { static const
sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo
rt_ExtModeInfo ; static const sysRanDType * systemRan [ 35 ] ;
gblRTWExtModeInfo = & rt_ExtModeInfo ; ssSetRTWExtModeInfo ( rtS , &
rt_ExtModeInfo ) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo ,
systemRan ) ; systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = &
rtAlwaysEnabled ; systemRan [ 2 ] = & rtAlwaysEnabled ; systemRan [ 3 ] = &
rtAlwaysEnabled ; systemRan [ 4 ] = & rtAlwaysEnabled ; systemRan [ 5 ] = &
rtAlwaysEnabled ; systemRan [ 6 ] = & rtAlwaysEnabled ; systemRan [ 7 ] = &
rtAlwaysEnabled ; systemRan [ 8 ] = & rtAlwaysEnabled ; systemRan [ 9 ] = &
rtAlwaysEnabled ; systemRan [ 10 ] = & rtAlwaysEnabled ; systemRan [ 11 ] = &
rtAlwaysEnabled ; systemRan [ 12 ] = & rtAlwaysEnabled ; systemRan [ 13 ] = &
rtAlwaysEnabled ; systemRan [ 14 ] = & rtAlwaysEnabled ; systemRan [ 15 ] = &
rtAlwaysEnabled ; systemRan [ 16 ] = & rtAlwaysEnabled ; systemRan [ 17 ] = &
rtAlwaysEnabled ; systemRan [ 18 ] = & rtAlwaysEnabled ; systemRan [ 19 ] = &
rtAlwaysEnabled ; systemRan [ 20 ] = & rtAlwaysEnabled ; systemRan [ 21 ] = &
rtAlwaysEnabled ; systemRan [ 22 ] = & rtAlwaysEnabled ; systemRan [ 23 ] = &
rtAlwaysEnabled ; systemRan [ 24 ] = & rtAlwaysEnabled ; systemRan [ 25 ] = &
rtAlwaysEnabled ; systemRan [ 26 ] = & rtAlwaysEnabled ; systemRan [ 27 ] = &
rtAlwaysEnabled ; systemRan [ 28 ] = & rtAlwaysEnabled ; systemRan [ 29 ] = &
rtAlwaysEnabled ; systemRan [ 30 ] = & rtAlwaysEnabled ; systemRan [ 31 ] = &
rtAlwaysEnabled ; systemRan [ 32 ] = & rtAlwaysEnabled ; systemRan [ 33 ] = &
rtAlwaysEnabled ; systemRan [ 34 ] = & rtAlwaysEnabled ;
rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) , &
ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo (
rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS )
, ssGetTPtr ( rtS ) ) ; } rtP . Saturation3_LowerSat = rtMinusInf ; rtP .
inti_LowerSat = rtMinusInf ; rtP . Saturation3_LowerSat_ikhjztqrap =
rtMinusInf ; rtP . inti_LowerSat_plajszqohf = rtMinusInf ; rtP .
Saturation3_LowerSat_b5p1gj4cuc = rtMinusInf ; rtP . inti_LowerSat_hwyc0llog5
= rtMinusInf ; ssSetNumSFunctions ( rtS , 3 ) ; { static SimStruct
childSFunctions [ 3 ] ; static SimStruct * childSFunctionPtrs [ 3 ] ; ( void
) memset ( ( void * ) & childSFunctions [ 0 ] , 0 , sizeof ( childSFunctions
) ) ; ssSetSFunctions ( rtS , & childSFunctionPtrs [ 0 ] ) ; ssSetSFunction (
rtS , 0 , & childSFunctions [ 0 ] ) ; ssSetSFunction ( rtS , 1 , &
childSFunctions [ 1 ] ) ; ssSetSFunction ( rtS , 2 , & childSFunctions [ 2 ]
) ; { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ; static time_T sfcnPeriod
[ 1 ] ; static time_T sfcnOffset [ 1 ] ; static int_T sfcnTsMap [ 1 ] ; (
void ) memset ( ( void * ) sfcnPeriod , 0 , sizeof ( time_T ) * 1 ) ; ( void
) memset ( ( void * ) sfcnOffset , 0 , sizeof ( time_T ) * 1 ) ;
ssSetSampleTimePtr ( rts , & sfcnPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rts ,
& sfcnOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr ( rts , sfcnTsMap ) ;
ssSetMdlInfoPtr ( rts , ssGetMdlInfoPtr ( rtS ) ) ; { static struct
_ssSFcnModelMethods2 methods2 ; ssSetModelMethods2 ( rts , & methods2 ) ; } {
static struct _ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 ( rts , &
methods3 ) ; } { static struct _ssSFcnModelMethods4 methods4 ;
ssSetModelMethods4 ( rts , & methods4 ) ; } { static struct _ssStatesInfo2
statesInfo2 ; static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetStatesInfo2 ( rts , & statesInfo2 ) ; ssSetPeriodicStatesInfo ( rts , &
periodicStatesInfo ) ; } { static struct _ssPortInputs inputPortInfo [ 1 ] ;
_ssSetNumInputPorts ( rts , 1 ) ; ssSetPortInfoForInputs ( rts , &
inputPortInfo [ 0 ] ) ; { static real_T const * sfcnUPtrs [ 2 ] ; sfcnUPtrs [
0 ] = & rtB . brqcacx4dy ; sfcnUPtrs [ 1 ] = & rtB . mzsf40mopc ;
ssSetInputPortSignalPtrs ( rts , 0 , ( InputPtrsType ) & sfcnUPtrs [ 0 ] ) ;
_ssSetInputPortNumDimensions ( rts , 0 , 1 ) ; ssSetInputPortWidth ( rts , 0
, 2 ) ; } } { static struct _ssPortOutputs outputPortInfo [ 1 ] ;
ssSetPortInfoForOutputs ( rts , & outputPortInfo [ 0 ] ) ;
_ssSetNumOutputPorts ( rts , 1 ) ; { _ssSetOutputPortNumDimensions ( rts , 0
, 1 ) ; ssSetOutputPortWidth ( rts , 0 , 1 ) ; ssSetOutputPortSignal ( rts ,
0 , ( ( real_T * ) & rtB . ltqlujcfbs ) ) ; } } ssSetModelName ( rts ,
"State-Space" ) ; ssSetPath ( rts ,
"Load_Simulation_07/powergui/EquivalentModel2/State-Space" ) ; if (
ssGetRTModel ( rtS ) == ( NULL ) ) { ssSetParentSS ( rts , rtS ) ;
ssSetRootSS ( rts , ssGetRootSS ( rtS ) ) ; } else { ssSetRTModel ( rts ,
ssGetRTModel ( rtS ) ) ; ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts
, rts ) ; } ssSetVersion ( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; { static
mxArray * sfcnParams [ 4 ] ; ssSetSFcnParamsCount ( rts , 4 ) ;
ssSetSFcnParamsPtr ( rts , & sfcnParams [ 0 ] ) ; ssSetSFcnParam ( rts , 0 ,
( mxArray * ) rtP . StateSpace_P1_Size ) ; ssSetSFcnParam ( rts , 1 , (
mxArray * ) rtP . StateSpace_P2_Size ) ; ssSetSFcnParam ( rts , 2 , ( mxArray
* ) rtP . StateSpace_P3_Size ) ; ssSetSFcnParam ( rts , 3 , ( mxArray * ) rtP
. StateSpace_P4_Size ) ; } ssSetRWork ( rts , ( real_T * ) & rtDW .
my4ttjz2fk [ 0 ] ) ; ssSetIWork ( rts , ( int_T * ) & rtDW . i3jqpyztxw [ 0 ]
) ; ssSetPWork ( rts , ( void * * ) & rtDW . i52v1nqs1o [ 0 ] ) ; { static
struct _ssDWorkRecord dWorkRecord [ 3 ] ; static struct _ssDWorkAuxRecord
dWorkAuxRecord [ 3 ] ; ssSetSFcnDWork ( rts , dWorkRecord ) ;
ssSetSFcnDWorkAux ( rts , dWorkAuxRecord ) ; _ssSetNumDWork ( rts , 3 ) ;
ssSetDWorkWidth ( rts , 0 , 2 ) ; ssSetDWorkDataType ( rts , 0 , SS_DOUBLE )
; ssSetDWorkComplexSignal ( rts , 0 , 0 ) ; ssSetDWork ( rts , 0 , & rtDW .
my4ttjz2fk [ 0 ] ) ; ssSetDWorkWidth ( rts , 1 , 23 ) ; ssSetDWorkDataType (
rts , 1 , SS_INTEGER ) ; ssSetDWorkComplexSignal ( rts , 1 , 0 ) ; ssSetDWork
( rts , 1 , & rtDW . i3jqpyztxw [ 0 ] ) ; ssSetDWorkWidth ( rts , 2 , 22 ) ;
ssSetDWorkDataType ( rts , 2 , SS_POINTER ) ; ssSetDWorkComplexSignal ( rts ,
2 , 0 ) ; ssSetDWork ( rts , 2 , & rtDW . i52v1nqs1o [ 0 ] ) ; }
sfun_spid_contc ( rts ) ; sfcnInitializeSizes ( rts ) ;
sfcnInitializeSampleTimes ( rts ) ; ssSetSampleTime ( rts , 0 , 0.0 ) ;
ssSetOffsetTime ( rts , 0 , 0.0 ) ; sfcnTsMap [ 0 ] = 0 ;
ssSetNumNonsampledZCs ( rts , 0 ) ; _ssSetInputPortConnected ( rts , 0 , 1 )
; _ssSetOutputPortConnected ( rts , 0 , 1 ) ; _ssSetOutputPortBeingMerged (
rts , 0 , 0 ) ; ssSetInputPortBufferDstPort ( rts , 0 , - 1 ) ; } { SimStruct
* rts = ssGetSFunction ( rtS , 1 ) ; static time_T sfcnPeriod [ 1 ] ; static
time_T sfcnOffset [ 1 ] ; static int_T sfcnTsMap [ 1 ] ; ( void ) memset ( (
void * ) sfcnPeriod , 0 , sizeof ( time_T ) * 1 ) ; ( void ) memset ( ( void
* ) sfcnOffset , 0 , sizeof ( time_T ) * 1 ) ; ssSetSampleTimePtr ( rts , &
sfcnPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rts , & sfcnOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rts , sfcnTsMap ) ; ssSetMdlInfoPtr ( rts ,
ssGetMdlInfoPtr ( rtS ) ) ; { static struct _ssSFcnModelMethods2 methods2 ;
ssSetModelMethods2 ( rts , & methods2 ) ; } { static struct
_ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 ( rts , & methods3 ) ; } {
static struct _ssSFcnModelMethods4 methods4 ; ssSetModelMethods4 ( rts , &
methods4 ) ; } { static struct _ssStatesInfo2 statesInfo2 ; static
ssPeriodicStatesInfo periodicStatesInfo ; ssSetStatesInfo2 ( rts , &
statesInfo2 ) ; ssSetPeriodicStatesInfo ( rts , & periodicStatesInfo ) ; } {
static struct _ssPortInputs inputPortInfo [ 1 ] ; _ssSetNumInputPorts ( rts ,
1 ) ; ssSetPortInfoForInputs ( rts , & inputPortInfo [ 0 ] ) ; { static
real_T const * sfcnUPtrs [ 2 ] ; sfcnUPtrs [ 0 ] = & rtB . dfjf12bep4 ;
sfcnUPtrs [ 1 ] = & rtB . mzsf40mopc ; ssSetInputPortSignalPtrs ( rts , 0 , (
InputPtrsType ) & sfcnUPtrs [ 0 ] ) ; _ssSetInputPortNumDimensions ( rts , 0
, 1 ) ; ssSetInputPortWidth ( rts , 0 , 2 ) ; } } { static struct
_ssPortOutputs outputPortInfo [ 1 ] ; ssSetPortInfoForOutputs ( rts , &
outputPortInfo [ 0 ] ) ; _ssSetNumOutputPorts ( rts , 1 ) ; {
_ssSetOutputPortNumDimensions ( rts , 0 , 1 ) ; ssSetOutputPortWidth ( rts ,
0 , 1 ) ; ssSetOutputPortSignal ( rts , 0 , ( ( real_T * ) & rtB . oben2eao5k
) ) ; } } ssSetModelName ( rts , "State-Space" ) ; ssSetPath ( rts ,
"Load_Simulation_07/powergui/EquivalentModel1/State-Space" ) ; if (
ssGetRTModel ( rtS ) == ( NULL ) ) { ssSetParentSS ( rts , rtS ) ;
ssSetRootSS ( rts , ssGetRootSS ( rtS ) ) ; } else { ssSetRTModel ( rts ,
ssGetRTModel ( rtS ) ) ; ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts
, rts ) ; } ssSetVersion ( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; { static
mxArray * sfcnParams [ 4 ] ; ssSetSFcnParamsCount ( rts , 4 ) ;
ssSetSFcnParamsPtr ( rts , & sfcnParams [ 0 ] ) ; ssSetSFcnParam ( rts , 0 ,
( mxArray * ) rtP . StateSpace_P1_Size_o5kda433ud ) ; ssSetSFcnParam ( rts ,
1 , ( mxArray * ) rtP . StateSpace_P2_Size_bulgjz5eca ) ; ssSetSFcnParam (
rts , 2 , ( mxArray * ) rtP . StateSpace_P3_Size_phw4ixie5t ) ;
ssSetSFcnParam ( rts , 3 , ( mxArray * ) rtP . StateSpace_P4_Size_br3dqazqmh
) ; } ssSetRWork ( rts , ( real_T * ) & rtDW . an5tlpibsu [ 0 ] ) ;
ssSetIWork ( rts , ( int_T * ) & rtDW . cdm1crpp3z [ 0 ] ) ; ssSetPWork ( rts
, ( void * * ) & rtDW . pasjhbqynx [ 0 ] ) ; { static struct _ssDWorkRecord
dWorkRecord [ 3 ] ; static struct _ssDWorkAuxRecord dWorkAuxRecord [ 3 ] ;
ssSetSFcnDWork ( rts , dWorkRecord ) ; ssSetSFcnDWorkAux ( rts ,
dWorkAuxRecord ) ; _ssSetNumDWork ( rts , 3 ) ; ssSetDWorkWidth ( rts , 0 , 2
) ; ssSetDWorkDataType ( rts , 0 , SS_DOUBLE ) ; ssSetDWorkComplexSignal (
rts , 0 , 0 ) ; ssSetDWork ( rts , 0 , & rtDW . an5tlpibsu [ 0 ] ) ;
ssSetDWorkWidth ( rts , 1 , 23 ) ; ssSetDWorkDataType ( rts , 1 , SS_INTEGER
) ; ssSetDWorkComplexSignal ( rts , 1 , 0 ) ; ssSetDWork ( rts , 1 , & rtDW .
cdm1crpp3z [ 0 ] ) ; ssSetDWorkWidth ( rts , 2 , 22 ) ; ssSetDWorkDataType (
rts , 2 , SS_POINTER ) ; ssSetDWorkComplexSignal ( rts , 2 , 0 ) ; ssSetDWork
( rts , 2 , & rtDW . pasjhbqynx [ 0 ] ) ; } sfun_spid_contc ( rts ) ;
sfcnInitializeSizes ( rts ) ; sfcnInitializeSampleTimes ( rts ) ;
ssSetSampleTime ( rts , 0 , 0.0 ) ; ssSetOffsetTime ( rts , 0 , 0.0 ) ;
sfcnTsMap [ 0 ] = 0 ; ssSetNumNonsampledZCs ( rts , 0 ) ;
_ssSetInputPortConnected ( rts , 0 , 1 ) ; _ssSetOutputPortConnected ( rts ,
0 , 1 ) ; _ssSetOutputPortBeingMerged ( rts , 0 , 0 ) ;
ssSetInputPortBufferDstPort ( rts , 0 , - 1 ) ; } { SimStruct * rts =
ssGetSFunction ( rtS , 2 ) ; static time_T sfcnPeriod [ 1 ] ; static time_T
sfcnOffset [ 1 ] ; static int_T sfcnTsMap [ 1 ] ; ( void ) memset ( ( void *
) sfcnPeriod , 0 , sizeof ( time_T ) * 1 ) ; ( void ) memset ( ( void * )
sfcnOffset , 0 , sizeof ( time_T ) * 1 ) ; ssSetSampleTimePtr ( rts , &
sfcnPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rts , & sfcnOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rts , sfcnTsMap ) ; ssSetMdlInfoPtr ( rts ,
ssGetMdlInfoPtr ( rtS ) ) ; { static struct _ssSFcnModelMethods2 methods2 ;
ssSetModelMethods2 ( rts , & methods2 ) ; } { static struct
_ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 ( rts , & methods3 ) ; } {
static struct _ssSFcnModelMethods4 methods4 ; ssSetModelMethods4 ( rts , &
methods4 ) ; } { static struct _ssStatesInfo2 statesInfo2 ; static
ssPeriodicStatesInfo periodicStatesInfo ; ssSetStatesInfo2 ( rts , &
statesInfo2 ) ; ssSetPeriodicStatesInfo ( rts , & periodicStatesInfo ) ; } {
static struct _ssPortInputs inputPortInfo [ 1 ] ; _ssSetNumInputPorts ( rts ,
1 ) ; ssSetPortInfoForInputs ( rts , & inputPortInfo [ 0 ] ) ; { static
real_T const * sfcnUPtrs [ 2 ] ; sfcnUPtrs [ 0 ] = & rtB . offgvp1su2 ;
sfcnUPtrs [ 1 ] = & rtB . mzsf40mopc ; ssSetInputPortSignalPtrs ( rts , 0 , (
InputPtrsType ) & sfcnUPtrs [ 0 ] ) ; _ssSetInputPortNumDimensions ( rts , 0
, 1 ) ; ssSetInputPortWidth ( rts , 0 , 2 ) ; } } { static struct
_ssPortOutputs outputPortInfo [ 1 ] ; ssSetPortInfoForOutputs ( rts , &
outputPortInfo [ 0 ] ) ; _ssSetNumOutputPorts ( rts , 1 ) ; {
_ssSetOutputPortNumDimensions ( rts , 0 , 1 ) ; ssSetOutputPortWidth ( rts ,
0 , 1 ) ; ssSetOutputPortSignal ( rts , 0 , ( ( real_T * ) & rtB . mj03tas4fg
) ) ; } } ssSetModelName ( rts , "State-Space" ) ; ssSetPath ( rts ,
"Load_Simulation_07/powergui/EquivalentModel3/State-Space" ) ; if (
ssGetRTModel ( rtS ) == ( NULL ) ) { ssSetParentSS ( rts , rtS ) ;
ssSetRootSS ( rts , ssGetRootSS ( rtS ) ) ; } else { ssSetRTModel ( rts ,
ssGetRTModel ( rtS ) ) ; ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts
, rts ) ; } ssSetVersion ( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; { static
mxArray * sfcnParams [ 4 ] ; ssSetSFcnParamsCount ( rts , 4 ) ;
ssSetSFcnParamsPtr ( rts , & sfcnParams [ 0 ] ) ; ssSetSFcnParam ( rts , 0 ,
( mxArray * ) rtP . StateSpace_P1_Size_j1wqbrx4kb ) ; ssSetSFcnParam ( rts ,
1 , ( mxArray * ) rtP . StateSpace_P2_Size_ilvhkduu3r ) ; ssSetSFcnParam (
rts , 2 , ( mxArray * ) rtP . StateSpace_P3_Size_mtz3nb2eku ) ;
ssSetSFcnParam ( rts , 3 , ( mxArray * ) rtP . StateSpace_P4_Size_fdb0ovkp3r
) ; } ssSetRWork ( rts , ( real_T * ) & rtDW . cnb4tdv1fb [ 0 ] ) ;
ssSetIWork ( rts , ( int_T * ) & rtDW . efvfgmr2jk [ 0 ] ) ; ssSetPWork ( rts
, ( void * * ) & rtDW . cxgfidnvpg [ 0 ] ) ; { static struct _ssDWorkRecord
dWorkRecord [ 3 ] ; static struct _ssDWorkAuxRecord dWorkAuxRecord [ 3 ] ;
ssSetSFcnDWork ( rts , dWorkRecord ) ; ssSetSFcnDWorkAux ( rts ,
dWorkAuxRecord ) ; _ssSetNumDWork ( rts , 3 ) ; ssSetDWorkWidth ( rts , 0 , 2
) ; ssSetDWorkDataType ( rts , 0 , SS_DOUBLE ) ; ssSetDWorkComplexSignal (
rts , 0 , 0 ) ; ssSetDWork ( rts , 0 , & rtDW . cnb4tdv1fb [ 0 ] ) ;
ssSetDWorkWidth ( rts , 1 , 23 ) ; ssSetDWorkDataType ( rts , 1 , SS_INTEGER
) ; ssSetDWorkComplexSignal ( rts , 1 , 0 ) ; ssSetDWork ( rts , 1 , & rtDW .
efvfgmr2jk [ 0 ] ) ; ssSetDWorkWidth ( rts , 2 , 22 ) ; ssSetDWorkDataType (
rts , 2 , SS_POINTER ) ; ssSetDWorkComplexSignal ( rts , 2 , 0 ) ; ssSetDWork
( rts , 2 , & rtDW . cxgfidnvpg [ 0 ] ) ; } sfun_spid_contc ( rts ) ;
sfcnInitializeSizes ( rts ) ; sfcnInitializeSampleTimes ( rts ) ;
ssSetSampleTime ( rts , 0 , 0.0 ) ; ssSetOffsetTime ( rts , 0 , 0.0 ) ;
sfcnTsMap [ 0 ] = 0 ; ssSetNumNonsampledZCs ( rts , 0 ) ;
_ssSetInputPortConnected ( rts , 0 , 1 ) ; _ssSetOutputPortConnected ( rts ,
0 , 1 ) ; _ssSetOutputPortBeingMerged ( rts , 0 , 0 ) ;
ssSetInputPortBufferDstPort ( rts , 0 , - 1 ) ; } } return rtS ; } const
int_T gblParameterTuningTid = 2 ; void MdlOutputsParameterSampleTime ( int_T
tid ) { MdlOutputsTID2 ( tid ) ; }
