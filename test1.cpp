#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int func(int a, int b)

{
if((a&(1<<b-1))!=0){

    return 1;
}
else{
    return 0;
}

}


int main()
{
    cout <<func(7, 4)<< endl;

    return 0;
}
