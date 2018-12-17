/*Main file for linked list pair project
 *create several students in linked list and prints them out
 *Author: Grace Hunter
 *Date: 11 December 2018
 */

#include <iostream>
#include <cstring>
#include "Student.h"
#include "Node.h"

void printList(Node* start);
void addNode(Node* start, Student* student);

int main(){
  //student1
  char* first = new char[20];
  strcpy(first, "Paige");
  char* last = new char[20];
  strcpy(last, "Turner");
  Student* student1 = new Student(first, last, 823456, 2.45);
  Node* start = new Node(student1); //create first Node
  cout << "created student1" << endl;
  
  //student2
  char* first2 = new char[20];
  strcpy(first2, "Peter");
  char* last2 = new char[20];
  strcpy(last2, "Piper");
  Student* student2 = new Student(first2, last2, 654321, 5.42);
  addNode(start, student2); //add new Node
  cout << "created student2" << endl;
  
  char* first3 = new char[20];
  strcpy(first3, "Jack");
  char* last3 = new char[20];
  strcpy(last3, "Corner");
  Student* student3 = new Student(first3, last3, 898765, 0.92);
  addNode(start, student3); //add new Node
  cout << "created student3" << endl;
  //print list of students
  printList(start);

  return 0;
}

void printList(Node* start){
  if(start != NULL){
    start->getStudent()->print();
    printList(start->getNext());
  }
}

void addNode(Node* start, Student* student){
  //if list is empty
  if(start == NULL){
    start = new Node(student);
    cout << "Added in if1" << endl;
    start->getStudent()->print();
  }
  //if student is greater than current and next node is NULL
  else if(start->getStudent()->getId() <= student->getId() && start->getNext() == NULL){
    Node* node = new Node(student);
    start->setNext(node);
    cout << "Added in if2" << endl;
    start->getStudent()->print();
  }
  //if start is between current and next nodes
  else if(start->getStudent()->getId() <= student->getId() && start->getNext()->getStudent()->getId() >= student->getId()){
    Node* node = new Node(student);
    node->setNext(start->getNext());
    start->setNext(node);
    cout << "Added in if3" << endl;
    start->getStudent()->print();
  }
  else{
    addNode(start->getNext(), student);
    cout << "not there yet" << endl;
  }
  //get last node in list
  //  Node* current = start;
  //while(current->getNext() != NULL){
    //current = current->getNext();
    //}
  //current->setNext(new Node(student));
}
