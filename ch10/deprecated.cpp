#include <functional>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using namespace std::placeholders;

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

}
