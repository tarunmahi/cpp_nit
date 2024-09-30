//usd to find in both negative and positive integers for target=k
//has a time complexity of O(n) and O(nlogn) depending on used hash structure
#include <bits/stdc++.h> 
using namespace std;
int getLongestSubarray(vector<int>& nums, int k){
    // Write your code here
   map<int,int> ma;
   int sum=0;
   int maxlen=0;
   for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        if(sum==k){
            maxlen=max(maxlen,i+1);
        }
        int rem=sum-k;
        if(ma.find(rem)!=ma.end()){
            int len=i-ma[rem];
            maxlen=max(maxlen,len);
        }
        if(ma.find(sum)==ma.end()){
            ma[sum]=i;
        }
   }
   return maxlen;
}