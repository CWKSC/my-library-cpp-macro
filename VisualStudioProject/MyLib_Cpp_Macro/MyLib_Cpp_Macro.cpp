#include <iostream>
#include "SupportingMacro.h"

int main()
{
    ccoutln(select0_1("args0", "args1"));
    // Expend to:
    // ccoutln(select0_1("args0", "args1"));
    // * #define ccoutln(...) std::cout << # __VA_ARGS__ " : " << __VA_ARGS__ << '\n'
    // __VA_ARGS__ = select0_1("args0", "args1")
    // -> std::cout << # __VA_ARGS__ " : " << __VA_ARGS__ << '\n';
    // -> std::cout << "select0_1(\"args0\", \"args1\")" " : " << select0_1("args0", "args1") << '\n';
    // * #define select0_1(m0, m1, ...) get2th( __VA_ARGS__ __VA_OPT__(,) m1, m0 )
    // m0 = "args0" | m1 = "args1" | __VA_ARGS__ = (Empty) | __VA_OPT__(,) = (Empty)
    // -> std::cout << "select0_1(\"args0\", \"args1\") : " << get2th( __VA_ARGS__ __VA_OPT__(,) m1, m0 ) << '\n';
    // -> std::cout << "select0_1(\"args0\", \"args1\") : " << get2th("args1", "args0") << '\n';
    // * #define get2th(a1, a2, ...) a2
    // a2 = "args0"
    // -> std::cout << "select0_1(\"args0\", \"args1\") : " << a2 << '\n';
    // -> std::cout << "select0_1(\"args0\", \"args1\") : " << "args0" << '\n';

    // I just expand this as an example.
    // Macro is something outdated.
    // Very no clean and difficult to maintain.
    // Also, Different compilers have different behaviors. 
    // For some advanced Macro, it cannot be shared between different compilers.


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

    with(std::cout << parameterNum, << std::endl;,
        (),
        (?),
        (?, ?),
        (?, ?, ?),
        (?, ?, ?, ?),
        (?, ?, ?, ?, ?),
        (?, ?, ?, ?, ?, ?),
        (?, ?, ?, ?, ?, ?, ?),
        (?, ?, ?, ?, ?, ?, ?, ?),
        (?, ?, ?, ?, ?, ?, ?, ?, ?)
    );


    with(std::cout << "It will not print anything", << std::endl;) ln;

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
    // Expend to: //
    // std::cout << "1" << std::endl;
    // std::cout << "2" << std::endl;
    // std::cout << "3" << std::endl;

    with(std::cout <<, << std::endl;,
        "1",
        "2",
        "3",
        "4",
        "5",
        "6",
        "7",
        "8",
        "9",
        "10",
        "11") // the expend max is 10, so "11" will not show and no expend when compile
}
/* Output
select0_1("args0", "args1") : args0
select0_1("args0", "args1", ?) : args1

select0_2("args0", "args1", "args2") : args0
select0_2("args0", "args1", "args2", ?) : args1
select0_2("args0", "args1", "args2", ?, ?) : args2

parameterNum() : 0
parameterNum(?) : 1
parameterNum(?, ?) : 2
parameterNum(?, ?, ?) : 3
parameterNum(?, ?, ?, ?) : 4
parameterNum(?, ?, ?, ?, ?) : 5
parameterNum(?, ?, ?, ?, ?, ?) : 6
parameterNum(?, ?, ?, ?, ?, ?, ?) : 7
parameterNum(?, ?, ?, ?, ?, ?, ?, ?) : 8
parameterNum(?, ?, ?, ?, ?, ?, ?, ?, ?) : 9

0
1
2
3
4
5
6
7
8
9

1

1
2

1
2
3

1
2
3
4
5
6
7
8
9
10
*/
