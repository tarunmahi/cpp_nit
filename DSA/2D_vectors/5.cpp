/*5. Searching in a 2D Vector
Problem: Write a function to search for an element in a 2D vector.
 If the element is found, return its position (row and column index). 
 If the element is not found, return -1.
*/
#include<bits/stdc++.h>
using namespace std;

pair<int,int> findof(vector<vector<int>> &arr,int val){
    int row=arr.size();
    int col=arr[0].size();
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]==val){
                return {i,j};
            }
        }
    }
    return {-1,-1};
}

int main(){
    vector<vector<int>>vec={{1,2,3,4},{11,12,14,15},{21,22,23,24},{34,35,31,32}};
    int target=35;
    pair<int,int> res = findof(vec,target);
    if(res.first==-1){
        cout<<"element is not found";
    }
    else{
        cout<<"element found at index value["<<res.first<<"],["<<res.second<<"]";
    }
}