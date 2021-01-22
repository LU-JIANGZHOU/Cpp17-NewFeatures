#include <iostream>
#include <variant>
using namespace std;

int main()
{
  variant<int, long, double> a{0}; //ok
  cout << holds_alternative<int long>(a) << ' ' << holds_alternative<double>(a) << endl;

  variant<string> b("abc"); // OK
  cout << get<string>(b) << "\n";

  //variant<string, string> c("");                          // ill-formed
  variant<string, const char *> d("def"); // OK, chooses const char*
  cout << get<const char *>(d) << "\n";

  variant<string, bool> e("ghi"); // OK, chooses string; bool is not a candidate
  cout << get<string>(e) << "\n"; //bad variant access

  return EXIT_SUCCESS;
}