#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsSM3State* pState, Ipp8u* pBuffer);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsSM3Pack(const IppsSM3State* pState, Ipp8u* pBuffer);
extern IppStatus m7_ippsSM3Pack(const IppsSM3State* pState, Ipp8u* pBuffer);
extern IppStatus n8_ippsSM3Pack(const IppsSM3State* pState, Ipp8u* pBuffer);
extern IppStatus y8_ippsSM3Pack(const IppsSM3State* pState, Ipp8u* pBuffer);
extern IppStatus e9_ippsSM3Pack(const IppsSM3State* pState, Ipp8u* pBuffer);
extern IppStatus l9_ippsSM3Pack(const IppsSM3State* pState, Ipp8u* pBuffer);
extern IppStatus n0_ippsSM3Pack(const IppsSM3State* pState, Ipp8u* pBuffer);
extern IppStatus k0_ippsSM3Pack(const IppsSM3State* pState, Ipp8u* pBuffer);
extern IppStatus k1_ippsSM3Pack(const IppsSM3State* pState, Ipp8u* pBuffer);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsSM3Pack,
	(IPP_PROC)m7_ippsSM3Pack,
	(IPP_PROC)n8_ippsSM3Pack,
	(IPP_PROC)y8_ippsSM3Pack,
	(IPP_PROC)e9_ippsSM3Pack,
	(IPP_PROC)l9_ippsSM3Pack,
	(IPP_PROC)n0_ippsSM3Pack,
	(IPP_PROC)k0_ippsSM3Pack,
	(IPP_PROC)k1_ippsSM3Pack
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsSM3Pack,(const IppsSM3State* pState, Ipp8u* pBuffer))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsSM3Pack,(const IppsSM3State* pState, Ipp8u* pBuffer))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsSM3Pack]
        jmp  rax
  }
};
