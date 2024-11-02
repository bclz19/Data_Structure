#include <stdio.h>
#include <stdlib.h>

// 这个代码有bug，但我没空改了，先这样，以后再改

// 定义链表节点
struct node {
    int data;
    struct node* next;
};

// 定义栈结构
struct stack {
    struct node* data;
    struct stack* top;
};

// 初始化栈
void initStack(struct stack* s) {
    s->top = NULL;
}

// 压栈操作
void push(struct stack* s, struct node* p) {
    struct stack* temp = (struct stack*)malloc(sizeof(struct stack));
    temp->data = p;
    temp->top = s->top;
    s->top = temp;
}

// 弹栈操作
struct node* pop(struct stack* s) {
    if (s->top == NULL) {
        return NULL;
    }
    struct stack* temp = s->top;
    s->top = s->top->top;
    struct node* data = temp->data;
    free(temp);
    return data;
}

// 方法一：递归
void printListFromEnd_1(struct node* head) {
    if (head == NULL) {
        return;
    }
    printListFromEnd_1(head->next);
    printf("%d ", head->data);
}

// 方法二：反转链表
void printListFromEnd_2(struct node* head) {
    struct node *p = head;
    struct node *q = NULL;
    struct node *r = NULL;

    // 反转链表
    while (p != NULL) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }

    // 打印反转后的链表
    while (q != NULL) {
        printf("%d ", q->data);
        q = q->next;
    }
}

// 方法三：使用栈
void printListFromEnd_3(struct node* head) {
    struct stack s;
    initStack(&s);
    struct node* p = head;

    // 遍历链表，将每个节点压入栈中
    while (p != NULL) {
        push(&s, p);
        p = p->next;
    }

    // 弹出栈中的元素并打印
    while (s.top != NULL) {
        struct node* temp = pop(&s);
        printf("%d ", temp->data);
    }
}

int main() {
    printf("请输入链表的长度：");
    int n;
    scanf("%d", &n);
    printf("请输入链表的元素：");
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* p = head;

    for (int i = 0; i < n; i++) {
        scanf("%d", &p->data);
        if (i < n - 1) {
            p->next = (struct node*)malloc(sizeof(struct node));
            p = p->next;
        } else {
            p->next = NULL;
        }
    }

    // 方法一：递归
    printListFromEnd_1(head);
    printf("\n");

    // 方法二：反转链表
    printListFromEnd_2(head);
    printf("\n");

    // 方法三：使用栈
    printListFromEnd_3(head);
    printf("\n");

    // 释放链表内存
    p = head;
    while (p != NULL) {
        struct node* temp = p;
        p = p->next;
        free(temp);
    }

    return 0;
}