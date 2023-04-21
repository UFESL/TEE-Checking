#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pBuffer, IppsSHA224State* pState);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsSHA224Unpack(const Ipp8u* pBuffer, IppsSHA224State* pState);
extern IppStatus m7_ippsSHA224Unpack(const Ipp8u* pBuffer, IppsSHA224State* pState);
extern IppStatus n8_ippsSHA224Unpack(const Ipp8u* pBuffer, IppsSHA224State* pState);
extern IppStatus y8_ippsSHA224Unpack(const Ipp8u* pBuffer, IppsSHA224State* pState);
extern IppStatus e9_ippsSHA224Unpack(const Ipp8u* pBuffer, IppsSHA224State* pState);
extern IppStatus l9_ippsSHA224Unpack(const Ipp8u* pBuffer, IppsSHA224State* pState);
extern IppStatus n0_ippsSHA224Unpack(const Ipp8u* pBuffer, IppsSHA224State* pState);
extern IppStatus k0_ippsSHA224Unpack(const Ipp8u* pBuffer, IppsSHA224State* pState);
extern IppStatus k1_ippsSHA224Unpack(const Ipp8u* pBuffer, IppsSHA224State* pState);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsSHA224Unpack,
	(IPP_PROC)m7_ippsSHA224Unpack,
	(IPP_PROC)n8_ippsSHA224Unpack,
	(IPP_PROC)y8_ippsSHA224Unpack,
	(IPP_PROC)e9_ippsSHA224Unpack,
	(IPP_PROC)l9_ippsSHA224Unpack,
	(IPP_PROC)n0_ippsSHA224Unpack,
	(IPP_PROC)k0_ippsSHA224Unpack,
	(IPP_PROC)k1_ippsSHA224Unpack
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsSHA224Unpack,(const Ipp8u* pBuffer, IppsSHA224State* pState))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsSHA224Unpack,(const Ipp8u* pBuffer, IppsSHA224State* pState))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsSHA224Unpack]
        jmp  rax
  }
};
