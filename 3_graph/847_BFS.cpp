///��� 1 �� n�����̾��룬���о���� -1
///����m��2�б�ʾ�Ǵ�a��b�����ڱ�,a��b��
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string.h>

using namespace std;

const int N = 100010;

int n , m ;
int h[N] , e[N] , ne[N] , idx;
int q[N] ,  d[N];

void add(int a, int b){//h[a]������������
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

int bfs(){
    int hh = 0, tt = 0;//////Ϊʲô��ʼ״̬�£�tt = 0,
    /////��Ϊһ����ڳ�ʼ���������һ����Ա
    q[0] = 1;///ջ��,1�ŵ㣿����
    memset(d , -1 , sizeof(d));//////// -1 ��ʾ���Ǵ˽��û�з���
    // d[1] = 0;//////
    d[1] = 0;
    while(hh <= tt){
        //��ȡ����Ԫ��
        int t  = q[hh++];
        for(int i = h[t] ; i != -1 ;i = ne[i]){
            int j = e[i];///i�Ž��
            // cout<<t<<"�ĺ�̽��Ϊ"<<j<<endl;
            if (d[j] == -1)  
            {   
                d[j] = d[t] + 1 ;
                q[++tt] = j;
            }
        }
    }
    // for(int i = 0 ; i < n ; i ++) printf("%d" , d[i]);
    return d[n];
}

// 4 5
// 1 2
// 2 3
// 3 4
// 1 3
// 1 4

 int main(){
     scanf("%d%d" , &n , &m );
     memset(h , -1 ,sizeof(h));
     for(int i = 0 ; i < m ; ++i){
         int a,b;
         scanf("%d%d",&a , &b);
         add(a,b);
    }
    printf("%d" , bfs());
    printf("\nC ܳ mother fucker\n");
    system("pause");
 }
