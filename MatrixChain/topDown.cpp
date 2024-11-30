#include <vector>
#include <iostream>
#include <climits>

using namespace std;

vector<vector<int>> memo(7, vector<int>(7, -1));

/**
 * @brief topDown动态规划
 */
int recursion(vector<int>& p, int i, int j) {
    if(memo[i][j] >= 0)
        return memo[i][j];

    if(i == j) {
        memo[i][j] = 0;
        return 0;
    }

    int minCnt{INT_MAX};
    for(int k{i}; k < j; k++) {    //1.此处为什么k不能等于j?
        minCnt = min(minCnt, recursion(p, i, k) + recursion(p, k + 1, j) + p[i - 1] * p[k] * p[j]);
    }
    memo[i][j] = minCnt;
    return minCnt;
}

int main() {
    //矩阵规模数组
    vector<int> p{30, 35, 15, 5, 10, 20, 25};
    cout << recursion(p, 1, p.size() - 1) << endl;
    return 0;
}