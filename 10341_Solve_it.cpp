#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    int p, q, r, s, t, u;
    cout<< setprecision(4) << fixed;
    while(cin>>p>>q>>r>>s>>t>>u){
        double min=0.0000, max=1.0000,x,eq;
        do{
            if(p==0 && q==0 && r==0 && s==0 && t==0 && u==0){x=0; break;}
            x=( max+min)/2;
            eq=(p*exp(-x))+(q*sin(x))+(r*cos(x))+(s*tan(x))+(t*pow(x,2.0))+u;
            eq=floor((eq * 100000) + .5) / 100000;
            if(eq<0)max=x;
            else if(eq>0)min=x;
        }while(eq!=0 && min!=max);
        if(min==max)cout<<"No solution"<<endl;
        else cout<<x<<endl;
    }
}
