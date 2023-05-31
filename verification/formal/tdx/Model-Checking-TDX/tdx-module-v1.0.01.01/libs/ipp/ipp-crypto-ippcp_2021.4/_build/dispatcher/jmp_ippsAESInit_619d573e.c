#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pKey, int keyLen, IppsAESSpec* pCtx, int ctxSize);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsAESInit(const Ipp8u* pKey, int keyLen, IppsAESSpec* pCtx, int ctxSize);
extern IppStatus m7_ippsAESInit(const Ipp8u* pKey, int keyLen, IppsAESSpec* pCtx, int ctxSize);
extern IppStatus n8_ippsAESInit(const Ipp8u* pKey, int keyLen, IppsAESSpec* pCtx, int ctxSize);
extern IppStatus y8_ippsAESInit(const Ipp8u* pKey, int keyLen, IppsAESSpec* pCtx, int ctxSize);
extern IppStatus e9_ippsAESInit(const Ipp8u* pKey, int keyLen, IppsAESSpec* pCtx, int ctxSize);
extern IppStatus l9_ippsAESInit(const Ipp8u* pKey, int keyLen, IppsAESSpec* pCtx, int ctxSize);
extern IppStatus n0_ippsAESInit(const Ipp8u* pKey, int keyLen, IppsAESSpec* pCtx, int ctxSize);
extern IppStatus k0_ippsAESInit(const Ipp8u* pKey, int keyLen, IppsAESSpec* pCtx, int ctxSize);
extern IppStatus k1_ippsAESInit(const Ipp8u* pKey, int keyLen, IppsAESSpec* pCtx, int ctxSize);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsAESInit,
	(IPP_PROC)m7_ippsAESInit,
	(IPP_PROC)n8_ippsAESInit,
	(IPP_PROC)y8_ippsAESInit,
	(IPP_PROC)e9_ippsAESInit,
	(IPP_PROC)l9_ippsAESInit,
	(IPP_PROC)n0_ippsAESInit,
	(IPP_PROC)k0_ippsAESInit,
	(IPP_PROC)k1_ippsAESInit
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsAESInit,(const Ipp8u* pKey, int keyLen, IppsAESSpec* pCtx, int ctxSize))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsAESInit,(const Ipp8u* pKey, int keyLen, IppsAESSpec* pCtx, int ctxSize))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsAESInit]
        jmp  rax
  }
};
