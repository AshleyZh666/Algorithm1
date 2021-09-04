////时间复杂度稳定为:O(n*log(n))

////输入为：q[] , l , h
////////难点在于归并，即两个有序的数组合二为一

////     基本思想也是为分而治之
////      先递归排序，再归并(即合二为一)


////1.设置递归结束条件
////2.先递归排序
////3.归并；重点在于设置两个指针，辅助数组，再某段结束后另一段没结束，整体挪入temp
////4.挪回原数组

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

const int N = 1000001;
int temp[N];

void merge_sort(int q[] , int l , int h){
    if(l >= h) return ;////////记住，终止条件是l >= h;
    // int i = l - 1 , j = h + 1 , x = (q[l] + q[h])/2;
    int m = (l + h) >> 1;
    merge_sort(q, l, m);
    merge_sort(q, m+1, h);
    int i = l , j = m + 1 , k = 0 ;
    while( i <= m && j <= h)
        if (q[i] <= q[j]) temp[k++] = q[i++];
        else temp[k++] = q[j++];
    while(i <= m) temp[k++] = q[i++];
    while(j <= h) temp[k++] = q[j++];

    for(int i = l , j = 0 ; i <= h ; i++ , j ++) q[i] = temp[j];
}
//////重载向量版
void merge_sort(vector<int>& q , int l , int h){
    if(l >= h) return ;////////记住，终止条件是l >= h;
    // int i = l - 1 , j = h + 1 , x = (q[l] + q[h])/2;
    int m = (l + h) >> 1;
    merge_sort(q, l, m);
    merge_sort(q, m+1, h);
    int i = l , j = m + 1 , k = 0 ;
    while( i <= m && j <= h)
        if (q[i] <= q[j]) temp[k++] = q[i++];
        else temp[k++] = q[j++];
    while(i <= m) temp[k++] = q[i++];
    while(j <= h) temp[k++] = q[j++];

    /////////很经典在于，经处理从l 到  h
    for(int i = l , j = 0 ; i <= h ; i++ , j ++) q[i] = temp[j];
    // printf("*\n"); //////归并次数
}
void print_arr(const int q[],int n){
    // for(auto i:q){
    //     printf("%d ",i);
    // }
    for (int i = 0 ; i < n ; ++i){
        printf("%d ", q[i]);
    }
    printf("\n");
}
void print_vec(const vector<int>& q){
    for(auto i:q){
        printf("%d ",i);
    }
    // for (int i = 0 ; i < n ; ++i){
    //     printf("%d ", q[i]);
    // }
    printf("\n");
}

int main(){
//////////
    printf("数组归并排序前后\n");
    int q[10] = {10,9,8,7,6,5,4,3,2,1};
    print_arr(q,sizeof(q)/sizeof(q[0]));
    merge_sort(q,0,sizeof(q)/sizeof(q[0])-1);
    print_arr(q,sizeof(q)/sizeof(q[0]));
//////////
    printf("向量归并排序前后\n");
    vector<int> qq = {10,9,8,7,6,5,4,3,2,1};
    print_vec(qq);
    merge_sort(qq,0,qq.size() - 1);
    print_vec(qq);

    printf("C艹 mother fucker\n");
    system("pause");
}
