#include<stdio.h>

//插入排序,把未排序的部分插到排好的里面去，用折半查找法

int main()
{
    int n,arr[100];
    printf("please enter the number of integer:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++)
    {   
        int j=i+1;
        if(arr[j]>=arr[i])
        {

        }
        else if(j==1)arr[i]^=arr[j]^=arr[i]^=arr[j];
        else
        {
            int left=0,right=i;
            while(left<=right)
            {
                int mid=(left+right)/2;
                if(arr[j]<=arr[mid])
                {
                    right=mid-1;
                }
                else if(arr[j]>arr[mid])
                {
                    left=mid+1;
                }
            }
            int temp = arr[j];
            for(int k=j;k>left;k--)
            arr[k]=arr[k-1];
            arr[left]=temp;

        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;

}