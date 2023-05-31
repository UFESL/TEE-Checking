#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsGFpElement* pX, const IppsGFpElement* pY, IppsGFpECPoint* pPoint, IppsGFpECState* pEC);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpECPointInit(const IppsGFpElement* pX, const IppsGFpElement* pY, IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
extern IppStatus m7_ippsGFpECPointInit(const IppsGFpElement* pX, const IppsGFpElement* pY, IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
extern IppStatus n8_ippsGFpECPointInit(const IppsGFpElement* pX, const IppsGFpElement* pY, IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
extern IppStatus y8_ippsGFpECPointInit(const IppsGFpElement* pX, const IppsGFpElement* pY, IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
extern IppStatus e9_ippsGFpECPointInit(const IppsGFpElement* pX, const IppsGFpElement* pY, IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
extern IppStatus l9_ippsGFpECPointInit(const IppsGFpElement* pX, const IppsGFpElement* pY, IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
extern IppStatus n0_ippsGFpECPointInit(const IppsGFpElement* pX, const IppsGFpElement* pY, IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
extern IppStatus k0_ippsGFpECPointInit(const IppsGFpElement* pX, const IppsGFpElement* pY, IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
extern IppStatus k1_ippsGFpECPointInit(const IppsGFpElement* pX, const IppsGFpElement* pY, IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpECPointInit,
	(IPP_PROC)m7_ippsGFpECPointInit,
	(IPP_PROC)n8_ippsGFpECPointInit,
	(IPP_PROC)y8_ippsGFpECPointInit,
	(IPP_PROC)e9_ippsGFpECPointInit,
	(IPP_PROC)l9_ippsGFpECPointInit,
	(IPP_PROC)n0_ippsGFpECPointInit,
	(IPP_PROC)k0_ippsGFpECPointInit,
	(IPP_PROC)k1_ippsGFpECPointInit
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpECPointInit,(const IppsGFpElement* pX, const IppsGFpElement* pY, IppsGFpECPoint* pPoint, IppsGFpECState* pEC))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpECPointInit,(const IppsGFpElement* pX, const IppsGFpElement* pY, IppsGFpECPoint* pPoint, IppsGFpECState* pEC))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpECPointInit]
        jmp  rax
  }
};
