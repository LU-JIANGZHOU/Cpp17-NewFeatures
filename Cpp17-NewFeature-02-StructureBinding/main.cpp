#include <iostream>
#include <array>
#include <vector>
#include <map>

using namespace std;

struct Point3D
{
  Point3D(float x, float y, float z) : x(x), y(y), z(z){};
  float x;
  float y;
  float z;

  /* private:
  float heading = 0;//there are more elements than there are binding names */
};
Point3D getPoint()
{
  Point3D ST(1, 2, 3);
  return ST;
}

int main()
{
  std::cout << "demonstrate the Structure Binding in C++ 17" << std::endl;

  //1) array
  {
    //c array
    int cArr[] = {10, 20, 30};
    auto [v01, v02, v03] = cArr;
    cout << v01 << " " << v02 << " " << v03 << " " << endl;

    //cpp array
    int cppArr[] = {11, 21, 31};
    auto [v11, v12, v13] = cppArr;
    cout << v11 << " " << v12 << " " << v13 << " " << endl;
  }

  //2) struct
  {
    //binding by return value
    auto [x, y, z] = getPoint();
    cout << x << " " << y << " " << z << " " << endl;

    //data member binding
    Point3D sTemp(3.0, 4.0, 5.0);
    auto [x1, y1, z1] = sTemp;
    cout << x1 << " " << y1 << " " << z1 << " " << endl;
  }

  //3 vector
  {
    vector<Point3D> points = {
        Point3D(1, 2, 3),
        Point3D(4, 5, 6),
        Point3D(7, 8, 9)};
    for (auto &[x, y, z] : points)
    {
      x += 10;
      y += 20;
      z += 30;
    }

    for (vector<Point3D>::iterator it = points.begin(); it != points.end(); ++it)
    {
      std::cout << ' ' << it->x << " " << it->y << " " << it->z;
      std::cout << '\n';
    }
  }
  // 4 pair
  {
    std::pair<int, double> p{2, 2.0};
    auto [i, d] = p;
    std::cout << "The pair element are: " << i << " " << d << '\n';
  }
  //5 map
  {
    const std::map<int, std::string> countryCodes{
        {65, "Singapore"},
        {86, "China"},
        {33, "France"},
    };

    for (const auto &[k, v] : countryCodes)
      std::cout << k << " " << v << "\n";
  }

  //6tuple
  {
    const auto tpl = std::make_tuple(1, 'a', 2.3);
    const auto [i, c, d] = tpl;
    std::cout << "The tuple element are: " << i << " " << c << " " << d << '\n';
  }
  return EXIT_SUCCESS;
};
