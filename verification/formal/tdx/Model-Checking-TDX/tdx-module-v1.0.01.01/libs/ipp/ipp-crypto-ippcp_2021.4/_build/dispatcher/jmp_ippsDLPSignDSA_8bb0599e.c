#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pPrvKey, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsDLPState* pCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsDLPSignDSA(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pPrvKey, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsDLPState* pCtx);
extern IppStatus m7_ippsDLPSignDSA(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pPrvKey, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsDLPState* pCtx);
extern IppStatus n8_ippsDLPSignDSA(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pPrvKey, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsDLPState* pCtx);
extern IppStatus y8_ippsDLPSignDSA(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pPrvKey, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsDLPState* pCtx);
extern IppStatus e9_ippsDLPSignDSA(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pPrvKey, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsDLPState* pCtx);
extern IppStatus l9_ippsDLPSignDSA(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pPrvKey, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsDLPState* pCtx);
extern IppStatus n0_ippsDLPSignDSA(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pPrvKey, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsDLPState* pCtx);
extern IppStatus k0_ippsDLPSignDSA(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pPrvKey, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsDLPState* pCtx);
extern IppStatus k1_ippsDLPSignDSA(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pPrvKey, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsDLPState* pCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsDLPSignDSA,
	(IPP_PROC)m7_ippsDLPSignDSA,
	(IPP_PROC)n8_ippsDLPSignDSA,
	(IPP_PROC)y8_ippsDLPSignDSA,
	(IPP_PROC)e9_ippsDLPSignDSA,
	(IPP_PROC)l9_ippsDLPSignDSA,
	(IPP_PROC)n0_ippsDLPSignDSA,
	(IPP_PROC)k0_ippsDLPSignDSA,
	(IPP_PROC)k1_ippsDLPSignDSA
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsDLPSignDSA,(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pPrvKey, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsDLPState* pCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsDLPSignDSA,(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pPrvKey, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsDLPState* pCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsDLPSignDSA]
        jmp  rax
  }
};
