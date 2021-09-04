////平均时间复杂度为:O(n*log(n)),最坏n^2，但不会达到

////输入为：q[] , l , h
////  
////1.设置递归结束条件
////2.i,j;设置数值点x，直接记为q[（l+h）/2]
////3.进入循环，终止条件明显，注意while的停止条件；寻找逆序的两点。并swap()
////4.最后开始递归，即分而治之。更新l和h，注意边界点。

#include<iostream>
#include<string>
#include<vector>

using namespace std;

void quick_sort(int q[] , int l , int h){
    if(l >= h) return ;////////记住，终止条件是l >= h;
    // int i = l - 1 , j = h + 1 , x = (q[l] + q[h])/2;
    int i = l - 1 , j = h + 1 , x = q[(l+h)/2];
    while(i < j){//////循环结束时,必然是i 与 j 相遇,并且l左边小于x,右边的都大于x;
    while(q[++i] < x);
    while(q[--j] > x);
    if (i < j) swap(q[i],q[j]);
    }
    quick_sort(q,l,i);
    quick_sort(q,i+1,h);
}
//////重载向量版
void quick_sort(vector<int>& q , int l , int h){
    if(l >= h) return ;////////记住，终止条件是l >= h;
    // int i = l - 1 , j = h + 1 , x = (q[l] + q[h])/2;
    int i = l - 1 , j = h + 1 , x = q[(l+h)/2];
    while(i < j){//////循环结束时,必然是i 与 j 相遇,并且l左边小于x,右边的都大于x;
    while(q[++i] < x);
    while(q[--j] > x);
    if (i < j) swap(q[i],q[j]);
    }
    quick_sort(q,l,i);
    quick_sort(q,i+1,h);
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
    printf("数组快速排序前后\n");
    int q[10] = {10,9,8,7,6,5,4,3,2,1};
    print_arr(q,sizeof(q)/sizeof(q[0]));
    quick_sort(q,0,sizeof(q)/sizeof(q[0])-1);
    print_arr(q,sizeof(q)/sizeof(q[0]));
//////////
    printf("向量快速排序前后\n");
    vector<int> qq = {10,9,8,7,6,5,4,3,2,1};
    print_vec(qq);
    quick_sort(qq,0,qq.size() - 1);
    print_vec(qq);

    printf("C艹 mother fucker\n");
    system("pause");
}
