#include <iostream>
#include <iterator>
#include <algorithm>

class IntSequence {
    private:
        int value;
    public:
        IntSequence(int initialVal)
            : value(initialVal) {
        }
        int operator() () {
            return ++value;
        }
}

int main() {
    list
}
