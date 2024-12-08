
#include <iostream>

template<typename T>
T add(T a, T b)
{
    //std::cout << "a : " << a << "\n" << "b : " << b << std::endl;
    return a+b;
}

int main()
{
    
    std::cout << "add : " << add(10, 12) << std::endl;
    std::cout << "add : " << add<>(10, 12) << std::endl;
    std::cout << "add : " << add<int>(10.12, 12.10) << std::endl;
    
    std::cout << "add : " << add(10.12, 12.10) << std::endl;
    std::cout << "add : " << add<>(10.12, 12.10) << std::endl;
    std::cout << "add : " << add<float>(10.12, 12.10) << std::endl;
    std::cout << "add : " << add<double>(10.12, 12.10) << std::endl;
    
    //std::cout << "add : " << add<int, float>(10.12, 12.10) << std::endl;
    return 0;
}