/*Class Node, for project Linked List
 *contains a Student and pointer to another Node
 *Author: Grace Hunter
 *Date: 05 December 2018
 */

#include <iostream>
#include <cstring>
#include "Node.h"
#include "Student.h"

using namespace std;

//constructor
Node::Node(Student* newstudent){
  student = newstudent;
  next = NULL;
}

//destructor
Node::~Node(){
  delete student;
  delete next;
}

//returns student it contains
Student* Node::getStudent(){
  return student;
}

//sets student it contains
void Node::setStudent(Student* newstudent){
  student = newstudent;
}

//returns Node it points to
Node* Node::getNext(){
  return next;
}

//sets Node it points to
void Node::setNext(Node* newnode){
  next = newnode;
}
