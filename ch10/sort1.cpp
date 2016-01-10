#include <algorithm>
#include <iostream>
#include <set>
#include <string>

using namespace std;

class Person {
    private:
        string fn;
        string ln;

    public:
        Person(string fn, string ln) :
            fn {fn},
            ln {ln} {}

        string firstname() const;
        string lastname() const;
};

string Person::firstname() const {
    return fn;
}

string Person::lastname() const {
    return ln;
}

ostream& operator<<(ostream& os, const Person& p) {
    os << p.lastname() << ", " <<  p.firstname();
    return os;
}

class PersonSortCriterion {
    public:
    bool operator()(const Person& p1, const Person& p2) const {
        return p1.lastname() < p2.lastname() || (
                p1.lastname() == p2.lastname() &&
                p1.firstname() < p2.firstname());
    }
};

int main(int argc, char *argv[]) {

    Person p1("Yang", "Ge");
    Person p2("Yukan", "Zhang");
    Person p3("Shannon", "Ge");
    cout << p1 << endl;

    set<Person, PersonSortCriterion> col;
    col.insert(p1);
    col.insert(p2);
    col.insert(p3);
    for (auto pos = col.begin(); pos != col.end(); ++pos) {
        cout << *pos << endl;
    }
    return 0;
}
