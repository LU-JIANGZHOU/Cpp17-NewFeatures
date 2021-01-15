#include <iostream>
#include <set>
#include <string>
#include <tuple>
#include <utility>
using namespace std;

int main()
{
  const string myString = "This is a test string";
  //C++11
  {
    const auto it = myString.find("Hello");
    if (it != string::npos)
      cout << it << " Hello\n";
    else
      cout << "there is no Hello"
           << "\n";
  }

  {
    const auto it = myString.find("string");
    if (it != string::npos)
      cout << it << " string\n";
    else
      cout << "there is no string"
           << "\n";
  }

  //C++17
  if (const auto it = myString.find("Hello"); it != string::npos)
    cout << it << " Hello\n";
  else
    cout << "no hello"
         << "\n";

  if (const auto it = myString.find("string"); it != string::npos)
    cout << it << " string\n";

  set<pair<string, int>> mySet;

  pair<string, int> items[3]{{"this", 1}, {"is", 2}, {"string", 3}};

  for (auto &p : items)
  {
    if (const auto [iter, inserted] = mySet.insert(p); inserted)
      cout << "Value(" << iter->first << ", " << iter->second << ") was inserted"
           << "\n";
    else
      cout << "Value(" << iter->first << ", ...) not inserted!"
           << "\n";
  }
  return EXIT_SUCCESS;
}
