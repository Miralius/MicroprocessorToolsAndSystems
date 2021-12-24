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

    DWORD *A, *B;
    int MySize = 1024 * 1024; //10 Mbytes
    A = (DWORD*)VirtualAlloc(NULL, MySize * sizeof(DWORD), MEM_COMMIT, PAGE_READWRITE);
    B = (DWORD*)VirtualAlloc(NULL, MySize * sizeof(DWORD), MEM_COMMIT, PAGE_READWRITE);

    if ((A == NULL) || (B == NULL)) {
        cout << "Memory Allocation Error";
        return 1;
    }

    for (int i = 0; i < MySize; i++)
    {
        A[i] = i;
        B[i] = i + 5;
    }
    
    NumStart = __rdtsc();

	MySize /= 2;
    __asm
        {
            mov ECX, MySize;
            mov ESI, A
                mov EDI, B
                xor EBX, EBX
                LPP : movq MM0, [ESI + EBX]
                paddd MM0, [EDI + EBX]
                movq [EDI + EBX], MM0
                add EBX, 8
                loop LPP
        } //а этот в два раза быстрее — 2 млн тактов

    NumEnd = __rdtsc();

    Num = NumEnd - NumStart;

    bool FLAG = TRUE;
    for (int i = 0; i < MySize; i++)
        if ((B[i] - A[i]) != (i + 5)) FLAG = FALSE;

    VirtualFree(A, 0, MEM_RELEASE);
    VirtualFree(B, 0, MEM_RELEASE);

    if (FLAG) cout << "CORRECT : NumCycles: " << Num << endl; else cout << "INCORRECT : NumCycles: " << Num << endl;

    return 0;
}
