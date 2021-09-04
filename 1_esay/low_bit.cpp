#include<iostream>

using namespace std;

//模板   x为二进制数
/////    -x == ~x + 1
/////通过(x&~x + 1) 求得x中1的个数
////补码 = 反码 + 1
int low_bit (int x){
    return x & -x;
}
// x -= low_bit(x)  ////减掉低位带1的数。eg:100101001000 - 1000 = 10010100 0000
int main(){
    int n ;////总共n个数，分别统计其1的个数
    cin>>n;
    while(n--){
        int x , res = 0;
        // scanf("%d",&x);
        cin>>x;///////两个循环条件，都很简略
        while(x) x -= low_bit(x), ++res;
        cout<<res<<" ";
    }
    cout<<endl;
    printf("C 艹 mother fucker\n");
    system("pause");
}