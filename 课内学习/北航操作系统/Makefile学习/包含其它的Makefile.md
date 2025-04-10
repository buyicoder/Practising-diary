## 包含其它的Makefile

include *filenames*...

==注意不要在前面加“#”==

其中的filename可以包含shell文件名模式。

```c++
inlcude foo *.mk $(bar)
```

等价于

```
include foo a.mk b.mk
```

