#include <vector>
#include <climits>
#include <cstdint>
#include <type_traits>
#include <utility>
#include <iostream>

using namespace std;

template <typename... Exprs>
void myPrint(Exprs &&... exprs)
{
  (cout << ... << exprs) << '\n';
}

template <typename T, typename... Exprs>
void push_back_vec(vector<T> &v, Exprs &&... exprs)
{
  static_assert((is_constructible_v<T, Exprs &&> && ...));
  (v.push_back(forward<Exprs>(exprs)), ...);
}

bool allVar()
{
  return true;
}

template <typename T, typename... Ts>
bool allVar(T t, Ts... ts)
{
  return t && allVar(ts...);
}

template <typename... Args>
bool all(Args... args) { return (... && args); }

int main()
{

  myPrint(10, 20, 69, "abcdr");

  std::vector<int> v;
  push_back_vec(v, 34, 56, 78, 12, 'a');
  push_back_vec(v, 12, 23, 34);
  for (int i : v)
    cout << i << ' ';
  cout << "\n";

  //cout << "allVar(): " << allVar() << endl;
  cout << "all(): " << all() << endl;

  cout << "allVar(true): " << allVar(true) << endl;
  cout << "all(true): " << all(true) << endl;

  cout << "allVar(true, true, true, false): " << allVar(true, true, true, false) << endl;
  cout << "all(true, true, true, false): " << all(true, true, true, false) << endl;

  return EXIT_SUCCESS;
}
