#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsGFpElement* pA, Ipp32u* pDataA, int lenA, IppsGFpState* pGFp);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpGetElement(const IppsGFpElement* pA, Ipp32u* pDataA, int lenA, IppsGFpState* pGFp);
extern IppStatus m7_ippsGFpGetElement(const IppsGFpElement* pA, Ipp32u* pDataA, int lenA, IppsGFpState* pGFp);
extern IppStatus n8_ippsGFpGetElement(const IppsGFpElement* pA, Ipp32u* pDataA, int lenA, IppsGFpState* pGFp);
extern IppStatus y8_ippsGFpGetElement(const IppsGFpElement* pA, Ipp32u* pDataA, int lenA, IppsGFpState* pGFp);
extern IppStatus e9_ippsGFpGetElement(const IppsGFpElement* pA, Ipp32u* pDataA, int lenA, IppsGFpState* pGFp);
extern IppStatus l9_ippsGFpGetElement(const IppsGFpElement* pA, Ipp32u* pDataA, int lenA, IppsGFpState* pGFp);
extern IppStatus n0_ippsGFpGetElement(const IppsGFpElement* pA, Ipp32u* pDataA, int lenA, IppsGFpState* pGFp);
extern IppStatus k0_ippsGFpGetElement(const IppsGFpElement* pA, Ipp32u* pDataA, int lenA, IppsGFpState* pGFp);
extern IppStatus k1_ippsGFpGetElement(const IppsGFpElement* pA, Ipp32u* pDataA, int lenA, IppsGFpState* pGFp);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpGetElement,
	(IPP_PROC)m7_ippsGFpGetElement,
	(IPP_PROC)n8_ippsGFpGetElement,
	(IPP_PROC)y8_ippsGFpGetElement,
	(IPP_PROC)e9_ippsGFpGetElement,
	(IPP_PROC)l9_ippsGFpGetElement,
	(IPP_PROC)n0_ippsGFpGetElement,
	(IPP_PROC)k0_ippsGFpGetElement,
	(IPP_PROC)k1_ippsGFpGetElement
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpGetElement,(const IppsGFpElement* pA, Ipp32u* pDataA, int lenA, IppsGFpState* pGFp))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpGetElement,(const IppsGFpElement* pA, Ipp32u* pDataA, int lenA, IppsGFpState* pGFp))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpGetElement]
        jmp  rax
  }
};
