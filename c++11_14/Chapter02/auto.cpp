#include <iostream>
#include <vector>
#include <typeinfo>

int main(int argc, char const* argv[])
{
  std::vector<int> vec = {1,2,3,4,5};

  std::cout << "Normal modal:\t";
  for(std::vector<int>::const_iterator itr = vec.cbegin(); itr != vec.cend(); ++itr)
    std::cout << *itr << " ";
  
  std::cout << std::endl;
  std::cout << "auto modal: \t";
  for(auto itr = vec.cbegin(); itr != vec.cend(); ++itr)
    std::cout << *itr << " "; 

  auto i = 5;
  auto a_i = new auto(10);
  auto a_d = new auto(10.0);
  std::cout << std::endl;
  std::cout << "type(i) \t\t:" << typeid(i).name() <<std::endl;
  std::cout << "type(a_i) \t:" << typeid(a_i).name() <<std::endl;
  std::cout << "type(a_d) \t:" << typeid(a_d).name() <<std::endl;

  // 下面的代码无法通过编译器，即不能推导数组
  // auto i = 5;
  // int arr[10] = {0};
  // auto auto_arr = arr;
  // auto auto_arr2[10] = arr;
  // return 0;
}

