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
    IntSequence seq(1);

    generate_n<back_insert_iterator<list<int>>, int, IntSequence&> (back_inserter(coll), 4, seq);
    PRINT_ELEMENT(coll);

    generate_n(back_inserter(coll), 4, IntSequence(42));
    PRINT_ELEMENT(coll);

    generate_n(back_inserter(coll), 4, seq);
    PRINT_ELEMENT(coll);

    generate_n(back_inserter(coll), 4, seq);
    PRINT_ELEMENT(coll);

    return 0;
}
