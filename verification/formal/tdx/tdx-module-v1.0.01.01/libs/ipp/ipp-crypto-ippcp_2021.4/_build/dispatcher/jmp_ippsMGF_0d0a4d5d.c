#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pSeed, int seedLen, Ipp8u* pMask, int maskLen, IppHashAlgId hashAlg);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsMGF(const Ipp8u* pSeed, int seedLen, Ipp8u* pMask, int maskLen, IppHashAlgId hashAlg);
extern IppStatus m7_ippsMGF(const Ipp8u* pSeed, int seedLen, Ipp8u* pMask, int maskLen, IppHashAlgId hashAlg);
extern IppStatus n8_ippsMGF(const Ipp8u* pSeed, int seedLen, Ipp8u* pMask, int maskLen, IppHashAlgId hashAlg);
extern IppStatus y8_ippsMGF(const Ipp8u* pSeed, int seedLen, Ipp8u* pMask, int maskLen, IppHashAlgId hashAlg);
extern IppStatus e9_ippsMGF(const Ipp8u* pSeed, int seedLen, Ipp8u* pMask, int maskLen, IppHashAlgId hashAlg);
extern IppStatus l9_ippsMGF(const Ipp8u* pSeed, int seedLen, Ipp8u* pMask, int maskLen, IppHashAlgId hashAlg);
extern IppStatus n0_ippsMGF(const Ipp8u* pSeed, int seedLen, Ipp8u* pMask, int maskLen, IppHashAlgId hashAlg);
extern IppStatus k0_ippsMGF(const Ipp8u* pSeed, int seedLen, Ipp8u* pMask, int maskLen, IppHashAlgId hashAlg);
extern IppStatus k1_ippsMGF(const Ipp8u* pSeed, int seedLen, Ipp8u* pMask, int maskLen, IppHashAlgId hashAlg);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsMGF,
	(IPP_PROC)m7_ippsMGF,
	(IPP_PROC)n8_ippsMGF,
	(IPP_PROC)y8_ippsMGF,
	(IPP_PROC)e9_ippsMGF,
	(IPP_PROC)l9_ippsMGF,
	(IPP_PROC)n0_ippsMGF,
	(IPP_PROC)k0_ippsMGF,
	(IPP_PROC)k1_ippsMGF
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsMGF,(const Ipp8u* pSeed, int seedLen, Ipp8u* pMask, int maskLen, IppHashAlgId hashAlg))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsMGF,(const Ipp8u* pSeed, int seedLen, Ipp8u* pMask, int maskLen, IppHashAlgId hashAlg))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsMGF]
        jmp  rax
  }
};
