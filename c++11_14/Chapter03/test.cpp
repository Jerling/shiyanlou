#include <iostream>
#include <functional>

int foo(int a, int b, int c) {
  std::cout << "a = " << a << " ";
  std::cout << "b = " << b << " ";
  std::cout << "c = " << c << std::endl;
  return a + b - c;
}

int main(int argc, char const* argv[])
{
  // 将参数1,2绑定到函数 foo 上，但是使用 std::placeholders::_1 来对第一个参数进行占位
  auto bindFoo = std::bind(foo, std::placeholders::_2, std::placeholders::_1, 1);
  // 这时调用 bindFoo 时，只需要提供第一个参数即可
  std::cout << bindFoo(3,4) << std::endl; // output: a=4 b=3, c=1
  return 0;
}
