#include<iostream>

using namespace std;

//模板


int main(){
    int n = 10;
    ///那么如何知道 这个 3 呢;
    for (int i = 3 ; 0 <= i ; --i )
        cout<< (n >> i & 1)<<" ";
    cout<<endl;
    printf("C 艹 mother fucker\n");
    system("pause");
}