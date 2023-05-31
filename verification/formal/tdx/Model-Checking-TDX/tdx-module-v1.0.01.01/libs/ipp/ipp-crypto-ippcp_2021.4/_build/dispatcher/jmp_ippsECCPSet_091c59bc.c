#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pPrime, const IppsBigNumState* pA, const IppsBigNumState* pB, const IppsBigNumState* pGX,const IppsBigNumState* pGY,const IppsBigNumState* pOrder, int cofactor, IppsECCPState* pEC);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsECCPSet(const IppsBigNumState* pPrime, const IppsBigNumState* pA, const IppsBigNumState* pB, const IppsBigNumState* pGX,const IppsBigNumState* pGY,const IppsBigNumState* pOrder, int cofactor, IppsECCPState* pEC);
extern IppStatus m7_ippsECCPSet(const IppsBigNumState* pPrime, const IppsBigNumState* pA, const IppsBigNumState* pB, const IppsBigNumState* pGX,const IppsBigNumState* pGY,const IppsBigNumState* pOrder, int cofactor, IppsECCPState* pEC);
extern IppStatus n8_ippsECCPSet(const IppsBigNumState* pPrime, const IppsBigNumState* pA, const IppsBigNumState* pB, const IppsBigNumState* pGX,const IppsBigNumState* pGY,const IppsBigNumState* pOrder, int cofactor, IppsECCPState* pEC);
extern IppStatus y8_ippsECCPSet(const IppsBigNumState* pPrime, const IppsBigNumState* pA, const IppsBigNumState* pB, const IppsBigNumState* pGX,const IppsBigNumState* pGY,const IppsBigNumState* pOrder, int cofactor, IppsECCPState* pEC);
extern IppStatus e9_ippsECCPSet(const IppsBigNumState* pPrime, const IppsBigNumState* pA, const IppsBigNumState* pB, const IppsBigNumState* pGX,const IppsBigNumState* pGY,const IppsBigNumState* pOrder, int cofactor, IppsECCPState* pEC);
extern IppStatus l9_ippsECCPSet(const IppsBigNumState* pPrime, const IppsBigNumState* pA, const IppsBigNumState* pB, const IppsBigNumState* pGX,const IppsBigNumState* pGY,const IppsBigNumState* pOrder, int cofactor, IppsECCPState* pEC);
extern IppStatus n0_ippsECCPSet(const IppsBigNumState* pPrime, const IppsBigNumState* pA, const IppsBigNumState* pB, const IppsBigNumState* pGX,const IppsBigNumState* pGY,const IppsBigNumState* pOrder, int cofactor, IppsECCPState* pEC);
extern IppStatus k0_ippsECCPSet(const IppsBigNumState* pPrime, const IppsBigNumState* pA, const IppsBigNumState* pB, const IppsBigNumState* pGX,const IppsBigNumState* pGY,const IppsBigNumState* pOrder, int cofactor, IppsECCPState* pEC);
extern IppStatus k1_ippsECCPSet(const IppsBigNumState* pPrime, const IppsBigNumState* pA, const IppsBigNumState* pB, const IppsBigNumState* pGX,const IppsBigNumState* pGY,const IppsBigNumState* pOrder, int cofactor, IppsECCPState* pEC);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsECCPSet,
	(IPP_PROC)m7_ippsECCPSet,
	(IPP_PROC)n8_ippsECCPSet,
	(IPP_PROC)y8_ippsECCPSet,
	(IPP_PROC)e9_ippsECCPSet,
	(IPP_PROC)l9_ippsECCPSet,
	(IPP_PROC)n0_ippsECCPSet,
	(IPP_PROC)k0_ippsECCPSet,
	(IPP_PROC)k1_ippsECCPSet
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsECCPSet,(const IppsBigNumState* pPrime, const IppsBigNumState* pA, const IppsBigNumState* pB, const IppsBigNumState* pGX,const IppsBigNumState* pGY,const IppsBigNumState* pOrder, int cofactor, IppsECCPState* pEC))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsECCPSet,(const IppsBigNumState* pPrime, const IppsBigNumState* pA, const IppsBigNumState* pB, const IppsBigNumState* pGX,const IppsBigNumState* pGY,const IppsBigNumState* pOrder, int cofactor, IppsECCPState* pEC))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsECCPSet]
        jmp  rax
  }
};
