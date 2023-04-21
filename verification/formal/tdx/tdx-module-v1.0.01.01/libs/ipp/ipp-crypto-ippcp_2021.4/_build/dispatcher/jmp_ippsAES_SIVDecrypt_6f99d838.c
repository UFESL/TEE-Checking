#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pSrc, Ipp8u* pDst, int len, int* pAuthPassed, const Ipp8u* pAuthKey, const Ipp8u* pConfKey, int keyLen, const Ipp8u* pAD[], const int pADlen[], int numAD, const Ipp8u* pSIV);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsAES_SIVDecrypt(const Ipp8u* pSrc, Ipp8u* pDst, int len, int* pAuthPassed, const Ipp8u* pAuthKey, const Ipp8u* pConfKey, int keyLen, const Ipp8u* pAD[], const int pADlen[], int numAD, const Ipp8u* pSIV);
extern IppStatus m7_ippsAES_SIVDecrypt(const Ipp8u* pSrc, Ipp8u* pDst, int len, int* pAuthPassed, const Ipp8u* pAuthKey, const Ipp8u* pConfKey, int keyLen, const Ipp8u* pAD[], const int pADlen[], int numAD, const Ipp8u* pSIV);
extern IppStatus n8_ippsAES_SIVDecrypt(const Ipp8u* pSrc, Ipp8u* pDst, int len, int* pAuthPassed, const Ipp8u* pAuthKey, const Ipp8u* pConfKey, int keyLen, const Ipp8u* pAD[], const int pADlen[], int numAD, const Ipp8u* pSIV);
extern IppStatus y8_ippsAES_SIVDecrypt(const Ipp8u* pSrc, Ipp8u* pDst, int len, int* pAuthPassed, const Ipp8u* pAuthKey, const Ipp8u* pConfKey, int keyLen, const Ipp8u* pAD[], const int pADlen[], int numAD, const Ipp8u* pSIV);
extern IppStatus e9_ippsAES_SIVDecrypt(const Ipp8u* pSrc, Ipp8u* pDst, int len, int* pAuthPassed, const Ipp8u* pAuthKey, const Ipp8u* pConfKey, int keyLen, const Ipp8u* pAD[], const int pADlen[], int numAD, const Ipp8u* pSIV);
extern IppStatus l9_ippsAES_SIVDecrypt(const Ipp8u* pSrc, Ipp8u* pDst, int len, int* pAuthPassed, const Ipp8u* pAuthKey, const Ipp8u* pConfKey, int keyLen, const Ipp8u* pAD[], const int pADlen[], int numAD, const Ipp8u* pSIV);
extern IppStatus n0_ippsAES_SIVDecrypt(const Ipp8u* pSrc, Ipp8u* pDst, int len, int* pAuthPassed, const Ipp8u* pAuthKey, const Ipp8u* pConfKey, int keyLen, const Ipp8u* pAD[], const int pADlen[], int numAD, const Ipp8u* pSIV);
extern IppStatus k0_ippsAES_SIVDecrypt(const Ipp8u* pSrc, Ipp8u* pDst, int len, int* pAuthPassed, const Ipp8u* pAuthKey, const Ipp8u* pConfKey, int keyLen, const Ipp8u* pAD[], const int pADlen[], int numAD, const Ipp8u* pSIV);
extern IppStatus k1_ippsAES_SIVDecrypt(const Ipp8u* pSrc, Ipp8u* pDst, int len, int* pAuthPassed, const Ipp8u* pAuthKey, const Ipp8u* pConfKey, int keyLen, const Ipp8u* pAD[], const int pADlen[], int numAD, const Ipp8u* pSIV);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsAES_SIVDecrypt,
	(IPP_PROC)m7_ippsAES_SIVDecrypt,
	(IPP_PROC)n8_ippsAES_SIVDecrypt,
	(IPP_PROC)y8_ippsAES_SIVDecrypt,
	(IPP_PROC)e9_ippsAES_SIVDecrypt,
	(IPP_PROC)l9_ippsAES_SIVDecrypt,
	(IPP_PROC)n0_ippsAES_SIVDecrypt,
	(IPP_PROC)k0_ippsAES_SIVDecrypt,
	(IPP_PROC)k1_ippsAES_SIVDecrypt
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsAES_SIVDecrypt,(const Ipp8u* pSrc, Ipp8u* pDst, int len, int* pAuthPassed, const Ipp8u* pAuthKey, const Ipp8u* pConfKey, int keyLen, const Ipp8u* pAD[], const int pADlen[], int numAD, const Ipp8u* pSIV))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsAES_SIVDecrypt,(const Ipp8u* pSrc, Ipp8u* pDst, int len, int* pAuthPassed, const Ipp8u* pAuthKey, const Ipp8u* pConfKey, int keyLen, const Ipp8u* pAD[], const int pADlen[], int numAD, const Ipp8u* pSIV))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsAES_SIVDecrypt]
        jmp  rax
  }
};
