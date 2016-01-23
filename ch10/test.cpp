#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <vector>
#include <iterator>

using namespace std;

class Base {
private:
    int b;

public:
    Base(int b) : b {b} {
    }

    virtual void print(ostream& os) const {
        os << "This is Base: " << b << endl;
    }

    friend ostream& operator<<(ostream &os, const Base &b) {
        b.print(os);

        return os;
    }
};

class Derived : public Base {
private:
    int d;

public:
    Derived(int b, int d) : Base{b}, d {d} {
    }

    virtual void print(ostream& os) const {
        os << "This is Derived: " << d << endl;
    }

    friend ostream& operator<<(ostream &os, const Derived &d) {
        d.print(os);

        return os;
    }

};

typedef shared_ptr<Base> BasePtr;
typedef shared_ptr<Derived> DerivedPtr;

ostream& operator<<(ostream &os, const BasePtr &pb) {
    pb->print(os);

    return os;
}

int main() {
    BasePtr pb {new Base{23}};    
    DerivedPtr pd {new Derived{23, 29}};

    vector<BasePtr> coll;
    coll.push_back(pb);
    coll.push_back(pd);

    copy(coll.begin(), coll.end(), ostream_iterator<BasePtr>(cout));
    for_each(coll.begin(), coll.end(), bind(&Base::print, placeholders::_1, ref(cout)));
}
