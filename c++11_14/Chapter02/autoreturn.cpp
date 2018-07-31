#include <iostream>
#include <typeinfo>

template<typename T, typename U, typename R>
R add(T x, U y){
  return x + y;
}

template<typename T, typename U> 
auto add_c11(T x, U y) -> decltype(x+y){
  return x + y;
}

template<typename T, typename U> 
auto add_c14(T x, U y){
  return x + y;
}

int main(int argc, char const* argv[])
{
  auto x = 1;
  auto y = 2.0;
  // decltype(x+y) z = add(x, y);  // 无法通过编译器

  // std::cout << "result of traditional: \t" << z << std::endl; // output: i
  std::cout << "result of c11: \t" << add_c11(x, y) << 
    "\tthe type of result is :\t" <<typeid(add_c11(x, y)).name() << std::endl; // output: 3 d
  std::cout << "result of c14: \t" << add_c14(x, y) << 
    "\tthe type of result is :\t" << typeid(add_c14(x,y)).name() << std::endl; // output: 3 d

  return 0;
}
