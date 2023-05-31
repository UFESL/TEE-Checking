#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u *pKey, int keyLen, IppsARCFourState *pCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsARCFourInit(const Ipp8u *pKey, int keyLen, IppsARCFourState *pCtx);
extern IppStatus m7_ippsARCFourInit(const Ipp8u *pKey, int keyLen, IppsARCFourState *pCtx);
extern IppStatus n8_ippsARCFourInit(const Ipp8u *pKey, int keyLen, IppsARCFourState *pCtx);
extern IppStatus y8_ippsARCFourInit(const Ipp8u *pKey, int keyLen, IppsARCFourState *pCtx);
extern IppStatus e9_ippsARCFourInit(const Ipp8u *pKey, int keyLen, IppsARCFourState *pCtx);
extern IppStatus l9_ippsARCFourInit(const Ipp8u *pKey, int keyLen, IppsARCFourState *pCtx);
extern IppStatus n0_ippsARCFourInit(const Ipp8u *pKey, int keyLen, IppsARCFourState *pCtx);
extern IppStatus k0_ippsARCFourInit(const Ipp8u *pKey, int keyLen, IppsARCFourState *pCtx);
extern IppStatus k1_ippsARCFourInit(const Ipp8u *pKey, int keyLen, IppsARCFourState *pCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsARCFourInit,
	(IPP_PROC)m7_ippsARCFourInit,
	(IPP_PROC)n8_ippsARCFourInit,
	(IPP_PROC)y8_ippsARCFourInit,
	(IPP_PROC)e9_ippsARCFourInit,
	(IPP_PROC)l9_ippsARCFourInit,
	(IPP_PROC)n0_ippsARCFourInit,
	(IPP_PROC)k0_ippsARCFourInit,
	(IPP_PROC)k1_ippsARCFourInit
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsARCFourInit,(const Ipp8u *pKey, int keyLen, IppsARCFourState *pCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsARCFourInit,(const Ipp8u *pKey, int keyLen, IppsARCFourState *pCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsARCFourInit]
        jmp  rax
  }
};
