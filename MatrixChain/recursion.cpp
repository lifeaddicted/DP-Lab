#include <vector>
#include <iostream>
#include <climits>

using namespace std;

/**
 * @brief DP风格递归
 *        1. 首先明确单个递归函数的作用，参数，返回值
 *              计算当前规模矩阵链的最少标量乘法次数
 *              因此，参数要有p,i,j；表示矩阵链的范围
 *              返回值为本链的最少标量乘法次数
 *        2. 返回条件：
 *              i=j时；矩阵本身，返回乘法次数0
 *        3. 单层递归逻辑
 *              根据问题的最优子结构和递推公式，在邻接子问题选择最优解
 *              递推公式如下
 *              m[i, j] = m[i, k] + m[k+1, j] + p_{i-1}*p_k*p_j
 */
int recursion(vector<int>& p, int i, int j) {
    if(i == j)
        return 0;

    int minCnt{INT_MAX};
    for(int k{i}; k < j; k++) {    //1.此处为什么k不能等于j?
                                   //因为矩阵乘法是个二元运算，切分的意义是两个矩阵间插入括号
                                   //k=j之后，划分出的右边子链为空，是没有意义的
                                   //如果将条件改为 k <= j，返回条件变为 i >= j
                                   //仍然会陷入死循环；因为当k=j之后，左子链会被反复求解，永无止境
        minCnt = min(minCnt, recursion(p, i, k) + recursion(p, k + 1, j) + p[i - 1] * p[k] * p[j]);
    }
    return minCnt;
}

int main() {
    //矩阵规模数组
    vector<int> p{30, 35, 15, 5, 10, 20, 25};
    cout << p.size() << endl;
    // cout << recursion(p, 1, p.size()) << endl;       //j传错了，导致一直输出0
    cout << recursion(p, 1, p.size() - 1) << endl;
    return 0;
}