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

class queue{
//tail是高位,保证低位是++,pop
public:
//////////记住，构造函数，不能有返回值！！！！！！！！！
///////////默认参数，只能放在后面
    queue(int head , int tail = -1){
        this->head = head;
        this->tail = tail; 
    }
    queue(){
        head = 0;
        tail = -1;
    };
    // queue(const queue& Q1){
    //     head = Q1.head;
    //     tail = Q1.tail;
    //     que = Q1.que;//数组的指针
    // }
    // ~queue(){}
    int size(){
        return tail - head;
    }
    bool is_empty(){
        return tail - head < 0;
    }
    void push_back(int x){
    que[++tail] = x;
    }
    void pop(){
        if(is_empty()){}
        else head ++;
    }
    int get_head(){
        return que[head];
    }
    int get_tail(){
        return que[tail];
    }
public:
    int que[N] ;
    int head , tail;
};

int main(){
    // list<int> li;
    // queue Q = new queen(0,-1);
    queue Q;
    // Q.head = 0 ;
    // Q.tail = -1 ;
    Q.push_back(1);
    Q.pop();
    cout<<Q.is_empty()<<endl;
    printf("C艹 mother fucker\n");
    system("pause");
}