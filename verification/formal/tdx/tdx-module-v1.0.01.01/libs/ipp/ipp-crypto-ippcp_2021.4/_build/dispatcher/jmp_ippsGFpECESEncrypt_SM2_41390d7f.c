#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pInput, Ipp8u* pOutput, int dataLen, IppsECESState_SM2* pState);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpECESEncrypt_SM2(const Ipp8u* pInput, Ipp8u* pOutput, int dataLen, IppsECESState_SM2* pState);
extern IppStatus m7_ippsGFpECESEncrypt_SM2(const Ipp8u* pInput, Ipp8u* pOutput, int dataLen, IppsECESState_SM2* pState);
extern IppStatus n8_ippsGFpECESEncrypt_SM2(const Ipp8u* pInput, Ipp8u* pOutput, int dataLen, IppsECESState_SM2* pState);
extern IppStatus y8_ippsGFpECESEncrypt_SM2(const Ipp8u* pInput, Ipp8u* pOutput, int dataLen, IppsECESState_SM2* pState);
extern IppStatus e9_ippsGFpECESEncrypt_SM2(const Ipp8u* pInput, Ipp8u* pOutput, int dataLen, IppsECESState_SM2* pState);
extern IppStatus l9_ippsGFpECESEncrypt_SM2(const Ipp8u* pInput, Ipp8u* pOutput, int dataLen, IppsECESState_SM2* pState);
extern IppStatus n0_ippsGFpECESEncrypt_SM2(const Ipp8u* pInput, Ipp8u* pOutput, int dataLen, IppsECESState_SM2* pState);
extern IppStatus k0_ippsGFpECESEncrypt_SM2(const Ipp8u* pInput, Ipp8u* pOutput, int dataLen, IppsECESState_SM2* pState);
extern IppStatus k1_ippsGFpECESEncrypt_SM2(const Ipp8u* pInput, Ipp8u* pOutput, int dataLen, IppsECESState_SM2* pState);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpECESEncrypt_SM2,
	(IPP_PROC)m7_ippsGFpECESEncrypt_SM2,
	(IPP_PROC)n8_ippsGFpECESEncrypt_SM2,
	(IPP_PROC)y8_ippsGFpECESEncrypt_SM2,
	(IPP_PROC)e9_ippsGFpECESEncrypt_SM2,
	(IPP_PROC)l9_ippsGFpECESEncrypt_SM2,
	(IPP_PROC)n0_ippsGFpECESEncrypt_SM2,
	(IPP_PROC)k0_ippsGFpECESEncrypt_SM2,
	(IPP_PROC)k1_ippsGFpECESEncrypt_SM2
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpECESEncrypt_SM2,(const Ipp8u* pInput, Ipp8u* pOutput, int dataLen, IppsECESState_SM2* pState))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpECESEncrypt_SM2,(const Ipp8u* pInput, Ipp8u* pOutput, int dataLen, IppsECESState_SM2* pState))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpECESEncrypt_SM2]
        jmp  rax
  }
};
