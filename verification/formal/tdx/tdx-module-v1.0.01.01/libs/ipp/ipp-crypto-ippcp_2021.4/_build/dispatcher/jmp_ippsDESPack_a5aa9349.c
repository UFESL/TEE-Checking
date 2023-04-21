#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsDESSpec* pCtx, Ipp8u* pBuffer);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsDESPack(const IppsDESSpec* pCtx, Ipp8u* pBuffer);
extern IppStatus m7_ippsDESPack(const IppsDESSpec* pCtx, Ipp8u* pBuffer);
extern IppStatus n8_ippsDESPack(const IppsDESSpec* pCtx, Ipp8u* pBuffer);
extern IppStatus y8_ippsDESPack(const IppsDESSpec* pCtx, Ipp8u* pBuffer);
extern IppStatus e9_ippsDESPack(const IppsDESSpec* pCtx, Ipp8u* pBuffer);
extern IppStatus l9_ippsDESPack(const IppsDESSpec* pCtx, Ipp8u* pBuffer);
extern IppStatus n0_ippsDESPack(const IppsDESSpec* pCtx, Ipp8u* pBuffer);
extern IppStatus k0_ippsDESPack(const IppsDESSpec* pCtx, Ipp8u* pBuffer);
extern IppStatus k1_ippsDESPack(const IppsDESSpec* pCtx, Ipp8u* pBuffer);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsDESPack,
	(IPP_PROC)m7_ippsDESPack,
	(IPP_PROC)n8_ippsDESPack,
	(IPP_PROC)y8_ippsDESPack,
	(IPP_PROC)e9_ippsDESPack,
	(IPP_PROC)l9_ippsDESPack,
	(IPP_PROC)n0_ippsDESPack,
	(IPP_PROC)k0_ippsDESPack,
	(IPP_PROC)k1_ippsDESPack
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsDESPack,(const IppsDESSpec* pCtx, Ipp8u* pBuffer))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsDESPack,(const IppsDESSpec* pCtx, Ipp8u* pBuffer))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsDESPack]
        jmp  rax
  }
};
