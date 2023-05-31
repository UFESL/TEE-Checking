#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsGFpElement* pA, const IppsGFpElement* pParentB, IppsGFpElement* pR, IppsGFpState* pGFp);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpSub_PE(const IppsGFpElement* pA, const IppsGFpElement* pParentB, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus m7_ippsGFpSub_PE(const IppsGFpElement* pA, const IppsGFpElement* pParentB, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus n8_ippsGFpSub_PE(const IppsGFpElement* pA, const IppsGFpElement* pParentB, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus y8_ippsGFpSub_PE(const IppsGFpElement* pA, const IppsGFpElement* pParentB, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus e9_ippsGFpSub_PE(const IppsGFpElement* pA, const IppsGFpElement* pParentB, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus l9_ippsGFpSub_PE(const IppsGFpElement* pA, const IppsGFpElement* pParentB, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus n0_ippsGFpSub_PE(const IppsGFpElement* pA, const IppsGFpElement* pParentB, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus k0_ippsGFpSub_PE(const IppsGFpElement* pA, const IppsGFpElement* pParentB, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus k1_ippsGFpSub_PE(const IppsGFpElement* pA, const IppsGFpElement* pParentB, IppsGFpElement* pR, IppsGFpState* pGFp);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpSub_PE,
	(IPP_PROC)m7_ippsGFpSub_PE,
	(IPP_PROC)n8_ippsGFpSub_PE,
	(IPP_PROC)y8_ippsGFpSub_PE,
	(IPP_PROC)e9_ippsGFpSub_PE,
	(IPP_PROC)l9_ippsGFpSub_PE,
	(IPP_PROC)n0_ippsGFpSub_PE,
	(IPP_PROC)k0_ippsGFpSub_PE,
	(IPP_PROC)k1_ippsGFpSub_PE
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpSub_PE,(const IppsGFpElement* pA, const IppsGFpElement* pParentB, IppsGFpElement* pR, IppsGFpState* pGFp))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpSub_PE,(const IppsGFpElement* pA, const IppsGFpElement* pParentB, IppsGFpElement* pR, IppsGFpState* pGFp))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpSub_PE]
        jmp  rax
  }
};
