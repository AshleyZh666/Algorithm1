////////  n-�ʺ����⣬����n * n�Ĺ�������������ϣ�����n���ʺ�
/////// ʹ�䲻���������ڣ����๥�����ʺ��ܹ��ᣬ����б
/////// ��ֽ����ǰ�жϣ���ǰ��������Ϸ�����������������
/////// �л��ݣ��м�֦
////////��֦���������ż�֦�Ϳ����Լ�֦�������������źͿ����Ծͻᱻ��֦

#include<iostream>
#include<string.h>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 10;
int n ;
char q[N][N];///// 
//ͬ���Ļ��� bool �жϣ�����Щ����ǺϷ���
//dgΪ���Խ����Ƿ�Ϸ���udg��Ϊ���Խ����Ƿ�Ϸ�

///�������أ���,   g[i][j] = 'Q'
//�� col[j] = true ,
bool col[N] , dg[N] , udg[N];/////Ĭ�϶���0����false


void dfs(int u ){
    if(u == n){//�����˸��ڵ㣬��������
        for(int i = 0 ; i < n ; ++i) {
            puts(q[i]);
        }
        puts("");
        return;
    }
    for(int i = 0 ; i < n ; ++i){
        if(!col[i] && !dg[u + i] && !udg[i - u + n])
            q[u][i] = 'Q';
            col[i] = dg[u + i] = udg[i - u + n] = true;
            dfs(u + 1);
            col[i] = dg[u + i] = udg[i - u + n] = false;
            q[u][i] = '*';
    }
}

int main(){
    // int n ;
    // cin>> n ;
    scanf("%d" , &n);
    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < n ;++j)
            q[i][j] = '*';
    dfs(0);/////�������� 0 �� 

    printf("C ܳ mother fucker\n");
    system("pause");
}