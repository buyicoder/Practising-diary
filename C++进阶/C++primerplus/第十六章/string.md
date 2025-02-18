# string类

string类其实是模板具体化basic_string\<char\>的一个typedef,同时省略了内存管理相关的参数

## 构造函数

string的九种构造方式

```c++
string(size_type n, char c)//重复n个字符c
string(const char * s)//用C风格字符串
string(const string & str)//复制构造函数
string()//默认构造函数，空字符串
string(const char *s,size_type n)//s的前n个字符

template<class Iter>
string(Iter begin,Iter end)//用迭代器

string(const string & str,string size_type pos = 0,size_type n = npos)//str的pos开始，长度为n
string(string && str)noexcept //C++11新增的，将一个string对象初始化为string对象str,可能修改str
string(initializer_list<char> il)//C++11新增，将string对象初始化为初始化列表il中的字符
```

重载了+，+=，=，<<,>>,[]

## string类输入

```c++
string stuff;
getline(cin,stuff);
cin>>stuff;
```

string可以自动调整大小，但不是每次大小变化都会调整，而是不够的时候分出原来两倍空间

getline终止条件：

- 文件尾
- 遇到分界字符(默认为'\n')
- 读取字符达到允许最大值



## 使用字符串

### 比较字符串

可以使用关系运算符

### 字符串长度

方法length()，和size() 都可以



### find

```
size_type find(const string)
```

