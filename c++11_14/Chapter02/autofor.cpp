#include <iostream>
#include <vector>

int main(int argc, char const* argv[])
{
  std::vector<int> vec(5, 100);
  for(auto &i : vec)
    std::cout << i << std::endl;
  return 0;
}
