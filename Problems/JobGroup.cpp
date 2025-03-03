#include <iostream>
#include <unordered_map>
using namespace std;

long long T, n, k;

int main()
{
  cin >> T;  // 输入测试用例数量
  while (T--) {  // 遍历所有的测试用例
    cin >> n >> k; // 输入小队数量和目标要组成的纯职业小组数量
    --k;  // 目标小组数减一，因为后面可能会多选一个小组

    unordered_map<int, int> arr;  // 哈希表，用来存储每个职业士兵的总数
    int a, b;
    for (int i = 0; i < n; ++i) {  // 遍历所有的小队
      cin >> a >> b;  // 输入职业编号 a 和士兵数量 b
      arr[a] += b;  // 累加该职业士兵的数量
    }

    long long ret = 0;  // 用于记录最终需要选择的士兵数
    long long hash[4] = {0};  // 数组，用来存储剩余士兵数量的统计（1、2、3个士兵的剩余数）
    for (auto &e : arr) {  // 遍历所有职业的士兵数量
      int b = e.second;  // 获取当前职业的士兵数量

      // 如果该职业的士兵数量小于 3，直接加上士兵数量到结果
      if (b < 3) {
        ret += b;
      } else {  // 如果士兵数量大于等于 3
        ret += 2;  // 最多选2个士兵组成部分小队
        b -= 2;  // 减去已选择的2个士兵

        // 计算可以从当前职业剩余的士兵中组成多少个完整的小队
        hash[3] += b / 3;  // 完整的小队（每3个士兵组成一个小队）
        ++hash[b % 3];  // 剩余的士兵数量（1个或2个）放入对应的数组位置
      }
    }

    // 现在我们需要根据剩余的小队成员来尽量凑出剩余的k-1个小队
    for (int i = 3; i > 0; --i) {  // 从3个士兵的小队开始，尝试组成剩余的小队
      if (hash[i] < k) {  // 如果当前可以组成的小队数少于剩余需要的k个小队
        ret += i * hash[i];  // 选取尽可能多的小队
        k -= hash[i];  // 减少所需的小队数
        hash[i] = 0;  // 已经使用完该类小队
      }
      else {  // 如果剩余的可以组成的小队数足够，直接组成需要的小队
        ret += i * k;  // 选择剩余需要的小队
        k = 0;  // 所需小队已组成完
        hash[i] -= k;  // 减少已使用的数量
        break;  // 已经满足要求，可以结束
      }
    }

    // 如果剩下的士兵还可以组成小队（hash[3]、hash[2]、hash[1]中还有士兵）
    if (k == 0 && (hash[3] + hash[2] + hash[1]) > 0) {
      cout << ret + 1 << endl;  // 需要加上1个士兵，组成一个完整的小队
    } else {  // 如果无法组成足够的小队，输出 -1
      cout << -1 << endl;
    }
  }
  return 0;
}
