#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef  const IppLibraryVersion* (*IPP_PROC)(void);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern  const IppLibraryVersion* in_ippcpGetLibVersion(void);
extern  const IppLibraryVersion* m7_ippcpGetLibVersion(void);
extern  const IppLibraryVersion* n8_ippcpGetLibVersion(void);
extern  const IppLibraryVersion* y8_ippcpGetLibVersion(void);
extern  const IppLibraryVersion* e9_ippcpGetLibVersion(void);
extern  const IppLibraryVersion* l9_ippcpGetLibVersion(void);
extern  const IppLibraryVersion* n0_ippcpGetLibVersion(void);
extern  const IppLibraryVersion* k0_ippcpGetLibVersion(void);
extern  const IppLibraryVersion* k1_ippcpGetLibVersion(void);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippcpGetLibVersion,
	(IPP_PROC)m7_ippcpGetLibVersion,
	(IPP_PROC)n8_ippcpGetLibVersion,
	(IPP_PROC)y8_ippcpGetLibVersion,
	(IPP_PROC)e9_ippcpGetLibVersion,
	(IPP_PROC)l9_ippcpGetLibVersion,
	(IPP_PROC)n0_ippcpGetLibVersion,
	(IPP_PROC)k0_ippcpGetLibVersion,
	(IPP_PROC)k1_ippcpGetLibVersion
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI( const IppLibraryVersion*, ippcpGetLibVersion,(void))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI( const IppLibraryVersion*, in_ippcpGetLibVersion,(void))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippcpGetLibVersion]
        jmp  rax
  }
};
