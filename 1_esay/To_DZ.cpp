/////////802题.区间和,先输入,n和m，
//n行add数据，即在位置 x 加上 c
//m行query数据，即返回值为l到r的前缀和
//重点在于数据范围极大,而数据量仅仅10e6 

// 3 3
// 1 2
// 3 6
// 7 5
// 1 3
// 4 6
// 7 8
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;
const int N = 300010;
int a[N],s[N];
typedef pair<int , int > PAI;

vector<int>::iterator unique(vector<int>& a){
    int j = 0 ;
    for(int i = 0 ; i < a.size() ; ++i){
        if(!i || a[i] != a[i - 1]) a[j++] = a[i];
    }
    return a.begin() + j ;//////必须返回迭代器
}
//模板   x为vector
void sort_unique(vector<int>& x){
///排序加上去重
sort(x.begin() , x.end());
////先unique(x.begin() , x.end())返回，去重后下标
////然后rease剔除掉后面部分
x.erase(unique(x.begin() , x.end()),x.end());
}
int find(int x , vector<int> alls){
    int l = 0 , r = alls.size() - 1;
    while(l < r){
        int mid = (l + r) / 2;
        if(alls[mid] >= x) r = mid;
        else l = mid +1;
    }
    return l + 1;/////////返回的是在数组里的索引值
}

void print_arr(vector<int> & x){
    for(auto i : x){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    // vector<int> x(5);
    // for(int i = 0 ; i < x.size() ;++i) cin>>x[i];
    // cout<<endl;
    // print_arr(x);
    // sort_unique(x);
    // print_arr(x);
    // vector<int> 
    vector<int> alls; //////存远有的标记
    vector<PAI> add,query;
    int n , m ;
    scanf("%d%d" , &n , &m);
    for(int i = 0 ; i < n ; ++i){
        int x,c;
        scanf("%d%d",&x,&c);
        ///要加到映射的数组上去
        add.push_back({x,c});
        alls.push_back(x);
    }
    for(int i = 0 ; i < m ; ++i){
        int l,r;
        scanf("%d%d",&l,&r);
        ///要加到映射的数组上去
        query.push_back(make_pair(l,r));
        alls.push_back(l);
        alls.push_back(r);
    }
    ////////已经出现的索引，都已经装入
    /////////想清楚，这个前缀和是，映射后的前缀和,
    //映射谁，alls，映射前需要，去重，排序
    sort_unique(alls);/////////alls用来存原索引，即映射前
    for(auto i : add){
        int x = find(i.first , alls);
        a[x] += i.second;//////a是原数组
    }
    ///////此时需要映射出下标，可从1开始,需要前缀和数组了
    ///////即现在需要映射的原索引的长度为alls.size()
    ///////但是a有数的中的长度，与alls长不一样
    for(int i = 1 ; i <= alls.size() ; ++i ) s[i] = s[i - 1] + a[i];

    for(auto i : query){
        int l = find(i.first , alls) ;
        int r = find(i.second , alls);
        cout<<s[r] - s[l -1]<<" ";
    }
    cout<<endl;
    printf("C 艹 mother fucker\n");
    system("pause");
}