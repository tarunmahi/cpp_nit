//finding the kth smallest median using the median of medians program 
//Benifit- having a time complexity of O(n) instead of usual O(nlogn)
#include<bits/stdc++.h>
using namespace std;
int findmedian(vector<int> &arr,int low,int high){
    sort(arr.begin()+low,arr.begin()+high);
    return arr[low+(high-low)/2]; 
}
int partiton(vector<int> &arr,int low, int high,int median){
    for(int i=low;i<high;i++){
        if(arr[i]==median){
            swap(arr[i],arr[high]);
            break;
        }
    }
    int pivotval=arr[high];
    int storind=low;
    for(int i=low;i<high;i++){
        if(arr[i]<pivotval){
            swap(arr[storind],arr[i]);
            storind++;
        }
    }
    swap(arr[storind],arr[high]);
    return storind;
}
int kthsmallest(vector<int> &arr,int low,int high,int k){
    int n=high-low+1;
    vector<int>medians;
    for(int i=0;i<n/5;i++){
        int median=findmedian(arr,low+(i*5),low+(i*5)+5);
        medians.push_back(median);
    }
    if(n%5!=0){
        int median=findmedian(arr,low+(n/5)*5,low+(n/5)*5+(n%5));
        medians.push_back(median);
    }
    int mom;
    if(medians.size()==1)mom=medians[0];
    else{
        mom=kthsmallest(medians,0,medians.size()-1,medians.size()/2);
    }

    int pivotindex=partiton(arr,low,high,mom);
    int rank=pivotindex-low+1;
    if(rank==k)return arr[pivotindex];
    else if(rank>k)return kthsmallest(arr,low,pivotindex-1,k);
    else return kthsmallest(arr,pivotindex+1,high,k-rank);

}

int main(){
    int k=11;
    vector<int> rec={34,56,21,23,78,90,43,11,9,8,7,6,5,4,3,2,1};
    int small=kthsmallest(rec,0,rec.size()-1,k);
    cout<<"the smallest element is "<<small<<endl;
}