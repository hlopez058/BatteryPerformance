#include "__cf_Load_Simulation_07.h"
#ifndef RTW_HEADER_Load_Simulation_07_cap_host_h_
#define RTW_HEADER_Load_Simulation_07_cap_host_h_
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"
typedef struct { rtwCAPI_ModelMappingInfo mmi ; }
Load_Simulation_07_host_DataMapInfo_T ;
#ifdef __cplusplus
extern "C" {
#endif
void Load_Simulation_07_host_InitializeDataMapInfo (
Load_Simulation_07_host_DataMapInfo_T * dataMap , const char * path ) ;
#ifdef __cplusplus
}
#endif
#endif
#endif
