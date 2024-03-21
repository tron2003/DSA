#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int func(string str,int n){

    int i =0;
    int j =n-1;
    if(n<=0){
        return -1;
    }
    if(n==1){
        return 1;
    }
    if(n>=2){

        while(i<=j){

            if(str[i]==str[j]){

                i++;
                j--;
            }
            else{
                return 0;
            }
        }
    }
    return 1;
}
int main()
{
    string str= "121a";
    cout<<func(str,str.length());

    return 0;
}
