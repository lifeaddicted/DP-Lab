#include <string>
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief bottomUp动态规划
 *        最优子结构性质：《两个串的lcs总是包含它们前缀的lcs》
 * 
 *        bottomUp最难的还是子问题的遍历顺序；
 *        最好的办法还是首先确定**问题的规模是什么**
 *        然后画出dp表，进行推演
 * 
 *        用l[i][j]表示X_i与Y_j的lcs
 *        根据递推公式
 *        l[i][j] = 0 i=0或j=0（空串没有子序列）
 *        l[i][j] = l[i - 1][j - 1] + 1
 *        l[i][j] = max{l[i][j - 1], l[i - 1][j]}
 *        可知，需将i=0, j=0的所有元素置零
 * 
 *        遍历顺序，参看bottomUp图片(可以表述为**行主次序**，即外层先遍历行，内层遍历列)
 * 
 *        **这个版本返回的是最优值，而不是最优解**
 */
int recursion(string s1, int n, string s2, int m) {
    vector<vector<int>> l(m + 1, vector<int>(n + 1, -1));

    //初始化
    for(int j{0}; j < n + 1; j++)   //  这里在构造表时，把s1做行，s2做列就更好理解了，不然索引绕来绕去
        l[0][j] = 0;
    for(int i{0}; i < m + 1; i++)
        l[i][0] = 0;

    for(int i{1}; i <= m; i++) {        //遍历dp表的行
        for(int j{1}; j <= n; j++) {    //遍历dp表的列
            if(s1[j - 1] == s2[i - 1])
                l[i][j] = l[i - 1][j - 1] + 1;
            else
                l[i][j] = max(l[i][j - 1], l[i - 1][j]);
        }
    }

    return l[m][n];
}

///用i表示s1的版本，好理解多了
int recursion2(string s1, int n, string s2, int m) {
    vector<vector<int>> l(n + 1, vector<int>(m + 1, -1));

    //初始化
    for(int i{0}; i < n + 1; i++)
        l[i][0] = 0;
    for(int j{0}; j < m + 1; j++)
        l[0][j] = 0;

    for(int i{1}; i <= n; i++) {        //遍历dp表的行
        for(int j{1}; j <= m; j++) {    //遍历dp表的列
            if(s1[i - 1] == s2[j - 1])
                l[i][j] = l[i - 1][j - 1] + 1;
            else
                l[i][j] = max(l[i][j - 1], l[i - 1][j]);
        }
    }

    return l[n][m];
}

int main() {
    string s1("ACCGGTCGAGTGCGCGGAAGCCGGCCGAA");
    string s2("GTCGTTCGGAATGCCGTTGCTCTGTAAA");
    string s3("GTCGTCGGAAGCCGGCCGAA");
    // cout << s1.size() << endl;
    // cout << s2.size() << endl;
    // string s1("hell");
    // string s2("eil");
    cout << s3 << endl;
    cout << s3.size() << endl;
    cout << recursion(s1, s1.size(), s2, s2.size()) << endl;
    cout << recursion2(s1, s1.size(), s2, s2.size()) << endl;
    return 0;
}