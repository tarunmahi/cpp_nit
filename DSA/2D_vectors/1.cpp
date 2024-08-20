/*1. Basic Operations on 2D Vectors
Problem: Create a 2D vector with 3 rows and 4 columns, 
where each element is initialized to 0. Then update the 2D vector such that:

The first row contains numbers from 1 to 4.
The second row contains numbers from 5 to 8.
The third row contains numbers from 9 to 12.
Print the 2D vector.
Hint: Use nested loops to update and print the 2D vector*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>>vec(3,vector<int>(4,0));
    int val=1;
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec[i].size();j++){
            vec[i][j]=val++;
        }
    }
    for(auto &X:vec){
        for(auto &v :X){
          cout<<v<<" ";
        }
        cout<<endl;
    }
}