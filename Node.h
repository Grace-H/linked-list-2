/*Header file for class Node, for project Linked List
 *contains a Student and pointer to another Node
 *Author: Grace Hunter
 *Date: 05 December 2018
 */

#include <iostream>
#include <cstring>

#ifndef NODE_H
#define NODE_H

using namespace std;

class Node{
 public:
  //constuctor, takes Student pointer
  Node(Student* newstudent);
  //destructor, destroys student and pointer
  ~Node();
  //returns student Node contains
  Student* getStudent();
  //set student Node contains
  void setStudent(Student* newstudent);
  //returns pointer to next Node
  Node* getNext();
  //set pointer to next Node
  void setNext(Node* newnode);
 private:
  Student* student;
  Node* next;
}

#endif
