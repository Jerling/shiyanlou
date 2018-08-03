#include <iostream>
#include <string>

void reference(std::string& str) {
  std::cout << "左值" << std::endl;
}

void reference(std::string&& str) {
  std::cout << "右值" << std::endl;
}

int main(int argc, char const* argv[])
{
  std::string  lv1 = "string,";       // lv1 是一个左值
  std::cout << "lv1 = " << &lv1 << std::endl;      // string,
  // std::string&& r1 = s1;           // 非法, s1 在全局上下文中没有声明
  std::string&& rv1 = std::move(lv1); // 合法, std::move 可以将左值转移为右值
  rv1 += "rv1";
  std::cout << "rv1 = " << rv1 << std::endl;      // string,rv1
  	
  auto test = lv1;            // 合法，只是一份拷贝,但是在同一地址
  test += "test";
  std::cout << "test = " << test << std::endl;      // string,rv1test

  auto test_1 = &lv1;            // 合法
  *test_1 += "test_1";         // 不能等同于左值引用，这里的字符串增加只是在尾部添加
  std::cout << "test_1 = " << *test_1 << std::endl;      // string,rv1test_1

  const std::string& lv2 = lv1 + lv1; // 合法, 常量左值引用能够延长临时变量的生命周期
  // lv2 += "Test";                   // 非法, 引用的右值无法被修改
  std::cout << "lv2 = "<<lv2 << std::endl;      // string,rv1test_1stringstring,rv1test_1

  std::string&& rv2 = lv1 + lv2;      // 合法, 右值引用延长临时对象的生命周期
  rv2 += "string";                    // 合法, 非常量引用能够修改临时变量
  std::cout << "rv2 = " << rv2 << std::endl;      // string,rv1test_1string,rv1test_1string,rv1test_1string

  reference(rv1);                    // 输出左值
  reference(rv2);                    // 输出左值,rv2 虽然引用了一个右值，但由于它是一个引用，所以 rv2 依然是一个左值。
  reference(std::move(lv1));         // 输出右值，std::move 将左值转换为右值
  return 0;
}
