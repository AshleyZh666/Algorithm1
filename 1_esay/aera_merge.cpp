//������n,��һ�½���n������
//������Ǻϲ������������,������ɺϲ�

// 5
// 1 1
// 2 4
// 5 6
// 7 8
// 7 9


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// const int N = 100010;

typedef pair<int , int> PAI;

// vector<PAI>
void merge_area(vector<PAI>& a){
    // int l = -2e9 , r = - 2e9;
    vector<PAI> res;
    sort(a.begin(),a.end());
    int l = a[0].first , r = a[0].second;
    for(auto i : a)
        if(r < i.first) {
            ///////��Ϊ��ʼ���䣬�����������
            ///////��Ϊ��ʼ���䣬����Ҫ
            res.push_back({l,r});
            l = i.first;
            r = i.second;
            }
        else r = max(r,i.second);////////��˵�����,����ֵ������l;
    if (r != -2e9) res.push_back({l,r});
    a = res;
    // return res;
}

int main(){
    int n ;
    scanf("%d" , &n);
    vector<PAI> a;
    while(n --){
        int l , r;
        scanf("%d%d" , &l , &r);
        a.push_back({l,r});
    }
    merge_area(a);
    cout<<a.size()<<endl;
    printf("C ܳ mother fucker\n");
    system("pause");
}