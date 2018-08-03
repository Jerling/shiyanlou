#include <iostream>
#include <vector>

std::vector<int> foo()
{
  std::vector<int> tmp = {1,2,3,4,5};
  return tmp;
}

int main(int argc, char const* argv[])
{
  std::vector<int> vec = foo();
  /*
   * vec 为左值，foo() 的返回值是纯右值
   * 而在foo(), 里面的 tmp 临时值，一旦被 vec 
   * 复制后，就被销毁，称为将亡值
   * */
  for(auto &i : vec)
    std::cout << i << " ";
  std::cout << std::endl;
  return 0;
}
