#include<bits/stdc++.h>
using namespace std;

int findof(vector<int> const &obj,int k){
    for(int i=0;i<obj.size();i++){
        if(obj[i]==k)return i;
    }
    return -1;

}

int main(){
    vector<int> vec={1,5,43,21,65,7,2,76,54,33,99};
    int key;
    cout<<"enter the key value";
    cin>>key;
    int index=findof(vec,key);

    if(index!=-1)cout<<"the element is being found at index "<<index<<endl;
    else cout<<"element is not found";
}

//time complexity is O(n);
//->has to search ever element for the req number/key