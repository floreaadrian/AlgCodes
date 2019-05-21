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

ifstream fin("/Users/adrianflorea/Codes/CatalystNov1/CatalystNov18/level2/level2_3.in");
ofstream fout("/Users/adrianflorea/Codes/CatalystNov1/CatalystNov18/data.out");

int main()
{
    int n;
    fin>>n;
    for(int i=0;i<n;++i) {
        int ax,ay,bx,by;
        double ratio;
        fin>>ax>>ay>>bx>>by>>ratio;
        double cx = ax + round(ratio*(bx-ax));
        double cy = ay + round(ratio*(by-ay));
        fout<<cx<<" "<<cy<<"\n";
    }
    return 0;
}

