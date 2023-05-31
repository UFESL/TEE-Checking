#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(int nTrials, IppECResult* pResult, IppsECCPState* pEC, IppBitSupplier rndFunc, void* pRndParam);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsECCPValidate(int nTrials, IppECResult* pResult, IppsECCPState* pEC, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus m7_ippsECCPValidate(int nTrials, IppECResult* pResult, IppsECCPState* pEC, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus n8_ippsECCPValidate(int nTrials, IppECResult* pResult, IppsECCPState* pEC, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus y8_ippsECCPValidate(int nTrials, IppECResult* pResult, IppsECCPState* pEC, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus e9_ippsECCPValidate(int nTrials, IppECResult* pResult, IppsECCPState* pEC, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus l9_ippsECCPValidate(int nTrials, IppECResult* pResult, IppsECCPState* pEC, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus n0_ippsECCPValidate(int nTrials, IppECResult* pResult, IppsECCPState* pEC, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus k0_ippsECCPValidate(int nTrials, IppECResult* pResult, IppsECCPState* pEC, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus k1_ippsECCPValidate(int nTrials, IppECResult* pResult, IppsECCPState* pEC, IppBitSupplier rndFunc, void* pRndParam);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsECCPValidate,
	(IPP_PROC)m7_ippsECCPValidate,
	(IPP_PROC)n8_ippsECCPValidate,
	(IPP_PROC)y8_ippsECCPValidate,
	(IPP_PROC)e9_ippsECCPValidate,
	(IPP_PROC)l9_ippsECCPValidate,
	(IPP_PROC)n0_ippsECCPValidate,
	(IPP_PROC)k0_ippsECCPValidate,
	(IPP_PROC)k1_ippsECCPValidate
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsECCPValidate,(int nTrials, IppECResult* pResult, IppsECCPState* pEC, IppBitSupplier rndFunc, void* pRndParam))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsECCPValidate,(int nTrials, IppECResult* pResult, IppsECCPState* pEC, IppBitSupplier rndFunc, void* pRndParam))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsECCPValidate]
        jmp  rax
  }
};
