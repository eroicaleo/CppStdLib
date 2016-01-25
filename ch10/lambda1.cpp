#include <functional>
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;
using namespace std::placeholders;

int main() {
    auto plus10 = [](int i) {
                        return i+10;
                    };

    cout << "+10:    " << plus10(7) << endl;

    auto plus10times2 = [](int i) {
                            return (i+10)*2;
                        };
    cout << "+10*2:  " << plus10times2(7) << endl;

    auto pow3 = [] (int i) {
                    return i*i*i;
                };
    cout << "x*x*x:  " << pow3(7) << endl;

    auto inversDivide = [] (double d1, double d2) {
                            return d2/d1;
                        };
    cout << "invdiv: " << inversDivide(49, 7) << endl;

}
