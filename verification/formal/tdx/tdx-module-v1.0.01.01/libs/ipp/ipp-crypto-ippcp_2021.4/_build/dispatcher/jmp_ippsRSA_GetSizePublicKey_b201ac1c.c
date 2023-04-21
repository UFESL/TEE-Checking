#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(int rsaModulusBitSize, int pubicExpBitSize, int* pKeySize);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsRSA_GetSizePublicKey(int rsaModulusBitSize, int pubicExpBitSize, int* pKeySize);
extern IppStatus m7_ippsRSA_GetSizePublicKey(int rsaModulusBitSize, int pubicExpBitSize, int* pKeySize);
extern IppStatus n8_ippsRSA_GetSizePublicKey(int rsaModulusBitSize, int pubicExpBitSize, int* pKeySize);
extern IppStatus y8_ippsRSA_GetSizePublicKey(int rsaModulusBitSize, int pubicExpBitSize, int* pKeySize);
extern IppStatus e9_ippsRSA_GetSizePublicKey(int rsaModulusBitSize, int pubicExpBitSize, int* pKeySize);
extern IppStatus l9_ippsRSA_GetSizePublicKey(int rsaModulusBitSize, int pubicExpBitSize, int* pKeySize);
extern IppStatus n0_ippsRSA_GetSizePublicKey(int rsaModulusBitSize, int pubicExpBitSize, int* pKeySize);
extern IppStatus k0_ippsRSA_GetSizePublicKey(int rsaModulusBitSize, int pubicExpBitSize, int* pKeySize);
extern IppStatus k1_ippsRSA_GetSizePublicKey(int rsaModulusBitSize, int pubicExpBitSize, int* pKeySize);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsRSA_GetSizePublicKey,
	(IPP_PROC)m7_ippsRSA_GetSizePublicKey,
	(IPP_PROC)n8_ippsRSA_GetSizePublicKey,
	(IPP_PROC)y8_ippsRSA_GetSizePublicKey,
	(IPP_PROC)e9_ippsRSA_GetSizePublicKey,
	(IPP_PROC)l9_ippsRSA_GetSizePublicKey,
	(IPP_PROC)n0_ippsRSA_GetSizePublicKey,
	(IPP_PROC)k0_ippsRSA_GetSizePublicKey,
	(IPP_PROC)k1_ippsRSA_GetSizePublicKey
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsRSA_GetSizePublicKey,(int rsaModulusBitSize, int pubicExpBitSize, int* pKeySize))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsRSA_GetSizePublicKey,(int rsaModulusBitSize, int pubicExpBitSize, int* pKeySize))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsRSA_GetSizePublicKey]
        jmp  rax
  }
};
