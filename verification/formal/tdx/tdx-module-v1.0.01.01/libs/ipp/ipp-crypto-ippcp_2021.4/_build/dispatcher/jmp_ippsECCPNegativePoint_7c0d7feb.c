#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsECCPPointState* pP, IppsECCPPointState* pR, IppsECCPState* pEC);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsECCPNegativePoint(const IppsECCPPointState* pP, IppsECCPPointState* pR, IppsECCPState* pEC);
extern IppStatus m7_ippsECCPNegativePoint(const IppsECCPPointState* pP, IppsECCPPointState* pR, IppsECCPState* pEC);
extern IppStatus n8_ippsECCPNegativePoint(const IppsECCPPointState* pP, IppsECCPPointState* pR, IppsECCPState* pEC);
extern IppStatus y8_ippsECCPNegativePoint(const IppsECCPPointState* pP, IppsECCPPointState* pR, IppsECCPState* pEC);
extern IppStatus e9_ippsECCPNegativePoint(const IppsECCPPointState* pP, IppsECCPPointState* pR, IppsECCPState* pEC);
extern IppStatus l9_ippsECCPNegativePoint(const IppsECCPPointState* pP, IppsECCPPointState* pR, IppsECCPState* pEC);
extern IppStatus n0_ippsECCPNegativePoint(const IppsECCPPointState* pP, IppsECCPPointState* pR, IppsECCPState* pEC);
extern IppStatus k0_ippsECCPNegativePoint(const IppsECCPPointState* pP, IppsECCPPointState* pR, IppsECCPState* pEC);
extern IppStatus k1_ippsECCPNegativePoint(const IppsECCPPointState* pP, IppsECCPPointState* pR, IppsECCPState* pEC);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsECCPNegativePoint,
	(IPP_PROC)m7_ippsECCPNegativePoint,
	(IPP_PROC)n8_ippsECCPNegativePoint,
	(IPP_PROC)y8_ippsECCPNegativePoint,
	(IPP_PROC)e9_ippsECCPNegativePoint,
	(IPP_PROC)l9_ippsECCPNegativePoint,
	(IPP_PROC)n0_ippsECCPNegativePoint,
	(IPP_PROC)k0_ippsECCPNegativePoint,
	(IPP_PROC)k1_ippsECCPNegativePoint
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsECCPNegativePoint,(const IppsECCPPointState* pP, IppsECCPPointState* pR, IppsECCPState* pEC))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsECCPNegativePoint,(const IppsECCPPointState* pP, IppsECCPPointState* pR, IppsECCPState* pEC))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsECCPNegativePoint]
        jmp  rax
  }
};
