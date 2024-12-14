# C++实践笔记

## unordered_map的用法

### 头文件：#include<unordered_map>

### 适用情况：查找问题

### 创建方法：

```
std::unordered_map<std::string,std::string> umap
```

创建的同时初始化：

```
std::unordered_map<std::string,std::string> umap{
	{"淘宝","https://www.taobao.com/"},
    {"京东","https://www.jd.com/"},
    {"天猫商城","https://jx.tmall.com/"}
}
```

拷贝构造函数：

```
std::unordered_map<std::string, std::string> umap2(umap);
```

使用迭代器拷贝部分函数：

```
使用unordered_map类模板提供的迭代器
std::unordered_map<std::string,std::string>umap2(++umap.begin(),umap.end());
```

常用函数

begin（），指向第一个键值对的迭代器

end（），指向最后一个键值对后面一个的迭代器

find（key），返回指向该键值对的迭代器，如果没有返回end（）指向的迭代器

emplace，插入新的键值对

insert，插入新的键值对

at（key）返回key对应的值

count（key），查找以key键为键值对的个数

erase(),



### emplace和insert有什么区别？

insert接收一个值或者一个范围，有一个复制操作

而emplace没有复制操作，所以emplace比insert更高效

## string的用法

### 构造函数

```
string str;
string s(str);
string s(str,strbegin,strlen);复制str中的一段
string s(cstr,char_len);以C_string类型cstr的前char_len个字符串作为s初值
string s(num,c);生成num个c字符的字符串
string s(str,stridx);将字符串str中从stridx开始到字符串结束的位置作为字符串初值
```

### 大小和容量

 ```
 size()和length() 效果一样
 capacity()重新分配内存之前，string能包括的最大字符数
 ```

### 比较

```
C++字符支持常见的比较操作符(>,>=,<,<=,==,!=)
支持string和C_string的比较
还有一个compare()成员函数
```

### string的插入：push_back()和insert

```
push_back(char)尾插
insert(pos,char)制定位置插入
```

## stack的用法

stack常用操作和函数：

### 构造函数

```
std::stack<元素类型> s ;

std::vector<int> v= {1,2,3};
std::stack<int> s(v);
```

### 元素访问

```
top()返回栈顶元素的引用
empty()检查栈是否为空
```

### 修改栈

```
push()
pop()
```

### 大小

```
size()
```

### 交换

```
swap()交换两个栈的内容
```

