#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

// vector<int> memo(4, -1);    //备忘录 | 注意备忘录的长度！！！很关键
vector<int> memo(5, -1);    //备忘录 | 对于递归来说，备忘录初不初始化都可以

/**
 * @brief 带备忘的自顶向下DP
 *        可以看到，其实带备忘的递归解法很简单，只是做了如下改变
 *        1. 在递归入口处检查备忘录
 *        2. 每个节点处理完后（即每个子问题第一次求解完后），将解放入备忘录中（dp数组）
 *        3. 注意备忘录的长度，一般为问题规模的+1（即**n+1**）
 */
int cutRod(const vector<int>& price, int n) {
    if(memo[n] >= 0)    //使用备忘录（dp数组）；如果子问题有结果，立即返回
        return memo[n];
    int q = -1;         //这个初始化很重要；虽然说递归是自顶向下，但其实值的求解还是自底向上的
                        //因此每一层（即每一个子问题）的解一开始是未知的，要初始化为一个无意义的值，然后从子问题中筛选最优解
    if(n == 0) {
        memo[n] = 0;    //记录子问题的解
        return 0;
    }
    for(int left{1}; left <= n; left++) {
        q = max(q, price[left - 1] + cutRod(price, n - left));
    }
    memo[n] = q;        //记录子问题的解
    return q;
}

int main() {
    int total{-1};
    vector<int> price{1,5,8,9,10,17,17,20,24,30};
    // memo[0] = 0;             初不初始化都可以
    // memo[1] = price[0];
    total = cutRod(price, 4);
    cout << total << endl;
    cout << memo[2] << endl;
    return 0;
}
