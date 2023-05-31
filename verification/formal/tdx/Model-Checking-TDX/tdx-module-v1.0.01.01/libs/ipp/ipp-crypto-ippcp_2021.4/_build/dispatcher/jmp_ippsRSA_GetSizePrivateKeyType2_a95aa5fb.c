#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(int factorPbitSize, int factorQbitSize, int* pKeySize);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsRSA_GetSizePrivateKeyType2(int factorPbitSize, int factorQbitSize, int* pKeySize);
extern IppStatus m7_ippsRSA_GetSizePrivateKeyType2(int factorPbitSize, int factorQbitSize, int* pKeySize);
extern IppStatus n8_ippsRSA_GetSizePrivateKeyType2(int factorPbitSize, int factorQbitSize, int* pKeySize);
extern IppStatus y8_ippsRSA_GetSizePrivateKeyType2(int factorPbitSize, int factorQbitSize, int* pKeySize);
extern IppStatus e9_ippsRSA_GetSizePrivateKeyType2(int factorPbitSize, int factorQbitSize, int* pKeySize);
extern IppStatus l9_ippsRSA_GetSizePrivateKeyType2(int factorPbitSize, int factorQbitSize, int* pKeySize);
extern IppStatus n0_ippsRSA_GetSizePrivateKeyType2(int factorPbitSize, int factorQbitSize, int* pKeySize);
extern IppStatus k0_ippsRSA_GetSizePrivateKeyType2(int factorPbitSize, int factorQbitSize, int* pKeySize);
extern IppStatus k1_ippsRSA_GetSizePrivateKeyType2(int factorPbitSize, int factorQbitSize, int* pKeySize);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsRSA_GetSizePrivateKeyType2,
	(IPP_PROC)m7_ippsRSA_GetSizePrivateKeyType2,
	(IPP_PROC)n8_ippsRSA_GetSizePrivateKeyType2,
	(IPP_PROC)y8_ippsRSA_GetSizePrivateKeyType2,
	(IPP_PROC)e9_ippsRSA_GetSizePrivateKeyType2,
	(IPP_PROC)l9_ippsRSA_GetSizePrivateKeyType2,
	(IPP_PROC)n0_ippsRSA_GetSizePrivateKeyType2,
	(IPP_PROC)k0_ippsRSA_GetSizePrivateKeyType2,
	(IPP_PROC)k1_ippsRSA_GetSizePrivateKeyType2
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsRSA_GetSizePrivateKeyType2,(int factorPbitSize, int factorQbitSize, int* pKeySize))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsRSA_GetSizePrivateKeyType2,(int factorPbitSize, int factorQbitSize, int* pKeySize))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsRSA_GetSizePrivateKeyType2]
        jmp  rax
  }
};
