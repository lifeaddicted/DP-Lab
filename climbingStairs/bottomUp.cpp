#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief bottomUp动态规划
 */
int climbStairs(int n) {
    vector<int> memo(45, -1);
    memo[1] = 1;
    memo[2] = 2;

    for(int i{3}; i <= n; i++)
        memo[i] = memo[i - 1] + memo[i - 2];

    return memo[n];
}

int main() {
    cout << climbStairs(44) << endl;
    return 0;
}