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
  DateClass d1{2023, 01, 16};
  d1.print();
  return 0;
}
