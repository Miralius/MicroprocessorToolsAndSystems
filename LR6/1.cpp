#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
extern "C" int Funct(char* In, int length, char* Out);
int main()
{ //согласно MSDN, в NTFS такие ограничения на размер пути и размер имени файла
    char In[32768], Out[256];
    cout << "Input full path: "; 
    cin.getline(In, 32768, '\n');
    Funct(In, strlen(In), Out);
    cout << Out;
    return 0;
}
