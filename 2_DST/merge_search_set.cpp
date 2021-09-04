#include <stdio.h>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 1000010;
int p[N], size[N];
//p[]存储每个点的祖宗节点, 
//size[]只有祖宗节点的有意义，表示祖宗节点所在集合中的点的数量
void merge_search_init(){
    for(int = 0 ; i < n ; ++i) {
        p[i] = i;
        size[i] = 1;
    }
}

void find(int x){
    if(P[x] != x) P[x] = find(x);
    return P[x];
}

void merge(int a , int b){
    if (find(a) != find(b))
        size[find(b)] += size[find(a)];/////先加size,否则find(a)的根节点解释b了
        P[find(b)] = find(a);
}

int main() {
    // printf("Congratulasions! It works!\n");
    printf("C ܳ mother fucker \n");
    system("pause");
}