#ifndef STUDENT_H
#define STUDENT_H
	#include "..\..\.\data_management\data_management.h"
	#define MAX_TRIES 3
	#define ADMIN 1
	#define STUDENT 0
#endif

//checks student password 3 times, returns 0 if the user ran out of tries
int check_student_password();

//prints a student data and takes the index as argument and isadmin or not
void View_student_record(int index, int is_admin);

//asks student for id and password 3 times, returns 0 if the user ran out of tries
int Edit_student_Password();

//Edits Student Name
void Edit_your_name();

//asks user to enter id and name and prints the password decrypted if the id and the name are correct.
void forgot_my_password();