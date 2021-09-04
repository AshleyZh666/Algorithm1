#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;



bool baoli(string value , string pattern){
        int n = value.size() , i = 0;
        int m = pattern.size() , j = 0;
        bool flag = false;
        while(i < n && j < m){
            if(value[i] == pattern[j]){
                ++i;
                ++j;
            }
            else{
                i -= j - 1;
                j = 0;
            }
            if(j == m -1) {
                cout<< i - j<<endl;
                return true;}
        }
        cout<<"匹配失败"<<endl;
        return flag;
}
void print_arr(vector<int> N){
    for(auto  i : N) printf("%d " , i);
    printf("\n");
}

// vector<int> built_next(char P[]){
//     int m = strlen(P) , i = 0 ;//////主串
//     vector<int> N(m);///第一个位置废了？？？
//     int j = N[0] = -1;//////后串
//     while(i < m - 1){
//         if(j < 0 || P[i] == P[j]){
//             ++i;
//             ++j;
//             N[i] = (P[i] != P[j]) ? j : N[j];
//             // N[i] = j;
//         }
//         else{
//             j = N[j];
//         }
//     }
//     print_arr(N);
//     return N;
// }

int KMP(char T[] , char P[]){
    int n = strlen(T) , i = 0 ;
    int m = strlen(P) , j = 0 ;
    // vector<int> N = built_next(P);
    // vector<int> N(m);
    int Ne[m];
    j = Ne[0] = -1;
    while(i < m - 1){
        if(j < 0 || P[i] == P[j]){
            ++i;
            ++j;
            Ne[i] = (P[i] == P[j]) ? Ne[j] : j ;
        }
        else{
            j = Ne[j];
        }
    }
    i = 0 ;
    j = 0 ;
    while(i < n && j < m){
        if(j < 0 || T[i] == P[j]){
            ++i;
            ++j;
        }
        else{
            j = Ne[j];
        }
    }
    printf("\ni = %d j = %d\n", i ,j);
    return i - j;
}
////////N[j]即0到N[j] 和 j - N[j] +i 到 j的最长相同串
int main(){
    char T[] = "cococococococococococococococococococococococococococococococococococococococococococococococococococoacocococococococococococococococococococococococococococococococococococococococolaco";
    char P[] = "cococococococococococococola";
    // char P[] = "colacolacolacolacolacola";
    // -1 0 0 0 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
    // -1 0 0 0 -1 0 0 0 -1 0 0 0 -1 0 0 0 -1 0 0 0 -1 0 0 0
    printf("strlen(T) = %d , strlen(P) = %d\n",strlen(T),strlen(P));
    printf("%d\n",baoli(T,P));
    printf("%d\n",KMP(T,P));

    printf("mother fucker C ܳ\n");
    system("pause");
}