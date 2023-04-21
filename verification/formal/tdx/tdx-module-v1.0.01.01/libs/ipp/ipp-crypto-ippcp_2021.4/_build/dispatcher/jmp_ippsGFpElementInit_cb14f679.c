#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp32u* pA, int lenA, IppsGFpElement* pR, IppsGFpState* pGFp);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpElementInit(const Ipp32u* pA, int lenA, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus m7_ippsGFpElementInit(const Ipp32u* pA, int lenA, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus n8_ippsGFpElementInit(const Ipp32u* pA, int lenA, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus y8_ippsGFpElementInit(const Ipp32u* pA, int lenA, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus e9_ippsGFpElementInit(const Ipp32u* pA, int lenA, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus l9_ippsGFpElementInit(const Ipp32u* pA, int lenA, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus n0_ippsGFpElementInit(const Ipp32u* pA, int lenA, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus k0_ippsGFpElementInit(const Ipp32u* pA, int lenA, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus k1_ippsGFpElementInit(const Ipp32u* pA, int lenA, IppsGFpElement* pR, IppsGFpState* pGFp);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpElementInit,
	(IPP_PROC)m7_ippsGFpElementInit,
	(IPP_PROC)n8_ippsGFpElementInit,
	(IPP_PROC)y8_ippsGFpElementInit,
	(IPP_PROC)e9_ippsGFpElementInit,
	(IPP_PROC)l9_ippsGFpElementInit,
	(IPP_PROC)n0_ippsGFpElementInit,
	(IPP_PROC)k0_ippsGFpElementInit,
	(IPP_PROC)k1_ippsGFpElementInit
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpElementInit,(const Ipp32u* pA, int lenA, IppsGFpElement* pR, IppsGFpState* pGFp))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpElementInit,(const Ipp32u* pA, int lenA, IppsGFpElement* pR, IppsGFpState* pGFp))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpElementInit]
        jmp  rax
  }
};
