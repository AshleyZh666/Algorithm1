#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<list>

using namespace std;

//�õ��٣���Ϊnew���ٶ�̫����
// struct Node{
//     int val;
//     Node* next;
// }

//new Node////�ǳ����������ö�̬������Ҫ�Ľ�
//1.����ģ�ⵥ����  ===>�ڽӱ�====>��ͼ������
//2.����ģ��˫����
//
const int N = 100010;
int e[N] , r[N], l[N];
int idx;///////ͷ�ڵ�ֱ�ӻ���0λ��

void init(){
    r[0] = 1;
    l[1] = 0;
    idx = 2;
}
void add(int k ,int x){
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;
    r[k] = idx;

}
///////���±�Ϊk,��̽��ɾ��.
//ɾ��ͷ�ڵ㣬������Ϊ -1��

void remove_at(int k){
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}
void remove_next(int k){
    r[k] = r[r[k]];
    l[r[k]] = k;
    // l[r[r[k]]] = k;
    // r[k] = r[r[k]];
}
//�����õ�ʱ�򣬵��ã�remove(k-1)���ɡ�

// ���򻻺�����
// void remove_idx(int k){
//     if (!k) head = ne[head];
//     else ///����
// }

//k������Ͻ��,ֵλx
// void add(int k , int x){
//     e[idx] = x;
//     ne[idx] = ne[k];
//     ne[k] = idx++;
// }


int main(){
    list<int> li;

    printf("Cܳ mother fucker\n");
    system("pause");
}