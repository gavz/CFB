#include "Utils.h"


/*++

--*/
VOID CfbDbgPrint(const WCHAR* lpFormatString, ...)
{
#ifdef _DEBUG
	va_list args;
	WCHAR buffer[1024] = { 0, };
	va_start(args, lpFormatString);
	vswprintf_s(buffer, sizeof(buffer) / sizeof(WCHAR), lpFormatString, args);
	va_end(args);

	// todo add timestamp
	KdPrint(("[CFB] %S", buffer));
#endif
}


/*++

Simplified version of the one in common\.

--*/
VOID CfbHexDump(UCHAR *Buffer, ULONG Length)
{
	for (ULONG i = 0; i < Length; i++)
	{
		if(i%16==0)	KdPrint(("\n"));
		KdPrint(("%02x ", Buffer[i]));
	}
	KdPrint(("\n"));
}