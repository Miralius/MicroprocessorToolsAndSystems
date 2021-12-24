#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NON_CONFORMING_SWPRINTFS
#include <iostream>
#include <intrin.h>
#include <Windows.h>

using namespace std;

int main()
{
    int CpuInfo[4] = { 0,0,0,0 };
    __cpuid(CpuInfo, 1);

    __int64 Num, NumStart, NumEnd;

    DWORD* A, * B; 
    int *C;
    int MySize = 1024 * 1024; //10 Mbytes
    A = (DWORD*)VirtualAlloc(NULL, MySize * sizeof(DWORD), MEM_COMMIT, PAGE_READWRITE);
    B = (DWORD*)VirtualAlloc(NULL, MySize * sizeof(DWORD), MEM_COMMIT, PAGE_READWRITE);
    C = (int*)VirtualAlloc(NULL, MySize / 2 * sizeof(int), MEM_COMMIT, PAGE_READWRITE);

    if ((A == NULL) || (B == NULL) || (C == NULL) /*|| (D == NULL)*/)
        MessageBox(NULL, L"Memory Allocation Error", L"TEST", MB_OK);
    for (int i = 0; i < MySize; i += 2)
    {
        A[i] = (short int)2*i;	//x
        B[i] = (short int)i;   //y
        A[i + 1] = (short int)2*i;	//x
        B[i + 1] = (short int)i;	//y
    }

    NumStart = __rdtsc();

    MySize = MySize / 4;
    __asm
    {
        mov ECX, MySize;
        mov ESI, A
        mov EDI, B
        mov EDX, C
        xor EBX, EBX
        LPP : movq MM0, [ESI + EBX]
        psubw MM0, [EDI + EBX]
        pmaddwd MM0, MM0
        movq[EDX + EBX], MM0
        add EBX, 8
        loop LPP
	}

    NumEnd = __rdtsc();

    Num = NumEnd - NumStart;

    VirtualFree(A, 0, MEM_RELEASE);
    VirtualFree(B, 0, MEM_RELEASE);

    cout << "NumCycles: " << Num << endl;

    return 0;
}
