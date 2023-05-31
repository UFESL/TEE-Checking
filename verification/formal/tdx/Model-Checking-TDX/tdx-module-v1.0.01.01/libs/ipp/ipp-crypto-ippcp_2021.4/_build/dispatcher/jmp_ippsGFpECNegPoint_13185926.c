#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsGFpECPoint* pP, IppsGFpECPoint* pR, IppsGFpECState* pEC);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpECNegPoint(const IppsGFpECPoint* pP, IppsGFpECPoint* pR, IppsGFpECState* pEC);
extern IppStatus m7_ippsGFpECNegPoint(const IppsGFpECPoint* pP, IppsGFpECPoint* pR, IppsGFpECState* pEC);
extern IppStatus n8_ippsGFpECNegPoint(const IppsGFpECPoint* pP, IppsGFpECPoint* pR, IppsGFpECState* pEC);
extern IppStatus y8_ippsGFpECNegPoint(const IppsGFpECPoint* pP, IppsGFpECPoint* pR, IppsGFpECState* pEC);
extern IppStatus e9_ippsGFpECNegPoint(const IppsGFpECPoint* pP, IppsGFpECPoint* pR, IppsGFpECState* pEC);
extern IppStatus l9_ippsGFpECNegPoint(const IppsGFpECPoint* pP, IppsGFpECPoint* pR, IppsGFpECState* pEC);
extern IppStatus n0_ippsGFpECNegPoint(const IppsGFpECPoint* pP, IppsGFpECPoint* pR, IppsGFpECState* pEC);
extern IppStatus k0_ippsGFpECNegPoint(const IppsGFpECPoint* pP, IppsGFpECPoint* pR, IppsGFpECState* pEC);
extern IppStatus k1_ippsGFpECNegPoint(const IppsGFpECPoint* pP, IppsGFpECPoint* pR, IppsGFpECState* pEC);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpECNegPoint,
	(IPP_PROC)m7_ippsGFpECNegPoint,
	(IPP_PROC)n8_ippsGFpECNegPoint,
	(IPP_PROC)y8_ippsGFpECNegPoint,
	(IPP_PROC)e9_ippsGFpECNegPoint,
	(IPP_PROC)l9_ippsGFpECNegPoint,
	(IPP_PROC)n0_ippsGFpECNegPoint,
	(IPP_PROC)k0_ippsGFpECNegPoint,
	(IPP_PROC)k1_ippsGFpECNegPoint
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpECNegPoint,(const IppsGFpECPoint* pP, IppsGFpECPoint* pR, IppsGFpECState* pEC))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpECNegPoint,(const IppsGFpECPoint* pP, IppsGFpECPoint* pR, IppsGFpECState* pEC))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpECNegPoint]
        jmp  rax
  }
};
