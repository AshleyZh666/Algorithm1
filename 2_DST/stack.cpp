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
    printf("Cܳ mother fucker\n");
    system("pause");
}