#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pBN, int* pSize);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGetSize_BN(const IppsBigNumState* pBN, int* pSize);
extern IppStatus m7_ippsGetSize_BN(const IppsBigNumState* pBN, int* pSize);
extern IppStatus n8_ippsGetSize_BN(const IppsBigNumState* pBN, int* pSize);
extern IppStatus y8_ippsGetSize_BN(const IppsBigNumState* pBN, int* pSize);
extern IppStatus e9_ippsGetSize_BN(const IppsBigNumState* pBN, int* pSize);
extern IppStatus l9_ippsGetSize_BN(const IppsBigNumState* pBN, int* pSize);
extern IppStatus n0_ippsGetSize_BN(const IppsBigNumState* pBN, int* pSize);
extern IppStatus k0_ippsGetSize_BN(const IppsBigNumState* pBN, int* pSize);
extern IppStatus k1_ippsGetSize_BN(const IppsBigNumState* pBN, int* pSize);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGetSize_BN,
	(IPP_PROC)m7_ippsGetSize_BN,
	(IPP_PROC)n8_ippsGetSize_BN,
	(IPP_PROC)y8_ippsGetSize_BN,
	(IPP_PROC)e9_ippsGetSize_BN,
	(IPP_PROC)l9_ippsGetSize_BN,
	(IPP_PROC)n0_ippsGetSize_BN,
	(IPP_PROC)k0_ippsGetSize_BN,
	(IPP_PROC)k1_ippsGetSize_BN
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGetSize_BN,(const IppsBigNumState* pBN, int* pSize))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGetSize_BN,(const IppsBigNumState* pBN, int* pSize))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGetSize_BN]
        jmp  rax
  }
};
