#include <iostream>
#include <functional>

using foo_ = void(int); // 定义函数指针， using 的使用是上一节别名的用法
void functional_(foo_ f)
{
  f(1);
}

int foo(int para){
  return para;
}

int main(int argc, char const* argv[])
{
  auto f = [](int value){
    std::cout << value <<std::endl;
  };
  functional_(f);  // 函数指针的使用 output: 1
  f(1);            // output: 1

  // std::function 包装一个返回值为 int 、参数为 int 的函数
  std::function<int(int)> func = foo;

  int important = 10;
  std::function<int(int)> func2 = [&](int value) -> int{
    return 1 + value + important;
  };
  std::cout << func(10) << std::endl; // output: 10
  std::cout << func2(10) << std::endl; // output: 21

  return 0;
}
