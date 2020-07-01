//
// Created by helywin on 2020/7/1.
//

#include <iostream>
#include <windows.h>
#include "MyDll.hpp"
using namespace std;

int main()
{
    SetDllDirectory("dlls");
    cout << "press ENTER to continue..." << endl;
    getchar();
    cout << "begin" << endl;
    MyDll dll;
    cout << "new" << endl;
    dll.func();
    cout << "end" << endl;
}
