#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pMsg, int msgLen, const Ipp8u* pSign, int* pIsValid, const IppsRSAPublicKeyState* pKey, IppHashAlgId hashAlg, Ipp8u* pBuffer);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsRSAVerify_PKCS1v15(const Ipp8u* pMsg, int msgLen, const Ipp8u* pSign, int* pIsValid, const IppsRSAPublicKeyState* pKey, IppHashAlgId hashAlg, Ipp8u* pBuffer);
extern IppStatus m7_ippsRSAVerify_PKCS1v15(const Ipp8u* pMsg, int msgLen, const Ipp8u* pSign, int* pIsValid, const IppsRSAPublicKeyState* pKey, IppHashAlgId hashAlg, Ipp8u* pBuffer);
extern IppStatus n8_ippsRSAVerify_PKCS1v15(const Ipp8u* pMsg, int msgLen, const Ipp8u* pSign, int* pIsValid, const IppsRSAPublicKeyState* pKey, IppHashAlgId hashAlg, Ipp8u* pBuffer);
extern IppStatus y8_ippsRSAVerify_PKCS1v15(const Ipp8u* pMsg, int msgLen, const Ipp8u* pSign, int* pIsValid, const IppsRSAPublicKeyState* pKey, IppHashAlgId hashAlg, Ipp8u* pBuffer);
extern IppStatus e9_ippsRSAVerify_PKCS1v15(const Ipp8u* pMsg, int msgLen, const Ipp8u* pSign, int* pIsValid, const IppsRSAPublicKeyState* pKey, IppHashAlgId hashAlg, Ipp8u* pBuffer);
extern IppStatus l9_ippsRSAVerify_PKCS1v15(const Ipp8u* pMsg, int msgLen, const Ipp8u* pSign, int* pIsValid, const IppsRSAPublicKeyState* pKey, IppHashAlgId hashAlg, Ipp8u* pBuffer);
extern IppStatus n0_ippsRSAVerify_PKCS1v15(const Ipp8u* pMsg, int msgLen, const Ipp8u* pSign, int* pIsValid, const IppsRSAPublicKeyState* pKey, IppHashAlgId hashAlg, Ipp8u* pBuffer);
extern IppStatus k0_ippsRSAVerify_PKCS1v15(const Ipp8u* pMsg, int msgLen, const Ipp8u* pSign, int* pIsValid, const IppsRSAPublicKeyState* pKey, IppHashAlgId hashAlg, Ipp8u* pBuffer);
extern IppStatus k1_ippsRSAVerify_PKCS1v15(const Ipp8u* pMsg, int msgLen, const Ipp8u* pSign, int* pIsValid, const IppsRSAPublicKeyState* pKey, IppHashAlgId hashAlg, Ipp8u* pBuffer);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsRSAVerify_PKCS1v15,
	(IPP_PROC)m7_ippsRSAVerify_PKCS1v15,
	(IPP_PROC)n8_ippsRSAVerify_PKCS1v15,
	(IPP_PROC)y8_ippsRSAVerify_PKCS1v15,
	(IPP_PROC)e9_ippsRSAVerify_PKCS1v15,
	(IPP_PROC)l9_ippsRSAVerify_PKCS1v15,
	(IPP_PROC)n0_ippsRSAVerify_PKCS1v15,
	(IPP_PROC)k0_ippsRSAVerify_PKCS1v15,
	(IPP_PROC)k1_ippsRSAVerify_PKCS1v15
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsRSAVerify_PKCS1v15,(const Ipp8u* pMsg, int msgLen, const Ipp8u* pSign, int* pIsValid, const IppsRSAPublicKeyState* pKey, IppHashAlgId hashAlg, Ipp8u* pBuffer))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsRSAVerify_PKCS1v15,(const Ipp8u* pMsg, int msgLen, const Ipp8u* pSign, int* pIsValid, const IppsRSAPublicKeyState* pKey, IppHashAlgId hashAlg, Ipp8u* pBuffer))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsRSAVerify_PKCS1v15]
        jmp  rax
  }
};
