#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pBuffer, IppsDLPState* pCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsDLPUnpack(const Ipp8u* pBuffer, IppsDLPState* pCtx);
extern IppStatus m7_ippsDLPUnpack(const Ipp8u* pBuffer, IppsDLPState* pCtx);
extern IppStatus n8_ippsDLPUnpack(const Ipp8u* pBuffer, IppsDLPState* pCtx);
extern IppStatus y8_ippsDLPUnpack(const Ipp8u* pBuffer, IppsDLPState* pCtx);
extern IppStatus e9_ippsDLPUnpack(const Ipp8u* pBuffer, IppsDLPState* pCtx);
extern IppStatus l9_ippsDLPUnpack(const Ipp8u* pBuffer, IppsDLPState* pCtx);
extern IppStatus n0_ippsDLPUnpack(const Ipp8u* pBuffer, IppsDLPState* pCtx);
extern IppStatus k0_ippsDLPUnpack(const Ipp8u* pBuffer, IppsDLPState* pCtx);
extern IppStatus k1_ippsDLPUnpack(const Ipp8u* pBuffer, IppsDLPState* pCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsDLPUnpack,
	(IPP_PROC)m7_ippsDLPUnpack,
	(IPP_PROC)n8_ippsDLPUnpack,
	(IPP_PROC)y8_ippsDLPUnpack,
	(IPP_PROC)e9_ippsDLPUnpack,
	(IPP_PROC)l9_ippsDLPUnpack,
	(IPP_PROC)n0_ippsDLPUnpack,
	(IPP_PROC)k0_ippsDLPUnpack,
	(IPP_PROC)k1_ippsDLPUnpack
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsDLPUnpack,(const Ipp8u* pBuffer, IppsDLPState* pCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsDLPUnpack,(const Ipp8u* pBuffer, IppsDLPState* pCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsDLPUnpack]
        jmp  rax
  }
};
