#include<vector>
#include<iostream>
using namespace std;

class Sorting {
public:
    int rounds = 0;     //外层循环的执行次数
    //这是选择排序的交换版本，选择排序是每轮经过一一比较挑出最大的放在最后面
    vector<int> Bubble_Sort(vector<int> nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            rounds++;
            for (int j = i + 1; j < n; j++) {
                //若某次靠左的数小于等于右边的数了，下次比较的就不是相邻的两个元素了，因为j照样+1，而i没变
                if (nums[i] > nums[j]) {
                    int temp = nums[j];
                    nums[j] = nums[i];
                    nums[i] = temp;
                }
            }
        }
        return nums;
    }

    //冒泡排序：每轮两两相邻元素进行比较，若左边的数大于右边的数，则交换位置，第一遍会将最大的数移到最后面，第二遍将第二大的数移到倒数第二位，以此类推。
    vector<int> Bubble_sort2(vector<int> nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            rounds++;
            //只对相邻元素进行比较，这是冒泡排序的核心思想
            for (int j = 0; j < n - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }
        return nums;
    }

    /*优化版本1：为防止排序已经完成但外层循环依然徒然继续，设置bool变量flag,
     *若某次外层循环没有对数组进行改动说明排序已经完成，不再进入下次外层循环
     */
    vector<int> Bubble_sort21(vector<int> nums) {
        int n = nums.size();
        bool flag = true;       //flag变量用于表示标记是否进入内层循环，即上次外层循环内是否执行冒泡排序操作
        for (int i = 0; i < n - 1 && flag; i++) {
            flag = false;
            rounds++;
            for (int j = 0; j < n - i - 1; j++) {
                if (nums[j] > nums[j+1]) {
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                    flag = true;
                }
            }
        }
        return nums;
    }
};

int main() {
    vector<int> a = {7,1,2,3,6,4,5};
    Sorting sort;

    vector<int> sorted1 = sort.Bubble_Sort(a);
    for (int i = 0; i <= a.size() - 1; i++) {
        cout << sorted1[i] << " ";
    }
    cout << endl << "排序轮数：" << sort.rounds << endl;
    sort.rounds = 0;

    vector<int> sorted2 = sort.Bubble_sort2(a);
    for (int i = 0; i <= a.size() - 1; i++) {
        cout << sorted2[i] << " ";
    }
    cout << endl << "排序轮数：" << sort.rounds << endl;
    sort.rounds = 0;

    vector<int> sorted3 = sort.Bubble_sort21(a);
    for (int i = 0; i <= a.size() - 1; i++) {
        cout << sorted3[i] << " ";
    }
    cout << endl << "排序轮数：" << sort.rounds << endl;
    sort.rounds = 0;
    return 0;
}