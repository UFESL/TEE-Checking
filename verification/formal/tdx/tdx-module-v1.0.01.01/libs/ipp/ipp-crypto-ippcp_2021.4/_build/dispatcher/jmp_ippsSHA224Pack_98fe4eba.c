#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsSHA224State* pState, Ipp8u* pBuffer);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsSHA224Pack(const IppsSHA224State* pState, Ipp8u* pBuffer);
extern IppStatus m7_ippsSHA224Pack(const IppsSHA224State* pState, Ipp8u* pBuffer);
extern IppStatus n8_ippsSHA224Pack(const IppsSHA224State* pState, Ipp8u* pBuffer);
extern IppStatus y8_ippsSHA224Pack(const IppsSHA224State* pState, Ipp8u* pBuffer);
extern IppStatus e9_ippsSHA224Pack(const IppsSHA224State* pState, Ipp8u* pBuffer);
extern IppStatus l9_ippsSHA224Pack(const IppsSHA224State* pState, Ipp8u* pBuffer);
extern IppStatus n0_ippsSHA224Pack(const IppsSHA224State* pState, Ipp8u* pBuffer);
extern IppStatus k0_ippsSHA224Pack(const IppsSHA224State* pState, Ipp8u* pBuffer);
extern IppStatus k1_ippsSHA224Pack(const IppsSHA224State* pState, Ipp8u* pBuffer);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsSHA224Pack,
	(IPP_PROC)m7_ippsSHA224Pack,
	(IPP_PROC)n8_ippsSHA224Pack,
	(IPP_PROC)y8_ippsSHA224Pack,
	(IPP_PROC)e9_ippsSHA224Pack,
	(IPP_PROC)l9_ippsSHA224Pack,
	(IPP_PROC)n0_ippsSHA224Pack,
	(IPP_PROC)k0_ippsSHA224Pack,
	(IPP_PROC)k1_ippsSHA224Pack
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsSHA224Pack,(const IppsSHA224State* pState, Ipp8u* pBuffer))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsSHA224Pack,(const IppsSHA224State* pState, Ipp8u* pBuffer))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsSHA224Pack]
        jmp  rax
  }
};
