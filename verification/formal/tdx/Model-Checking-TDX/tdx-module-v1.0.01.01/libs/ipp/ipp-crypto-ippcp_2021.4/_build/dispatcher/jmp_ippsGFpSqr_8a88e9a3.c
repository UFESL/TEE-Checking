#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsGFpElement* pA, IppsGFpElement* pR, IppsGFpState* pGFp);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpSqr(const IppsGFpElement* pA, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus m7_ippsGFpSqr(const IppsGFpElement* pA, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus n8_ippsGFpSqr(const IppsGFpElement* pA, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus y8_ippsGFpSqr(const IppsGFpElement* pA, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus e9_ippsGFpSqr(const IppsGFpElement* pA, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus l9_ippsGFpSqr(const IppsGFpElement* pA, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus n0_ippsGFpSqr(const IppsGFpElement* pA, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus k0_ippsGFpSqr(const IppsGFpElement* pA, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus k1_ippsGFpSqr(const IppsGFpElement* pA, IppsGFpElement* pR, IppsGFpState* pGFp);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpSqr,
	(IPP_PROC)m7_ippsGFpSqr,
	(IPP_PROC)n8_ippsGFpSqr,
	(IPP_PROC)y8_ippsGFpSqr,
	(IPP_PROC)e9_ippsGFpSqr,
	(IPP_PROC)l9_ippsGFpSqr,
	(IPP_PROC)n0_ippsGFpSqr,
	(IPP_PROC)k0_ippsGFpSqr,
	(IPP_PROC)k1_ippsGFpSqr
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpSqr,(const IppsGFpElement* pA, IppsGFpElement* pR, IppsGFpState* pGFp))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpSqr,(const IppsGFpElement* pA, IppsGFpElement* pR, IppsGFpState* pGFp))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpSqr]
        jmp  rax
  }
};
