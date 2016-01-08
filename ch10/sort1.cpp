#include <algorithm>
#include <iostream>
#include <set>
#include <string>

using namespace std;

class Person {
    private:
        string fn;
        string ln;

    public:
        Person(string fn, string ln) :
            fn {fn},
            ln {ln} {}

        string firstname() const;
        string lastname() const;
};

int main(int argc, char *argv[]) {
    return 0;
}
