#include "std_lib_facilities.h"

template <typename T>
class myVector {
 public:
  myVector<T>() {
    elem = new T[2];
    sz = 0;
    capacity = 2;
  }
  myVector(int s);

  void push_back(T val);

  // Copy constructor
  myVector(const myVector<T> &a);

  // Move constructor
  myVector(myVector<T> &&a);

  // Copy assignment operator
  myVector<T> &operator=(const myVector<T> &a);

  // Move assignment operator
  myVector<T> &operator=(myVector<T> &&a);

  // Subscript operator overload
  T &operator[](int i) { return elem[i]; }

  int size() const { return sz; };

  ~myVector() { delete[] elem; }

 private:
  int sz;       // The number of elements placed in the vector
  int capacity; // The number of elements the vector can hold
  T *elem;
};

template <typename T>
myVector<T>::myVector(int s) {
  elem = new T[s];

  sz = s;
  capacity = s;
}

template <typename T>
void myVector<T>::push_back(T val) {
  if (sz < capacity){
    cout << "Inserting " << val << " without resizing\n";
    elem[sz] = val;
    sz += 1;
    return;
  }

  cout << "Inserting " << val << ", resizing from " << capacity << " to " << capacity * 2 << "\n";

  T *temp = new T[capacity*2];
  
  for (int j = 0; j < capacity; j++) {
    temp[j] = elem[j];
  }

  delete[] elem;
  elem = temp;

  elem[sz] = val;
  sz += 1;
  capacity *= 2;
}

// Copy constructor: Copy elements from `a` into a new myVector
template <typename T>
myVector<T>::myVector(const myVector<T> &a) {
  cout << "Copy constructor invoked\n";

  elem = new T[a.sz];
  sz = a.sz;

  for (int i = 0; i < a.sz; i++) {
    elem[i] = a.elem[i];
  }
}

// Move constructor: Move elements from `a` into a new myVector
template <typename T>
myVector<T>::myVector(myVector<T> &&a) {
  cout << "Move constructor invoked\n";

  elem = a.elem;
  a.elem = nullptr;
  sz = a.sz;
}

// Copy assignment operator: Copy elements from `a`, overwriting an existing myVector
template <typename T>
myVector<T> &myVector<T>::operator=(const myVector<T> &a) {
  cout << "Copy assignment operator invoked\n";

  delete[] elem;

  elem = new T[a.sz];
  sz = a.sz;

  for (int i = 0; i < a.sz; i++) {
    elem[i] = a.elem[i];
  }

  return *this;
}

// Move assignment operator: Move elements from `a`, overwriting an existing myVector
template <typename T>
myVector<T> &myVector<T>::operator=(myVector<T> &&a) {
  cout << "Move assignment operator invoked\n";

  delete[] elem;

  elem = a.elem;
  a.elem = nullptr;

  sz = a.sz;

  return *this;
}

// Create a new vector filled with some numbers
myVector<double> getFilledVector() {
  myVector<double> v;

  v.push_back(1.0);
  v.push_back(2.0);
  v.push_back(3.0);

  return v;
}

int main() {
  myVector<double> mv;
  
  cout << "Empty vector size: " << mv.size() << "\n";

  mv.push_back(159.35);
  mv.push_back(490.2);
  mv.push_back(-352.2);

  cout << "mv element at location 0: " << mv[0] << "\n\n";

  cout << "Copying into new myVector\n";
  myVector<double> copyConstructorVector = mv;
  copyConstructorVector[0] = 99.9;

  cout << "copyConstructorVector element at location 0: " << copyConstructorVector[0] << "\n\n";

  cout << "Copying into existing myVector\n";
  myVector<double> copyAssignmentVector;
  copyAssignmentVector = mv;
  cout << "copyAssignmentVector element at location 0: " << copyAssignmentVector[0] << "\n\n";

  cout << "Move into new vector\n";
  myVector<double> moveConstructorVector = getFilledVector();
  cout << "moveConstructorVector element at location 0: " << moveConstructorVector[0] << "\n\n";
  myVector<double> m;

    cout << "Move into existing vector: Should invoke copy constructor but probably won't\n";
  myVector<double> moveAssignmentVector;
  moveAssignmentVector = getFilledVector();
  cout << "moveAssignmentVector element at location 0: " << moveAssignmentVector[0] << "\n\n";

}