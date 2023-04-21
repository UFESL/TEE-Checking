#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pPrime, int primeBitSize, const IppsGFpMethod* pGFpMethod, IppsGFpState* pGFp);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpInit(const IppsBigNumState* pPrime, int primeBitSize, const IppsGFpMethod* pGFpMethod, IppsGFpState* pGFp);
extern IppStatus m7_ippsGFpInit(const IppsBigNumState* pPrime, int primeBitSize, const IppsGFpMethod* pGFpMethod, IppsGFpState* pGFp);
extern IppStatus n8_ippsGFpInit(const IppsBigNumState* pPrime, int primeBitSize, const IppsGFpMethod* pGFpMethod, IppsGFpState* pGFp);
extern IppStatus y8_ippsGFpInit(const IppsBigNumState* pPrime, int primeBitSize, const IppsGFpMethod* pGFpMethod, IppsGFpState* pGFp);
extern IppStatus e9_ippsGFpInit(const IppsBigNumState* pPrime, int primeBitSize, const IppsGFpMethod* pGFpMethod, IppsGFpState* pGFp);
extern IppStatus l9_ippsGFpInit(const IppsBigNumState* pPrime, int primeBitSize, const IppsGFpMethod* pGFpMethod, IppsGFpState* pGFp);
extern IppStatus n0_ippsGFpInit(const IppsBigNumState* pPrime, int primeBitSize, const IppsGFpMethod* pGFpMethod, IppsGFpState* pGFp);
extern IppStatus k0_ippsGFpInit(const IppsBigNumState* pPrime, int primeBitSize, const IppsGFpMethod* pGFpMethod, IppsGFpState* pGFp);
extern IppStatus k1_ippsGFpInit(const IppsBigNumState* pPrime, int primeBitSize, const IppsGFpMethod* pGFpMethod, IppsGFpState* pGFp);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpInit,
	(IPP_PROC)m7_ippsGFpInit,
	(IPP_PROC)n8_ippsGFpInit,
	(IPP_PROC)y8_ippsGFpInit,
	(IPP_PROC)e9_ippsGFpInit,
	(IPP_PROC)l9_ippsGFpInit,
	(IPP_PROC)n0_ippsGFpInit,
	(IPP_PROC)k0_ippsGFpInit,
	(IPP_PROC)k1_ippsGFpInit
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpInit,(const IppsBigNumState* pPrime, int primeBitSize, const IppsGFpMethod* pGFpMethod, IppsGFpState* pGFp))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpInit,(const IppsBigNumState* pPrime, int primeBitSize, const IppsGFpMethod* pGFpMethod, IppsGFpState* pGFp))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpInit]
        jmp  rax
  }
};
