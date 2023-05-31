#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsGFpElement* pA, const IppsGFpElement* pB, int* pResult, const IppsGFpState* pGFp);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpCmpElement(const IppsGFpElement* pA, const IppsGFpElement* pB, int* pResult, const IppsGFpState* pGFp);
extern IppStatus m7_ippsGFpCmpElement(const IppsGFpElement* pA, const IppsGFpElement* pB, int* pResult, const IppsGFpState* pGFp);
extern IppStatus n8_ippsGFpCmpElement(const IppsGFpElement* pA, const IppsGFpElement* pB, int* pResult, const IppsGFpState* pGFp);
extern IppStatus y8_ippsGFpCmpElement(const IppsGFpElement* pA, const IppsGFpElement* pB, int* pResult, const IppsGFpState* pGFp);
extern IppStatus e9_ippsGFpCmpElement(const IppsGFpElement* pA, const IppsGFpElement* pB, int* pResult, const IppsGFpState* pGFp);
extern IppStatus l9_ippsGFpCmpElement(const IppsGFpElement* pA, const IppsGFpElement* pB, int* pResult, const IppsGFpState* pGFp);
extern IppStatus n0_ippsGFpCmpElement(const IppsGFpElement* pA, const IppsGFpElement* pB, int* pResult, const IppsGFpState* pGFp);
extern IppStatus k0_ippsGFpCmpElement(const IppsGFpElement* pA, const IppsGFpElement* pB, int* pResult, const IppsGFpState* pGFp);
extern IppStatus k1_ippsGFpCmpElement(const IppsGFpElement* pA, const IppsGFpElement* pB, int* pResult, const IppsGFpState* pGFp);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpCmpElement,
	(IPP_PROC)m7_ippsGFpCmpElement,
	(IPP_PROC)n8_ippsGFpCmpElement,
	(IPP_PROC)y8_ippsGFpCmpElement,
	(IPP_PROC)e9_ippsGFpCmpElement,
	(IPP_PROC)l9_ippsGFpCmpElement,
	(IPP_PROC)n0_ippsGFpCmpElement,
	(IPP_PROC)k0_ippsGFpCmpElement,
	(IPP_PROC)k1_ippsGFpCmpElement
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpCmpElement,(const IppsGFpElement* pA, const IppsGFpElement* pB, int* pResult, const IppsGFpState* pGFp))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpCmpElement,(const IppsGFpElement* pA, const IppsGFpElement* pB, int* pResult, const IppsGFpState* pGFp))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpCmpElement]
        jmp  rax
  }
};
