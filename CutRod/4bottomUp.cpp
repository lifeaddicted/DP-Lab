#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

/**
 * @brief 自底向上DP；
 *        自底向上的求解，需要将思维进行大逆转，比较考验编码能力
 *        需要注意以下几点：
 *        1. 因为是自底向上求解：因此**要从规模最小的子问题开始求解**
 *        2. 需要用到**2层for循环**
 *           第一层：求解不同规模的问题（**从小到大的顺序**）
 *           第二层：在当前规模的子问题中，寻找最优解(参看bottomUp.png就理解了)
 */
int cutRod(const vector<int>& price, int n) {
    // vector<int> r(n, -1);
    vector<int> r(n + 1, -1);   //dp数组（表格）其实就是**各个规模子问题的解**；因为r[0]有效，因此，数组大小为 n + 1
    r[0] = 0;
    for(int left{1}; left <= n; left++) {
        int q{-1};
        for(int right{1}; right <= left; right++)
            q = max(q, price[left] + r[right - left]);
        r[left] = q;
    }
    return r[n];
}

int main() {
    int total{-1};
    vector<int> price{1,5,8,9,10,17,17,20,24,30};
    total = cutRod(price, 4);
    cout << total << endl;
    return 0;
}
