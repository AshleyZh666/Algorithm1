//先输入n,即一下将有n个区间
//输出则是合并后的区间数量,闭区间可合并

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
            ///////不为初始区间，才算独立区间
            ///////不为初始区间，很重要
            res.push_back({l,r});
            l = i.first;
            r = i.second;
            }
        else r = max(r,i.second);////////左端点有序,此两值都大于l;
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
    printf("C 艹 mother fucker\n");
    system("pause");
}