/* class without constructor, initilizing data members using uniform initializing.
  uniform initializer will work for class with out constructors same as it works for structure */

#include <iostream>

class DateClass
{
  //public:
    int m_year{};
    int m_month{};
    int m_day{};

  public:
  void print()
  {
      std::cout << m_day << "/" << m_month << "/" << m_year << std::endl;
  }

  private:
  DateClass(int y, int m, int d) : m_year(y), m_month(m), m_day(d)
  {
  }
};

int main()
{
  //DateClass d1{2023, 01, 16}; // uniform initializer works
  DateClass d2(2023, 01, 17); //direct initializer won't work as it requires constructor.
  d2.print();
  return 0;
}
