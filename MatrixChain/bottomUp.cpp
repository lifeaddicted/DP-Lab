#include <vector>
#include <iostream>
#include <climits>

using namespace std;


/**
 * @brief bottomUp动态规划
 *        难点：
 *          1. dp表格的含义是什么?
 *               m[i,j]即表示A_{ij}，即矩阵链A_i~A_j的最小乘法次数
 *               换句话说，即问题规模i~j的最优解
 *          2. 内层for循环的遍历顺序如何确定?
 *               ==其实这个问题之所以理解不透彻，是因为对最优子结构理解还不够透彻==
 *               这个问题不理解，其实对于topDown方法的递归树也是不清晰的
 * 
 *               对于这个问题的解释是：
 *                   矩阵链A1~An的最少乘法次数，是一个规模(len)为n（矩阵链长度）的问题
 *                   其最优解的递归公式为
 *                   m[1,n] = min(m[1,k] + m[k+1,n] + p0*pk*pn)
 *                   k∈[1, n-1]，即是说，m[1,n]==依赖于所有规模(len) < n的问题的解
 *                   因此，第一层for循环，要按照规模从小到大的顺序求解，即 len from 2 to n
 *          
 *                   规模为len的子问题，有很多个，因此第二个for循环求解所有这些子问题（同时也就确定了i&j）
 *                   
 *                   接下来在这些len的子问题中选择最优解，即在遍历所有切分点（k）
 *                   找到最优解保存到m[i][j]
 * 
 *                   其实画一颗topDown的递归树之后，这个问题自然就解决了
 * 
 *               为了实现自底向上的方法，**必须确定m[i,j]的所有子问题的解**
 *               m[i,j]的含义上面已经给出
 *               要确定m[i,j]的最优值，就需要遍历所有m[i,k] + m[k+1,j] + p_{i-1}*p_k*p_j
 *               选出其中的最小值，而k的选择有 j - i 种[i, j - 1]
 *          3. dp表格如何初始化?
 */
int recursion(vector<int>& p, int n) {
    vector<vector<int>> m(n + 1, vector<int>(n + 1, -1));
    for(int i{1}; i <= n; i++)  //注意这里的初始化
        m[i][i] = 0;

    // for(int i{1}; i <= n; i++) {    //从小到大，求解各个规模的问题
    for(int len{2}; len <= n; len++) {  //这里的问题规模指的是矩阵链的长度，应该从2开始；长度为1是平凡的，乘法次数为0
                                        //长度为2的链有很多，第二层for循环就是遍历这些长度为2的链
                                        //为什么要确定所有长度为2的最优解呢？因为长度为3的链，依赖于长度为2的解
                                        //其实这里最难的地方在于，这是个二维dp表格
                                        //之所以是二维的，原因在于：问题切分之后变成了**两个子问题**，问题的最优解需要组合两个子问题的最优解
                                        //（这么说也不对，爬楼梯也是两个子问题），那区别到底在哪里呢?
        for(int i{1}; i <= n - len + 1; i++){   //这一步是最难的；之所以难，是因为对递推公式以及topDown的递归树理解还不到位
            int j = i + len - 1;
            int minCnt{INT_MAX};
            for(int k{i}; k < j; k++){  //内层for循环应该遍历len规模问题的所有切分点
                minCnt = min(minCnt, m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]);
            }
            m[i][j] = minCnt;
        }
    }

    return m[1][n];
}

int main() {
    //矩阵规模数组
    vector<int> p{30, 35, 15, 5, 10, 20, 25};
    cout << recursion(p, p.size() - 1) << endl;
    return 0;
}