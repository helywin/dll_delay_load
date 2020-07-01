//
// Created by helywin on 2020/7/1.
//

#ifndef DLL_DELAY_LOAD_MYDLL_HPP
#define DLL_DELAY_LOAD_MYDLL_HPP

#include "MyDll_Export.hpp"

class MYDLL_API MyDll
{
private:
    const char *mStr = "MyDll func";
public:
    MyDll();
    void func() const;
};


#endif //DLL_DELAY_LOAD_MYDLL_HPP
