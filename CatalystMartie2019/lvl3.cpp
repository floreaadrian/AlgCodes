//
//  main.cpp
//  CatalystMartie2019
//
//  Created by Adrian-Paul Florea on 3/22/19.
//  Copyright © 2019 Adrian-Paul Florea. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <string.h>
#include <sstream>
#include <algorithm>
#include <math.h>

using namespace std;

ifstream fin("/Users/adrianflorea/Codes/CodingSites/CatalystMartie2019/level3/level3_5.in");
ofstream fout("/Users/adrianflorea/Codes/CodingSites/CatalystMartie2019/data.out");

double distanceCalculate(double x1, double y1, double x2, double y2)
{
    double x = x1 - x2; //calculating number to square in next step
    double y = y1 - y2;
    double dist;
    
    dist = pow(x, 2) + pow(y, 2);       //calculating Euclidean distance
    dist = sqrt(dist);
    
    return dist;
}

int main(int argc, const char * argv[]) {
    int x,y,sizex,sizey;
    fin>>sizex>>sizey;
    fin>>x>>y;
    vector<pair<int,int>> steps;
    int plusx = 1,plusy = 0,status = 0;
    steps.push_back(make_pair(x,y));
    string s;
    getline(fin,s);
    getline(fin,s);
    std::stringstream ss(s);
    std::istream_iterator<std::string> begin(ss);
    std::istream_iterator<std::string> end;
    std::vector<std::string> vstrings(begin, end);
    int index =0;
    for(int index=0;index<vstrings.size();index+=2) {
        string com=vstrings[index];
        int step=stoi(vstrings[index+1]);
        if(!com.compare("T")){
            status = (status+step)%4;
        } else {
            if(status == 0){
                plusx = 1;
                plusy = 0;
            }else if(status == 1){
                plusx = 0;
                plusy = 1;
            }else if(status == 2){
                plusx= -1;
                plusy=0;
            }else if(status == 3){
                plusx=0;
                plusy=-1;
            }
            for(int i=0;i<step;++i){
                x+=plusx;
                y+=plusy;
                steps.push_back(make_pair(x,y));
            }
        }
    }
    string speedStr;
    fin>>speedStr;
    float speed = stof(speedStr);
    int n;
    fin>>n;
    vector<int> ids;
    int totalSteps = steps.size();
    for(int i=0;i<n;++i){
        int readed;
        fin>>readed;
        ids.push_back(readed);
    }
    int q;
    fin>>q;
    for(int i=0;i<q;++i){
        int time,id;
        fin>>time>>id;
        int distanceTrav = floor((time-ids[id])*speed);
        //cout<<distanceTrav<<"\n";
        fout<<time<<" "<<id<<" "<<steps[distanceTrav].first<<" "<<steps[distanceTrav].second<<"\n";
    }
//    fout<<x<<" "<<y<<"\n";
    //F 1 /T 3/ F 2/ T 1 F 1 T 1 F 4 T 3 F 1 T 3 F 2 T 1 F 1
//    int i=0;
//    for(auto it: steps)
//        cout<<i++<<" "<<it.first<<" "<<it.second<<'\n';
    return 0;
}

