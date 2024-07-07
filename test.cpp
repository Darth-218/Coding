#include <iostream>
using namespace std;

class Array {
private:
  int size;
  int length;
  int *items;

public:
  Array(int arrsize) // constructor (a specially defined method in a C++ class
                     // that is automatically called when an instance of that
                     // class is created, has same name as the class)
  {
    size = arrsize;
    length = 0;
    items = new int[arrsize];
  }

  void Fill() // method used to fill the array with items
  {
    int no_of_items;
    cout << "Please enter number of items: \n";
    cin >> no_of_items;
    if (no_of_items > size) {
      cout << "Error: number of items exceeds array size.";
      return; // ends the method
    } else
      for (int i = 0; i < no_of_items; i++) {
        cout << "please enter item number " << i << endl;
        cin >> items[i];
      }
  }
};
