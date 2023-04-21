#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(IppsGFpECPoint* pPoint, IppsGFpECState* pEC);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpECSetPointAtInfinity(IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
extern IppStatus m7_ippsGFpECSetPointAtInfinity(IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
extern IppStatus n8_ippsGFpECSetPointAtInfinity(IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
extern IppStatus y8_ippsGFpECSetPointAtInfinity(IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
extern IppStatus e9_ippsGFpECSetPointAtInfinity(IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
extern IppStatus l9_ippsGFpECSetPointAtInfinity(IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
extern IppStatus n0_ippsGFpECSetPointAtInfinity(IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
extern IppStatus k0_ippsGFpECSetPointAtInfinity(IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
extern IppStatus k1_ippsGFpECSetPointAtInfinity(IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpECSetPointAtInfinity,
	(IPP_PROC)m7_ippsGFpECSetPointAtInfinity,
	(IPP_PROC)n8_ippsGFpECSetPointAtInfinity,
	(IPP_PROC)y8_ippsGFpECSetPointAtInfinity,
	(IPP_PROC)e9_ippsGFpECSetPointAtInfinity,
	(IPP_PROC)l9_ippsGFpECSetPointAtInfinity,
	(IPP_PROC)n0_ippsGFpECSetPointAtInfinity,
	(IPP_PROC)k0_ippsGFpECSetPointAtInfinity,
	(IPP_PROC)k1_ippsGFpECSetPointAtInfinity
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpECSetPointAtInfinity,(IppsGFpECPoint* pPoint, IppsGFpECState* pEC))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpECSetPointAtInfinity,(IppsGFpECPoint* pPoint, IppsGFpECState* pEC))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpECSetPointAtInfinity]
        jmp  rax
  }
};
