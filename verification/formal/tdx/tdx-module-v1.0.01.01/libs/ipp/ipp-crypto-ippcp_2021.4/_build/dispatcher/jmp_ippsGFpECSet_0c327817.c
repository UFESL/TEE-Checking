#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpECState* pEC);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpECSet(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpECState* pEC);
extern IppStatus m7_ippsGFpECSet(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpECState* pEC);
extern IppStatus n8_ippsGFpECSet(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpECState* pEC);
extern IppStatus y8_ippsGFpECSet(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpECState* pEC);
extern IppStatus e9_ippsGFpECSet(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpECState* pEC);
extern IppStatus l9_ippsGFpECSet(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpECState* pEC);
extern IppStatus n0_ippsGFpECSet(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpECState* pEC);
extern IppStatus k0_ippsGFpECSet(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpECState* pEC);
extern IppStatus k1_ippsGFpECSet(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpECState* pEC);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpECSet,
	(IPP_PROC)m7_ippsGFpECSet,
	(IPP_PROC)n8_ippsGFpECSet,
	(IPP_PROC)y8_ippsGFpECSet,
	(IPP_PROC)e9_ippsGFpECSet,
	(IPP_PROC)l9_ippsGFpECSet,
	(IPP_PROC)n0_ippsGFpECSet,
	(IPP_PROC)k0_ippsGFpECSet,
	(IPP_PROC)k1_ippsGFpECSet
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpECSet,(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpECState* pEC))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpECSet,(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpECState* pEC))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpECSet]
        jmp  rax
  }
};
