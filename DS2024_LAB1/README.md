# 实验任务

编程实现以下任务：

1、键盘输入建立2个有序顺序表A和B，类型任意；

2、求表A、B的并集，结果存储在表A中（注意并集要保持有序性），并输出结果；

3、求表A、B的交集，结果存储在表A中，并输出结果。

# 思路

定义三个函数
InputSequence()         用于输入顺序表
UnionSequence()         用于求并集
IntersectionSequence()  用于求交集

重点是求并集和交集的算法，与学习C程时不同，我着重考虑了时间复杂度。
按照传统做法，并集的做法是先创一个新数组C，复制A到C，然后遍历B数组，如果有和C相同的就跳过，如果没有相同的，就遍历C数组，找到位置后插入，这样的时间复杂度非常高
如果用count_a count_b和count_c来表示a,b和c数组的时间复杂度的话，遍历B是O(count_b)，找到位置是O(count_c),插入是O(count_c)（因为要每个往后挪）

一种优化的方法是用链表，我嫌烦就没用

另一种我采用的优化的方法是使用双指针，分别指向a和b数组的位置，比较两者的大小，如果a比b小，指向a的指针向后挪，继续比较；如果相同，就指向a和b的指针都向后挪；以此类推
这样的时间复杂度就是O(count_a+count_b)，大大优化

# p.s
这次定义数组用的是int a[length]这种方法，下次一定用int *a = (*int)malloc(length*sizeof(int))这种方法

如果您不能运行我的.c文件，请把.exe文件和.vscode文件夹全部删掉

本程序使用UTF-8编码，出现乱码可以改成UTF-8 编译器为ucrt64

机器人工程 方辰 3230102284
9/20