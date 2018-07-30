#include <iostream>

#define LEN 10

int len_foo(){
  return 5;
}


constexpr int fibonacci_1(const int n){
  return n==1 || n==2 ? 1 : fibonacci_1(n-1) + fibonacci_1(n-2);
}

constexpr int fibonacci_2(const int n){
  if(n == 1) return 1;
  if(n == 2) return 1;
  return fibonacci_2(n-1) + fibonacci_2(n-2);
}

int main(int argc, char const* argv[])
{
  char arr_1[10];
  char arr_2[LEN];
  int len = 5;
  char arr_3[len+5];  // 非法
  const int len_2 = 10;
  char arr_4[len_2+5];
  char arr_5[len_foo() + 5]; // 非法
  std::cout << "fibonacci_1(5): " << fibonacci_1(5) << std::endl;
  // std::cout << "fibonacci_2(5): " << fibonacci_2(5) << std::endl; // c++11无法通过，c++14可以
  return 0;
}
