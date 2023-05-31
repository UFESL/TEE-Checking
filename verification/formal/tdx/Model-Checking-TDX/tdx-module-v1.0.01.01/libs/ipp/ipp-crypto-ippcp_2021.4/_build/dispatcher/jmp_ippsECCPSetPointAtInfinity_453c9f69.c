#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(IppsECCPPointState* pPoint, IppsECCPState* pEC);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsECCPSetPointAtInfinity(IppsECCPPointState* pPoint, IppsECCPState* pEC);
extern IppStatus m7_ippsECCPSetPointAtInfinity(IppsECCPPointState* pPoint, IppsECCPState* pEC);
extern IppStatus n8_ippsECCPSetPointAtInfinity(IppsECCPPointState* pPoint, IppsECCPState* pEC);
extern IppStatus y8_ippsECCPSetPointAtInfinity(IppsECCPPointState* pPoint, IppsECCPState* pEC);
extern IppStatus e9_ippsECCPSetPointAtInfinity(IppsECCPPointState* pPoint, IppsECCPState* pEC);
extern IppStatus l9_ippsECCPSetPointAtInfinity(IppsECCPPointState* pPoint, IppsECCPState* pEC);
extern IppStatus n0_ippsECCPSetPointAtInfinity(IppsECCPPointState* pPoint, IppsECCPState* pEC);
extern IppStatus k0_ippsECCPSetPointAtInfinity(IppsECCPPointState* pPoint, IppsECCPState* pEC);
extern IppStatus k1_ippsECCPSetPointAtInfinity(IppsECCPPointState* pPoint, IppsECCPState* pEC);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsECCPSetPointAtInfinity,
	(IPP_PROC)m7_ippsECCPSetPointAtInfinity,
	(IPP_PROC)n8_ippsECCPSetPointAtInfinity,
	(IPP_PROC)y8_ippsECCPSetPointAtInfinity,
	(IPP_PROC)e9_ippsECCPSetPointAtInfinity,
	(IPP_PROC)l9_ippsECCPSetPointAtInfinity,
	(IPP_PROC)n0_ippsECCPSetPointAtInfinity,
	(IPP_PROC)k0_ippsECCPSetPointAtInfinity,
	(IPP_PROC)k1_ippsECCPSetPointAtInfinity
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsECCPSetPointAtInfinity,(IppsECCPPointState* pPoint, IppsECCPState* pEC))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsECCPSetPointAtInfinity,(IppsECCPPointState* pPoint, IppsECCPState* pEC))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsECCPSetPointAtInfinity]
        jmp  rax
  }
};
