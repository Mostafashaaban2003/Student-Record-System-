#ifndef ADMIN_H
#define ADMIN_H
	#include "..\.\student\student.h"
	#define MAXIMUM_GRADE 100
	#define GENDERS 2
	#define ADDING 1
	#define EDITING 0

#endif

//6 functions

//checks admin password 3 times, returns 0 if the user ran out of tries
int check_admin_password();

//adds a student to the array
void add_student();

//remove a student record from the array
void Remove_student_record(int index);

//view all students records
void View_all_records();

//change admin password and returns 0 if he didn't enter the old password correctly for 3 times
void Edit_admin_password();

//change student grade (must be 0 ~ 100) and returns 0 if not edited (user entered -1)
int Edit_student_grade(int index, int is_adding);

