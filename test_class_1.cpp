#include <iostream>
#include <string>

using namespace std;

class hero
{
private:
    int aa;
    char name;

public:
    // Default constructor
    hero() : aa(0), name('a') {}

    // Parameterized constructor
    hero(int aa, char name) : aa(aa), name(name) {}

    // Copy constructor
    hero(const hero &temp)
    {
        this->aa = temp.aa;
        this->name = temp.name;
    }

    // Method to print hero details
    void print()
    {
        cout << "Hero aa: " << this->aa << endl;
        cout << "Hero name: " << this->name << endl;
    }

    // // Destructor
    // ~hero()
    // {
    //     cout << "Destructor called" << endl;
    // }
};

class child :private hero
{
    public:
        int color = 2;

  
        // Using base class constructors
        child() : hero() {}
        child(int aa, char name) : hero(aa, name) {}

        // Overriding print method
        int colorreturn(){
            return this->color;
        }

        void print()
        {
            cout << "Child aa: " << aa << endl;
            cout << "Child name: " << name << endl;
    }
};

int main()
{
    child tron;

    // tron.print();

    child anotherTron(5, 'b');
    cout << anotherTron.color<< endl;
    // anotherTron.print();

    return 0;
}
