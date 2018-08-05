#include <iostream>
#include <memory>

class A;
class B;

class A{
    public:
    // A 或 B 中至少有一个使用 weak_ptr
    // std::shared_ptr<B> pointer; // A、B都不会销毁
    std::weak_ptr<B> pointer;
    ~A(){
      std::cout << "A 被销毁" << std::endl;
    }
};

class B {
  public:
    std::shared_ptr<A> pointer;
    ~B(){
      std::cout << "B 被销毁" << std::endl;
    }
};

int main(void)
{
  std::shared_ptr<A> a  = std::make_shared<A>();
  std::shared_ptr<B> b = std::make_shared<B>();
  a->pointer = b;
  b->pointer = a;

  return 0;
}
