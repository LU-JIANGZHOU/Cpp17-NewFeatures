#include <cstddef>
#include <iostream>
using namespace std;

// Function to Display byte a
void Display(const byte &a)
{
  cout << to_integer<int>(a) << endl;
}

int main()
{
  byte b{7};

  // Initialize two new bytes using
  // binary literals
  byte b1{0b1100};
  byte b2{0b1010};

  // show byte
  Display(b);
  // A 2-bit left shift
  b <<= 3;
  //show byte
  Display(b);
  Display(b1);
  Display(b2);

  // Bit-wise OR and AND operations
  byte byteOr = b1 | b2;
  byte byteAnd = b1 & b2;

  // show byte
  Display(byteOr);
  Display(byteAnd);

  return 0;
}