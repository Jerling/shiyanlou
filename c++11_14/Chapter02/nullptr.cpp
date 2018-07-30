#include <iostream>

void foo(char*);
void foo(int);

int main(int argc, char const* argv[])
{
  if (NULL == (void*)0) {
    std::cout << "NULL is 0" <<std::endl;
  }
  else {
    std::cout << "NULL is not 0" << std::endl;
  }
  foo(0);
  // foo(NULL); 编译无法通过
  foo(nullptr);
  return 0;
}

void foo(char *ch){
  std::cout << "call foo(char*)" << std::endl;
}

void foo(int i){
  std::cout << "call foo(int)" << std::endl;
}
