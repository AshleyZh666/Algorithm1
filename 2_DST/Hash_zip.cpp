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

const int N = 100003;
// const int INF = 1e9;
int n ;
int e[N] , ne[N] , h[N] , idx;
// 向哈希表中插入一个数
void insert(int x){
    int k = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[k];///////存在k处
    h[k] = idx++;
}
// 在哈希表中查询某个数是否存在
bool query(int x){
    int k = (x % N + N) % N;
    for(int i = h[k] ; i != -1 ; i = ne[i]){
        // int j = e[i];
        if(e[i] == x) return true;
    } 
    return false;
}
// 3 3
// 1 2 2
// 2 3 1
// 1 3 4
int main(){
    // cout<<N<<endl;
    memset( h , -1 , sizeof(h));
    scanf("%d%d" , &n );
    while(n--){
        char oper[2];
        int x;
        scanf("%s%d" , oper,&x);
        if (*oper == 'I') insert(x);
        else {
            if (query(x)) puts("Yes");
            else puts("No");
        }
    }
    printf("\nC 艹 mother fucker\n");
    system("pause");
}
