#include <iostream>
#include <iterator>
#include <list>
#include <algorithm>

using namespace std;

class Nth {
    private:
        int nth;
        int count;
    public:
        Nth(int n) : nth(n), count(0) {
        }
        bool operator()(int n) {
            return ++count == nth;
        }
};

void PRINT_ELEMENT(const list<int> &coll) {
    for (auto pos = coll.begin(); pos != coll.end(); ++pos) {
        cout << *pos << " ";
    }
    cout << endl;
}

int main() {
    list<int> coll {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    PRINT_ELEMENT(coll);

    list<int>::iterator pos;
    pos = remove_if(coll.begin(), coll.end(), Nth(3));
    PRINT_ELEMENT(coll);
    coll.erase(pos, coll.end());
    PRINT_ELEMENT(coll);
}
