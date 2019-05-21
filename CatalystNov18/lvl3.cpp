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
#include <math.h>
using namespace std;

ifstream fin("/Users/adrianflorea/Codes/CatalystNov1/CatalystNov18/level3/level3_2.in");
ofstream fout("/Users/adrianflorea/Codes/CatalystNov1/CatalystNov18/data.out");


int main()
{
    int n;
    fin>>n;
    for(int i=0;i<n;++i) {
        vector<pair<int,int>> cells;
        int ax,ay,bx,by;
        fin>>ax>>ay>>bx>>by;
        for(double ratio=0;ratio<=1;ratio+=0.001){
            double cx = ax + round(ratio*(bx-ax));
            double cy = ay + round(ratio*(by-ay));
            pair<int,int> c;
            c.first=cx;
            c.second=cy;
            if(find(cells.begin(), cells.end(), c) == cells.end()) {
                cells.push_back(c);
            }
           // cout<<c.first<<" "<<c.second<<"\n";
        }
        for(auto it: cells)
            fout<<it.first<<" "<<it.second<<" ";
        fout<<"\n";
    }
    return 0;
}

