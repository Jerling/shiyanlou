#include <iostream>
#include <list>
#include <initializer_list>

// 普通类初始化
class Foo {
  private:
    int value;
  public:
    Foo(int);
    auto getValue(){return value;}
};
Foo::Foo(int i) {
  value = i; 
}

// 初始化列表初始化
class Magic {
  private:
    std::list<int> list_; 
  public:
    Magic(std::initializer_list<int>);
    auto getValue(){return list_;}
    void visit() const{
      std::cout << "Magic:\t";
      for(auto &i : list_)
        std::cout << i << ' ';
      std::cout << std::endl;
    }
};
Magic::Magic(std::initializer_list<int> list) {
  list_ = list;
}

// 初始化列表函数用于函数参数
void func(std::initializer_list<int> list){
  std::cout << "func:\t";
  for(auto &i : list)
    std::cout << i << " ";
  std::cout << std::endl;
}

struct A {
  int a;
  float b;
};
struct B {
  B(int _a, float _b):a(_a), b(_b){}
  void visit() const {
    std::cout << "B.a: " << a << "\tB.b : " << b << std::endl;
  }
  private:
    int a;
    float b;
};

int main(int argc, char const* argv[])
{
  int arr[5] = {1,2,3,4,5};  // 列表初始化

  Foo foo(arr[0]);           // 普通构造器初始化
  std::cout << "foo:\t" << foo.getValue() << std::endl;

  Magic magic = {1,2,3,4,5}; // 初始化列表初始化
  magic.visit();

  func({1,2,3,4,5});         // 函数参数列表化

  A a{1,1.1};                // 统一初始化对象
  B b{2,2.2};
  std::cout << "A.a: " << a.a << "\tA.b : " << a.b << std::endl;
  b.visit();

  return 0;
}
