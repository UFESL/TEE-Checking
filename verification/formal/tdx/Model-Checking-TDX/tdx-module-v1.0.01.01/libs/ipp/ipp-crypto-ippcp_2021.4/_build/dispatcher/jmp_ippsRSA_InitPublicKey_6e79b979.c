#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(int rsaModulusBitSize, int publicExpBitSize, IppsRSAPublicKeyState* pKey, int keyCtxSize);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsRSA_InitPublicKey(int rsaModulusBitSize, int publicExpBitSize, IppsRSAPublicKeyState* pKey, int keyCtxSize);
extern IppStatus m7_ippsRSA_InitPublicKey(int rsaModulusBitSize, int publicExpBitSize, IppsRSAPublicKeyState* pKey, int keyCtxSize);
extern IppStatus n8_ippsRSA_InitPublicKey(int rsaModulusBitSize, int publicExpBitSize, IppsRSAPublicKeyState* pKey, int keyCtxSize);
extern IppStatus y8_ippsRSA_InitPublicKey(int rsaModulusBitSize, int publicExpBitSize, IppsRSAPublicKeyState* pKey, int keyCtxSize);
extern IppStatus e9_ippsRSA_InitPublicKey(int rsaModulusBitSize, int publicExpBitSize, IppsRSAPublicKeyState* pKey, int keyCtxSize);
extern IppStatus l9_ippsRSA_InitPublicKey(int rsaModulusBitSize, int publicExpBitSize, IppsRSAPublicKeyState* pKey, int keyCtxSize);
extern IppStatus n0_ippsRSA_InitPublicKey(int rsaModulusBitSize, int publicExpBitSize, IppsRSAPublicKeyState* pKey, int keyCtxSize);
extern IppStatus k0_ippsRSA_InitPublicKey(int rsaModulusBitSize, int publicExpBitSize, IppsRSAPublicKeyState* pKey, int keyCtxSize);
extern IppStatus k1_ippsRSA_InitPublicKey(int rsaModulusBitSize, int publicExpBitSize, IppsRSAPublicKeyState* pKey, int keyCtxSize);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsRSA_InitPublicKey,
	(IPP_PROC)m7_ippsRSA_InitPublicKey,
	(IPP_PROC)n8_ippsRSA_InitPublicKey,
	(IPP_PROC)y8_ippsRSA_InitPublicKey,
	(IPP_PROC)e9_ippsRSA_InitPublicKey,
	(IPP_PROC)l9_ippsRSA_InitPublicKey,
	(IPP_PROC)n0_ippsRSA_InitPublicKey,
	(IPP_PROC)k0_ippsRSA_InitPublicKey,
	(IPP_PROC)k1_ippsRSA_InitPublicKey
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsRSA_InitPublicKey,(int rsaModulusBitSize, int publicExpBitSize, IppsRSAPublicKeyState* pKey, int keyCtxSize))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsRSA_InitPublicKey,(int rsaModulusBitSize, int publicExpBitSize, IppsRSAPublicKeyState* pKey, int keyCtxSize))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsRSA_InitPublicKey]
        jmp  rax
  }
};
