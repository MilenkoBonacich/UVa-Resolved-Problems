#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(){
    double n=0, km=0, lastkm=0, leak=0;
    double fuel=0, minfuel=0;
    string event;
    cout<< setprecision(3) << fixed;
    while(cin>>km>>event){
        fuel=fuel+(km-lastkm)*leak+((km-lastkm)/100.0)*n;
        if(event.compare("Fuel")==0){
            cin>>event>>n;
            if (n==0) break;
        }else if(event.compare("Leak")==0) ++leak;
        else if(event.compare("Gas")==0){
            cin>>event;
            if(minfuel<fuel)minfuel=fuel; 
            fuel=0;
        }else if(event.compare("Mechanic")==0) leak=0;
        else if(event.compare("Goal")==0){
            if(minfuel<fuel)minfuel=fuel;
            cout<<minfuel<<endl;
            fuel=0; n=0; lastkm=0; km=0; leak=0, minfuel=0;
        }
        lastkm=km;
    }
}
