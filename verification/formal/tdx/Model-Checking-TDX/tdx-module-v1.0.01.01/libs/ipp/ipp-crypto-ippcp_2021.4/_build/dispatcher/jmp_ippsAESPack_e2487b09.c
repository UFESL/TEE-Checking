#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsAESSpec* pCtx, Ipp8u* pBuffer, int bufSize);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsAESPack(const IppsAESSpec* pCtx, Ipp8u* pBuffer, int bufSize);
extern IppStatus m7_ippsAESPack(const IppsAESSpec* pCtx, Ipp8u* pBuffer, int bufSize);
extern IppStatus n8_ippsAESPack(const IppsAESSpec* pCtx, Ipp8u* pBuffer, int bufSize);
extern IppStatus y8_ippsAESPack(const IppsAESSpec* pCtx, Ipp8u* pBuffer, int bufSize);
extern IppStatus e9_ippsAESPack(const IppsAESSpec* pCtx, Ipp8u* pBuffer, int bufSize);
extern IppStatus l9_ippsAESPack(const IppsAESSpec* pCtx, Ipp8u* pBuffer, int bufSize);
extern IppStatus n0_ippsAESPack(const IppsAESSpec* pCtx, Ipp8u* pBuffer, int bufSize);
extern IppStatus k0_ippsAESPack(const IppsAESSpec* pCtx, Ipp8u* pBuffer, int bufSize);
extern IppStatus k1_ippsAESPack(const IppsAESSpec* pCtx, Ipp8u* pBuffer, int bufSize);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsAESPack,
	(IPP_PROC)m7_ippsAESPack,
	(IPP_PROC)n8_ippsAESPack,
	(IPP_PROC)y8_ippsAESPack,
	(IPP_PROC)e9_ippsAESPack,
	(IPP_PROC)l9_ippsAESPack,
	(IPP_PROC)n0_ippsAESPack,
	(IPP_PROC)k0_ippsAESPack,
	(IPP_PROC)k1_ippsAESPack
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsAESPack,(const IppsAESSpec* pCtx, Ipp8u* pBuffer, int bufSize))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsAESPack,(const IppsAESSpec* pCtx, Ipp8u* pBuffer, int bufSize))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsAESPack]
        jmp  rax
  }
};
