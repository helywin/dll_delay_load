//
// Created by helywin on 2020/7/1.
//

#include "MyDll.hpp"
#include <windows.h>
#include <windef.h>
#include <iostream>

using namespace std;

BOOL APIENTRY DllMain(HMODULE hModule,
                      DWORD ul_reason_for_call,
                      LPVOID lpReserved
)
{
    switch (ul_reason_for_call) {
        case DLL_PROCESS_ATTACH:
            cout << "MyDll DLL_PROCESS_ATTACH" << endl;
            break;
        case DLL_THREAD_ATTACH:
            cout << "MyDll DLL_THREAD_ATTACH" << endl;
            break;
        case DLL_THREAD_DETACH:
            cout << "MyDll DLL_THREAD_DETACH" << endl;
            break;
        case DLL_PROCESS_DETACH:
            cout << "MyDll DLL_PROCESS_DETACH" << endl;
            break;
    }
    return TRUE;
}

MyDll::MyDll()
{
    cout << "MyDll constructor" << endl;
}

void MyDll::func() const
{
    cout << mStr << endl;
}
