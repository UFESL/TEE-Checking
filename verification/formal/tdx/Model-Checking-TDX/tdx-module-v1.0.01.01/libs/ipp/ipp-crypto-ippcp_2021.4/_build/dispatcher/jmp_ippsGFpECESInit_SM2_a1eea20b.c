#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(IppsGFpECState* pEC, IppsECESState_SM2* pState, int avaliableCtxSize);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpECESInit_SM2(IppsGFpECState* pEC, IppsECESState_SM2* pState, int avaliableCtxSize);
extern IppStatus m7_ippsGFpECESInit_SM2(IppsGFpECState* pEC, IppsECESState_SM2* pState, int avaliableCtxSize);
extern IppStatus n8_ippsGFpECESInit_SM2(IppsGFpECState* pEC, IppsECESState_SM2* pState, int avaliableCtxSize);
extern IppStatus y8_ippsGFpECESInit_SM2(IppsGFpECState* pEC, IppsECESState_SM2* pState, int avaliableCtxSize);
extern IppStatus e9_ippsGFpECESInit_SM2(IppsGFpECState* pEC, IppsECESState_SM2* pState, int avaliableCtxSize);
extern IppStatus l9_ippsGFpECESInit_SM2(IppsGFpECState* pEC, IppsECESState_SM2* pState, int avaliableCtxSize);
extern IppStatus n0_ippsGFpECESInit_SM2(IppsGFpECState* pEC, IppsECESState_SM2* pState, int avaliableCtxSize);
extern IppStatus k0_ippsGFpECESInit_SM2(IppsGFpECState* pEC, IppsECESState_SM2* pState, int avaliableCtxSize);
extern IppStatus k1_ippsGFpECESInit_SM2(IppsGFpECState* pEC, IppsECESState_SM2* pState, int avaliableCtxSize);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpECESInit_SM2,
	(IPP_PROC)m7_ippsGFpECESInit_SM2,
	(IPP_PROC)n8_ippsGFpECESInit_SM2,
	(IPP_PROC)y8_ippsGFpECESInit_SM2,
	(IPP_PROC)e9_ippsGFpECESInit_SM2,
	(IPP_PROC)l9_ippsGFpECESInit_SM2,
	(IPP_PROC)n0_ippsGFpECESInit_SM2,
	(IPP_PROC)k0_ippsGFpECESInit_SM2,
	(IPP_PROC)k1_ippsGFpECESInit_SM2
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpECESInit_SM2,(IppsGFpECState* pEC, IppsECESState_SM2* pState, int avaliableCtxSize))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpECESInit_SM2,(IppsGFpECState* pEC, IppsECESState_SM2* pState, int avaliableCtxSize))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpECESInit_SM2]
        jmp  rax
  }
};
