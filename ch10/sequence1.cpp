#include <iostream>
#include <iterator>
#include <list>
#include <algorithm>

using namespace std;

class IntSequence {
    private:
        int value;
    public:
        IntSequence(int initialVal)
            : value(initialVal) {
        }
        int operator() () {
            return ++value;
        }
};

void PRINT_ELEMENT(const list<int> &coll) {
    for (auto pos = coll.begin(); pos != coll.end(); ++pos) {
        cout << *pos << " ";
    }
    cout << endl;
}

int main() {
    list<int> coll;
    generate_n(back_inserter(coll), 9, IntSequence(1));
    PRINT_ELEMENT(coll);

    generate(next(coll.begin()), prev(coll.end()), IntSequence(42));
    PRINT_ELEMENT(coll);

    IntSequence seq = IntSequence(1);

    coll = list<int>();
    generate_n(back_inserter(coll), 9, seq);
    PRINT_ELEMENT(coll);

    coll = list<int>();
    generate_n(back_inserter(coll), 9, seq);
    PRINT_ELEMENT(coll);

    return 0;
}
