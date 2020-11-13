#include "std_lib_facilities.h"

class myVector {
    public:
        myVector(int s) {
            elem = new double[s];

            for(int i = 0; i < s; i++) {
                elem[i] = 0.0;
            }

            sz = s;
        }
        int size() const { return sz; };

        void put(int i, double val) {
            if (i > sz) {
                error("You can't go past the end of the vector!");
            }
            elem[i] = val;
        }

        double get(int i) {
            if (i > sz) {
                error("You can't go past the end of the vector!");
            }
            return elem[i];
        }
    private:
        int sz;
        double *elem;
};

int main() {
    myVector mv {200};  // Create a myVector with room for 200 doubles
    cout << "Vector size: " << mv.size() << "\n";
    
    mv.put(0, 159.35);
    mv.put(1, 490.2);
    mv.put(2, -352.2);

    cout << "Element at location 100: " << mv.get(100) << "\n";
}