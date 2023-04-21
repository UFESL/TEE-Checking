#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(IppsExpMethod method, int length, IppsMontState* pCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsMontInit(IppsExpMethod method, int length, IppsMontState* pCtx);
extern IppStatus m7_ippsMontInit(IppsExpMethod method, int length, IppsMontState* pCtx);
extern IppStatus n8_ippsMontInit(IppsExpMethod method, int length, IppsMontState* pCtx);
extern IppStatus y8_ippsMontInit(IppsExpMethod method, int length, IppsMontState* pCtx);
extern IppStatus e9_ippsMontInit(IppsExpMethod method, int length, IppsMontState* pCtx);
extern IppStatus l9_ippsMontInit(IppsExpMethod method, int length, IppsMontState* pCtx);
extern IppStatus n0_ippsMontInit(IppsExpMethod method, int length, IppsMontState* pCtx);
extern IppStatus k0_ippsMontInit(IppsExpMethod method, int length, IppsMontState* pCtx);
extern IppStatus k1_ippsMontInit(IppsExpMethod method, int length, IppsMontState* pCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsMontInit,
	(IPP_PROC)m7_ippsMontInit,
	(IPP_PROC)n8_ippsMontInit,
	(IPP_PROC)y8_ippsMontInit,
	(IPP_PROC)e9_ippsMontInit,
	(IPP_PROC)l9_ippsMontInit,
	(IPP_PROC)n0_ippsMontInit,
	(IPP_PROC)k0_ippsMontInit,
	(IPP_PROC)k1_ippsMontInit
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsMontInit,(IppsExpMethod method, int length, IppsMontState* pCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsMontInit,(IppsExpMethod method, int length, IppsMontState* pCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsMontInit]
        jmp  rax
  }
};
