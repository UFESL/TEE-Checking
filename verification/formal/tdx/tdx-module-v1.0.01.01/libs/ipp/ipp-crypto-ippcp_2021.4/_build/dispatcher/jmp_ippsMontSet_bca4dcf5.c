#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp32u* pModulo, int size, IppsMontState* pCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsMontSet(const Ipp32u* pModulo, int size, IppsMontState* pCtx);
extern IppStatus m7_ippsMontSet(const Ipp32u* pModulo, int size, IppsMontState* pCtx);
extern IppStatus n8_ippsMontSet(const Ipp32u* pModulo, int size, IppsMontState* pCtx);
extern IppStatus y8_ippsMontSet(const Ipp32u* pModulo, int size, IppsMontState* pCtx);
extern IppStatus e9_ippsMontSet(const Ipp32u* pModulo, int size, IppsMontState* pCtx);
extern IppStatus l9_ippsMontSet(const Ipp32u* pModulo, int size, IppsMontState* pCtx);
extern IppStatus n0_ippsMontSet(const Ipp32u* pModulo, int size, IppsMontState* pCtx);
extern IppStatus k0_ippsMontSet(const Ipp32u* pModulo, int size, IppsMontState* pCtx);
extern IppStatus k1_ippsMontSet(const Ipp32u* pModulo, int size, IppsMontState* pCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsMontSet,
	(IPP_PROC)m7_ippsMontSet,
	(IPP_PROC)n8_ippsMontSet,
	(IPP_PROC)y8_ippsMontSet,
	(IPP_PROC)e9_ippsMontSet,
	(IPP_PROC)l9_ippsMontSet,
	(IPP_PROC)n0_ippsMontSet,
	(IPP_PROC)k0_ippsMontSet,
	(IPP_PROC)k1_ippsMontSet
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsMontSet,(const Ipp32u* pModulo, int size, IppsMontState* pCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsMontSet,(const Ipp32u* pModulo, int size, IppsMontState* pCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsMontSet]
        jmp  rax
  }
};
