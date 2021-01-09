#include <iostream>
using namespace std;
class A
{
public:
  A()
  {
    ++num;
  }
  ~A()
  {
    --num;
  }
  inline static int num = 1;
};
int main()
{
  cout << "to demonstrate the inline variables" << endl;
  cout << "The static value is: " << A::num << "\n";
  return EXIT_SUCCESS;
}