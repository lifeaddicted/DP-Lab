#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<std::string>> memo(30, vector<string>(29, "-1"));

/**
 * @brief topDown动态规划
 *        最优子结构性质：《两个串的lcs总是包含它们前缀的lcs》
 * 
 *        因为memo需要初始化，使用索引时进行了一些改造
 *        这里的备忘因为做成全局的，不同串需要改代码进行初始化
 */
string recursion(string s1, int i, string s2, int j) {
    if(memo[i][j] != "-1")
        return memo[i][j];      //这里得到的已经是最优解了；但是字符串形式的最优解这样判断有点不高效
                                //可以先求最优值（lcs的长度），最优解求解完成后再构造
    
    if(i == 0 || j == 0) {
        memo[i][j] = "";
        return "";
    }

    string lcs;
    if(s1[i - 1] == s2[j - 1]) {
        lcs = recursion(s1, i - 1, s2, j - 1);
        lcs.push_back(s1[i - 1]);
    }
    else {
        string tmp1 = recursion(s1, i, s2, j - 1);
        string tmp2 = recursion(s1, i - 1, s2, j);
        lcs = tmp1.size() > tmp2.size() ? tmp1 : tmp2;
    }

    memo[i][j] = lcs;

    return lcs;
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
    cout << recursion(s1, s1.size(), s2, s2.size()) << endl;
    return 0;
}