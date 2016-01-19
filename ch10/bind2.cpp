#include <functional>
#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <string>
#include <memory>

using namespace std;
using namespace std::placeholders;

class Person {
    private:
        string name;
    public:
        Person(const string& n) : name(n) {
        }
        void print() const {
            cout << name << endl;
        }
        void print2(const string &prefix) const {
            cout << prefix << name << endl;
        }
        void setName(const string &n) {
            name = n;
        }
};

int main() {
    vector<Person> coll
        = { Person("Tick"), Person("Trick"), Person("Track") };

    for_each(coll.begin(), coll.end(),
            bind(&Person::print, _1));
    cout << endl;

    for_each(coll.begin(), coll.end(),
            bind(&Person::print2, _1, "Person: "));
    cout << endl;

    bind(&Person::print2, _1, "This is: ")(Person("nico"));

    shared_ptr<Person> p1{new Person{"Yang"}};
    shared_ptr<Person> p2{new Person{"Yukan"}};

    vector<shared_ptr<Person>> sp;
    sp.push_back(p1);
    sp.push_back(p2);

    for_each(sp.begin(), sp.end(), bind(&Person::print, _1));

    for_each(coll.begin(), coll.end(), bind(&Person::setName, _1, "Paul"));
    for_each(coll.begin(), coll.end(),
            bind(&Person::print, _1));
    cout << endl;

}
