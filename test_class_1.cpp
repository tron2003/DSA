#include <iostream>
#include <string>

using namespace std;

class hero
{
private:
    int aa = 0;
    char name = 'a';

public:
    
    hero(int aa,char name)
    {

        this->aa = aa;
        this->name =name;
    }
    hero(hero& temp)
    {
 
        this->aa = temp.aa;
        this->name = temp.name;
    }
    void print()
    {
  
        cout << this->aa << endl;
        cout << this->name << endl;
    }

    
};

int main()
{
    hero neon(12, 'k');
    neon.print();

    hero neo(neon);
    neo.print();


    return 0;
}
