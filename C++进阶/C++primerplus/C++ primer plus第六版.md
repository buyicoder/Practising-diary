# C++ primer plus第六版

## 整数加后缀

22022L背存储为long

u-------------->unsigned int

ul------------->unsigned long

L-------------->long

LL------------>long long



## 指针和const

```c++
int age =39;
const int *pt=&age;
//这里表示不能用pt修改它所指向的值，但是pt本身可以修改
//比如pt->age++就是非法的
//但是只是不能通过pt修改，而因为指向的age本身不是const值，所以可以直接修改
//age++;就是合法的
age++;
//pt本身可以修改，可以指向别的值
int sage =80;
pt=&sage;

int sloth =3;
const int *ps=&sloth;
int * const finger = &sloth;
//这里的finger只能指向sloth,但允许使用finger来修改sloth的值。
(*finger)++;//允许
//finger = &sage是不对的，finger本身是const,不能改变

```

有一个简单的分辨方法，就是看const后面紧跟着的作用对象，const的作用对象修改值的动作会被限制。

const int *pt作用对象是\*pt,所以\*pt不能修改值；

int * const finger作用对象是finger 所以finger 不能修改值；

如果const后面紧跟着成员函数体，说明作用对象是成员函数体，则该函数体不能修改对象中的数据成员。

### 友元

为什么需要友元？

重载运算符的时候，如果只有成员函数，会造成无法更换顺序，所以需要重载为传递两个参数的非成员函数，但是非成员函数一般没有访问类private数据的权限，所以需要在类中定义友元，赋给该非成员函数访问权限；

### 类的自动转换

只有接收一个参数的构造函数才能作为转换函数

```C++
Stonewt myCat;
myCat = 19.6;
```

这种转换是自动转换，也叫隐式转换，如果程序员不需要这种转换，就要在构造函数的声明前面加上explicit关键字，加上之后将关闭隐式转换,但仍然可以显示转换

```C++
explicit Stonewt(doublee lbs);
```



```c++
Stonewt myCat;
myCat = 19.6;//不允许
myCat = Stonewt(19.6);//允许
myCat = (Stonewt)19.6;//允许
```

#### 转换函数

```
explicit operate doulbe() const;
```

