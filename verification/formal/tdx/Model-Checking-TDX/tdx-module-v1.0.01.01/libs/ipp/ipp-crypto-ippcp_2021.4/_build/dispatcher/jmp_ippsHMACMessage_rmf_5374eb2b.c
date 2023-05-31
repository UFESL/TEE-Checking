#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pMsg, int msgLen, const Ipp8u* pKey, int keyLen, Ipp8u* pMD, int mdLen, const IppsHashMethod* pMethod);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsHMACMessage_rmf(const Ipp8u* pMsg, int msgLen, const Ipp8u* pKey, int keyLen, Ipp8u* pMD, int mdLen, const IppsHashMethod* pMethod);
extern IppStatus m7_ippsHMACMessage_rmf(const Ipp8u* pMsg, int msgLen, const Ipp8u* pKey, int keyLen, Ipp8u* pMD, int mdLen, const IppsHashMethod* pMethod);
extern IppStatus n8_ippsHMACMessage_rmf(const Ipp8u* pMsg, int msgLen, const Ipp8u* pKey, int keyLen, Ipp8u* pMD, int mdLen, const IppsHashMethod* pMethod);
extern IppStatus y8_ippsHMACMessage_rmf(const Ipp8u* pMsg, int msgLen, const Ipp8u* pKey, int keyLen, Ipp8u* pMD, int mdLen, const IppsHashMethod* pMethod);
extern IppStatus e9_ippsHMACMessage_rmf(const Ipp8u* pMsg, int msgLen, const Ipp8u* pKey, int keyLen, Ipp8u* pMD, int mdLen, const IppsHashMethod* pMethod);
extern IppStatus l9_ippsHMACMessage_rmf(const Ipp8u* pMsg, int msgLen, const Ipp8u* pKey, int keyLen, Ipp8u* pMD, int mdLen, const IppsHashMethod* pMethod);
extern IppStatus n0_ippsHMACMessage_rmf(const Ipp8u* pMsg, int msgLen, const Ipp8u* pKey, int keyLen, Ipp8u* pMD, int mdLen, const IppsHashMethod* pMethod);
extern IppStatus k0_ippsHMACMessage_rmf(const Ipp8u* pMsg, int msgLen, const Ipp8u* pKey, int keyLen, Ipp8u* pMD, int mdLen, const IppsHashMethod* pMethod);
extern IppStatus k1_ippsHMACMessage_rmf(const Ipp8u* pMsg, int msgLen, const Ipp8u* pKey, int keyLen, Ipp8u* pMD, int mdLen, const IppsHashMethod* pMethod);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsHMACMessage_rmf,
	(IPP_PROC)m7_ippsHMACMessage_rmf,
	(IPP_PROC)n8_ippsHMACMessage_rmf,
	(IPP_PROC)y8_ippsHMACMessage_rmf,
	(IPP_PROC)e9_ippsHMACMessage_rmf,
	(IPP_PROC)l9_ippsHMACMessage_rmf,
	(IPP_PROC)n0_ippsHMACMessage_rmf,
	(IPP_PROC)k0_ippsHMACMessage_rmf,
	(IPP_PROC)k1_ippsHMACMessage_rmf
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsHMACMessage_rmf,(const Ipp8u* pMsg, int msgLen, const Ipp8u* pKey, int keyLen, Ipp8u* pMD, int mdLen, const IppsHashMethod* pMethod))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsHMACMessage_rmf,(const Ipp8u* pMsg, int msgLen, const Ipp8u* pKey, int keyLen, Ipp8u* pMD, int mdLen, const IppsHashMethod* pMethod))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsHMACMessage_rmf]
        jmp  rax
  }
};
