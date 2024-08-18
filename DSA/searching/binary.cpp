#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> const &arr,int key){
    int left=0,right=arr.size()-1;
    while(left<=right){
        int mid = left+(right-left)/2;
        if(arr[mid]==key)return mid;
        else if(arr[mid]<key)left=mid+1;
        else right=mid-1;
    }
    return -1;
   
}


int main() {
    vector<int> arr = {1, 2, 4, 7, 8, 9};
    int key = 4;
    int index = binarySearch(arr, key);

    if (index != -1) {
        cout << "Element found at index " << index << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}