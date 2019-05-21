//
//  main.cpp
//  GoogleHashCode
//
//  Created by Adrian-Paul Florea on 2/28/19.
//  Copyright © 2019 Adrian-Paul Florea. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <fstream>
#include <map>

using namespace std;

ifstream fin("a_example.txt");
ofstream fout("data.out");

int numberOfSame(vector<string> a, vector<string> b){
    int contor=0;
    for(auto inA: a){
        for(auto inB: b){
            if(inA==inB)
                contor++;
        }
    }
    return contor;
}

int mini(int a,int b){
    if(a>b) return b;
    return a;
}

int Interes(vector<string> a,vector<string> b){
    int com = numberOfSame(a, b);
    int left = a.size() - com;
    int right = b.size() - com;
    int minimu = mini(com, mini(left,right));
    return minimu;
}

bool mysort(pair<int,vector<string>> a,pair<int,vector<string>> b){
    return a.second.size()>b.second.size();
}

bool sizeSort(vector<pair<char,int>> a, vector<pair<char,int>> b){
    return a.size()>b.size();
}


int main(int argc, const char * argv[]) {
    long n;
    fin>>n;
    vector<pair<int,vector<string>>> verticale;
//    vector<pair<int,vector<string>>> orizontale;
    bool retine[90001] = {false};
    map<string,vector<pair<char,int>>> cuvinte;
    vector<vector<pair<char,int>>> retineCuv;
    for(int tt=0;tt<n;++tt){
        char a;
        fin>>a;
        long t;
        fin>>t;
//        vector<string> temp;
//        if(a == 'V')
            for(int i=0;i<t;++i){
                string toRead;
                fin>>toRead;
                cuvinte[toRead].push_back(make_pair('V',tt));
//                temp.push_back(toRead);
            }
//        else
//            for(int i=0;i<t;++i){
//                string toRead;
//                fin>>toRead;
//                cuvinteO[toRead].push_back(make_pair('O',tt));
//            }
//        if(a == 'V')
//            verticale.push_back(make_pair(tt,temp));
////        else
////            orizontale.push_back(make_pair(tt,temp));
    }
    vector<int> notUsed;
    for ( const auto &myPair : cuvinte )
        retineCuv.push_back(myPair.second);
    sort(retineCuv.begin(),retineCuv.end(),sizeSort);
//    fout<<n-verticalSize<<"\n";
    bool found = false;
    int remember = -1;
    int contor = 0;
    vector<pair<int,int>> toPrint;
    for(auto vectO: retineCuv)
        for(auto el: vectO){
            if(el.first=='O'){
                if(!retine[el.second]){
                    toPrint.push_back(make_pair(el.second,-1));
                    contor++;
                    retine[el.second] = true;
                }
            }
            if(el.first=='V'){
                if(found){
                    if(!retine[el.second] && !retine[remember]){
                        toPrint.push_back(make_pair(remember,el.second));

                        remember = -1;
                        found = false;
                        retine[el.second] = true;
                        retine[remember] = true;
                        contor++;
                        
                    }
                }
                else{
                    if(!retine[el.second]){
                        remember = el.second;
                        found = true;
                    }
                }
            }
            
        }
    fout<<toPrint.size()<<"\n";
    for(auto it: toPrint){
        if(it.second==-1)
            fout<<it.first<<"\n";
        else fout<<it.first<<" "<<it.second<<"\n";
    }
//    size_t orizontalSize = orizontale.size();
//    sort(orizontale.begin(),orizontale.end(),mysort);
//    sort(verticale.begin(),verticale.end(),mysort);
//
//    if(orizontalSize>verticalSize){
//        for(int i=0;i<verticalSize;++i)
//            fout<<orizontale[i].first<<"\n"<<verticale[i*2].first<<" "<<verticale[i*2+1].first<<"\n";
//        for(size_t i=verticalSize;i<orizontalSize;++i)
//            fout<<orizontale[i].first<<"\n";
//    }else{
//        for(int i=0;i<orizontalSize;++i)
//            fout<<orizontale[i].first<<"\n"<<verticale[i*2].first<<" "<<verticale[i*2+1].first<<"\n";
//        for(size_t i=orizontalSize;i<verticalSize;i+=2)
//            fout<<verticale[i].first<<" "<<verticale[i+1].first<<"\n";
//    }
//    if(orizontalSize%2 == 1)
//        fout<<orizontale[orizontalSize/2+1].first<<"\n";
//    for(int i=0;i<orizontalSize/2;++i)
//        fout<<orizontale[orizontalSize/2-i].first<<"\n"<<orizontale[orizontalSize/2+i].first<<"\n";
////    for(int i=0;i<verticalSize/2;i++)
////        fout<<verticale[i*2].first<<" "<<verticale[verticalSize-i*2+1].first<<"\n";
////    for(int i=0;i<orizontalSize;++i)
////        fout<<orizontale[i].first<<"\n";
    for(int i=0;i<verticale.size();i+=2)
        fout<<verticale[i].first<<" "<<verticale[i+1].first<<"\n";
    return 0;
}
