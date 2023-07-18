# Memory Manage Together

[toc]

## 介绍
**Memory Manage Together 一起内存管理**

本项目主要记录各类在C/C++使用过程中，有关内存的各种事项。

如：

- 内存泄漏 **memory leak** 
- 内存溢出 **out of memory**
- 访问越界 **access violation**
- 等等



## 展现形式

均以code的形式展现，一份文件一般对应一种问题。

[目录](catalog/catalog.md)



## 辅助工具

关于检测内存问题的工具有很多。

这里推荐在Linux下的`valgrind`

```bash
# 默认生成 a.out
gcc ./main.c

# 对 a.out 文件进行检测 
valgrind ./a.out
# 将检测信息打到文件中
# valgrind_out.log 不会自动创建
valgrind --log-file=valgrind_out.log ./a.out
```



## 交流合作

> 交流qq群：817328828

本项目致力于打造为一个拥有丰富例子的仓库。

有各种有趣的场景或者idea可以直接提交issues。

---

---

---

# END