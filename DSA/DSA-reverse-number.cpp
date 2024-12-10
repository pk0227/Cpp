#include <iostream>
#include <bits/stdc++.h>

unsigned int reverseNumberRecursive(unsigned int num)
{
    static int power{0};
    unsigned int revNum{0};
    
    if(num)
    {
        revNum = reverseNumberRecursive(num/10);
        revNum += ((num%10) * pow(10,power++));
    }
    
    return revNum;
}

unsigned int reverseNumber(unsigned int num)
{
    int power{static_cast<int>(log10(num))};
    unsigned int revNum{0};
    
    while(num)
    {
        revNum += ((num%10) * pow(10,power--));
        num /= 10;
    }
    
    return revNum;
}

unsigned int reverseNumber_(unsigned int num)
{
    
    unsigned int revNum{0};
    
    while(num)
    {
        revNum = (revNum*10) + (num%10);
        num /= 10;
    }
    
    return revNum;
}

int main()
{
    unsigned int number{0};
    
    std::cout << "Enter a number : " ;
    std::cin >> number;
    
    std::cout << "reverse of given number( " << number << " ) : " << reverseNumber(number) << std::endl;
    std::cout << "Recursive - reverse of given number( " << number << " ) : " << reverseNumberRecursive(number) << std::endl;
    std::cout << "reverse of given number( " << number << " ) : " << reverseNumber_(number) << std::endl;
    return 0;
}