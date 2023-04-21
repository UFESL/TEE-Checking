#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(IppsBigNumState* pRand, int nBits, void* pCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsTRNGenRDSEED_BN(IppsBigNumState* pRand, int nBits, void* pCtx);
extern IppStatus m7_ippsTRNGenRDSEED_BN(IppsBigNumState* pRand, int nBits, void* pCtx);
extern IppStatus n8_ippsTRNGenRDSEED_BN(IppsBigNumState* pRand, int nBits, void* pCtx);
extern IppStatus y8_ippsTRNGenRDSEED_BN(IppsBigNumState* pRand, int nBits, void* pCtx);
extern IppStatus e9_ippsTRNGenRDSEED_BN(IppsBigNumState* pRand, int nBits, void* pCtx);
extern IppStatus l9_ippsTRNGenRDSEED_BN(IppsBigNumState* pRand, int nBits, void* pCtx);
extern IppStatus n0_ippsTRNGenRDSEED_BN(IppsBigNumState* pRand, int nBits, void* pCtx);
extern IppStatus k0_ippsTRNGenRDSEED_BN(IppsBigNumState* pRand, int nBits, void* pCtx);
extern IppStatus k1_ippsTRNGenRDSEED_BN(IppsBigNumState* pRand, int nBits, void* pCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsTRNGenRDSEED_BN,
	(IPP_PROC)m7_ippsTRNGenRDSEED_BN,
	(IPP_PROC)n8_ippsTRNGenRDSEED_BN,
	(IPP_PROC)y8_ippsTRNGenRDSEED_BN,
	(IPP_PROC)e9_ippsTRNGenRDSEED_BN,
	(IPP_PROC)l9_ippsTRNGenRDSEED_BN,
	(IPP_PROC)n0_ippsTRNGenRDSEED_BN,
	(IPP_PROC)k0_ippsTRNGenRDSEED_BN,
	(IPP_PROC)k1_ippsTRNGenRDSEED_BN
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsTRNGenRDSEED_BN,(IppsBigNumState* pRand, int nBits, void* pCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsTRNGenRDSEED_BN,(IppsBigNumState* pRand, int nBits, void* pCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsTRNGenRDSEED_BN]
        jmp  rax
  }
};
