# include<stdio.h>
# include<stdlib.h>
//逆序输出链表元素
//首先建立一个链表

struct node
{
    int data;
    struct node* next;
};

void printListFromEnd_1(struct node* head)
{
    if(head == NULL||head->next == NULL)
        return;
    printListFromEnd_1(head->next);
    printf("%d ", head->data);
}
int main()
{
    printf("请输入链表的长度：");
    int n;
    scanf("%d", &n);
    printf("请输入链表的元素：");
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* p = head;
    for(int i=0; i<n; i++)
    {
        scanf("%d", &p->data);
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        p->next = temp;
        p = temp;
        temp->next = NULL;
    }
    //方法一：递归
    printListFromEnd_1(head);
}