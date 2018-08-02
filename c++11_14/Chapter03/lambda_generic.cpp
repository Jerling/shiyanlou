#include <iostream>

void learn_lambda_generic() {
  auto generic = [](auto x, auto y){
    return x + y;
  };
  std::cout << "generic(1, 2) = " << generic(1, 2) << std::endl;
  std::cout << "generic(1.1, 2.2) = " << generic(1.1, 2.2) << std::endl;
  std::cout << "generic(a, 1) = " << (char)generic('a', 1) << std::endl;
}

int main(int argc, char const* argv[])
{
  learn_lambda_generic();
  return 0;
}
