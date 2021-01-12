#include <type_traits>
#include <iostream>
#include <utility>
using namespace std;

int main()
{
  pair p(12, "Hello");
  static_assert(is_same_v<decltype(p), pair<int, const char *>>);
  cout<< typeid(p.first).name() << typeid(p.second).name()<<"\n";
  return EXIT_SUCCESS;
}
