#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    vector<int> coll;

    for (int i = 0; i < 6; ++i) {
        coll.push_back(i);
    }

    for (size_t i = 0; i < coll.size(); ++i) {
        cout << coll[i] << " ";
    }
    cout << endl;

    copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
    cout << endl; 
    transform(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "), [](int i){return i;});
    cout << endl; 
}
