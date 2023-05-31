#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pMsg, int msgLen, const Ipp8u* pSalt, int saltLen, Ipp8u* pSign, const IppsRSAPrivateKeyState* pPrvKey, const IppsRSAPublicKeyState* pPubKey, IppHashAlgId hashAlg, Ipp8u* pBuffer);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsRSASign_PSS(const Ipp8u* pMsg, int msgLen, const Ipp8u* pSalt, int saltLen, Ipp8u* pSign, const IppsRSAPrivateKeyState* pPrvKey, const IppsRSAPublicKeyState* pPubKey, IppHashAlgId hashAlg, Ipp8u* pBuffer);
extern IppStatus m7_ippsRSASign_PSS(const Ipp8u* pMsg, int msgLen, const Ipp8u* pSalt, int saltLen, Ipp8u* pSign, const IppsRSAPrivateKeyState* pPrvKey, const IppsRSAPublicKeyState* pPubKey, IppHashAlgId hashAlg, Ipp8u* pBuffer);
extern IppStatus n8_ippsRSASign_PSS(const Ipp8u* pMsg, int msgLen, const Ipp8u* pSalt, int saltLen, Ipp8u* pSign, const IppsRSAPrivateKeyState* pPrvKey, const IppsRSAPublicKeyState* pPubKey, IppHashAlgId hashAlg, Ipp8u* pBuffer);
extern IppStatus y8_ippsRSASign_PSS(const Ipp8u* pMsg, int msgLen, const Ipp8u* pSalt, int saltLen, Ipp8u* pSign, const IppsRSAPrivateKeyState* pPrvKey, const IppsRSAPublicKeyState* pPubKey, IppHashAlgId hashAlg, Ipp8u* pBuffer);
extern IppStatus e9_ippsRSASign_PSS(const Ipp8u* pMsg, int msgLen, const Ipp8u* pSalt, int saltLen, Ipp8u* pSign, const IppsRSAPrivateKeyState* pPrvKey, const IppsRSAPublicKeyState* pPubKey, IppHashAlgId hashAlg, Ipp8u* pBuffer);
extern IppStatus l9_ippsRSASign_PSS(const Ipp8u* pMsg, int msgLen, const Ipp8u* pSalt, int saltLen, Ipp8u* pSign, const IppsRSAPrivateKeyState* pPrvKey, const IppsRSAPublicKeyState* pPubKey, IppHashAlgId hashAlg, Ipp8u* pBuffer);
extern IppStatus n0_ippsRSASign_PSS(const Ipp8u* pMsg, int msgLen, const Ipp8u* pSalt, int saltLen, Ipp8u* pSign, const IppsRSAPrivateKeyState* pPrvKey, const IppsRSAPublicKeyState* pPubKey, IppHashAlgId hashAlg, Ipp8u* pBuffer);
extern IppStatus k0_ippsRSASign_PSS(const Ipp8u* pMsg, int msgLen, const Ipp8u* pSalt, int saltLen, Ipp8u* pSign, const IppsRSAPrivateKeyState* pPrvKey, const IppsRSAPublicKeyState* pPubKey, IppHashAlgId hashAlg, Ipp8u* pBuffer);
extern IppStatus k1_ippsRSASign_PSS(const Ipp8u* pMsg, int msgLen, const Ipp8u* pSalt, int saltLen, Ipp8u* pSign, const IppsRSAPrivateKeyState* pPrvKey, const IppsRSAPublicKeyState* pPubKey, IppHashAlgId hashAlg, Ipp8u* pBuffer);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsRSASign_PSS,
	(IPP_PROC)m7_ippsRSASign_PSS,
	(IPP_PROC)n8_ippsRSASign_PSS,
	(IPP_PROC)y8_ippsRSASign_PSS,
	(IPP_PROC)e9_ippsRSASign_PSS,
	(IPP_PROC)l9_ippsRSASign_PSS,
	(IPP_PROC)n0_ippsRSASign_PSS,
	(IPP_PROC)k0_ippsRSASign_PSS,
	(IPP_PROC)k1_ippsRSASign_PSS
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsRSASign_PSS,(const Ipp8u* pMsg, int msgLen, const Ipp8u* pSalt, int saltLen, Ipp8u* pSign, const IppsRSAPrivateKeyState* pPrvKey, const IppsRSAPublicKeyState* pPubKey, IppHashAlgId hashAlg, Ipp8u* pBuffer))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsRSASign_PSS,(const Ipp8u* pMsg, int msgLen, const Ipp8u* pSalt, int saltLen, Ipp8u* pSign, const IppsRSAPrivateKeyState* pPrvKey, const IppsRSAPublicKeyState* pPubKey, IppHashAlgId hashAlg, Ipp8u* pBuffer))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsRSASign_PSS]
        jmp  rax
  }
};
