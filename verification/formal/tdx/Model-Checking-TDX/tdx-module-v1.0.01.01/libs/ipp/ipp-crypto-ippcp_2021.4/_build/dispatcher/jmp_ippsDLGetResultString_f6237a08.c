#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef  const char* (*IPP_PROC)(IppDLResult code);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern  const char* in_ippsDLGetResultString(IppDLResult code);
extern  const char* m7_ippsDLGetResultString(IppDLResult code);
extern  const char* n8_ippsDLGetResultString(IppDLResult code);
extern  const char* y8_ippsDLGetResultString(IppDLResult code);
extern  const char* e9_ippsDLGetResultString(IppDLResult code);
extern  const char* l9_ippsDLGetResultString(IppDLResult code);
extern  const char* n0_ippsDLGetResultString(IppDLResult code);
extern  const char* k0_ippsDLGetResultString(IppDLResult code);
extern  const char* k1_ippsDLGetResultString(IppDLResult code);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsDLGetResultString,
	(IPP_PROC)m7_ippsDLGetResultString,
	(IPP_PROC)n8_ippsDLGetResultString,
	(IPP_PROC)y8_ippsDLGetResultString,
	(IPP_PROC)e9_ippsDLGetResultString,
	(IPP_PROC)l9_ippsDLGetResultString,
	(IPP_PROC)n0_ippsDLGetResultString,
	(IPP_PROC)k0_ippsDLGetResultString,
	(IPP_PROC)k1_ippsDLGetResultString
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI( const char*, ippsDLGetResultString,(IppDLResult code))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI( const char*, in_ippsDLGetResultString,(IppDLResult code))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsDLGetResultString]
        jmp  rax
  }
};
