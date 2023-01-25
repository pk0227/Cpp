/* class without constructor, initilizing data members using uniform initializing.

  uniform initializer will work for class without constructors same as it works for 
  structure if and only if  class data members are public

  direct initializer requires constructors anyway.
*/

#include <iostream>

class DateClass
{
  public:
    int m_year{};
    int m_month{};
    int m_day{};

  //public:
  void print()
  {
      std::cout << m_day << "/" << m_month << "/" << m_year << std::endl;
  }

/*
  DateClass(int y, int m, int d) : m_year(y), m_month(m), m_day(d)
  {
  }
*/
};

int main()
{
  DateClass d1{2023, 01, 16}; // uniform initializer works without constructor if class members are public.
  //DateClass d2(2023, 01, 17); //direct initializer won't work as it requires constructor.
  d1.print();
  return 0;
}
