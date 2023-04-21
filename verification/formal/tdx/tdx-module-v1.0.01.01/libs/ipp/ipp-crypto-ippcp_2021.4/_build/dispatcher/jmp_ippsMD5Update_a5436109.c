#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pSrc, int len, IppsMD5State* pState);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsMD5Update(const Ipp8u* pSrc, int len, IppsMD5State* pState);
extern IppStatus m7_ippsMD5Update(const Ipp8u* pSrc, int len, IppsMD5State* pState);
extern IppStatus n8_ippsMD5Update(const Ipp8u* pSrc, int len, IppsMD5State* pState);
extern IppStatus y8_ippsMD5Update(const Ipp8u* pSrc, int len, IppsMD5State* pState);
extern IppStatus e9_ippsMD5Update(const Ipp8u* pSrc, int len, IppsMD5State* pState);
extern IppStatus l9_ippsMD5Update(const Ipp8u* pSrc, int len, IppsMD5State* pState);
extern IppStatus n0_ippsMD5Update(const Ipp8u* pSrc, int len, IppsMD5State* pState);
extern IppStatus k0_ippsMD5Update(const Ipp8u* pSrc, int len, IppsMD5State* pState);
extern IppStatus k1_ippsMD5Update(const Ipp8u* pSrc, int len, IppsMD5State* pState);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsMD5Update,
	(IPP_PROC)m7_ippsMD5Update,
	(IPP_PROC)n8_ippsMD5Update,
	(IPP_PROC)y8_ippsMD5Update,
	(IPP_PROC)e9_ippsMD5Update,
	(IPP_PROC)l9_ippsMD5Update,
	(IPP_PROC)n0_ippsMD5Update,
	(IPP_PROC)k0_ippsMD5Update,
	(IPP_PROC)k1_ippsMD5Update
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsMD5Update,(const Ipp8u* pSrc, int len, IppsMD5State* pState))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsMD5Update,(const Ipp8u* pSrc, int len, IppsMD5State* pState))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsMD5Update]
        jmp  rax
  }
};
