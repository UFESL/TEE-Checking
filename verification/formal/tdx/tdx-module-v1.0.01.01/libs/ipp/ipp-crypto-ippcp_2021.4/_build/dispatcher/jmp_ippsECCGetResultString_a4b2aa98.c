#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef  const char* (*IPP_PROC)(IppECResult code);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern  const char* in_ippsECCGetResultString(IppECResult code);
extern  const char* m7_ippsECCGetResultString(IppECResult code);
extern  const char* n8_ippsECCGetResultString(IppECResult code);
extern  const char* y8_ippsECCGetResultString(IppECResult code);
extern  const char* e9_ippsECCGetResultString(IppECResult code);
extern  const char* l9_ippsECCGetResultString(IppECResult code);
extern  const char* n0_ippsECCGetResultString(IppECResult code);
extern  const char* k0_ippsECCGetResultString(IppECResult code);
extern  const char* k1_ippsECCGetResultString(IppECResult code);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsECCGetResultString,
	(IPP_PROC)m7_ippsECCGetResultString,
	(IPP_PROC)n8_ippsECCGetResultString,
	(IPP_PROC)y8_ippsECCGetResultString,
	(IPP_PROC)e9_ippsECCGetResultString,
	(IPP_PROC)l9_ippsECCGetResultString,
	(IPP_PROC)n0_ippsECCGetResultString,
	(IPP_PROC)k0_ippsECCGetResultString,
	(IPP_PROC)k1_ippsECCGetResultString
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI( const char*, ippsECCGetResultString,(IppECResult code))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI( const char*, in_ippsECCGetResultString,(IppECResult code))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsECCGetResultString]
        jmp  rax
  }
};
