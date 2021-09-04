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
class stack{
public:
    int stk[N] ;
    int idx;
public:
    stack(){
        idx = -1 ;
    }
    int size(){
        return idx;
    }
    bool is_empty(){
        return idx <= 0;
    }
    void push(int x){
        stk[++idx] = x;
    }
    void pop(){
        if(is_empty()){}
        else idx--;
    }
    int top(){
        return stk[idx];
    }
};

int main(){
    // list<int> li;
    stack ss;
    ss.push(1);
    ss.push(2);
    cout<<ss.top()<<endl;
    ss.pop();
    cout<<ss.top()<<endl;
    printf("C艹 mother fucker\n");
    system("pause");
}