//
// Created by Adrian-Paul Florea on 1/5/18.
//
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int v[4];
        cin>>v[0]>>v[1]>>v[2]>>v[3];
        sort(v,v+4);
        if(v[0]==v[1] && v[2]==v[3])
            cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
