#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief bottomUp动态规划
 *        在求解最优值的过程中，记录每一步的信息
 *        并根据该信息构造最优解
 * 
 *        构造最优解的过程，其实是简单的
 *        **从rec[n][m]开始**即可，这是一个==逆序==的过程
 * 
 *        注意构造时使用枚举的陷阱，小心default！！！
 */
int recursion2(string s1, int n, string s2, int m) {
    vector<vector<int>> l(n + 1, vector<int>(m + 1, -1));
    vector<vector<int>> rec(n + 1, vector<int>(m + 1, -1));     //记录每一步的选择
    enum {
        LEFT,
        TOP,
        OTHER
    };

    //初始化
    for(int i{0}; i < n + 1; i++)
        l[i][0] = 0;
    for(int j{0}; j < m + 1; j++)
        l[0][j] = 0;

    for(int i{1}; i <= n; i++) {        //遍历dp表的行
        for(int j{1}; j <= m; j++) {    //遍历dp表的列
            if(s1[i - 1] == s2[j - 1]) {
                l[i][j] = l[i - 1][j - 1] + 1;
                rec[i][j] = OTHER;      //记录选择
            }
            else {
                l[i][j] = max(l[i][j - 1], l[i - 1][j]);
                rec[i][j] = l[i][j - 1] > l[i - 1][j] ? LEFT : TOP;
            }
        }
    }

    //构造最优解
    string str;
    // for(int i{n}, j{m}; i > 0 || j > 0;) {   //不是或条件。。。。死循环
    for(int i{n}, j{m}; i > 0 && j > 0;) {
        switch(rec[i][j]) {
            case LEFT:
                --j;
                break;
            case TOP:
                --i;
                break;
            // default:     //注意，不要用default；因为数组的元素总会是个整型值。。。。
                            //最优解莫名其妙多了几个字符，查了半天
            case OTHER:
                str.push_back(s1[i - 1]);
                --i, --j;
                break;
        }
    }
    reverse(str.begin(), str.end());
    cout << str.size() << endl;
    cout << str << endl;

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
    cout << "solution: " << endl;
    cout << recursion2(s1, s1.size(), s2, s2.size()) << endl;
    return 0;
}