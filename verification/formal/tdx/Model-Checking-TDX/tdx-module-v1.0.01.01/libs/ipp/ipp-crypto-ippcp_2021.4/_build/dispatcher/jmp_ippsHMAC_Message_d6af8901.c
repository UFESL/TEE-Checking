#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pMsg, int msgLen, const Ipp8u* pKey, int keyLen, Ipp8u* pMD, int mdLen, IppHashAlgId hashAlg);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsHMAC_Message(const Ipp8u* pMsg, int msgLen, const Ipp8u* pKey, int keyLen, Ipp8u* pMD, int mdLen, IppHashAlgId hashAlg);
extern IppStatus m7_ippsHMAC_Message(const Ipp8u* pMsg, int msgLen, const Ipp8u* pKey, int keyLen, Ipp8u* pMD, int mdLen, IppHashAlgId hashAlg);
extern IppStatus n8_ippsHMAC_Message(const Ipp8u* pMsg, int msgLen, const Ipp8u* pKey, int keyLen, Ipp8u* pMD, int mdLen, IppHashAlgId hashAlg);
extern IppStatus y8_ippsHMAC_Message(const Ipp8u* pMsg, int msgLen, const Ipp8u* pKey, int keyLen, Ipp8u* pMD, int mdLen, IppHashAlgId hashAlg);
extern IppStatus e9_ippsHMAC_Message(const Ipp8u* pMsg, int msgLen, const Ipp8u* pKey, int keyLen, Ipp8u* pMD, int mdLen, IppHashAlgId hashAlg);
extern IppStatus l9_ippsHMAC_Message(const Ipp8u* pMsg, int msgLen, const Ipp8u* pKey, int keyLen, Ipp8u* pMD, int mdLen, IppHashAlgId hashAlg);
extern IppStatus n0_ippsHMAC_Message(const Ipp8u* pMsg, int msgLen, const Ipp8u* pKey, int keyLen, Ipp8u* pMD, int mdLen, IppHashAlgId hashAlg);
extern IppStatus k0_ippsHMAC_Message(const Ipp8u* pMsg, int msgLen, const Ipp8u* pKey, int keyLen, Ipp8u* pMD, int mdLen, IppHashAlgId hashAlg);
extern IppStatus k1_ippsHMAC_Message(const Ipp8u* pMsg, int msgLen, const Ipp8u* pKey, int keyLen, Ipp8u* pMD, int mdLen, IppHashAlgId hashAlg);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsHMAC_Message,
	(IPP_PROC)m7_ippsHMAC_Message,
	(IPP_PROC)n8_ippsHMAC_Message,
	(IPP_PROC)y8_ippsHMAC_Message,
	(IPP_PROC)e9_ippsHMAC_Message,
	(IPP_PROC)l9_ippsHMAC_Message,
	(IPP_PROC)n0_ippsHMAC_Message,
	(IPP_PROC)k0_ippsHMAC_Message,
	(IPP_PROC)k1_ippsHMAC_Message
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsHMAC_Message,(const Ipp8u* pMsg, int msgLen, const Ipp8u* pKey, int keyLen, Ipp8u* pMD, int mdLen, IppHashAlgId hashAlg))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsHMAC_Message,(const Ipp8u* pMsg, int msgLen, const Ipp8u* pKey, int keyLen, Ipp8u* pMD, int mdLen, IppHashAlgId hashAlg))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsHMAC_Message]
        jmp  rax
  }
};
