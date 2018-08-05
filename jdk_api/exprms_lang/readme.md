# 1. java.lang包
## 1.1. 知识点
- 包装类
- String 类
- Math 类
- Class 类
- Object 类

## 1.2. Java API 简介
Java 的核心 API 是非常庞大的。所谓的 API 就是一些已经写好、可直接调用的类库。Java 里有非常庞大的 API，其中有一些类库是必须得掌握的，只有熟练掌握了 Java 一些核心的 API，才能更好的使用 Java。
![](https://doc.shiyanlou.com/document-uid18510labid1118timestamp1500451929664.png/wm)

在程序中，java.lang 包并不需要像其他包一样需要`import`关键字进行引入。系统会自动加载，可以直接取用其中的所有类。

## 1.3. java.lang 包装类
java 是一门面向对象的语言，类将方法和属性封装起来，这样就可以创建和处理相同方法和属性的对象了。但是 java 中的基本数据类型却不是面向对象的，不能定义基本类型的对象。想像处理对象的方式处理基本类型的数据，调用一些方法怎么办呢？

其实 java 为每个基本类型都提供了包装类：

原始数据类型      | 包装类
------------------|----------
byte（字节）      | Byte
char（字符）      | Character
int（整型）       | Integer
long （长整型）   | Long
float（浮点型）   | Float
double （双精度） | Double
boolean （布尔）  | Boolean
short（短整型）   | Short

在这八个类名中，除了Integer和Character类以后，其它六个类的类名和基本数据类型一致，只是类名的第一个字母大写。

### 1.3.1. Integer 类
java.lang 包中的 `Integer` 类、`Long` 类和 `Short` 类都是 `Number` 的子类，他们的区别在于不同子类里面封装着不同的数据类型，比如 `Integer` 类包装了一个基本类型 `int`。其包含的方法基本相同。

我们以 `Integer` 类为例。 `Integer` 构造方法有两种：

1. `Integer(int value)` ，以 `int` 型变量作为参数创建 `Integer` 对象。例如`Integer a = new Integer(10);`
2. `Integer(String s)` ，以 `String` 型变量作为参数创建 `Integer` 对象，例如`Integer a = new Integer("10");`

下面列举一下 Integer 的常用方法

方法                              | 返回值  | 功能描述
----------------------------------|---------|-------------------------------
byteValue()                       | byte    | 以 byte 类型返回该 Integer 的值
CompareTo(Integer anotherInteger) | int     | 在数字上比较 Integer 对象。如果这两个值相等，则返回0；如果调用对象的数值小于 anotherInteger 的数值，则返回负值；如果调用对象的数值大于 anotherInteger 的数值，则返回正值
equals(Object IntegerObj)         | boolean | 比较此对象与指定对象是否相等
intValue()                        | int     | 以 int 型返回此 Integer 对象
shortValue()                      | short   | 以 short 型返回此 Integer 对象
longValue()                       | long    | 以 long 型返回此 Integer 对象
floatValue()                      | float   | 以 float 型返回此 Integer 对象
doubleValue()                     | double  | 以 double 型返回此 Integer 对象
toString()                        | String  | 返回一个表示该 Integer 值的 String 对象
valueOf(String str)               | Integer | 返回保存指定的 String 值的 Integer 对象
parseInt(String str)              | int     | 将字符串参数作为有符号的十进制整数进行解析

例子：
```java
public class IntegerTest {
    public static void main(String[] args){
        //初始化一个 Integer 类实例
        Integer a = new Integer("10");
        //初始化一个 Integer 类实例
        Integer b = new Integer(11);
        //判断两个数的大小
        System.out.println(a.compareTo(b));
        // 判断两个实例是否相等
        System.out.println(a.equals(b));
        //将 a 转换成 float 型数
        float c = a.floatValue();
        System.out.println(c);

        String d = "10101110";
        //将字符串转换为数值
        //parseInt(String str) 和 parseInt(String str,int radix) 都是类方法，由类来调用。后一个方法则实现将字符串按照参数 radix 指定的进制转换为 int，
        int e = Integer.parseInt(d, 2);
        System.out.println(e);
    }
}
```
输出结果：
```java
  a = 10
  b = 11
  a.compareTo(b): -1
  a.equals(b): false
  float(a) : 10.0
  10101110 = 174
```

### 1.3.2. Character 类
`Character` 类在对象中包装一个基本类型 `char` 的值。`Character` 类型的对象包含类型为 `char` 的单个字段。

`Character` 包装类的常用方法：

方法                              | 返回值  | 说明
----------------------------------|---------|------------------
isDigit(char ch)                  | boolean | 确定字符是否为数字
isLetter(char ch)                 | boolean | 确定字符是否为字母
isLowerCase(char ch)              | boolean | 确定字符是否为小写字母
isUpperCase(char ch)              | boolean | 确定字符是否为大写字母
isWhitespace(char ch)             | boolean | 确定字符是否为空白字符
isUnicodeIdentifierStart(char ch) | boolean | 确定是否允许将指定字符作为 Unicode 标识符中的首字符

实例：
```java
public class Charactertest {
  public static void main(String args[]) {
    int count;
    char[] values = {'*', '_', '%', '8', 'L', 'l', ' '};
    for (count = 0; count < values.length; count++) {
      if (Character.isDigit(values[count])) {
        System.out.println(values[count] + " is a digit");
      }
      if (Character.isLetter(values[count])) {
        System.out.println(values[count] + " is a letter");
      }
      if (Character.isUpperCase(values[count])) {
        System.out.println(values[count] + " is a upperletter");
      }
      if (Character.isLowerCase(values[count])) {
        System.out.println(values[count] + " is a lowerletter");
      }
      if (Character.isUnicodeIdentifierStart(values[count])) {
        System.out.println(values[count] + " is a first sign of unicode");
      }
      if (Character.isWhitespace(values[count])) {
        System.out.println(values[count] + " is a whitespace"); 
      }
    }
  }
}
```
输出结果：
```java
  8 is a digit
  L is a letter
  L is a upperletter
  L is a first sign of unicode
  l is a letter
  l is a lowerletter
  l is a first sign of unicode
    is a whitespace
```
### 1.3.3 Boolean 类
`Boolean` 类将基本类型为 `boolean` 的值包装在一个对象中。一个 `Boolean` 类型的对象只包含一个类型为 `boolean` 的字段。

`Boolean` 类的构造方法也有两个：

1. `Boolean(boolean value)`，创建一个表示 `value` 参数的 `Boolean` 对象，如`Boolean b = new Boolean(true)`
2. `Boolean(String s)`，如果 `String` 参数不为 `null` 且在忽略大小写时等于 "`true`",创建一个表示 `true` 值的 `Boolean` 对象，如`Boolean b = new Boolean("ok")`，为 `false`。
Boolean 包装类的常用方法：

方法                   | 返回值  | 说明
-----------------------|---------|------------------------------------------
booleanValue()         | boolean | 将 Boolean 对象的值以对应的 boolean 值返回
equals(Object obj)     | boolean | 判断调用该方法的对象与 obj 是否相等。当且仅当参数不是 null，而且与调用该方法的对象一样都表示同一个 boolean 值的 Boolean 对象时，才返回 true
parseBoolean(String s) | boolean | 将字符串参数解析为 boolean 值
toString()             | String  | 返回表示该 boolean 值的 String 对象
valueOf(String s)      | Boolean | 返回一个用指定得字符串表示值的 boolean 值

实例：
```java
public class Booleantest {
  public static void main(String args[]) {
    Boolean a = new Boolean(true);
    System.out.println("a is " + a);
    Boolean b = new Boolean("true");
    Boolean c = new Boolean("OK");
    System.out.println("b is " + b);
    System.out.println("c is " + c);
    System.out.println("a.booleanValue() is " + a.booleanValue());
    System.out.println("a ?= b :" + a.equals(b));
  }
}
```
输出结果：
```java
  a为true
  b为true
  c为false
  a的booleanValue()为true
  a和b相等吗？true
```
其他的参考 Java 类库的手册。

## 1.4. java.lang 类 String
使用 `String` 类来定义一个字符串。字符串是常量，它们的值在创建之后不能更改。字符串缓冲区支持可变的字符串。

`String` 对象的初始化格式有如下两种：

```java
String s0 = "abc";

String s1 = new String("abd");
```
`String` 类具有丰富的方法，比如计算字符串的长度、连接字符串、比较字符串、提取字符串等等。

### 1.4.1  计算字符串长度
- length()方法
```java
//方法原型
public int length(){
}
```
- 调用方法：字符串标识符`.length()`; 返回一个`int`类型的整数（字符串中字符数，中文字符也是一个字符）。例如：
```java
String s1 = "abc";
String s2 = "Java语言";
int len1 = s1.length();
int len2 = s2.length();
```
则变量len1的值是3，变量len2的值是6。

### 1.4.2 字符串比较
`equals()` 方法,该方法的作用是判断两个字符串对象的内容是否相同。如果相同则返回`true`，否则返回`false`。

`equals()` 方法比较是从第一字符开始，一个字符一个字符依次比较。

![](https://doc.shiyanlou.com/document-uid79144labid1085timestamp1435503766697.png/wm)

如果想忽略掉大小写关系，比如：`java` 和 `Java` 是一样的，可以调用`equalsIgnoreCase()`方法，其用法与 `equals` 一致，不过它会忽视大小写。

而使用`"=="`比较的是两个对象在内存中存储的地址是否一样。例如: `String s1 = "abc"; String s2 = new String("abc"); boolean b = (s1 == s2);` 则变量`b`的值是`false`，因为`s1`对象对应的地址是`"abc"`的地址，而`s2`使用`new`关键字申请新的内存，所以内存地址和`s1`的`"abc"`的地址不一样，所以获得的值是`false`。

### 1.4.3. 字符串连接
字符串连接有两种方法：

1. 使用`+`，比如`String s = "Hello " + "World!"`

2. 使用 `String` 类的 `concat()` 方法

代码示例：
```java
String s0 = new String("Hello ");
String s1 = "World" + "!";   //+号连接
String s2 = s0.concat(s1); //concat()方法连接
System.out.println(s2);
```
而且使用`+`进行连接，不仅可以连接字符串，也可以连接其他类型。但是要求进行连接时至少有一个参与连接的内容是字符串类型。

### 1.4.4 charAt()方法
`charAt()`方法的作用是按照索引值(规定字符串中第一个字符的索引值是`0`，第二个字符的索引值是`1`，依次类推)，获得字符串中的指定字符。例如：
```java
     String s = "abc";
     char c = s.charAt(1);
```
则变量`c`的值是`'b'`。

### 1.4.5. 字符串常用提取方法
方法                                    | 返回值 | 功能描述
----------------------------------------|--------|----------------------------
indexOf(int ch)                         | int    | 搜索字符 ch 第一次出现的索引
indexOf(String value)                   | int    | 搜索字符串 value 第一次出现的索引
lastIndexOf(int ch)                     | int    | 搜索字符ch最后一次出现的索引
lastIndexOf(String value)               | int    | 搜索字符串 value 最后一次出现的索引
substring(int index)                    | String | 提取从位置索引开始到结束的字符串
substring(int beginindex, int endindex) | String | 提取beginindex和endindex之间的字符串部分
trim()                                  | String | 返回一个前后不含任何空格的调用字符串的副本

> 说明：在字符串中，第一个字符的索引为`0`，子字符串包含`beginindex`的字符，但不包含`endindex`的字符。

实例：
```java
public class Stringtest {
  public static void main(String args[]) {
    String s = new String("Java");
    String m = "java";
    System.out.println("The length of s is " + s.length());
    System.out.println("The length of m is " + s.length());
    System.out.println("equals test s and m : " + s.equals(m));
    System.out.println("equalsIgnoreCase test s and m : " + m.equalsIgnoreCase(s));

    String sm1 = s + m;
    String sm2 = sm1.concat(s);
    System.out.println("s + m : " + sm1);
    System.out.println("sm1.concat(s) : " + sm2);
    System.out.println("The first of s is " + s.charAt(0));
    System.out.println("The first index of a is  " + s.indexOf('a'));
    System.out.println("The first index of va is  " + s.indexOf("va"));
    System.out.println("The first index of a is  " + s.lastIndexOf('a'));
    System.out.println("The first index of va is sm2 " + sm2.lastIndexOf("va"));
    System.out.println("Th substring of 2: is " + sm2.substring(2));
    System.out.println("Th substring of 2-5: is " + sm2.substring(2, 5));

    String str = "first test last";
    System.out.println("trim test : " + str.trim());
  }
}
```
输出结果为： 
```java
  The length of s is 4
  The length of m is 4
  equals test s and m : false
  equalsIgnoreCase test s and m : true
  s + m : Javajava
  sm1.concat(s) : JavajavaJava
  The first of s is J
  The first index of a is  1
  The first index of va is  2
  The first index of a is  3
  The first index of va is sm2 10
  Th substring of 2: is vajavaJava
  Th substring of 2-5: is vaj
  trim test : first test last
```

### 1.4.6. StringBuffer
`String` 类的字符串创建后是不能够改变的。

```java
String s = "Hello ";
s.concat("World!");   //字符串连接
System.out.println(s); //输出s，还是"Hello "
s = s.concat("World!");  //把字符串对象连接的结果赋给了s引用
System.out.println(s);  //输出s，变成了"Hello World!"

/*
上述三条语句其实产生了3个String对象，"Hello "，"World!"，"Hello World!"。第2条语句确实产生了"Hello World"字符串，但是没有指定把该字符串的引用赋给谁，因此没有改变s引用。第3条语句根据不变性，并没有改变"Hello "，JVM创建了一个新的对象，把"Hello "，"World!"的连接赋给了s引用，因此引用变了，但是原对象没变。
*/
```
`String` 的不变性的机制显然会在 `String` 常量内有大量的冗余。比如创建一个循环，使字符`'1'`依次连接到`'n'`，那么系统就得创建 `n+(n-1)` 个 `String` 对象。那有没有可变的 `String` 类呢？

`StringBuffer` 类是可变的。它是 `String` 的对等类，它可以增加和编写字符的可变序列，并且能够将字符插入到字符串中间或附加到字符串末尾（当然是不用创建其他对象的，这里建议大家去看一看 `String` 类与 `StringBuffer` 类的区别，理解一下他们在内存中的存储情况）

`StringBuffer` 的构造方法：

构造方法                       | 说明
-------------------------------|----------------------------------------------------------
StringBuffer()                 | 构造一个其中不带字符的字符串缓冲区，其初始容量为 16 个字符
StringBuffer(CharSequence seq) | 构造一个字符串缓冲区，它包含与指定的 CharSequence 相同的字符
StringBuffer(int capacity)     | 构造一个不带字符，但具有指定初始容量的字符串缓冲区
StringBuffer(String str)       | 构造一个字符串缓冲区，并将其内容初始化为指定的字符串内容

`StringBuffer`类的常用方法：

方法                                  | 返回值       | 功能描述
--------------------------------------|--------------|----------------------------
insert(int offsetm,Object s)          | StringBuffer | 在 offsetm 的位置插入字符串s
append(Object s)                      | StringBuffer | 在字符串末尾追加字符串s
length()                              | int          | 确定 StringBuffer 对象的长度
setCharAt(int pos,char ch)            | void         | 使用 ch 指定的新值设置 pos 指定的位置上的字符
toString()                            | String       | 转换为字符串形式
reverse()                             | StringBuffer | 反转字符串
delete(int start, int end)            | StringBuffer | 删除调用对象中从 start 位置开始直到 end 指定的索引（end-1）位置的字符序列
replace(int start, int end, String s) | StringBuffer | 使用一组字符替换另一组字符。将用替换字符串从 start 指定的位置开始替换，直到 end 指定的位置结束

上面的方法中选择几个：
```java
public class StringBuffertest {
  public static void main(String args[]) {
    StringBuffer s = new StringBuffer("I");
    s.append(" java");
    s.insert(1, " love");
    System.out.println("s : " + s.toString());
    System.out.println("The length of s : " + s.length());
    s.setCharAt(0,'i');
    System.out.println("s : " + s.toString());
    System.out.println("The reverse of s : " + s.reverse());
    System.out.println("After delete : " + s.delete(0,5));
    System.out.println("After replace: " + s.replace(0,4,"java"));
  }
}
```
输出结果为： 
```java
  s : I love java
  The length of s : 11
  s : i love java
  The reverse of s : avaj evol i
  After delete : evol i
  After replace: java i
```

在这里只介绍了 `String` 类常用的方法，其他方法可参照 JDK 文档。

## 1.5. java.lang 类 Math
在编程的过程中，经常对一些数字进行数学操作，比如想要求绝对值或余弦什么的。其实在 `java.lang` 里的 `Math` 类`Math` 类包含用于执行基本数学运算的方法，如初等指数、对数、平方根和三角函数。

方法                    | 返回值 | 功能描述
------------------------|--------|------------------------
sin(double numvalue)    | double | 计算角 numvalue 的正弦值
cos(double numvalue)    | double | 计算角 numvalue 的余弦值
acos(double numvalue)   | double | 计算 numvalue 的反余弦
asin(double numvalue)   | double | 计算 numvalue 的反正弦
atan(double numvalue)   | double | 计算 numvalue 的反正切
pow(double a, double b) | double | 计算 a 的 b 次方
sqrt(double numvalue)   | double | 计算给定值的正平方根
abs(int numvalue)       | int    | 计算 int 类型值 numvalue 的绝对值，也接收 long、float 和 double 类型的参数
ceil(double numvalue)   | double | 返回大于等于 numvalue 的最小整数值
floor(double numvalue)  | double | 返回小于等于 numvalue 的最大整数值
max(int a, int b)       | int    | 返回 int 型 a 和 b 中的较大值，也接收 long、float 和 double 类型的参数
min(int a, int b)       | int    | 返回 a 和 b 中的较小值，也可接受 long、float 和 double 类型的参数
rint(double numvalue)   | double | 返回最接近 numvalue 的整数值
round(T arg)            | arg    | 为 double 时返回 long，为 float 时返回 int	返回最接近arg的整数值
random()                | double | 返回带正号的 double 值，该值大于等于 0.0 且小于 1.0

会用到极坐标、对数等，就去查一查手册。

实例：
```java
public class Mathtest {
  public static void main(String args[]) {
    Float f = new Float(8.88);
    System.out.format("The sin of %.2f is %.4f%n" ,f.floatValue(), Math.sin(f.floatValue()));
    System.out.format("The cos of %.2f is %.4f%n" ,f.floatValue(), Math.cos(f.floatValue()));
    System.out.format("The asin of %.2f is %.4f%n" ,f.floatValue(), Math.asin(f.floatValue()));
    System.out.format("The acos of %.2f is %.4f%n" ,f.floatValue(), Math.acos(f.floatValue()));
    System.out.format("The atan of %.2f is %.4f%n" ,f.floatValue(), Math.atan(f.floatValue()));
    System.out.format("The pow(2) of %.2f is %.4f%n" ,f.floatValue(), Math.pow(f.floatValue(), 2));
    System.out.format("The sqrt of %.2f is %.4f%n" ,f.floatValue(), Math.sqrt(f.floatValue()));
    System.out.format("The abs of %.2f is %.4f%n" ,f.floatValue(), Math.abs(f.floatValue()));
    System.out.format("The ceil of %.2f is %.4f%n",f.floatValue(), Math.ceil(f.floatValue()));
    System.out.format("The floor of %.2f is %.4f%n" ,f.floatValue(), Math.floor(f.floatValue()));
    System.out.format("The ceil of %.2f is %.4f%n" ,f.floatValue(), Math.ceil(f.floatValue()));
    System.out.format("The rint of %.2f is %.4f%n" ,f.floatValue(), Math.rint(f.floatValue()));
    System.out.format("The random is %.4f%n" ,Math.random());
  }
}
```
输入结果：
```java
  The sin of 8.88 is 0.5182
  The cos of 8.88 is -0.8552
  The asin of 8.88 is NaN
  The acos of 8.88 is NaN
  The atan of 8.88 is 1.4587
  The pow(2) of 8.88 is 78.8544
  The sqrt of 8.88 is 2.9799
  The abs of 8.88 is 8.8800
  The ceil of 8.88 is 9.0000
  The floor of 8.88 is 8.0000
  The ceil of 8.88 is 9.0000
  The rint of 8.88 is 9.0000
  The random is 0.5478
```

## 1.6. java.lang 类 Class
`Class` 类的实例表示正在运行的 `Java` 应用程序中的类或接口。在 `Java` 中，每个 `Class` 都有一个相应的 `Class` 对象，即每一个类，在生成的`.class`文件中，就会产生一个 `Class` 对象，用于表示这个类的类型信息。获取 `Class` 实例有三种方法：

利用对象调用 `getClass()`方法获取该对象的 `Class` 实例

使用 `Class` 类的静态方法 `forName(String className)`，用类的名字获取一个 `Class` 实例
![](https://doc.shiyanlou.com/document-uid79144labid1085timestamp1435762998336.png/wm)

运用`.class`的方式来获取 `Class` 实例，对于基本数据类型的封装类，还可以采用`.TYPE`来获取相对应的基本数据类型的 `Class` 实例

`class` 类没有共有的构造方法，它由 JVM 自动调用。`class` 类的方法在这里就不细讲了.

想要了解更多关于 Class 对象的信息，可以参考一下[这里](http://blog.csdn.net/u010858605/article/details/53454830)。

## 1.7. java.lang 类 Object
`Object` 类是所有类的父类，所有对象（包括数组）都实现这个类的方法。所以在默认的情况下，定义的类扩展自 `Object` 类，当然可以调用和重写 `Object` 类里的所有方法了。

看一下 `Object` 类里都定义了哪些方法。

方法                               | 返回值  | 功能描述
-----------------------------------|---------|----------------------------------------------------
equals(Objectobj)                  | boolean | 将当前对象实例与给定的对象进行比较，检查它们是否相等
finalize() throws Throwable        | void    | 当垃圾回收器确定不存在对象的更多引用时，由对象的垃圾回收器调用此方法。通常被子类重写
getClass()                         | Class   | 返回当前对象的 Class 对象
toString()                         | String  | 返回此对象的字符串表示
wait() throws InterruptedException | void    | 在其他线程调用此对象的 notify() 方法或 notifyAll() 方法前，使当前线程进入等待状态

## 1.8. 总结
本节主要对 `java.lang` 包内的包装类以及 `String` 类、`Math` 类、`Class` 类、`Object` 类的相关知识。
