#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsGFpECPoint* pPoint, IppsBigNumState* pX, IppsBigNumState* pY, IppsGFpECState* pEC);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpECGetPointRegular(const IppsGFpECPoint* pPoint, IppsBigNumState* pX, IppsBigNumState* pY, IppsGFpECState* pEC);
extern IppStatus m7_ippsGFpECGetPointRegular(const IppsGFpECPoint* pPoint, IppsBigNumState* pX, IppsBigNumState* pY, IppsGFpECState* pEC);
extern IppStatus n8_ippsGFpECGetPointRegular(const IppsGFpECPoint* pPoint, IppsBigNumState* pX, IppsBigNumState* pY, IppsGFpECState* pEC);
extern IppStatus y8_ippsGFpECGetPointRegular(const IppsGFpECPoint* pPoint, IppsBigNumState* pX, IppsBigNumState* pY, IppsGFpECState* pEC);
extern IppStatus e9_ippsGFpECGetPointRegular(const IppsGFpECPoint* pPoint, IppsBigNumState* pX, IppsBigNumState* pY, IppsGFpECState* pEC);
extern IppStatus l9_ippsGFpECGetPointRegular(const IppsGFpECPoint* pPoint, IppsBigNumState* pX, IppsBigNumState* pY, IppsGFpECState* pEC);
extern IppStatus n0_ippsGFpECGetPointRegular(const IppsGFpECPoint* pPoint, IppsBigNumState* pX, IppsBigNumState* pY, IppsGFpECState* pEC);
extern IppStatus k0_ippsGFpECGetPointRegular(const IppsGFpECPoint* pPoint, IppsBigNumState* pX, IppsBigNumState* pY, IppsGFpECState* pEC);
extern IppStatus k1_ippsGFpECGetPointRegular(const IppsGFpECPoint* pPoint, IppsBigNumState* pX, IppsBigNumState* pY, IppsGFpECState* pEC);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpECGetPointRegular,
	(IPP_PROC)m7_ippsGFpECGetPointRegular,
	(IPP_PROC)n8_ippsGFpECGetPointRegular,
	(IPP_PROC)y8_ippsGFpECGetPointRegular,
	(IPP_PROC)e9_ippsGFpECGetPointRegular,
	(IPP_PROC)l9_ippsGFpECGetPointRegular,
	(IPP_PROC)n0_ippsGFpECGetPointRegular,
	(IPP_PROC)k0_ippsGFpECGetPointRegular,
	(IPP_PROC)k1_ippsGFpECGetPointRegular
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpECGetPointRegular,(const IppsGFpECPoint* pPoint, IppsBigNumState* pX, IppsBigNumState* pY, IppsGFpECState* pEC))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpECGetPointRegular,(const IppsGFpECPoint* pPoint, IppsBigNumState* pX, IppsBigNumState* pY, IppsGFpECState* pEC))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpECGetPointRegular]
        jmp  rax
  }
};
