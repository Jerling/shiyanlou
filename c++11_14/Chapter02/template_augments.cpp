#include <iostream>
#include <vector>
#include <typeinfo>
#include <initializer_list>

template<typename T, typename U, int value> 
class SuckType {
  private:
    T a;
    U b;
  public:
    SuckType():a(value > 0),b(value){};
    void Visit() const{
      std::cout << a << " " <<b << std::endl;
    }
};

// typedef SuckType<std::vector<int>, U, 1> NewType; // 不合法

typedef int (*process)(void *);  // 定义了一个返回类型为 int，参数为 void* 的函数指针类型，名字叫做 process
using process = int(*)(void *); // 同上, 更加直观

template <typename T>
using NewType = SuckType<int, T , 3>;  // 合法

template<typename T=int, typename U=int>  // 默认模板
auto add(T x, U y){
  return x + y;
}


template<typename T>                   // 变长模板实例
void printf(T value) {
    std::cout << value << " "; 
}
template<typename T, typename... Args>
void printf(T value, Args... args) {
    std::cout << value << " ";
    printf(args...);
}

int main(int argc, char const* argv[])
{
  std::vector<std::vector<int>> vec = {{1,2},{3,4}}; // '>>' 例子
  for(auto &i : vec)
    for(auto &j : i)
      std::cout << j << " ";  // output: 1 2 3 4
  std::cout << std::endl;
  
  SuckType<bool, int, -1> obj;
  obj.Visit();   // output: 0 -1
  
  NewType<int> obj2;
  obj2.Visit();  // output: 1 3

  std::cout << add(1,2) << " ";
  std::cout << add(1.5,2) << std::endl; // output: 3.5

  printf(1, 2, 3.5, 'a');    // output: 1 2 3.5 a

  return 0;
}
