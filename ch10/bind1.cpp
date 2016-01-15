#include <functional>
#include <iostream>

using namespace std;

int main() {
    auto plus10 = bind(plus<int>(), placeholders::_1, 10);
    cout << "+10: " << plus10(7) << endl;
}
