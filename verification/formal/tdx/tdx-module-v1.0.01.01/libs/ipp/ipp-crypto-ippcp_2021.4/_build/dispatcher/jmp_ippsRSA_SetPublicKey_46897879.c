#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pModulus, const IppsBigNumState* pPublicExp, IppsRSAPublicKeyState* pKey);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsRSA_SetPublicKey(const IppsBigNumState* pModulus, const IppsBigNumState* pPublicExp, IppsRSAPublicKeyState* pKey);
extern IppStatus m7_ippsRSA_SetPublicKey(const IppsBigNumState* pModulus, const IppsBigNumState* pPublicExp, IppsRSAPublicKeyState* pKey);
extern IppStatus n8_ippsRSA_SetPublicKey(const IppsBigNumState* pModulus, const IppsBigNumState* pPublicExp, IppsRSAPublicKeyState* pKey);
extern IppStatus y8_ippsRSA_SetPublicKey(const IppsBigNumState* pModulus, const IppsBigNumState* pPublicExp, IppsRSAPublicKeyState* pKey);
extern IppStatus e9_ippsRSA_SetPublicKey(const IppsBigNumState* pModulus, const IppsBigNumState* pPublicExp, IppsRSAPublicKeyState* pKey);
extern IppStatus l9_ippsRSA_SetPublicKey(const IppsBigNumState* pModulus, const IppsBigNumState* pPublicExp, IppsRSAPublicKeyState* pKey);
extern IppStatus n0_ippsRSA_SetPublicKey(const IppsBigNumState* pModulus, const IppsBigNumState* pPublicExp, IppsRSAPublicKeyState* pKey);
extern IppStatus k0_ippsRSA_SetPublicKey(const IppsBigNumState* pModulus, const IppsBigNumState* pPublicExp, IppsRSAPublicKeyState* pKey);
extern IppStatus k1_ippsRSA_SetPublicKey(const IppsBigNumState* pModulus, const IppsBigNumState* pPublicExp, IppsRSAPublicKeyState* pKey);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsRSA_SetPublicKey,
	(IPP_PROC)m7_ippsRSA_SetPublicKey,
	(IPP_PROC)n8_ippsRSA_SetPublicKey,
	(IPP_PROC)y8_ippsRSA_SetPublicKey,
	(IPP_PROC)e9_ippsRSA_SetPublicKey,
	(IPP_PROC)l9_ippsRSA_SetPublicKey,
	(IPP_PROC)n0_ippsRSA_SetPublicKey,
	(IPP_PROC)k0_ippsRSA_SetPublicKey,
	(IPP_PROC)k1_ippsRSA_SetPublicKey
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsRSA_SetPublicKey,(const IppsBigNumState* pModulus, const IppsBigNumState* pPublicExp, IppsRSAPublicKeyState* pKey))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsRSA_SetPublicKey,(const IppsBigNumState* pModulus, const IppsBigNumState* pPublicExp, IppsRSAPublicKeyState* pKey))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsRSA_SetPublicKey]
        jmp  rax
  }
};
