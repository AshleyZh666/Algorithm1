////////求滑动窗口里的最大值和最小值；
//输入n , m ;长度为n的数组;
//输出长度为m的滑动窗口的最大最小值

#include<iostream>
#include<stdio.h>
#include<vector>
#include<cstring>
#include<algorithm>
#include<list>

using namespace std;

const int N = 100010;

int queue[N] , a[N];


//暴力模板
// void baoli(int a[] , int n ， int m){
//     for(int i = 0 ; i <= n - m ;++i){
//         int MAX = - 2e9 ; 
//         for(int j = i ; j < i + m ;++j){
//             MAX = max(MAX , a[j]);
//         }
//         printf("%d " ,MAX);
//     }
// }

int main(){
    ios::sync_with_stdio(false);////////cin加速,但不可混用
    cin.tie(0);///////加速cin
    int n , m;
    scanf("%d%d" , &n , &m);
    for(int i = 0 ; i < n ; ++i) scanf("%d" , &a[i]);
    int hh = 0 ;
    int tt = -1;
    for(int i = 0 ; i < n ; ++i){
        // int x ;
        // scanf("%d" , &x);
        // while()
        //单调队列，如何单调,要把某些给去除掉，即出队
        //while(tt >= hh && ) ///貌似不太对

        ///队内保持m??????
        ///////队列来维护窗口,怎样才能queue[hh]为最小值
        // while(tt >= hh && queue[hh] >= x) ++hh;
        // cout<<queue[hh]<<" ";
        // queue[++tt] = x;

        ///////队列里存下标,即数组的下标
        //////啥叫队头已经滑出窗口，，，，，，，，，
        //i表示窗口的右端,             此下标已经出队
        
        if (tt >= hh && i - m + 1 > queue[hh]) ++hh;//即让队内下标在窗口中
        /////新插入的数---窗口的右端，比队尾小，则出队
        while(tt >= hh && a[queue[tt]] >= a[i]) --tt;///////好像是可以两端出队
        queue[++tt] = i;///////存的是下标，即窗口右端加入队列
        if (i - m + 1 >= 0) printf("%d ",a[queue[hh]]);
 
// 8 3
// 1 3 -1 -3 5 3 6 7
    }
    // puts("\n");
    // printf("\n");
    hh = 0 ;
    tt = -1;
    for(int i = 0 ; i < n ; ++i){
        //if可以换成while
        if (tt >= hh && i - m + 1 > queue[hh]) ++hh;//即让队内下标在窗口中
        /////新插入的数---窗口的右端，比队尾小，则出队,队内窗口的数字满了
        while(tt >= hh && a[queue[tt]] <= a[i]) --tt;///////好像是可以两端出队
        //////保证单调递减
        queue[++tt] = i;///////存的是下标，即窗口右端加入队列
        if (i - m + 1 >= 0) printf("%d ",a[queue[hh]]);
    }

    printf("\nC艹 mother fucker\n");
    system("pause");
}