#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsGFpElement* pA, int* pResult, const IppsGFpState* pGFp);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpIsUnityElement(const IppsGFpElement* pA, int* pResult, const IppsGFpState* pGFp);
extern IppStatus m7_ippsGFpIsUnityElement(const IppsGFpElement* pA, int* pResult, const IppsGFpState* pGFp);
extern IppStatus n8_ippsGFpIsUnityElement(const IppsGFpElement* pA, int* pResult, const IppsGFpState* pGFp);
extern IppStatus y8_ippsGFpIsUnityElement(const IppsGFpElement* pA, int* pResult, const IppsGFpState* pGFp);
extern IppStatus e9_ippsGFpIsUnityElement(const IppsGFpElement* pA, int* pResult, const IppsGFpState* pGFp);
extern IppStatus l9_ippsGFpIsUnityElement(const IppsGFpElement* pA, int* pResult, const IppsGFpState* pGFp);
extern IppStatus n0_ippsGFpIsUnityElement(const IppsGFpElement* pA, int* pResult, const IppsGFpState* pGFp);
extern IppStatus k0_ippsGFpIsUnityElement(const IppsGFpElement* pA, int* pResult, const IppsGFpState* pGFp);
extern IppStatus k1_ippsGFpIsUnityElement(const IppsGFpElement* pA, int* pResult, const IppsGFpState* pGFp);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpIsUnityElement,
	(IPP_PROC)m7_ippsGFpIsUnityElement,
	(IPP_PROC)n8_ippsGFpIsUnityElement,
	(IPP_PROC)y8_ippsGFpIsUnityElement,
	(IPP_PROC)e9_ippsGFpIsUnityElement,
	(IPP_PROC)l9_ippsGFpIsUnityElement,
	(IPP_PROC)n0_ippsGFpIsUnityElement,
	(IPP_PROC)k0_ippsGFpIsUnityElement,
	(IPP_PROC)k1_ippsGFpIsUnityElement
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpIsUnityElement,(const IppsGFpElement* pA, int* pResult, const IppsGFpState* pGFp))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpIsUnityElement,(const IppsGFpElement* pA, int* pResult, const IppsGFpState* pGFp))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpIsUnityElement]
        jmp  rax
  }
};
