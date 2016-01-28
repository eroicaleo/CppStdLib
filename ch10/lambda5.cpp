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
            [] (const Person& p) {
                p.print();
            });
    cout << endl;

    for_each(coll.begin(), coll.end(),
            [] (const Person& p) { 
                p.print2("Person: ");
            });
    cout << endl;

}
