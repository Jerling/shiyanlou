# 2. 语言可用性的强化
## 2.1 nullptr 与 constexpr
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
### 2.1.2 constexpr
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
## 2.2. 类型推导
在传统c和c++中，参数必须明确定义，这会拖慢开发效率，代码量也大。  
c++11 引入`auto`和`decltype`这两个关键字实现类型推导，让编译器来操心变量的类型。
### 2.2.1 auto
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

### 2.2.2. decltype
`decltype` 关键字是为了解决 `auto` 关键字只能对就是进行类型推导的缺陷而出现的，
它的用法和`sizeof`很相似：
```cpp
decltype(表达式);
```
有时候，我们可能需要计算某个表达式的类型，如：
```cpp
auto x = 1;
auto y = 2;
decltype(x+y) z;
```
### 2.2.3.尾返回类型、auto和decltype配合
考虑`auto`是否能用于推导函数的返回类型：
```cpp
template<typename T, typename T, typename U>
R add(T x, U y){
  return x+y;
}
```
> typename 和 class 在模板中没有区别， 在typename 这个关键字出现之前，都用class。

在上面的代码中，必须指定返回类型，但是我们并不知道`add()`这个函数会做什么，会
返回什么类型。于是就可能有下面这种写法：
```cpp
decltype(x+y) add(T x, U y);
```
但这样无法通过编译器，因为编译器读到`decltype(x+y)`时。`x`和`y`还未定义。
因此在c++11中引入尾返回类型(trailing return type),利用`auto`关键字将返回类型后置。
```cpp
template<typename T, typename U>
auto add(T x, U y) -> decltype(x+y){
  return x+y;
}
```
当然在c++14中就可以直接使用 `auto` 了。
```cpp
template<typename T, typename U>
auto add(T x, U y){ 
  return x+y;
}
```

## 2.3. 区间迭代
### 2.3.1 基于范围的 `for` 循环
c++11引入基于范围的迭代，就可以写出类似python的简洁语句
```cpp
int array[] = {1,2,3,4,5};
for(auto &x : array){
  visit(x);
}
```
值得注意的是，以上写法可用于各种容器，如：
```cpp
std::vector<int> vec(5, 100);
for(auto &i : vec){
  visit(i);
}
```

## 2.4. 初始化列表
初始化是一个非常重要的语言特性，最常见的就是对对象进行初始化。在传统 C++ 中，不同的对象有着不同的初始化方法，例如普通数组、POD （plain old data，没有构造、析构和虚函数的类或结构体）类型都可以使用 `{}` 进行初始化，也就是我们所说的初始化列表。而对于类对象的初始化，要么需要通过拷贝构造、要么就需要使用 `()` 进行。这些不同方法都针对各自对象，不能通用。
```cpp
int arr[3] = {1,2,3};   // 列表初始化

class Foo {
private:
    int value;
public:
    Foo(int) {}
};

Foo foo(1);             // 普通构造初始化
```
为了解决这个问题，C++11 首先把初始化列表的概念绑定到了类型上，并将其称之为 `std::initializer_list`，允许构造函数或其他函数像参数一样使用初始化列表，这就为类对象的初始化与普通数组和 POD 的初始化方法提供了统一的桥梁，例如：
```cpp
#include <initializer_list>

class Magic {
public:
    Magic(std::initializer_list<int> list) {}
};

Magic magic = {1,2,3,4,5};
std::vector<int> v = {1, 2, 3, 4};
```
这种构造函数被叫做初始化列表构造函数，具有这种构造函数的类型将在初始化时被特殊关照。  

初始化列表除了用在对象构造上，还能将其作为普通函数的形参，例如：
```cpp
void func(std::initializer_list<int> list) {
    return;
}
func({1,2,3});
```
其次，C++11 提供了统一的语法来初始化任意的对象，例如：
```cpp
struct A {
    int a;
    float b;
};
struct B {

    B(int _a, float _b): a(_a), b(_b) {}
private:
    int a;
    float b;
};

A a {1, 1.1};    // 统一的初始化语法
B b {2, 2.2};
```

## 2.5. 模板增强
### 2.5.1. 外部模板
传统 C++ 中，模板只有在使用时才会被编译器实例化。换句话说，只要在每个编译单元（文件）中编译的代码中遇到了被完整定义的模板，都会实例化。这就产生了重复实例化而导致的编译时间的增加。并且，我们没有办法通知编译器不要出发模板实例化。

C++11 引入了外部模板，扩充了原来的强制编译器在特定位置实例化模板的语法，使得能够显式的告诉编译器何时进行模板的实例化：
```cpp
template class std::vector<bool>;            // 强行实例化
extern template class std::vector<double>;  // 不在该编译文件中实例化模板 
```
### 2.5.2. 尖括号 ">"
在传统 C++ 的编译器中，`>>`一律被当做右移运算符来进行处理。但实际上我们很容易就写出了嵌套模板的代码：
```cpp
std::vector<std::vector<int>> wow;
```
这在传统C++编译器下是不能够被编译的，而 C++11 开始，连续的右尖括号将变得合法，并且能够顺利通过编译。

### 2.5.3. 类型别名模板
在了解类型别名模板之前，需要理解『模板』和『类型』之间的不同。仔细体会这句话：**模板是用来产生类型的**。在传统 C++中，`typedef` 可以为类型定义一个新的名称，但是却没有办法为模板定义一个新的名称。因为，模板不是类型。例如：
```cpp
template< typename T, typename U, int value>
class SuckType {
public:
    T a;
    U b;
    SuckType():a(value),b(value){}
};
template< typename U>
typedef SuckType<std::vector<int>, U, 1> NewType; // 不合法
```
C++11 使用 `using` 引入了下面这种形式的写法，并且同时支持对传统 `typedef` 相同的功效：

> 通常我们使用 `typedef` 定义别名的语法是：`typedef` 原名称 新名称;，但是对函数指针等别名的定义语法却不相同，这通常给直接阅读造成了一定程度的困难。
```cpp
typedef int (*process)(void *);  // 定义了一个返回类型为 int，参数为 void* 的函数指针类型，名字叫做 process
using process = int(*)(void *); // 同上, 更加直观

template <typename T>
using NewType = SuckType<int, T, 1>;    // 合法
```
### 2.5.4.默认模板参数
如下定义了一个加法函数：
```cpp
template<typename T, typename U>
auto add(T x, U y) -> decltype(x+y) {
    return x+y
}
```
但在使用时发现，要使用 add，就必须每次都指定其模板参数的类型。

在 C++11 中提供了一种便利，可以指定模板的默认参数：

template<typename T = int, typename U = int>
auto add(T x, U y) -> decltype(x+y) {
    return x+y;
}
### 2.5.5 变长参数模板
模板一直是 C++ 所独有的黑魔法之一。在 C++11 之前，无论是类模板还是函数模板，都只能按其指定的样子，接受一组固定数量的模板参数；而 C++11 加入了新的表示方法，允许任意个数、任意类别的模板参数，同时也不需要再定义时将参数的个数固定。
```cpp
template<typename... Ts> class Magic;
```
模板类 Magic 的对象，能够接受不受限制个数的 typename 作为模板的形式参数，例如下面的定义：
```cpp
class Magic<int, 
            std::vector<int>, 
            std::map<std::string, 
                     std::vector<int>>> darkMagic;
```
既然是任意形式，所以个数为0的模板参数也是可以的：`class Magic<> nothing`;。

如果不希望产生的模板参数个数为0，可以手动的定义至少一个模板参数：
```cpp
template<typename Require, typename... Args> class Magic;
```
变长参数模板也能被直接调整到到模板函数上。传统 C 中的 `printf` 函数，虽然也能达成不定个数的形参的调用，但其并非类别安全。而 C++11 除了能定义类别安全的变长参数函数外，还可以使类似 `printf` 的函数能自然地处理非自带类别的对象。除了在模板参数中能使用 ``...`` 表示不定长模板参数外，函数参数也使用同样的表示法代表不定长参数，这也就为我们简单编写变长参数函数提供了便捷的手段，例如：
```cpp
template<typename... Args> void printf(const std::string &str, Args... args);
```
那么我们定义了变长的模板参数，如何对参数进行解包呢？

首先，我们可以使用 `sizeof...` 来计算参数的个数，：
```cpp
template<typename... Args>
void magic(Args... args) {
    std::cout << sizeof...(args) << std::endl;
}
```
我们可以传递任意个参数给 magic 函数：
```cpp
magic();        // 输出0
magic(1);       // 输出1
magic(1, "");   // 输出2
```
其次，对参数进行解包，到目前为止还没有一种简单的方法能够处理参数包，但有两种经典的处理手法：

1. 递归模板函数

递归是非常容易想到的一种手段，也是最经典的处理方法。这种方法不断递归的向函数传递模板参数，进而达到递归遍历所有模板参数的目的：
```cpp
#include <iostream>
template<typename T>
void printf(T value) {
    std::cout << value << std::endl;
}
template<typename T, typename... Args>
void printf(T value, Args... args) {
    std::cout << value << std::endl;
    printf(args...);
}
int main() {
    printf(1, 2, "123", 1.1);
    return 0;
}
```
2. 初始化列表展开

这个方法需要之后介绍的知识，读者可以简单阅读以下，将这个代码段保存，在后面的内容了解过了之后再回过头来阅读此处方法会大有收获。

递归模板函数是一种标准的做法，但缺点显而易见的在于必须定义一个终止递归的函数。

这里介绍一种使用初始化列表展开的黑魔法：

// 编译这个代码需要开启 -std=c++14
// 因为版本原因，实验环境中的 g++ 尚不支持此特性，此处可以使用 clang++ 替代 g++
```cpp
template<typename T, typename... Args>
auto print(T value, Args... args) {
    std::cout << value << std::endl;
    return std::initializer_list<T>{([&] {
        std::cout << args << std::endl;
    }(), value)...};
}
int main() {
    print(1, 2.1, "123");
    return 0;
}
```
在这个代码中，额外使用了 C++11 中提供的初始化列表以及 Lambda 表达式的特性（下一节中将提到），而 `std::initializer_list` 也是 C++11 新引入的容器（以后会介绍到）。

通过初始化列表，`(lambda 表达式, value)...` 将会被展开。由于逗号表达式的出现，首先会执行前面的 `lambda` 表达式，完成参数的输出。唯一不美观的地方在于如果不使用 return 编译器会给出未使用的变量作为警告。

> 事实上，有时候我们虽然使用了变参模板，却不一定需要对参数做逐个遍历，我们可以利用 `std::bind` 及完美转发等特性实现对函数和参数的绑定，从而达到成功调用的目的。

> 关于这方面的使用技巧，可以通过项目课：100 行 C++ 代码实现线程池 进行进一步巩固学习。

## 2.6. 面向对象增强
### 2.6.1.  委托构造
C++11 引入了委托构造的概念，这使得构造函数可以在同一个类中一个构造函数调用另一个构造函数，从而达到简化代码的目的：
```cpp
class Base {
public:
    int value1;
    int value2;
    Base() {
        value1 = 1;
    }
    Base(int value) : Base() {  // 委托 Base() 构造函数
        value2 = 2;
    }
};

int main() {
    Base b(2);
    std::cout << b.value1 << std::endl;
    std::cout << b.value2 << std::endl;
}
```
### 2.6.2 继承构造
在传统 C++ 中，构造函数如果需要继承是需要将参数一一传递的，这将导致效率低下。C++11 利用关键字 using 引入了继承构造函数的概念：
```cpp
class Base {
public:
    int value1;
    int value2;
    Base() {
        value1 = 1;
    }
    Base(int value) : Base() {                          // 委托 Base() 构造函数
        value2 = 2;
    }
};
class Subclass : public Base {
public:
    using Base::Base;  // 继承构造
};
int main() {
    Subclass s(3);
    std::cout << s.value1 << std::endl;
    std::cout << s.value2 << std::endl;
}
```
### 2.6.3. 显式虚函数重载
在传统 C++中，经常容易发生意外重载虚函数的事情。例如：
```cpp
struct Base {
    virtual void foo();
};
struct SubClass: Base {
    void foo();
};
```
SubClass::foo 可能并不是程序员尝试重载虚函数，只是恰好加入了一个具有相同名字的函数。另一个可能的情形是，当基类的虚函数被删除后，子类拥有旧的函数就不再重载该虚拟函数并摇身一变成为了一个普通的类方法，这将造成灾难性的后果。

C++11 引入了 override 和 final 这两个关键字来防止上述情形的发生。

#### 2.6.3.1 override
当重载虚函数时，引入 override 关键字将显式的告知编译器进行重载，编译器将检查基函数是否存在这样的虚函数，否则将无法通过编译：
```cpp
struct Base {
    virtual void foo(int);
};
struct SubClass: Base {
    virtual void foo(int) override; // 合法
    virtual void foo(float) override; // 非法, 父类没有此虚函数
};
```
#### 2.6.3.2 final
final 则是为了防止类被继续继承以及终止虚函数继续重载引入的。
```cpp
struct Base {
        virtual void foo() final;
};
struct SubClass1 final: Base {
};                  // 合法

struct SubClass2 : SubClass1 {
};                  // 非法, SubClass 已 final

struct SubClass3: Base {
        void foo(); // 非法, foo 已 final
};
```
### 2.6.4 显式禁用默认函数
在传统 C++ 中，如果程序员没有提供，编译器会默认为对象生成默认构造函数、复制构造、赋值算符以及析构函数。另外，C++ 也为所有类定义了诸如 new delete 这样的运算符。当程序员有需要时，可以重载这部分函数。

这就引发了一些需求：无法精确控制默认函数的生成行为。例如禁止类的拷贝时，必须将赋值构造函数与赋值算符声明为 private。尝试使用这些未定义的函数将导致编译或链接错误，则是一种非常不优雅的方式。

并且，编译器产生的默认构造函数与用户定义的构造函数无法同时存在。若用户定义了任何构造函数，编译器将不再生成默认构造函数，但有时候我们却希望同时拥有这两种构造函数，这就造成了尴尬。

C++11 提供了上述需求的解决方案，允许显式的声明采用或拒绝编译器自带的函数。例如：
```cpp
class Magic {
public:
    Magic() = default;  // 显式声明使用编译器生成的构造
    Magic& operator=(const Magic&) = delete; // 显式声明拒绝编译器生成构造
    Magic(int magic_number);
}
```
## 2.7. 强类型枚举
在传统 C++中，枚举类型并非类型安全，枚举类型会被视作证书，则会让两种完全不同的枚举类型可以进行直接的比较（虽然编译器给出了检查，但并非所有），甚至枚举类型的枚举值名字不能相同，这不是我们希望看到的结果。

C++11 引入了枚举类（`enumaration class`），并使用 `enum class` 的语法进行声明：
```cpp
enum class new_enum : unsigned int {
    value1,
    value2,
    value3 = 100,
    value4 = 100
};
```
这样定义的枚举实现了类型安全，首先他不能够被隐式的转换为整数，同时也不能够将其与整数数字进行比较，更不可能对不同的枚举类型的枚举值进行比较。但相同枚举值之间如果指定的值相同，那么可以进行比较：
```cpp
if (new_enum::value3 == new_enum::value4) {
    // 会输出
    std::cout << "new_enum::value3 == new_enum::value4" << std::endl;
}
```
在这个语法中，枚举类型后面使用了冒号及类型关键字来指定枚举中枚举值的类型，这使得我们能够为枚举赋值（未指定时将默认使用 int）。

而我们希望获得枚举值的值时，将必须显式的进行类型转换，不过我们可以通过重载 << 这个算符来进行输出，可以收藏下面这个代码段：
```cpp
#include <iostream>
template<typename T>
std::ostream& operator<<(typename std::enable_if<std::is_enum<T>::value, std::ostream>::type& stream, const T& e)
{
    return stream << static_cast<typename std::underlying_type<T>::type>(e);
}
```
这时，下面的代码将能够被编译：
```cpp
std::cout << new_enum::value3 << std::endl
```
## 2.8. 总结
本节介绍了 C++11/14 中对语言可用性的增强，其中笔者认为最为重要的几个特性是几乎所有人都需要了解并熟练使用的：

1. auto 类型推导
2. 范围 for 迭代
3. 初始化列表
4. 变参模板
