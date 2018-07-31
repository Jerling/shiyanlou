#include <iostream>
#include <typeinfo>

int main(int argc, char const* argv[])
{
  auto x = 1;
  auto y = 2.0;
  decltype(x+y) z;

  std::cout << "type of x: \t" << typeid(x).name() << std::endl; // output: i
  std::cout << "type of y: \t" << typeid(y).name() << std::endl; // output: d
  std::cout << "type of z: \t" << typeid(z).name() << std::endl; // output: d

  return 0;
}
