#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pCtxt, IppsBigNumState* pPtxt, const IppsRSAPrivateKeyState* pKey, Ipp8u* pScratchBuffer);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsRSA_Decrypt(const IppsBigNumState* pCtxt, IppsBigNumState* pPtxt, const IppsRSAPrivateKeyState* pKey, Ipp8u* pScratchBuffer);
extern IppStatus m7_ippsRSA_Decrypt(const IppsBigNumState* pCtxt, IppsBigNumState* pPtxt, const IppsRSAPrivateKeyState* pKey, Ipp8u* pScratchBuffer);
extern IppStatus n8_ippsRSA_Decrypt(const IppsBigNumState* pCtxt, IppsBigNumState* pPtxt, const IppsRSAPrivateKeyState* pKey, Ipp8u* pScratchBuffer);
extern IppStatus y8_ippsRSA_Decrypt(const IppsBigNumState* pCtxt, IppsBigNumState* pPtxt, const IppsRSAPrivateKeyState* pKey, Ipp8u* pScratchBuffer);
extern IppStatus e9_ippsRSA_Decrypt(const IppsBigNumState* pCtxt, IppsBigNumState* pPtxt, const IppsRSAPrivateKeyState* pKey, Ipp8u* pScratchBuffer);
extern IppStatus l9_ippsRSA_Decrypt(const IppsBigNumState* pCtxt, IppsBigNumState* pPtxt, const IppsRSAPrivateKeyState* pKey, Ipp8u* pScratchBuffer);
extern IppStatus n0_ippsRSA_Decrypt(const IppsBigNumState* pCtxt, IppsBigNumState* pPtxt, const IppsRSAPrivateKeyState* pKey, Ipp8u* pScratchBuffer);
extern IppStatus k0_ippsRSA_Decrypt(const IppsBigNumState* pCtxt, IppsBigNumState* pPtxt, const IppsRSAPrivateKeyState* pKey, Ipp8u* pScratchBuffer);
extern IppStatus k1_ippsRSA_Decrypt(const IppsBigNumState* pCtxt, IppsBigNumState* pPtxt, const IppsRSAPrivateKeyState* pKey, Ipp8u* pScratchBuffer);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsRSA_Decrypt,
	(IPP_PROC)m7_ippsRSA_Decrypt,
	(IPP_PROC)n8_ippsRSA_Decrypt,
	(IPP_PROC)y8_ippsRSA_Decrypt,
	(IPP_PROC)e9_ippsRSA_Decrypt,
	(IPP_PROC)l9_ippsRSA_Decrypt,
	(IPP_PROC)n0_ippsRSA_Decrypt,
	(IPP_PROC)k0_ippsRSA_Decrypt,
	(IPP_PROC)k1_ippsRSA_Decrypt
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsRSA_Decrypt,(const IppsBigNumState* pCtxt, IppsBigNumState* pPtxt, const IppsRSAPrivateKeyState* pKey, Ipp8u* pScratchBuffer))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsRSA_Decrypt,(const IppsBigNumState* pCtxt, IppsBigNumState* pPtxt, const IppsRSAPrivateKeyState* pKey, Ipp8u* pScratchBuffer))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsRSA_Decrypt]
        jmp  rax
  }
};
