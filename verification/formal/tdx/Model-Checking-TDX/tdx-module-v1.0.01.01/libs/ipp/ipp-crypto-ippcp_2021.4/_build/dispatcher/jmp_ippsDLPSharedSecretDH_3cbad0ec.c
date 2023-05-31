#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pPrvKeyA, const IppsBigNumState* pPubKeyB, IppsBigNumState* pShare, IppsDLPState* pCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsDLPSharedSecretDH(const IppsBigNumState* pPrvKeyA, const IppsBigNumState* pPubKeyB, IppsBigNumState* pShare, IppsDLPState* pCtx);
extern IppStatus m7_ippsDLPSharedSecretDH(const IppsBigNumState* pPrvKeyA, const IppsBigNumState* pPubKeyB, IppsBigNumState* pShare, IppsDLPState* pCtx);
extern IppStatus n8_ippsDLPSharedSecretDH(const IppsBigNumState* pPrvKeyA, const IppsBigNumState* pPubKeyB, IppsBigNumState* pShare, IppsDLPState* pCtx);
extern IppStatus y8_ippsDLPSharedSecretDH(const IppsBigNumState* pPrvKeyA, const IppsBigNumState* pPubKeyB, IppsBigNumState* pShare, IppsDLPState* pCtx);
extern IppStatus e9_ippsDLPSharedSecretDH(const IppsBigNumState* pPrvKeyA, const IppsBigNumState* pPubKeyB, IppsBigNumState* pShare, IppsDLPState* pCtx);
extern IppStatus l9_ippsDLPSharedSecretDH(const IppsBigNumState* pPrvKeyA, const IppsBigNumState* pPubKeyB, IppsBigNumState* pShare, IppsDLPState* pCtx);
extern IppStatus n0_ippsDLPSharedSecretDH(const IppsBigNumState* pPrvKeyA, const IppsBigNumState* pPubKeyB, IppsBigNumState* pShare, IppsDLPState* pCtx);
extern IppStatus k0_ippsDLPSharedSecretDH(const IppsBigNumState* pPrvKeyA, const IppsBigNumState* pPubKeyB, IppsBigNumState* pShare, IppsDLPState* pCtx);
extern IppStatus k1_ippsDLPSharedSecretDH(const IppsBigNumState* pPrvKeyA, const IppsBigNumState* pPubKeyB, IppsBigNumState* pShare, IppsDLPState* pCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsDLPSharedSecretDH,
	(IPP_PROC)m7_ippsDLPSharedSecretDH,
	(IPP_PROC)n8_ippsDLPSharedSecretDH,
	(IPP_PROC)y8_ippsDLPSharedSecretDH,
	(IPP_PROC)e9_ippsDLPSharedSecretDH,
	(IPP_PROC)l9_ippsDLPSharedSecretDH,
	(IPP_PROC)n0_ippsDLPSharedSecretDH,
	(IPP_PROC)k0_ippsDLPSharedSecretDH,
	(IPP_PROC)k1_ippsDLPSharedSecretDH
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsDLPSharedSecretDH,(const IppsBigNumState* pPrvKeyA, const IppsBigNumState* pPubKeyB, IppsBigNumState* pShare, IppsDLPState* pCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsDLPSharedSecretDH,(const IppsBigNumState* pPrvKeyA, const IppsBigNumState* pPubKeyB, IppsBigNumState* pShare, IppsDLPState* pCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsDLPSharedSecretDH]
        jmp  rax
  }
};
