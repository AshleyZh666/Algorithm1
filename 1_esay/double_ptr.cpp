#include<iostream>

using namespace std;

//ģ��
// void double_ptr(){
//     for(int i = 0 ; i < n ; ++ i){
//         int j = 0;//j = i ;
//         while( j < i && check(i , j)) ++j;
//     }
// }
//////��������ظ�����
const int N = 10010;
int a[N] , s[N];
int n ;


int main(){
    scanf("%d" , &n);
    for(int i = 0 ; i < n ; ++i){
        scanf("%d" , &a[i]);
    }
    int res = 0 ;
    for(int i = 0 , j = 0; i < n ; ++i){
        s[a[i]]++;
        while(s[a[i]] > 1){//////ע�⣬֮���Ի��ظ�������Ϊiָ��˴������ֳ��������Ρ�
            s[a[j]]--;//��ʱjָ����ƣ�������һ����ѭ�������˼Ϊ��
            ++j;      ////jָ�벻�Ϻ��ƣ�ֱ��a[i]������Ϊ1
        }
        res = max(res , i - j + 1);
    }
    cout<<res<<endl;
    printf("C ܳ mother fucker\n");
    system("pause");
}