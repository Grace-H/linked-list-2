/*Class Student, project Linked List
 *contains and prints info related to student
 *Author: Grace Hunter
 *Date: 05 December 2018
 */

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Student.h"

using namespace std;

//constructor
Student::Student(char* newfirst, char* newlast, int newid, float newgpa){
  first = newfirst;
  last = newlast;
  id = newid;
  gpa = newgpa;
}

//destructor
Student::~Student(){
  delete [] first;
  delete [] last;
}

//get student's id
int Student::getId(){
  return id;
}

//display Student's info
void Student::print(){
  cout << first << " " << last << ", " << id << ", " << setprecision(3) << gpa << endl;
}

float Student::getGPA(){
  return gpa;
}
