#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pPrvKey, IppsBigNumState* pPubKey, IppsDLPState* pCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsDLPPublicKey(const IppsBigNumState* pPrvKey, IppsBigNumState* pPubKey, IppsDLPState* pCtx);
extern IppStatus m7_ippsDLPPublicKey(const IppsBigNumState* pPrvKey, IppsBigNumState* pPubKey, IppsDLPState* pCtx);
extern IppStatus n8_ippsDLPPublicKey(const IppsBigNumState* pPrvKey, IppsBigNumState* pPubKey, IppsDLPState* pCtx);
extern IppStatus y8_ippsDLPPublicKey(const IppsBigNumState* pPrvKey, IppsBigNumState* pPubKey, IppsDLPState* pCtx);
extern IppStatus e9_ippsDLPPublicKey(const IppsBigNumState* pPrvKey, IppsBigNumState* pPubKey, IppsDLPState* pCtx);
extern IppStatus l9_ippsDLPPublicKey(const IppsBigNumState* pPrvKey, IppsBigNumState* pPubKey, IppsDLPState* pCtx);
extern IppStatus n0_ippsDLPPublicKey(const IppsBigNumState* pPrvKey, IppsBigNumState* pPubKey, IppsDLPState* pCtx);
extern IppStatus k0_ippsDLPPublicKey(const IppsBigNumState* pPrvKey, IppsBigNumState* pPubKey, IppsDLPState* pCtx);
extern IppStatus k1_ippsDLPPublicKey(const IppsBigNumState* pPrvKey, IppsBigNumState* pPubKey, IppsDLPState* pCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsDLPPublicKey,
	(IPP_PROC)m7_ippsDLPPublicKey,
	(IPP_PROC)n8_ippsDLPPublicKey,
	(IPP_PROC)y8_ippsDLPPublicKey,
	(IPP_PROC)e9_ippsDLPPublicKey,
	(IPP_PROC)l9_ippsDLPPublicKey,
	(IPP_PROC)n0_ippsDLPPublicKey,
	(IPP_PROC)k0_ippsDLPPublicKey,
	(IPP_PROC)k1_ippsDLPPublicKey
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsDLPPublicKey,(const IppsBigNumState* pPrvKey, IppsBigNumState* pPubKey, IppsDLPState* pCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsDLPPublicKey,(const IppsBigNumState* pPrvKey, IppsBigNumState* pPubKey, IppsDLPState* pCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsDLPPublicKey]
        jmp  rax
  }
};
