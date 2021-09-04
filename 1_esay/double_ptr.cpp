#include<iostream>

using namespace std;

//模板
// void double_ptr(){
//     for(int i = 0 ; i < n ; ++ i){
//         int j = 0;//j = i ;
//         while( j < i && check(i , j)) ++j;
//     }
// }
//////最长连续不重复数字
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
        while(s[a[i]] > 1){//////注意，之所以会重复，是因为i指针此处的数字出现了两次。
            s[a[j]]--;//此时j指针后移，计数减一，在循环里的意思为，
            ++j;      ////j指针不断后移，直到a[i]计数将为1
        }
        res = max(res , i - j + 1);
    }
    cout<<res<<endl;
    printf("C 艹 mother fucker\n");
    system("pause");
}