//Node class definitions

#ifndef NODE_H
#define NODE_H
#include "student.h"
#include <iostream>

using namespace std;

//definition of the Node class, with 2 private variables and required functions
class Node{
 public:
  Node(Student*);        //constructor
  ~Node();               //deconstructor  

  Student* getStudent(); //get student pointer
  Node* getNext();       //get next Node pointer
  void setNext(Node*);   //set the next pointer to the corresponding node pointer
  
private:
  Student* sdt;
  Node* next;
};
#endif
