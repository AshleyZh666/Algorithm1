#include<iostream>

using namespace std;

//ģ��   xΪ��������
/////    -x == ~x + 1
/////ͨ��(x&~x + 1) ���x��1�ĸ���
////���� = ���� + 1
int low_bit (int x){
    return x & -x;
}
// x -= low_bit(x)  ////������λ��1������eg:100101001000 - 1000 = 10010100 0000
int main(){
    int n ;////�ܹ�n�������ֱ�ͳ����1�ĸ���
    cin>>n;
    while(n--){
        int x , res = 0;
        // scanf("%d",&x);
        cin>>x;///////����ѭ�����������ܼ���
        while(x) x -= low_bit(x), ++res;
        cout<<res<<" ";
    }
    cout<<endl;
    printf("C ܳ mother fucker\n");
    system("pause");
}