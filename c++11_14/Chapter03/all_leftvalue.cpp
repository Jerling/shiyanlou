#include <iostream>

void reference(int& v) {
    std::cout << "左值" << std::endl;
}
void reference(int&& v) {
    std::cout << "右值" << std::endl;
}
template <typename T>
void pass(T&& v) {
    std::cout << "普通传参:";
    reference(v);   // 始终调用 reference(int& )
}

int main(int argc, char const* argv[])
{
  std::cout << "传递右值：" << std::endl;
  pass(1);             // 1是右值, 但输出左值

  pass(std::move(1));  // 左值

  std::cout << "传递左值：" << std::endl;
  int v = 1;
  pass(v);            // v是左引用, 输出左值

  pass(std::move(v));  // 左值

  return 0;
}
