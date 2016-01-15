#include <functional>
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;
using namespace std::placeholders;

int main() {
    auto plus10 = bind(plus<int>(), placeholders::_1, 10);
    cout << "+10: " << plus10(7) << endl;
    cout << bind(plus<int>(), _1, 10)(32) << endl;

    list<int> coll = {1, 2, 3, 4, 5};
    transform(coll.begin(), coll.end(), coll.begin(), bind(plus<int>(), _1, 10));

    for (auto pos = coll.begin(); pos != coll.end(); ++pos) {
        cout << *pos << " ";
    }
    cout << endl;

    coll = {41, 42, 43, 44, 45};
    auto pos = find_if(coll.begin(), coll.end(), bind(greater<int>(), _1, 42));
    cout << *pos << endl;

    auto plus10times2 = bind(multiplies<int>(), 
                                bind(plus<int>(), _1, 10),
                                2);
    cout << "+10*2: " << plus10times2(7) << endl;

    auto pow3 = bind(multiplies<int>(),
                    bind(multiplies<int>(),
                        _1,
                        _1),
                    _1);
    cout << "x^3: " << pow3(7) << endl;

    auto inversDivide = bind(divides<double>(),
                            _2,
                            _1);
    cout << "invdiv:" << inversDivide(49, 7) << endl;
}
