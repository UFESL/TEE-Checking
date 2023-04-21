#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pX, const IppsBigNumState* pY, IppsECCPPointState* pPoint, IppsECCPState* pEC);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsECCPSetPoint(const IppsBigNumState* pX, const IppsBigNumState* pY, IppsECCPPointState* pPoint, IppsECCPState* pEC);
extern IppStatus m7_ippsECCPSetPoint(const IppsBigNumState* pX, const IppsBigNumState* pY, IppsECCPPointState* pPoint, IppsECCPState* pEC);
extern IppStatus n8_ippsECCPSetPoint(const IppsBigNumState* pX, const IppsBigNumState* pY, IppsECCPPointState* pPoint, IppsECCPState* pEC);
extern IppStatus y8_ippsECCPSetPoint(const IppsBigNumState* pX, const IppsBigNumState* pY, IppsECCPPointState* pPoint, IppsECCPState* pEC);
extern IppStatus e9_ippsECCPSetPoint(const IppsBigNumState* pX, const IppsBigNumState* pY, IppsECCPPointState* pPoint, IppsECCPState* pEC);
extern IppStatus l9_ippsECCPSetPoint(const IppsBigNumState* pX, const IppsBigNumState* pY, IppsECCPPointState* pPoint, IppsECCPState* pEC);
extern IppStatus n0_ippsECCPSetPoint(const IppsBigNumState* pX, const IppsBigNumState* pY, IppsECCPPointState* pPoint, IppsECCPState* pEC);
extern IppStatus k0_ippsECCPSetPoint(const IppsBigNumState* pX, const IppsBigNumState* pY, IppsECCPPointState* pPoint, IppsECCPState* pEC);
extern IppStatus k1_ippsECCPSetPoint(const IppsBigNumState* pX, const IppsBigNumState* pY, IppsECCPPointState* pPoint, IppsECCPState* pEC);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsECCPSetPoint,
	(IPP_PROC)m7_ippsECCPSetPoint,
	(IPP_PROC)n8_ippsECCPSetPoint,
	(IPP_PROC)y8_ippsECCPSetPoint,
	(IPP_PROC)e9_ippsECCPSetPoint,
	(IPP_PROC)l9_ippsECCPSetPoint,
	(IPP_PROC)n0_ippsECCPSetPoint,
	(IPP_PROC)k0_ippsECCPSetPoint,
	(IPP_PROC)k1_ippsECCPSetPoint
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsECCPSetPoint,(const IppsBigNumState* pX, const IppsBigNumState* pY, IppsECCPPointState* pPoint, IppsECCPState* pEC))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsECCPSetPoint,(const IppsBigNumState* pX, const IppsBigNumState* pY, IppsECCPPointState* pPoint, IppsECCPState* pEC))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsECCPSetPoint]
        jmp  rax
  }
};
