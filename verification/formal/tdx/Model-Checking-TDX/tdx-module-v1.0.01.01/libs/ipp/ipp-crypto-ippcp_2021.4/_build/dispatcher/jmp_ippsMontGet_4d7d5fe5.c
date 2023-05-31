#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(Ipp32u* pModulo, int* pSize, const IppsMontState* pCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsMontGet(Ipp32u* pModulo, int* pSize, const IppsMontState* pCtx);
extern IppStatus m7_ippsMontGet(Ipp32u* pModulo, int* pSize, const IppsMontState* pCtx);
extern IppStatus n8_ippsMontGet(Ipp32u* pModulo, int* pSize, const IppsMontState* pCtx);
extern IppStatus y8_ippsMontGet(Ipp32u* pModulo, int* pSize, const IppsMontState* pCtx);
extern IppStatus e9_ippsMontGet(Ipp32u* pModulo, int* pSize, const IppsMontState* pCtx);
extern IppStatus l9_ippsMontGet(Ipp32u* pModulo, int* pSize, const IppsMontState* pCtx);
extern IppStatus n0_ippsMontGet(Ipp32u* pModulo, int* pSize, const IppsMontState* pCtx);
extern IppStatus k0_ippsMontGet(Ipp32u* pModulo, int* pSize, const IppsMontState* pCtx);
extern IppStatus k1_ippsMontGet(Ipp32u* pModulo, int* pSize, const IppsMontState* pCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsMontGet,
	(IPP_PROC)m7_ippsMontGet,
	(IPP_PROC)n8_ippsMontGet,
	(IPP_PROC)y8_ippsMontGet,
	(IPP_PROC)e9_ippsMontGet,
	(IPP_PROC)l9_ippsMontGet,
	(IPP_PROC)n0_ippsMontGet,
	(IPP_PROC)k0_ippsMontGet,
	(IPP_PROC)k1_ippsMontGet
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsMontGet,(Ipp32u* pModulo, int* pSize, const IppsMontState* pCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsMontGet,(Ipp32u* pModulo, int* pSize, const IppsMontState* pCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsMontGet]
        jmp  rax
  }
};
