#include <iostream>
using namespace std;

struct A
{
  int m_sum{0};
  int incTen()
  {
     [this]() { 
      m_sum += 10; cout << "the value of m_sum = " << m_sum << "\n\n"; }();
      return m_sum;
  };
  int incTen_CaptureCopy(){
    [*this]() mutable { m_sum += 10; cout << "the value of m_sum copy = " << m_sum << "\n\n"; }();
    return m_sum;
  };
};

int main()
{
  A a;

  cout << "calling add 10 value of m_sum = " << a.m_sum << '\n';
  a.incTen();
  cout << "After calling add 10 value of m_sum = " << a.m_sum << "\n\n";
  a.incTen_CaptureCopy();
  cout << "After calling add 10_CaptureCopy() m_sum = " << a.m_sum << '\n';
  return EXIT_SUCCESS;
}