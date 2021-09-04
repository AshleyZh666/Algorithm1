////////给定一个数列，求idx数，左边小于idx且最近的数，没有返回-1

#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<list>

using namespace std;

const int N = 100010;
class stack{
public:
    int stk[N] ;
    int idx;
public:
    stack(){
        idx = -1 ;
    }
    int size(){
        return idx;
    }
    bool is_empty(){
        return idx <= 0;
    }
    void push(int x){
        stk[++idx] = x;
    }
    void pop(){
        if(is_empty()){}
        else idx--;
    }
    int top(){
        return stk[idx];
    }
};

int stk[N];
int tt = 0;

// 5
// 3 4 2 7 5
// -1 3 -1 2 2

//暴力模板
void baoli(int a[] , int n){
    for(int i = 0 ; i < n ;++i){
        int res = -1 ;
        for(int j = i ; j >= 0 ; --j)//第一个找到的就是最近
            if (a[j] < a[i]){
                res = a[j];
                break;
            }
        cout<<res<<" ";
        printf("%d ", res);
    }
}

int main(){
    ios::sync_with_stdio(false);////////cin加速,但不可混用
    int n;
    scanf("%d" , &n);
    // for(int i = 0 ; i < n ; ++i) scanf("%d" ,&stk[i]);
    // for(int i = 0 ; i < n ; ++i) cin>>stk[i];
    // baoli(stk,n);
    while(n --){
        int x;
        scanf("%d" , &x);
        while(!tt && stk[tt] >= x) --tt;///保证单调性
        //即此时的tt == 0 ,或者就是小于 x的最近的数
        if(tt) printf("%d ",stk[tt]);
        else printf("-1 ");
        stk[++tt] = x;
    }
    printf("\nC艹 mother fucker\n");
    system("pause");
}