#include<stdio.h>
#define MAX_SIZE 100
int InputSequence(int *a);//输入顺序表元素，并且返回元素个数
int UnionSequence(int *a, int *b, int *c, int count_a, int count_b);//并集运算
int IntersectionSequence(int *a, int *b,int *c,  int count_a, int count_b);//交集运算

int main()
{
    //定义顺序表，c用于中间运算
    int a[MAX_SIZE];
    int b[MAX_SIZE];
    int c[2*MAX_SIZE];
    int count_a;
    int count_b;
    int count_c;
    printf("请按照顺序输入顺序表A：");
    count_a = InputSequence(a);
    printf("请按照顺序输入顺序表B：");
    count_b = InputSequence(b);
    printf("请输入1进行并集运算，输入2进行交集运算：");
    if(getchar() == '1')
    {
        count_c = UnionSequence(a, b, c, count_a, count_b);
        printf("下面是顺序表A和顺序表B的并集，存放在顺序表A中：");
    }
    else
    {
        count_c = IntersectionSequence(a, b, c,  count_a, count_b);
        if(count_c)
        printf("下面是顺序表A和顺序表B的交集，存放在顺序表A中：");
        else
        printf("顺序表A和顺序表B没有交集");
    }

    for(int i = 0; i < count_c; i++)
    {
        a[i] = c[i];
        printf("%d ", a[i]);
    }
    return 0;
}

int InputSequence(int *a)
{
    int i = 0;
    while (i < MAX_SIZE)
    {    

        scanf("%d", &a[i]);
        i++;        
        if(getchar() == '\n') break;

    }

    return i;
}

//这个部分的思路是用双指针，一个指向a的初始位置，一个指向b的初始位置，比较两个指针指向的元素的大小
//如果a的元素小于b的元素，那么将a的元素放入c中，a的指针向后移动一位
//如果a的元素大于b的元素，那么将b的元素放入c中，b的指针向后移动一位
//如果a的元素等于b的元素，那么将a的元素放入c中，a和b的指针都向后移动一位。
//重要的点是处理剩余元素，例如a的元素已经全部放入c中，但是b的元素还有剩余，那么将b的剩余元素放入c中   如果测试不全面特别容易忽略这一点！
int UnionSequence(int *a, int *b, int *c, int count_a, int count_b)
{
    int *m = a;
    int *n = b;
    int *p = c;
    int count_c = 0;
    while(m < a + count_a && n < b + count_b)
    {
        if(*m < *n)
        {
            *p = *m;
            p++;
            m++;
            count_c++;
        }
        else if(*m > *n)
        {
            *p = *n;
            p++;
            n++;
            count_c++;
        }
        else
        {
            *p = *m;
            p++;
            m++;
            n++;
            count_c++;
        }
    }
    //处理剩余元素！！！
    while(m < a + count_a)
    {
        *p = *m;
        p++;
        m++;
        count_c++;
    }
    while(n < b + count_b)
    {
        *p = *n;
        p++;
        n++;
        count_c++;
    }
    return count_c;

}
//这个部分的思路依然是仿照上面求并集用双指针，一个指向a的初始位置，一个指向b的初始位置，比较两个指针指向的元素的大小，如果相同就放进c中;如果不同还是依次增长指针
//这边不需要处理剩余元素，因为交集的元素一定是两个顺序表中都有的元素，所以不会出现一个顺序表的元素已经全部放入c中，另一个顺序表还有剩余元素的情况
int IntersectionSequence(int *a, int *b, int *c, int count_a, int count_b)
{
    int *m = a;
    int *n = b;
    int *p = c;
    int count_c = 0;
    while(m < a + count_a && n < b + count_b)
    {
        if(*m == *n)
        {
            *p = *m; m++; n++; p++; count_c++;
        }
        else if(*m < *n)
        {
            m++;
        }
        else
        {
            n++;
        }
    }
    return count_c;
}