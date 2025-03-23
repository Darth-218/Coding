#include <iostream>
#include <limits>
#include <list>
#include <string>
#include <vector>
using namespace std;

class Student;
class StudentNode;
class EnrollmentHistory;
class StudentList;

// Node for Doubly Linked List (Enrollment History)
class Node {
private:
  string courseName;
  Node *next = nullptr;
  Node *prev = nullptr;

public:
  Node(string course) : courseName(course) {}

  string getCourseName() { return courseName; }
  void setCourseName(string course) { courseName = course; }

  Node *getNext() { return next; }
  void setNext(Node *nextNode) { next = nextNode; }

  Node *getPrev() { return prev; }
  void setPrev(Node *prevNode) { prev = prevNode; }
};

// Doubly Linked List for Enrollment History
class DoublyLinkedList {
private:
  Node *head;
  Node *tail;

public:
  DoublyLinkedList() : head(nullptr), tail(nullptr) {}

  Node *getHead() { return head; }
  Node *getTail() { return tail; }

  void add(string course) {
    Node *newNode = new Node(course);

    if (head == nullptr) {
      head = tail = newNode;
    } else {
      tail->setNext(newNode);
      newNode->setPrev(tail);
      tail = newNode;
    }
    cout << "Course '" << course << "' added to the enrollment history."
         << endl;
  }

  void view() {
    if (head == nullptr) {
      cout << "No enrollment history found." << endl;
      return;
    }

    cout << "Enrollment history: ";
    Node *temp = head;
    while (temp != nullptr) {
      cout << temp->getCourseName() << " ";
      temp = temp->getNext();
    }
    cout << endl;
  }

  int size() {
    int count = 0;
    Node *temp = head;
    while (temp != nullptr) {
      count++;
      temp = temp->getNext();
    }
    return count;
  }

  void append_toArray(string *arr, int size) {
    Node *temp = head;
    for (int i = 0; i < size && temp != nullptr; i++) {
      arr[i] = temp->getCourseName();
      temp = temp->getNext();
    }
  }

  bool findHistory(const string &courseName) {
    Node *temp = head;
    while (temp != nullptr) {
      if (temp->getCourseName() == courseName) {
        return true;
      }
      temp = temp->getNext();
    }
    return false;
  }
};

// Student Class
class Student {
private:
  int ID;
  string Name, Email, Phone, Address, Password;
  DoublyLinkedList enrollmentHistory;

public:
  Student *next;

  Student()
      : ID(0), Name(""), Email(""), Phone(""), Address(""), Password(""),
        next(nullptr) {}

  void setID(int id) { ID = id; }
  void setName(const string &name) { Name = name; }
  void setEmail(const string &email) { Email = email; }
  void setPhone(const string &phone) { Phone = phone; }
  void setAddress(const string &address) { Address = address; }
  void setPassword(const string &password) { Password = password; }

  int getID() const { return ID; }
  string getName() const { return Name; }
  string getEmail() const { return Email; }
  string getPhone() const { return Phone; }
  string getAddress() const { return Address; }
  string getPassword() const { return Password; }

  DoublyLinkedList &getHistory() { return enrollmentHistory; }
};

// Student List (Single Linked List)
Student *head = nullptr;
Student *studentsList[100];
int studentsCount = 0;

void addStudent(int id, string name, string email, string phone, string address,
                string password) {
  Student *newStudent = new Student();
  newStudent->setID(id);
  newStudent->setName(name);
  newStudent->setEmail(email);
  newStudent->setPhone(phone);
  newStudent->setAddress(address);
  newStudent->setPassword(password);

  if (head == nullptr) {
    head = newStudent;
  } else {
    if (id < head->getID()) {
      newStudent->next = head;
      head = newStudent;
    } else {
      Student *current = head;
      Student *prev = nullptr;
      while (current != nullptr && current->getID() < id) {
        prev = current;
        current = current->next;
      }
      newStudent->next = current;
      prev->next = newStudent;
    }
  }

  studentsList[studentsCount++] = newStudent;
  cout << "Student added successfully.\n";
}

void displayStudents() {
  if (head == nullptr) {
    cout << "No students to display. List is empty.\n";
    return;
  }

  Student *current = head;
  cout << "Student Records:\n";
  cout << "ID\tName\tEmail\t\tPhone\t\tAddress\t\tPassword\n";
  cout << "--------------------------------------------------------------\n";
  while (current != nullptr) {
    cout << current->getID() << "\t" << current->getName() << "\t"
         << current->getEmail() << "\t" << current->getPhone() << "\t"
         << current->getAddress() << "\t" << current->getPassword() << "\n";
    current = current->next;
  }
}

void insertionSortStudentIDs() {
  for (int i = 1; i < studentsCount; i++) {
    Student *currentStudent = studentsList[i];
    int old = i - 1;
    while (old >= 0 && studentsList[old]->getID() > currentStudent->getID()) {
      studentsList[old + 1] = studentsList[old];
      old--;
    }
    studentsList[old + 1] = currentStudent;
  }

  cout << "Student records sorted by ID.\n";
}

int binarySearchStudentByID(int targetID) {
  int low = 0;
  int high = studentsCount - 1;
  while (low <= high) {
    int mid = (high + low) / 2;
    if (studentsList[mid]->getID() == targetID) {
      return mid;
    } else if (studentsList[mid]->getID() < targetID) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

// BST for Course Management
class BST {
private:
  struct node {
    int courseId;
    string courseName;
    int courseCredits;
    string courseInstructor;
    node *left;
    node *right;

    node(int id, string name, int credits, string instructor)
        : courseId(id), courseName(name), courseCredits(credits),
          courseInstructor(instructor), left(nullptr), right(nullptr) {}
  };

  node *root;

  void addCourse(node *&root, int id, string name, int credits,
                 string instructor) {
    if (root == nullptr) {
      root = new node(id, name, credits, instructor);
      return;
    }
    if (id > root->courseId) {
      addCourse(root->right, id, name, credits, instructor);
    } else {
      addCourse(root->left, id, name, credits, instructor);
    }
  }

  node *minId(node *root) {
    if (!root->left)
      return root;
    return minId(root->left);
  }

  void dropCourse(node *&root, int id) {
    if (root == nullptr)
      return;

    if (id < root->courseId)
      dropCourse(root->left, id);
    else if (id > root->courseId)
      dropCourse(root->right, id);
    else {
      if (root->left == nullptr && root->right == nullptr) {
        delete root;
        root = nullptr;
      } else if (root->left == nullptr) {
        node *temp = root->right;
        delete root;
        root = temp;
      } else if (root->right == nullptr) {
        node *temp = root->left;
        delete root;
        root = temp;
      } else {
        node *n = minId(root->right);
        root->courseId = n->courseId;
        root->courseName = n->courseName;
        root->courseCredits = n->courseCredits;
        root->courseInstructor = n->courseInstructor;
        dropCourse(root->right, n->courseId);
      }
    }
  }

  void inorder(node *root) {
    if (root == nullptr)
      return;
    inorder(root->left);
    cout << root->courseId << " " << root->courseName << " "
         << root->courseCredits << " " << root->courseInstructor << endl;
    inorder(root->right);
  }

public:
  BST() : root(nullptr) {}

  void addCourse(int id, string name, int credits, string instructor) {
    addCourse(root, id, name, credits, instructor);
  }

  void dropCourse(int id) { dropCourse(root, id); }

  void displayCourses() { inorder(root); }
};

// Stack for Prerequisites
template <class T> class stack {
private:
  struct nodeS {
    T prerequisites;
    nodeS *next;

    nodeS(T p) : prerequisites(p), next(nullptr) {}
  };

  nodeS *top;

public:
  stack() : top(nullptr) {}

  bool isEmpty() { return top == nullptr; }

  void push(T d) {
    nodeS *newNode = new nodeS(d);
    if (top == nullptr) {
      top = newNode;
    } else {
      newNode->next = top;
      top = newNode;
    }
  }

  T pop() {
    if (top == nullptr) {
      return T();
    } else {
      nodeS *temp = top;
      top = top->next;
      T data = temp->prerequisites;
      delete temp;
      return data;
    }
  }

  void validatePrerequisites(int courseID, int studentID) {
    Student *current = head;
    while (current != nullptr && current->getID() != studentID) {
      current = current->next;
    }

    if (!current) {
      cout << "Student with ID " << studentID << " not found!" << endl;
      return;
    }

    DoublyLinkedList &history = current->getHistory();
    vector<T> missingPrereqs;

    while (!isEmpty()) {
      T prereqCourseName = pop();
      if (!history.findHistory(prereqCourseName)) {
        missingPrereqs.push_back(prereqCourseName);
      }
    }

    if (missingPrereqs.empty()) {
      cout << "All prerequisites are satisfied for course " << courseID << "."
           << endl;
    } else {
      cout << "The student is missing the following prerequisite(s) for course "
           << courseID << ":" << endl;
      for (auto &m : missingPrereqs) {
        cout << "- " << m << endl;
      }
    }
  }
};

// Waitlist Management
class CourseWaitlist {
private:
  struct WaitlistNode {
    int studentID;
    string studentName;
    WaitlistNode *next;

    WaitlistNode(int id, const string &name)
        : studentID(id), studentName(name), next(nullptr) {}
  };

  WaitlistNode *front;
  WaitlistNode *rear;

public:
  CourseWaitlist() : front(nullptr), rear(nullptr) {}

  void enqueue() {
    int id;
    string name;

    cout << "Enter Student ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Student Name: ";
    getline(cin, name);

    WaitlistNode *newNode = new WaitlistNode(id, name);

    if (rear == nullptr) {
      front = rear = newNode;
      cout << "Student added to the waitlist.\n";
      return;
    }

    rear->next = newNode;
    rear = newNode;

    cout << "Student added to the waitlist.\n";
  }

  void dequeue() {
    if (front == nullptr) {
      cout << "The waitlist is empty. No student to enroll.\n";
      return;
    }

    WaitlistNode *temp = front;
    front = front->next;

    if (front == nullptr) {
      rear = nullptr;
    }

    cout << "Student with ID " << temp->studentID << " (" << temp->studentName
         << ") has been enrolled.\n";

    delete temp;
  }

  void display() const {
    if (front == nullptr) {
      cout << "The waitlist is empty.\n";
      return;
    }

    cout << "Current Waitlist:\n";
    WaitlistNode *current = front;
    while (current != nullptr) {
      cout << "ID: " << current->studentID << ", Name: " << current->studentName
           << "\n";
      current = current->next;
    }
  }

  ~CourseWaitlist() {
    while (front != nullptr) {
      WaitlistNode *temp = front;
      front = front->next;
      delete temp;
    }
  }
};

// Hash Table for Fast Course Lookup
class HashTable {
private:
  static const int TABLE_SIZE = 100;
  list<pair<int, string>> table[TABLE_SIZE];

  int hashFunction(int CourseID) { return CourseID % TABLE_SIZE; }

public:
  void insertCourse(int CourseID, const string &CourseName) {
    int index = hashFunction(CourseID);
    table[index].push_back(make_pair(CourseID, CourseName));
  }

  // Search for a course by CourseID using hashing
  string searchWithHashing(int CourseID) {
    int index = hashFunction(CourseID);
    for (auto &course : table[index]) {
      if (course.first == CourseID) {
        return course.second;
      }
    }
    return "";
  }
};

// Bubble Sort for sorting courses
void bubbleSort(string arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

// Linear Search for searching courses
int linearSearch(string arr[], int size, const string &target) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == target) {
      return i;
    }
  }
  return -1;
}

// Main Function
int main() {
  DoublyLinkedList dll;
  BST courseTree;
  stack<string> prereqStack;
  CourseWaitlist waitlist;
  HashTable courseHashTable;
  int choice;
  string course;

  do {
    cout << "\n--- University Management System ---\n";
    cout << "1. Add a course\n";
    cout << "2. View course enrollment history\n";
    cout << "3. Sort and display courses\n";
    cout << "4. Search for a course\n";
    cout << "5. Add a student\n";
    cout << "6. Display students\n";
    cout << "7. Sort students by ID\n";
    cout << "8. Search for a student by ID\n";
    cout << "9. Add student to waitlist\n";
    cout << "10. Enroll student from waitlist\n";
    cout << "11. Display waitlist\n";
    cout << "12. Validate prerequisites\n";
    cout << "13. Search for a course using hashing\n";
    cout << "14. Exit\n";
    cout << "Enter your choice: ";

    if (!(cin >> choice)) {
      cout << "Invalid input. Please enter a valid option (1-14)." << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      continue;
    }

    switch (choice) {
    case 1: {
      int id, credits;
      string name, instructor;
      cout << "Enter Course ID: ";
      cin >> id;
      cin.ignore();
      cout << "Enter Course Name: ";
      getline(cin, name);
      cout << "Enter Course Credits: ";
      cin >> credits;
      cin.ignore();
      cout << "Enter Course Instructor: ";
      getline(cin, instructor);
      courseTree.addCourse(id, name, credits, instructor);
      courseHashTable.insertCourse(id, name); // Add to hash table
      break;
    }

    case 2:
      dll.view();
      break;

    case 3: {
      int size = dll.size();
      if (size == 0) {
        cout << "No courses to sort." << endl;
      } else {
        string *courses = new string[size];
        dll.append_toArray(courses, size);
        bubbleSort(courses, size); // Use bubble sort
        cout << "Sorted courses: ";
        for (int i = 0; i < size; i++) {
          cout << courses[i] << " ";
        }
        cout << endl;
        delete[] courses;
      }
      break;
    }

    case 4: {
      int size = dll.size();
      if (size == 0) {
        cout << "No courses to search." << endl;
      } else {
        string *courses = new string[size];
        dll.append_toArray(courses, size);

        cout << "Enter the course name to search: ";
        cin.ignore();
        getline(cin, course);

        int index = linearSearch(courses, size, course); // Use linear search
        if (index != -1) {
          cout << "Course '" << course << "' found at index " << index << "."
               << endl;
        } else {
          cout << "Course '" << course << "' not found." << endl;
        }

        delete[] courses;
      }
      break;
    }

    case 5: {
      int id;
      string name, email, phone, address, password;
      cout << "Enter student ID: ";
      cin >> id;
      cin.ignore();
      cout << "Enter student Name: ";
      getline(cin, name);
      cout << "Enter student Email: ";
      getline(cin, email);
      cout << "Enter student Phone: ";
      getline(cin, phone);
      cout << "Enter student Address: ";
      getline(cin, address);
      cout << "Enter student Password: ";
      getline(cin, password);

      addStudent(id, name, email, phone, address, password);
      break;
    }

    case 6:
      displayStudents();
      break;

    case 7:
      insertionSortStudentIDs();
      break;

    case 8: {
      // Sort the studentsList array before performing binary search
      insertionSortStudentIDs();

      int targetID;
      cout << "Enter the student ID to search: ";
      cin >> targetID;

      int index = binarySearchStudentByID(targetID);
      if (index != -1) {
        cout << "Student with ID " << targetID << " found at index " << index
             << "." << endl;
        cout << "Student Details:\n";
        cout << "ID: " << studentsList[index]->getID() << "\n";
        cout << "Name: " << studentsList[index]->getName() << "\n";
        cout << "Email: " << studentsList[index]->getEmail() << "\n";
        cout << "Phone: " << studentsList[index]->getPhone() << "\n";
        cout << "Address: " << studentsList[index]->getAddress() << "\n";
        cout << "Password: " << studentsList[index]->getPassword() << "\n";
      } else {
        cout << "Student with ID " << targetID << " not found." << endl;
      }
      break;
    }

    case 9:
      waitlist.enqueue();
      break;

    case 10:
      waitlist.dequeue();
      break;

    case 11:
      waitlist.display();
      break;

    case 12: {
      int courseID, studentID;
      cout << "Enter Course ID: ";
      cin >> courseID;
      cout << "Enter Student ID: ";
      cin >> studentID;
      prereqStack.validatePrerequisites(courseID, studentID);
      break;
    }

    case 13: {
      int courseID;
      cout << "Enter Course ID to search: ";
      cin >> courseID;
      string courseName = courseHashTable.searchWithHashing(courseID);
      if (!courseName.empty()) {
        cout << "Course found: " << courseName << endl;
      } else {
        cout << "Course with ID " << courseID << " not found." << endl;
      }
      break;
    }

    case 14:
      cout << "Exiting program. Goodbye!\n";
      break;

    default:
      cout << "Invalid choice! Please try again.\n";
    }
  } while (choice != 14);

  return 0;
}
