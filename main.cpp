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
  
  //student1
  char* first = new char[20];
  strcpy(first, "Paige");
  char* last = new char[20];
  strcpy(last, "Turner");
  Student* student1 = new Student(first, last, 823456, 2.4544);
  Node* head = new Node(student1); //create first Node
  cout << "created student1" << endl;
  
  //student2
  char* first2 = new char[20];
  strcpy(first2, "Peter");
  char* last2 = new char[20];
  strcpy(last2, "Piper");
  Student* student2 = new Student(first2, last2, 654321, 5.4299);
  addNode(head, head, NULL, student2); //add new Node
  cout << "created student2" << endl;
  
  char* first3 = new char[20];
  strcpy(first3, "Jack");
  char* last3 = new char[20];
  strcpy(last3, "Corner");
  Student* student3 = new Student(first3, last3, 898765, 1.925);
  addNode(head, head, NULL, student3); //add new Node
  cout << "created student3" << endl;
  //print list of students
  //printList(head);

  char* first4 = new char[20];
  strcpy(first4, "Jack");
  char* last4 = new char[20];
  strcpy(last4, "Corner");
  Student* student4 = new Student(first4, last4, 798765, 1.92);
  addNode(head, head, NULL, student4); //add new Node
  cout << "created student4" << endl;
  //print list of students
  printList(head);

  cout << "searching for student with id 798765" << endl;
  deleteNode(head, head, NULL, 654321);
  cout << endl;
  printList(head);
  average(head);

  //cstrings with commands for comparision
  char addStr[10] = "ADD";
  char deleteStr[10] = "DELETE";
  char printStr[10] = "PRINT";
  char quitStr[10] = "QUIT";
  
  //Welcome!
  cout << "Welcome to student list." << endl;
  
  //continue to read in commands while still running
  bool stillRunning = true;
  char input[256];
  while (stillRunning){
  
    //get a command from the user
    cout << "Ready for command 'ADD' 'DELETE' 'PRINT' 'QUIT'" << endl;
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
    } else if (strcmp(input, deleteStr) == 0){ //DELETE
      //    deleteStudent(students);
    } else if (strcmp(input, printStr) == 0){ //PRINT
      printList(head);
    } else if (strcmp(input, quitStr) == 0){ //QUIT
      quit(head);
      stillRunning = false;
      cout << "Quit application" << endl;
    } else { //input not recognized, prompt again
      cout << "Sorry, did not recognize that command" << endl;
    }
  }  

  return 0;
}

void addStudent(Node* &head){

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
  
  Student* student = new Student(first, last, id, gpa);
  //Node* head = new Node(student1); //create first Node
  addNode(head, head, NULL, student);
  cout << "created student1" << endl;
    
}
void quit(Node* &head){
  if(head != NULL){
    Node* current = head;
    head = head->getNext();
    delete current;
    quit(head);
  }
}
  
void deleteNode(Node* &head, Node* current, Node* previous, int id){
  if(head == NULL){
    cout << "No students with matching id" << endl;
  }
  else if(current->getStudent()->getId() == id){
    cout << "Student found" << endl;
    current->getStudent()->print();
    if(current == head){
      head = current->getNext();
    }
    else{
	previous->setNext(current->getNext());
    }
    delete current;
  }
  else if (current->getNext() != NULL){
    deleteNode(head, current->getNext(), current, id);
  }
  else{
    cout << "No students with matching id" << endl;
  }
}

void average(Node* head){
  float gpa = 0;
  Node* current = head;
  int total = 0;
  while(current != NULL){
    gpa += current->getStudent()->getGPA();
    current = current->getNext();
    total++;
  }
  cout << setprecision(3) << gpa/total << endl;
  cout << "hi" << endl;
}

void printList(Node* start){
  if(start != NULL){
    start->getStudent()->print();
    printList(start->getNext());
  }
}

void addNode(Node* &head, Node* current, Node* previous, Student* student){
  if(head != NULL){
    cout << "Head: " << head->getStudent()->getId() << endl;
  }
  else{
    cout << "head is NULL" << endl;
  }
  if(current != NULL){
    cout << "current: " << current->getStudent()->getId() << endl;
  }
  else{
    cout << "current is NULL" << endl;
  }
  if(previous != NULL){
    cout << "Previous: " << previous->getStudent()->getId() << endl;
  }
  else{
    cout << "previous is NULL" << endl;
  }
  //if list is empty
  if(current == NULL){
    current = new Node(student);
    cout << "Added in if1" << endl;
    //start->getStudent()->print();
    printList(current);
  }
  //the first node in the list and smallest
  if(previous == NULL && student->getId() <= current->getStudent()->getId()){
    head = new Node(student);
    head->setNext(current);
    cout << "head's student in 1B" << head->getStudent()->getId() << endl;
    cout << "Added in if1B" << endl;
  }
  //if student is greater than current and next node is NULL
  else if(current->getStudent()->getId() <= student->getId() && current->getNext() == NULL){
    Node* node = new Node(student);
    current->setNext(node);
    cout << "Added in if2" << endl;
    //start->getStudent()->print();
  }
  //if start is between current and next nodes
  else if(current->getStudent()->getId() <= student->getId() && current->getNext()->getStudent()->getId() >= student->getId()){
    Node* node = new Node(student);
    node->setNext(current->getNext());
    current->setNext(node);
    cout << "Added in if3" << endl;
    //start->getStudent()->print();
  }
  else{
    addNode(head, current->getNext(), current, student);
    cout << "not there yet" << endl;
  }
  //get last node in list
  //  Node* current = start;
  //while(current->getNext() != NULL){
    //current = current->getNext();
    //}
  //current->setNext(new Node(student));
}
