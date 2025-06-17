UnaryProc for_each(beg,end,op),区间+操作函数，返回操作函数

==根据算法的功能很容易猜出op是一元函数还是二元函数==

- 这里的规律是如果op是代替value重载，则op是一元判断函数，（除了search _n)
- 如果op是多出来的，则op是二元判断函数（比较函数）

==根据算法的功能很容易猜出返回值类型，有的功能返回值不重要，有的功能返回值重要==

## 非变动性算法

- difference_type count(beg,end, value);
- difference_type count_if(be, end, op);根据算法的功能很容易猜出op是一元函数还是二元函数，这里op是一元函数
- InputIterator min_element(beg,end)
- InputIterator min_element(beg, end, op)，op是二元判断函数
- InputIterator max_element(beg,end)
- InputIterator max_element(beg, end, op)
- InputIterator find(beg,end,value)
- InputIterator find(beg,end,op)
- InputIterator search_n(beg, end, count, value);
- ==InputIterator search_n(beg, end, count, value, op)==,这个函数非常格格不入
- ForwardIterator1 search (beg, end, searchBeg,searchEnd)
- ForwardIterator1 search (beg, end, searchBeg,searchEnd,op),op是二元判断函数
- 