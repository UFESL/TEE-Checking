#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpElement* pR, IppsGFpState* pGFp);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpMul(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus m7_ippsGFpMul(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus n8_ippsGFpMul(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus y8_ippsGFpMul(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus e9_ippsGFpMul(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus l9_ippsGFpMul(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus n0_ippsGFpMul(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus k0_ippsGFpMul(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus k1_ippsGFpMul(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpElement* pR, IppsGFpState* pGFp);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpMul,
	(IPP_PROC)m7_ippsGFpMul,
	(IPP_PROC)n8_ippsGFpMul,
	(IPP_PROC)y8_ippsGFpMul,
	(IPP_PROC)e9_ippsGFpMul,
	(IPP_PROC)l9_ippsGFpMul,
	(IPP_PROC)n0_ippsGFpMul,
	(IPP_PROC)k0_ippsGFpMul,
	(IPP_PROC)k1_ippsGFpMul
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpMul,(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpElement* pR, IppsGFpState* pGFp))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpMul,(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpElement* pR, IppsGFpState* pGFp))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpMul]
        jmp  rax
  }
};
