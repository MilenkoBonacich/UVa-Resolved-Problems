#include <iostream>
#include <map>
#include <bits/stdc++.h>

using namespace std;

struct Dictionary{
    unordered_map <string, string> entries;
}d;

int main(){
    int flag = 0;
    string line, english, foreign;
    while (getline(cin,line) && !line.empty()){
        istringstream word(line);
        word >> english;
        word >> foreign;
        d.entries.insert(make_pair(foreign,english));
    }
    while(getline(cin,foreign) && !foreign.empty()){
        if (d.entries.count(foreign)) cout << d.entries[foreign] << endl;
        else cout <<"eh"<<endl;
    }
}
