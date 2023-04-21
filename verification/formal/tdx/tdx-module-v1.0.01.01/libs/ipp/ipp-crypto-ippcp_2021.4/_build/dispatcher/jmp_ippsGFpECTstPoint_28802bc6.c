#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsGFpECPoint* pP, IppECResult* pResult, IppsGFpECState* pEC);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpECTstPoint(const IppsGFpECPoint* pP, IppECResult* pResult, IppsGFpECState* pEC);
extern IppStatus m7_ippsGFpECTstPoint(const IppsGFpECPoint* pP, IppECResult* pResult, IppsGFpECState* pEC);
extern IppStatus n8_ippsGFpECTstPoint(const IppsGFpECPoint* pP, IppECResult* pResult, IppsGFpECState* pEC);
extern IppStatus y8_ippsGFpECTstPoint(const IppsGFpECPoint* pP, IppECResult* pResult, IppsGFpECState* pEC);
extern IppStatus e9_ippsGFpECTstPoint(const IppsGFpECPoint* pP, IppECResult* pResult, IppsGFpECState* pEC);
extern IppStatus l9_ippsGFpECTstPoint(const IppsGFpECPoint* pP, IppECResult* pResult, IppsGFpECState* pEC);
extern IppStatus n0_ippsGFpECTstPoint(const IppsGFpECPoint* pP, IppECResult* pResult, IppsGFpECState* pEC);
extern IppStatus k0_ippsGFpECTstPoint(const IppsGFpECPoint* pP, IppECResult* pResult, IppsGFpECState* pEC);
extern IppStatus k1_ippsGFpECTstPoint(const IppsGFpECPoint* pP, IppECResult* pResult, IppsGFpECState* pEC);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpECTstPoint,
	(IPP_PROC)m7_ippsGFpECTstPoint,
	(IPP_PROC)n8_ippsGFpECTstPoint,
	(IPP_PROC)y8_ippsGFpECTstPoint,
	(IPP_PROC)e9_ippsGFpECTstPoint,
	(IPP_PROC)l9_ippsGFpECTstPoint,
	(IPP_PROC)n0_ippsGFpECTstPoint,
	(IPP_PROC)k0_ippsGFpECTstPoint,
	(IPP_PROC)k1_ippsGFpECTstPoint
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpECTstPoint,(const IppsGFpECPoint* pP, IppECResult* pResult, IppsGFpECState* pEC))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpECTstPoint,(const IppsGFpECPoint* pP, IppECResult* pResult, IppsGFpECState* pEC))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpECTstPoint]
        jmp  rax
  }
};
