#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(IppsBigNumState* pPrvKey, IppsBigNumState* pPubKey, IppsDLPState* pCtx, IppBitSupplier rndFunc, void* pRndParam);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsDLPGenKeyPair(IppsBigNumState* pPrvKey, IppsBigNumState* pPubKey, IppsDLPState* pCtx, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus m7_ippsDLPGenKeyPair(IppsBigNumState* pPrvKey, IppsBigNumState* pPubKey, IppsDLPState* pCtx, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus n8_ippsDLPGenKeyPair(IppsBigNumState* pPrvKey, IppsBigNumState* pPubKey, IppsDLPState* pCtx, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus y8_ippsDLPGenKeyPair(IppsBigNumState* pPrvKey, IppsBigNumState* pPubKey, IppsDLPState* pCtx, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus e9_ippsDLPGenKeyPair(IppsBigNumState* pPrvKey, IppsBigNumState* pPubKey, IppsDLPState* pCtx, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus l9_ippsDLPGenKeyPair(IppsBigNumState* pPrvKey, IppsBigNumState* pPubKey, IppsDLPState* pCtx, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus n0_ippsDLPGenKeyPair(IppsBigNumState* pPrvKey, IppsBigNumState* pPubKey, IppsDLPState* pCtx, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus k0_ippsDLPGenKeyPair(IppsBigNumState* pPrvKey, IppsBigNumState* pPubKey, IppsDLPState* pCtx, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus k1_ippsDLPGenKeyPair(IppsBigNumState* pPrvKey, IppsBigNumState* pPubKey, IppsDLPState* pCtx, IppBitSupplier rndFunc, void* pRndParam);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsDLPGenKeyPair,
	(IPP_PROC)m7_ippsDLPGenKeyPair,
	(IPP_PROC)n8_ippsDLPGenKeyPair,
	(IPP_PROC)y8_ippsDLPGenKeyPair,
	(IPP_PROC)e9_ippsDLPGenKeyPair,
	(IPP_PROC)l9_ippsDLPGenKeyPair,
	(IPP_PROC)n0_ippsDLPGenKeyPair,
	(IPP_PROC)k0_ippsDLPGenKeyPair,
	(IPP_PROC)k1_ippsDLPGenKeyPair
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsDLPGenKeyPair,(IppsBigNumState* pPrvKey, IppsBigNumState* pPubKey, IppsDLPState* pCtx, IppBitSupplier rndFunc, void* pRndParam))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsDLPGenKeyPair,(IppsBigNumState* pPrvKey, IppsBigNumState* pPubKey, IppsDLPState* pCtx, IppBitSupplier rndFunc, void* pRndParam))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsDLPGenKeyPair]
        jmp  rax
  }
};
