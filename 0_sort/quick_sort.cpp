////ƽ��ʱ�临�Ӷ�Ϊ:O(n*log(n)),�n^2��������ﵽ

////����Ϊ��q[] , l , h
////  
////1.���õݹ��������
////2.i,j;������ֵ��x��ֱ�Ӽ�Ϊq[��l+h��/2]
////3.����ѭ������ֹ�������ԣ�ע��while��ֹͣ������Ѱ����������㡣��swap()
////4.���ʼ�ݹ飬���ֶ���֮������l��h��ע��߽�㡣

#include<iostream>
#include<string>
#include<vector>

using namespace std;

void quick_sort(int q[] , int l , int h){
    if(l >= h) return ;////////��ס����ֹ������l >= h;
    // int i = l - 1 , j = h + 1 , x = (q[l] + q[h])/2;
    int i = l - 1 , j = h + 1 , x = q[(l+h)/2];
    while(i < j){//////ѭ������ʱ,��Ȼ��i �� j ����,����l���С��x,�ұߵĶ�����x;
    while(q[++i] < x);
    while(q[--j] > x);
    if (i < j) swap(q[i],q[j]);
    }
    quick_sort(q,l,i);
    quick_sort(q,i+1,h);
}
//////����������
void quick_sort(vector<int>& q , int l , int h){
    if(l >= h) return ;////////��ס����ֹ������l >= h;
    // int i = l - 1 , j = h + 1 , x = (q[l] + q[h])/2;
    int i = l - 1 , j = h + 1 , x = q[(l+h)/2];
    while(i < j){//////ѭ������ʱ,��Ȼ��i �� j ����,����l���С��x,�ұߵĶ�����x;
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
    printf("�����������ǰ��\n");
    int q[10] = {10,9,8,7,6,5,4,3,2,1};
    print_arr(q,sizeof(q)/sizeof(q[0]));
    quick_sort(q,0,sizeof(q)/sizeof(q[0])-1);
    print_arr(q,sizeof(q)/sizeof(q[0]));
//////////
    printf("������������ǰ��\n");
    vector<int> qq = {10,9,8,7,6,5,4,3,2,1};
    print_vec(qq);
    quick_sort(qq,0,qq.size() - 1);
    print_vec(qq);

    printf("Cܳ mother fucker\n");
    system("pause");
}
