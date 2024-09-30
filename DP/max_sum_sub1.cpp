//kadanes algo 
//has a linear time complexity  O(n)
#include<bits/stdc++.h>
using namespace std;

tuple<int,int,int> maxSubArray(vector<int> &arr){
   int left_i=0,right_i=0,temp_i=0,sum=0,max_sum=arr[0];
   for (int i = 0; i < arr.size(); i++){
    /* code */
    sum+=arr[i];
    if(sum>max_sum){
        max_sum=sum;
        left_i=temp_i;
        right_i=i;
    }
    if(sum<0){
        sum=0;
        temp_i=i+1;
    }
   }
   return make_tuple(max_sum,left_i,right_i);
}

int main(){
        vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};  // Example input

    // Getting the max sum and indices
    auto [max_sum, start, end] = maxSubArray(nums);

    cout << "Maximum Sum Subarray: " << max_sum << endl;
    cout << "Start Index: " << start << ", End Index: " << end << endl;

    return 0;
}

