#include <iostream>
using namespace std;

namespace A::B::C
{
  class X
  {
  public:
    int x = 1;
    float y = 2.1;
  };
}; // namespace A::B::C

namespace D
{
  namespace E
  {
    namespace F
    {
      class Y
      {
      public:
        int x = 3;
        float y = 4.1;
      };
    } // namespace F
  }   // namespace E
};    // namespace D

int main()
{
  cout << "01 demonstrate the nested namespaces in c++ 17" << endl;
  A::B::C::X a;
  cout << a.x << a.y << endl;
  D::E::F::Y b;
  cout << b.x << b.y << endl;
  return EXIT_SUCCESS;
};
