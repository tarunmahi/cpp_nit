#include<bits/stdc++.h>
using namespace std;

int partiti(vector<int> &arr, int low,int high){
    int i= low+1;
    int j = high;
    int pivot = arr[low];
    while(i<=j){
        if(i<=j && arr[i]<=pivot)i++;
        if(i<=j && arr[j]>=pivot)j--;
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}

void   quickSort(vector<int> &arr,int low,int high){
    if(low<high){
int partition1 = partiti(arr,low,high);
quickSort(arr,low,partition1-1);
quickSort(arr,partition1+1,high);
    }
}
void printVector(vector<int> &arr){
    for(auto &x : arr){
        cout<<x<<" ";
    }
}

int main(){
     
    int n;
    cout<<"enter size of array";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        int num=0;
        cin>>num;
        arr[i]=num;
    }

    cout << "Given vector is \n";
    printVector(arr);

    quickSort(arr, 0, n - 1);

    cout << "\nSorted vector is \n";
    printVector(arr);
    return 0;
}