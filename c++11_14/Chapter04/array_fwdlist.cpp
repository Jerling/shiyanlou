#include <iostream>
#include <array>
#include <forward_list> // 单向链表实现，list是双向的,而且唯一没有size方法
#include <algorithm>

void visit(auto a) {
  for(auto i : a)
    std::cout << i << " ";
  std::cout << std::endl;
}

void foo(int *p, int len) {
  std::cout << "len : " << len << std::endl;
  for (int i = 0; i < len; i++) {
    std::cout << *(p + i) << " ";
  }
  std::cout << std::endl;
}
int main(int argc, char const* argv[])
{
  std::array<int, 5> arr = {1,2,3,4,5};
  // int len = 5;
  // std::array<int, len> arr = {1,2,3,4,5}; // 非法，大小必须是常量表达式
  const int len_cst = 5;
  std::array<int , len_cst> arr_cst = {1,2,3,4,5};
  visit(arr);
  visit(arr_cst);

  // foo(arr, arr.size()); // 非法，无法隐式转换为指针
  foo(&arr[0], arr.size());
  foo(arr.data(), arr.size()); // data() 是取得首指针

  // 使用lambda表达式
  std::sort(arr.begin(), arr.end(), [](int a, int b){return a > b;});
  std::cout << "sorted:" ;
  visit(arr);
  // 使用自定义函数
  struct customlg{
    bool operator()(int a, int b){return a > b;}
  }customlg ;  // 此处名字不可省略, 前面的无所谓，没有也行
  std::sort(arr_cst.begin(), arr_cst.end(), customlg);
  std::cout << "sorted:" ;
  visit(arr_cst);

  std::forward_list<int> flt= {1,2,3};
  visit(flt);
  return 0;
}
