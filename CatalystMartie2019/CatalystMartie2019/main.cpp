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

//ifstream fin("/Users/adrianflorea/Codes/CodingSites/CatalystMartie2019/level4/level4_1.in");
ifstream fin("/Users/adrianflorea/Codes/CodingSites/CatalystMartie2019/data.in");
ofstream fout("/Users/adrianflorea/Codes/CodingSites/CatalystMartie2019/data.out");

bool checkIfRange(float x1,float y1, float x2, float y2, float radius){
    double x = x2 - x1; //calculating number to square in next step
    double y = y2 - y1;
    return sqrt(pow(x, 2) + pow(y, 2))<radius;
}

bool mysort(pair<int,int> a,pair<int,int> b){
    return a.second<b.second;
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
    string speedStr, healthStr;
    fin>>healthStr>>speedStr;
    float speed = stof(speedStr);
    float health = stof(healthStr);
    int n;
    fin>>n;
    //alienId, spawnTime
    vector<int> spawnTime;
    for(int i=0;i<n;++i){
        int readed;
        fin>>readed;
        spawnTime.push_back(readed);
    }
//    sort(spawnTime.begin(),spawnTime.end(),mysort);
    string damageStr, radiusStr;
    fin>>damageStr>>radiusStr;
    float damage = stof(damageStr);
    float radius = stof(radiusStr);
    int t;
    fin>>t;
    //lockedId, x,y
    vector<pair<int,pair<int,int>>> towers;
    //pair<id,health>, spawnTime
    vector<pair<pair<int,int>,int>> aliveAliens;
    for(int tt=0;tt<t;++tt){
        int xt,yt;
        fin>>xt>>yt;
        towers.push_back(make_pair(-1,make_pair(xt,yt)));
    }
//    for(auto it: spawnTime)
//        cout<<it.first<<" "<<it.second<<"\n";
    int tick=0;
    while(true) {
        for(auto it: aliveAliens){
            int distanceTrav = floor((tick-it.second)*speed);
            if(distanceTrav == steps.size()-1){
                cout<<tick<<"\nLOSE\n";
                return 0;
            }
        }
        vector<int> toDelete;
        for(int spawnIndex=0;spawnIndex<spawnTime.size();spawnIndex++){
            if(spawnTime[spawnIndex] == tick){
                aliveAliens.push_back(make_pair(make_pair(spawnIndex,health),tick));
            }
        }
        
        for(int ind = 0;ind<towers.size();++ind){
            for(int i = 0; i < aliveAliens.size();++i){
                if(towers[ind].first == -1) {
                    int distanceTrav = floor((tick-aliveAliens[i].second)*speed);
                    int alx = steps[distanceTrav].first;
                    int aly = steps[distanceTrav].second;
                        if(checkIfRange(towers[ind].second.first, towers[ind].second.second, alx, aly, radius) && aliveAliens[i].first.second>0){
                            if(towers[ind].first<aliveAliens[i].first.first)
                                towers[ind].first = aliveAliens[i].first.first;
                        }
                }
            }
            if(tick!=0)
            for(int i = 0; i < aliveAliens.size();++i){
                int distanceTrav = floor((tick-aliveAliens[i].second)*speed);
                int alx = steps[distanceTrav].first;
                int aly = steps[distanceTrav].second;
                if(aliveAliens[i].first.first == towers[ind].first && checkIfRange(towers[ind].second.first,towers[ind].second.second,alx,aly,radius
                                                                                   )){
                    aliveAliens[i].first.second -= damage;
                }
                if(aliveAliens[i].first.second <= 0){
                    toDelete.push_back(i);
                    towers[ind].first = -1;
                }
                if(!checkIfRange(towers[ind].second.first,towers[ind].second.second,alx,aly,radius
                                 )){
                    towers[ind].first = -1;
                }
            }
            
        }
        for(int i=0;i<toDelete.size();++i){
            if(aliveAliens.size()>0)
                aliveAliens.erase(aliveAliens.begin()+toDelete[i]-i);
        }
        toDelete.clear();
        bool re = true;
        for(auto it: spawnTime){
            if(it > tick)
                re = false;
        }
        if(aliveAliens.size() == 0 && re){
            cout<<tick-1<<"\nWIN\n";
            return 0;
        }
        tick++;
    }
    return 0;
}
