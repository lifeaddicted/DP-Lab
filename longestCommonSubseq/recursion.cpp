#include <string>
#include <iostream>

using namespace std;

/**
 * @brief DP风格递归
 *        最优子结构性质：《两个串的lcs总是包含它们前缀的lcs》
 * 
 *        还是一样，返回值是两个前缀的lcs（最优解）
 *        这是使用substr构造新串的方式，比较费空间，可以用传索引的方式，避免构造新串
 * 
 *        1. 参数&返回值
 *              参数：两个串的前缀
 *              返回值：两个前缀的lcs
 *        2. 单层逻辑
 *              若两个前缀的尾字符相同
 *              则递归地寻找两个前缀缩减1个字符后的lcs
 *              待递归返回后，将改为字符添加到返回的lcs后
 *        3. 返回条件
 *              当到达X_0或Y_0时（此时前缀为空串）
 *              空串没有子序列，更不用谈lcs
 *              返回空串
 * 
 *          递归树分析：从递归树树可以看出
 *              lcs**只有在两个前缀的尾字符相同时，才会增长**
 *              当尾字符不同时，会优先将s2缩减1，继续比较
 *              返回后，将s1缩减1，再继续比较
 *              因此，树中节点要么出度为1，要么出度为2（或0）
 */
string recursion(string s1, string s2) {
    if(s1.empty() || s2.empty())
        return "";

    string lcs;
    if(s1.back() == s2.back()) {
        lcs = recursion(s1.substr(0, s1.size() - 1), s2.substr(0, s2.size() -1));
        lcs.push_back(s1.back());
    }
    else {
        string tmp1 = recursion(s1, s2.substr(0, s2.size() - 1));
        string tmp2 = recursion(s1.substr(0, s1.size() - 1), s2);
        lcs = tmp1.size() > tmp2.size() ? tmp1 : tmp2;
    }

    return lcs;
}

///传索引版本；索引版本更能体现备忘如何构造
string recursion(string s1, int i, string s2, int j) {
    if(i < 0 || j < 0)
        return "";

    string lcs;
    if(s1[i] == s2[j]) {
        lcs = recursion(s1, i - 1, s2, j - 1);
        lcs.push_back(s1[i]);
    }
    else {
        string tmp1 = recursion(s1, i, s2, j - 1);
        string tmp2 = recursion(s1, i - 1, s2, j);
        lcs = tmp1.size() > tmp2.size() ? tmp1 : tmp2;
    }

    return lcs;
}

int main() {
    // string s1("ACCGGTCGAGTGCGCGGAAGCCGGCCGAA");
    // string s2("GTCGTTCGGAATGCCGTTGCTCTGTAAA");
    // string s3("GTCGTCGGAAGCCGGCCGAA");
    string s1("hell");
    string s2("eil");
    cout << recursion(s1, s2) << endl;
    cout << recursion(s1, s1.size() - 1, s2, s2.size() - 1) << endl;
    return 0;
}