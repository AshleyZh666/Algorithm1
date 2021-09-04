#include<iostream>
#include<cstring>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;

///拉链法即  链表法
////功能有添加，查找，删除（等同于查找，即找到后标记为false）


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
const int N = 1000003;
int n ;
int h[N];//////// 替代链表的数组
// 如果x在哈希表中，返回x的下标；如果x不在哈希表中，返回x应该插入的位置

int find(int x){
    int k = (x % N + N) % N;
    while(h[k] != -1 && h[k] != x)//////坑被占了
    {
        ++k;
        /////////如果坑满了
        if (k == N * 2) k = 0 ;
    }
    return k;
}
// 3 3
// 1 2 2
// 2 3 1
// 1 3 4
int main(){
    memset( h , -1 , sizeof(h));
    scanf("%d%d" , &n );
    while(n--){
        char oper[2];
        int x;
        scanf("%s%d" , oper,&x);
        // if (h[find[x]] == x)
        if(*oper == 'I') 
            h[find(x)] = (h[find(x)] == -1) ? x : -1;
        else{
            if (h[find(x)]==x) puts("Yes");
            else puts("No");
        }
            // h[find[x]] = x;
        // if (*oper == "I") h[find[x]] = x;
        // else {
            // if (query(x)) puts("Yes");
            // else puts("No");
        // }
    }
    printf("\nC 艹 mother fucker\n");
    system("pause");
}
