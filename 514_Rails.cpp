#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(){
    stack <int> station;
    queue <int> raila, desired;
    int aux, n, cart;
    cin>>n;
    while (true){
        cin>>aux;
        if(aux!=0){
            int count=1;
            while(count!=n+1){
                raila.push(count);
                ++count;
            }
            for (int i=0; i<n; ++i){
                desired.push(aux);
                if(i!=n-1)cin>>aux;
            }
            while (true){
                if(!station.empty()){
                    if(desired.front()==station.top()){
                        desired.pop();
                        station.pop();
                    }else if(raila.empty()){
                        cout<<"No"<<endl;
                        break;
                    }else{
                        station.push(raila.front());
                        raila.pop();
                    }
                }
                else if(!raila.empty()){
                    station.push(raila.front());
                    raila.pop();
                }
                else if(desired.empty()){
                    cout<<"Yes"<<endl;
                    break;
                }
            }
        }else{
            cout<<endl;
            cin>>n;
            if(n==0){
                break;
            }
        }
        while(!station.empty()) station.pop();
        while(!desired.empty()) desired.pop();
    }
}
