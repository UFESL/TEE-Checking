#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pPrvKey, const IppsBigNumState* pPubKey, IppsDLPState* pCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsDLPSetKeyPair(const IppsBigNumState* pPrvKey, const IppsBigNumState* pPubKey, IppsDLPState* pCtx);
extern IppStatus m7_ippsDLPSetKeyPair(const IppsBigNumState* pPrvKey, const IppsBigNumState* pPubKey, IppsDLPState* pCtx);
extern IppStatus n8_ippsDLPSetKeyPair(const IppsBigNumState* pPrvKey, const IppsBigNumState* pPubKey, IppsDLPState* pCtx);
extern IppStatus y8_ippsDLPSetKeyPair(const IppsBigNumState* pPrvKey, const IppsBigNumState* pPubKey, IppsDLPState* pCtx);
extern IppStatus e9_ippsDLPSetKeyPair(const IppsBigNumState* pPrvKey, const IppsBigNumState* pPubKey, IppsDLPState* pCtx);
extern IppStatus l9_ippsDLPSetKeyPair(const IppsBigNumState* pPrvKey, const IppsBigNumState* pPubKey, IppsDLPState* pCtx);
extern IppStatus n0_ippsDLPSetKeyPair(const IppsBigNumState* pPrvKey, const IppsBigNumState* pPubKey, IppsDLPState* pCtx);
extern IppStatus k0_ippsDLPSetKeyPair(const IppsBigNumState* pPrvKey, const IppsBigNumState* pPubKey, IppsDLPState* pCtx);
extern IppStatus k1_ippsDLPSetKeyPair(const IppsBigNumState* pPrvKey, const IppsBigNumState* pPubKey, IppsDLPState* pCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsDLPSetKeyPair,
	(IPP_PROC)m7_ippsDLPSetKeyPair,
	(IPP_PROC)n8_ippsDLPSetKeyPair,
	(IPP_PROC)y8_ippsDLPSetKeyPair,
	(IPP_PROC)e9_ippsDLPSetKeyPair,
	(IPP_PROC)l9_ippsDLPSetKeyPair,
	(IPP_PROC)n0_ippsDLPSetKeyPair,
	(IPP_PROC)k0_ippsDLPSetKeyPair,
	(IPP_PROC)k1_ippsDLPSetKeyPair
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsDLPSetKeyPair,(const IppsBigNumState* pPrvKey, const IppsBigNumState* pPubKey, IppsDLPState* pCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsDLPSetKeyPair,(const IppsBigNumState* pPrvKey, const IppsBigNumState* pPubKey, IppsDLPState* pCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsDLPSetKeyPair]
        jmp  rax
  }
};
