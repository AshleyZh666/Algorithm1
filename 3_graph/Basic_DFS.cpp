////////最基础的DFS程序，以n个数数字全排列为例；
///////其中最重要的是树的结构，树在第i层数，理解为第i个数是否确定了
///////需要有一个机制，即否定某个数字
/////仅仅有回溯，并没有剪枝

#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

const int N = 7;
int n ;
int path[N];/////记录这n个数的状态哦
bool st[N];///////st[i]为true代表的是    数字 i 已经使用过

void dfs(int u){/////向下层数增加
    if(u == n)
    {////////即层数到了叶结点
        for(int i = 0 ; i < n ; ++i) printf("%d ", path[i]);
        puts("");
        /////////输出了之后，为什么要停止
        // return;
    }
    else
    {///   u < n ,即目前的递归在，即在第i层，则已经确定了1~i位的数字
        for(int i = 1 ; i <= n ; ++i )
        {//////此为数字，即1~n,代表
            if(!st[i])
            {//////当数字i，没有有用过，则走向第u位数字使用数字i
                path[u] = i;
                st[i] = true;/////记住数字 i ,已经使用过;
                dfs(u + 1);
                /////恢复现场
                //////path[u] = 0;
                st[i] = false;
            }
        }
    }
}

int main(){
    // int n ;
    cin>> n ;
    dfs(0);/////即遍历第 0 层 

    printf("C 艹 mother fucker\n");
    system("pause");
}