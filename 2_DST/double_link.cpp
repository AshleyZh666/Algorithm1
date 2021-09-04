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
int e[N] , r[N], l[N];
int idx;///////头节点直接换成0位置

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
///////将下标为k,后继结点删除.
//删除头节点，则输入为 -1，

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
//即调用的时候，调用，remove(k-1)即可。

// 否则换函数：
// void remove_idx(int k){
//     if (!k) head = ne[head];
//     else ///离谱
// }

//k后面加上结点,值位x
// void add(int k , int x){
//     e[idx] = x;
//     ne[idx] = ne[k];
//     ne[k] = idx++;
// }


int main(){
    list<int> li;

    printf("C艹 mother fucker\n");
    system("pause");
}