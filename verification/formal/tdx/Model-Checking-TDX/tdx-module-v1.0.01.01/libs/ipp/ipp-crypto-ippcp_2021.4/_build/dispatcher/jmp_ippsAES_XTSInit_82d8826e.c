#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pKey, int keyLen, int duBitsize, IppsAES_XTSSpec* pCtx,int ctxSize);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsAES_XTSInit(const Ipp8u* pKey, int keyLen, int duBitsize, IppsAES_XTSSpec* pCtx,int ctxSize);
extern IppStatus m7_ippsAES_XTSInit(const Ipp8u* pKey, int keyLen, int duBitsize, IppsAES_XTSSpec* pCtx,int ctxSize);
extern IppStatus n8_ippsAES_XTSInit(const Ipp8u* pKey, int keyLen, int duBitsize, IppsAES_XTSSpec* pCtx,int ctxSize);
extern IppStatus y8_ippsAES_XTSInit(const Ipp8u* pKey, int keyLen, int duBitsize, IppsAES_XTSSpec* pCtx,int ctxSize);
extern IppStatus e9_ippsAES_XTSInit(const Ipp8u* pKey, int keyLen, int duBitsize, IppsAES_XTSSpec* pCtx,int ctxSize);
extern IppStatus l9_ippsAES_XTSInit(const Ipp8u* pKey, int keyLen, int duBitsize, IppsAES_XTSSpec* pCtx,int ctxSize);
extern IppStatus n0_ippsAES_XTSInit(const Ipp8u* pKey, int keyLen, int duBitsize, IppsAES_XTSSpec* pCtx,int ctxSize);
extern IppStatus k0_ippsAES_XTSInit(const Ipp8u* pKey, int keyLen, int duBitsize, IppsAES_XTSSpec* pCtx,int ctxSize);
extern IppStatus k1_ippsAES_XTSInit(const Ipp8u* pKey, int keyLen, int duBitsize, IppsAES_XTSSpec* pCtx,int ctxSize);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsAES_XTSInit,
	(IPP_PROC)m7_ippsAES_XTSInit,
	(IPP_PROC)n8_ippsAES_XTSInit,
	(IPP_PROC)y8_ippsAES_XTSInit,
	(IPP_PROC)e9_ippsAES_XTSInit,
	(IPP_PROC)l9_ippsAES_XTSInit,
	(IPP_PROC)n0_ippsAES_XTSInit,
	(IPP_PROC)k0_ippsAES_XTSInit,
	(IPP_PROC)k1_ippsAES_XTSInit
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsAES_XTSInit,(const Ipp8u* pKey, int keyLen, int duBitsize, IppsAES_XTSSpec* pCtx,int ctxSize))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsAES_XTSInit,(const Ipp8u* pKey, int keyLen, int duBitsize, IppsAES_XTSSpec* pCtx,int ctxSize))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsAES_XTSInit]
        jmp  rax
  }
};
