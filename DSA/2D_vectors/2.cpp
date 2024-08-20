/*2. Matrix Addition
Problem: Given two 2D vectors (matrices) of size 3x3,
 write a function to add the two matrices and store the result in a third 2D vector.
  Print the resulting matrix*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>>vec1 = {{1,2,3},{4,5,6},{8,9,10}};
    vector<vector<int>>vec2 = {{1,2,3},{4,5,6},{1,2,3}};
    vector<vector<int>>res(3,vector<int>(3));
    for(int i=0;i<vec1.size();i++){
      for(int j=0;j<vec2.size();j++){
        res[i][j]=vec1[i][j]+vec2[i][j];
      }
    }
    for(auto x : res){
        for(auto  y: x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
}