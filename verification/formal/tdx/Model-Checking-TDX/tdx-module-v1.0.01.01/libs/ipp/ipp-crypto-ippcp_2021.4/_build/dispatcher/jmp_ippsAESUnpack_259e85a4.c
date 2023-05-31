#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pBuffer, IppsAESSpec* pCtx, int ctxSize);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsAESUnpack(const Ipp8u* pBuffer, IppsAESSpec* pCtx, int ctxSize);
extern IppStatus m7_ippsAESUnpack(const Ipp8u* pBuffer, IppsAESSpec* pCtx, int ctxSize);
extern IppStatus n8_ippsAESUnpack(const Ipp8u* pBuffer, IppsAESSpec* pCtx, int ctxSize);
extern IppStatus y8_ippsAESUnpack(const Ipp8u* pBuffer, IppsAESSpec* pCtx, int ctxSize);
extern IppStatus e9_ippsAESUnpack(const Ipp8u* pBuffer, IppsAESSpec* pCtx, int ctxSize);
extern IppStatus l9_ippsAESUnpack(const Ipp8u* pBuffer, IppsAESSpec* pCtx, int ctxSize);
extern IppStatus n0_ippsAESUnpack(const Ipp8u* pBuffer, IppsAESSpec* pCtx, int ctxSize);
extern IppStatus k0_ippsAESUnpack(const Ipp8u* pBuffer, IppsAESSpec* pCtx, int ctxSize);
extern IppStatus k1_ippsAESUnpack(const Ipp8u* pBuffer, IppsAESSpec* pCtx, int ctxSize);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsAESUnpack,
	(IPP_PROC)m7_ippsAESUnpack,
	(IPP_PROC)n8_ippsAESUnpack,
	(IPP_PROC)y8_ippsAESUnpack,
	(IPP_PROC)e9_ippsAESUnpack,
	(IPP_PROC)l9_ippsAESUnpack,
	(IPP_PROC)n0_ippsAESUnpack,
	(IPP_PROC)k0_ippsAESUnpack,
	(IPP_PROC)k1_ippsAESUnpack
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsAESUnpack,(const Ipp8u* pBuffer, IppsAESSpec* pCtx, int ctxSize))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsAESUnpack,(const Ipp8u* pBuffer, IppsAESSpec* pCtx, int ctxSize))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsAESUnpack]
        jmp  rax
  }
};
