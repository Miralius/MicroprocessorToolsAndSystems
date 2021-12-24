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

    for (int i = 0; i < MySize; i += 2) // СИшная команда выполняется в среднем за 6 300 000 тактов
        C[i / 2] = (A[i + 1] - B[i + 1]) * (A[i + 1] - B[i + 1]) + (A[i] - B[i]) * (A[i] - B[i]);

    NumEnd = __rdtsc();

    Num = NumEnd - NumStart;

    VirtualFree(A, 0, MEM_RELEASE);
    VirtualFree(B, 0, MEM_RELEASE);

    cout << "NumCycles: " << Num << endl;

    return 0;
}
