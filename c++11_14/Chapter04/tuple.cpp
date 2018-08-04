#include <iostream>
#include <tuple>

auto get_student(int id){
  if (id == 0) {
    return std::make_tuple(3.8, 'A', "张三");
  }else if(id == 1){
    return std::make_tuple(2.9, 'C', "李四");
  }
  return std::make_tuple(1.7, 'D', "王五");
}

int main(void)
{
  auto student = get_student(0);
  std::cout << "ID: 0,"
    << "GPA:" << std::get<0>(student) << ","
    << "成绩:" << std::get<1>(student) << ","
    << "姓名:" << std::get<2>(student) << std::endl;

  double gpa;
  char grade;
  std::string name;
  std::tie(gpa, grade, name) = get_student(1);
  std::cout << "ID: 1,"
    << "GPA:" << gpa << ","
    << "成绩:" << grade << ","
    << "姓名:" << name << std::endl;

  std::tuple<std::string, double, double, int> t("123", 4.5, 6.7, 8);
  std::cout << std::get<std::string>(t) << std::endl;
  // std::cout << std::get<double>(t) << std::endl;   // 非法, 引发编译期错误, 如果只有一个double则可以
  std::cout << std::get<3>(t) << std::endl;

  return 0;
}
