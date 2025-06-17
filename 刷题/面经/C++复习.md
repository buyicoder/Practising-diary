## RTTI（Runtime Type Identification)

RTTI是一种新特性

RTTI只用于包含虚函数的类层次结构

包括四个组件：dynamic_cast、typeid、type_info、

- dynamic_cast<>是一种最常用的RTTI组件,判断类型转换是否安全，模板参数里面是转换成的类型，圆括号里面是被转换的指针。如果能安全转换就直接转换，如果不能安全转换，会返回0。

  - 注意，只有基类指针指向派生类是安全的，反之则不行，指针类型和对象类型是一致的也是安全的。

- typeid运算符和type_info类

  - typeid返回一个对type_info对象的引用，其中，type_info是在头文件typeinfo中定义的一个类。type_info类重载了==和!=运算符，以便可以使用这些运算符来对类型进行比较。
  - type_info类的实现随着厂商而异，但是包含一个name()成员，返回一个字符串，通常是类的名称

- 类型转换运算符：

  - dynamic_cast，检测是否安全
  - const_cast，只允许改变connst和volatile
  - static_cast，只允许隐式转换，可以向上转换也可以向下转换，也就是说static_cast可以将基类的地址转换为派生类的指针
  - reinterpret_cast，除了不允许删除const几乎什么都能转换，可以直接把long类型转换成地址，不能将函数指针转换成数据指针，反之亦然，不能将指针转换成更小的整型或浮点型。

  这四种类型转换都是模板参数里放目标类型