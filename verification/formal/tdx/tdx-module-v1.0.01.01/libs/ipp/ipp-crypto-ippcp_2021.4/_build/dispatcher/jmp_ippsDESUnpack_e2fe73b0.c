#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pBuffer, IppsDESSpec* pCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsDESUnpack(const Ipp8u* pBuffer, IppsDESSpec* pCtx);
extern IppStatus m7_ippsDESUnpack(const Ipp8u* pBuffer, IppsDESSpec* pCtx);
extern IppStatus n8_ippsDESUnpack(const Ipp8u* pBuffer, IppsDESSpec* pCtx);
extern IppStatus y8_ippsDESUnpack(const Ipp8u* pBuffer, IppsDESSpec* pCtx);
extern IppStatus e9_ippsDESUnpack(const Ipp8u* pBuffer, IppsDESSpec* pCtx);
extern IppStatus l9_ippsDESUnpack(const Ipp8u* pBuffer, IppsDESSpec* pCtx);
extern IppStatus n0_ippsDESUnpack(const Ipp8u* pBuffer, IppsDESSpec* pCtx);
extern IppStatus k0_ippsDESUnpack(const Ipp8u* pBuffer, IppsDESSpec* pCtx);
extern IppStatus k1_ippsDESUnpack(const Ipp8u* pBuffer, IppsDESSpec* pCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsDESUnpack,
	(IPP_PROC)m7_ippsDESUnpack,
	(IPP_PROC)n8_ippsDESUnpack,
	(IPP_PROC)y8_ippsDESUnpack,
	(IPP_PROC)e9_ippsDESUnpack,
	(IPP_PROC)l9_ippsDESUnpack,
	(IPP_PROC)n0_ippsDESUnpack,
	(IPP_PROC)k0_ippsDESUnpack,
	(IPP_PROC)k1_ippsDESUnpack
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsDESUnpack,(const Ipp8u* pBuffer, IppsDESSpec* pCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsDESUnpack,(const Ipp8u* pBuffer, IppsDESSpec* pCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsDESUnpack]
        jmp  rax
  }
};
