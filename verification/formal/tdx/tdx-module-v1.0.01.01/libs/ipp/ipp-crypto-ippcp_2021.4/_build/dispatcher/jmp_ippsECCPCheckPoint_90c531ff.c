#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsECCPPointState* pP, IppECResult* pResult, IppsECCPState* pEC);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsECCPCheckPoint(const IppsECCPPointState* pP, IppECResult* pResult, IppsECCPState* pEC);
extern IppStatus m7_ippsECCPCheckPoint(const IppsECCPPointState* pP, IppECResult* pResult, IppsECCPState* pEC);
extern IppStatus n8_ippsECCPCheckPoint(const IppsECCPPointState* pP, IppECResult* pResult, IppsECCPState* pEC);
extern IppStatus y8_ippsECCPCheckPoint(const IppsECCPPointState* pP, IppECResult* pResult, IppsECCPState* pEC);
extern IppStatus e9_ippsECCPCheckPoint(const IppsECCPPointState* pP, IppECResult* pResult, IppsECCPState* pEC);
extern IppStatus l9_ippsECCPCheckPoint(const IppsECCPPointState* pP, IppECResult* pResult, IppsECCPState* pEC);
extern IppStatus n0_ippsECCPCheckPoint(const IppsECCPPointState* pP, IppECResult* pResult, IppsECCPState* pEC);
extern IppStatus k0_ippsECCPCheckPoint(const IppsECCPPointState* pP, IppECResult* pResult, IppsECCPState* pEC);
extern IppStatus k1_ippsECCPCheckPoint(const IppsECCPPointState* pP, IppECResult* pResult, IppsECCPState* pEC);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsECCPCheckPoint,
	(IPP_PROC)m7_ippsECCPCheckPoint,
	(IPP_PROC)n8_ippsECCPCheckPoint,
	(IPP_PROC)y8_ippsECCPCheckPoint,
	(IPP_PROC)e9_ippsECCPCheckPoint,
	(IPP_PROC)l9_ippsECCPCheckPoint,
	(IPP_PROC)n0_ippsECCPCheckPoint,
	(IPP_PROC)k0_ippsECCPCheckPoint,
	(IPP_PROC)k1_ippsECCPCheckPoint
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsECCPCheckPoint,(const IppsECCPPointState* pP, IppECResult* pResult, IppsECCPState* pEC))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsECCPCheckPoint,(const IppsECCPPointState* pP, IppECResult* pResult, IppsECCPState* pEC))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsECCPCheckPoint]
        jmp  rax
  }
};
