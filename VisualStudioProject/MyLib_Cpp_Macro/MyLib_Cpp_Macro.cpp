#include <iostream>
#include "SupportingMacro.h"

int main()
{
    ccoutln(select0_1("args0", "args1"));
    ccoutlnln(select0_1("args0", "args1", ?));

    ccoutln(select0_2("args0", "args1", "args2"));
    ccoutln(select0_2("args0", "args1", "args2", ?));
    ccoutlnln(select0_2("args0", "args1", "args2", ?, ?));

    ccoutln(parameterNum());
    ccoutln(parameterNum(?));
    ccoutln(parameterNum(?, ?));
    ccoutln(parameterNum(?, ?, ?));
    ccoutln(parameterNum(?, ?, ?, ?));
    ccoutln(parameterNum(?, ?, ?, ?, ?));
    ccoutln(parameterNum(?, ?, ?, ?, ?, ?));
    ccoutln(parameterNum(?, ?, ?, ?, ?, ?, ?));
    ccoutln(parameterNum(?, ?, ?, ?, ?, ?, ?, ?));
    ccoutlnln(parameterNum(?, ?, ?, ?, ?, ?, ?, ?, ?));

    std::cout << "Hello World!\n";
}



