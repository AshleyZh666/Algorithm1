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
int e[N] , ne[N];
int idx,head;

void init(){
    idx = 0;////////����ǰ���е�λ��
    head = -1;
}
void add_to_head(int x){
    e[idx] = x;
    ne[idx] = head;//head��ʱָ�����±꣬�� ne[-1] = head ��e[head] ���� e[0]
    head = idx++;
}
///////���±�Ϊk,��̽��ɾ��.
//ɾ��ͷ�ڵ㣬������Ϊ -1��
void remove_next(int k){
    if (k == -1) head = ne[head]; 
    else ne[k] = ne[ne[k]];
}
//�����õ�ʱ�򣬵��ã�remove(k-1)���ɡ�

// ���򻻺�����
void remove_at(int k){
    if (!k) head = ne[head];
    else ne[k - 1] = ne[ne[k]];///����
}

//k������Ͻ��,ֵλx
void add(int k , int x){
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}


int main(){
    list<int> li;

    printf("Cܳ mother fucker\n");
    system("pause");
}