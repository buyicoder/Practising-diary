## 通用工具

### pair

pair是一个结构体，也就是说所有成员都是public

访问用first和seconde，重载了关系运算符

#### 便捷函数make_pair

无需给出模板参数就可以生成pair对象

### 数值极限

class numeric_limits

is_specialized设置为flase，说明对于这个类型而言没有极值

static min(), 返回该类型最小值,而且是静态成员函数，说明使用这个函数的时候不需要实例化

static max(),

### 辅助函数

min(),

max()，只要是重载了小于号的类型都可以用

swap

## 序列式容器

- vector
  - push_back()
  - size()
  - []
- deque
  - push_back()
  - push_front()
- list
  - empty()
  - front(),返回第一个元素
  - pop_front()
- string
- array

## 关联式容器

- set，自动排序，每个元素值只能出现一次
- multiset，允许重复元素
- map，键值对
- multimap，键值对，键允许重复

## 容器配接器

- stack
- queue
- priority_queue

## 算法

算法分为单个区间算法和多个区间算法，我们给出区间的方式常常为给出一头一尾两个迭代器，多区间算法通常第一个区间必须给出起点和重点，其它区间只需要给出起点即可，比如copy算法

### 迭代器配接器

- insert iterator(插入迭代器)
  - back_inserter(container)
  - front_inserter(container)
  - inserter(container, pos)
- Stream Iterators(流迭代器)
  - istream_iterator\<T>(cin)标准输入流
  - istream_iterator\<T>()产生流结束符号
  - ostream_iterator\<T>
- Reverse Iterators(逆向迭代器)
  - 所有容器都可以通过成员函数rbegin()和rend()产生除reverse iterator

### 更易型算法

- remove(begin, end, value)返回新的终点迭代器，但是容器的大小是不会改变的
- 成员函数.erase(begin,end)删除参数所示区间的全部元素

更易型算法不适用于关联式容器，如果要删除元素需要调用成员函数

