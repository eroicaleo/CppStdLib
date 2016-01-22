#include <functional>
#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <string>
#include <memory>
#include <map>

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

    cout << "mem_fn" << endl;
    for_each(sp.begin(), sp.end(), mem_fn(&Person::print));

    cout << "mem_fn with additional parameter" << endl;
    for_each(sp.begin(), sp.end(), bind(mem_fn(&Person::print2), _1, "Melon: "));

    map<string, int> mapColl;
    mapColl.insert(pair<string, int>("Yang", 1));
    mapColl.insert(pair<string, int>("Yukan", 2));
    mapColl.insert(pair<string, int>("Melon", 3));
    int sum = accumulate(mapColl.begin(), mapColl.end(),
                        0,
                        bind(plus<int>(),
                            _1,
                            bind(&map<string, int>::value_type::second,
                                _2)
                            )
            );
    cout << "sum is: " << sum << endl;
}
