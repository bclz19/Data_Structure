# 实验要求

编程实现键盘输入一个中缀表达式（包含括号和加减乘除运算），转换成后缀表达式，并求解该后缀表达式。

要求提交核心源代码和程序执行结果截屏图像。

除此外，该实验完成了按步输出和乘方运算的bonus

# 前提知识
- 栈的相关知识
- 表达式的相关知识

### 表达式
算数表达式有三种：
- 前缀表达式(prifix) 操作符操作数操作数
- 中缀表达式(infix)  操作数操作符操作数 正常生活中使用
- 后缀表达式(postfix)操作数操作数操作符

### 操作符

### 中缀表达式求值方法

我用的方法就是中缀转后缀，再计算后缀

### 中缀转后缀方法

1、字符为 运算数 ：

直接送入后缀表达式（注：需要先分析出完整的运算数）。

2、字符为 左括号 ：

直接入栈（注：左括号入栈后优先级降至最低）。

3、字符为 右括号 ：

直接出栈，并将出栈字符依次送入后缀表达式，直到栈顶字符为左括号（左括号也要出栈，但不送入后缀表达式）。

总结：只要满足 栈顶为左括号 即可进行最后一次出栈。

4、字符为 操作符 ：

若栈空，直接入栈。

若栈非空，判断栈顶操作符，若栈顶操作符优先级低于该操作符，该操作符入栈；否则一直出栈，并将出栈字符依次送入后缀表达式，直到栈空或栈顶操作符优先级低于该操作符，该操作符再入栈。

总结：只要满足 栈空 或者 优先级高于栈顶操作符 即可停止出栈，并将该操作符入栈。

5、重复以上步骤直至遍历完成中缀表达式，接着判断字符栈是否为空，非空则直接出栈，并将出栈字符依次送入后缀表达式。

这边参考了Amentos原创文章，遵循 CC 4.0 BY-SA 版权协议                     
原文链接：https://blog.csdn.net/Amentos/article/details/127182926
### 后缀计算方法
建一个运算数栈，遇到数直接入栈，遇到操作符就pop出两个进行计算再push进去，依次类推