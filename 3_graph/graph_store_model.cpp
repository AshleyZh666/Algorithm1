#include<istream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 100010  , M = N * 2; 
int n , m;
int h[N] , e[M] , ne[M] , idx;////����
bool st[N] ;////����ʾi�Ž���Ƿ�������

void add(int a , int b){
    e[idx] = b ;
    ne[idx] = h[a] ;//////h[a]��ͷ�ڵ�
    h[a] = idx++ ;
}

void dfs(int u){
    st[u] = true;///���һ�£�������u�ŵ�
    //���������еĳ���
    for(int i = h[u] ; i != -1 ; i = ne[i]){
        int j = e[i];
        if (! st[j])/////////��Ĳ��� st[i]
            dfs(j);////////��Ĳ���dfs(i)��
    }
}

int main(){
    memset(h , -1 , sizeof h);
    dfs(1);
    printf("C ܳ mother fucker\n");
    system("pause");
}
