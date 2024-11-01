#include<stdio.h>
#include<stdlib.h>
void merge(int* arr,int left,int mid,int right);

void sort_merge(int* arr,int left,int right)
{
    if(left==right)
    return;
    int mid = (left+right)/2;
    sort_merge(arr,left,mid);
    sort_merge(arr,mid+1,right);
    merge(arr,left,mid,right);
}

void merge(int* arr,int left,int mid,int right)
{
    int i=left,j=mid+1,k=0;
    int* temp = (int*)malloc(sizeof(int)*(right-left+1));
    while(i<=mid && j<=right)
    {
        if(arr[i]<arr[j])
        {
            temp[k++]=arr[i++];
        }
        else
        {
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid)
    {
        temp[k++]=arr[i++];
    }
    while(j<=right)
    {
        temp[k++]=arr[j++];
    }
    for(i=left,k=0;i<=right;i++,k++)
    {
        arr[i]=temp[k];
    }
}

int main()
{
    int n,arr[100];
    printf("please enter the number of integer:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    sort_merge(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}