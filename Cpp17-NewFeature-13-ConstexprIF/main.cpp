#include <iostream>
#include <set>
#include <string>
#include <tuple>
#include <utility>
using namespace std;

template <typename T>
constexpr bool isInteger(T n)
{
  if constexpr (std::is_integral<T>::value)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int main()
{
  static_assert(isInteger(3) == true);
  static_assert(isInteger('c') == true);
  static_assert(isInteger(3.1415926) == false);
  return EXIT_SUCCESS;
}
