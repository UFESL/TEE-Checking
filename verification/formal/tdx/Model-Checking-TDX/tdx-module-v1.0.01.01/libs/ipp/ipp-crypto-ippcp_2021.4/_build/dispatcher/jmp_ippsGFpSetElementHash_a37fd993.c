#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pMsg, int msgLen, IppsGFpElement* pElm, IppsGFpState* pGFp, IppHashAlgId hashID);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpSetElementHash(const Ipp8u* pMsg, int msgLen, IppsGFpElement* pElm, IppsGFpState* pGFp, IppHashAlgId hashID);
extern IppStatus m7_ippsGFpSetElementHash(const Ipp8u* pMsg, int msgLen, IppsGFpElement* pElm, IppsGFpState* pGFp, IppHashAlgId hashID);
extern IppStatus n8_ippsGFpSetElementHash(const Ipp8u* pMsg, int msgLen, IppsGFpElement* pElm, IppsGFpState* pGFp, IppHashAlgId hashID);
extern IppStatus y8_ippsGFpSetElementHash(const Ipp8u* pMsg, int msgLen, IppsGFpElement* pElm, IppsGFpState* pGFp, IppHashAlgId hashID);
extern IppStatus e9_ippsGFpSetElementHash(const Ipp8u* pMsg, int msgLen, IppsGFpElement* pElm, IppsGFpState* pGFp, IppHashAlgId hashID);
extern IppStatus l9_ippsGFpSetElementHash(const Ipp8u* pMsg, int msgLen, IppsGFpElement* pElm, IppsGFpState* pGFp, IppHashAlgId hashID);
extern IppStatus n0_ippsGFpSetElementHash(const Ipp8u* pMsg, int msgLen, IppsGFpElement* pElm, IppsGFpState* pGFp, IppHashAlgId hashID);
extern IppStatus k0_ippsGFpSetElementHash(const Ipp8u* pMsg, int msgLen, IppsGFpElement* pElm, IppsGFpState* pGFp, IppHashAlgId hashID);
extern IppStatus k1_ippsGFpSetElementHash(const Ipp8u* pMsg, int msgLen, IppsGFpElement* pElm, IppsGFpState* pGFp, IppHashAlgId hashID);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpSetElementHash,
	(IPP_PROC)m7_ippsGFpSetElementHash,
	(IPP_PROC)n8_ippsGFpSetElementHash,
	(IPP_PROC)y8_ippsGFpSetElementHash,
	(IPP_PROC)e9_ippsGFpSetElementHash,
	(IPP_PROC)l9_ippsGFpSetElementHash,
	(IPP_PROC)n0_ippsGFpSetElementHash,
	(IPP_PROC)k0_ippsGFpSetElementHash,
	(IPP_PROC)k1_ippsGFpSetElementHash
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpSetElementHash,(const Ipp8u* pMsg, int msgLen, IppsGFpElement* pElm, IppsGFpState* pGFp, IppHashAlgId hashID))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpSetElementHash,(const Ipp8u* pMsg, int msgLen, IppsGFpElement* pElm, IppsGFpState* pGFp, IppHashAlgId hashID))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpSetElementHash]
        jmp  rax
  }
};
