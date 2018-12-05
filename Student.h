/*Header file for class Student, for projects Linked List
 *contains and prints information elated to Student
 *Author: Grace Hunter
 *Date: 05 December 2018
 */

#include <iostream>
#include <cstring>

#ifndef STUDENT_H
#define STUDENT_H

using namespace std;

class Student{
 public:
  Student(char* newfirst, char* newlast, int newid, float newgpa);
  ~Student();
  void print();
 private:
  char* first;
  char* last;
  int id;
  float gpa;
}

#endif
