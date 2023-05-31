#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsGFpElement* pA, IppsGFpElement* pR, IppsGFpState* pGFp);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpCpyElement(const IppsGFpElement* pA, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus m7_ippsGFpCpyElement(const IppsGFpElement* pA, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus n8_ippsGFpCpyElement(const IppsGFpElement* pA, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus y8_ippsGFpCpyElement(const IppsGFpElement* pA, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus e9_ippsGFpCpyElement(const IppsGFpElement* pA, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus l9_ippsGFpCpyElement(const IppsGFpElement* pA, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus n0_ippsGFpCpyElement(const IppsGFpElement* pA, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus k0_ippsGFpCpyElement(const IppsGFpElement* pA, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus k1_ippsGFpCpyElement(const IppsGFpElement* pA, IppsGFpElement* pR, IppsGFpState* pGFp);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpCpyElement,
	(IPP_PROC)m7_ippsGFpCpyElement,
	(IPP_PROC)n8_ippsGFpCpyElement,
	(IPP_PROC)y8_ippsGFpCpyElement,
	(IPP_PROC)e9_ippsGFpCpyElement,
	(IPP_PROC)l9_ippsGFpCpyElement,
	(IPP_PROC)n0_ippsGFpCpyElement,
	(IPP_PROC)k0_ippsGFpCpyElement,
	(IPP_PROC)k1_ippsGFpCpyElement
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpCpyElement,(const IppsGFpElement* pA, IppsGFpElement* pR, IppsGFpState* pGFp))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpCpyElement,(const IppsGFpElement* pA, IppsGFpElement* pR, IppsGFpState* pGFp))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpCpyElement]
        jmp  rax
  }
};
