#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pFactorP, const IppsBigNumState* pFactorQ, const IppsBigNumState* pCrtExpP, const IppsBigNumState* pCrtExpQ, const IppsBigNumState* pInverseQ, IppsRSAPrivateKeyState* pKey);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsRSA_SetPrivateKeyType2(const IppsBigNumState* pFactorP, const IppsBigNumState* pFactorQ, const IppsBigNumState* pCrtExpP, const IppsBigNumState* pCrtExpQ, const IppsBigNumState* pInverseQ, IppsRSAPrivateKeyState* pKey);
extern IppStatus m7_ippsRSA_SetPrivateKeyType2(const IppsBigNumState* pFactorP, const IppsBigNumState* pFactorQ, const IppsBigNumState* pCrtExpP, const IppsBigNumState* pCrtExpQ, const IppsBigNumState* pInverseQ, IppsRSAPrivateKeyState* pKey);
extern IppStatus n8_ippsRSA_SetPrivateKeyType2(const IppsBigNumState* pFactorP, const IppsBigNumState* pFactorQ, const IppsBigNumState* pCrtExpP, const IppsBigNumState* pCrtExpQ, const IppsBigNumState* pInverseQ, IppsRSAPrivateKeyState* pKey);
extern IppStatus y8_ippsRSA_SetPrivateKeyType2(const IppsBigNumState* pFactorP, const IppsBigNumState* pFactorQ, const IppsBigNumState* pCrtExpP, const IppsBigNumState* pCrtExpQ, const IppsBigNumState* pInverseQ, IppsRSAPrivateKeyState* pKey);
extern IppStatus e9_ippsRSA_SetPrivateKeyType2(const IppsBigNumState* pFactorP, const IppsBigNumState* pFactorQ, const IppsBigNumState* pCrtExpP, const IppsBigNumState* pCrtExpQ, const IppsBigNumState* pInverseQ, IppsRSAPrivateKeyState* pKey);
extern IppStatus l9_ippsRSA_SetPrivateKeyType2(const IppsBigNumState* pFactorP, const IppsBigNumState* pFactorQ, const IppsBigNumState* pCrtExpP, const IppsBigNumState* pCrtExpQ, const IppsBigNumState* pInverseQ, IppsRSAPrivateKeyState* pKey);
extern IppStatus n0_ippsRSA_SetPrivateKeyType2(const IppsBigNumState* pFactorP, const IppsBigNumState* pFactorQ, const IppsBigNumState* pCrtExpP, const IppsBigNumState* pCrtExpQ, const IppsBigNumState* pInverseQ, IppsRSAPrivateKeyState* pKey);
extern IppStatus k0_ippsRSA_SetPrivateKeyType2(const IppsBigNumState* pFactorP, const IppsBigNumState* pFactorQ, const IppsBigNumState* pCrtExpP, const IppsBigNumState* pCrtExpQ, const IppsBigNumState* pInverseQ, IppsRSAPrivateKeyState* pKey);
extern IppStatus k1_ippsRSA_SetPrivateKeyType2(const IppsBigNumState* pFactorP, const IppsBigNumState* pFactorQ, const IppsBigNumState* pCrtExpP, const IppsBigNumState* pCrtExpQ, const IppsBigNumState* pInverseQ, IppsRSAPrivateKeyState* pKey);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsRSA_SetPrivateKeyType2,
	(IPP_PROC)m7_ippsRSA_SetPrivateKeyType2,
	(IPP_PROC)n8_ippsRSA_SetPrivateKeyType2,
	(IPP_PROC)y8_ippsRSA_SetPrivateKeyType2,
	(IPP_PROC)e9_ippsRSA_SetPrivateKeyType2,
	(IPP_PROC)l9_ippsRSA_SetPrivateKeyType2,
	(IPP_PROC)n0_ippsRSA_SetPrivateKeyType2,
	(IPP_PROC)k0_ippsRSA_SetPrivateKeyType2,
	(IPP_PROC)k1_ippsRSA_SetPrivateKeyType2
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsRSA_SetPrivateKeyType2,(const IppsBigNumState* pFactorP, const IppsBigNumState* pFactorQ, const IppsBigNumState* pCrtExpP, const IppsBigNumState* pCrtExpQ, const IppsBigNumState* pInverseQ, IppsRSAPrivateKeyState* pKey))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsRSA_SetPrivateKeyType2,(const IppsBigNumState* pFactorP, const IppsBigNumState* pFactorQ, const IppsBigNumState* pCrtExpP, const IppsBigNumState* pCrtExpQ, const IppsBigNumState* pInverseQ, IppsRSAPrivateKeyState* pKey))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsRSA_SetPrivateKeyType2]
        jmp  rax
  }
};
