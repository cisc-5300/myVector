#include "std_lib_facilities.h"

class myVector {
 public:
  myVector(int s);

  // Copy constructor
  myVector(const myVector &a);

  // Move constructor
  myVector(myVector &&a);

  // Copy assignment operator
  myVector &operator=(const myVector &a);

  // Move assignment operator
  myVector &operator=(myVector &&a);

  void put(int i, double val);
  double get(int i);

  int size() const { return sz; };

  ~myVector() { delete[] elem; }

 private:
  int sz;
  double *elem;
};

myVector::myVector(int s) {
  elem = new double[s];

  for (int i = 0; i < s; i++) {
    elem[i] = 0.0;
  }

  sz = s;
}

// Copy constructor: Copy elements from `a` into a new myVector
myVector::myVector(const myVector &a) {
  cout << "Copy constructor invoked\n";

  elem = new double[a.sz];
  sz = a.sz;

  for (int i = 0; i < a.sz; i++) {
    elem[i] = a.elem[i];
  }
}

// Move constructor: Move elements from `a` into a new myVector
myVector::myVector(myVector &&a) {
  cout << "Move constructor invoked\n";

  elem = a.elem;
  a.elem = nullptr;
  sz = a.sz;
}

// Copy assignment operator: Copy elements from `a`, overwriting an existing myVector
myVector &myVector::operator=(const myVector &a) {
  cout << "Copy assignment operator invoked\n";

  delete[] elem;

  elem = new double[a.sz];
  sz = a.sz;

  for (int i = 0; i < a.sz; i++) {
    elem[i] = a.elem[i];
  }

  return *this;
}

// Move assignment operator: Move elements from `a`, overwriting an existing myVector
myVector &myVector::operator=(myVector &&a) {
  cout << "Move assignment operator invoked\n";

  delete[] elem;

  elem = a.elem;
  a.elem = nullptr;

  sz = a.sz;

  return *this;
}

// Put a value `val` into position `i`
void myVector::put(int i, double val) {
  if (i > sz) {
    error("You can't go past the end of the vector!");
  }
  elem[i] = val;
}

// Get a value at position `i`
double myVector::get(int i) {
  if (i > sz) {
    error("You can't go past the end of the vector!");
  }
  return elem[i];
}

// Create a new vector filled with some numbers
myVector getFilledVector() {
  myVector v{100};
  v.put(0, 1.0);
  v.put(1, 2.0);
  v.put(2, 3.0);

  return v;
}

int main() {
  myVector mv{200};  // Create a myVector with room for 200 doubles
  cout << "Vector size: " << mv.size() << "\n";

  mv.put(0, 159.35);
  mv.put(1, 490.2);
  mv.put(2, -352.2);

  cout << "mv element at location 0: " << mv.get(0) << "\n\n";

  cout << "Copying into new myVector\n";
  myVector copyConstructorVector = mv;
  copyConstructorVector.put(0, 99.9);

  cout << "copyConstructorVector element at location 0: " << copyConstructorVector.get(0) << "\n\n";

  cout << "Copying into existing myVector\n";
  myVector copyAssignmentVector{100};
  copyAssignmentVector = mv;
  cout << "copyAssignmentVector element at location 0: " << copyAssignmentVector.get(0) << "\n\n";

  cout << "Move into new vector\n";
  myVector moveConstructorVector = getFilledVector();
  cout << "moveConstructorVector element at location 0: " << moveConstructorVector.get(0) << "\n\n";

    cout << "Move into existing vector\n";
  myVector moveAssignmentVector{100};
  moveAssignmentVector = getFilledVector();
  cout << "moveAssignmentVector element at location 0: " << moveAssignmentVector.get(0) << "\n\n";
}