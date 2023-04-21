#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsGFpECPoint* pP, const IppsGFpECPoint* pQ, IppECResult* pResult, IppsGFpECState* pEC);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpECCmpPoint(const IppsGFpECPoint* pP, const IppsGFpECPoint* pQ, IppECResult* pResult, IppsGFpECState* pEC);
extern IppStatus m7_ippsGFpECCmpPoint(const IppsGFpECPoint* pP, const IppsGFpECPoint* pQ, IppECResult* pResult, IppsGFpECState* pEC);
extern IppStatus n8_ippsGFpECCmpPoint(const IppsGFpECPoint* pP, const IppsGFpECPoint* pQ, IppECResult* pResult, IppsGFpECState* pEC);
extern IppStatus y8_ippsGFpECCmpPoint(const IppsGFpECPoint* pP, const IppsGFpECPoint* pQ, IppECResult* pResult, IppsGFpECState* pEC);
extern IppStatus e9_ippsGFpECCmpPoint(const IppsGFpECPoint* pP, const IppsGFpECPoint* pQ, IppECResult* pResult, IppsGFpECState* pEC);
extern IppStatus l9_ippsGFpECCmpPoint(const IppsGFpECPoint* pP, const IppsGFpECPoint* pQ, IppECResult* pResult, IppsGFpECState* pEC);
extern IppStatus n0_ippsGFpECCmpPoint(const IppsGFpECPoint* pP, const IppsGFpECPoint* pQ, IppECResult* pResult, IppsGFpECState* pEC);
extern IppStatus k0_ippsGFpECCmpPoint(const IppsGFpECPoint* pP, const IppsGFpECPoint* pQ, IppECResult* pResult, IppsGFpECState* pEC);
extern IppStatus k1_ippsGFpECCmpPoint(const IppsGFpECPoint* pP, const IppsGFpECPoint* pQ, IppECResult* pResult, IppsGFpECState* pEC);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpECCmpPoint,
	(IPP_PROC)m7_ippsGFpECCmpPoint,
	(IPP_PROC)n8_ippsGFpECCmpPoint,
	(IPP_PROC)y8_ippsGFpECCmpPoint,
	(IPP_PROC)e9_ippsGFpECCmpPoint,
	(IPP_PROC)l9_ippsGFpECCmpPoint,
	(IPP_PROC)n0_ippsGFpECCmpPoint,
	(IPP_PROC)k0_ippsGFpECCmpPoint,
	(IPP_PROC)k1_ippsGFpECCmpPoint
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpECCmpPoint,(const IppsGFpECPoint* pP, const IppsGFpECPoint* pQ, IppECResult* pResult, IppsGFpECState* pEC))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpECCmpPoint,(const IppsGFpECPoint* pP, const IppsGFpECPoint* pQ, IppECResult* pResult, IppsGFpECState* pEC))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpECCmpPoint]
        jmp  rax
  }
};
