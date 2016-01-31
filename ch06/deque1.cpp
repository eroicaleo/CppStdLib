#include <deque>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
    deque<float> coll;

    for (int i = 0; i <= 6; ++i) {
        coll.push_front(i*1.1);
    }

    copy(coll.begin(), coll.end(), ostream_iterator<float>(cout, " "));
    cout << endl;
}
