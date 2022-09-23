#include<iostream>
using namespace std;
int f(int*a,int n){
    if(n<=0)return(-1);
    else if(*a%2==0){

        return(*a-f(a+1,n-1));}
    else {
        return (*a+f(a+1,n-1));}

}
int main(){
    int a[]={10,15,17,18,26,39};
    printf("%d",f(a,6));

   
        
    
    }
    
