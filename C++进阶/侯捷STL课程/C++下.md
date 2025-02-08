# C++下

## conversion function,转换函数

![image-20250122112533510](C:\Users\86135\AppData\Roaming\Typora\typora-user-images\image-20250122112533510.png)

```C++
operator double() const{
	return (double) (m_numerator/m_denominator);	
}
```

设计出来的函数不是显式地使用的，而是在需要类型转换的时候使用

```C++
Fraction f(3,5);
doublee d=4+f; //调用operator double()将f转为0.6
```

==把operator double()整体当成一个函数名==

可以不止写一个转换函数

比如也可以写

```C++
operator string() const{
	return (string)···
}
```



构造函数

本来是自动的转换函数，可以把别的数转成自己这种类型



但是加上explict就可以不自动转换

```C++
explict Fraction(int num, int den=1)
	: m_numerator(num),m_denominator(den){}
```



pointer-like classes,关于智能指针

```

```





function-like classes,所谓仿函数

```C++
template <class T>
struct identity {
	const T&
	operator()(const T& x) const {return x;}
};

template<class Pair>
struct select1st{
    const typename Pair::first_type&
    operator()(const Pair& x) const
    {return x.first; }
};

template<class Pair>
struct select2nd {
    const typename Pair::second_type&
	operator()(const Pair& x)const
    {return x.second;}
};

```



## partial specialization,模板偏特化 --范围的偏

```C++
template <typename T>
class C<T*>
{
	···
};
```

``` C++
C<string*> obj2;
C<string> obj1;
```



## 模板模板参数

```C++
template<typename T,template <typename T> class Container >
class XCls
{
private:
    Container<T> c;
public:
    
}
```



```C++
template<typename T>
using Lst = list<T,allocator<T>>;
```



```C++
XCls<string,list> mylst1;//这个是错的
XCls<string,Lst> mylst2;//这个是对的
```

定义模板名称的时候typename和class共通



## variadic templates (since C++11)

```C++
void print()
{
}

template <typename T,typename... Types>
void print(const T& firstArg, const Types&... args) {
	cout << firstArg << endl;
	print(args...);
}
```

```C++
...就是一个所谓的pack(包)
用于
```

```C++
sizeof...(args) yields the number of arguments
```



## auto(since C++11)

```C++
list<string> c;
...
list<string>::iterator ite;
ite = find(c.begin(),c.end(),target);
```



```C++
list<string> c;
...
auto ite = find(c.begin(),c.end(),atget);
```



## range-base for(since C++11)

```
for(decl:coll){
	statement
}
```

```C++
for (int i:{2,3,5,7,9,13,17,19}){
	cout<<i<<endl;
}
```

```C++
vector<double> vec;
...
for(auto elem :vec){
	cout<< elem <<endl;
}
```

```
for(auto& elem : vec ){
	elem *=3;
}
```

## reference

```C++
int& r=x;
int x2=5;

r=x2;//不是r代表x2，而是r的值变成x2,即x的值变成x2;
int& r2 = r;
```



```
object和reference的大小相同，地址也相同（全都是假象）
```



### reference的常见的用途

reference就是一种漂亮的pointer

很少直接声明变量为reference

更多用于参数传递，参数传递尽可能用reference

```
void func1(Cls* pobj){pobj->xxx();}
void func2(Cls obj) {obj.xxx();}
void func3(Cls& ovj){obj.xxx();}
...
Cls obj;
func1(&obj);
func2(obj);----接口不同，困扰
func3(obj);//调用端接口相同，很好
```

还有返回类型，不是local变量就可以用reference



```
double imag(const double& im){...}
double imag(const double im){...}
```

same signature

签名相同，二者不能同时存在



double imag(const double& im){...}

double imag(const double im)  const  {...}//Ambiguity

signature

const是不是函数签名的一部分？



## vptr和vtbl

如果符合某些条件会做动态绑定

通过指针调用函数，指针new的时候是new一只猪，但是类型是动物

调用的是虚函数

符合这三个条件

这一条路线

不一定

看p指的是什么，动态绑定，静态绑定

这种用法叫做多态

list<A*>

实际上指向不同的东西

多态，虚函数，动态绑定，其实是同一件事情

把这些事情弄清楚，面向对象了然于心。



## 关于this

通过一个对象来调用一个函数，那个地址就是this pointer

好处

面向对象用了虚函数的好处

子类对象调用父类的函数，但是父类函数里有一个没有定义的虚函数，虚函数在子类才定义，这是可以的

```c++
myDoc.OnFileOpen();
相当于
CDocument::OnFileOpen(&myDoc);
```

所有的调用动作都是

==向上转型动作==

## 谈谈const

|                            | const object | non-const ovject |
| -------------------------- | :----------: | :--------------: |
| const member functions     |      √       |        √         |
| non-const member functions |      ×       |        √         |

```C++
memberFunctionName const {
}
```

这个位置的const 表示成员函数不改变类数据的值

const object只能调用const版本的成员函数

non-const ovject 只会调用non-const 版本



初学者不管什么函数都不加const

如果不加，const object 加了



```C++
charT
operator[](size_type pos) const
{}

reference
operator[](size_type pos)
{}

这两个函数加不加const影响签名，重载成功
为什么不影响签名，应该是因为看object是不是const

const object只能调用const版本的成员函数
non-const object 只会调用non-const 版本


如果有一个字符串，拷贝四个，其实共享同一个内容
万一想要该内容，数据变化怎么办，单独拷贝一份给你改

```



## new 和delete

new:先分配memory,再调用ctor

delete:先调用dtor,再释放memory



```C++
class Foo{
public:
	void* operator new[](size_t);
	void operator delete[](void*,size_t);
}
```



若无成员函数就调用全局函数

```C++
//强制调用全局函数
::new
::delete
```



delete



```C++
Foo* pArray = new Foo[5];
delete [] pArray //需要使用数组delete,这样才会调用五次析构函数
```



重载成员函数



placement arguments



```C++
Foo* pf = new(300,'c')Foo;


```

也可以重载class member operator delete()

但它们绝不会被delete调用。只有当new调用的ctor抛出excepetion(异常),才会调用对应重载的delete。





# 









