#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(IppsBigNumState* pX, IppsBigNumState* pY, const IppsECCPPointState* pPoint, IppsECCPState* pEC);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsECCPGetPoint(IppsBigNumState* pX, IppsBigNumState* pY, const IppsECCPPointState* pPoint, IppsECCPState* pEC);
extern IppStatus m7_ippsECCPGetPoint(IppsBigNumState* pX, IppsBigNumState* pY, const IppsECCPPointState* pPoint, IppsECCPState* pEC);
extern IppStatus n8_ippsECCPGetPoint(IppsBigNumState* pX, IppsBigNumState* pY, const IppsECCPPointState* pPoint, IppsECCPState* pEC);
extern IppStatus y8_ippsECCPGetPoint(IppsBigNumState* pX, IppsBigNumState* pY, const IppsECCPPointState* pPoint, IppsECCPState* pEC);
extern IppStatus e9_ippsECCPGetPoint(IppsBigNumState* pX, IppsBigNumState* pY, const IppsECCPPointState* pPoint, IppsECCPState* pEC);
extern IppStatus l9_ippsECCPGetPoint(IppsBigNumState* pX, IppsBigNumState* pY, const IppsECCPPointState* pPoint, IppsECCPState* pEC);
extern IppStatus n0_ippsECCPGetPoint(IppsBigNumState* pX, IppsBigNumState* pY, const IppsECCPPointState* pPoint, IppsECCPState* pEC);
extern IppStatus k0_ippsECCPGetPoint(IppsBigNumState* pX, IppsBigNumState* pY, const IppsECCPPointState* pPoint, IppsECCPState* pEC);
extern IppStatus k1_ippsECCPGetPoint(IppsBigNumState* pX, IppsBigNumState* pY, const IppsECCPPointState* pPoint, IppsECCPState* pEC);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsECCPGetPoint,
	(IPP_PROC)m7_ippsECCPGetPoint,
	(IPP_PROC)n8_ippsECCPGetPoint,
	(IPP_PROC)y8_ippsECCPGetPoint,
	(IPP_PROC)e9_ippsECCPGetPoint,
	(IPP_PROC)l9_ippsECCPGetPoint,
	(IPP_PROC)n0_ippsECCPGetPoint,
	(IPP_PROC)k0_ippsECCPGetPoint,
	(IPP_PROC)k1_ippsECCPGetPoint
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsECCPGetPoint,(IppsBigNumState* pX, IppsBigNumState* pY, const IppsECCPPointState* pPoint, IppsECCPState* pEC))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsECCPGetPoint,(IppsBigNumState* pX, IppsBigNumState* pY, const IppsECCPPointState* pPoint, IppsECCPState* pEC))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsECCPGetPoint]
        jmp  rax
  }
};
