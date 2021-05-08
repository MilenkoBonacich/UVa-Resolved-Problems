#include <iostream>

using namespace std;

int students[1000006];
long long swaps;

void merge(int vec[], int l, int m, int r) //MergeSort sacado de GeeksForGeeks de flojera
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
            swaps+=(n1-i);
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
    int n, aux;
    while(cin>>n){
        swaps=0;
        for(int i=0; i<n; ++i){
            cin>>aux;
            students[i]=aux;
        }
        mergeSort(students,0,n-1);
        cout<<swaps<<endl;
    }
}
