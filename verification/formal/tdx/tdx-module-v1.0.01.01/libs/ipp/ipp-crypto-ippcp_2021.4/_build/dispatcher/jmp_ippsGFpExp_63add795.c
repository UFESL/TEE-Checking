#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsGFpElement* pA, const IppsBigNumState* pE, IppsGFpElement* pR, IppsGFpState* pGFp, Ipp8u* pScratchBuffer);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpExp(const IppsGFpElement* pA, const IppsBigNumState* pE, IppsGFpElement* pR, IppsGFpState* pGFp, Ipp8u* pScratchBuffer);
extern IppStatus m7_ippsGFpExp(const IppsGFpElement* pA, const IppsBigNumState* pE, IppsGFpElement* pR, IppsGFpState* pGFp, Ipp8u* pScratchBuffer);
extern IppStatus n8_ippsGFpExp(const IppsGFpElement* pA, const IppsBigNumState* pE, IppsGFpElement* pR, IppsGFpState* pGFp, Ipp8u* pScratchBuffer);
extern IppStatus y8_ippsGFpExp(const IppsGFpElement* pA, const IppsBigNumState* pE, IppsGFpElement* pR, IppsGFpState* pGFp, Ipp8u* pScratchBuffer);
extern IppStatus e9_ippsGFpExp(const IppsGFpElement* pA, const IppsBigNumState* pE, IppsGFpElement* pR, IppsGFpState* pGFp, Ipp8u* pScratchBuffer);
extern IppStatus l9_ippsGFpExp(const IppsGFpElement* pA, const IppsBigNumState* pE, IppsGFpElement* pR, IppsGFpState* pGFp, Ipp8u* pScratchBuffer);
extern IppStatus n0_ippsGFpExp(const IppsGFpElement* pA, const IppsBigNumState* pE, IppsGFpElement* pR, IppsGFpState* pGFp, Ipp8u* pScratchBuffer);
extern IppStatus k0_ippsGFpExp(const IppsGFpElement* pA, const IppsBigNumState* pE, IppsGFpElement* pR, IppsGFpState* pGFp, Ipp8u* pScratchBuffer);
extern IppStatus k1_ippsGFpExp(const IppsGFpElement* pA, const IppsBigNumState* pE, IppsGFpElement* pR, IppsGFpState* pGFp, Ipp8u* pScratchBuffer);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpExp,
	(IPP_PROC)m7_ippsGFpExp,
	(IPP_PROC)n8_ippsGFpExp,
	(IPP_PROC)y8_ippsGFpExp,
	(IPP_PROC)e9_ippsGFpExp,
	(IPP_PROC)l9_ippsGFpExp,
	(IPP_PROC)n0_ippsGFpExp,
	(IPP_PROC)k0_ippsGFpExp,
	(IPP_PROC)k1_ippsGFpExp
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpExp,(const IppsGFpElement* pA, const IppsBigNumState* pE, IppsGFpElement* pR, IppsGFpState* pGFp, Ipp8u* pScratchBuffer))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpExp,(const IppsGFpElement* pA, const IppsBigNumState* pE, IppsGFpElement* pR, IppsGFpState* pGFp, Ipp8u* pScratchBuffer))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpExp]
        jmp  rax
  }
};
