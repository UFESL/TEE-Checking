#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsGFpElement* pA, int* pResult, const IppsGFpState* pGFp);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpIsZeroElement(const IppsGFpElement* pA, int* pResult, const IppsGFpState* pGFp);
extern IppStatus m7_ippsGFpIsZeroElement(const IppsGFpElement* pA, int* pResult, const IppsGFpState* pGFp);
extern IppStatus n8_ippsGFpIsZeroElement(const IppsGFpElement* pA, int* pResult, const IppsGFpState* pGFp);
extern IppStatus y8_ippsGFpIsZeroElement(const IppsGFpElement* pA, int* pResult, const IppsGFpState* pGFp);
extern IppStatus e9_ippsGFpIsZeroElement(const IppsGFpElement* pA, int* pResult, const IppsGFpState* pGFp);
extern IppStatus l9_ippsGFpIsZeroElement(const IppsGFpElement* pA, int* pResult, const IppsGFpState* pGFp);
extern IppStatus n0_ippsGFpIsZeroElement(const IppsGFpElement* pA, int* pResult, const IppsGFpState* pGFp);
extern IppStatus k0_ippsGFpIsZeroElement(const IppsGFpElement* pA, int* pResult, const IppsGFpState* pGFp);
extern IppStatus k1_ippsGFpIsZeroElement(const IppsGFpElement* pA, int* pResult, const IppsGFpState* pGFp);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpIsZeroElement,
	(IPP_PROC)m7_ippsGFpIsZeroElement,
	(IPP_PROC)n8_ippsGFpIsZeroElement,
	(IPP_PROC)y8_ippsGFpIsZeroElement,
	(IPP_PROC)e9_ippsGFpIsZeroElement,
	(IPP_PROC)l9_ippsGFpIsZeroElement,
	(IPP_PROC)n0_ippsGFpIsZeroElement,
	(IPP_PROC)k0_ippsGFpIsZeroElement,
	(IPP_PROC)k1_ippsGFpIsZeroElement
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpIsZeroElement,(const IppsGFpElement* pA, int* pResult, const IppsGFpState* pGFp))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpIsZeroElement,(const IppsGFpElement* pA, int* pResult, const IppsGFpState* pGFp))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpIsZeroElement]
        jmp  rax
  }
};
