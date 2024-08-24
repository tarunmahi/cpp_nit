#include<bits/stdc++.h>
using namespace std;

void mergeo(vector<int> &arr,int low,int mid,int high){
    int n1 =mid-low+1;
    int n2 = high-mid;
    vector<int> v1(n1);
    vector<int> v2(n2);
    for(int i=0;i<n1;i++){
        v1[i]=arr[low+i];
    }
    for(int i=0;i<n2;i++){
        v2[i]=arr[mid+i+1];
    }
    int i=0,j=0,k=low;
    while(i<n1 && j<n2){
        if(v1[i]<v2[j]){
            arr[k]=v1[i];
            i++;
        }
        else{
            arr[k]=v2[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=v1[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=v2[j];
        j++;
        k++;
    }
}
void mergesort(vector<int> &arr,int low,int high){
     if(low<high){
     int mid = low+(high-low)/2;
     mergesort(arr,low,mid);
     mergesort(arr,mid+1,high);
     mergeo(arr,low,mid,high);
}}

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
    mergesort(arr,0,arr.size()-1);
    for(auto &x : arr){
        cout<<x<<" ";
    }    
    }