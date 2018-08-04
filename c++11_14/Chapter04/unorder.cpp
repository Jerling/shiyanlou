#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>

void visit_m(auto u){
  for(const auto n : u)
    std::cout << "Key:[" << n.first << "]\tValue:[" << n.second << "] ";
  std::cout  << std::endl;
}

void visit_s(auto u){
  for(const auto n : u)
    std::cout << n << " "; 
  std::cout  << std::endl;
}

int main(int argc, char const* argv[])
{
  std::unordered_map<int, std::string> u = {
    {1, "a"},
    {3, "c"},
    {2, "b"}
  };
  std::map<int, std::string> v = {
    {1, "a"},
    {3, "c"},
    {2, "b"}
  };
  std::cout << "std::unordered_map:" << std::endl;
  visit_m(u);
  std::cout << "std::map:" << std::endl;
  visit_m(v);

  std::set<int> st = {1,1,3,5,2,3,5};
  std::unordered_set<int> ust = {1,1,3,5,2,3,5};
  std::cout << "std::unordered_set:" << std::endl;
  visit_s(ust);
  std::cout << "std::set:" << std::endl;
  visit_s(st);


  return 0;
}
