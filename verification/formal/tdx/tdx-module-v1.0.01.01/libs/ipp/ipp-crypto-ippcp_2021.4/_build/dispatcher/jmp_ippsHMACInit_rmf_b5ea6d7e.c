#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pKey, int keyLen, IppsHMACState_rmf* pCtx, const IppsHashMethod* pMethod);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsHMACInit_rmf(const Ipp8u* pKey, int keyLen, IppsHMACState_rmf* pCtx, const IppsHashMethod* pMethod);
extern IppStatus m7_ippsHMACInit_rmf(const Ipp8u* pKey, int keyLen, IppsHMACState_rmf* pCtx, const IppsHashMethod* pMethod);
extern IppStatus n8_ippsHMACInit_rmf(const Ipp8u* pKey, int keyLen, IppsHMACState_rmf* pCtx, const IppsHashMethod* pMethod);
extern IppStatus y8_ippsHMACInit_rmf(const Ipp8u* pKey, int keyLen, IppsHMACState_rmf* pCtx, const IppsHashMethod* pMethod);
extern IppStatus e9_ippsHMACInit_rmf(const Ipp8u* pKey, int keyLen, IppsHMACState_rmf* pCtx, const IppsHashMethod* pMethod);
extern IppStatus l9_ippsHMACInit_rmf(const Ipp8u* pKey, int keyLen, IppsHMACState_rmf* pCtx, const IppsHashMethod* pMethod);
extern IppStatus n0_ippsHMACInit_rmf(const Ipp8u* pKey, int keyLen, IppsHMACState_rmf* pCtx, const IppsHashMethod* pMethod);
extern IppStatus k0_ippsHMACInit_rmf(const Ipp8u* pKey, int keyLen, IppsHMACState_rmf* pCtx, const IppsHashMethod* pMethod);
extern IppStatus k1_ippsHMACInit_rmf(const Ipp8u* pKey, int keyLen, IppsHMACState_rmf* pCtx, const IppsHashMethod* pMethod);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsHMACInit_rmf,
	(IPP_PROC)m7_ippsHMACInit_rmf,
	(IPP_PROC)n8_ippsHMACInit_rmf,
	(IPP_PROC)y8_ippsHMACInit_rmf,
	(IPP_PROC)e9_ippsHMACInit_rmf,
	(IPP_PROC)l9_ippsHMACInit_rmf,
	(IPP_PROC)n0_ippsHMACInit_rmf,
	(IPP_PROC)k0_ippsHMACInit_rmf,
	(IPP_PROC)k1_ippsHMACInit_rmf
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsHMACInit_rmf,(const Ipp8u* pKey, int keyLen, IppsHMACState_rmf* pCtx, const IppsHashMethod* pMethod))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsHMACInit_rmf,(const Ipp8u* pKey, int keyLen, IppsHMACState_rmf* pCtx, const IppsHashMethod* pMethod))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsHMACInit_rmf]
        jmp  rax
  }
};
