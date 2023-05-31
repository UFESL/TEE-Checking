#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(int *pSize);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsAESGetSize(int *pSize);
extern IppStatus m7_ippsAESGetSize(int *pSize);
extern IppStatus n8_ippsAESGetSize(int *pSize);
extern IppStatus y8_ippsAESGetSize(int *pSize);
extern IppStatus e9_ippsAESGetSize(int *pSize);
extern IppStatus l9_ippsAESGetSize(int *pSize);
extern IppStatus n0_ippsAESGetSize(int *pSize);
extern IppStatus k0_ippsAESGetSize(int *pSize);
extern IppStatus k1_ippsAESGetSize(int *pSize);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsAESGetSize,
	(IPP_PROC)m7_ippsAESGetSize,
	(IPP_PROC)n8_ippsAESGetSize,
	(IPP_PROC)y8_ippsAESGetSize,
	(IPP_PROC)e9_ippsAESGetSize,
	(IPP_PROC)l9_ippsAESGetSize,
	(IPP_PROC)n0_ippsAESGetSize,
	(IPP_PROC)k0_ippsAESGetSize,
	(IPP_PROC)k1_ippsAESGetSize
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsAESGetSize,(int *pSize))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsAESGetSize,(int *pSize))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsAESGetSize]
        jmp  rax
  }
};
