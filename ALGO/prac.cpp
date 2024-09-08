#include<bits/stdc++.h>
using namespace std;
int median(vector<int> &arr,int low,int high){
    sort(arr.begin()+low,arr.begin()+high);
    return arr[(low+(high-low)/2)];
}
int partition(vector<int> &arr,int low,int high,int median){
    for(int i=low;i<high;i++){
        if(arr[i]==median){
            swap(arr[i],arr[high]);
            break;
        }
    }
    int pivot=arr[high];
    int storeindex=low;
    for(int i=low;i<high;i++){
        if(arr[i]<pivot){
            swap(arr[i],arr[storeindex]);
            storeindex++;
        }
    }
    swap(arr[storeindex],arr[high]);
    return storeindex;
}
int kthsmallest(vector<int> &arr,int low,int high,int k){
    int n=high-low+1;
    vector<int>medians;
    for(int i=0;i<n/5;i++){
       int mediann=median(arr,low+(i*5),low+(i*5)+5);
       medians.push_back(mediann);
    }
    if(n%5!=0){
        int mediann=median(arr,low+(n/5)*5,+low+(n/5)*5+(n%5));
        medians.push_back(mediann);
    }
    int mom;
    if(medians.size()==1)mom=medians[0];
    else{
        mom=median(medians,0,medians.size()-1);
    }
    int partitionn=partition(arr,low,high,mom);
    int rank=partitionn-low+1;
    if(rank==k)return arr[partitionn];
    else if(rank>k)return kthsmallest(arr,low,partitionn-1,k);
    else return kthsmallest(arr,partitionn+1,high,k-rank);
}

int main(){
    int k;
    vector<int> vec={76,9,8,7,6,5,4,3,2,1};
    cout<<"enter value of k";
    cin>>k;
    int val=kthsmallest(vec,0,vec.size()-1,k);
    cout<<" the "<<k<<"th smallest element is "<<val<<endl;
}