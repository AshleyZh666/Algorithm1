/////////整数二分,存在很多边界问题
////  两个模板。如下两个题
////  题目789.数的范围
////  题目290.书的三次方

#include<iostream>
#include<string>

using namespace std;

int bsearch_1(int l , int r){//找绿点，也就是右边界点
    int mid = (l + r)/2;
    while(l < r){
        if (check_green(mid)){
            //mid满足绿段，答案在[l,mid]
            r = mid;
        }
        else//mid满足红段,答案在[mid+1,r]
        {
            l = mid + 1;//(mid在左，不用管mid值)
        }
    }
    return l;
}
int bsearch_2(int l ,int r){//找红点，也就是左边界
    int mid = (l + r + 1)/2;
    while(l < r){
        if (check_red(mid)){//在红段，即[mid,r]
            l = mid;
        }
        else{//在绿段，即[l , mid-1]
            r = mid - 1 ;//（mid在右，需要+1）
        }
    }
    return l;
}

int main(){
    

    printf("C艹 mother fucker\n");
    system("pause");
}
