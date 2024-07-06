#include <iostream>
#include <string>

using namespace std;

class hero
{
private:
    int aa;

public:
    void speak()
    {
        cout << "speaking11" << endl;
    }
};
class animal : public hero
{

public:
    void speak()
    {
        cout << "barking" << endl;
    }
};

int main()
{
    animal tron;

    tron.hero::speak();

    // anotherTron.print();

    return 0;
}
