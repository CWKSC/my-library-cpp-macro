#pragma once

#define ln putchar('\n')
#define ln2 printf("\n\n")

#define refer *

#define leftBracket (
#define rightBracket )

#define leftCurlyBracket {
#define rightCurlyBracket }

#define comma ,

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

#define with(start, end, ...) \
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

//#define with(start, end, m1, m2, m3) \
//    start m1 end \
//    start m2 end \
//    start m3 end
