#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsHashState* pState, Ipp8u* pBuffer, int bufSize);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsHashPack(const IppsHashState* pState, Ipp8u* pBuffer, int bufSize);
extern IppStatus m7_ippsHashPack(const IppsHashState* pState, Ipp8u* pBuffer, int bufSize);
extern IppStatus n8_ippsHashPack(const IppsHashState* pState, Ipp8u* pBuffer, int bufSize);
extern IppStatus y8_ippsHashPack(const IppsHashState* pState, Ipp8u* pBuffer, int bufSize);
extern IppStatus e9_ippsHashPack(const IppsHashState* pState, Ipp8u* pBuffer, int bufSize);
extern IppStatus l9_ippsHashPack(const IppsHashState* pState, Ipp8u* pBuffer, int bufSize);
extern IppStatus n0_ippsHashPack(const IppsHashState* pState, Ipp8u* pBuffer, int bufSize);
extern IppStatus k0_ippsHashPack(const IppsHashState* pState, Ipp8u* pBuffer, int bufSize);
extern IppStatus k1_ippsHashPack(const IppsHashState* pState, Ipp8u* pBuffer, int bufSize);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsHashPack,
	(IPP_PROC)m7_ippsHashPack,
	(IPP_PROC)n8_ippsHashPack,
	(IPP_PROC)y8_ippsHashPack,
	(IPP_PROC)e9_ippsHashPack,
	(IPP_PROC)l9_ippsHashPack,
	(IPP_PROC)n0_ippsHashPack,
	(IPP_PROC)k0_ippsHashPack,
	(IPP_PROC)k1_ippsHashPack
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsHashPack,(const IppsHashState* pState, Ipp8u* pBuffer, int bufSize))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsHashPack,(const IppsHashState* pState, Ipp8u* pBuffer, int bufSize))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsHashPack]
        jmp  rax
  }
};
