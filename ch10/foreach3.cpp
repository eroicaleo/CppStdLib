#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MeanValue {
    private:
        long num;
        long sum;
    public:
        MeanValue() : num(0), sum(0) {
        }
        void operator()(int elem) {
            ++num;
            sum += elem;
        }
        double value() {
            return static_cast<double>(sum) / static_cast<double>(num); 
        }
};

int main() {
    vector<int> coll = {1, 2, 3, 4, 5, 6, 7, 8};
    MeanValue mv = for_each(coll.begin(), coll.end(), MeanValue());
    cout << "Mean value: " << mv.value() << endl;

    return 0;
}
