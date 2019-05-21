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

ifstream fin("/Users/adrianflorea/Codes/CatalystNov1/CatalystNov18/level4/level4_3.in");
ofstream fout("/Users/adrianflorea/Codes/CatalystNov1/CatalystNov18/data.out");


bool cmp(pair<int,int> a,pair<int, int> b){
    if(a.first < b.first)
        return true;
    if(a.first == b.first)
        if(a.second<b.second)
            return true;
    return false;
        
}

int main()
{
    int n,m;
    int a[600][600];
    fin>>n>>m;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            fin>>a[i][j];
    vector<pair<int,int>> points;
    vector<pair<int,int>> initPoints;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j)
            if(a[i][j]!=0){
                int i1=i,j1=j;
                while(a[i1][j]==a[i][j])
                    i1++;
                while(a[i][j1]==a[i][j])
                    j1++;
                i1--;
                j1--;
                if(i1!=i && j1!=j){
                pair<int,int> c;
                c.first=i1;
                c.second=j1;
                if(find(points.begin(), points.end(), c) == points.end()) {
                    points.push_back(c);
                    pair<int,int> c1;
                    c1.first=i;
                    c1.second=j;
                    initPoints.push_back(c1);
                }}
            }
    }
    vector<pair<int,int>> result;
    double ratio = 0.5;
    for(int i=0;i<points.size();i++){
        int ax = points[i].first,ay = points[i].second;
        int bx = initPoints[i].first, by = initPoints[i].second;
        if(ax-bx>=3 && ay-by>=3){
            double cx = ax + round(ratio*(bx-ax));
            double cy = ay + round(ratio*(by-ay));
            pair<int,int> c;
            c.first=cx;
            c.second=cy;
            result.push_back(c);
        }
    }
    sort(result.begin(),result.end(),cmp);
    for(int i=0;i<result.size();++i)
        fout<<i<<" "<<result[i].first<<" "<<result[i].second<<" ";
    return 0;
}

