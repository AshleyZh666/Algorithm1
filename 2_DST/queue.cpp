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

class queue{
//tail�Ǹ�λ,��֤��λ��++,pop
public:
//////////��ס�����캯���������з���ֵ������������������
///////////Ĭ�ϲ�����ֻ�ܷ��ں���
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
    //     que = Q1.que;//�����ָ��
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
    printf("Cܳ mother fucker\n");
    system("pause");
}