////////����һ�����У���idx�������С��idx�����������û�з���-1

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

//����ģ��
void baoli(int a[] , int n){
    for(int i = 0 ; i < n ;++i){
        int res = -1 ;
        for(int j = i ; j >= 0 ; --j)//��һ���ҵ��ľ������
            if (a[j] < a[i]){
                res = a[j];
                break;
            }
        cout<<res<<" ";
        printf("%d ", res);
    }
}

int main(){
    ios::sync_with_stdio(false);////////cin����,�����ɻ���
    int n;
    scanf("%d" , &n);
    // for(int i = 0 ; i < n ; ++i) scanf("%d" ,&stk[i]);
    // for(int i = 0 ; i < n ; ++i) cin>>stk[i];
    // baoli(stk,n);
    while(n --){
        int x;
        scanf("%d" , &x);
        while(!tt && stk[tt] >= x) --tt;///��֤������
        //����ʱ��tt == 0 ,���߾���С�� x���������
        if(tt) printf("%d ",stk[tt]);
        else printf("-1 ");
        stk[++tt] = x;
    }
    printf("\nCܳ mother fucker\n");
    system("pause");
}