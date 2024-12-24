/*
    Write a cpp code to convert a string input to integer array.
    Like inp = "6,7,8,9,10"
    out = [6,7,8,9,10]
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    cout<<"Enter the String Input"<<endl;
    string str;
    vector<int> arr;
    getline(cin, str);

    for(int i = 0;i<str.size();i++){
        // if(str[i] == ','){
        //     continue;
        // }
        if(isdigit(str[i])){
            int digit = str[i] - '0';
            arr.push_back(digit);
        }
        cout<<str<<endl;
    }

    for(auto num:arr){
        cout<<num<<' ';
    }

    
    
    return 0;

}