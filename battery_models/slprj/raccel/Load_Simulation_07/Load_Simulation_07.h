#include "__cf_Load_Simulation_07.h"
#ifndef RTW_HEADER_Load_Simulation_07_h_
#define RTW_HEADER_Load_Simulation_07_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef Load_Simulation_07_COMMON_INCLUDES_
#define Load_Simulation_07_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "sigstream_rtw.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "Load_Simulation_07_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_zcfcn.h"
#include "rtGetInf.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#define MODEL_NAME Load_Simulation_07
#define NSAMPLE_TIMES (3) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (197) 
#define NUM_ZC_EVENTS (3) 
#ifndef NCSTATES
#define NCSTATES (18)   
#elif NCSTATES != 18
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T jru2iqrfmm ; real_T gu5rsica4y ; real_T eafza0ignh ;
real_T mo0fhfwjbn ; real_T hbrgffmmwb ; real_T ffdlej0esm ; real_T iu235cbed5
; real_T jm35sgpar2 ; real_T o4aync4hqi ; real_T a4eiiet2o0 ; real_T
p4h4wunzca ; real_T lpwludxfnb ; real_T pmxqn1j2n3 ; real_T mfjtrcfybp ;
real_T djwy2mdgcr ; real_T bn5kz230z1 ; real_T ksvnvluruk ; real_T b4dvnbx2z0
; real_T losq44zfsw ; real_T ia1kg5fvtb ; real_T on5jb3go3s ; real_T
fgkxbpykg1 ; real_T cb1nnepflz ; real_T msdjbx4ftv ; real_T kypwxy50kw ;
real_T bb25sco2fm ; real_T abmbri4rct ; real_T gi1zeejtvl ; real_T brqcacx4dy
; real_T mzsf40mopc ; real_T ltqlujcfbs ; real_T ml5sunf4wl ; real_T
kgwpzskznu ; real_T cu3rpzq1ir ; real_T ebzvvcw0uj ; real_T nvl5qjckkv ;
real_T p4pflkgeyq ; real_T ded05j4tle ; real_T kjbniesfcu ; real_T kcia4oomek
; real_T f3yztw02af ; real_T ebadym5xni ; real_T ascuylmfea ; real_T
lgl3sevxjx ; real_T i2cij1nsan ; real_T cy2mdsactk ; real_T hrgapvp0ps ;
real_T gx3vfbmrpy ; real_T opjh3hy4jh ; real_T dltlpyqxxt ; real_T hesfhsyv0h
; real_T dz2enm0ww0 ; real_T j5n5fyudax ; real_T iirqhbasaw ; real_T
poiu0irxc0 ; real_T fzd1h5apha ; real_T m12jzkvpeg ; real_T nwx1m5flyz ;
real_T gre3fyyedb ; real_T ei5r5a5pav ; real_T ommpg3cgpv ; real_T i1k1tidl2o
; real_T olb0grj3j3 ; real_T mkgovfegci ; real_T dfjf12bep4 ; real_T
oben2eao5k ; real_T btbyo2vcmz ; real_T mqfk5v4diy ; real_T bfx2u5xgpq ;
real_T bybpkn3fg3 ; real_T gqdjkmiehk ; real_T mfmapc1zif ; real_T m4i5mlkre0
; real_T ik21zuu0w2 ; real_T jqky25xmle ; real_T fmkuq1m3bb ; real_T
brt0odp1ig ; real_T hwk4furfbr ; real_T poeuuptz0e ; real_T kyxi4xk5b1 ;
real_T lad2rbhq0d ; real_T n0ykw2xnss ; real_T j2m1rxr1a0 ; real_T nisapdp2vu
; real_T dgq5far14c ; real_T mdkcdrc1dj ; real_T g3fahebeoh ; real_T
dg1ivic2cv ; real_T o2w0cdwc0f ; real_T foxxmgfp1n ; real_T guy2kz5ncd ;
real_T fzutsooicn ; real_T i0dlbs1b2l ; real_T ffql2fnkid ; real_T bzhvuobncb
; real_T g4hw1qgbdv ; real_T prq1vlt5vx ; real_T ecaohy0st5 ; real_T
b4dywjx5hn ; real_T offgvp1su2 ; real_T mj03tas4fg ; real_T aepfzat2ah ;
real_T bb0v5z1gyy ; real_T awto1smfy3 ; real_T adxkajg20f ; real_T p5iut1x42c
; real_T bb0be3gnia ; real_T hqpcpdn5qa ; real_T jbhxgjw5cy ; real_T
nf3rdcvax5 ; real_T j4gfvflild ; real_T lzetnopoo3 ; real_T jce4jecbbp ;
real_T dwb42stmvv ; real_T gu3qbji4xc ; real_T pgudi1oete ; real_T fmw5kmtm1r
; real_T bwvje3ihiw ; real_T m0yglvlyme ; real_T pvwijbyxkr ; real_T
aesu3l5yyk ; real_T e3cqouyy3w ; real_T dcqdhsbevr ; real_T o3lepigeif ;
real_T d5351zjf4x ; real_T eoju45gqpq ; real_T dfbrmr4pqz ; real_T dabeiiy4xg
; real_T koz3cqzv1c ; real_T etpdoa2xuk ; real_T jaquvxw41i ; real_T
oaqch21uel ; real_T lvkqstzrdf ; real_T lmk5yid3hu ; real_T grozn2da0l ;
real_T dzqkvxhkd1 ; real_T n5c0k4fbwb ; real_T lwlovbyzf2 ; real_T n0r3f03erl
; real_T e0dl0dglhu ; real_T j3xdv1bkdg ; real_T maqw5opry0 ; real_T
acjy0wcx33 ; real_T ffgdskx2hu ; real_T brdas51kj1 ; real_T nfweyj1qvq ;
real_T h2cdsbamjg ; real_T njpjxwiwga ; real_T mc3kmonqyw ; real_T eajyu4e2gg
; real_T csv1q2rmqm ; real_T hap1ivasmg ; real_T o0zujw030w ; real_T
hrenjgvsp2 ; real_T agnwtijpiy ; real_T oepc1i4s5o ; real_T gnxuzeutps ;
real_T hoa4ffors0 ; real_T p5bxowhy3u ; real_T dl2oj2hwn5 ; real_T btonwzxytu
; real_T g03b5ho0xb [ 4 ] ; real_T egi1glv2iz [ 4 ] ; real_T aufyna3xwp [ 4 ]
; real_T dpzsk0fv2e [ 4 ] ; real_T oiiyyqltbq ; real_T pjy23u5hnz ; real_T
b3jprbo2ch ; real_T psc1bdwm0e [ 4 ] ; real_T lwryrfr1np [ 4 ] ; real_T
dehp52jxod [ 4 ] ; real_T dhz0gnwoz2 [ 4 ] ; real_T chxlnefiu2 ; real_T
gucbgg34uu ; real_T jl0as1i1kv ; real_T gayccjz0g2 [ 4 ] ; real_T cgcsvraqod
[ 4 ] ; real_T amabyxe2q5 [ 4 ] ; real_T hp4pbsppeu [ 4 ] ; boolean_T
p3hqh0p1ve ; boolean_T gibfnm5yif ; boolean_T h5yixci3b5 ; boolean_T
iu45wsrpul ; boolean_T l5k4v4pkri ; boolean_T bbvpjaqjcj ; boolean_T
c33k25rpdh ; boolean_T pm3wjc2bv1 ; boolean_T kvprg4ppnw ; boolean_T
eqm015gtbx ; boolean_T hvjsipjvee ; boolean_T nj4n1mxjv0 ; boolean_T
druqytbldp ; boolean_T kjxguscvc3 ; boolean_T f142q2bocw ; boolean_T
b1tb4rlksj ; boolean_T ewa4jwoiei ; boolean_T h54wfmqlk0 ; } B ; typedef
struct { real_T jflxrokyki ; real_T gkgewmrthj ; real_T byrrqwbwuv ; real_T
ko2pp0cfqy ; real_T knyijtosqg ; real_T ft2nyeqcg1 ; real_T my4ttjz2fk [ 2 ]
; real_T an5tlpibsu [ 2 ] ; real_T cnb4tdv1fb [ 2 ] ; struct { void * TimePtr
; void * DataPtr ; void * RSimInfoPtr ; } ixzxf22pdy ; void * i52v1nqs1o [ 22
] ; struct { void * LoggedData [ 3 ] ; } ifo13hvcar ; void * pasjhbqynx [ 22
] ; struct { void * LoggedData [ 3 ] ; } dyo1jajuwp ; void * cxgfidnvpg [ 22
] ; struct { void * LoggedData [ 3 ] ; } chubbvu0th ; struct { void *
LoggedData ; } cddwntinmn ; int_T nkl51yszn4 ; struct { int_T PrevIndex ; }
j4pqvee5xt ; int_T i3jqpyztxw [ 23 ] ; int_T fyfdvnwnzj ; int_T cdm1crpp3z [
23 ] ; int_T gxhjb1iyjf ; int_T efvfgmr2jk [ 23 ] ; int_T j4qnczxkrf ; int_T
ezytuzrwcm ; int_T cr3vas1c0t ; int_T i5fsfrib41 ; int_T l4pyajhrvl ; int_T
etgutsyzrf ; int_T nn2v3m5mqb ; int_T i4dp0latxw ; int_T elzvn2clyn ; int_T
p4ho05td4b ; int_T okerpy1dzv ; int_T ayr4ahfun4 ; int_T j220vn1p2t ; int_T
e0tyil0jmq ; int_T llbft42mya ; boolean_T e2bbi1copd ; boolean_T aroxcxqsxi ;
boolean_T cgagzvjehp ; boolean_T nsqv1bhvah ; boolean_T oajahukjrq ;
boolean_T jq3tf3x1xs ; boolean_T hvbgl0hgfc ; boolean_T dvabjhaxc1 ;
boolean_T i3xk5pcc1t ; boolean_T okwoxppsxh ; boolean_T erby3qbuzu ;
boolean_T knppb5aj2r ; boolean_T ecnrycha4x ; boolean_T dkqm0duv1u ;
boolean_T f4ellfbxmn ; boolean_T guk1qwasso ; boolean_T d3wwahyjdv ;
boolean_T bwnvfnkkdo ; boolean_T gurrglctsf ; boolean_T nrqdnhqrpx ;
boolean_T i0tbjbubdb ; boolean_T ho5g2sdnaf ; boolean_T ixmlzcolrr ;
boolean_T fkqektwhpq ; boolean_T ieybpiozzj ; boolean_T e4tlndddzv ;
boolean_T abjaxhp14q ; boolean_T ivlzoptp2y ; boolean_T bkvk3xox1d ;
boolean_T mwafatbfsb ; } DW ; typedef struct { real_T awyk3jkmpp ; real_T
geiqvotdgd ; real_T gjrr5rcl1i ; real_T emndqevlhi ; real_T oobd5yyumt ;
real_T gqep4i1he1 ; real_T lr2fon2uwe ; real_T plzaosk005 ; real_T femnmi0kft
; real_T czasr4omxo ; real_T cdhjf34fys ; real_T fgmli1n2fu ; real_T
drcq2lkoq2 ; real_T cw5koqcmmd ; real_T jaymf1z1oc ; real_T mlhiasidwv ;
real_T lvhyb51zfr ; real_T ic4xkivobu ; } X ; typedef struct { real_T
awyk3jkmpp ; real_T geiqvotdgd ; real_T gjrr5rcl1i ; real_T emndqevlhi ;
real_T oobd5yyumt ; real_T gqep4i1he1 ; real_T lr2fon2uwe ; real_T plzaosk005
; real_T femnmi0kft ; real_T czasr4omxo ; real_T cdhjf34fys ; real_T
fgmli1n2fu ; real_T drcq2lkoq2 ; real_T cw5koqcmmd ; real_T jaymf1z1oc ;
real_T mlhiasidwv ; real_T lvhyb51zfr ; real_T ic4xkivobu ; } XDot ; typedef
struct { boolean_T awyk3jkmpp ; boolean_T geiqvotdgd ; boolean_T gjrr5rcl1i ;
boolean_T emndqevlhi ; boolean_T oobd5yyumt ; boolean_T gqep4i1he1 ;
boolean_T lr2fon2uwe ; boolean_T plzaosk005 ; boolean_T femnmi0kft ;
boolean_T czasr4omxo ; boolean_T cdhjf34fys ; boolean_T fgmli1n2fu ;
boolean_T drcq2lkoq2 ; boolean_T cw5koqcmmd ; boolean_T jaymf1z1oc ;
boolean_T mlhiasidwv ; boolean_T lvhyb51zfr ; boolean_T ic4xkivobu ; } XDis ;
typedef struct { real_T awyk3jkmpp ; real_T geiqvotdgd ; real_T gjrr5rcl1i ;
real_T emndqevlhi ; real_T oobd5yyumt ; real_T gqep4i1he1 ; real_T lr2fon2uwe
; real_T plzaosk005 ; real_T femnmi0kft ; real_T czasr4omxo ; real_T
cdhjf34fys ; real_T fgmli1n2fu ; real_T drcq2lkoq2 ; real_T cw5koqcmmd ;
real_T jaymf1z1oc ; real_T mlhiasidwv ; real_T lvhyb51zfr ; real_T ic4xkivobu
; } CStateAbsTol ; typedef struct { real_T bqt044leqt ; real_T pkihvgg2n2 ;
real_T ewhwxebxoc ; real_T k4qoef5cni ; real_T nxkqgaevpl ; real_T hq4g4ipse5
; real_T fn1a4gv4tp ; real_T hyark1ffav ; real_T nx1cmtrwmb ; real_T
gbmtqtlsls ; real_T fbte5t1m0e ; real_T bemgirumpk ; real_T aecravb3hs ;
real_T esljyrzmlw ; real_T o14mfob1cz ; real_T j5ayeqfwy1 ; real_T limtohtsdo
; real_T csnqjhl3mu ; real_T kftxbk5pmm ; real_T nwalcj5gms ; real_T
pdhvg12scp ; real_T h3prldoayh ; real_T gjqeyfsj2x ; real_T ab4lh402sw ;
real_T jb2yhcno4b ; real_T fv4eegkotw ; real_T evpb4rq3eh ; real_T dbd0qhgqv4
; real_T n50h24fuoh ; real_T etc5hgx3c1 ; real_T jjioyrkmn0 ; real_T
inwacnnnt0 ; real_T jokkaie0ca ; real_T cvyhscvv1a ; real_T lxzrkicv1c ;
real_T mb1gev2viv ; real_T mm3cy3skdk ; real_T d55rudnyfq ; real_T mkqafvfyfz
; real_T hkmvwa2w5q ; real_T c5wc5exuel ; real_T a1g3zj5mxf ; real_T
fsu2d1koy1 ; real_T gu2wzrl1df ; real_T aopqdltyuh ; real_T hxrnfhwyqp ;
real_T pl2qli5qh3 ; real_T ew2p2am1jo ; real_T htrknilzxi ; real_T ip53nzovbl
; real_T pucajiwng3 ; real_T kv0mpvlxjk ; real_T hcjekczuu2 ; real_T
hxi5trliim ; real_T bwzvkocqq1 ; real_T dzuyaprajo ; real_T opg0fsvdib ; }
ZCV ; typedef struct { ZCSigState oz2emx0tx4 ; ZCSigState g2jgodrbhp ;
ZCSigState ivgw3hbjew ; } PrevZCX ; typedef struct { rtwCAPI_ModelMappingInfo
mmi ; } DataMapInfo ; struct P_ { real_T u2volts10AhLeadAcidbattery_BatType ;
real_T u2v10AhLiFePO4_BatType ; real_T u2volts10AhNiMHbattery_BatType ;
real_T u2volts10AhLeadAcidbattery_SOC ; real_T u2v10AhLiFePO4_SOC ; real_T
u2volts10AhNiMHbattery_SOC ; real_T Constant1_Value ; real_T Constant_Value ;
real_T Saturation3_UpperSat ; real_T Saturation3_LowerSat ; real_T
Constant10_Value ; real_T Switch3_Threshold ; real_T itinit1_X0 ; real_T
Constant13_Value ; real_T Switch5_Threshold ; real_T R2_Gain ; real_T
Currentfilter_A ; real_T Currentfilter_C ; real_T Constant_Value_alteb1itig ;
real_T inti_UpperSat ; real_T inti_LowerSat ; real_T Gain_Gain ; real_T
Constant9_Value ; real_T StateSpace_A ; real_T StateSpace_B ; real_T
StateSpace_C ; real_T StateSpace_X0 ; real_T Constant5_Value ; real_T
Constant4_Value ; real_T Switch_Threshold ; real_T Constant4_Value_baux3n4syi
; real_T R3_Gain ; real_T Constant_Value_ox3fg1go0h ; real_T
Constant1_Value_ena3bvbnod ; real_T Constant3_Value ; real_T Constant2_Value
; real_T Constant14_Value ; real_T Constant15_Value ; real_T Constant16_Value
; real_T Switch6_Threshold ; real_T Currentfilter1_A ; real_T
Currentfilter1_C ; real_T Constant7_Value ; real_T Constant6_Value ; real_T
Switch2_Threshold ; real_T Constant3_Value_iqsu23z4ce ; real_T
Constant2_Value_cdqfgwpsti ; real_T Switch1_Threshold ; real_T R1_Gain ;
real_T FromWorkspace_Time0 [ 3600 ] ; real_T FromWorkspace_Data0 [ 3600 ] ;
real_T StateSpace_P1_Size [ 2 ] ; real_T StateSpace_P1 [ 3 ] ; real_T
StateSpace_P2_Size [ 2 ] ; real_T StateSpace_P2 [ 4 ] ; real_T
StateSpace_P3_Size [ 2 ] ; real_T StateSpace_P4_Size [ 2 ] ; real_T
StateSpace_P4 [ 198 ] ; real_T donotdeletethisgain_Gain ; real_T R_Gain ;
real_T R4_Gain ; real_T Saturation_UpperSat ; real_T Saturation_LowerSat ;
real_T Constant1_Value_p0nk0e4k4t ; real_T Constant_Value_b2oae4kl4u ; real_T
Saturation3_UpperSat_matxumbq22 ; real_T Saturation3_LowerSat_ikhjztqrap ;
real_T Constant10_Value_b4me2hmi3i ; real_T Switch3_Threshold_f11xead0ed ;
real_T itinit1_X0_izz5uwg0q1 ; real_T Constant13_Value_bofm4evjtq ; real_T
Switch5_Threshold_gd4feiqqyu ; real_T R2_Gain_bxxpczbi0a ; real_T
Currentfilter_A_hpeprc3wrq ; real_T Currentfilter_C_ghxfrv2shu ; real_T
Constant_Value_o5texc1pzk ; real_T inti_UpperSat_dal2xymi3h ; real_T
inti_LowerSat_plajszqohf ; real_T Gain_Gain_fvqpvk3pvf ; real_T
Constant9_Value_jc35dhdc3v ; real_T StateSpace_A_lj2d3hqe0x ; real_T
StateSpace_B_mjohccgfqz ; real_T StateSpace_C_iee0yjqzes ; real_T
StateSpace_X0_hyto3shui2 ; real_T Constant5_Value_fafteqsipq ; real_T
Constant4_Value_jum4bwpjax ; real_T Switch_Threshold_abfzybubnv ; real_T
Constant4_Value_db1mnqkkob ; real_T R3_Gain_bqq4aa4t3o ; real_T
Constant_Value_mscbjvxnfy ; real_T Constant1_Value_e3wa3mydbv ; real_T
Constant3_Value_f2btqjtsos ; real_T Constant2_Value_fa544zy0zf ; real_T
Constant14_Value_mkv5pnyukp ; real_T Constant15_Value_ad54pn3wr2 ; real_T
Constant16_Value_cjh5ma2c3k ; real_T Switch6_Threshold_htoqtnapgo ; real_T
Currentfilter1_A_cqp1aqrh0k ; real_T Currentfilter1_C_o13iba3s0t ; real_T
Constant7_Value_ncodhoosuz ; real_T Constant6_Value_hd4fth2fjz ; real_T
Switch2_Threshold_l01luurl0n ; real_T Constant3_Value_n51n10aq0o ; real_T
Constant2_Value_hvybrtqmxz ; real_T Switch1_Threshold_mcownc3hf5 ; real_T
R1_Gain_frm0s5nenw ; real_T StateSpace_P1_Size_o5kda433ud [ 2 ] ; real_T
StateSpace_P1_lgsdqm3bih [ 3 ] ; real_T StateSpace_P2_Size_bulgjz5eca [ 2 ] ;
real_T StateSpace_P2_lhxftost1h [ 4 ] ; real_T StateSpace_P3_Size_phw4ixie5t
[ 2 ] ; real_T StateSpace_P4_Size_br3dqazqmh [ 2 ] ; real_T
StateSpace_P4_ah0hhhtenk [ 150 ] ; real_T donotdeletethisgain_Gain_hql5qzrmqi
; real_T R_Gain_leocntiara ; real_T R4_Gain_gi4xenlaa1 ; real_T
Saturation_UpperSat_mtqq4gsywh ; real_T Saturation_LowerSat_gwhczn143q ;
real_T Constant1_Value_nxh5i5seoh ; real_T Constant_Value_irl5fvnkc1 ; real_T
Saturation3_UpperSat_ntsul5erig ; real_T Saturation3_LowerSat_b5p1gj4cuc ;
real_T Constant10_Value_lc4vxfnhde ; real_T Switch3_Threshold_dyzy5hn0uo ;
real_T itinit1_X0_auy3ty1z4l ; real_T Constant13_Value_mqbxzfv4z4 ; real_T
Switch5_Threshold_aipebitqdl ; real_T R2_Gain_lmwx4sb00n ; real_T
Currentfilter_A_cwwxbi13u0 ; real_T Currentfilter_C_mskf05lo23 ; real_T
Constant_Value_ezg4nv1jai ; real_T inti_UpperSat_m5funkuur3 ; real_T
inti_LowerSat_hwyc0llog5 ; real_T Gain_Gain_f4berbk0ip ; real_T
Constant9_Value_e4pjobvupn ; real_T StateSpace_A_aeig1o2grk ; real_T
StateSpace_B_ggzos4rhxs ; real_T StateSpace_C_flmaxlhzmm ; real_T
StateSpace_X0_fdo1l0da13 ; real_T Constant5_Value_mdyfw3r2se ; real_T
Constant4_Value_hx5xprji3v ; real_T Switch_Threshold_c01jx1rxkb ; real_T
Constant4_Value_nfrrjffypp ; real_T R3_Gain_h2tjvli4op ; real_T
Constant_Value_i12rhgm4ll ; real_T Constant1_Value_a1rhrhkbfn ; real_T
Constant3_Value_cy3b2kpr1c ; real_T Constant2_Value_a5vfpd3gf4 ; real_T
Constant14_Value_badjrarjmp ; real_T Constant15_Value_crqj5fw4c3 ; real_T
Constant16_Value_idauo5rtab ; real_T Switch6_Threshold_jp4ffub4pb ; real_T
Currentfilter1_A_a05epnrbo3 ; real_T Currentfilter1_C_nx2vxymlgz ; real_T
Constant7_Value_fs50zyrehf ; real_T Constant6_Value_kkiebpd3zp ; real_T
Switch2_Threshold_dcfkmijqkz ; real_T Constant3_Value_jbt5o32vyc ; real_T
Constant2_Value_idziu2npmy ; real_T Switch1_Threshold_id0sltlw43 ; real_T
R1_Gain_lxoje1sbcn ; real_T StateSpace_P1_Size_j1wqbrx4kb [ 2 ] ; real_T
StateSpace_P1_gcbokynfeb [ 3 ] ; real_T StateSpace_P2_Size_ilvhkduu3r [ 2 ] ;
real_T StateSpace_P2_jtefz4j2hs [ 4 ] ; real_T StateSpace_P3_Size_mtz3nb2eku
[ 2 ] ; real_T StateSpace_P4_Size_fdb0ovkp3r [ 2 ] ; real_T
StateSpace_P4_jnl2tr4gcu [ 183 ] ; real_T donotdeletethisgain_Gain_cnrap2hfmr
; real_T R_Gain_gmkimg2vno ; real_T R4_Gain_grw2mkmlr5 ; real_T
Saturation_UpperSat_mo1jv0phgx ; real_T Saturation_LowerSat_dggvwabw03 ;
real_T u_Value ; real_T Constant11_Value ; real_T Constant12_Value ; real_T
Constant8_Value ; real_T Constant_Value_blwrb2w0qh ; real_T Gain4_Gain ;
real_T Gain1_Gain ; real_T Ta_Value ; real_T Gain2_Gain ; real_T
Constant_Value_dn32sdoil4 ; real_T Gain_Gain_dwzn0ogzht ; real_T
Saturation2_UpperSat ; real_T Saturation2_LowerSat ; real_T Switch4_Threshold
; real_T TransferFcn1_A ; real_T TransferFcn1_C ; real_T Gain_Gain_npmm5mmnhb
; real_T Constant11_Value_fwpcd5xjtn ; real_T Constant12_Value_ir3wdqdic4 ;
real_T Constant8_Value_kzavomyluf ; real_T Constant_Value_mexjddav50 ; real_T
Gain4_Gain_l2e2nzph1g ; real_T Gain1_Gain_fytmd1ajrp ; real_T
Ta_Value_grpxumhhux ; real_T Gain2_Gain_b1lukokzr1 ; real_T
Constant_Value_ce0ilwr0v4 ; real_T Gain_Gain_mavdcgl3fv ; real_T
Saturation2_UpperSat_ppqdia3avp ; real_T Saturation2_LowerSat_jhnens0jar ;
real_T Switch4_Threshold_laodusaory ; real_T TransferFcn1_A_a3pzcnto0r ;
real_T TransferFcn1_C_nct1hyfwyw ; real_T Gain_Gain_ocmxl2t2zp ; real_T
Constant11_Value_k5i3bqlkzv ; real_T Constant12_Value_ooh2hzd22c ; real_T
Constant8_Value_ojzmwgq5pn ; real_T Constant_Value_fk15mpo45m ; real_T
Gain4_Gain_bwxmd45ipv ; real_T Gain1_Gain_pji14mxcuf ; real_T
Ta_Value_ko1cwv42q0 ; real_T Gain2_Gain_oxevkaekqr ; real_T
Constant_Value_cvgmtz023a ; real_T Gain_Gain_ig2ewsw3sm ; real_T
Saturation2_UpperSat_kllm5hrnuw ; real_T Saturation2_LowerSat_lf1dgltu2n ;
real_T Switch4_Threshold_abb0upiodf ; real_T TransferFcn1_A_izgygp24sn ;
real_T TransferFcn1_C_omqc4vdzkc ; real_T Gain_Gain_k3wfy1rzcq ; } ; extern
const char * RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ;
extern DW rtDW ; extern PrevZCX rtPrevZCX ; extern P rtP ; extern const
rtwCAPI_ModelMappingStaticInfo * Load_Simulation_07_GetCAPIStaticMap ( void )
; extern SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern
const int_T gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
extern const int_T gblNumRootInportBlks ; extern const int_T
gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ; extern
const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [ ] ;
extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ; extern const int_T gblParameterTuningTid ; extern
size_t gblCurrentSFcnIdx ; extern size_t * gblChildIdxToInfoIdx ; extern
DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model ( void
) ;
#endif
