/* uniform initialization 
        -- with constructor (data members can be private/public)
        -- without constructor (data members must be public)

  direct initializer must require constructor anyway.
*/

#include <iostream>

class Date_A
{
  public:
    int m_year{};
    int m_month{};
    int m_day{};


  void print()
  {
      std::cout << m_day << "/" << m_month << "/" << m_year << std::endl;
  }

  Date_A(int y, int m, int d) : m_year(y), m_month(m), m_day(d)
  {
    std::cout << "in Date_A..." << std::endl;
  }
};

class Date_B
{
    int m_year{};
    int m_month{};
    int m_day{};

  public:
  void print()
  {
      std::cout << m_day << "/" << m_month << "/" << m_year << std::endl;
  }

  Date_B(int y, int m, int d) : m_year(y), m_month(m), m_day(d)
  {
    std::cout << "in Date_B..." << std::endl;
  }
};

class Date_C
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
  Date_A d1{2023, 01, 16}; // uniform initializer works with constructor & data members are public
  Date_B d2{2023, 01, 17}; // uniform initializer works with constructor & data members are private
  Date_C d3{2023, 01, 18}; // uniform initializer works with no constructor & data members are public

  d1.print();
  d2.print();
  d3.print();
  
 return 0;
}
