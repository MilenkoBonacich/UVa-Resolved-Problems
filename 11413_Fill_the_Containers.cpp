#include <iostream>
#include <vector>
using namespace std;

bool cap(int capacity, vector<int> milk, int m){
    int container=0;
    int count=1;
    for(int i=0; i<milk.size(); ++i){
        if(milk[i]>capacity) return false;
        if(container+milk[i]>capacity){container=0; ++count;}
        if(count>m)return false;
        container+=milk[i];
    }
    return true;
}

int main(){
    int n, m, aux;
    while(cin>>n>>m){
        int max=0;
        vector<int> ves;
        for(int i=0; i<n; ++i){
            cin>>aux;
            max+=aux;
            ves.push_back(aux);
        }
        int lo=1, hi=max;
        int mid;
        while(lo<=hi){
            mid=(lo+hi)/2;
            if(cap(mid,ves,m)){max=mid; hi=mid-1;}
            else lo=mid+1;
        }
        cout<<max<<endl;
    }
}
