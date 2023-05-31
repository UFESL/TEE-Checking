#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pSrc, Ipp8u* pDst, int encBitsize, int aesBlkNo, const Ipp8u* pTweakPT, const Ipp8u* pKey, int keyBitsize, int dataUnitBitsize);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsAESEncryptXTS_Direct(const Ipp8u* pSrc, Ipp8u* pDst, int encBitsize, int aesBlkNo, const Ipp8u* pTweakPT, const Ipp8u* pKey, int keyBitsize, int dataUnitBitsize);
extern IppStatus m7_ippsAESEncryptXTS_Direct(const Ipp8u* pSrc, Ipp8u* pDst, int encBitsize, int aesBlkNo, const Ipp8u* pTweakPT, const Ipp8u* pKey, int keyBitsize, int dataUnitBitsize);
extern IppStatus n8_ippsAESEncryptXTS_Direct(const Ipp8u* pSrc, Ipp8u* pDst, int encBitsize, int aesBlkNo, const Ipp8u* pTweakPT, const Ipp8u* pKey, int keyBitsize, int dataUnitBitsize);
extern IppStatus y8_ippsAESEncryptXTS_Direct(const Ipp8u* pSrc, Ipp8u* pDst, int encBitsize, int aesBlkNo, const Ipp8u* pTweakPT, const Ipp8u* pKey, int keyBitsize, int dataUnitBitsize);
extern IppStatus e9_ippsAESEncryptXTS_Direct(const Ipp8u* pSrc, Ipp8u* pDst, int encBitsize, int aesBlkNo, const Ipp8u* pTweakPT, const Ipp8u* pKey, int keyBitsize, int dataUnitBitsize);
extern IppStatus l9_ippsAESEncryptXTS_Direct(const Ipp8u* pSrc, Ipp8u* pDst, int encBitsize, int aesBlkNo, const Ipp8u* pTweakPT, const Ipp8u* pKey, int keyBitsize, int dataUnitBitsize);
extern IppStatus n0_ippsAESEncryptXTS_Direct(const Ipp8u* pSrc, Ipp8u* pDst, int encBitsize, int aesBlkNo, const Ipp8u* pTweakPT, const Ipp8u* pKey, int keyBitsize, int dataUnitBitsize);
extern IppStatus k0_ippsAESEncryptXTS_Direct(const Ipp8u* pSrc, Ipp8u* pDst, int encBitsize, int aesBlkNo, const Ipp8u* pTweakPT, const Ipp8u* pKey, int keyBitsize, int dataUnitBitsize);
extern IppStatus k1_ippsAESEncryptXTS_Direct(const Ipp8u* pSrc, Ipp8u* pDst, int encBitsize, int aesBlkNo, const Ipp8u* pTweakPT, const Ipp8u* pKey, int keyBitsize, int dataUnitBitsize);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsAESEncryptXTS_Direct,
	(IPP_PROC)m7_ippsAESEncryptXTS_Direct,
	(IPP_PROC)n8_ippsAESEncryptXTS_Direct,
	(IPP_PROC)y8_ippsAESEncryptXTS_Direct,
	(IPP_PROC)e9_ippsAESEncryptXTS_Direct,
	(IPP_PROC)l9_ippsAESEncryptXTS_Direct,
	(IPP_PROC)n0_ippsAESEncryptXTS_Direct,
	(IPP_PROC)k0_ippsAESEncryptXTS_Direct,
	(IPP_PROC)k1_ippsAESEncryptXTS_Direct
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsAESEncryptXTS_Direct,(const Ipp8u* pSrc, Ipp8u* pDst, int encBitsize, int aesBlkNo, const Ipp8u* pTweakPT, const Ipp8u* pKey, int keyBitsize, int dataUnitBitsize))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsAESEncryptXTS_Direct,(const Ipp8u* pSrc, Ipp8u* pDst, int encBitsize, int aesBlkNo, const Ipp8u* pTweakPT, const Ipp8u* pKey, int keyBitsize, int dataUnitBitsize))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsAESEncryptXTS_Direct]
        jmp  rax
  }
};
