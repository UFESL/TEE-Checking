#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pMsg, int len, Ipp8u* pMD, IppHashAlgId hashAlg);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsHashMessage(const Ipp8u* pMsg, int len, Ipp8u* pMD, IppHashAlgId hashAlg);
extern IppStatus m7_ippsHashMessage(const Ipp8u* pMsg, int len, Ipp8u* pMD, IppHashAlgId hashAlg);
extern IppStatus n8_ippsHashMessage(const Ipp8u* pMsg, int len, Ipp8u* pMD, IppHashAlgId hashAlg);
extern IppStatus y8_ippsHashMessage(const Ipp8u* pMsg, int len, Ipp8u* pMD, IppHashAlgId hashAlg);
extern IppStatus e9_ippsHashMessage(const Ipp8u* pMsg, int len, Ipp8u* pMD, IppHashAlgId hashAlg);
extern IppStatus l9_ippsHashMessage(const Ipp8u* pMsg, int len, Ipp8u* pMD, IppHashAlgId hashAlg);
extern IppStatus n0_ippsHashMessage(const Ipp8u* pMsg, int len, Ipp8u* pMD, IppHashAlgId hashAlg);
extern IppStatus k0_ippsHashMessage(const Ipp8u* pMsg, int len, Ipp8u* pMD, IppHashAlgId hashAlg);
extern IppStatus k1_ippsHashMessage(const Ipp8u* pMsg, int len, Ipp8u* pMD, IppHashAlgId hashAlg);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsHashMessage,
	(IPP_PROC)m7_ippsHashMessage,
	(IPP_PROC)n8_ippsHashMessage,
	(IPP_PROC)y8_ippsHashMessage,
	(IPP_PROC)e9_ippsHashMessage,
	(IPP_PROC)l9_ippsHashMessage,
	(IPP_PROC)n0_ippsHashMessage,
	(IPP_PROC)k0_ippsHashMessage,
	(IPP_PROC)k1_ippsHashMessage
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsHashMessage,(const Ipp8u* pMsg, int len, Ipp8u* pMD, IppHashAlgId hashAlg))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsHashMessage,(const Ipp8u* pMsg, int len, Ipp8u* pMD, IppHashAlgId hashAlg))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsHashMessage]
        jmp  rax
  }
};
