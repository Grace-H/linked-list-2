/*Main file for linked list pair project
 *create several students in linked list and prints them out
 *Author: Grace Hunter
 *Date: 11 December 2018
 */

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include "Student.h"
#include "Node.h"

void quit(Node* &head);
void printList(Node* start);
void deleteNode(Node* &head, Node* current, Node* previous, int id);
void addNode(Node* &head, Node* current, Node* previous, Student* student);
void addStudent(Node* &head);
void deleteStudent(Node* &head);
void average(Node* head);

int main(){
  //start of linked list
  Node* head = NULL;

  //cstrings with commands for comparision
  char addStr[10] = "ADD";
  char deleteStr[10] = "DELETE";
  char printStr[10] = "PRINT";
  char quitStr[10] = "QUIT";
  char avgStr[10] = "AVERAGE";  

  //Welcome!
  cout << "Welcome to student list." << endl;
  
  //continue to read in commands while still running
  bool stillRunning = true;
  char input[256];
  while (stillRunning){
  
    //get a command from the user
    cout << "Ready for command 'ADD' 'DELETE' 'PRINT' 'AVERAGE' 'QUIT'" << endl;
    cin.get(input, 256);
    cin.get();
    
    //make all caps
    for(int i = 0; i < 256; i++){
      input[i] = toupper(input[i]);
    }

    //match the input to a command and run corresponding function
    if(strcmp(input, addStr) == 0){ //ADD
      addStudent(head);
      cout << "Added Student" << endl;
      cout << endl;
    } else if (strcmp(input, deleteStr) == 0){ //DELETE
      deleteStudent(head);
      cout << endl;
    } else if (strcmp(input, printStr) == 0){ //PRINT
      if(head == NULL){
	cout << "No students to print" << endl;
      }
      else{
	printList(head);
      }
      cout << endl;
    } else if (strcmp(input, quitStr) == 0){ //QUIT
      quit(head);
      stillRunning = false;
      cout << "Quit application" << endl;
    } else if(strcmp(input, avgStr) == 0){
      average(head);
      cout << endl;
    } else { //input not recognized, prompt again
      cout << "Sorry, did not recognize that command" << endl;
    }
  }  

  return 0;
}

//void addStudent(Node* &head): get student info from user and add a Node with new Student
void addStudent(Node* &head){
  //get info about student
  char* first = new char[256];
  cout << "First Name: " << endl;
  cin.get(first, 256);
  cin.get();
  
  char* last = new char[20];
  cout << "Last Name: " << endl;
  cin.get(last, 256);
  cin.get();

  char input[256];
  cout << "ID: " << endl;
  cin.get(input, 256);
  cin.get();
  int id = atoi(input);

  cout << "GPA: " << endl;
  cin.get(input, 256);
  cin.get();
  float gpa = atof(input);

  //create student and node
  Student* student = new Student(first, last, id, gpa);
  addNode(head, head, NULL, student);
}

//void quit(Node* &head): delete all Nodes & Students
void quit(Node* &head){
  if(head != NULL){
    Node* current = head;
    head = head->getNext();
    delete current;
    quit(head);
  }
}

//void deleteNode(Node* &head, Node* current, Node* previous, int id): find and delete node using Student id
void deleteNode(Node* &head, Node* current, Node* previous, int id){
  //if list is empty, no students can match
  if(head == NULL){
    cout << "No students with matching id" << endl;
  }
  //if current node matches id
  else if(current->getStudent()->getId() == id){
    //if current is the head, make head the next node
    if(current == head){
      head = current->getNext();
    }
    //connect previous to next
    else{
	previous->setNext(current->getNext());
    }
    //delete found node
    delete current;
  }
  //if end of list hasn't been reached
  else if (current->getNext() != NULL){
    deleteNode(head, current->getNext(), current, id);
  }
  //if end of list and no student found
  else{
    cout << "No students with matching id" << endl;
  }
}

//void deleteStudent(Node* &head): get student id from user and delete corresponding node
void deleteStudent(Node* &head){
  //get id from user
  cout << "Student id: " << endl;
  char* input = new char[256];
  cin.get(input, 256);
  cin.get();
  int num = atoi(input);
  
  //find and delete node
  deleteNode(head, head, NULL, num);
  delete [] input;
}

//void average(Node* head): prints out average GPA of list
void average(Node* head){
  if(head == NULL){
    cout << "No students to average" << endl;
  }
  else{
    float gpa = 0;
    Node* current = head;
    int total = 0;
    //loop through all students and add each gpa to gpa
    while(current != NULL){
      gpa += current->getStudent()->getGPA();
      current = current->getNext();
      total++;
    }
    //print out gpa, shown to two decimal places
    cout << setprecision(3) << gpa/total << endl;
  }
}

//void printList(Node* start): prints out students
void printList(Node* start){
  if(start != NULL){
    start->getStudent()->print();
    printList(start->getNext());
  }
}

//void addNode(Node*, Node*, Node*, Student*): locates where student should
//be in list based on student id (list is sorted low->high) and creates new node at that location
void addNode(Node* &head, Node* current, Node* previous, Student* student){
  //if list is empty
  if(head == NULL){
    head = new Node(student);
  }
  //if at the end of the list
  else if(current == NULL){
    current = new Node(student);
  }
  //the first node in the list and smallest
  else if(previous == NULL && student->getId() <= current->getStudent()->getId()){
    head = new Node(student);
    head->setNext(current);
  }
  //if student is greater than current and next node is NULL
  else if(current->getStudent()->getId() <= student->getId() && current->getNext() == NULL){
    Node* node = new Node(student);
    current->setNext(node);
  }
  //if start is between current and next nodes
  else if(current->getStudent()->getId() <= student->getId() && current->getNext()->getStudent()->getId() >= student->getId()){
    Node* node = new Node(student);
    node->setNext(current->getNext());
    current->setNext(node);
  }
  //move on to next position in list
  else{
    addNode(head, current->getNext(), current, student);
  }
}
