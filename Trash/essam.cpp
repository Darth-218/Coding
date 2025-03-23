#include <iostream>
#include <string>
using namespace std;

/* 
===========================================================
  CLASSES FOR OUR RECORD TYPES (using 'class' instead of 'struct')
===========================================================
*/

/* ---------------------------------------------------------
   Student: Basic student info for the SLL
--------------------------------------------------------- */
class Student {
public:
    int    ID;
    string Name;
    string Email;
    string Phone;
    string Address;
    string Password;
};

/* ---------------------------------------------------------
   StudentNode: Node for singly linked list (SLL) of students
--------------------------------------------------------- */
class StudentNode {
public:
    Student     data;   // The actual student record
    StudentNode *next;  // Pointer to the next node
};

/* ---------------------------------------------------------
   Course: Basic course info for the BST & Hash Table
--------------------------------------------------------- */
class Course {
public:
    int    courseID;
    string courseName;
    int    courseCredits;
    string courseInstructor;
};

/* ---------------------------------------------------------
   CourseNode: Node for binary search tree (BST) of courses
--------------------------------------------------------- */
class CourseNode {
public:
    Course      data;    // The actual course record
    CourseNode *left;    // Left child
    CourseNode *right;   // Right child
};

/* ---------------------------------------------------------
   Enrollment: A record of (studentID, courseID) 
   for the DLL tracking who is enrolled in what
--------------------------------------------------------- */
class Enrollment {
public:
    int studentID;
    int courseID;
};

/* ---------------------------------------------------------
   EnrollmentNode: Node for doubly linked list (DLL)
--------------------------------------------------------- */
class EnrollmentNode {
public:
    Enrollment     data;
    EnrollmentNode *next;
    EnrollmentNode *prev;
};

/* ---------------------------------------------------------
   For Waitlist: We'll store both courseID & studentID
   in the queue. 
--------------------------------------------------------- */
class WaitlistItem {
public:
    int studentID;
    int courseID;
};

/* ---------------------------------------------------------
   CourseHashNode: Node for chaining in the course hash table
--------------------------------------------------------- */
class CourseHashNode {
public:
    Course data;
    CourseHashNode *next;
};


/* 
===========================================================
  1) STUDENT RECORDS (SINGLY LINKED LIST)
===========================================================
   Global head pointer + helper functions
*/

StudentNode *gStudentHead = NULL; // global head for Student SLL

// Check if a student with this ID already exists
bool studentExists(int id) {
    StudentNode *temp = gStudentHead;
    while(temp != NULL) {
        if(temp->data.ID == id) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Add Student: If the ID doesn't already exist, append at end
void addStudent(int id, const string &name, const string &email,
                const string &phone, const string &address, const string &password)
{
    // Prevent duplicate IDs
    if(studentExists(id)) {
        cout << "Error: A student with ID " << id << " already exists.\n";
        return;
    }

    // Create new node
    StudentNode *newNode = new StudentNode;
    newNode->data.ID       = id;
    newNode->data.Name     = name;
    newNode->data.Email    = email;
    newNode->data.Phone    = phone;
    newNode->data.Address  = address;
    newNode->data.Password = password;
    newNode->next = NULL;

    if(gStudentHead == NULL) {
        gStudentHead = newNode;
        return;
    }

    StudentNode *temp = gStudentHead;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Delete Student by ID
bool deleteStudent(int id)
{
    if(gStudentHead == NULL) return false;

    // If the head node is the target
    if(gStudentHead->data.ID == id) {
        StudentNode *toDelete = gStudentHead;
        gStudentHead = gStudentHead->next;
        delete toDelete;
        return true;
    }

    // Otherwise find the node whose next is target
    StudentNode *current = gStudentHead;
    while(current->next != NULL && current->next->data.ID != id) {
        current = current->next;
    }
    if(current->next == NULL) {
        // Not found
        return false;
    }
    StudentNode *toDelete = current->next;
    current->next = toDelete->next;
    delete toDelete;
    return true;
}

// Display Students in SLL
void displayStudents()
{
    cout << "\n-- Displaying All Students --\n";
    if(gStudentHead == NULL) {
        cout << "[No students found]\n";
        return;
    }

    StudentNode *temp = gStudentHead;
    while(temp != NULL) {
        cout << "Student ID: " << temp->data.ID << "\n"
             << "  Name: " << temp->data.Name << "\n"
             << "  Email: " << temp->data.Email << "\n"
             << "  Phone: " << temp->data.Phone << "\n"
             << "  Address: " << temp->data.Address << "\n"
             << "  Password: " << temp->data.Password << "\n"
             << "---------------------------------\n";
        temp = temp->next;
    }
    cout << endl; // extra blank line for spacing
}

// Search Student by ID
Student* searchStudentByID(int id)
{
    StudentNode *temp = gStudentHead;
    while(temp != NULL) {
        if(temp->data.ID == id) {
            return &(temp->data);
        }
        temp = temp->next;
    }
    return NULL;
}

// Sort Students by ID (Bubble Sort)
void sortStudentsByID()
{
    if(gStudentHead == NULL || gStudentHead->next == NULL) return;

    bool swapped;
    do {
        swapped = false;
        StudentNode *current = gStudentHead;
        while(current->next != NULL) {
            if(current->data.ID > current->next->data.ID) {
                // Swap entire Student object
                Student temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
    } while(swapped);
}


/* 
===========================================================
  2) COURSE RECORDS (BINARY SEARCH TREE)
===========================================================
   Global root pointer + helper functions
*/

CourseNode *gCourseRoot = NULL;

// Check if course with cID already exists
bool courseExists(int cID);

// Create a new course node
CourseNode* createCourseNode(int cID, const string &cName,
                             int cCredits, const string &cInstr)
{
    CourseNode *newNode = new CourseNode;
    newNode->left = NULL;
    newNode->right= NULL;
    newNode->data.courseID      = cID;
    newNode->data.courseName    = cName;
    newNode->data.courseCredits = cCredits;
    newNode->data.courseInstructor = cInstr;
    return newNode;
}

// Add Course Helper (recursive BST insert)
CourseNode* addCourseHelper(CourseNode *node, int cID, const string &cName,
                            int cCredits, const string &cInstr)
{
    if(node == NULL) {
        return createCourseNode(cID, cName, cCredits, cInstr);
    }
    if(cID < node->data.courseID) {
        node->left = addCourseHelper(node->left, cID, cName, cCredits, cInstr);
    } else if(cID > node->data.courseID) {
        node->right= addCourseHelper(node->right, cID, cName, cCredits, cInstr);
    }
    // if equal, we ignore (duplicates not inserted)
    return node;
}

// Add Course (checks for duplicates first)
void addCourse(int cID, const string &cName, int cCredits, const string &cInstr)
{
    // Prevent duplicate IDs
    if(courseExists(cID)) {
        cout << "Error: A course with ID " << cID << " already exists.\n";
        return;
    }
    gCourseRoot = addCourseHelper(gCourseRoot, cID, cName, cCredits, cInstr);
}

// Find minimum node in subtree (for BST deletion)
CourseNode* findMinCourseNode(CourseNode *node)
{
    while(node != NULL && node->left != NULL) {
        node = node->left;
    }
    return node;
}

// BST Deletion helper
CourseNode* dropCourseHelper(CourseNode *node, int cID)
{
    if(node == NULL) return NULL;
    if(cID < node->data.courseID) {
        node->left = dropCourseHelper(node->left, cID);
    } else if(cID > node->data.courseID) {
        node->right= dropCourseHelper(node->right, cID);
    } else {
        // found it
        if(node->left == NULL) {
            CourseNode *tmp = node->right;
            delete node;
            return tmp;
        } else if(node->right == NULL) {
            CourseNode *tmp = node->left;
            delete node;
            return tmp;
        } else {
            CourseNode *minRight = findMinCourseNode(node->right);
            node->data = minRight->data;
            node->right = dropCourseHelper(node->right, minRight->data.courseID);
        }
    }
    return node;
}

// Drop Course
void dropCourse(int cID)
{
    gCourseRoot = dropCourseHelper(gCourseRoot, cID);
}

// Display (in-order) BFS
void displayCoursesInOrderHelper(CourseNode *node)
{
    if(node == NULL) return;
    displayCoursesInOrderHelper(node->left);
    cout << "Course ID: " << node->data.courseID << "\n"
         << "  Name: " << node->data.courseName << "\n"
         << "  Credits: " << node->data.courseCredits << "\n"
         << "  Instructor: " << node->data.courseInstructor << "\n"
         << "---------------------------------\n";
    displayCoursesInOrderHelper(node->right);
}

void displayCoursesInOrder()
{
    cout << "\n-- Displaying All Courses (In-Order) --\n";
    if(gCourseRoot == NULL) {
        cout << "[No courses found]\n\n";
        return;
    }
    displayCoursesInOrderHelper(gCourseRoot);
    cout << endl;
}

// Search for CourseNode by ID
CourseNode* searchCourseHelper(CourseNode *node, int cID)
{
    if(node == NULL) return NULL;
    if(node->data.courseID == cID) return node;
    if(cID < node->data.courseID)
        return searchCourseHelper(node->left, cID);
    else
        return searchCourseHelper(node->right, cID);
}

// Return pointer to Course if found
Course* searchCourseByID(int cID)
{
    CourseNode *found = searchCourseHelper(gCourseRoot, cID);
    if(found) return &(found->data);
    return NULL;
}

// Check existence of a course by ID
bool courseExists(int cID)
{
    return (searchCourseByID(cID) != NULL);
}

// Collect all courses in sorted order (for Hash insertion)
void collectCoursesInOrder(CourseNode *node, Course arr[], int &index, int maxSize)
{
    if(node == NULL) return;
    collectCoursesInOrder(node->left, arr, index, maxSize);
    if(index < maxSize) {
        arr[index] = node->data;
        index++;
    }
    collectCoursesInOrder(node->right, arr, index, maxSize);
}

int getAllCoursesInOrder(Course arr[], int maxSize)
{
    int index = 0;
    collectCoursesInOrder(gCourseRoot, arr, index, maxSize);
    return index;
}


/* 
===========================================================
  3) COURSE ENROLLMENT HISTORY (DOUBLY LINKED LIST)
===========================================================
   Global head/tail + add & view
*/

EnrollmentNode *gEnrollmentHead = NULL;
EnrollmentNode *gEnrollmentTail = NULL;

// Add Enrollment: Checks if Student & Course exist first
void addEnrollment(int studentID, int courseID)
{
    // Check existence
    if(!searchStudentByID(studentID)) {
        cout << "Error: Student ID " << studentID << " does not exist.\n";
        return;
    }
    if(!courseExists(courseID)) {
        cout << "Error: Course ID " << courseID << " does not exist.\n";
        return;
    }

    // Optional: Check if already enrolled in that course
    // We'll do a quick pass
    EnrollmentNode *checkPtr = gEnrollmentHead;
    while(checkPtr != NULL) {
        if(checkPtr->data.studentID == studentID &&
           checkPtr->data.courseID  == courseID) {
            cout << "Error: Student " << studentID 
                 << " is already enrolled in Course " << courseID << ".\n";
            return;
        }
        checkPtr = checkPtr->next;
    }

    // If valid, add new enrollment node
    EnrollmentNode *newNode = new EnrollmentNode;
    newNode->data.studentID = studentID;
    newNode->data.courseID  = courseID;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(gEnrollmentHead == NULL) {
        gEnrollmentHead = gEnrollmentTail = newNode;
    } else {
        gEnrollmentTail->next = newNode;
        newNode->prev = gEnrollmentTail;
        gEnrollmentTail = newNode;
    }
    cout << "Enrollment added (Student " << studentID 
         << " in Course " << courseID << ").\n";
}

// View Enrollment for a given student
void viewEnrollment(int studentID)
{
    cout << "\n-- Enrollment History for Student " << studentID << " --\n";
    EnrollmentNode *current = gEnrollmentHead;
    bool found = false;
    while(current != NULL) {
        if(current->data.studentID == studentID) {
            cout << "  Course ID: " << current->data.courseID << "\n";
            found = true;
        }
        current = current->next;
    }
    if(!found) {
        cout << "  [No enrollment records found]\n";
    }
    cout << "---------------------------------\n\n";
}


/* 
===========================================================
  4) REGISTRATION STACK (ARRAY-BASED)
===========================================================
*/

static const int MAX_STACK = 10;
int prereqStack[MAX_STACK];
int stackTop = -1;

// Basic stack ops
bool pushPrereq(int val) {
    if(stackTop >= MAX_STACK - 1) return false;
    prereqStack[++stackTop] = val;
    return true;
}
bool popPrereq() {
    if(stackTop < 0) return false;
    stackTop--;
    return true;
}
int topPrereq() {
    if(stackTop < 0) return -1;
    return prereqStack[stackTop];
}
bool isPrereqEmpty() {
    return (stackTop < 0);
}

/* 
   validatePrerequisites (Demo):
   - Now checks if the course & student exist 
     before even pushing anything.
*/
bool validatePrerequisites(int courseID, int studentID)
{
    // Check existence of student & course
    if(!searchStudentByID(studentID)) {
        cout << "Error: Student ID " << studentID << " does not exist.\n";
        return false;
    }
    if(!courseExists(courseID)) {
        cout << "Error: Course ID " << courseID << " does not exist.\n";
        return false;
    }

    cout << "[STACK] Checking prerequisites for course "
         << courseID << " (student " << studentID << ")...\n";
    // Reset the stack
    stackTop = -1;

    // Suppose course has prereqs: 101, 102
    pushPrereq(101);
    pushPrereq(102);

    // Suppose student completed only 101
    int studentCompleted[1] = {101};
    for(int i = 0; i < 1; i++) {
        if(!isPrereqEmpty() && topPrereq() == studentCompleted[i]) {
            popPrereq();
        }
    }

    if(isPrereqEmpty()) {
        cout << " -> All prerequisites met. Registration allowed!\n";
        return true;
    } else {
        cout << " -> Missing prereqs! Still on stack top = " << topPrereq() << "\n";
        return false;
    }
}


/* 
===========================================================
  5) WAITLIST QUEUE (ARRAY-BASED)
===========================================================
   We'll store pairs: (courseID, studentID).
   We'll verify existence of both before enqueuing, 
   and also check if they're already enqueued if we want.
*/

static const int MAX_Q = 10;
WaitlistItem waitlistQ[MAX_Q]; 
int frontIdx = 0, rearIdx = -1, qCount = 0;

// Enqueue: check if both student & course exist
bool enqueueWaitlist(int studentID, int courseID)
{
    // Existence check
    if(!searchStudentByID(studentID)) {
        cout << "Error: Student ID " << studentID << " does not exist.\n";
        return false;
    }
    if(!courseExists(courseID)) {
        cout << "Error: Course ID " << courseID << " does not exist.\n";
        return false;
    }

    // Optional: check if already in queue
    for(int i = 0; i < qCount; i++) {
        // get index in circular array
        int idx = (frontIdx + i) % MAX_Q;
        if(waitlistQ[idx].studentID == studentID &&
           waitlistQ[idx].courseID == courseID) {
            cout << "Error: That student is already waitlisted for this course.\n";
            return false;
        }
    }

    if(qCount == MAX_Q) {
        cout << "Error: Waitlist is full.\n";
        return false;
    }
    rearIdx = (rearIdx + 1) % MAX_Q;
    waitlistQ[rearIdx].studentID = studentID;
    waitlistQ[rearIdx].courseID  = courseID;
    qCount++;
    cout << "Student " << studentID 
         << " waitlisted for Course " << courseID << ".\n";
    return true;
}

// Dequeue: remove from front
bool dequeueWaitlist()
{
    if(qCount == 0) {
        // empty
        return false;
    }
    WaitlistItem frontItem = waitlistQ[frontIdx];
    cout << "Enrolling student " << frontItem.studentID 
         << " from waitlist in course " << frontItem.courseID << ".\n";

    // Actually, we might want to add them to enrollment here:
    addEnrollment(frontItem.studentID, frontItem.courseID);

    frontIdx = (frontIdx + 1) % MAX_Q;
    qCount--;
    return true;
}


/* 
===========================================================
  6) COURSE HASH TABLE (CHAINING)
===========================================================
*/

static const int TABLE_SIZE = 10;
CourseHashNode *courseTable[TABLE_SIZE];

// Initialize the hash table
void initCourseHashTable() {
    for(int i=0; i<TABLE_SIZE; i++) {
        courseTable[i] = NULL;
    }
}

// Very simple hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Insert course into hash (front of chain)
void insertCourseHash(const Course &c)
{
    int index = hashFunction(c.courseID);
    CourseHashNode *newNode = new CourseHashNode;
    newNode->data = c;
    newNode->next = courseTable[index];
    courseTable[index] = newNode;
}

// Search course in hash by ID
Course* searchCourseHash(int cID)
{
    int index = hashFunction(cID);
    CourseHashNode *current = courseTable[index];
    while(current != NULL) {
        if(current->data.courseID == cID) {
            return &(current->data);
        }
        current = current->next;
    }
    return NULL;
}


/* 
===========================================================
  SUB-MENU FUNCTIONS
===========================================================
   Each data structure has its own mini-menu.
*/

/* ---------------------------
   STUDENT MENU (SLL)
--------------------------- */
void studentMenu()
{
    while(true) {
        cout << "\n*** STUDENT MENU ***\n"
             << "1. Add Student\n"
             << "2. Delete Student\n"
             << "3. Display All Students\n"
             << "4. Sort Students by ID\n"
             << "5. Search Student by ID\n"
             << "0. Return to Main Menu\n"
             << "Choose an option: ";
        int choice;
        cin >> choice;
        if(!cin) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if(choice == 0) {
            break;
        }
        else if(choice == 1) {
            int id;
            string name, email, phone, addr, pass;
            cout << "Enter ID: "; 
            cin >> id;
            cin.ignore(); // clear newline

            cout << "Enter Name: "; getline(cin, name);
            cout << "Enter Email: "; getline(cin, email);
            cout << "Enter Phone: "; getline(cin, phone);
            cout << "Enter Address: "; getline(cin, addr);
            cout << "Enter Password: "; getline(cin, pass);

            addStudent(id, name, email, phone, addr, pass);
        }
        else if(choice == 2) {
            int id;
            cout << "Enter ID to delete: ";
            cin >> id;
            bool ok = deleteStudent(id);
            if(ok) cout << "Deleted.\n"; 
            else cout << "ID not found.\n";
        }
        else if(choice == 3) {
            displayStudents();
        }
        else if(choice == 4) {
            sortStudentsByID();
            cout << "Students sorted by ID.\n";
        }
        else if(choice == 5) {
            int id;
            cout << "Enter ID to search: ";
            cin >> id;
            Student *s = searchStudentByID(id);
            if(s) {
                cout << "\n-- Student Found --\n"
                     << " ID: " << s->ID << "\n"
                     << " Name: " << s->Name << "\n"
                     << " Email: " << s->Email << "\n"
                     << " Phone: " << s->Phone << "\n"
                     << " Address: " << s->Address << "\n"
                     << " Password: " << s->Password << "\n\n";
            } else {
                cout << "Not found.\n";
            }
        }
        else {
            cout << "[Invalid choice]\n";
        }
    }
}

/* ---------------------------
   COURSE MENU (BST)
--------------------------- */
void courseMenu()
{
    while(true) {
        cout << "\n*** COURSE MENU ***\n"
             << "1. Add Course\n"
             << "2. Drop Course\n"
             << "3. Display All Courses (In-Order)\n"
             << "4. Search Course by ID\n"
             << "0. Return to Main Menu\n"
             << "Choose an option: ";
        int choice; 
        cin >> choice;
        if(!cin) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if(choice == 0) {
            break;
        }
        else if(choice == 1) {
            int cID, cCredits;
            string cName, cInstr;
            cout << "Enter Course ID: "; cin >> cID;
            cout << "Enter Credits: "; cin >> cCredits;
            cin.ignore();

            cout << "Enter Course Name: "; getline(cin, cName);
            cout << "Enter Instructor: "; getline(cin, cInstr);

            addCourse(cID, cName, cCredits, cInstr);
        }
        else if(choice == 2) {
            int cID;
            cout << "Enter Course ID to drop: ";
            cin >> cID;
            dropCourse(cID);
            cout << "Course dropped (if it existed).\n";
        }
        else if(choice == 3) {
            displayCoursesInOrder();
        }
        else if(choice == 4) {
            int cID;
            cout << "Enter Course ID to search: ";
            cin >> cID;
            Course *c = searchCourseByID(cID);
            if(c) {
                cout << "\n-- Course Found --\n"
                     << " ID: " << c->courseID << "\n"
                     << " Name: " << c->courseName << "\n"
                     << " Credits: " << c->courseCredits << "\n"
                     << " Instructor: " << c->courseInstructor << "\n\n";
            } else {
                cout << "Not found.\n";
            }
        }
        else {
            cout << "[Invalid choice]\n";
        }
    }
}

/* ---------------------------
   ENROLLMENT MENU (DLL)
--------------------------- */
void enrollmentMenu()
{
    while(true) {
        cout << "\n*** ENROLLMENT MENU ***\n"
             << "1. Add Enrollment\n"
             << "2. View Enrollment by Student ID\n"
             << "0. Return to Main Menu\n"
             << "Choose an option: ";
        int choice; 
        cin >> choice;
        if(!cin) {
            cin.clear(); 
            cin.ignore(1000, '\n');
            continue;
        }

        if(choice == 0) {
            break;
        }
        else if(choice == 1) {
            int sID, cID;
            cout << "Enter Student ID: "; cin >> sID;
            cout << "Enter Course ID: "; cin >> cID;
            addEnrollment(sID, cID);
        }
        else if(choice == 2) {
            int sID;
            cout << "Enter Student ID: "; cin >> sID;
            viewEnrollment(sID);
        }
        else {
            cout << "[Invalid choice]\n";
        }
    }
}

/* ---------------------------
   REGISTRATION STACK MENU
--------------------------- */
void prereqStackMenu()
{
    while(true) {
        cout << "\n*** REGISTRATION (STACK) MENU ***\n"
             << "1. Validate Prerequisites (Demo)\n"
             << "0. Return to Main Menu\n"
             << "Choose an option: ";
        int choice; 
        cin >> choice;

        if(!cin) {
            cin.clear(); 
            cin.ignore(1000, '\n');
            continue;
        }

        if(choice == 0) {
            break;
        }
        else if(choice == 1) {
            int courseID, studentID;
            cout << "Enter Course ID: "; cin >> courseID;
            cout << "Enter Student ID: "; cin >> studentID;
            validatePrerequisites(courseID, studentID);
        }
        else {
            cout << "[Invalid choice]\n";
        }
    }
}

/* ---------------------------
   WAITLIST QUEUE MENU
--------------------------- */
void waitlistQueueMenu()
{
    while(true) {
        cout << "\n*** WAITLIST (QUEUE) MENU ***\n"
             << "1. Enqueue (Student, Course)\n"
             << "2. Dequeue (Enroll next Waitlisted)\n"
             << "0. Return to Main Menu\n"
             << "Choose an option: ";
        int choice; 
        cin >> choice;

        if(!cin) {
            cin.clear(); 
            cin.ignore(1000, '\n');
            continue;
        }

        if(choice == 0) {
            break;
        }
        else if(choice == 1) {
            int sID, cID;
            cout << "Enter Student ID: "; cin >> sID;
            cout << "Enter Course ID: "; cin >> cID;
            enqueueWaitlist(sID, cID);
        }
        else if(choice == 2) {
            if(!dequeueWaitlist()) {
                cout << "Waitlist is empty!\n";
            }
        }
        else {
            cout << "[Invalid choice]\n";
        }
    }
}

/* ---------------------------
   COURSE HASH TABLE MENU
--------------------------- */
void hashTableMenu()
{
    while(true) {
        cout << "\n*** COURSE HASH TABLE MENU ***\n"
             << "1. Init Hash Table\n"
             << "2. Insert All BST Courses into Hash\n"
             << "3. Search Course in Hash\n"
             << "0. Return to Main Menu\n"
             << "Choose an option: ";
        int choice; 
        cin >> choice;

        if(!cin) {
            cin.clear(); 
            cin.ignore(1000, '\n');
            continue;
        }

        if(choice == 0) {
            break;
        }
        else if(choice == 1) {
            initCourseHashTable();
            cout << "Hash Table Initialized.\n";
        }
        else if(choice == 2) {
            Course arr[50];
            int cnt = getAllCoursesInOrder(arr, 50);
            for(int i=0; i<cnt; i++) {
                insertCourseHash(arr[i]);
            }
            cout << cnt << " courses inserted into hash table.\n";
        }
        else if(choice == 3) {
            int cID;
            cout << "Enter Course ID to search in hash: ";
            cin >> cID;
            Course *c = searchCourseHash(cID);
            if(c) {
                cout << "\n-- Found in Hash --\n"
                     << " ID: " << c->courseID << "\n"
                     << " Name: " << c->courseName << "\n"
                     << " Credits: " << c->courseCredits << "\n"
                     << " Instructor: " << c->courseInstructor << "\n\n";
            } else {
                cout << "Not found in Hash.\n";
            }
        }
        else {
            cout << "[Invalid choice]\n";
        }
    }
}


/* 
===========================================================
  MAIN: MASTER MENU
===========================================================
*/

int main()
{
    try {
        while(true) {
            cout << "\n=========== MAIN MENU ===========\n"
                 << "1. Manage Students (SLL)\n"
                 << "2. Manage Courses (BST)\n"
                 << "3. Manage Enrollments (DLL)\n"
                 << "4. Registration (Prereq Stack)\n"
                 << "5. Waitlist (Queue)\n"
                 << "6. Course Hash Table (Chaining)\n"
                 << "0. Exit\n"
                 << "=================================\n"
                 << "Enter your choice: ";
            int mainChoice;
            cin >> mainChoice;

            // Handle bad input
            if(!cin) {
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            if(mainChoice == 0) {
                cout << "Exiting program. Goodbye!\n";
                break;
            }
            else if(mainChoice == 1) {
                studentMenu();
            }
            else if(mainChoice == 2) {
                courseMenu();
            }
            else if(mainChoice == 3) {
                enrollmentMenu();
            }
            else if(mainChoice == 4) {
                prereqStackMenu();
            }
            else if(mainChoice == 5) {
                waitlistQueueMenu();
            }
            else if(mainChoice == 6) {
                hashTableMenu();
            }
            else {
                cout << "[Invalid choice]\n";
            }
        }
    }
    catch(int) {
        cout << "[ERROR] An integer exception was caught.\n";
    }
    catch(...) {
        cout << "[ERROR] An unknown exception occurred.\n";
    }

    return 0;
}
