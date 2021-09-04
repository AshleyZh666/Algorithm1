/////////浮点数二分,十分简单
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

double tow_piece_float(double n){
    double l = 0 , h = n;
    while(h - l > 1e-6){
        double mid = (l + h)/2;
        if(mid * mid >= n) h = mid;
        else l = mid;
    }
    return h ;
}

int main(){
    double n ;
    // scanf("%lf" , &n);
    cin>>n;
    // double l = 0 , h = n;
    // while(h - l > 1e-8){
    //     double mid = (l + h)/2;
    //     if(mid * mid >= n) h = mid;
    //     else l = mid;
    // }
    // printf("%lf\n", l);
    // double res = tow_piece_float(n);

    // vector<int> dp = {3,2,1};
    // sort(dp);

    printf("%lf\n", tow_piece_float(n));
    printf("C艹 mother fucker\n");
    system("pause");
}