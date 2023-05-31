#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsGFpElement* pX, IppsGFpECPoint* pPoint, IppsGFpECState* pEC);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpECMakePoint(const IppsGFpElement* pX, IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
extern IppStatus m7_ippsGFpECMakePoint(const IppsGFpElement* pX, IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
extern IppStatus n8_ippsGFpECMakePoint(const IppsGFpElement* pX, IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
extern IppStatus y8_ippsGFpECMakePoint(const IppsGFpElement* pX, IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
extern IppStatus e9_ippsGFpECMakePoint(const IppsGFpElement* pX, IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
extern IppStatus l9_ippsGFpECMakePoint(const IppsGFpElement* pX, IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
extern IppStatus n0_ippsGFpECMakePoint(const IppsGFpElement* pX, IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
extern IppStatus k0_ippsGFpECMakePoint(const IppsGFpElement* pX, IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
extern IppStatus k1_ippsGFpECMakePoint(const IppsGFpElement* pX, IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpECMakePoint,
	(IPP_PROC)m7_ippsGFpECMakePoint,
	(IPP_PROC)n8_ippsGFpECMakePoint,
	(IPP_PROC)y8_ippsGFpECMakePoint,
	(IPP_PROC)e9_ippsGFpECMakePoint,
	(IPP_PROC)l9_ippsGFpECMakePoint,
	(IPP_PROC)n0_ippsGFpECMakePoint,
	(IPP_PROC)k0_ippsGFpECMakePoint,
	(IPP_PROC)k1_ippsGFpECMakePoint
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpECMakePoint,(const IppsGFpElement* pX, IppsGFpECPoint* pPoint, IppsGFpECState* pEC))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpECMakePoint,(const IppsGFpElement* pX, IppsGFpECPoint* pPoint, IppsGFpECState* pEC))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpECMakePoint]
        jmp  rax
  }
};
