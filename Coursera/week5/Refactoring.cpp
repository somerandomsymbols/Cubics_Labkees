#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person
{
public:
    Person(const string &name) : Name(name) {}

    virtual string Type() const
    {
        return "Person";
    }

    ostream& Log() const
    {
        cout << Type() << ": " << Name;
        return cout;
    }

    virtual void Walk(const string &destination) const
    {
        Log() << " walks to: " << destination << endl;
    }

public:
    const string Name;
};

class Student : public Person{
public:
    Student(const string &name, const string &favouriteSong) : Person(name), FavouriteSong(favouriteSong) {}

    void Learn() const
    {
        Log() << " learns" << endl;
    }

    void Walk(const string &destination) const
    {
        Log() << " walks to: " << destination << endl;
        SingSong();
    }

    void SingSong() const
    {
        Log() << " sings a song: " << FavouriteSong << endl;
    }

    string Type() const
    {
        return "Student";
    }

public:
    const string FavouriteSong;
};

class Teacher : public Person{
public:
    Teacher(const string &name, const string subject) : Person(name), Subject(subject) {}

    void Teach() const
    {
        Log() << " teaches: " << Subject << endl;
    }

    string Type() const
    {
        return "Teacher";
    }

public:
    const string Subject;
};

class Policeman : public Person {
public:
    Policeman(const string &name) : Person(name) {}

    void Check(const Person &t) const
    {
        Log() << " checks " << t.Type() << ". " <<  t.Type() << "'s name is: " << t.Name << endl;
    }

    string Type() const
    {
        return "Policeman";
    }
};

void VisitPlaces(Person &t, const vector<string> &places)
{
    for (auto p : places)
    {
        t.Walk(p);
    }
}


int main()
{
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");
    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}

