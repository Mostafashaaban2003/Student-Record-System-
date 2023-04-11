#ifndef ADMIN_H
#define ADMIN_H
	#include "..\.\student\student.h"
	#define MAX_TRIES 3
	#define MAXIMUM_GRADE 100
#endif

//11 functions

//checks admin password 3 times, returns 0 if the user ran out of tries
int check_admin_password();

//returns the index of the first unoccupied space in the array
int check_available();

//adds a student to the array
void add_student();

//remove a student record from the array
void Remove_student_record();

//view all students records
void View_all_records();

//change admin password and returns 0 if he didn't enter the old password correctly for 3 times
void Edit_admin_password();

//change student grade (must be 0 ~ 150) 
void Edit_student_grade(int index);

//encrypt student password
void encrypt(char* origin);

//decrypt student password
void decrypt(char* encrypted);



