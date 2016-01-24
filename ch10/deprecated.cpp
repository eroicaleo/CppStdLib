#include <functional>
#include <iostream>
#include <algorithm>
#include <vector>

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
    vector<int> coll = {1, 3, 5, 7, 9, 10, 43};

    auto pos = find_if(coll.begin(), coll.end(), bind2nd(greater<int>(), 42));
    cout << *pos << endl;
    pos = find_if(coll.begin(), coll.end(), bind1st(greater<int>(), 42));
    cout << *pos << endl;

    pos = find_if(coll.begin(), coll.end(), not1(bind2nd(modulus<int>(), 2)));
    cout << *pos << endl;

    // C++11
    pos = find_if(coll.begin(), coll.end(),
                    bind(
                        logical_not<bool>(),
                        bind(modulus<int>(), _1, 2)
                        ));
    cout << *pos << endl;

    // mem_fun_ref
    cout << "mem_fun_ref example:" << endl;

    vector<Person> coll1
        = { Person("Tick"), Person("Trick"), Person("Track") };

    for_each(coll1.begin(), coll1.end(), mem_fun_ref(&Person::print));
    // for_each(coll1.begin(), coll1.end(), mem_fun_ref(&Person::print2));
    // bind1st(mem_fun_ref(&Person::print2), *coll1.begin())("Person: ");
    // bind2nd(mem_fun_ref(&Person::print2), "Person: ")(*coll1.begin());

    // mem_fun
    cout << "mem_fun example:" << endl;
    Person* p1 = new Person{"Yang"};
    Person* p2 = new Person{"Yukan"};

    vector<Person *> coll2 {p1, p2};

    for_each(coll2.begin(), coll2.end(), mem_fun(&Person::print));
    mem_fun(&Person::print)(*coll2.begin());
    mem_fun(&Person::print2)(*coll2.begin(), "Person: ");
    bind2nd(mem_fun(&Person::print2), "Person: ")(*coll2.begin());
    // bind1st(mem_fun(&Person::print2), *coll2.begin())("Person: ");
    // bind1st(mem_fun(&Person::print2), *coll2.begin())("Person: ");

}
