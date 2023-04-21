#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pKey, int keyLen, IppsSMS4Spec* pCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsSMS4SetKey(const Ipp8u* pKey, int keyLen, IppsSMS4Spec* pCtx);
extern IppStatus m7_ippsSMS4SetKey(const Ipp8u* pKey, int keyLen, IppsSMS4Spec* pCtx);
extern IppStatus n8_ippsSMS4SetKey(const Ipp8u* pKey, int keyLen, IppsSMS4Spec* pCtx);
extern IppStatus y8_ippsSMS4SetKey(const Ipp8u* pKey, int keyLen, IppsSMS4Spec* pCtx);
extern IppStatus e9_ippsSMS4SetKey(const Ipp8u* pKey, int keyLen, IppsSMS4Spec* pCtx);
extern IppStatus l9_ippsSMS4SetKey(const Ipp8u* pKey, int keyLen, IppsSMS4Spec* pCtx);
extern IppStatus n0_ippsSMS4SetKey(const Ipp8u* pKey, int keyLen, IppsSMS4Spec* pCtx);
extern IppStatus k0_ippsSMS4SetKey(const Ipp8u* pKey, int keyLen, IppsSMS4Spec* pCtx);
extern IppStatus k1_ippsSMS4SetKey(const Ipp8u* pKey, int keyLen, IppsSMS4Spec* pCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsSMS4SetKey,
	(IPP_PROC)m7_ippsSMS4SetKey,
	(IPP_PROC)n8_ippsSMS4SetKey,
	(IPP_PROC)y8_ippsSMS4SetKey,
	(IPP_PROC)e9_ippsSMS4SetKey,
	(IPP_PROC)l9_ippsSMS4SetKey,
	(IPP_PROC)n0_ippsSMS4SetKey,
	(IPP_PROC)k0_ippsSMS4SetKey,
	(IPP_PROC)k1_ippsSMS4SetKey
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsSMS4SetKey,(const Ipp8u* pKey, int keyLen, IppsSMS4Spec* pCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsSMS4SetKey,(const Ipp8u* pKey, int keyLen, IppsSMS4Spec* pCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsSMS4SetKey]
        jmp  rax
  }
};
