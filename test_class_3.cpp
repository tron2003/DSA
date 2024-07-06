#include <iostream>
#include <string>

using namespace std;

class hero
{


public:
long long a;
    int b = 0;
    void operator()()
    
    {
        // int val = this->a;
        // int val2 = temp.a;
        cout << "Output difference "<<this->a<< endl;
    }
};


int main()
{

    hero obj1, obj2;
    obj1.a = 1212;
    obj1.b = 2;
    obj2.a = 2;
    obj2.b = 3;
    obj1 ();

    return 0;
}
