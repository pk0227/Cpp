#include <iostream>

class Date
{
    int m_year{};
    int m_month{};
    int m_day{};

  public:
    Date(int y=0, int m=0, int d=0) : m_year(y), m_month(m), m_day(d)
    {
      std::cout << "in Date..." << std::endl;
    }
    
    // Setter Functions
    void setYear(int &y)
    {
      m_year = y;
    }
    
    void setMonth(int &m)
    {
      m_month = m;
    }

    void setDay(int &d)
    {
      m_day = d;
    }
    
    //Getter Functions
    int getYear()
    {
        return m_year;
    }
  
    int getMonth()
    {
        return m_month;
    }

    int getDay()
    { 
        return m_day;
    }

};


int main()
{
  Date d1{2023, 01, 25};
  std::cout << "Today Date : " << d1.getDay()  << "/" << d1.getMonth() << "/" << d1.getYear() << std::endl;
 
  return 0;
}