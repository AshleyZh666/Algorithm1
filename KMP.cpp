//KMP����������ĵط������ܹ���P������
//�ؼ�֮������next()����������¼P�����ظ��ԣ�����P���йأ�
//1������next��������
//2.����ѭ������i < nΪ����
//3���жϣ���ƥ������Լ�1��ʧ����j�ص�next()��
//4.���У�next()������ʵ��ͬ�����

#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<ctime>
#include<time.h>

using namespace std;

clock_t start1,end1;
// struct timeval { 
// ��time_t tv_sec;����������/* Seconds. */ 
// ��suseconds_t tv_usec;�� /* Microseconds. */ 
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
            i -= j - 1;////////ע���ʱ�� i ���� j 
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
    ////  t ������
    while(j < m - 1){///////ΪʲôС�� m -1 ,��֤ ++j�� P[j]��Խ�磬��Ҫ��N[j]��Խ��
        if (t < 0 || P[j] == P[t])//ƥ��
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
    while(i < n && j < m){//����Ҫ��С��
        //ƥ��,����P�ƶ����ձ�
        if (j < 0 || T[i] == P[j]){
            ++i;
            ++j;
        } 
        else//ʧ��
            j = next[j];
    }
    if ( i - j <= n - m) printf("\nƥ��ɹ�����������\n");
    else printf("\nƥ��ʧ�ܣ�������\n");
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
    start1=clock();		//����ʼ��ʱ
    // gettimeofday(&t1, NULL);
    printf("%d\n",indexof_O_N_N(T,P));
    end1=clock();		//���������ʱ
    // gettimeofday(&t2, NULL);
	double endtime=(double)(end1-start1)/CLOCKS_PER_SEC;
    cout<<"indexof_O_N_N Total time:"<<endtime*1000<<"ms"<<endl;	//msΪ��λ

    // double time_diff_sec = (t2.tv_sec-t1.tv_sec) + (t2.tv_usec-t1.tv_usec)/1000000;
    // cout<<"indexof_O_N_N Total time:"<<time_diff_sec*1000000<<"us"<<endl;	//usΪ��λ
    
    start1=clock();		//����ʼ��ʱ
    // gettimeofday(&t1, NULL);
    printf("%d\n",KMP(T,P));
    end1=clock();		//���������ʱ
    // gettimeofday(&t2, NULL);
	endtime=(double)(end1-start1)/CLOCKS_PER_SEC;
    cout<<"KMP Total time:"<<endtime*1000<<"ms"<<endl;	//msΪ��λ
    // time_diff_sec = (t2.tv_sec-t1.tv_sec) + (t2.tv_usec-t1.tv_usec)/1000000;
    // cout<<"KMP Total time:"<<time_diff_sec*1000000<<"us"<<endl;	//usΪ��λ
    // delete [] T,P;
    printf("mother fucker C ܳ\n");
    system("pause");
}