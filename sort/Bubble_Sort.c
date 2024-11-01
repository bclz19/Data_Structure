#include<stdio.h>

int main()
{
    int n,arr[100];
    printf("please enter the number of integer:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    //开始冒泡排序
    //基本的逻辑是，从第一个数开始，如果遇到右边比他小的，就交换，这样保证第一轮能把最大的放到第n个位置(arr[n-1])，这样进行n-1次就行
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n-i+1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
                //如果大就交换
            }
        }
    }
    printf("after sort:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}