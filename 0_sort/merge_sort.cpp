////ʱ�临�Ӷ��ȶ�Ϊ:O(n*log(n))

////����Ϊ��q[] , l , h
////////�ѵ����ڹ鲢�����������������϶�Ϊһ

////     ����˼��Ҳ��Ϊ�ֶ���֮
////      �ȵݹ������ٹ鲢(���϶�Ϊһ)


////1.���õݹ��������
////2.�ȵݹ�����
////3.�鲢���ص�������������ָ�룬�������飬��ĳ�ν�������һ��û����������Ų��temp
////4.Ų��ԭ����

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

const int N = 1000001;
int temp[N];

void merge_sort(int q[] , int l , int h){
    if(l >= h) return ;////////��ס����ֹ������l >= h;
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
//////����������
void merge_sort(vector<int>& q , int l , int h){
    if(l >= h) return ;////////��ס����ֹ������l >= h;
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

    /////////�ܾ������ڣ��������l ��  h
    for(int i = l , j = 0 ; i <= h ; i++ , j ++) q[i] = temp[j];
    // printf("*\n"); //////�鲢����
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
    printf("����鲢����ǰ��\n");
    int q[10] = {10,9,8,7,6,5,4,3,2,1};
    print_arr(q,sizeof(q)/sizeof(q[0]));
    merge_sort(q,0,sizeof(q)/sizeof(q[0])-1);
    print_arr(q,sizeof(q)/sizeof(q[0]));
//////////
    printf("�����鲢����ǰ��\n");
    vector<int> qq = {10,9,8,7,6,5,4,3,2,1};
    print_vec(qq);
    merge_sort(qq,0,qq.size() - 1);
    print_vec(qq);

    printf("Cܳ mother fucker\n");
    system("pause");
}
