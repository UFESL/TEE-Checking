#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pSignR, const IppsBigNumState* pSignS, IppDLResult* pResult, IppsDLPState* pCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsDLPVerifyDSA(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pSignR, const IppsBigNumState* pSignS, IppDLResult* pResult, IppsDLPState* pCtx);
extern IppStatus m7_ippsDLPVerifyDSA(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pSignR, const IppsBigNumState* pSignS, IppDLResult* pResult, IppsDLPState* pCtx);
extern IppStatus n8_ippsDLPVerifyDSA(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pSignR, const IppsBigNumState* pSignS, IppDLResult* pResult, IppsDLPState* pCtx);
extern IppStatus y8_ippsDLPVerifyDSA(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pSignR, const IppsBigNumState* pSignS, IppDLResult* pResult, IppsDLPState* pCtx);
extern IppStatus e9_ippsDLPVerifyDSA(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pSignR, const IppsBigNumState* pSignS, IppDLResult* pResult, IppsDLPState* pCtx);
extern IppStatus l9_ippsDLPVerifyDSA(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pSignR, const IppsBigNumState* pSignS, IppDLResult* pResult, IppsDLPState* pCtx);
extern IppStatus n0_ippsDLPVerifyDSA(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pSignR, const IppsBigNumState* pSignS, IppDLResult* pResult, IppsDLPState* pCtx);
extern IppStatus k0_ippsDLPVerifyDSA(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pSignR, const IppsBigNumState* pSignS, IppDLResult* pResult, IppsDLPState* pCtx);
extern IppStatus k1_ippsDLPVerifyDSA(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pSignR, const IppsBigNumState* pSignS, IppDLResult* pResult, IppsDLPState* pCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsDLPVerifyDSA,
	(IPP_PROC)m7_ippsDLPVerifyDSA,
	(IPP_PROC)n8_ippsDLPVerifyDSA,
	(IPP_PROC)y8_ippsDLPVerifyDSA,
	(IPP_PROC)e9_ippsDLPVerifyDSA,
	(IPP_PROC)l9_ippsDLPVerifyDSA,
	(IPP_PROC)n0_ippsDLPVerifyDSA,
	(IPP_PROC)k0_ippsDLPVerifyDSA,
	(IPP_PROC)k1_ippsDLPVerifyDSA
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsDLPVerifyDSA,(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pSignR, const IppsBigNumState* pSignS, IppDLResult* pResult, IppsDLPState* pCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsDLPVerifyDSA,(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pSignR, const IppsBigNumState* pSignS, IppDLResult* pResult, IppsDLPState* pCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsDLPVerifyDSA]
        jmp  rax
  }
};
