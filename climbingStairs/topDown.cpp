#include <iostream>
#include <vector>

using namespace std;


vector<int> memo(45, -1);
/**
 * @brief topDown动态规划
 *        在朴素递归的基础上增加备忘
 */
int climbStairs(int n) {
    if(memo[n] >= 0)
        return memo[n];
    // if(n < 0)
    //     return 0;
    // if(n == 0)
    //     return 1;
    if(n < 3) {         //这里topDown将返回1，变为给memo赋值还挺烧脑的
        memo[n] = n;
        return n;
    }

    // int cnt = climbStairs(n - 1) + climbStairs(n - 2);
    memo[n] = climbStairs(n - 1) + climbStairs(n - 2);

    return memo[n];
}

int main() {
    cout << climbStairs(44) << endl;
    return 0;
}