#include<stdio.h>

//要求：编程实现：1).键盘输入数值型数据; 2).实现选择排序。要求上传核心代码和程序执行结果的电脑截屏图像。
// 选择排序算法逻辑：从数组第0个开始遍历，再嵌套一个循环，如果有比当前元素小的元素，则将其下标赋值给min
//遍历完一遍后，将min和当前元素交换，然后继续遍历下一个元素。
void select_sort(double *arr, int n)
{
    int i, j, min;
    double temp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

int main()
{
    double arr[10];
    printf("Please input 10 numbers:\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%lf", &arr[i]);
    }
    select_sort(arr, 10);
    printf("The sorted numbers are:\n");
    for(int i=0;i<10;i++)
    {
        printf("%lf ",arr[i]);
    }
    return 0;
}