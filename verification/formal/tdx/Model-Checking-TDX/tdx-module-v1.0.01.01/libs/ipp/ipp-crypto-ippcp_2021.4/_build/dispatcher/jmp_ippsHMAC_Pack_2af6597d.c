#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsHMACState* pCtx, Ipp8u* pBuffer, int bufSize);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsHMAC_Pack(const IppsHMACState* pCtx, Ipp8u* pBuffer, int bufSize);
extern IppStatus m7_ippsHMAC_Pack(const IppsHMACState* pCtx, Ipp8u* pBuffer, int bufSize);
extern IppStatus n8_ippsHMAC_Pack(const IppsHMACState* pCtx, Ipp8u* pBuffer, int bufSize);
extern IppStatus y8_ippsHMAC_Pack(const IppsHMACState* pCtx, Ipp8u* pBuffer, int bufSize);
extern IppStatus e9_ippsHMAC_Pack(const IppsHMACState* pCtx, Ipp8u* pBuffer, int bufSize);
extern IppStatus l9_ippsHMAC_Pack(const IppsHMACState* pCtx, Ipp8u* pBuffer, int bufSize);
extern IppStatus n0_ippsHMAC_Pack(const IppsHMACState* pCtx, Ipp8u* pBuffer, int bufSize);
extern IppStatus k0_ippsHMAC_Pack(const IppsHMACState* pCtx, Ipp8u* pBuffer, int bufSize);
extern IppStatus k1_ippsHMAC_Pack(const IppsHMACState* pCtx, Ipp8u* pBuffer, int bufSize);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsHMAC_Pack,
	(IPP_PROC)m7_ippsHMAC_Pack,
	(IPP_PROC)n8_ippsHMAC_Pack,
	(IPP_PROC)y8_ippsHMAC_Pack,
	(IPP_PROC)e9_ippsHMAC_Pack,
	(IPP_PROC)l9_ippsHMAC_Pack,
	(IPP_PROC)n0_ippsHMAC_Pack,
	(IPP_PROC)k0_ippsHMAC_Pack,
	(IPP_PROC)k1_ippsHMAC_Pack
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsHMAC_Pack,(const IppsHMACState* pCtx, Ipp8u* pBuffer, int bufSize))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsHMAC_Pack,(const IppsHMACState* pCtx, Ipp8u* pBuffer, int bufSize))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsHMAC_Pack]
        jmp  rax
  }
};
