#include<bits/stdc++.h>
using namespace std;

int main(){
    set<int> s;
    int arr[5] = {1,1,2,3,3};
    for(auto &x:arr){
        s.insert(x);
    }
    cout<<s.size();
}