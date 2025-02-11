#include <iostream>
#include <ctime>
#include <chrono>  // 引入 chrono 库

const int maxsize = 50000;  // maxsize为待排序表的长度
using namespace std;
#define RcdType int

// 定义待排序的表结构
struct Node {
    int key;
};

// 定义待排序的表结构
struct Sqlist {
    int length;
    Node r[maxsize];
};

// 对待排序的表进行初始化
void Initlist(Sqlist &L) {
    srand(1);
    for (int i = 0; i < maxsize; i++)  // 产生 maxsize 个随机数
        L.r[i].key = rand();
    L.length = maxsize;
}

// 直接插入排序
void Insertsort(Sqlist &L) {
    for (int i = 1; i < L.length; i++) {
        for (int j = 0; j < i; j++) {
            if (L.r[i].key < L.r[j].key) {
                // 其他项移后
                int temp = L.r[i].key;  // 最后一个元素
                for (int k = i; k >= j; k--) {
                    L.r[k].key = L.r[k - 1].key;
                }
                L.r[j].key = temp;
            }
        }
    }
}

// 起泡排序
void Bubblesort(Sqlist &L) {
    int status = 1;
    while (status) {
        status = 0;
        for (int i = 0; i < L.length - 1; i++) {
            if (L.r[i].key > L.r[i + 1].key) {
                int temp = L.r[i].key;
                L.r[i].key = L.r[i + 1].key;
                L.r[i + 1].key = temp;
                status = 1;
            }
        }
    }
}

// 直接选择排序
void Selectsort(Sqlist &L) {
    for (int i = 0; i < L.length; i++) {
        int min = L.r[i + 1].key;
        int index_m = i + 1;
        // 找到最小值
        for (int j = i; j < L.length; j++) {
            if (min > L.r[j].key) {
                min = L.r[j].key;
                index_m = j;
            }
        }
        L.r[index_m].key = L.r[i].key;
        L.r[i].key = min;
    }
}
// 快速排序
void QuickSort(Sqlist &L, int start, int end) {
    if (start >= end) return;
    int ptr1 = start;
    int ptr2 = end;
    while (ptr1 != ptr2) {
        if ((L.r[ptr2].key - L.r[ptr1].key) * (ptr2 - ptr1) < 0) {
            int temp = L.r[ptr2].key;
            L.r[ptr2].key = L.r[ptr1].key;
            L.r[ptr1].key = temp;

            temp = ptr2;
            ptr2 = ptr1;
            ptr1 = temp;
        } else {
            if (ptr2 > ptr1) ptr2--;
            else ptr2++;
        }
    }

    QuickSort(L, start, ptr1 - 1);
    QuickSort(L, ptr1 + 1, end);
}
void heapSort(Sqlist &L){
    
}

// 显示表
void Display(const Sqlist &L) {
    cout << "           ";
    for (int i = 0; i < L.length; i++) {
        cout << L.r[i].key << " ";
    }
    cout << endl;
}

int main() {
    Sqlist L;
    int k;

    // 使用 chrono 来记录高精度时间
    using namespace std::chrono;
    steady_clock::time_point t1, t2;
    double tt = 0.0;

    cout << "\n\n\n\n";
    cout << "\t\t       排序 子系统\n";
    cout << "\t\t*****************************\n";
    cout << "\t\t*     1----初始化待排表     *\n";
    cout << "\t\t*     2----直接插入排序     *\n";
    cout << "\t\t*     3----冒 泡 排  序    *\n";
    cout << "\t\t*     4----直接选择排序     *\n";
    cout << "\t\t*     5----快 速 排 序     *\n";
    cout << "\t\t*     0----返      回      *\n";
    cout << "\t\t*****************************\n";

    do {
        cout << "\t\t   请选择菜单项(0－5)：";
        cin >> k;

        t1 = steady_clock::now();  // 记录开始时间

        switch (k) {
            case 1:
                Initlist(L);
                break;
            case 2:
                Insertsort(L);
                t2 = steady_clock::now();  // 记录结束时间
                tt = duration_cast<milliseconds>(t2 - t1).count();  // 计算时间差，转化为毫秒
                cout << "           直接插入排序的时间是：" << tt << " 毫秒." << endl;
                break;
            case 3:
                Bubblesort(L);
                t2 = steady_clock::now();
                tt = duration_cast<milliseconds>(t2 - t1).count();
                cout << "           冒泡排序的时间是：" << tt << " 毫秒." << endl;
                break;
            case 4:
                Selectsort(L);
                t2 = steady_clock::now();
                tt = duration_cast<milliseconds>(t2 - t1).count();
                cout << "           直接选择排序的时间是：" << tt << " 毫秒." << endl;
                break;
            case 5:
                QuickSort(L, 0, L.length - 1);
                t2 = steady_clock::now();
                tt = duration_cast<milliseconds>(t2 - t1).count();
                cout << "           快速排序的时间是：" << tt << " 毫秒." << endl;
                break;
            case 0:
                Display(L);
                break;
            default:
                exit(666);
        }
    } while (k);

    return 0;
}
