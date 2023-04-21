#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsGFpState* pGFp, const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpECState* pEC);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpECInit(const IppsGFpState* pGFp, const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpECState* pEC);
extern IppStatus m7_ippsGFpECInit(const IppsGFpState* pGFp, const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpECState* pEC);
extern IppStatus n8_ippsGFpECInit(const IppsGFpState* pGFp, const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpECState* pEC);
extern IppStatus y8_ippsGFpECInit(const IppsGFpState* pGFp, const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpECState* pEC);
extern IppStatus e9_ippsGFpECInit(const IppsGFpState* pGFp, const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpECState* pEC);
extern IppStatus l9_ippsGFpECInit(const IppsGFpState* pGFp, const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpECState* pEC);
extern IppStatus n0_ippsGFpECInit(const IppsGFpState* pGFp, const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpECState* pEC);
extern IppStatus k0_ippsGFpECInit(const IppsGFpState* pGFp, const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpECState* pEC);
extern IppStatus k1_ippsGFpECInit(const IppsGFpState* pGFp, const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpECState* pEC);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpECInit,
	(IPP_PROC)m7_ippsGFpECInit,
	(IPP_PROC)n8_ippsGFpECInit,
	(IPP_PROC)y8_ippsGFpECInit,
	(IPP_PROC)e9_ippsGFpECInit,
	(IPP_PROC)l9_ippsGFpECInit,
	(IPP_PROC)n0_ippsGFpECInit,
	(IPP_PROC)k0_ippsGFpECInit,
	(IPP_PROC)k1_ippsGFpECInit
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpECInit,(const IppsGFpState* pGFp, const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpECState* pEC))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpECInit,(const IppsGFpState* pGFp, const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpECState* pEC))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpECInit]
        jmp  rax
  }
};
