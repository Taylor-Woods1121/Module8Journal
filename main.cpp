#include <iostream>
#include <string>
#include <algorithm>
#include <fstream> 
#include <vector>


using namespace std;

// course information
using namespace std;
struct Course {
    string courseID;
    string courseName;
    vector<string> prerequisites;
};
struct Node {
    Course data;
    Node* next;
};
Node *head = nullptr;
void split(vector<string>&parts, string Line, string delimiter){

}
Node* newNode(Course data) {
    Node* node = new Node;
    node->data = data;
    node-> next = nullptr;
    return node;
}
void insertNewNode(Node* root, Course data) {
    Node* node = newNode(data);
    Node* ptr;
    if (root == nullptr) {
        root == node;
    }
    else {
        ptr = root;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        ptr->next = node;
    }
}
void printLinkedList(Node* root) {
    while (root!= nullptr) {
        cout << root->data.courseName << " -> ";
        root = root-> next;
    }
    cout << "nullptr" << endl;
}
Node* creatingLinkedList(Course arr[], int n) {
    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        insertNewNode(root, arr[i]);
    }
    return root;
}

int main()
{
    ifstream file;
    Node list;
    cout << "Welcome to the Course Planner!"; // First line printed
    while (true) // start of loop for menu options
    {
        int input;
        string input2; //get input within first input
        input = 0;
        cout << "    1. Load Data Structure."; // load all options the user has
        cout << "    2. Print Course List.";
        cout << "    3. Pring Course.";
        cout << "    9. Exit";
        cin >> input;
        cout << "";
        if (input == 9) // exit the menu
        {
            break;
        }
        else if (input ==1) // input to load data structure
        {
            file.open("project2.txt"); //defining the load data structure code
            string Line; // read one line of the file
                while(getline(file, Line)){
                    //create course for that line
                    vector<string> parts;
                    split(parts, Line, ",");

                    Course newCourse;

                    newCourse.courseID = parts[0];
                    newCourse.courseName = parts[1];

                    for (int i=2; i<parts.size(); i++) {
                        newCourse.prerequisites.push_back(parts[i]);
                    }
                    // turn that course into a node
                    //add new node to Node list
                    insertNewNode(&list, newCourse);
                }
        } // repeat step one until there are no more lines
    
    else if (input == 2) // input for course list
    { // outputs if input is 2. Shows course list
        printLinkedList(&list);
    }
    else if (input == 3) //input to show specific course
    {
        cout << "What course do you want to know about?"; // ask for input
        cin >> input2; //get input
        // search List of nodes for a node whose course has a courseID equal to the input
        Node* curr = &list;
        while (curr->next != nullptr){
            if(curr->data.courseID == input2){
                cout << curr->data.courseName << endl;
                // for loop to loop prerequisites
                for (int i=0; i<curr->data.prerequisites.size(); i++) {
                    cout << curr->data.prerequisites[i];
                    if (i<curr->data.prerequisites.size()-1) {
                        cout << ", ";
                    }
                }
                break;
            }
            else{// if its not the right node move on to the next}
                curr = curr->next;
            }
        }
        cout << endl;
    }
    }
    return 0;
}