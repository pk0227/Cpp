#include <iostream>
#include <bits/stdc++.h>

int countAndPrintDigits(unsigned int num)
{
    int ret{0};
    if(num)
    {
        ret = countAndPrintDigits(num/10);
        std::cout << num%10 << " ";
        return ++ret;
    }
    else
        return 0;
}

int countDigits(unsigned int num)
{
    int count{0};
    
    while(num)
    {
        count++;
        num /= 10;
    }
    
    return count;
}

int countWithLog(unsigned int num)
{
    return (static_cast<int>(log10(num)) + 1);
}

int main()
{
    unsigned int number{0}, numOfDigits{0};
    
    std::cout << "Enter a number : " ;
    std::cin >> number;
    
    numOfDigits = countDigits(number);
    std::cout << "No of digits in " << number << " : " << numOfDigits << std::endl;
    
    numOfDigits = countAndPrintDigits(number);
    std::cout << "\nNo of digits in " << number << " : " << numOfDigits << std::endl;

    numOfDigits = countWithLog(number);
    std::cout << "No of digits in " << number << " : " << numOfDigits << std::endl;
    
    return 0;
}