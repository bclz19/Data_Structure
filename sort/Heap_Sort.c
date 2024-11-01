#include <stdio.h>

// 交换函数
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 大根堆的建堆
void max_heapify(int *arr, int start, int end) {
    int dad = start;
    int son = 2 * dad + 1;
    while (son <= end) {
        if (son + 1 <= end && arr[son] < arr[son + 1]) {
            son++;
        }
        if (arr[dad] >= arr[son]) {
            return;
        } else {
            swap(&arr[dad], &arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

// 堆排序
void heap_sort(int *arr, int start, int end) {
    for (int i = end / 2; i >= 0; i--) {
        max_heapify(arr, i, end);
    }
    for (int i = end; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        max_heapify(arr, 0, i - 1);
    }
}

int main() {
    int n, arr[100];
    printf("Please enter the number of integers: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    heap_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}