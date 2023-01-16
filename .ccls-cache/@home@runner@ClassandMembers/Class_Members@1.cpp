/* class without constructor, initilizing data members using uniform initializing.
  uniform initializer will work for class with out constructors same as it works for structure */

#include <iostream>

class DateClass
{
  public:
    int m_year{};
    int m_month{};
    int m_day{};

  void print()
  {
      std::cout << m_day << "/" << m_month << "/" << m_year << std::endl;
  }
};

int main()
{
  DateClass d1{2023, 01, 16}; // uniform initializer works
  //DateClass d2(2023, 01, 17); //direct initializer won't work as it requires constructor.
  d1.print();
  return 0;
}
