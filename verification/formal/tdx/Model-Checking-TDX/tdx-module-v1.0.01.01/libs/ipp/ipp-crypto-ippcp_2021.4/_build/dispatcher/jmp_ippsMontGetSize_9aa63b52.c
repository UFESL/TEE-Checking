#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(IppsExpMethod method, int length, int* pSize);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsMontGetSize(IppsExpMethod method, int length, int* pSize);
extern IppStatus m7_ippsMontGetSize(IppsExpMethod method, int length, int* pSize);
extern IppStatus n8_ippsMontGetSize(IppsExpMethod method, int length, int* pSize);
extern IppStatus y8_ippsMontGetSize(IppsExpMethod method, int length, int* pSize);
extern IppStatus e9_ippsMontGetSize(IppsExpMethod method, int length, int* pSize);
extern IppStatus l9_ippsMontGetSize(IppsExpMethod method, int length, int* pSize);
extern IppStatus n0_ippsMontGetSize(IppsExpMethod method, int length, int* pSize);
extern IppStatus k0_ippsMontGetSize(IppsExpMethod method, int length, int* pSize);
extern IppStatus k1_ippsMontGetSize(IppsExpMethod method, int length, int* pSize);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsMontGetSize,
	(IPP_PROC)m7_ippsMontGetSize,
	(IPP_PROC)n8_ippsMontGetSize,
	(IPP_PROC)y8_ippsMontGetSize,
	(IPP_PROC)e9_ippsMontGetSize,
	(IPP_PROC)l9_ippsMontGetSize,
	(IPP_PROC)n0_ippsMontGetSize,
	(IPP_PROC)k0_ippsMontGetSize,
	(IPP_PROC)k1_ippsMontGetSize
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsMontGetSize,(IppsExpMethod method, int length, int* pSize))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsMontGetSize,(IppsExpMethod method, int length, int* pSize))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsMontGetSize]
        jmp  rax
  }
};
