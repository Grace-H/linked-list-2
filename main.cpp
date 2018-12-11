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
  Student* student1 = new Student(first, last, 123456, 2.45);
  Node* start = new Node(student1); //create first Node

  //student2
  char* first2 = new char[20];
  strcpy(first2, "Peter");
  char* last2 = new char[20];
  strcpy(last2, "Piper");
  Student* student2 = new Student(first2, last2, 654321, 5.42);
  addNode(start, student2); //add new Node

  char* first3 = new char[20];
  strcpy(first3, "Jack");
  char* last3 = new char[20];
  strcpy(last3, "Corner");
  Student* student3 = new Student(first3, last3, 898765, 0.92);
  addNode(start, student3); //add new Node

  //print list of students
  printList(start);

  return 0;
}

void printList(Node* start){
  Node* current = start;
  do{
    current->getStudent()->print();
    current = current->getNext();
  } while(current != NULL);
}

void addNode(Node* start, Student* student){
  //get last node in list
  Node* current = start;
  while(current->getNext() != NULL){
    current = current->getNext();
  }
  current->setNext(new Node(student));
}
