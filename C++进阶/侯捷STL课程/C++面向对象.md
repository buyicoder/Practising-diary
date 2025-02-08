# C++面向对象

- Inheritance(继承)
- Composition(复合)
- Delegation(委托)



## Composition(复合)

```
template <class T>
class queue{
···
protected:
deque<T> c;
public:
	//以下完全利用c的操作函数完成
	bool empty() const{return c.empty();}
	size_type size() const{return c.size();}
	reference front(){return c.front();}
	reference back(){return c.back();}
	//
	void push(const value_type& x){c.push_back(x)}
	void pop(){c.pop_front();}
};
```

queue里面包含deque

deque很强大，完全可以满足queue的操作要求

这个东西叫Adapter

把一个比较成熟的东西改造成需要的样子



Container的构造函数首先调用Component的default（默认）构造函数，

然后才执行自己



析构由外而内

​	Container::~Container(...){... ~Component()};



## Delegation(委托).Composition by reference

![image-20250115141434338](C:\Users\86135\AppData\Roaming\Typora\typora-user-images\image-20250115141434338.png)

pimpl



编译防火墙，经典手法



## Inheritance(继承)，表示is-a

struct _List_node_base

{

​	_List_node_base* _M_next;

​	_List_node_base* _M_prev;



}

![image-20250115142524374](C:\Users\86135\AppData\Roaming\Typora\typora-user-images\image-20250115142524374.png)

使用public 继承

表示 is a,是一种



base class 的dtor必须是virtual

否则会出现undefined behavior



由内而外构造

由外而内析构



non-virtual函数：你不希望derived class重新定义（override 覆写）

virtual 函数：你希望derived class 重新定义它（override ,覆写），它已经有默认定义

pure virtual 函数：你希望derived class 一定要重新定义（override 覆写）

它，你对它没有默认定义



关键动作延缓到子类去写，把这种函数叫做 Template Method

大名鼎鼎的二十三个设计模式之一，函数就是Method,



对于一个做框架的人，

一般性动作，谁来写都一样，如果要开一个文件，这些都是固定的，大量用到Template Method



十多年前的MFC(Microsoft fundation classic)

虚函数里面最经典的一个用法



通过this 来调用

只有应用程序本身才知道如何读取自己的文件



Inheritance+Composition