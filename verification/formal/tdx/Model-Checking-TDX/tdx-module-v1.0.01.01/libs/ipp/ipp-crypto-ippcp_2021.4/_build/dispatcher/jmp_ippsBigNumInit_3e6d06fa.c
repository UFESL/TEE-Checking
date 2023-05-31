#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(int length, IppsBigNumState* pBN);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsBigNumInit(int length, IppsBigNumState* pBN);
extern IppStatus m7_ippsBigNumInit(int length, IppsBigNumState* pBN);
extern IppStatus n8_ippsBigNumInit(int length, IppsBigNumState* pBN);
extern IppStatus y8_ippsBigNumInit(int length, IppsBigNumState* pBN);
extern IppStatus e9_ippsBigNumInit(int length, IppsBigNumState* pBN);
extern IppStatus l9_ippsBigNumInit(int length, IppsBigNumState* pBN);
extern IppStatus n0_ippsBigNumInit(int length, IppsBigNumState* pBN);
extern IppStatus k0_ippsBigNumInit(int length, IppsBigNumState* pBN);
extern IppStatus k1_ippsBigNumInit(int length, IppsBigNumState* pBN);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsBigNumInit,
	(IPP_PROC)m7_ippsBigNumInit,
	(IPP_PROC)n8_ippsBigNumInit,
	(IPP_PROC)y8_ippsBigNumInit,
	(IPP_PROC)e9_ippsBigNumInit,
	(IPP_PROC)l9_ippsBigNumInit,
	(IPP_PROC)n0_ippsBigNumInit,
	(IPP_PROC)k0_ippsBigNumInit,
	(IPP_PROC)k1_ippsBigNumInit
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsBigNumInit,(int length, IppsBigNumState* pBN))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsBigNumInit,(int length, IppsBigNumState* pBN))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsBigNumInit]
        jmp  rax
  }
};
