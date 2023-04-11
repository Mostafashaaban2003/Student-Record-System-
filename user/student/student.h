#ifndef STUDENT_H
#define STUDENT_H
	#include "..\..\.\types\types.h"
	#define INITIAL_NUMBER_OF_STUDENTS 0
#endif

//number of maximum students can fit without allocating. (The size of the array).
int number_of_students;

//searches for a specified id and returns the index of it and if not found returns -1
int search_id(char* id);

//asks the user repeatidly to enter a correct id , search it and returns its index
int check_id();

//prints a student data and takes the index as argument 
void View_student_record(int index);








//void Edit your password();
//void Edit your name();
student* students;