/*4. Transpose of a Matrix
Problem: Given a 2D vector representing a matrix,
 write a function to compute its transpose. The transpose of a matrix is 
 obtained by flipping the matrix over its diagonal, i.e., converting row indices 
 into column indices and vice versa. Print the transposed matrix.*/
 #include<bits/stdc++.h>
 using namespace std;

 int main(){
    vector<vector<int>>vec={{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>>vec1={{1,2,3,4},{1,2,3,4}};
    int rows=vec1.size();
    int cols=vec1[0].size();
    vector<vector<int>>res(cols,vector<int>(rows,0));

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            res[j][i]=vec1[i][j];
        }
    }
    for(auto x:res){
        for(auto y:x){
            cout<<y<<" ";
        }cout<<endl;
    }
 }