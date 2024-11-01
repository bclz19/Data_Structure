#include<stdio.h>

//选择排序法，循环n-1次，每次找一个最小的放在第一个，找n-1次之后就不用排了

int main()
{
    int n,arr[100];
    printf("please enter the number of integer:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=1;i<n;i++)
    {
        int min = arr[i-1];
        int min_index =i-1;
        for(int j=i;j<n;j++)
        {
            if(arr[j]<min)
            {
                min = arr[j];
                min_index = j;
            }
        }
        int temp = arr[i-1];
        arr[i-1]=min;
        arr[min_index]=temp;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}