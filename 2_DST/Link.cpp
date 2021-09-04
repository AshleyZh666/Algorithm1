#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<list>

using namespace std;

//用的少，因为new的速度太慢了
// struct Node{
//     int val;
//     Node* next;
// }

//new Node////非常慢，不采用动态链表。需要改进
//1.数组模拟单链表  ===>邻接表====>存图或者树
//2.数组模拟双链表
//
const int N = 100010;
int e[N] , ne[N];
int idx,head;

void init(){
    idx = 0;////////链表当前运行的位置
    head = -1;
}
void add_to_head(int x){
    e[idx] = x;
    ne[idx] = head;//head此时指向向下标，即 ne[-1] = head 即e[head] 就是 e[0]
    head = idx++;
}
///////将下标为k,后继结点删除.
//删除头节点，则输入为 -1，
void remove_next(int k){
    if (k == -1) head = ne[head]; 
    else ne[k] = ne[ne[k]];
}
//即调用的时候，调用，remove(k-1)即可。

// 否则换函数：
void remove_at(int k){
    if (!k) head = ne[head];
    else ne[k - 1] = ne[ne[k]];///离谱
}

//k后面加上结点,值位x
void add(int k , int x){
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}


int main(){
    list<int> li;

    printf("C艹 mother fucker\n");
    system("pause");
}