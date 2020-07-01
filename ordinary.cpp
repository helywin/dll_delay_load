#include <iostream>
#include "MyDll.hpp"
#include <iostream>
using namespace std;

int main()
{
    cout << "press ENTER to continue..." << endl;
    getchar();
    cout << "begin" << endl;
    MyDll dll;
    cout << "new" << endl;
    dll.func();
    cout << "end" << endl;
}
