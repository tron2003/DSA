#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void helper(string str,string temp,int i ,vector<string>&res){
                   

 if(i>=str.size()){
    if(temp.size()>0){
        
    }
     res.push_back(temp);
     return;
 }

 helper(str,temp,i+1,res);
 temp += str[i];
 helper(str, temp,i+1,res );
}


void func (string str){
    vector<string> res;
    string temp = " ";
    int i = 0;
    helper(str,temp,i, res);
    for(auto x:res){
        cout << x <<endl;
        // cout << endl;
    }
}

int main(){
    string str = "abcd";
     func(str);
    return 0;
}