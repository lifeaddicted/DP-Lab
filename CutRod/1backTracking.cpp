#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

vector<int> slices;

/**
 * @brief 钢条切割的回溯解法
 *        可以看到，回溯法是在**叶子节点**才对解进行计算；没有体现出DP中**组合子问题的解**的步骤
 *        换句话说，回溯是树的前序遍历；DP是树的后序遍历
 */
void backTracking(const vector<int>& price, int n, int startIndex, int& total) {
    if(startIndex >= n) {
        int tmp{0};
        for(auto slice: slices)         //回溯法会有一个解集合（slices）保存每一次的选择；在叶子节点再计算最终值
            tmp += price[slice - 1];
        if(tmp > total) {
            total = tmp;
            for(auto slice: slices)
                cout << slice << ' ';
            cout << endl;
        }
        return;
    }
    for(int left{startIndex}; left < n; left++) {
        slices.push_back(left - startIndex + 1);
        backTracking(price, n, left + 1, total);    //DP中组合子问题的解，应该体现在这里；递归应有返回值
        slices.pop_back();
    }
}

int main() {
    int total{-1};
    vector<int> price{1,5,8,9,10,17,17,20,24,30};
    backTracking(price, 6, 0, total);
    cout << total << endl;
    return 0;
}
