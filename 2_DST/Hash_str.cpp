#include<iostream>
#include<cstring>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;

///字符串的映射
////即判断字符串是否相同
///////eg.   ABCD的映射
/////////(1 * P^3 + 2 * P^2 + 3 * P^2 + 4 * P^0)
////////P一般取 131   ////13331
///////Hash(str) = sum(P) % Q      .
//一般 Q = 2^64，即直接设置为 unsigned long long
////////帮助判断每个区间内字符串是否相同

// int search_first_N(int x){
//     for(int i = x ;;++i){
//         bool flag = true;
//         for(int j = 2 ; j * j < i ; ++j){
//             if (i % j == 0){
//                 flag = false ;
//                 break;
//             }
//         }
//         if(flag){
//             return i;
//         }
//     }
// }
// const int N = search_first_N(100000);///////最好为质数
// const int INF = 1e9;
typedef unsigned long long ULL;
const int  N = 1000010 , P = 131;
char str[N];/////比较字符串？？？？？？
ULL h[N] , p[N] ; 
int n , m;
///////返回字符串的Hash
ULL get_Hash(int a, int b){
    return h[b] - h[a - 1] * p[b - a + 1];
}
// 8 3
// aabbaabb
// 1 3 5 7
// 1 3 6 8
// 1 2 1 2
////str从1开始
int main(){
    scanf("%d%d%s" , &n ,&m,str +1);
    p[0] = 1;
    ///初始化p,h
    for(int i = 1; i <= n;++i){
        p[i] = p[i-1] * P;
        h[i] = h[i-1] * P + str[i];
    }
    while(m--){
        int a , b , c , d;
        scanf("%d%d%d%d" , &a , &b , &c , &d);
        if (get_Hash(a,b) == get_Hash(c,d))
            puts("Yes");
        else
            puts("No");
    }
    printf("\nC 艹 mother fucker\n");
    system("pause");
}
