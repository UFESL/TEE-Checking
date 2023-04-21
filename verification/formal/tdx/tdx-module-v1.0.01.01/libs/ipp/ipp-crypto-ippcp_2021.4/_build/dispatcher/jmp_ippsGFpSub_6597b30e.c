#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpElement* pR, IppsGFpState* pGFp);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpSub(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus m7_ippsGFpSub(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus n8_ippsGFpSub(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus y8_ippsGFpSub(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus e9_ippsGFpSub(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus l9_ippsGFpSub(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus n0_ippsGFpSub(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus k0_ippsGFpSub(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus k1_ippsGFpSub(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpElement* pR, IppsGFpState* pGFp);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpSub,
	(IPP_PROC)m7_ippsGFpSub,
	(IPP_PROC)n8_ippsGFpSub,
	(IPP_PROC)y8_ippsGFpSub,
	(IPP_PROC)e9_ippsGFpSub,
	(IPP_PROC)l9_ippsGFpSub,
	(IPP_PROC)n0_ippsGFpSub,
	(IPP_PROC)k0_ippsGFpSub,
	(IPP_PROC)k1_ippsGFpSub
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpSub,(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpElement* pR, IppsGFpState* pGFp))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpSub,(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpElement* pR, IppsGFpState* pGFp))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpSub]
        jmp  rax
  }
};
