#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pKey, int keyLen, const Ipp8u* pAD[], const int pADlen[], int numAD, Ipp8u* pV);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsAES_S2V_CMAC(const Ipp8u* pKey, int keyLen, const Ipp8u* pAD[], const int pADlen[], int numAD, Ipp8u* pV);
extern IppStatus m7_ippsAES_S2V_CMAC(const Ipp8u* pKey, int keyLen, const Ipp8u* pAD[], const int pADlen[], int numAD, Ipp8u* pV);
extern IppStatus n8_ippsAES_S2V_CMAC(const Ipp8u* pKey, int keyLen, const Ipp8u* pAD[], const int pADlen[], int numAD, Ipp8u* pV);
extern IppStatus y8_ippsAES_S2V_CMAC(const Ipp8u* pKey, int keyLen, const Ipp8u* pAD[], const int pADlen[], int numAD, Ipp8u* pV);
extern IppStatus e9_ippsAES_S2V_CMAC(const Ipp8u* pKey, int keyLen, const Ipp8u* pAD[], const int pADlen[], int numAD, Ipp8u* pV);
extern IppStatus l9_ippsAES_S2V_CMAC(const Ipp8u* pKey, int keyLen, const Ipp8u* pAD[], const int pADlen[], int numAD, Ipp8u* pV);
extern IppStatus n0_ippsAES_S2V_CMAC(const Ipp8u* pKey, int keyLen, const Ipp8u* pAD[], const int pADlen[], int numAD, Ipp8u* pV);
extern IppStatus k0_ippsAES_S2V_CMAC(const Ipp8u* pKey, int keyLen, const Ipp8u* pAD[], const int pADlen[], int numAD, Ipp8u* pV);
extern IppStatus k1_ippsAES_S2V_CMAC(const Ipp8u* pKey, int keyLen, const Ipp8u* pAD[], const int pADlen[], int numAD, Ipp8u* pV);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsAES_S2V_CMAC,
	(IPP_PROC)m7_ippsAES_S2V_CMAC,
	(IPP_PROC)n8_ippsAES_S2V_CMAC,
	(IPP_PROC)y8_ippsAES_S2V_CMAC,
	(IPP_PROC)e9_ippsAES_S2V_CMAC,
	(IPP_PROC)l9_ippsAES_S2V_CMAC,
	(IPP_PROC)n0_ippsAES_S2V_CMAC,
	(IPP_PROC)k0_ippsAES_S2V_CMAC,
	(IPP_PROC)k1_ippsAES_S2V_CMAC
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsAES_S2V_CMAC,(const Ipp8u* pKey, int keyLen, const Ipp8u* pAD[], const int pADlen[], int numAD, Ipp8u* pV))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsAES_S2V_CMAC,(const Ipp8u* pKey, int keyLen, const Ipp8u* pAD[], const int pADlen[], int numAD, Ipp8u* pV))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsAES_S2V_CMAC]
        jmp  rax
  }
};
