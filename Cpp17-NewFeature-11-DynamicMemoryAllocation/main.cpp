#include <iostream>
#include <cassert>
#include <cstdint>
#include <malloc.h>
#include <new>
using namespace std;

//C++11
struct alignas(16) Vec3
{
  float x, y, z;
};

class alignas(16) float4
{
  float f[4];
};

int main()
{
  //C++11
  auto ptr = new Vec3[1024];
  float4 *p = new float4[10];

  if (reinterpret_cast<uintptr_t>(&ptr) % alignof(Vec3) == 0)
    std::cout << "ptr is aligned to alignof(Vec3)!\n";
  else
    std::cout << "ptr is not aligned to alignof(Vec3)!\n";

  if (reinterpret_cast<uintptr_t>(p) % alignof(Vec3) == 0)
    std::cout << "p is aligned to alignof(Vec3)!\n";
  else
    std::cout << "p is not aligned to alignof(Vec3)!\n";

  delete[] p;
  delete[] ptr;

  return EXIT_SUCCESS;
}
