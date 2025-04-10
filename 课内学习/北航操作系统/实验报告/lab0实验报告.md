## 思考题

![image-20250311093439296](C:\Users\86135\AppData\Roaming\Typora\typora-user-images\image-20250311093439296.png)

![image-20250311093128681](C:\Users\86135\AppData\Roaming\Typora\typora-user-images\image-20250311093128681.png)

第一次执行add之前的状态是未跟踪，因为这个时候仓库里没有任何关于README.txt的信息。

而执行了一次add之后再修改，状态是已修改，这时候仓库里已经有README.txt的信息了，只不过我们又修改了一次文件，所以状态显示已修改。

![image-20250311093530856](C:\Users\86135\AppData\Roaming\Typora\typora-user-images\image-20250311093530856.png)

add the file 对应 git add 

stage the file 也对应 git add

commit 对应 git commit

![image-20250311093812039](C:\Users\86135\AppData\Roaming\Typora\typora-user-images\image-20250311093812039.png)

1.

```shell
git checkout print.c
```

2.

```shell
git reset HEAD print.c//取消删除操作
git checkout print.c//从暂存区恢复文件
```

3.

```shell
git rm print.c
```

![image-20250311095533453](C:\Users\86135\AppData\Roaming\Typora\typora-user-images\image-20250311095533453.png)

- 提交操作

![image-20250311095441605](C:\Users\86135\AppData\Roaming\Typora\typora-user-images\image-20250311095441605.png)

- 版本回退



- ![image-20250311095634866](C:\Users\86135\AppData\Roaming\Typora\typora-user-images\image-20250311095634866.png)

![image-20250311095647660](C:\Users\86135\AppData\Roaming\Typora\typora-user-images\image-20250311095647660.png)

![image-20250311095732136](C:\Users\86135\AppData\Roaming\Typora\typora-user-images\image-20250311095732136.png)

![image-20250311095750460](C:\Users\86135\AppData\Roaming\Typora\typora-user-images\image-20250311095750460.png)

![image-20250311100248901](C:\Users\86135\AppData\Roaming\Typora\typora-user-images\image-20250311100248901.png)

![image-20250311100231175](C:\Users\86135\AppData\Roaming\Typora\typora-user-images\image-20250311100231175.png)

\>会覆盖原来内容

\>\>会加入到原来内容的后面

![image-20250311101050288](C:\Users\86135\AppData\Roaming\Typora\typora-user-images\image-20250311101050288.png)

![image-20250311101042794](C:\Users\86135\AppData\Roaming\Typora\typora-user-images\image-20250311101042794.png)

## 难点分析

make的在使用的时候需要理清楚文件之间的依赖关系，已经make里面嵌套make 的时候，需要理清楚哪些是外部make做的事情，哪些是内部make做的事情。使用命令的时候需要清楚执行文件在哪个目录下，应使用正确的相对路径。

### 实验体会

刚开始接触命令行的时候有些不习惯，但是习惯了之后发现效率非常高，通过简单的命令就可以完成大量操作。熟练掌握git,vim,grep，管道，shell脚本，make等工具之后对PC的使用效率会大大提高