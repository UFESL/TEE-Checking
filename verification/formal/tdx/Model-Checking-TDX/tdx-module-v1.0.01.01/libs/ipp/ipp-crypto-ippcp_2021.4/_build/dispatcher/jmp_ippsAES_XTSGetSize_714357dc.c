#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(int * pSize);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsAES_XTSGetSize(int * pSize);
extern IppStatus m7_ippsAES_XTSGetSize(int * pSize);
extern IppStatus n8_ippsAES_XTSGetSize(int * pSize);
extern IppStatus y8_ippsAES_XTSGetSize(int * pSize);
extern IppStatus e9_ippsAES_XTSGetSize(int * pSize);
extern IppStatus l9_ippsAES_XTSGetSize(int * pSize);
extern IppStatus n0_ippsAES_XTSGetSize(int * pSize);
extern IppStatus k0_ippsAES_XTSGetSize(int * pSize);
extern IppStatus k1_ippsAES_XTSGetSize(int * pSize);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsAES_XTSGetSize,
	(IPP_PROC)m7_ippsAES_XTSGetSize,
	(IPP_PROC)n8_ippsAES_XTSGetSize,
	(IPP_PROC)y8_ippsAES_XTSGetSize,
	(IPP_PROC)e9_ippsAES_XTSGetSize,
	(IPP_PROC)l9_ippsAES_XTSGetSize,
	(IPP_PROC)n0_ippsAES_XTSGetSize,
	(IPP_PROC)k0_ippsAES_XTSGetSize,
	(IPP_PROC)k1_ippsAES_XTSGetSize
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsAES_XTSGetSize,(int * pSize))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsAES_XTSGetSize,(int * pSize))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsAES_XTSGetSize]
        jmp  rax
  }
};
