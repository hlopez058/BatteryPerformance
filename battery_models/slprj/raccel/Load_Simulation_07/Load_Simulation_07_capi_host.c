#include "Load_Simulation_07_capi_host.h"
static Load_Simulation_07_host_DataMapInfo_T root;
static int initialized = 0;
__declspec( dllexport ) rtwCAPI_ModelMappingInfo *getRootMappingInfo()
{
    if (initialized == 0) {
        initialized = 1;
        Load_Simulation_07_host_InitializeDataMapInfo(&(root), "Load_Simulation_07");
    }
    return &root.mmi;
}

rtwCAPI_ModelMappingInfo *mexFunction() {return(getRootMappingInfo());}
