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


    with(std::cout << "no print", << std::endl;) ln;

    with(std::cout << , << std::endl;,
        "1")
    ln;

    with(std::cout << , << std::endl; ,
        "1",
        "2")
    ln;

    with(std::cout << , << std::endl;,
        "1",
        "2",
        "3")
    ln;
    // std::cout << "1" << std::endl;
    // std::cout << "2" << std::endl;
    // std::cout << "3" << std::endl;

    with(std::cout <<, << std::endl;,
        "1",
        "2",
        "3",
        "4",
        "5",
        "6")
}



