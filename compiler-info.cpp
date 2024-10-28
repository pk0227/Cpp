#include <iostream>

int main() {
    #ifdef __clang__
        std::cout << "Clang/LLVM: " << __clang_version__ << std::endl;
    #elif defined(__GNUC__) || defined(__GNUG__)
        std::cout << "GNU GCC/G++: " << __GNUC__ << "." << __GNUC_MINOR__ << "." << __GNUC_PATCHLEVEL__ << std::endl;
    #elif defined(_MSC_VER)
        std::cout << "Microsoft Visual Studio: " << _MSC_VER << std::endl;
    #else
        std::cout << "Unknown compiler" << std::endl;
    #endif
    return 0;
}
