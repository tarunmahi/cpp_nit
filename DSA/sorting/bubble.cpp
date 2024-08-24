#include<bits/stdc++.h>
using namespace std;


void bubblesort(vector<int> &arr, int n){
    for(int i=0;i<arr.size();i++){
        for(int j=i;j<arr.size();j++){
            if(arr[j]<arr[i]){
                swap(arr[j],arr[i]);
            }
        }
    }
}

int main(){
    int num;
    cout<<"enter the size of vector ";
    cin>>num;
    vector<int> vec(num);
    for(int i=0;i<num;i++){
        int n;
        cin>>n;
        vec[i]=n;
    }
    bubblesort(vec,vec.size());

    for(auto &x : vec){
        cout<<x<<" ";
    }
}