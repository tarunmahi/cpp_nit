#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr,int left,int mid,int right){
    int n1=mid-left+1;
    int n2 = right-mid;
    vector<int> vec1(n1),vec2(n2);
    for(int i=0;i<n1;i++)vec1[i]=arr[left+i];
    for(int j=0;j<n2;j++)vec2[j]=arr[mid+j+1];
    int i=0,j=0,k=left;
    while(i<n1 && j<n2){
        if(vec1[i]<vec2[j]){
            arr[k]=vec1[i];
            i++;
        }
        else{
            arr[k]=vec2[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=vec1[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=vec2[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr,int low,int high){
    if (low<high){
    int mid = low+(high-low)/2;

    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);

    }
}
void printVector(vector<int> &arr){
    for(auto x:arr)cout<<x<<" ";
}
int main()
{
    vector<int> arr = { 12, 11, 13, 5, 6, 7 };
    int n = arr.size();

    cout << "Given vector is \n";
    printVector(arr);

    mergeSort(arr, 0, n - 1);

    cout << "\nSorted vector is \n";
    printVector(arr);
    return 0;}