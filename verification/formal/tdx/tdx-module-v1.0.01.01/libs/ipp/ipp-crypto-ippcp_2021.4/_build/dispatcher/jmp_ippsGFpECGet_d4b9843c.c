#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(IppsGFpState** const ppGFp, IppsGFpElement* pA, IppsGFpElement* pB, const IppsGFpECState* pEC);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpECGet(IppsGFpState** const ppGFp, IppsGFpElement* pA, IppsGFpElement* pB, const IppsGFpECState* pEC);
extern IppStatus m7_ippsGFpECGet(IppsGFpState** const ppGFp, IppsGFpElement* pA, IppsGFpElement* pB, const IppsGFpECState* pEC);
extern IppStatus n8_ippsGFpECGet(IppsGFpState** const ppGFp, IppsGFpElement* pA, IppsGFpElement* pB, const IppsGFpECState* pEC);
extern IppStatus y8_ippsGFpECGet(IppsGFpState** const ppGFp, IppsGFpElement* pA, IppsGFpElement* pB, const IppsGFpECState* pEC);
extern IppStatus e9_ippsGFpECGet(IppsGFpState** const ppGFp, IppsGFpElement* pA, IppsGFpElement* pB, const IppsGFpECState* pEC);
extern IppStatus l9_ippsGFpECGet(IppsGFpState** const ppGFp, IppsGFpElement* pA, IppsGFpElement* pB, const IppsGFpECState* pEC);
extern IppStatus n0_ippsGFpECGet(IppsGFpState** const ppGFp, IppsGFpElement* pA, IppsGFpElement* pB, const IppsGFpECState* pEC);
extern IppStatus k0_ippsGFpECGet(IppsGFpState** const ppGFp, IppsGFpElement* pA, IppsGFpElement* pB, const IppsGFpECState* pEC);
extern IppStatus k1_ippsGFpECGet(IppsGFpState** const ppGFp, IppsGFpElement* pA, IppsGFpElement* pB, const IppsGFpECState* pEC);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpECGet,
	(IPP_PROC)m7_ippsGFpECGet,
	(IPP_PROC)n8_ippsGFpECGet,
	(IPP_PROC)y8_ippsGFpECGet,
	(IPP_PROC)e9_ippsGFpECGet,
	(IPP_PROC)l9_ippsGFpECGet,
	(IPP_PROC)n0_ippsGFpECGet,
	(IPP_PROC)k0_ippsGFpECGet,
	(IPP_PROC)k1_ippsGFpECGet
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpECGet,(IppsGFpState** const ppGFp, IppsGFpElement* pA, IppsGFpElement* pB, const IppsGFpECState* pEC))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpECGet,(IppsGFpState** const ppGFp, IppsGFpElement* pA, IppsGFpElement* pB, const IppsGFpECState* pEC))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpECGet]
        jmp  rax
  }
};
