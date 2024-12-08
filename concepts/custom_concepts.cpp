// Concepts are supported from C++20 onwards


#include <iostream>
#include <concepts>
#include <string>

//Custom Concepts Definition
//--------------------------------------------------------------
template<typename T>
concept MyIntegral = std::integral<T>;

template<typename T>
concept Multiplicable = requires (T a, T b)
{
    a + b;//a * b;  // will just check if a and b are eligible for multiplication.
};

template<typename T>
concept Incrementable = requires (T a)
{
    a++;
    ++a;
    a+=1;
};

//Custom Concepts Usage
//--------------------------------------------------------------

/*
template<typename T> requires MyIntegral<T>
//template<MyIntegral T>
//template<typename T> 
T add(T a, T b) //requires MyIntegral<T>
{
    return (a+b);
}
*/


template<typename T> requires Multiplicable<T>
//template<Multiplicable T>
//template<typename T> 
T add(T a, T b) //requires Multiplicable<T>
{
    return (a+b);
}


/*
template<typename T> requires Incrementable<T>
//template<Incrementable T>
//template<typename T> 
T add(T a, T b) //requires Incrementable<T>
{
    return (a+b);
}
*/

/*
template<typename T>
void test_type(T &a)
{
    if(std::is_integral_v<T>)
    {
        std::cout << "std::is_integral_v" << std::endl;
    }
 
    if(std::integral<T>)
    {
        std::cout << "std::integral" << std::endl;
    }
    
}
*/

int main()
{
    int a{10};
    
    std::cout << "add : " << add(10,20) << std::endl;
    std::cout << "add : " << add<>(10,20) << std::endl;
    std::cout << "add : " << add<int>(10.20,20.10) << std::endl;
    
    std::cout << "add : " << add<float>(10,20) << std::endl;
    std::cout << "add : " << add<double>(10,20) << std::endl;
    
    std::cout << "add : " << add<>(10.20,20.10) << std::endl;
    //std::cout << "add : " << add<>(10,20.10) << std::endl;      // it always fails as the argument types are different. 
                                                                // the arguments should be same typename as defined in concept definition
                                                               
    std::cout << "add : " << add<std::string>("Hello", "World") << std::endl;
    
    //test_type(a);
    return 0;
}