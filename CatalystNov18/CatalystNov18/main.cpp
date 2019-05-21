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

ifstream fin("/Users/adrianflorea/Codes/CatalystNov1/CatalystNov18/level5/level5_0.in");
ofstream fout("/Users/adrianflorea/Codes/CatalystNov1/CatalystNov18/data.out");


bool cmp(pair<int,int> a,pair<int, int> b){
    if(a.first < b.first)
        return true;
    if(a.first == b.first)
        if(a.second < b.second)
            return true;
    return false;
    
}
int n,m;

int a[600][600];
vector<vector<int>> output;
void friendi(int i,int j,int index,int nr,int s){
    int x = n;
    int y = m;
    int flagc = 0;
    vector<pair<int,int>> steps;
    int flagr = 0;
    int k,kk=0;
    for(k=i;k<x;k++){
        if(a[k][j] == 0){
            flagr = 1;
            break;
        }
        if(a[k][j] == -1){
            ;
        }
        for(kk=j;kk<=y;++kk){
            if(a[k][kk] == 0){
                flagc = 1;
                break;
            }
            pair<int,int> some;
            some.first=k;
            some.second=kk;
            steps.push_back(some);
            a[k][kk] = -1;
        }
    }
    if(k-i >= s-1 && kk-j>=s-1){
        cout<<k<<" "<<kk<<"\n";
        if (flagr == 1){
            output[index].push_back(k-1);}
        else{
            output[index].push_back(k);
        }
        if (flagc == 1){
            output[index].push_back(kk-1);}
        else{
            output[index].push_back(kk);}
    }else{
        for(auto it: steps){
            a[it.first][it.second] = nr;
            cout<<it.first<<" "<<it.second<<"\n";
        }
    }
    
}

int main()
{
    int s;
    fin>>n>>m>>s;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            fin>>a[i][j];
    
    
    vector<pair<int,int>> points;
    vector<pair<int,int>> initPoints;
    //    for(int i=0;i<n;++i)
    //        for(int j=0;j<m;++j)
    //            if(a[i][j]!=0){
    //                int i1=i,j1=j;
    //                while(a[i1][j]==a[i][j])
    //                    i1++;
    //
    //                while(a[i][j1]==a[i][j])
    //                    j1++;
    //
    //                i1--;
    //                j1--;
    //                if(i1!=i && j1!=j){
    //                        if(i1-i>=s-1 && j1-j>=s-1){
    //                            pair<int,int> c;
    //                            c.first=i1;
    //                            c.second=j1;
    //                            if(find(points.begin(), points.end(), c) == points.end()) {
    //                                points.push_back(c);
    //                                pair<int,int> c1;
    //                                c1.first=i;
    //                                c1.second=j;
    //                                initPoints.push_back(c1);
    //                        }
    //                    }
    //                }
    //            }
    int index = -1;
    for(int i=0; i<n ;++i)
        for(int j=0; j<m;++j)
            if(a[i][j]>0){
                vector<int> ceva;
                ceva.push_back(i);
                ceva.push_back(j);
                output.push_back(ceva);
                index +=1;
                friendi(i, j, index,a[i][j],s);
                for(int ii=0;ii<n;++ii){
                    for(int jj=0;jj<m;++jj)
                        cout<<a[ii][jj]<<" ";
                    cout<<"\n";
                }
                cout<<"\n--------------------------\n";
            }
    vector<pair<int,int>> result;
    for(auto it: output){
        int ax = it[0],ay = it[1];
        cout<<ax<<" "<<ay<<"\n";
        int bx = it[2], by = it[3];
        cout<<bx<<" "<<by<<"\n";
        double ratio = 0.5;
        double cx = ax + round(ratio*(bx-ax));
        double cy = ay + round(ratio*(by-ay));
        pair<int,int> c;
        c.first=cx;
        c.second=cy;
        result.push_back(c);
        //}
        //cout<<"\n";
    }
    //    vector<pair<int,int>> result;
    //    double ratio = 0.5;
    //    for(int i=0;i<points.size();i++){
    //        int ax = points[i].first,ay = points[i].second;
    //        cout<<ax<<" "<<ay<<"\n";
    //        int bx = initPoints[i].first, by = initPoints[i].second;
    //        cout<<bx<<" "<<by<<"\n";
    //        if(ax-bx>=s-1 && ay-by>=s-1){
    //            double cx = ax + round(ratio*(bx-ax));
    //            double cy = ay + round(ratio*(by-ay));
    //            pair<int,int> c;
    //            c.first=cx;
    //            c.second=cy;
    //            result.push_back(c);
    //        }
    //    }
    sort(result.begin(),result.end(),cmp);
    for(int i=0;i<result.size();++i)
        fout<<i<<" "<<result[i].first<<" "<<result[i].second<<" ";
    return 0;
}
