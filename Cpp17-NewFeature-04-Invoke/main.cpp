#include <functional>
#include <iostream>
using namespace std;

struct A {
    A(int num) : _num(num) {}
    void myAdd(int i) const { cout << _num+i << '\n'; }
    int _num;
};
 
void myAdd(int i, int j)
{
    cout << i+j << '\n';
}
 
struct B{
    void operator()(int i) const
    {
        std::cout << i << '\n';
    }
};
 
int main()
{
  cout<<"to demonstrate the invoke"<<endl;

    // invoke a function
    invoke(myAdd, 2,6);
 
    // invoke a lambda
    auto funct= []() { myAdd(3,7); };
    invoke(funct);
 
    // invoke a member function
    const A a(9);
    invoke( & A::myAdd, a, 1);
 
    // invoke a data member
    cout << "num: " << invoke(&A ::_num, a) << '\n';
 
    // invoke a function object
    invoke(B(), 18);

  return EXIT_SUCCESS;
}
