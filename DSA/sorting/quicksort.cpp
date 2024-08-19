#include<bits/stdc++.h>
using namespace std;

int partion(vector<int> &arr,int low,int high){
    int i=low+1;
    int j=high;
    int pivot=arr[low];
    while(i<=j){
        while(i<=j && arr[i]<=pivot)i++;
        while(i<=j && arr[j]>=pivot)j--;
        if(i<j)swap(arr[i],arr[j]);
    }
    swap(arr[j],arr[low]);
    return j;

}
void quicksort(vector<int> &obj,int low,int high){
    if(low<high){
        int partition=partion(obj,low,high);
        quicksort(obj,low,partition-1);
        quicksort(obj,partition+1,high);
    }

}
int main(){
   vector<int> vec={3, 21, 11, 65, 43, 22, 10, 9, 7};
   quicksort(vec,0,vec.size()-1);
   for(auto x:vec){
    cout<<x<<" ";
   }
}