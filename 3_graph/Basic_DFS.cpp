////////�������DFS������n��������ȫ����Ϊ����
///////��������Ҫ�������Ľṹ�����ڵ�i���������Ϊ��i�����Ƿ�ȷ����
///////��Ҫ��һ�����ƣ�����ĳ������
/////�����л��ݣ���û�м�֦

#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

const int N = 7;
int n ;
int path[N];/////��¼��n������״̬Ŷ
bool st[N];///////st[i]Ϊtrue�������    ���� i �Ѿ�ʹ�ù�

void dfs(int u){/////���²�������
    if(u == n)
    {////////����������Ҷ���
        for(int i = 0 ; i < n ; ++i) printf("%d ", path[i]);
        puts("");
        /////////�����֮��ΪʲôҪֹͣ
        // return;
    }
    else
    {///   u < n ,��Ŀǰ�ĵݹ��ڣ����ڵ�i�㣬���Ѿ�ȷ����1~iλ������
        for(int i = 1 ; i <= n ; ++i )
        {//////��Ϊ���֣���1~n,����
            if(!st[i])
            {//////������i��û�����ù����������uλ����ʹ������i
                path[u] = i;
                st[i] = true;/////��ס���� i ,�Ѿ�ʹ�ù�;
                dfs(u + 1);
                /////�ָ��ֳ�
                //////path[u] = 0;
                st[i] = false;
            }
        }
    }
}

int main(){
    // int n ;
    cin>> n ;
    dfs(0);/////�������� 0 �� 

    printf("C ܳ mother fucker\n");
    system("pause");
}