#include<bits/stdc++.h>
using namespace std;

void insertion(vector<int> &arr){
    int n= arr.size();
    for(int i=0;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}

int main(){
    int num;
     cout<<"enter size of array";
    cin>>num;
    vector<int> arr(num);
    for(int i=0;i<num;i++){
       int n;
       cin>>n;
       arr[i]=n;
    }
    insertion(arr);
    for(auto &x : arr){
        cout<<x<<" ";
}}