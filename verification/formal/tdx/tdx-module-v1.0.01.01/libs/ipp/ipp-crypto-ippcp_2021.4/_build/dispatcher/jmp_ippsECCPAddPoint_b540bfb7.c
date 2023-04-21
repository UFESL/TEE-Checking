#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsECCPPointState* pP, const IppsECCPPointState* pQ, IppsECCPPointState* pR, IppsECCPState* pEC);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsECCPAddPoint(const IppsECCPPointState* pP, const IppsECCPPointState* pQ, IppsECCPPointState* pR, IppsECCPState* pEC);
extern IppStatus m7_ippsECCPAddPoint(const IppsECCPPointState* pP, const IppsECCPPointState* pQ, IppsECCPPointState* pR, IppsECCPState* pEC);
extern IppStatus n8_ippsECCPAddPoint(const IppsECCPPointState* pP, const IppsECCPPointState* pQ, IppsECCPPointState* pR, IppsECCPState* pEC);
extern IppStatus y8_ippsECCPAddPoint(const IppsECCPPointState* pP, const IppsECCPPointState* pQ, IppsECCPPointState* pR, IppsECCPState* pEC);
extern IppStatus e9_ippsECCPAddPoint(const IppsECCPPointState* pP, const IppsECCPPointState* pQ, IppsECCPPointState* pR, IppsECCPState* pEC);
extern IppStatus l9_ippsECCPAddPoint(const IppsECCPPointState* pP, const IppsECCPPointState* pQ, IppsECCPPointState* pR, IppsECCPState* pEC);
extern IppStatus n0_ippsECCPAddPoint(const IppsECCPPointState* pP, const IppsECCPPointState* pQ, IppsECCPPointState* pR, IppsECCPState* pEC);
extern IppStatus k0_ippsECCPAddPoint(const IppsECCPPointState* pP, const IppsECCPPointState* pQ, IppsECCPPointState* pR, IppsECCPState* pEC);
extern IppStatus k1_ippsECCPAddPoint(const IppsECCPPointState* pP, const IppsECCPPointState* pQ, IppsECCPPointState* pR, IppsECCPState* pEC);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsECCPAddPoint,
	(IPP_PROC)m7_ippsECCPAddPoint,
	(IPP_PROC)n8_ippsECCPAddPoint,
	(IPP_PROC)y8_ippsECCPAddPoint,
	(IPP_PROC)e9_ippsECCPAddPoint,
	(IPP_PROC)l9_ippsECCPAddPoint,
	(IPP_PROC)n0_ippsECCPAddPoint,
	(IPP_PROC)k0_ippsECCPAddPoint,
	(IPP_PROC)k1_ippsECCPAddPoint
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsECCPAddPoint,(const IppsECCPPointState* pP, const IppsECCPPointState* pQ, IppsECCPPointState* pR, IppsECCPState* pEC))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsECCPAddPoint,(const IppsECCPPointState* pP, const IppsECCPPointState* pQ, IppsECCPPointState* pR, IppsECCPState* pEC))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsECCPAddPoint]
        jmp  rax
  }
};
