#include <stdio.h>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 100010;
// int P[N];


/////////////////Ϊ�˿��ٲ�ѯĳ�ַ����ĸ���
////////ͳ�ƺ�����������ַ���
int son[N][26], cnt[N], idx;
// 0�ŵ���Ǹ��ڵ㣬���ǿսڵ�
// son[][]�洢����ÿ���ڵ���ӽڵ�ı��
// cnt[]�洢�Ե�ǰ����β�ĵ�������

// ����һ���ַ���

///////�ս��
void insert(char str[]){
    int p = 0 ;///////�ӽ�� 0 ����
    for(int i = str[0] ; str[i] ; ++i){
        int t = i - 'a';///��ֻ��Сд��ĸʱ
////��� trie tree �� ���洢ʱ�����˿գ�����Ҫ�¿���֧,�������µĽ����
        if(!son[p][t]) son[p][t] = ++idx;
        p = son[p][t];
    }
    ///////�ַ�β����Ҫcnt��һ
    cnt[p]++;
}
// ��ѯ�ַ������ֵĴ���
int query(char str[]){
    int p = 0;
    for(int i = 0 ; char[i] ; ++i){
        int t = i - 'a';
        if(!son[p][t]) return 0;
        p = son[p][t];
    }
    return cnt[p];
}
//////////////�ú����һ�� p = son[p][t];

//////////???????????????����


int main() {
    // printf("Congratulasions! It works!\n");
    printf("C ܳ mother fucker \n");
    system("pause");
}