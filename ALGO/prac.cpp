#include<bits/stdc++.h>
using namespace std;
int nCr(int a, int b){
    int res=1;
    for(int i=0;i<b;i++){
        res*=(a-i);
        res/=(i+1);
    }
    return res;
}
void printpascal(int c){
    for(int i=1;i<=c;i++){
        for(int k=1;k<=i;k++){
            cout<<nCr(i-1,k-1)<<" ";
        }cout<<"\n";
}}


int main(){
    // int n=10;
    // printpascal(n);
    cout<<floor(7/2);
    map<int,int>res;

}