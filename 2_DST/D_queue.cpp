////////�󻬶�����������ֵ����Сֵ��
//����n , m ;����Ϊn������;
//�������Ϊm�Ļ������ڵ������Сֵ

#include<iostream>
#include<stdio.h>
#include<vector>
#include<cstring>
#include<algorithm>
#include<list>

using namespace std;

const int N = 100010;

int queue[N] , a[N];


//����ģ��
// void baoli(int a[] , int n �� int m){
//     for(int i = 0 ; i <= n - m ;++i){
//         int MAX = - 2e9 ; 
//         for(int j = i ; j < i + m ;++j){
//             MAX = max(MAX , a[j]);
//         }
//         printf("%d " ,MAX);
//     }
// }

int main(){
    ios::sync_with_stdio(false);////////cin����,�����ɻ���
    cin.tie(0);///////����cin
    int n , m;
    scanf("%d%d" , &n , &m);
    for(int i = 0 ; i < n ; ++i) scanf("%d" , &a[i]);
    int hh = 0 ;
    int tt = -1;
    for(int i = 0 ; i < n ; ++i){
        // int x ;
        // scanf("%d" , &x);
        // while()
        //�������У���ε���,Ҫ��ĳЩ��ȥ������������
        //while(tt >= hh && ) ///ò�Ʋ�̫��

        ///���ڱ���m??????
        ///////������ά������,��������queue[hh]Ϊ��Сֵ
        // while(tt >= hh && queue[hh] >= x) ++hh;
        // cout<<queue[hh]<<" ";
        // queue[++tt] = x;

        ///////��������±�,��������±�
        //////ɶ�ж�ͷ�Ѿ��������ڣ�����������������
        //i��ʾ���ڵ��Ҷ�,             ���±��Ѿ�����
        
        if (tt >= hh && i - m + 1 > queue[hh]) ++hh;//���ö����±��ڴ�����
        /////�²������---���ڵ��Ҷˣ��ȶ�βС�������
        while(tt >= hh && a[queue[tt]] >= a[i]) --tt;///////�����ǿ������˳���
        queue[++tt] = i;///////������±꣬�������Ҷ˼������
        if (i - m + 1 >= 0) printf("%d ",a[queue[hh]]);
 
// 8 3
// 1 3 -1 -3 5 3 6 7
    }
    // puts("\n");
    // printf("\n");
    hh = 0 ;
    tt = -1;
    for(int i = 0 ; i < n ; ++i){
        //if���Ի���while
        if (tt >= hh && i - m + 1 > queue[hh]) ++hh;//���ö����±��ڴ�����
        /////�²������---���ڵ��Ҷˣ��ȶ�βС�������,���ڴ��ڵ���������
        while(tt >= hh && a[queue[tt]] <= a[i]) --tt;///////�����ǿ������˳���
        //////��֤�����ݼ�
        queue[++tt] = i;///////������±꣬�������Ҷ˼������
        if (i - m + 1 >= 0) printf("%d ",a[queue[hh]]);
    }

    printf("\nCܳ mother fucker\n");
    system("pause");
}