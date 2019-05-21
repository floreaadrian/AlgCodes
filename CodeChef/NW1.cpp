#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string s;
        int day, first;
        cin >> day >> s;
        if (s == "mon") first = 1;
        else if (s == "tues") first = 2;
        else if (s == "wed")first = 3;
        else if (s == "thurs")first = 4;
        else if (s == "fri")first = 5;
        else if (s == "sat")first = 6;
        else first = 7;
        int ma[8]={0};
        for(int j=0;j<day;++j)
        {
            ma[(first+j)%7]++;
        }
        for(int j=1;j<7;++j)
            cout<<ma[j]<<" ";
        cout<<ma[0];
        cout<<"\n";
    }

    return 0;
}