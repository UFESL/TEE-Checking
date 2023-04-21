#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsDLPState* pCtx, Ipp8u* pBuffer);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsDLPPack(const IppsDLPState* pCtx, Ipp8u* pBuffer);
extern IppStatus m7_ippsDLPPack(const IppsDLPState* pCtx, Ipp8u* pBuffer);
extern IppStatus n8_ippsDLPPack(const IppsDLPState* pCtx, Ipp8u* pBuffer);
extern IppStatus y8_ippsDLPPack(const IppsDLPState* pCtx, Ipp8u* pBuffer);
extern IppStatus e9_ippsDLPPack(const IppsDLPState* pCtx, Ipp8u* pBuffer);
extern IppStatus l9_ippsDLPPack(const IppsDLPState* pCtx, Ipp8u* pBuffer);
extern IppStatus n0_ippsDLPPack(const IppsDLPState* pCtx, Ipp8u* pBuffer);
extern IppStatus k0_ippsDLPPack(const IppsDLPState* pCtx, Ipp8u* pBuffer);
extern IppStatus k1_ippsDLPPack(const IppsDLPState* pCtx, Ipp8u* pBuffer);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsDLPPack,
	(IPP_PROC)m7_ippsDLPPack,
	(IPP_PROC)n8_ippsDLPPack,
	(IPP_PROC)y8_ippsDLPPack,
	(IPP_PROC)e9_ippsDLPPack,
	(IPP_PROC)l9_ippsDLPPack,
	(IPP_PROC)n0_ippsDLPPack,
	(IPP_PROC)k0_ippsDLPPack,
	(IPP_PROC)k1_ippsDLPPack
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsDLPPack,(const IppsDLPState* pCtx, Ipp8u* pBuffer))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsDLPPack,(const IppsDLPState* pCtx, Ipp8u* pBuffer))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsDLPPack]
        jmp  rax
  }
};
