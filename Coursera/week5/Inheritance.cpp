#include <bits/stdc++.h>

using namespace std;

class Animal {
public:
    const string Name;

    Animal(string x) : Name(x)
    {

    }
};


class Dog : public Animal {
public:

    Dog(string x) : Animal(x)
    {
    }

    void Bark() {
        cout << Name << " barks: woof!" << endl;
    }
};
