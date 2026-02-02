//冒泡算法1(n^2)
void bubbleSort1(int a[],int n){
    int i,j,tmp;
    for (i=1;i<=n-1;i++){
        for (j=0;j<=n-1-i;j++){
            if (a[j]>a[j+1]){  //两两比较
                tmp=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
            }
        }
    }
}

//冒泡算法2
int bubbleSort2(int a[], int n) {
    int i, j, tmp, swap;
    for(i=1, swap=1; i<=n-1 && swap>0; i++){//若某一趟无任何元素交换，说明数组已有序，直接终止循环
        for(j=0, swap=0; j<=n-1-i; j++){//记录交换个数
            if(a[j] > a[j+1]){
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                swap++;
            }
        }
    }
    return i-1; // 返回实际执行的排序趟数
}

//judge a[] is up sort?
int isSort(int a[],int n)
{
    int i,sorted;
    for(i=0,sorted=1; i<=n-2 && sorted==1; i++){
        if(a[i] > a[i+1])
            sorted=0;
    }

    return sorted;
}


// 插入排序（升序）(n^2)
void InsertSort(int a[], int n) {
    // 从第2个元素开始（i=1），逐个插入到已排序区间
    for (int i = 1; i < n; i++) {
        int temp = a[i];  // 保存当前要插入的元素
        int j = i - 1;    // 已排序区间的最后一个元素下标
        
        // 向前遍历已排序区间：若元素大于temp，则后移
        while (j >= 0 && a[j] > temp) {
            a[j + 1] = a[j];  // 元素后移，腾出插入位置
            j--;
        }
        a[j + 1] = temp;  // 将temp插入到正确位置
    }
}


//快速排序(升序)(n*log n)
// 划分函数：返回基准元素的最终索引
int partition(int a[], int low, int high) {
    int pivotkey = a[low]; // 基准值（区间第一个元素）
    while (low < high) {
        // 从右往左找小于基准的元素
        while (low < high && a[high] >= pivotkey) high--;
        a[low] = a[high];
        // 从左往右找大于基准的元素
        while (low < high && a[low] <= pivotkey) low++;
        a[high] = a[low];
    }
    a[low] = pivotkey; // 基准值放入最终位置
    return low;
}
// 主函数（递归版）：排序区间 [low, high]
void quick_sort(int a[], int low, int high) {
    int pivotloc;
    if (low < high) { // 递归终止条件：区间长度≤1
        pivotloc = partition(a, low, high); // 划分区间
        quick_sort(a, low, pivotloc - 1); // 排序左子区间
        quick_sort(a, pivotloc + 1, high); // 排序右子区间
    }
}


//二分查找（序列有序）(log n);
int binarySearch(int nums[], int n, int target) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
//二分查找（递归）
int RecurBinarySearch(int a[],int key,int left,int right){
    if (left > right) {
        return -1;
    }
    int mid = left + (right - left) / 2;
    if (a[mid] == key) {
        return mid;
    } else if (key < a[mid]) {
        return RecurBinarySearch(a, key, left, mid - 1);
    } else {
        return RecurBinarySearch(a, key, mid + 1, right);
    }
}



//用库排序qsort（升序）
#include <stdio.h>
#include <stdlib.h>
// 比较函数：a > b返回正数，a == b返回0，a < b返回负数
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
int main() {
    int arr[] = {3, 1, 4, 1, 5, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    qsort(arr, n, sizeof(int), cmp); // 调用库函数排序
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}

/*<string.h>
strncat(dest, src, n);把src拼接到dest后面
 strncpy是copy覆盖
 */

//归并算法（n*log n）
// 合并两个有序子数组：nums[left...mid] 和 nums[mid+1...right]
#include <stdlib.h>
#include <string.h>
void merge(int nums[], int left, int mid, int right) {
    int len = right - left + 1;
    int temp[len]; // 临时数组存储合并结果
    int i = left;   // 左子数组指针
    int j = mid + 1;// 右子数组指针
    int k = 0;      // 临时数组指针
    // 合并两个有序子数组到临时数组
    while (i <= mid && j <= right) {
        // 相等时取左子数组元素，保证稳定性
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
        }
    }
    // 处理左子数组剩余元素
    while (i <= mid) {
        temp[k++] = nums[i++];
    }
    // 处理右子数组剩余元素
    while (j <= right) {
        temp[k++] = nums[j++];
    }
    // 将临时数组拷贝回原数组
    for (k = 0; k < len; k++) {
        nums[left + k] = temp[k];
    }
}
// 递归拆分：nums[left...right]
void mergeSortRecursive(int nums[], int left, int right) {
    // 终止条件：子数组长度<=1（天然有序）
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2; 
    mergeSortRecursive(nums, left, mid); 
    mergeSortRecursive(nums, mid + 1, right); 
    merge(nums, left, mid, right); 
}
// 对外接口：排序整个数组
void mergeSort(int nums[], int n) {
    mergeSortRecursive(nums, 0, n - 1);
}


//归并算法（迭代）(n*log n)（#include <stdlib.h>   #include <string.h>）
void mergeSortIterative(int nums[], int n) {
    if (nums == NULL || n <= 1) return;
    for (int len = 1; len < n; len *= 2) {
        for (int left = 0; left < n; left += 2 * len) {
            int mid = left + len - 1;
            int right = left + 2 * len - 1;
            if (mid >= n - 1) continue; 
            if (right >= n) right = n - 1;
            merge(nums, left, mid, right);
        }
    }
}



//约瑟夫环
void josephusArray(int n, int m) {
    int people[n]; // 数组标记：1表示存活，0表示出列
    int count = 0; // 已出列人数
    int index = 0; // 当前遍历到的位置
    int step = 0;  // 报数计数器
    // 初始化：所有人都存活
    for (int i = 0; i < n; i++) {
        people[i] = 1;
    }
    printf("出列顺序：");
    // 直到只剩最后一人
    while (count < n - 1) {
        // 只对存活的人报数
        if (people[index] == 1) {
            step++; // 报数加1
            // 报到m的人出列
            if (step == m) {
                printf("%d ", index + 1); // 输出编号（从1开始）
                people[index] = 0;        // 标记为出列
                count++;                  // 出列人数加1
                step = 0;                 // 重置报数
            }
        }
        index = (index + 1) % n; // 循环遍历（形成圈）
    }
    // 找出最后存活的人
    printf("\n最后存活的人：");
    for (int i = 0; i < n; i++) {
        if (people[i] == 1) {
            printf("%d\n", i + 1);
            break;
        }
    }
}

