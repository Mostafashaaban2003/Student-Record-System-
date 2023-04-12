#ifndef DATA_MANAGEMENT_H
#define TYPES_H
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <ctype.h> 
	#define INITIAL_NUMBER_OF_STUDENTS 0
#endif

typedef struct student{
	char* id;
	char* name;
	char* gender;
	char* password;
	int age,total_grade;
}student;

typedef struct admin{
	char* password;
}admin;

//Array of students.
student* students;

//Stores the index of the logged-in admin's ID in the student* students array. 
int my_id_index;

//number of maximum students can fit without allocating. (The size of the array).
int number_of_students;

//load data from students.txt to student* students
void load_data();

//accepts data
char* takestring_v2();

//choose number from 1 to n
int Choose_Number(int n);

//asks the admin repeatidly to enter a correct id , search it and returns its index
int get_id();

//searches for a specified id and returns the index of it and if not found returns -1
int search_id(char* id);

//returns the index of the first unoccupied space in the array
int get_first_free_index();

//encrypt student password
void encrypt(char* origin);

//decrypt student password
void decrypt(char* encrypted);

//asking if admin wants to save data
void ask_to_save();
	
//save data from student* students to students.txt.
void save_data();

int Is_valid_id(char * id);

int take_valid_age();