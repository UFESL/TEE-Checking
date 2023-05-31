#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pKey, int keyLen, IppsAESSpec* pCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsAESSetKey(const Ipp8u* pKey, int keyLen, IppsAESSpec* pCtx);
extern IppStatus m7_ippsAESSetKey(const Ipp8u* pKey, int keyLen, IppsAESSpec* pCtx);
extern IppStatus n8_ippsAESSetKey(const Ipp8u* pKey, int keyLen, IppsAESSpec* pCtx);
extern IppStatus y8_ippsAESSetKey(const Ipp8u* pKey, int keyLen, IppsAESSpec* pCtx);
extern IppStatus e9_ippsAESSetKey(const Ipp8u* pKey, int keyLen, IppsAESSpec* pCtx);
extern IppStatus l9_ippsAESSetKey(const Ipp8u* pKey, int keyLen, IppsAESSpec* pCtx);
extern IppStatus n0_ippsAESSetKey(const Ipp8u* pKey, int keyLen, IppsAESSpec* pCtx);
extern IppStatus k0_ippsAESSetKey(const Ipp8u* pKey, int keyLen, IppsAESSpec* pCtx);
extern IppStatus k1_ippsAESSetKey(const Ipp8u* pKey, int keyLen, IppsAESSpec* pCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsAESSetKey,
	(IPP_PROC)m7_ippsAESSetKey,
	(IPP_PROC)n8_ippsAESSetKey,
	(IPP_PROC)y8_ippsAESSetKey,
	(IPP_PROC)e9_ippsAESSetKey,
	(IPP_PROC)l9_ippsAESSetKey,
	(IPP_PROC)n0_ippsAESSetKey,
	(IPP_PROC)k0_ippsAESSetKey,
	(IPP_PROC)k1_ippsAESSetKey
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsAESSetKey,(const Ipp8u* pKey, int keyLen, IppsAESSpec* pCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsAESSetKey,(const Ipp8u* pKey, int keyLen, IppsAESSpec* pCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsAESSetKey]
        jmp  rax
  }
};
