/////////802��.�����,������,n��m��
//n��add���ݣ�����λ�� x ���� c
//m��query���ݣ�������ֵΪl��r��ǰ׺��
//�ص��������ݷ�Χ����,������������10e6 

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
    return a.begin() + j ;//////���뷵�ص�����
}
//ģ��   xΪvector
void sort_unique(vector<int>& x){
///�������ȥ��
sort(x.begin() , x.end());
////��unique(x.begin() , x.end())���أ�ȥ�غ��±�
////Ȼ��rease�޳������沿��
x.erase(unique(x.begin() , x.end()),x.end());
}
int find(int x , vector<int> alls){
    int l = 0 , r = alls.size() - 1;
    while(l < r){
        int mid = (l + r) / 2;
        if(alls[mid] >= x) r = mid;
        else l = mid +1;
    }
    return l + 1;/////////���ص����������������ֵ
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
    vector<int> alls; //////��Զ�еı��
    vector<PAI> add,query;
    int n , m ;
    scanf("%d%d" , &n , &m);
    for(int i = 0 ; i < n ; ++i){
        int x,c;
        scanf("%d%d",&x,&c);
        ///Ҫ�ӵ�ӳ���������ȥ
        add.push_back({x,c});
        alls.push_back(x);
    }
    for(int i = 0 ; i < m ; ++i){
        int l,r;
        scanf("%d%d",&l,&r);
        ///Ҫ�ӵ�ӳ���������ȥ
        query.push_back(make_pair(l,r));
        alls.push_back(l);
        alls.push_back(r);
    }
    ////////�Ѿ����ֵ����������Ѿ�װ��
    /////////����������ǰ׺���ǣ�ӳ����ǰ׺��,
    //ӳ��˭��alls��ӳ��ǰ��Ҫ��ȥ�أ�����
    sort_unique(alls);/////////alls������ԭ��������ӳ��ǰ
    for(auto i : add){
        int x = find(i.first , alls);
        a[x] += i.second;//////a��ԭ����
    }
    ///////��ʱ��Ҫӳ����±꣬�ɴ�1��ʼ,��Ҫǰ׺��������
    ///////��������Ҫӳ���ԭ�����ĳ���Ϊalls.size()
    ///////����a�������еĳ��ȣ���alls����һ��
    for(int i = 1 ; i <= alls.size() ; ++i ) s[i] = s[i - 1] + a[i];

    for(auto i : query){
        int l = find(i.first , alls) ;
        int r = find(i.second , alls);
        cout<<s[r] - s[l -1]<<" ";
    }
    cout<<endl;
    printf("C ܳ mother fucker\n");
    system("pause");
}