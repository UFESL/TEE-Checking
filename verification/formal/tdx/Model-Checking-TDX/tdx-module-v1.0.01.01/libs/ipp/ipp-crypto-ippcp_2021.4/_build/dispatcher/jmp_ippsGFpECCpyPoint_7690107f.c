#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsGFpECPoint* pA, IppsGFpECPoint* pR, IppsGFpECState* pEC);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpECCpyPoint(const IppsGFpECPoint* pA, IppsGFpECPoint* pR, IppsGFpECState* pEC);
extern IppStatus m7_ippsGFpECCpyPoint(const IppsGFpECPoint* pA, IppsGFpECPoint* pR, IppsGFpECState* pEC);
extern IppStatus n8_ippsGFpECCpyPoint(const IppsGFpECPoint* pA, IppsGFpECPoint* pR, IppsGFpECState* pEC);
extern IppStatus y8_ippsGFpECCpyPoint(const IppsGFpECPoint* pA, IppsGFpECPoint* pR, IppsGFpECState* pEC);
extern IppStatus e9_ippsGFpECCpyPoint(const IppsGFpECPoint* pA, IppsGFpECPoint* pR, IppsGFpECState* pEC);
extern IppStatus l9_ippsGFpECCpyPoint(const IppsGFpECPoint* pA, IppsGFpECPoint* pR, IppsGFpECState* pEC);
extern IppStatus n0_ippsGFpECCpyPoint(const IppsGFpECPoint* pA, IppsGFpECPoint* pR, IppsGFpECState* pEC);
extern IppStatus k0_ippsGFpECCpyPoint(const IppsGFpECPoint* pA, IppsGFpECPoint* pR, IppsGFpECState* pEC);
extern IppStatus k1_ippsGFpECCpyPoint(const IppsGFpECPoint* pA, IppsGFpECPoint* pR, IppsGFpECState* pEC);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpECCpyPoint,
	(IPP_PROC)m7_ippsGFpECCpyPoint,
	(IPP_PROC)n8_ippsGFpECCpyPoint,
	(IPP_PROC)y8_ippsGFpECCpyPoint,
	(IPP_PROC)e9_ippsGFpECCpyPoint,
	(IPP_PROC)l9_ippsGFpECCpyPoint,
	(IPP_PROC)n0_ippsGFpECCpyPoint,
	(IPP_PROC)k0_ippsGFpECCpyPoint,
	(IPP_PROC)k1_ippsGFpECCpyPoint
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpECCpyPoint,(const IppsGFpECPoint* pA, IppsGFpECPoint* pR, IppsGFpECState* pEC))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpECCpyPoint,(const IppsGFpECPoint* pA, IppsGFpECPoint* pR, IppsGFpECState* pEC))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpECCpyPoint]
        jmp  rax
  }
};
