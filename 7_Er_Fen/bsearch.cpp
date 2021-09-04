//// 

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int  N = 100010;
int a[N];
int n;

/////////貌似最好直接，即左边界直接 a[mid] >= k
void bsearch_1(int a[] , int l , int r , int k){
    
    while(l < r){
        int mid = (l + r + 1)/2;
        if (a[mid] < k){//即最左k能够满足的check函数
            l = mid;
        }else{
            r = mid - 1;
        }
    }
    if (a[l+1] == k)
        cout<<l+1<<" ";
    else
        cout<<"-1"<<" ";
    l = 0 ;
    r = n -1;
    
    while(l < r){
        int mid2 = (l + r)/2;
        if (a[mid] > k){//即最右k能够满足的check函数
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    if(a[l-1] == k)
        cout<<l-1<<endl;
    else
        cout<<"-1"<<endl;
}
int main(){
    int q,k;
    scanf("%d%d", &n, &q);
    printf("%d%d" , n , q);
    for(int i = 0 ; i < n ; ++i){
        scanf("%d", &a[i]);
    }
    for(int i = 0 ; i < n ; ++i){
        printf("%d", a[i]);
    }
    while(q-- > 0){
        scanf("%d", &k);
        bsearch_1(a,0,n-1,k);
    }
    system("pause");
}
