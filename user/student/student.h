#ifndef STUDENT_H
#define STUDENT_H
	#include "..\..\.\data_management\data_management.h"
	#define MAX_TRIES 3
	#define ADMIN 1
	#define STUDENT 0
#endif

//checks student password 3 times, returns 0 if the user ran out of tries
int check_student_password();

//prints a student data and takes the index as argument and your admin
void View_student_record(int index, int is_admin);

//asks student for id and password 3 times, returns 0 if the user ran out of tries
int Edit_student_Password();

//asks student for id and edits its name
void Edit_your_name();

//asks student to enter his id
int check_your_id();