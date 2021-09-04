///////�����޻�ͼ
///// 848 ������ͼ����������
//input: n��� m ��
// 3 3
// 1 2
// 2 3
// 1 3
//Ouput:
//1 2 3

#include<iostream>
#include<cstring>
#include<algorithm>
#include<string.h>

using namespace std;

const int N = 1000010;
int n , m;
int idx , e[N] , ne[N] , h[N];
int q[N] , d[N] ;////////d[N] ���i����ȣ�����

void add(int a, int b){
    ///////ͷ�巨
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
//////�϶���Ҫ�����ܷ���������
bool tuopu_sort(){
    int hh = 0 , tt = -1;
    // q[++tt] = ;/////�ҵ���һ�����Ϊ 0 �Ľ��
    for(int i = 1 ; i <= n ; ++i) ///////����1��ʼ
        if(!d[i]) 
            q[++tt] = i;
    while(hh <= tt){
        int t = q[hh++];
        for(int i = h[t] ; i != -1 ; i = ne[i]){
            int j = e[i];
            d[j]--;///�뵽��ȥ�� ���t
            if(!d[j]) q[++tt] = j;
        }
    }
    // ������е㶼����ˣ�˵�������������У����򲻴����������С�
    // cout<<"hh = "<<hh<<" tt = "<<tt<<endl;
    return tt == n - 1;///////������ǽ��������n���㣬ֻ�� tt
}
bool topsort()
{
    int hh = 0, tt = -1;

    // d[i] �洢��i�����
    for (int i = 1; i <= n; i ++ )
        if (!d[i])
            q[ ++ tt] = i;

    while (hh <= tt)
    {
        int t = q[hh ++ ];

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (-- d[j] == 0)
                q[ ++ tt] = j;
        }
    }
    // cout<<"hh = "<<hh<<" tt = "<<tt<<endl;
    // ������е㶼����ˣ�˵�������������У����򲻴����������С�
    return tt == n - 1;
}



int main(){
    ////////һ��Ҫע�� ��n m�Ƿ�ȫ�ֱ���
    scanf("%d%d" , &n , &m);
    // memset(d, 0 , sizeof(d));////////Ĭ�ϳ�ʼ��Ϊ 0 
    memset(h , -1 , sizeof(h));
    for(int i = 0 ; i < m ; ++i) {
        int a, b;
        scanf("%d%d" , &a , &b);
        add(a,b);
        d[b]++;
    }
    // cout<<topsort()<<endl;
    if (tuopu_sort()){
        for(int i = 0 ; i < n ;++i) printf("%d " , q[i]);
        puts("");
    }
    else{
        puts("-1");
    }
    printf("\nC ܳ mother fucker\n");
    system("pause");
}