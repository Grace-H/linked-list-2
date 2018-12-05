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

Node::Node(Student* newstudent){
  student = student;
}

Node::~Node(){
  delete student;
  delete next;
}

Student* Node::getStudent(){
  return student;
}

void Node::setStudent(Student* newstudent){
  student = newstudent;
}

Node* Node::getNext(){
  return next;
}

void Node::setNext(Node* newnode){
  next = newnode;
}
