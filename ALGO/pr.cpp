int isSorted(int n, vector<int> a) {
    int count=0;
    for (int i=0;i<n;i++){
        if(a[i]>a[i+1]){
          return 0;
        }
    }
    return 1;
}

int main(){
    
}