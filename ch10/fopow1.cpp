#include <functional>
#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <string>
#include <memory>
#include <map>
#include <iterator>

#include "fopow.hpp"

using namespace std;
using namespace std::placeholders;

int main() {
    vector<int> coll = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    transform(coll.begin(), coll.end(),
            ostream_iterator<float>(cout, " "),
            bind(fopow<float, int>(), 3, _1)
            );
    cout << endl;

    transform(coll.begin(), coll.end(),
            ostream_iterator<float>(cout, " "),
            bind(fopow<float, int>(), _1, 3)
            );
    cout << endl;

}
