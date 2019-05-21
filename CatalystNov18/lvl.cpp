//
//  main.cpp
//  CatalystNov18
//
//  Created by Adrian-Paul Florea on 11/16/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

ifstream fin("/Users/adrianflorea/Codes/CatalystNov1/CatalystNov18/level1/level1_3.in");
ofstream fout("/Users/adrianflorea/Codes/CatalystNov1/CatalystNov18/data.out");

int main()
{
    int n,m;
    vector<int> inaltimiUnice;
    fin>>n>>m;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j){
            int height;
            fin>>height;
            if(height!=0)
                if(find(inaltimiUnice.begin(), inaltimiUnice.end(), height) == inaltimiUnice.end()) {
                    inaltimiUnice.push_back(height);
                }
        }
    sort(inaltimiUnice.begin(),inaltimiUnice.end());
    for(int i=0;i<inaltimiUnice.size();++i){
        fout<<inaltimiUnice[i]<<" ";
    }
    if(inaltimiUnice.size()==0)
        fout<<0;
    
    return 0;
}

