#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

/**
 * @brief 体现最优子结构性质的递归法（朴素递归）
 */
int cutRod(const vector<int>& price, int n) {
    if(n == 0)
        return 0;
    int q = -1;
    for(int left{1}; left <= n; left++) {
        q = max(q, price[left - 1] + cutRod(price, n - left));  //这里可以清晰的看到最优解的结构（price[i] + cutRod(n-i))
                                                                //只有一个子问题cutRod(n-i)
                                                                //这里的**for循环&max函数**就是在穷举子问题，寻找邻接子问题中的最优解
    }
    return q;
}

int main() {
    int total{-1};
    vector<int> price{1,5,8,9,10,17,17,20,24,30};
    total = cutRod(price, 4);
    cout << total << endl;
    return 0;
}
