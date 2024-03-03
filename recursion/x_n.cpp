/*
求x的n次方
*/

#include <iostream>
using namespace std;

// O(n)
int x_Power_n(int x, int n){
    int res = 1;
    for (int i = 0; i < n; i++){
        res = res * x;
    }
    return res;
}

// 仍然是O(n)
int x_Power_n_recursion(int x, int n){
    if (n == 0) return 1;
    if (n == 1) return x;
    if ((n % 2) == 1) {
        return x_Power_n_recursion(x, n / 2) * x_Power_n_recursion(x, n / 2) * x;
    }
    return x_Power_n_recursion(x, n / 2) * x_Power_n_recursion(x, n / 2);
}

// 保存递归计算结果，避免重复计算，时间复杂度降低为O(logn)
int x_Power_n_recursion_log(int x, int n){
    if (n == 0) return 1;
    if (n == 1) return x;
    int t = x_Power_n_recursion(x, n / 2);
    if ((n % 2) == 1) {
        return t * t * x;
    }
    return t * t;
}

int main(){
    int x = 3, n = 3;
    int res = x_Power_n(x, n);
    int res2 = x_Power_n_recursion(x, n);
    int res3 = x_Power_n_recursion_log(x, n);
    cout << res << endl;
    cout << res2 << endl;
    cout << res3 << endl;
}