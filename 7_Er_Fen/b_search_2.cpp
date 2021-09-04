#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int  N = 100010;
int a[N];
int n;

// 30 4
// 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2 3 3 3 3 3 3 3 3 3 3 3 3
// 1
// 3
// 2
// 4
void bsearch(int a[] , int l , int r , int k){
    int mid;
    while(l < r){
            mid = (l + r) / 2;
            if(a[mid] >= k) r = mid;
            else l = mid + 1;
        }
        if (a[l] == k){
            cout<<l <<" ";
            int l = 0 , r = n - 1;
            while(l < r){
                mid = (l + r + 1) /2;
                if (a[mid] <= k) l = mid;
                else r = mid -1;
            }
            cout<<l<<endl;
        }else
            cout<<"-1 -1"<<endl;
}

int main(){
    int q ,k;
    scanf("%d %d", &n, &q);
    for(int i = 0 ; i < n ; ++i){
        scanf("%d ", &a[i]);
    }
    while(q -- ){
        scanf("%d" , &k);
        // int l = 0 , r = n - 1;
        bsearch(a , 0 , n-1 ,k);
    }    
    system("pause");
}
