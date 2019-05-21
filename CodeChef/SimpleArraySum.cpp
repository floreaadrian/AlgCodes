#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n,sum=0,v;
    cin >> v;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
       if(arr[arr_i]==v)
        {cout<<arr_i;
        return 0;}
    }
    //cout<<sum;
    return 0;
}
