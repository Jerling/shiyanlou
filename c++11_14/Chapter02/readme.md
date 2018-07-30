# 1. 语言可用性的强化
## 1.1 nullptr 与 constexpr
### 1.1.1 nullptr
`nullptr` 出现的目的是为了替代 `NULL`。传统c++会把`NULL`、`0`看成是同一种东西，
这主要取决于编译器如何定义 `NULL`, 比如有的会将 `NULL`定义为`((void *)0)`,有些
直接定义为0。  
c++ 不允许直接将 `void *`隐式转换到其他类型，但如果是`NULL`被定义为`((void *)0)`,
那么当编译
```cpp
char *ch = NULL
```
时，`NULL`只好被定义为`0`。而这依然会产生问题，导致 c++ 中重载特性混乱，如：
```cpp
void foo(char *);
void foo(int);
```
对于这两个函数来说，如果 `NULL` 又被定义为了 `0` 那么 `foo(NULL)`; 这个语句将会去调用 `foo(int)`，从而导致代码违反直观。
为了解决这个问题，`C++11` 引入了 `nullptr` 关键字，专门用来区分空指针、`0`。`nullptr` 的类型为 `nullptr_t`，能够隐式的转换为任何指针或成员指针的类型，也能和他们进行相等或者不等的比较。  
如下例子：
```cpp
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
```
```cpp
null is 0
call foo(int)
call foo(char*)
```
因此，当需要使用`NULL`时，直接使用`nullptr`。
### 1.1.2 constexpr
c++ 已经具备常数表达式的概念，如 `1+2,3*4`这种表达式总会产生相同的下结果且无副作用，
若编译器能够在编译时就把这些表达式直接优化并植入到程序运行时，将能增加程序的性能。
一个显著的例子是在数组的定义阶段：
```cpp
#include <iostream>

#define LEN 10

int len_foo(){
  return 5;
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
  return 0;
}
```
在c++11之前，在常量表达式中使用的变量必须声明为`const`, `len_2`被定义为常量，
因此`len_2+5`是一个常量表达式，对于`arrr_5`来说，c++98这前的编译器无法得知`len_foo()`
在运行期实际上返回一个常数，这也就导致了非法的产生。 
c++11提供了`constexpr`让用户电焊工的声明函数或对象构造函数在编译器会成
为常数，它会明确告诉编译器应该去验证`len_foo()`在编译器就应该是一个常数。
此外，`constexpr`的函数可以使用递归：
```cpp
constexpr int fibonacci(const int n){
  return n==1 || n==2 ? 1 : fibonacci(n-1) + fibonacci(n-2);
}
```
从c++14开始，`constexpr`函数可以在内部使用局部变量、循环和分支简单句，如下（c++11通不过）：
```cpp
constexpr int fibonacci(const int n){
  if(n == 1) return 1;
  if(n == 2) return 1;
  return fibonacci(n-1) + fibonacci(n-2);
}
```
## 1.2. 类型推导
在传统c和c++中，参数必须明确定义，这会拖慢开发效率，代码量也大。  
c++11 引入`auto`和`decltype`这两个关键字实现类型推导，让编译器来操心变量的类型。
### 1.2.1 auto
`auto` 在很早以前就有了，但只作为一个存储类型的指示符存在，与`register`并存。  
使用`auto`进行类型推导的一个最为常见的就是迭代器，以前是这样写的：
```cpp
for(std::vector<int>::const_iterator itr = vec.cbegin(); itr != vec.cend(); ++itr);
```
而有了 `auto`,我们可以这样写：
```cpp
for(auto itr = vec.cbegin(); itr != vec.cend(); ++itr);
```
还有一些常见的用法：
```cpp
auto i = 5;
auto a_i = new auto(10);
auto a_d = new auto(10.0);
```
类型输出：
```cpp
type(i) 		:i
type(a_i) 	:Pi
type(a_d) 	:Pd
```
> **注意** ： `auto`不能用于函数传参(考虑重载，应该使用模板)：
```cpp
int add(auto x, auto y);   // 这是错误的
```
> 此外，`auto`也不能用于推导数组类型：
```cpp
#include <iostream>
int main(int argc, char const* argv[])
{
  auto i = 5;
  int arr[10] = {0};
  auto auto_arr = arr;
  auto auto_arr2[10] = arr;
  return 0;
}
```
```cpp
--------------------  
c++11_14/Chapter02/test.cpp: In function ‘int main(int, const char**)’:  
c++11_14/Chapter02/test.cpp:7:20: error: ‘auto_arr2’ declared as array of ‘auto’  
   auto auto_arr2[10] = arr;  
                     ^
```


