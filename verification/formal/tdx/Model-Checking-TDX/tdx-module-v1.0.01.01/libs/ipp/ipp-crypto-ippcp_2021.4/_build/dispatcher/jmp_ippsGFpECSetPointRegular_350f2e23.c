#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pX, const IppsBigNumState* pY, IppsGFpECPoint* pPoint, IppsGFpECState* pEC);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpECSetPointRegular(const IppsBigNumState* pX, const IppsBigNumState* pY, IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
extern IppStatus m7_ippsGFpECSetPointRegular(const IppsBigNumState* pX, const IppsBigNumState* pY, IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
extern IppStatus n8_ippsGFpECSetPointRegular(const IppsBigNumState* pX, const IppsBigNumState* pY, IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
extern IppStatus y8_ippsGFpECSetPointRegular(const IppsBigNumState* pX, const IppsBigNumState* pY, IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
extern IppStatus e9_ippsGFpECSetPointRegular(const IppsBigNumState* pX, const IppsBigNumState* pY, IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
extern IppStatus l9_ippsGFpECSetPointRegular(const IppsBigNumState* pX, const IppsBigNumState* pY, IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
extern IppStatus n0_ippsGFpECSetPointRegular(const IppsBigNumState* pX, const IppsBigNumState* pY, IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
extern IppStatus k0_ippsGFpECSetPointRegular(const IppsBigNumState* pX, const IppsBigNumState* pY, IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
extern IppStatus k1_ippsGFpECSetPointRegular(const IppsBigNumState* pX, const IppsBigNumState* pY, IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpECSetPointRegular,
	(IPP_PROC)m7_ippsGFpECSetPointRegular,
	(IPP_PROC)n8_ippsGFpECSetPointRegular,
	(IPP_PROC)y8_ippsGFpECSetPointRegular,
	(IPP_PROC)e9_ippsGFpECSetPointRegular,
	(IPP_PROC)l9_ippsGFpECSetPointRegular,
	(IPP_PROC)n0_ippsGFpECSetPointRegular,
	(IPP_PROC)k0_ippsGFpECSetPointRegular,
	(IPP_PROC)k1_ippsGFpECSetPointRegular
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpECSetPointRegular,(const IppsBigNumState* pX, const IppsBigNumState* pY, IppsGFpECPoint* pPoint, IppsGFpECState* pEC))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpECSetPointRegular,(const IppsBigNumState* pX, const IppsBigNumState* pY, IppsGFpECPoint* pPoint, IppsGFpECState* pEC))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpECSetPointRegular]
        jmp  rax
  }
};
