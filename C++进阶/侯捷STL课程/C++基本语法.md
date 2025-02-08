## class

public:后的变量和函数所有人都可以访问

private:后的变量和函数只有class内部可以访问

不一定要分成两段

可以有多个public 和private



![image-20250114120328144](C:\Users\86135\AppData\Roaming\Typora\typora-user-images\image-20250114120328144.png)

所有的数据都应该放在private

函数需要被外界调用就放在public

只是内部函数用的函数就放在private



## 构造函数

对象被创建的时候自动调用的函数

和类名同名

complex(double r=0,couble i=0)

:re（r),im(i)

{}

等于号后面是默认值

构造函数有什么特别：

- 没有返回值，因为构造函数就是创建对象的，只能返回对象
- 里面要做什么自己设计

大气的，正规的，好的写法：

只有构造函数才有的功能：

initialization list

初值列，初始列



==能用初始列，尽量用初始列==

否则就浪费了初始化阶段

多用了一个assign阶段



assign赋值



不可能在程序里直接调用构造函数

，只能在创建对象的同时自动调用



构造函数可以有很多个，overloading重载



同名的函数可以有很多个，

因为机器会把函数的名称、参数个数，参数类型编码成一个只有机器看得懂的名字，虽然函数名相同，但是真正的名字不同



有默认值的参数相当于没有，因为调用的时候可以省略

函数重载常常发生在构造函数身上



把构造函数放在private区域

表示这个函数不可以被外界调用，看起来不可以



但是有些时候可以这么做



就是不允许被外界创建对象的时候



外界需要的时候

Singleton单例模式，外界只能有一份对象A



```
A& A::getInstance()
{
	static A a;
	return a;
}
```

外界创建的时候用

```
A::getInstace.setup();
```



在函数的后面加==const==

![image-20250114181442403](C:\Users\86135\AppData\Roaming\Typora\typora-user-images\image-20250114181442403.png)

在函数的后面加function

表示这个函数不改变class的数据内容

不改变数据内容的马上加上const

比如说是拿数据的函数（接口）

person,stone



设计接口的时候就加上const,实现交给别人实现



![image-20250114181823974](C:\Users\86135\AppData\Roaming\Typora\typora-user-images\image-20250114181823974.png)

前面用了const,意思是对象的内容不会改变

万一定义函数的时候没有写const

调用函数的时候编译器说不行，这个函数有可能改变对象内容，不让用这个函数





参数传递：pass by value,pass by reference

pass by value,value就是整包传过去，可能传很大，尽量不要pass by value

pass by reference

引用在底部就是指针

最好所有的参数尽量传引用



指针传过去一改就会影响自己，为了防止被修改，就加一个const



#### 在每一个影响效率的地方注意

返回值尽量也用reference

return by reference



class语法特征

#### 友元

==朋友可以来拿数据==

![image-20250114183740561](C:\Users\86135\AppData\Roaming\Typora\typora-user-images\image-20250114183740561.png)

和直接设函数有什么区别？

为什么更快？

这个例子举得不好，因为其实可以不要这个friend,当需要直接拿别的类的数据时候



![image-20250114183935507](C:\Users\86135\AppData\Roaming\Typora\typora-user-images\image-20250114183935507.png)

这样可以，为什么？

第一个对象直接拿第三个对象的数据

一句话解释：

相同class的各个objects互为friends(友元)





- 数据放在private里面
- 传数据尽量用reference
- 返回值尽量用reference,有一种情况不能用，就是得到的结果没有载体的时候（其实挺多情况是这样的？应该不对，需要结果的时候应该要提前定义好载体，然后当参数传递进去）
- 定义函数的时候如果有就要加，否则报错会怪class设计者

- 尽量用initialization list



## 操作符重载

operator overloading

C++的一个很大的特性

对新设计出来的东西C只能用函数，但是C++可以用操作符

C++允许重写操作符，实际上C++里面操作符就是一种特殊形式的函数



```
c1 += c2
在编译器眼里
+=(this,c2);
+=是一个函数名
this表示调用者的指针
```

重载的时候

```
inline complex&
__doapl(comlex* ths, const complex& r)
{
 ths->re += r.re;
 ths->im += r.im;
 return *ths;
}

complex::operator +=(const complex& r)
{
	return __doapl (this,r);
}
```



这一段代码是标准库里面的代码

伟大的团队，正规的复数设计



传递者无需知道接收端是以reference形式接收

还是以value形式接收



非成员函数（无this)

```
inline complex
operator +(const complex& x, const complex& y)
{
	return complex (real(x)+real(y),imag(x)_imag(y));
}
```

这些东西不可能return by reference,

因为它们返回的时候必定是个local object

==返回的东西原来不存在==

return by value 就是函数类型是什么就返回什么，因为是传值，不用管生命周期

创建出来的东西虽然很快就销毁了,而且没有名字，但是因为是传值所以没关系，这个叫临时对象temp object



标准库用了很多临时对象



<<不能写成成员函数

只能写成非成员函数，只能用全局的写法

void operator << (ostream & os,const complex& x){

return os<< '('<<real(x)<<','<<imag(x)<<')';

}

ostream前面不能用const,因为需要更改cout



没有人在乎这个函数返回什么结果，所以返回类型设计为void？

但是为了满足

```
cout<<c1<<conj(c1);
```

这种句式

要把返回类型改为ostream&

作为一个好的设计者要尽量满足需求者



- initialization list一定要用
- 函数加不加const一定要考虑
- 数据放在private,函数大部分放在public
- 传参用引用，返回值也用引用（能用就用）



class complex

{

public:

​	complex (double r = 0, double i=0)

​	:re(r),im(i)

{



}

private:

​	double re,im;

}



拷贝构造

拷贝赋值



测试程序

![image-20250115094710209](C:\Users\86135\AppData\Roaming\Typora\typora-user-images\image-20250115094710209.png)



拷贝构造

String s3(s1);

拷贝赋值

s3=s2;



拷贝构造和拷贝赋值如果没有写

编译器会自己加

![image-20250115095711959](C:\Users\86135\AppData\Roaming\Typora\typora-user-images\image-20250115095711959.png)

String(const char* cstr=0);

String(const String& str);

String& operator=(const String& str);

~String();

char* get_c_str() const {return m_data;}

private:

​	char* m_data;

};

![image-20250115100116999](C:\Users\86135\AppData\Roaming\Typora\typora-user-images\image-20250115100116999.png)



new出来的内存一定要在析构函数中释放，否则内存泄漏了

![image-20250115100531686](C:\Users\86135\AppData\Roaming\Typora\typora-user-images\image-20250115100531686.png)



class with pointer members 必须有copy ctor和copy op

如果不自己写

编译器做的事情只是复制指针，即==浅拷贝==

拷贝构造函数应该为深拷贝

浅拷贝造成重名，非常危险



拷贝复制函数



![image-20250115101715885](C:\Users\86135\AppData\Roaming\Typora\typora-user-images\image-20250115101715885.png)

String& String::operator= (const String& str)

{

检测自我赋值(==功力深厚的人会写这一块==)

if(this == &str)return *this;



==如果不这么写会出错==，==因为下面一句话先把自己的东西删除了==



清空左边delete[] m_data;

分配和右边一样大的空间m_data=new char[strlen(str.m_data)+1]

把右边复制到左边

strcpy(m_data,str.m_data);

return*this;

}





最后一个，为了输出string，需要重载<<符号



## 栈stack和堆heap

==stack==，存在于某个作用域内的一块内存空间。

当你调用函数，函数本身即会形成一个stack用来放置它所接收的参数，以及返回地址

在函数本体内声明的任何变量，其所使用的内存都取自上述stack



new是从堆里面开辟的一块空间，必须手动delete掉



结束的时候析构函数会被调用起来



==static object== 

其生命在整个程序结束之后才结束

，作用域是整个程序



内存泄漏，因为作用域技术，p的heap object 还存在，但是p的生命结束了



new:先分配memory,然后调用ctor

所有的编译器都这样

![image-20250115104221384](C:\Users\86135\AppData\Roaming\Typora\typora-user-images\image-20250115104221384.png)

```
pc->Complex::Complex(1,2);	//构造函数
```

全名Complex::Complex(pc,1,2);



delete：两个动作

```
String::~String(ps) //析构函数
operator delete(ps); //释放内存
```





使用malloc和free到底分配多少内存

如果分配一个复数

new Complex(1,2)

本体8个字节

在调试模式下，会在上面多出32字节

下面多出4个字节

还有上下两个cookie,两个字节

8+（32+4）+4*2=52

在VC底下是这样

每个内存块一定是16的倍数，所以是64



为了回收的时候可以顺利回收





release模式就很精简

只有8+（4*2）





String *p=new String[3];

new String[3]是一个Array new

array new需要搭配array delete[]



delete[] p;

==才知道调用三次析构函数==



经典单一class

该怎么设计，分为有指针的和无指针的





## static

熟悉this pointer

要写很多class彼此组合

必须很清楚程序在很多class走来走去



在数据或函数前面加上static

![image-20250115114605738](C:\Users\86135\AppData\Roaming\Typora\typora-user-images\image-20250115114605738.png)

调用相同的函数，但是给的是不同的地址

这样才能处理不同的数据

![image-20250115114831408](C:\Users\86135\AppData\Roaming\Typora\typora-user-images\image-20250115114831408.png)

黄色部分可以不加，编译器会帮忙加上

但是实际上函数是通过this指针找到数据的



对于所有的实例来说都一样的数据

就要加static,只能友一份

比如对所有账户来说利率应该是一样的



静态函数只能处理静态数据

![image-20250115115515249](C:\Users\86135\AppData\Roaming\Typora\typora-user-images\image-20250115115515249.png)

在创建对象之前就可以调用静态函数





构造函数放在private区域

外界取得唯一的

![image-20250115120005370](C:\Users\86135\AppData\Roaming\Typora\typora-user-images\image-20250115120005370.png)



## class template,类模板

![image-20250115133347897](C:\Users\86135\AppData\Roaming\Typora\typora-user-images\image-20250115133347897.png)

![image-20250115133608991](C:\Users\86135\AppData\Roaming\Typora\typora-user-images\image-20250115133608991.png)

只需要重载<就可以了 

```
stone& operator<(const stone& rhs)const
{
	return _weight<rhs._weight;
}
```

标准库里面的算法，全部用function template实现

## namespace

### 定义

namespace std

{

···

}

### 使用

- ```
  #include<iostream.h>
  using namespace std;
  int main(){
  	cin<<...;
  	cout<<...;
  	return 0;
  }
  ```

- ```
  #include<iostream.h>
  using std::cout;
  int main(){
  	cout<<...;
  	return 0;
  }
  ```

- ```
  #include<iostream.h>
  int mian(){
  	std::cin<<...;
  	std::cout<<...;
  	return 0;
  }
  ```

  



![image-20250115134831643](C:\Users\86135\AppData\Roaming\Typora\typora-user-images\image-20250115134831643.png)



![image-20250115134911121](C:\Users\86135\AppData\Roaming\Typora\typora-user-images\image-20250115134911121.png)