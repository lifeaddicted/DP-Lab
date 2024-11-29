#include <iostream>

using namespace std;

int cnt{0};

/**
 * @brief 回溯法
 *        为什么称为回溯法？
 *        因为其实并没有用到子结构性质，只是在叶子节点对数目进行统计
 *        回溯隐藏在n-1，n-2中
 * 
 *        并且是模拟从楼梯顶往下倒退的方式（而这才符合递归的逻辑）
 *        而不是从下往上爬的方式
 */
int climbStairs(int n) {
    if(n < 0)
        return 0;
    if(n == 0) {
        ++cnt;
        return cnt;
    }

    climbStairs(n - 1);
    climbStairs(n - 2);

    return cnt;
}

int main() {
    cout << climbStairs(44) << endl;
    return 0;
}