/*实验要求：编程实现键盘输入数据，建立一颗二叉树，并对二叉树进行前序、中序或后续遍历，使用递归或非递归方法均可；
二叉树按二叉链表方式存储。要求提交核心源代码和程序运行结果截图。*/

#include <stdio.h>
#include <stdlib.h>

// 定义二叉链表节点结构
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// 创建新节点
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 前序遍历
void preOrderTraversal(struct TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
// 中序遍历
void inOrderTraversal(struct TreeNode* root) {
    if (root == NULL) return;
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

// 后序遍历 
void postOrderTraversal(struct TreeNode* root) {
    if (root == NULL) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->data);
}

// 层次遍历
void levelOrderTraversal(struct TreeNode* root) {
    if (root == NULL) return;
    struct TreeNode* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        struct TreeNode* node = queue[front++];
        printf("%d ", node->data);
        if (node->left != NULL) queue[rear++] = node->left;
        if (node->right != NULL) queue[rear++] = node->right;
    }
}
// 主函数
int main() {
    //创立一个4层的完全二叉树，根节点为0
    struct TreeNode* root = createNode(1);
    //层序输入输入数据
    printf("请输入二叉树的数据，输入顺序为层序输入");
    int data[15];
    for(int i=1;i<15;i++){
        scanf("%d",&data[i]);
    }
    //创建二叉树
    root->left = createNode(data[1]);
    root->right = createNode(data[2]);
    root->left->left = createNode(data[3]);
    root->left->right = createNode(data[4]);
    root->right->left = createNode(data[5]);
    root->right->right = createNode(data[6]);
    root->left->left->left = createNode(data[7]);
    root->left->left->right = createNode(data[8]);
    root->left->right->left = createNode(data[9]);
    root->left->right->right = createNode(data[10]);
    root->right->left->left = createNode(data[11]);
    root->right->left->right = createNode(data[12]);
    root->right->right->left = createNode(data[13]);
    root->right->right->right = createNode(data[14]);
    printf("前序遍历结果: ");
    preOrderTraversal(root);
    printf("\n");
    printf("中序遍历结果: ");
    inOrderTraversal(root);
    printf("\n");
    printf("后序遍历结果: ");
    postOrderTraversal(root);
    printf("\n");
    printf("层次遍历结果: ");
    levelOrderTraversal(root);
    printf("\n");

    return 0;
}