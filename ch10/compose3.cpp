#include <iostream>
#include <algorithm>
#include <functional>
#include <locale>
#include <string>

using namespace std;
using namespace std::placeholders;

char myToupper(char c) {
    locale loc;
    return use_facet<ctype<char> >(loc).toupper(c);
}

void incr(int &i) {
    ++i;
}

int main() {
    string s("Internationalization");
    string sub("Nation");

    string::iterator pos;
    pos = search(s.begin(), s.end(),
                sub.begin(), sub.end(),
                bind(equal_to<char>(),
                    bind(myToupper, _1),
                    bind(myToupper, _2)));

    if (pos != s.end()) {
        cout << "\"" << sub << "\" is part of \"" << s
            << endl;
    }

    int i = 0;
    bind(incr, i)();
    cout << i << endl;
    bind(incr, ref(i))();
    cout << i << endl;

}
