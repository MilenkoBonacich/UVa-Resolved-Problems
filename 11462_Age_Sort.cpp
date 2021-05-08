#include <iostream>

using namespace std;

int ages[200000001];

void merge(int vec[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
 
    for (int i = 0; i < n1; i++) L[i]=vec[l + i];
    for (int j = 0; j < n2; j++) R[j]=vec[m + 1 + j];
 
    int i = 0;
    int j = 0;
    int k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vec[k] = L[i];
            i++;
        }
        else {
            vec[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        vec[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        vec[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int vec[],int l,int r){
    long long swaps=0;
    if(l>=r){
        return;
    }
    int m =l+ (r-l)/2;
    mergeSort(vec,l,m);
    mergeSort(vec,m+1,r);
    merge(vec,l,m,r);
}


int main(){
    int n;
    while(cin>>n && n!=0){
        int aux;
        for(int i=0; i<n; ++i){
            cin>>aux;
            ages[i]=aux;
        }
        mergeSort(ages,0,n-1);
        for (int i=0; i<n; ++i){
            cout<<ages[i];
            if(i!=n-1)cout<<" ";
        }
        cout<<endl;
    }
}
