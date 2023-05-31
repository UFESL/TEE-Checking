#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsHMACState_rmf* pCtx, Ipp8u* pBuffer, int bufSize);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsHMACPack_rmf(const IppsHMACState_rmf* pCtx, Ipp8u* pBuffer, int bufSize);
extern IppStatus m7_ippsHMACPack_rmf(const IppsHMACState_rmf* pCtx, Ipp8u* pBuffer, int bufSize);
extern IppStatus n8_ippsHMACPack_rmf(const IppsHMACState_rmf* pCtx, Ipp8u* pBuffer, int bufSize);
extern IppStatus y8_ippsHMACPack_rmf(const IppsHMACState_rmf* pCtx, Ipp8u* pBuffer, int bufSize);
extern IppStatus e9_ippsHMACPack_rmf(const IppsHMACState_rmf* pCtx, Ipp8u* pBuffer, int bufSize);
extern IppStatus l9_ippsHMACPack_rmf(const IppsHMACState_rmf* pCtx, Ipp8u* pBuffer, int bufSize);
extern IppStatus n0_ippsHMACPack_rmf(const IppsHMACState_rmf* pCtx, Ipp8u* pBuffer, int bufSize);
extern IppStatus k0_ippsHMACPack_rmf(const IppsHMACState_rmf* pCtx, Ipp8u* pBuffer, int bufSize);
extern IppStatus k1_ippsHMACPack_rmf(const IppsHMACState_rmf* pCtx, Ipp8u* pBuffer, int bufSize);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsHMACPack_rmf,
	(IPP_PROC)m7_ippsHMACPack_rmf,
	(IPP_PROC)n8_ippsHMACPack_rmf,
	(IPP_PROC)y8_ippsHMACPack_rmf,
	(IPP_PROC)e9_ippsHMACPack_rmf,
	(IPP_PROC)l9_ippsHMACPack_rmf,
	(IPP_PROC)n0_ippsHMACPack_rmf,
	(IPP_PROC)k0_ippsHMACPack_rmf,
	(IPP_PROC)k1_ippsHMACPack_rmf
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsHMACPack_rmf,(const IppsHMACState_rmf* pCtx, Ipp8u* pBuffer, int bufSize))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsHMACPack_rmf,(const IppsHMACState_rmf* pCtx, Ipp8u* pBuffer, int bufSize))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsHMACPack_rmf]
        jmp  rax
  }
};
