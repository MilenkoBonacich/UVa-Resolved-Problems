#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <limits>
using namespace std;

int main(){
    double n, aux;
    cin >> n;
    cout<< setprecision(2) << fixed;
    while(n!=0){
        vector <double> cf;
        double irr, min=-1.0, max=numeric_limits<double>::max();
        for(int i=0; i<=n;i++){
            cin >> aux;
            cf.push_back(aux);
        }
        double npv;
        do{
            npv=cf.front();
            int root=1;
            double mid=(min+max)/2;
            for(vector<double>::iterator it = cf.begin()+1; it!=cf.end(); ++it, ++root){
                npv=npv+(*it/pow(1+mid,root));
            }
            npv= floor((npv * 1000) + .5) / 1000;
            if (npv>0) min=mid;
            else if(npv<0) max=mid;
            else irr=mid;
        } while (npv!=0.00);
        cout << irr << endl;
        cin >> n;
    }
}
