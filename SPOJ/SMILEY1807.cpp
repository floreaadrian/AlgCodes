#include<iostream>
#include<string.h>
using namespace std;

int main(){
    
    char s[1000009];
    cin>>s;
    int n = strlen(s);
    int arr[4];
    memset(arr,0,sizeof(arr));
    if(n<=3){
        cout<<0<<endl;
        return 0;
    }
    if(s[0] == '1'){
        arr[0] = 1;
    }
    for(int i = 1 ; i < n ; i++){
        if(s[i] == '1'){
            arr[0] = arr[0] + 1;
        }
        else if(s[i] == '8'){
            if(arr[0] > 0 || arr[1] > 0){
                arr[1] = max(arr[0] , arr[1]) + 1;
            }
        } else if(s[i] == '0'){
            if(arr[1] > 0 || arr[2] > 0){
                arr[2] = max(arr[1] , arr[2]) + 1;
            }
        } else if(s[i] == '7'){
            if(arr[2] > 0 || arr[3] > 0){
                arr[3] = max(arr[2] , arr[3])+1;
            }
        }
    }
    cout<<arr[3]<<endl;
    return 0;
}
