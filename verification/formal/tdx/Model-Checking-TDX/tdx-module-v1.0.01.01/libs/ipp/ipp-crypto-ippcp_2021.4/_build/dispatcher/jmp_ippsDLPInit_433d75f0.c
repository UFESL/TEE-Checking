#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(int bitSizeP, int bitSizeR, IppsDLPState* pCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsDLPInit(int bitSizeP, int bitSizeR, IppsDLPState* pCtx);
extern IppStatus m7_ippsDLPInit(int bitSizeP, int bitSizeR, IppsDLPState* pCtx);
extern IppStatus n8_ippsDLPInit(int bitSizeP, int bitSizeR, IppsDLPState* pCtx);
extern IppStatus y8_ippsDLPInit(int bitSizeP, int bitSizeR, IppsDLPState* pCtx);
extern IppStatus e9_ippsDLPInit(int bitSizeP, int bitSizeR, IppsDLPState* pCtx);
extern IppStatus l9_ippsDLPInit(int bitSizeP, int bitSizeR, IppsDLPState* pCtx);
extern IppStatus n0_ippsDLPInit(int bitSizeP, int bitSizeR, IppsDLPState* pCtx);
extern IppStatus k0_ippsDLPInit(int bitSizeP, int bitSizeR, IppsDLPState* pCtx);
extern IppStatus k1_ippsDLPInit(int bitSizeP, int bitSizeR, IppsDLPState* pCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsDLPInit,
	(IPP_PROC)m7_ippsDLPInit,
	(IPP_PROC)n8_ippsDLPInit,
	(IPP_PROC)y8_ippsDLPInit,
	(IPP_PROC)e9_ippsDLPInit,
	(IPP_PROC)l9_ippsDLPInit,
	(IPP_PROC)n0_ippsDLPInit,
	(IPP_PROC)k0_ippsDLPInit,
	(IPP_PROC)k1_ippsDLPInit
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsDLPInit,(int bitSizeP, int bitSizeR, IppsDLPState* pCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsDLPInit,(int bitSizeP, int bitSizeR, IppsDLPState* pCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsDLPInit]
        jmp  rax
  }
};
