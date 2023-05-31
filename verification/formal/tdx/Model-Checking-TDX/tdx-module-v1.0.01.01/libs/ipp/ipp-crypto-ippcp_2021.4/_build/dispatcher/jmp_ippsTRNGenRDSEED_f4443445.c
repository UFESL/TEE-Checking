#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(Ipp32u* pRand, int nBits, void* pCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsTRNGenRDSEED(Ipp32u* pRand, int nBits, void* pCtx);
extern IppStatus m7_ippsTRNGenRDSEED(Ipp32u* pRand, int nBits, void* pCtx);
extern IppStatus n8_ippsTRNGenRDSEED(Ipp32u* pRand, int nBits, void* pCtx);
extern IppStatus y8_ippsTRNGenRDSEED(Ipp32u* pRand, int nBits, void* pCtx);
extern IppStatus e9_ippsTRNGenRDSEED(Ipp32u* pRand, int nBits, void* pCtx);
extern IppStatus l9_ippsTRNGenRDSEED(Ipp32u* pRand, int nBits, void* pCtx);
extern IppStatus n0_ippsTRNGenRDSEED(Ipp32u* pRand, int nBits, void* pCtx);
extern IppStatus k0_ippsTRNGenRDSEED(Ipp32u* pRand, int nBits, void* pCtx);
extern IppStatus k1_ippsTRNGenRDSEED(Ipp32u* pRand, int nBits, void* pCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsTRNGenRDSEED,
	(IPP_PROC)m7_ippsTRNGenRDSEED,
	(IPP_PROC)n8_ippsTRNGenRDSEED,
	(IPP_PROC)y8_ippsTRNGenRDSEED,
	(IPP_PROC)e9_ippsTRNGenRDSEED,
	(IPP_PROC)l9_ippsTRNGenRDSEED,
	(IPP_PROC)n0_ippsTRNGenRDSEED,
	(IPP_PROC)k0_ippsTRNGenRDSEED,
	(IPP_PROC)k1_ippsTRNGenRDSEED
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsTRNGenRDSEED,(Ipp32u* pRand, int nBits, void* pCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsTRNGenRDSEED,(Ipp32u* pRand, int nBits, void* pCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsTRNGenRDSEED]
        jmp  rax
  }
};
