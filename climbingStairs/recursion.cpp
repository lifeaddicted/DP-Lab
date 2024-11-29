#include <iostream>

using namespace std;

/**
 * @brief DP风格的朴素递归
 *        利用了“最优”子结构性质（因为这并不是最优化问题，所以最优加了引号）
 *        特点：
 *          1. 递归有返回值
 *          2. 返回当前规模的（最优）解
 */
int climbStairs(int n) {
    if(n < 0)
        return 0;
    if(n == 0)
        return 1;

    int cnt = climbStairs(n - 1) + climbStairs(n - 2);

    return cnt;
}

int main() {
    cout << climbStairs(44) << endl;
    return 0;
}