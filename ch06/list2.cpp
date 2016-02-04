#include <list>
#include <string>
#include <iostream>

using namespace std;

int main() {
    list<char> coll;

    for (char c = 'a'; c <= 'z'; ++c) {
        coll.push_back(c);
    }

    while (!coll.empty()) {
        cout << coll.front() << " ";
        coll.pop_front();
    }
    cout << endl;

}
