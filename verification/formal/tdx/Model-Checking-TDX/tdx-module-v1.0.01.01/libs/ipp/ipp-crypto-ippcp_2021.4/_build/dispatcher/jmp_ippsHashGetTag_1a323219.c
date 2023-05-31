#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(Ipp8u* pTag, int tagLen, const IppsHashState* pState);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsHashGetTag(Ipp8u* pTag, int tagLen, const IppsHashState* pState);
extern IppStatus m7_ippsHashGetTag(Ipp8u* pTag, int tagLen, const IppsHashState* pState);
extern IppStatus n8_ippsHashGetTag(Ipp8u* pTag, int tagLen, const IppsHashState* pState);
extern IppStatus y8_ippsHashGetTag(Ipp8u* pTag, int tagLen, const IppsHashState* pState);
extern IppStatus e9_ippsHashGetTag(Ipp8u* pTag, int tagLen, const IppsHashState* pState);
extern IppStatus l9_ippsHashGetTag(Ipp8u* pTag, int tagLen, const IppsHashState* pState);
extern IppStatus n0_ippsHashGetTag(Ipp8u* pTag, int tagLen, const IppsHashState* pState);
extern IppStatus k0_ippsHashGetTag(Ipp8u* pTag, int tagLen, const IppsHashState* pState);
extern IppStatus k1_ippsHashGetTag(Ipp8u* pTag, int tagLen, const IppsHashState* pState);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsHashGetTag,
	(IPP_PROC)m7_ippsHashGetTag,
	(IPP_PROC)n8_ippsHashGetTag,
	(IPP_PROC)y8_ippsHashGetTag,
	(IPP_PROC)e9_ippsHashGetTag,
	(IPP_PROC)l9_ippsHashGetTag,
	(IPP_PROC)n0_ippsHashGetTag,
	(IPP_PROC)k0_ippsHashGetTag,
	(IPP_PROC)k1_ippsHashGetTag
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsHashGetTag,(Ipp8u* pTag, int tagLen, const IppsHashState* pState))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsHashGetTag,(Ipp8u* pTag, int tagLen, const IppsHashState* pState))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsHashGetTag]
        jmp  rax
  }
};
