#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    int a[n];
    int b[n];
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        cout<<" ";
    }
    for (int i = 0; i < n; i++){
        for (int j = i; j< n; j++){

            ans+=a[j];
            if(ans==k){
                 b[0]=i+1;
                 b[1]=j+1;
            }
        }
        
        
    }
    cout<<b[0]<<" "<<b[1];
    
    
}

