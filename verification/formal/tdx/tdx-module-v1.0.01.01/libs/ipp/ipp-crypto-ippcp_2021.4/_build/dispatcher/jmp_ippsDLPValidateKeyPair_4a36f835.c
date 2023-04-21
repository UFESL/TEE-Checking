#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pPrvKey, const IppsBigNumState* pPubKey, IppDLResult* pResult, IppsDLPState* pCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsDLPValidateKeyPair(const IppsBigNumState* pPrvKey, const IppsBigNumState* pPubKey, IppDLResult* pResult, IppsDLPState* pCtx);
extern IppStatus m7_ippsDLPValidateKeyPair(const IppsBigNumState* pPrvKey, const IppsBigNumState* pPubKey, IppDLResult* pResult, IppsDLPState* pCtx);
extern IppStatus n8_ippsDLPValidateKeyPair(const IppsBigNumState* pPrvKey, const IppsBigNumState* pPubKey, IppDLResult* pResult, IppsDLPState* pCtx);
extern IppStatus y8_ippsDLPValidateKeyPair(const IppsBigNumState* pPrvKey, const IppsBigNumState* pPubKey, IppDLResult* pResult, IppsDLPState* pCtx);
extern IppStatus e9_ippsDLPValidateKeyPair(const IppsBigNumState* pPrvKey, const IppsBigNumState* pPubKey, IppDLResult* pResult, IppsDLPState* pCtx);
extern IppStatus l9_ippsDLPValidateKeyPair(const IppsBigNumState* pPrvKey, const IppsBigNumState* pPubKey, IppDLResult* pResult, IppsDLPState* pCtx);
extern IppStatus n0_ippsDLPValidateKeyPair(const IppsBigNumState* pPrvKey, const IppsBigNumState* pPubKey, IppDLResult* pResult, IppsDLPState* pCtx);
extern IppStatus k0_ippsDLPValidateKeyPair(const IppsBigNumState* pPrvKey, const IppsBigNumState* pPubKey, IppDLResult* pResult, IppsDLPState* pCtx);
extern IppStatus k1_ippsDLPValidateKeyPair(const IppsBigNumState* pPrvKey, const IppsBigNumState* pPubKey, IppDLResult* pResult, IppsDLPState* pCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsDLPValidateKeyPair,
	(IPP_PROC)m7_ippsDLPValidateKeyPair,
	(IPP_PROC)n8_ippsDLPValidateKeyPair,
	(IPP_PROC)y8_ippsDLPValidateKeyPair,
	(IPP_PROC)e9_ippsDLPValidateKeyPair,
	(IPP_PROC)l9_ippsDLPValidateKeyPair,
	(IPP_PROC)n0_ippsDLPValidateKeyPair,
	(IPP_PROC)k0_ippsDLPValidateKeyPair,
	(IPP_PROC)k1_ippsDLPValidateKeyPair
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsDLPValidateKeyPair,(const IppsBigNumState* pPrvKey, const IppsBigNumState* pPubKey, IppDLResult* pResult, IppsDLPState* pCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsDLPValidateKeyPair,(const IppsBigNumState* pPrvKey, const IppsBigNumState* pPubKey, IppDLResult* pResult, IppsDLPState* pCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsDLPValidateKeyPair]
        jmp  rax
  }
};
