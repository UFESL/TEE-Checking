#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pKey, IppsDESSpec* pCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsDESInit(const Ipp8u* pKey, IppsDESSpec* pCtx);
extern IppStatus m7_ippsDESInit(const Ipp8u* pKey, IppsDESSpec* pCtx);
extern IppStatus n8_ippsDESInit(const Ipp8u* pKey, IppsDESSpec* pCtx);
extern IppStatus y8_ippsDESInit(const Ipp8u* pKey, IppsDESSpec* pCtx);
extern IppStatus e9_ippsDESInit(const Ipp8u* pKey, IppsDESSpec* pCtx);
extern IppStatus l9_ippsDESInit(const Ipp8u* pKey, IppsDESSpec* pCtx);
extern IppStatus n0_ippsDESInit(const Ipp8u* pKey, IppsDESSpec* pCtx);
extern IppStatus k0_ippsDESInit(const Ipp8u* pKey, IppsDESSpec* pCtx);
extern IppStatus k1_ippsDESInit(const Ipp8u* pKey, IppsDESSpec* pCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsDESInit,
	(IPP_PROC)m7_ippsDESInit,
	(IPP_PROC)n8_ippsDESInit,
	(IPP_PROC)y8_ippsDESInit,
	(IPP_PROC)e9_ippsDESInit,
	(IPP_PROC)l9_ippsDESInit,
	(IPP_PROC)n0_ippsDESInit,
	(IPP_PROC)k0_ippsDESInit,
	(IPP_PROC)k1_ippsDESInit
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsDESInit,(const Ipp8u* pKey, IppsDESSpec* pCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsDESInit,(const Ipp8u* pKey, IppsDESSpec* pCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsDESInit]
        jmp  rax
  }
};
