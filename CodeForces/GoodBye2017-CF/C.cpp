//
// Created by Adrian-Paul Florea on 12/29/17.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


int main()
{
    int n;
    double rad;
    vector <double> ans;
    cin >> n >> rad;
    double xCod[n+1];
    double yCod[n+1];
    for(int i=0;i<n;i++){
        cin >> xCod[i];
    }
    yCod[0] = rad;
    ans.push_back(rad);
    for(int i=1;i<n;i++){
        for(int j=ans.size()-1;j>=0;j--){
            if(abs(xCod[i]-xCod[j]) <= 2*rad){
                yCod[i] = sqrt((4*rad*rad) - (abs(xCod[i]-xCod[j]) * abs(xCod[i]-xCod[j])));
                yCod[i]+=yCod[j];
                ans.push_back(yCod[i]);
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%.7lf ",ans[i]);
    }
    printf("\n");
}