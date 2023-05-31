#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsGFpECPoint* pP, const IppsGFpECPoint* pQ, IppsGFpECPoint* pR, IppsGFpECState* pEC);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpECAddPoint(const IppsGFpECPoint* pP, const IppsGFpECPoint* pQ, IppsGFpECPoint* pR, IppsGFpECState* pEC);
extern IppStatus m7_ippsGFpECAddPoint(const IppsGFpECPoint* pP, const IppsGFpECPoint* pQ, IppsGFpECPoint* pR, IppsGFpECState* pEC);
extern IppStatus n8_ippsGFpECAddPoint(const IppsGFpECPoint* pP, const IppsGFpECPoint* pQ, IppsGFpECPoint* pR, IppsGFpECState* pEC);
extern IppStatus y8_ippsGFpECAddPoint(const IppsGFpECPoint* pP, const IppsGFpECPoint* pQ, IppsGFpECPoint* pR, IppsGFpECState* pEC);
extern IppStatus e9_ippsGFpECAddPoint(const IppsGFpECPoint* pP, const IppsGFpECPoint* pQ, IppsGFpECPoint* pR, IppsGFpECState* pEC);
extern IppStatus l9_ippsGFpECAddPoint(const IppsGFpECPoint* pP, const IppsGFpECPoint* pQ, IppsGFpECPoint* pR, IppsGFpECState* pEC);
extern IppStatus n0_ippsGFpECAddPoint(const IppsGFpECPoint* pP, const IppsGFpECPoint* pQ, IppsGFpECPoint* pR, IppsGFpECState* pEC);
extern IppStatus k0_ippsGFpECAddPoint(const IppsGFpECPoint* pP, const IppsGFpECPoint* pQ, IppsGFpECPoint* pR, IppsGFpECState* pEC);
extern IppStatus k1_ippsGFpECAddPoint(const IppsGFpECPoint* pP, const IppsGFpECPoint* pQ, IppsGFpECPoint* pR, IppsGFpECState* pEC);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpECAddPoint,
	(IPP_PROC)m7_ippsGFpECAddPoint,
	(IPP_PROC)n8_ippsGFpECAddPoint,
	(IPP_PROC)y8_ippsGFpECAddPoint,
	(IPP_PROC)e9_ippsGFpECAddPoint,
	(IPP_PROC)l9_ippsGFpECAddPoint,
	(IPP_PROC)n0_ippsGFpECAddPoint,
	(IPP_PROC)k0_ippsGFpECAddPoint,
	(IPP_PROC)k1_ippsGFpECAddPoint
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpECAddPoint,(const IppsGFpECPoint* pP, const IppsGFpECPoint* pQ, IppsGFpECPoint* pR, IppsGFpECState* pEC))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpECAddPoint,(const IppsGFpECPoint* pP, const IppsGFpECPoint* pQ, IppsGFpECPoint* pR, IppsGFpECState* pEC))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpECAddPoint]
        jmp  rax
  }
};
