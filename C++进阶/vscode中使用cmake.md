# vscode中使用cmake

### 7.1前言

1>CMake是一个跨平台的安装编译工具，可以使用简单的语句来描述所有平台的安装（编译过程）

2>CMake可以说是以及该成为大部分C++开发项目的标配

3>可以使用几行或者几十行的代码来完成非常冗长的Makefile代码

### 7.2为什么要使用CMake

1>在不使用CMake的时候

不同平台要使用不同的编译工具，有不同的配置文件，非常麻烦

2>在上面的机制中，工程文件中添加一个源程序bar.cpp



3>使用cmake来管理工程的状态

编写一个CmakeList.txt

通过CMake指令



4>语法特性介绍

### 7.3语法特性介绍

1>基本语法：指令（参数1，参数2...)

参数使用括号括起来

参数之间使用空格或分号隔开

2>注意：指令是大小写无关的，但是参数和变量是大小写相关的

```
set(HELLO hello.cpp) #定义一个变量名叫HELLO 变量的值为hello.cpp
add_executable(hello main.cpp hello.cpp) 	#	通过main.cpp 和hello.cpp 编译生成hello可执行程序
ADD_EXECUTABLE(hello main.cpp ${HELLO}) #作用同上
```

3>变量使用 $()进行取值，但是在if控制语句中，是直接使用变量名的

if(HELLO) 是正确的

if(${HELLO})是错误的



4> 语句不以分号结束



### 7.4 重要的指令和CMake常用变量

1>cmake_minimum_required:指定CMake的最小版本支持，一般作为第一条cmake指令

```
#CMake设置最小支持版本为2.8
cmake_minimum_required(VERSION 2.8)
```



2>project(定义工程的名称，并可以指定工程支持的语言)

```
#指定工程的名称为HELLOWORLD
project(HELLOWORLD CXX)
```

3>set:显式定义变量

```
#定义变量SRC
```

4>add_exexutable:通过依赖生成可执行程序



5>include_directories:向工程添加多个特定的 头文件搜索路径吗，类似于g++编译指令中的 -l

```
include_directories(/usr/lib/mylibfolder ./lib)
```

6>link_directories:向工程中添加多个特定的库文件搜索路径，类似于g++编译指令的-L选项

7>add_library:生成库文件（包括动态库和静态库）

```
# 通过SRC 变量中的文件，生成动态库
add_library(hello SHARED ${SRC})  #该语句生成的是动态库
add_library(hello STATIC ${SRC})  #该语句生成的是静态库
```

8> add_compile_options:添加编译参数

```
#
add_compile_options(-Wall -std=c++11)
```

9>target_link_

### 7.5CMake常用变量

1>CMAKE_C_FLAGS:gcc编译选项的值

2>CMAKE_CXX_GLAGS:g++编译选项的值

```
#在CMAKE_CXX_FLAGS
set()
```

3>CMAKE_BUILD_TYPE:编译类型：(Debug,Release)

```
# 设定编译类型为Debug，调试时需要选择该模式
set(CMAKE_BUILD_TYPE Debug)
# 设定编译类型为Release,发布需要选择该模式
set(CMAKE_BUILD_TYPE Release)
```

### 7.6 CMake编译工程

CMake目录结构：项目主目录中会放一个CMakeLists.txt的文本文档，后期使用cmake指令时，依赖的就是该文档

1>包含源文件的子文件夹中包含CMakeLists.txt文件时，主目录的CMakeLists.txt要通过add_subdirector添加子目录

2>包含源文件的子文件夹中不包含CMakeLists.txt文件时，子目录编译规则，体现在主目录中的CMakeLists.txt

#### 7.6.1	 两种构建方式

1>内部构建：不推荐使用

内部构建会在主目录下，产生一大堆中间文件，这些中间文件并不是我们最终所需要的，和工程源文件放在一起的时候，会显得比较杂乱无章

```
##内部构建

#在当前目录下，编译主目录中得到CMakeLists.txt 文件生成Makefile文件
cmake .
#执行make命令，生成目标文件
make
```

2>外部构建：推荐使用

将编译出的文件与源文件放到不同 的目录下，进行编译，此时编译生成的中间文件，不会跟工程源文件进行混淆

```
## 外部构建步骤

#1.在当前目录下，创建一个build文件，用于存储生成中间文件
mkdir build

#2.进入build文件夹内
cd build
#3.编译上一级目录中的CMakeLists.txt,生成Makefile文件以及其他文件
cmake ..

#4.执行make 命令，生成可执行程序
make
```

### 7.7CMake代码实战

#### 7.7.1	同一目录下的文件进行编译

1>源文件

编译完之后会生成CMakefiles文件夹和CMakeCache.txt和cmake_install.cmake和Makefile









