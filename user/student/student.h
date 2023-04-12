#ifndef STUDENT_H
#define STUDENT_H
	#include "..\..\.\types\types.h"
	#define INITIAL_NUMBER_OF_STUDENTS 0
	#define MAX_TRIES 3
#endif

//number of maximum students can fit without allocating. (The size of the array).
int number_of_students;


//searches for a specified id and returns the index of it and if not found returns -1
int search_id(char* id);

//asks the user repeatidly to enter a correct id , search it and returns its index
int check_id();

//prints a student data and takes the index as argument 
void View_student_record(int index);

void Edit_your_name();

int Edit_student_Password();

int check_student();

//encrypt student password
void encrypt(char* origin);

//decrypt student password
void decrypt(char* encrypted);

//asking if admin wants to save data
void ask_to_save();
	
//save data from student* students to students.txt.
void save_data();

int my_id_index;

student* students;