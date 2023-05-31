#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(int* pSize);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsARCFourGetSize(int* pSize);
extern IppStatus m7_ippsARCFourGetSize(int* pSize);
extern IppStatus n8_ippsARCFourGetSize(int* pSize);
extern IppStatus y8_ippsARCFourGetSize(int* pSize);
extern IppStatus e9_ippsARCFourGetSize(int* pSize);
extern IppStatus l9_ippsARCFourGetSize(int* pSize);
extern IppStatus n0_ippsARCFourGetSize(int* pSize);
extern IppStatus k0_ippsARCFourGetSize(int* pSize);
extern IppStatus k1_ippsARCFourGetSize(int* pSize);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsARCFourGetSize,
	(IPP_PROC)m7_ippsARCFourGetSize,
	(IPP_PROC)n8_ippsARCFourGetSize,
	(IPP_PROC)y8_ippsARCFourGetSize,
	(IPP_PROC)e9_ippsARCFourGetSize,
	(IPP_PROC)l9_ippsARCFourGetSize,
	(IPP_PROC)n0_ippsARCFourGetSize,
	(IPP_PROC)k0_ippsARCFourGetSize,
	(IPP_PROC)k1_ippsARCFourGetSize
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsARCFourGetSize,(int* pSize))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsARCFourGetSize,(int* pSize))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsARCFourGetSize]
        jmp  rax
  }
};
