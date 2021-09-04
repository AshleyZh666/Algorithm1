#include <stdio.h>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 100010;
// int P[N];


/////////////////为了快速查询某字符串的个数
////////统计和排序大量的字符串
int son[N][26], cnt[N], idx;
// 0号点既是根节点，又是空节点
// son[][]存储树中每个节点的子节点的编号
// cnt[]存储以当前结点结尾的单词数量

// 插入一个字符串

///////空结点
void insert(char str[]){
    int p = 0 ;///////从结点 0 出发
    for(int i = str[0] ; str[i] ; ++i){
        int t = i - 'a';///当只有小写字母时
////如果 trie tree 中 ，存储时遇到了空，即需要新开分支,即分配新的结点编号
        if(!son[p][t]) son[p][t] = ++idx;
        p = son[p][t];
    }
    ///////字符尾部需要cnt加一
    cnt[p]++;
}
// 查询字符串出现的次数
int query(char str[]){
    int p = 0;
    for(int i = 0 ; char[i] ; ++i){
        int t = i - 'a';
        if(!son[p][t]) return 0;
        p = son[p][t];
    }
    return cnt[p];
}
//////////////好好理解一下 p = son[p][t];

//////////???????????????排序


int main() {
    // printf("Congratulasions! It works!\n");
    printf("C 艹 mother fucker \n");
    system("pause");
}