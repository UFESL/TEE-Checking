#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(int length, int* pSize);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsBigNumGetSize(int length, int* pSize);
extern IppStatus m7_ippsBigNumGetSize(int length, int* pSize);
extern IppStatus n8_ippsBigNumGetSize(int length, int* pSize);
extern IppStatus y8_ippsBigNumGetSize(int length, int* pSize);
extern IppStatus e9_ippsBigNumGetSize(int length, int* pSize);
extern IppStatus l9_ippsBigNumGetSize(int length, int* pSize);
extern IppStatus n0_ippsBigNumGetSize(int length, int* pSize);
extern IppStatus k0_ippsBigNumGetSize(int length, int* pSize);
extern IppStatus k1_ippsBigNumGetSize(int length, int* pSize);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsBigNumGetSize,
	(IPP_PROC)m7_ippsBigNumGetSize,
	(IPP_PROC)n8_ippsBigNumGetSize,
	(IPP_PROC)y8_ippsBigNumGetSize,
	(IPP_PROC)e9_ippsBigNumGetSize,
	(IPP_PROC)l9_ippsBigNumGetSize,
	(IPP_PROC)n0_ippsBigNumGetSize,
	(IPP_PROC)k0_ippsBigNumGetSize,
	(IPP_PROC)k1_ippsBigNumGetSize
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsBigNumGetSize,(int length, int* pSize))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsBigNumGetSize,(int length, int* pSize))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsBigNumGetSize]
        jmp  rax
  }
};
