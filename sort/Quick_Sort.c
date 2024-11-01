#include <stdio.h>

void quicksort(int* arr, int low, int high) {
    if (low < high) {
        int start = low, end = high;
        int base = arr[low];

        while (low < high) {
            // 从右向左找到第一个小于基准值的元素
            while (low < high && arr[high] >= base) {
                high--;
            }
            arr[low] = arr[high];

            // 从左向右找到第一个大于基准值的元素
            while (low < high && arr[low] <= base) {
                low++;
            }
            arr[high] = arr[low];
        }
        // 将基准值放到中间位置
        arr[low] = base;

        // 递归排序左右两部分
        quicksort(arr, start, low - 1);
        quicksort(arr, low + 1, end);
    }
}

int main() {
    int n, arr[100];
    printf("Please enter the number of integers: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quicksort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}