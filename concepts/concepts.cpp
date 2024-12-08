// Concepts are supported from C++20 onwards


#include <iostream>

/*
//syntax-1
template<typename T> requires std::integral<T>
T add(T a, T b)
{
    return a+b;
}
*/

/*
//syntax-2
template<typename T> 
T add(T a, T b) requires std::integral<T>
{
    return a+b;
}
*/

/*
//syntax-3
template<std::integral T> 
T add(T a, T b)
{
    return a+b;
}
*/


//syntax-4
std::integral auto add(std::integral auto a, std::integral auto b)
{
    return (a+b);
}


int main()
{
    std::cout << "add : " << add(100,150) << std::endl;
    return 0;
}