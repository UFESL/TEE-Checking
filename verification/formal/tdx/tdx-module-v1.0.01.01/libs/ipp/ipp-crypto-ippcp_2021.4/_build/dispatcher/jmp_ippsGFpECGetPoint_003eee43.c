#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsGFpECPoint* pPoint, IppsGFpElement* pX, IppsGFpElement* pY, IppsGFpECState* pEC);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpECGetPoint(const IppsGFpECPoint* pPoint, IppsGFpElement* pX, IppsGFpElement* pY, IppsGFpECState* pEC);
extern IppStatus m7_ippsGFpECGetPoint(const IppsGFpECPoint* pPoint, IppsGFpElement* pX, IppsGFpElement* pY, IppsGFpECState* pEC);
extern IppStatus n8_ippsGFpECGetPoint(const IppsGFpECPoint* pPoint, IppsGFpElement* pX, IppsGFpElement* pY, IppsGFpECState* pEC);
extern IppStatus y8_ippsGFpECGetPoint(const IppsGFpECPoint* pPoint, IppsGFpElement* pX, IppsGFpElement* pY, IppsGFpECState* pEC);
extern IppStatus e9_ippsGFpECGetPoint(const IppsGFpECPoint* pPoint, IppsGFpElement* pX, IppsGFpElement* pY, IppsGFpECState* pEC);
extern IppStatus l9_ippsGFpECGetPoint(const IppsGFpECPoint* pPoint, IppsGFpElement* pX, IppsGFpElement* pY, IppsGFpECState* pEC);
extern IppStatus n0_ippsGFpECGetPoint(const IppsGFpECPoint* pPoint, IppsGFpElement* pX, IppsGFpElement* pY, IppsGFpECState* pEC);
extern IppStatus k0_ippsGFpECGetPoint(const IppsGFpECPoint* pPoint, IppsGFpElement* pX, IppsGFpElement* pY, IppsGFpECState* pEC);
extern IppStatus k1_ippsGFpECGetPoint(const IppsGFpECPoint* pPoint, IppsGFpElement* pX, IppsGFpElement* pY, IppsGFpECState* pEC);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpECGetPoint,
	(IPP_PROC)m7_ippsGFpECGetPoint,
	(IPP_PROC)n8_ippsGFpECGetPoint,
	(IPP_PROC)y8_ippsGFpECGetPoint,
	(IPP_PROC)e9_ippsGFpECGetPoint,
	(IPP_PROC)l9_ippsGFpECGetPoint,
	(IPP_PROC)n0_ippsGFpECGetPoint,
	(IPP_PROC)k0_ippsGFpECGetPoint,
	(IPP_PROC)k1_ippsGFpECGetPoint
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpECGetPoint,(const IppsGFpECPoint* pPoint, IppsGFpElement* pX, IppsGFpElement* pY, IppsGFpECState* pEC))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpECGetPoint,(const IppsGFpECPoint* pPoint, IppsGFpElement* pX, IppsGFpElement* pY, IppsGFpECState* pEC))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpECGetPoint]
        jmp  rax
  }
};
