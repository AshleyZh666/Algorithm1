//KMP，相对于最经典的地方在于能够让P串跳步
//关键之处在于next()函数，即记录P串的重复性（仅与P串有关）
//1，生成next（）函数
//2.进入循环，以i < n为结束
//3，判断，若匹配则各自加1，失配则，j回到next()。
//4.其中，next()函数，实现同样如此

#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<ctime>
#include<time.h>

using namespace std;

clock_t start1,end1;
// struct timeval { 
// 　time_t tv_sec;　　　　　/* Seconds. */ 
// 　suseconds_t tv_usec;　 /* Microseconds. */ 
// };
// struct timeval t1, t2;
// gettimeofday(&t1, NULL);
// // func()
// gettimeofday(&t2, NULL);

void print_vec(vector<int>& dp){
    cout<<endl;
    for(auto i : dp){
        printf("%d ",i);
    }
    cout<<endl;
}

int indexof_O_N_N(char* T,char* P){
    int n = strlen(T), i = 0;
    int m = strlen(P), j = 0;
    while(i < n && j < m){
        if (T[i] == P[j]){
            ++i;
            ++j;
        }else
        {
            i -= j - 1;////////注意此时的 i 对齐 j 
            j = 0 ;
        }
    }
    return i - j;
}

vector<int> built_next(char* P){
    int m = strlen(P) , j = 0;
    // printf(" m = %d \n",m);
    vector<int> N(m);
    int t = N[0] = -1;
    ////  t 在哪里
    while(j < m - 1){///////为什么小于 m -1 ,保证 ++j后 P[j]不越界，主要是N[j]不越界
        if (t < 0 || P[j] == P[t])//匹配
            {++t,++j,N[j] = (P[j] != P[t])? t : N[t];}
            // N[++j] = ++t;
        else
            t = N[t];
    }
    return N;
}

int KMP(char* T,char* P){
    vector<int> next = built_next(P);
    // printf("next = ");
    // print_vec(next);
    int n = strlen(T), i = 0;
    int m = strlen(P), j = 0;
    // printf(" m = %d \n",m);
    while(i < n && j < m){//必须要都小于
        //匹配,或者P移动至烧饼
        if (j < 0 || T[i] == P[j]){
            ++i;
            ++j;
        } 
        else//失配
            j = next[j];
    }
    if ( i - j <= n - m) printf("\n匹配成功！！！！！\n");
    else printf("\n匹配失败，，，，\n");
    return i - j;
}

int main(){
    char T[] = "cococococococococococococococococococococococococococococococococococococococococococococococococococoacocococococococococococococococococococococococococococococococococococococococolaco";
    char P[] = "cococococococococococococola";
    printf("strlen(T) = %d , strlen(P) = %d\n",strlen(T),strlen(P));
    //-1 0 -1 0 -1 0 4 0 0
    //-1 0 0 1 2 3 4 0 0
    // char* T = "cococococoococola" ;//, P = "cola";
    // char* P = "cococola";
    // char* T = new char[8];
    // T = "cococola";
    // char* P = new char[4];
    // P = "cola";
    start1=clock();		//程序开始计时
    // gettimeofday(&t1, NULL);
    printf("%d\n",indexof_O_N_N(T,P));
    end1=clock();		//程序结束用时
    // gettimeofday(&t2, NULL);
	double endtime=(double)(end1-start1)/CLOCKS_PER_SEC;
    cout<<"indexof_O_N_N Total time:"<<endtime*1000<<"ms"<<endl;	//ms为单位

    // double time_diff_sec = (t2.tv_sec-t1.tv_sec) + (t2.tv_usec-t1.tv_usec)/1000000;
    // cout<<"indexof_O_N_N Total time:"<<time_diff_sec*1000000<<"us"<<endl;	//us为单位
    
    start1=clock();		//程序开始计时
    // gettimeofday(&t1, NULL);
    printf("%d\n",KMP(T,P));
    end1=clock();		//程序结束用时
    // gettimeofday(&t2, NULL);
	endtime=(double)(end1-start1)/CLOCKS_PER_SEC;
    cout<<"KMP Total time:"<<endtime*1000<<"ms"<<endl;	//ms为单位
    // time_diff_sec = (t2.tv_sec-t1.tv_sec) + (t2.tv_usec-t1.tv_usec)/1000000;
    // cout<<"KMP Total time:"<<time_diff_sec*1000000<<"us"<<endl;	//us为单位
    // delete [] T,P;
    printf("mother fucker C 艹\n");
    system("pause");
}