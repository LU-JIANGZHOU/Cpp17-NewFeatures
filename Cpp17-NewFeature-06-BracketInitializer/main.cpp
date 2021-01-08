#include <iostream>
using namespace std;

int main()
{
  cout<<"to demonstrate the bracket initializer"<<endl;
  //auto a{1, 2, 3}; // error: not a single element
  auto a = {1, 2, 3}; // a is std::initializer_list<int>
  cout<<typeid(a).name()<<"\n";

  auto b{3}; // b is int
  cout<<typeid(b).name()<<"\n";

  auto c{3.0}; // c is double
  cout<<typeid(c).name()<<"\n";

  return EXIT_SUCCESS;
}
;
