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