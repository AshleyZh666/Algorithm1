/////////��������,���ںܶ�߽�����
////  ����ģ�塣����������
////  ��Ŀ789.���ķ�Χ
////  ��Ŀ290.������η�

#include<iostream>
#include<string>

using namespace std;

int bsearch_1(int l , int r){//���̵㣬Ҳ�����ұ߽��
    int mid = (l + r)/2;
    while(l < r){
        if (check_green(mid)){
            //mid�����̶Σ�����[l,mid]
            r = mid;
        }
        else//mid������,����[mid+1,r]
        {
            l = mid + 1;//(mid���󣬲��ù�midֵ)
        }
    }
    return l;
}
int bsearch_2(int l ,int r){//�Һ�㣬Ҳ������߽�
    int mid = (l + r + 1)/2;
    while(l < r){
        if (check_red(mid)){//�ں�Σ���[mid,r]
            l = mid;
        }
        else{//���̶Σ���[l , mid-1]
            r = mid - 1 ;//��mid���ң���Ҫ+1��
        }
    }
    return l;
}

int main(){
    

    printf("Cܳ mother fucker\n");
    system("pause");
}
