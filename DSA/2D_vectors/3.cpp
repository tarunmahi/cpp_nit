/*Problem: Implement matrix multiplication using 2D vectors. Given two matrices A and B,
 where A is of size 2x3 and B is of size 3x2, multiply them and store the result in matrix C.
 and also implement 4*2 and 2*4 matrix also
 Print the resulting matrix.*/
 #include<bits/stdc++.h>
 using namespace std;
void sample2(){
    vector<vector<int>>vec1={{1,2},{1,2},{1,2},{1,2}};
    vector<vector<int>>vec2={{1,2,3,4},{1,2,3,4}};
    vector<vector<int>>res(4,vector<int>(4,0));
    for(int i=0;i<vec1.size();i++){
        for(int j=0;j<vec1.size();j++){
            for(int k=0;k<vec1[i].size();k++){
                res[i][j]+=vec1[i][k]*vec2[k][j];
            }
        }
    }
    for(auto x : res){
        for(auto y:x){
            cout<<y<<" ";
        }cout<<endl;
    }
}




 int main(){
 vector<vector<int>>vec1={{1,2,3},{1,2,3}};
 vector<vector<int>>vec2={{1,2},{1,2},{1,2}};
 vector<vector<int>>res(2,vector<int>(2,0));
  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
        for(int k=0;k<3;k++){
            res[i][j]+=vec1[i][k]*vec2[k][j];
        }
    }
  }
  for(auto &x : res){
    for(auto &y:x){
        cout<<y<<" ";
    }cout<<endl;
  }
  sample2();
 }