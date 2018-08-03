#include <iostream>
#include <vector>
#include <string>

class A {
  
  public:
    int *pointer;
    A() :pointer(new int(1)){
      std::cout << "构造" << std::endl;
    };
    // 无意义的对象拷贝
    A(A& a):pointer(new int(*a.pointer)){
      std::cout << "拷贝" << std::endl;
    }
    A(A&& a):pointer(a.pointer) {
      a.pointer = nullptr;
      std::cout << "移动" << std::endl;
    }
    ~A(){
      std::cout << "析构" << std::endl;
      delete pointer;
    }
};
// 防止编译器优化
A return_value(bool test){
  A a, b;
  if (test) {
    return a;
  } else {
    return b;
  }
}

int main(int argc, char const* argv[])
{
  A obj = return_value(false);
  std::cout << "obj:" << std::endl;
  std::cout << obj.pointer << std::endl;
  std::cout << *obj.pointer << std::endl;
  
  A obj_1 = obj;          // 执行拷贝构造函数
  std::cout << "obj_1:" << std::endl;
  std::cout << obj_1.pointer << std::endl;
  std::cout << *obj_1.pointer << std::endl;

  A obj_2 = std::move(obj); // 拷贝构造函数
  std::cout << "obj_2:" << std::endl;
  std::cout << obj_2.pointer << std::endl;
  std::cout << *obj_2.pointer << std::endl;

  std::cout << "obj:" << std::endl;
  std::cout << "po:" << obj.pointer << std::endl;     // 输出 0 -> nullptr
  // std::cout << "*:" << *obj.pointer << std::endl;  // 这句虽然没报错，但是取不出值，后面代码无法运行

  // 系统例子
  std::string str = "Hello World";
  std::vector<std::string> v;
  
  // 将使用 push_back(const T&&), 不会出现拷贝行为
  // 而整个字符串会被移动到 vector 中，所以有时候 std::move 会用来减少拷贝出现的开销
  // 这步操作后, str 中的值会变为空
  v.push_back(str);
  std::cout << "str:" << str << std::endl;

  v.push_back(std::move(str));
  std::cout << "str:" << str << std::endl;
  return 0;
}
