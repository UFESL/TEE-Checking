#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pInput, Ipp8u* pOutput, int dataLen, IppsECESState_SM2* pState);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpECESDecrypt_SM2(const Ipp8u* pInput, Ipp8u* pOutput, int dataLen, IppsECESState_SM2* pState);
extern IppStatus m7_ippsGFpECESDecrypt_SM2(const Ipp8u* pInput, Ipp8u* pOutput, int dataLen, IppsECESState_SM2* pState);
extern IppStatus n8_ippsGFpECESDecrypt_SM2(const Ipp8u* pInput, Ipp8u* pOutput, int dataLen, IppsECESState_SM2* pState);
extern IppStatus y8_ippsGFpECESDecrypt_SM2(const Ipp8u* pInput, Ipp8u* pOutput, int dataLen, IppsECESState_SM2* pState);
extern IppStatus e9_ippsGFpECESDecrypt_SM2(const Ipp8u* pInput, Ipp8u* pOutput, int dataLen, IppsECESState_SM2* pState);
extern IppStatus l9_ippsGFpECESDecrypt_SM2(const Ipp8u* pInput, Ipp8u* pOutput, int dataLen, IppsECESState_SM2* pState);
extern IppStatus n0_ippsGFpECESDecrypt_SM2(const Ipp8u* pInput, Ipp8u* pOutput, int dataLen, IppsECESState_SM2* pState);
extern IppStatus k0_ippsGFpECESDecrypt_SM2(const Ipp8u* pInput, Ipp8u* pOutput, int dataLen, IppsECESState_SM2* pState);
extern IppStatus k1_ippsGFpECESDecrypt_SM2(const Ipp8u* pInput, Ipp8u* pOutput, int dataLen, IppsECESState_SM2* pState);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpECESDecrypt_SM2,
	(IPP_PROC)m7_ippsGFpECESDecrypt_SM2,
	(IPP_PROC)n8_ippsGFpECESDecrypt_SM2,
	(IPP_PROC)y8_ippsGFpECESDecrypt_SM2,
	(IPP_PROC)e9_ippsGFpECESDecrypt_SM2,
	(IPP_PROC)l9_ippsGFpECESDecrypt_SM2,
	(IPP_PROC)n0_ippsGFpECESDecrypt_SM2,
	(IPP_PROC)k0_ippsGFpECESDecrypt_SM2,
	(IPP_PROC)k1_ippsGFpECESDecrypt_SM2
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpECESDecrypt_SM2,(const Ipp8u* pInput, Ipp8u* pOutput, int dataLen, IppsECESState_SM2* pState))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpECESDecrypt_SM2,(const Ipp8u* pInput, Ipp8u* pOutput, int dataLen, IppsECESState_SM2* pState))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpECESDecrypt_SM2]
        jmp  rax
  }
};
