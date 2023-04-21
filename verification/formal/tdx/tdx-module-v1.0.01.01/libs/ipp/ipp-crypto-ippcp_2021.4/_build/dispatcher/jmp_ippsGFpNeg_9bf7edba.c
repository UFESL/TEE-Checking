#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsGFpElement* pA, IppsGFpElement* pR, IppsGFpState* pGFp);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpNeg(const IppsGFpElement* pA, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus m7_ippsGFpNeg(const IppsGFpElement* pA, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus n8_ippsGFpNeg(const IppsGFpElement* pA, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus y8_ippsGFpNeg(const IppsGFpElement* pA, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus e9_ippsGFpNeg(const IppsGFpElement* pA, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus l9_ippsGFpNeg(const IppsGFpElement* pA, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus n0_ippsGFpNeg(const IppsGFpElement* pA, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus k0_ippsGFpNeg(const IppsGFpElement* pA, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus k1_ippsGFpNeg(const IppsGFpElement* pA, IppsGFpElement* pR, IppsGFpState* pGFp);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpNeg,
	(IPP_PROC)m7_ippsGFpNeg,
	(IPP_PROC)n8_ippsGFpNeg,
	(IPP_PROC)y8_ippsGFpNeg,
	(IPP_PROC)e9_ippsGFpNeg,
	(IPP_PROC)l9_ippsGFpNeg,
	(IPP_PROC)n0_ippsGFpNeg,
	(IPP_PROC)k0_ippsGFpNeg,
	(IPP_PROC)k1_ippsGFpNeg
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpNeg,(const IppsGFpElement* pA, IppsGFpElement* pR, IppsGFpState* pGFp))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpNeg,(const IppsGFpElement* pA, IppsGFpElement* pR, IppsGFpState* pGFp))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpNeg]
        jmp  rax
  }
};
