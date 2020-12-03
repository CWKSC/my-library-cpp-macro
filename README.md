# MyLib_Cpp_Macro
Marco Lib for C++20 and new preprocessor in Visual Studio 2019

The old version macro lib before Visual Studio and C++20 update in here: [MacroLib](https://github.com/CWKSC/MacroLib)

### Set new preprocessor in the Visual Studio

1. Open the project's **Property Pages** dialog box. 
2. Select the **Configuration Properties** > **C/C++** > **Command Line** property page.
3. Modify the **Additional Options** property to include **/Zc:preprocessor /std:c++latest** and then choose **OK**.

### Some change detail

[MSVC experimental preprocessor overview | Microsoft Docs](https://docs.microsoft.com/en-us/cpp/preprocessor/preprocessor-experimental-overview?view=vs-2019)

[Announcing full support for a C/C++ conformant preprocessor in MSVC | C++ Team Blog](https://devblogs.microsoft.com/cppblog/announcing-full-support-for-a-c-c-conformant-preprocessor-in-msvc/)

### Source Code - Main

```c++
#include <iostream>
#include "SupportingMacro.h"

int main()
{
    ccoutln(select0_1("args0", "args1"));
    // Expend to:
    // -> ccoutln(select0_1("args0", "args1"));
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
```

### Source Code - SupportingMarco

```c++
#pragma once

#define ln putchar('\n')
#define ln2 printf("\n\n")

#define refer *

#define leftBracket (
#define rightBracket )

#define leftCurlyBracket {
#define rightCurlyBracket }

#define comma ,

#define eatBrackets(...) __VA_ARGS__

#define midLayer(...) __VA_ARGS__

#define linkMacro_body(a, b) a ## b
#define linkMacro(a, b) linkMacro_body(a, b)
#define uniqueVarName(name) linkMacro(name, __COUNTER__)
#define uniqueVarName2(name) linkMacro_body leftBracket name, __COUNTER__ )


#define get1th(a1, ...) a1
#define get2th(a1, a2, ...) a2
#define get3th(a1, a2, a3, ...) a3
#define get4th(a1, a2, a3, a4, ...) a4
#define get5th(a1, a2, a3, a4, a5, ...) a5
#define get6th(a1, a2, a3, a4, a5, a6, ...) a6
#define get7th(a1, a2, a3, a4, a5, a6, a7, ...) a7
#define get8th(a1, a2, a3, a4, a5, a6, a7, a8, ...) a8
#define get9th(a1, a2, a3, a4, a5, a6, a7, a8, a9, ...) a9
#define get10th(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, ...) a10

#define parameterNum(...) get10th( __VA_ARGS__ __VA_OPT__(,) 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)

#define select0_1(m0, m1, ...) get2th( __VA_ARGS__ __VA_OPT__(,) m1, m0 )
#define select0_2(m0, m1, m2, ...) get3th( __VA_ARGS__ __VA_OPT__(,) m2, m1, m0 )
#define select0_3(m0, m1, m2, m3, ...) get4th( __VA_ARGS__ __VA_OPT__(,) m3, m2, m1, m0 )
#define select0_4(m0, m1, m2, m3, m4, ...) get5th( __VA_ARGS__ __VA_OPT__(,) m4, m3, m2, m1, m0 )
#define select0_5(m0, m1, m2, m3, m4, m5, ...) get6th( __VA_ARGS__ __VA_OPT__(,) m5, m4, m3, m2, m1, m0 )
#define select0_6(m0, m1, m2, m3, m4, m5, m6, ...) get7th( __VA_ARGS__ __VA_OPT__(,) m6, m5, m4, m3, m2, m1, m0 )
#define select0_7(m0, m1, m2, m3, m4, m5, m6, m7, ...) get8th( __VA_ARGS__ __VA_OPT__(,) m7, m6, m5, m4, m3, m2, m1, m0 )
#define select0_8(m0, m1, m2, m3, m4, m5, m6, m7, m8, ...) get9th( __VA_ARGS__ __VA_OPT__(,) m8, m7, m6, m5, m4, m3, m2, m1, m0 )

#define ifTrue(condition, expersion) \
    condition && expersion

#define ifFalse(condition, expersion) \
    !condition && expersion

#define conditionalOperator(condition, exp1, exp2) \
    ifTrue(condition, exp1), ifFalse(condition, exp2)


#define ccout(...) std::cout << # __VA_ARGS__ " : " << __VA_ARGS__
#define ccoutln(...) std::cout << # __VA_ARGS__ " : " << __VA_ARGS__ << '\n'
#define ccoutlnln(...) std::cout << # __VA_ARGS__ " : " << __VA_ARGS__ << "\n\n"

#define IfExist(statement, ...) __VA_OPT__(statement)

#define with_body(start, end, ...) \
    IfExist(start get1th(__VA_ARGS__) end, get1th(__VA_ARGS__)) \
    IfExist(start get2th(__VA_ARGS__) end, get2th(__VA_ARGS__,)) \
    IfExist(start get3th(__VA_ARGS__) end, get3th(__VA_ARGS__,,)) \
    IfExist(start get4th(__VA_ARGS__) end, get4th(__VA_ARGS__,,,)) \
    IfExist(start get5th(__VA_ARGS__) end, get5th(__VA_ARGS__,,,,)) \
    IfExist(start get6th(__VA_ARGS__) end, get6th(__VA_ARGS__,,,,,)) \
    IfExist(start get7th(__VA_ARGS__) end, get7th(__VA_ARGS__,,,,,,)) \
    IfExist(start get8th(__VA_ARGS__) end, get8th(__VA_ARGS__,,,,,,,)) \
    IfExist(start get9th(__VA_ARGS__) end, get9th(__VA_ARGS__,,,,,,,,)) \
    IfExist(start get10th(__VA_ARGS__) end, get10th(__VA_ARGS__,,,,,,,,,))

#define with(start, end, ...) \
    midLayer(with_body(start, end, __VA_ARGS__))

```

