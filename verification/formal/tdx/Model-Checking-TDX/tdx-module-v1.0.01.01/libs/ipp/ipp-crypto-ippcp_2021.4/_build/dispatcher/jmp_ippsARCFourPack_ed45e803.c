#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsARCFourState* pCtx, Ipp8u* pBuffer);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsARCFourPack(const IppsARCFourState* pCtx, Ipp8u* pBuffer);
extern IppStatus m7_ippsARCFourPack(const IppsARCFourState* pCtx, Ipp8u* pBuffer);
extern IppStatus n8_ippsARCFourPack(const IppsARCFourState* pCtx, Ipp8u* pBuffer);
extern IppStatus y8_ippsARCFourPack(const IppsARCFourState* pCtx, Ipp8u* pBuffer);
extern IppStatus e9_ippsARCFourPack(const IppsARCFourState* pCtx, Ipp8u* pBuffer);
extern IppStatus l9_ippsARCFourPack(const IppsARCFourState* pCtx, Ipp8u* pBuffer);
extern IppStatus n0_ippsARCFourPack(const IppsARCFourState* pCtx, Ipp8u* pBuffer);
extern IppStatus k0_ippsARCFourPack(const IppsARCFourState* pCtx, Ipp8u* pBuffer);
extern IppStatus k1_ippsARCFourPack(const IppsARCFourState* pCtx, Ipp8u* pBuffer);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsARCFourPack,
	(IPP_PROC)m7_ippsARCFourPack,
	(IPP_PROC)n8_ippsARCFourPack,
	(IPP_PROC)y8_ippsARCFourPack,
	(IPP_PROC)e9_ippsARCFourPack,
	(IPP_PROC)l9_ippsARCFourPack,
	(IPP_PROC)n0_ippsARCFourPack,
	(IPP_PROC)k0_ippsARCFourPack,
	(IPP_PROC)k1_ippsARCFourPack
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsARCFourPack,(const IppsARCFourState* pCtx, Ipp8u* pBuffer))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsARCFourPack,(const IppsARCFourState* pCtx, Ipp8u* pBuffer))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsARCFourPack]
        jmp  rax
  }
};
