#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp32u* pA, int lenA, IppsGFpElement* pR, IppsGFpState* pGFp);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpSetElement(const Ipp32u* pA, int lenA, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus m7_ippsGFpSetElement(const Ipp32u* pA, int lenA, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus n8_ippsGFpSetElement(const Ipp32u* pA, int lenA, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus y8_ippsGFpSetElement(const Ipp32u* pA, int lenA, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus e9_ippsGFpSetElement(const Ipp32u* pA, int lenA, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus l9_ippsGFpSetElement(const Ipp32u* pA, int lenA, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus n0_ippsGFpSetElement(const Ipp32u* pA, int lenA, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus k0_ippsGFpSetElement(const Ipp32u* pA, int lenA, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus k1_ippsGFpSetElement(const Ipp32u* pA, int lenA, IppsGFpElement* pR, IppsGFpState* pGFp);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpSetElement,
	(IPP_PROC)m7_ippsGFpSetElement,
	(IPP_PROC)n8_ippsGFpSetElement,
	(IPP_PROC)y8_ippsGFpSetElement,
	(IPP_PROC)e9_ippsGFpSetElement,
	(IPP_PROC)l9_ippsGFpSetElement,
	(IPP_PROC)n0_ippsGFpSetElement,
	(IPP_PROC)k0_ippsGFpSetElement,
	(IPP_PROC)k1_ippsGFpSetElement
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpSetElement,(const Ipp32u* pA, int lenA, IppsGFpElement* pR, IppsGFpState* pGFp))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpSetElement,(const Ipp32u* pA, int lenA, IppsGFpElement* pR, IppsGFpState* pGFp))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpSetElement]
        jmp  rax
  }
};
