#include <iostream>
#include <iterator>
#include <list>
#include <algorithm>

using namespace std;

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
    pos = remove_if(coll.begin(), coll.end(),
                    [count](int){
                        ++count == 3;
                    });
    PRINT_ELEMENT(coll);
    coll.erase(pos, coll.end());
    PRINT_ELEMENT(coll);
}
