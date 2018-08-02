#include <iostream>
#include <memory>

void learn_lambda_func_1() {
  /*
   * 值捕获
   * */
  int value_1 = 1;
  auto copy_value_1 = [value_1] {
    return value_1;
  };
  value_1 = 100;
  auto stored_value_1 = copy_value_1();

  std::cout << "value_1 = " << value_1 << " "; // output: 100
  std::cout << "stored_value_1 = " 
    << stored_value_1 << std::endl;           // output: 1 因为在copy_value_1创建时就保存了 value_1 的拷贝
}

void learn_lambda_func_2()
{
  /*
   * 引用捕获
   * */
  int value_2 = 1;
  auto copy_value_2 = [&value_2]{
    return value_2;
  };
  value_2 = 100;
  auto stored_value_2 = copy_value_2();
  std::cout << "value_2 = " << value_2 << " "; // output: 100
  std::cout << "stored_value_2 = " 
    << stored_value_2 << std::endl;           // output: 100 因为在copy_value_2创建时保存了 value_2 的引用

}
void learn_lambda_func_3()
{
  /*
   * 隐式捕获
   * */
  int value_1 = 1;
  int value_2 = 2;
  auto copy_value_2 = [&]{
    return value_1 + value_2;
  };
  value_1 = 100;
  value_2 = 200;
  auto stored_value_2 = copy_value_2();
  std::cout << "value_2 = " << value_2 << " "; // output: 100
  std::cout << "stored_value_2 = " 
    << stored_value_2 << std::endl;           // output: 100 

}

void learn_lambda_func_4()
{
  auto important = std::make_unique<int>(1);  // important 被定义为一个独占指针, 是不能捕获的
  auto add = [v1 = 2.5, v2 = std::move(important)](int x, int y) -> int{ // move 用来将 important 转移为右值
    return x + y + v1 + (*v2);
  };
  std::cout << "add(3,4) = " << add(3,4) << std::endl;  // output: 9
}
int main(int argc, char const* argv[])
{
  learn_lambda_func_1();
  learn_lambda_func_2();
  learn_lambda_func_3();
  learn_lambda_func_4();
  return 0;
}
