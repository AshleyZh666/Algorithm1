////ʱ�临�Ӷ��ȶ�Ϊ:O(n*log(n))

////����Ϊ��q[] , l , h    ��Ϊ����n�Ϻ�
////////�ѵ����ڷ�Ͱ���ԣ���Ͱ���գ��Һ���

////1.װͰ����Ͱ����
////2.Ͱ������

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

// const int N = 1000001;
// int temp[N];

void bucket_sort(int q[] , int l , int h){
    if(l >= h) return ;////////��ס����ֹ������l >= h;
    // int i = l - 1 , j = h + 1 , x = (q[l] + q[h])/2;
    ////�������ݣ����������Ͱ
    vector<vector<int>> temp(3,vector<int>(0));
    for(int i = 0 ; i <= h ; ++i){
        temp[q[i]/10 - 1].push_back(q[i]);//////////��ʵ�˴���װͰ���Բ��ǹؼ�
    }
    // cout<<temp[0][0]<<temp[0][1]<<temp[0][2]<<endl;
    int k = 0;
    for(int i = 0 ; i < temp.size() ; ++i){
        sort(temp[i].begin(),temp[i].end());
        for(int j = 0 ; j < temp[i].size() ; ++j,++k){
            // q[i*temp[i].size()+j] = temp[i][j];
            q[k] = temp[i][j];
        }
    }  
}
//////����������
void bucket_sort(vector<int>& q , int l , int h){
    if(l >= h) return ;////////��ס����ֹ������l >= h;
    // int i = l - 1 , j = h + 1 , x = (q[l] + q[h])/2;
    vector<vector<int>> temp(3,vector<int>(0));
    for(int i = 0 ; i <= h ; ++i){
        temp[q[i]/10 - 1].push_back(q[i]);
    }
    q.clear();/////////���q����ֹ�ӳ�
    for(int i = 0 ; i < temp.size() ; ++i){
        sort(temp[i].begin(),temp[i].end());
        for(int j = 0 ; j < temp[i].size() ; ++j){
            // q[i*temp[i].size()+j] = temp[i][j];
            q.push_back(temp[i][j]);
        }
    }  
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
    // int q[10] = {10,9,8,7,6,5,4,3,2,1};
    int q[10] = {30,39,38,37,26,25,24,13,12,11};
    print_arr(q,sizeof(q)/sizeof(q[0]));
    bucket_sort(q,0,sizeof(q)/sizeof(q[0])-1);
    print_arr(q,sizeof(q)/sizeof(q[0]));
//////////
    printf("�����鲢����ǰ��\n");
    vector<int> qq = {30,39,38,37,26,25,24,13,12,11};
    print_vec(qq);
    bucket_sort(qq,0,qq.size() - 1);
    print_vec(qq);

    printf("Cܳ mother fucker\n");
    system("pause");
}
