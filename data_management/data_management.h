#ifndef DATA_MANAGEMENT_H
#define TYPES_H
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <ctype.h> 
	#define INITIAL_NUMBER_OF_STUDENTS 0
	#define BUFFER_SIZE 1000
	#define MAX_INT_LENGTH 10
	#define MAX_ID_LENGTH 14
	#define MINIMUM_STUDENT_AGE 7
	#define MAXIMUM_STUDENT_AGE 20
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

//accepts data from user as string
char* takestring_v2();

//converts string to integer and if the string isn't a number it returns -1 
int string_to_int(char* string_num);

//choose number from 1 to n
int Choose_Number(int n);

//checks if id is valid (length less than 14 and doen't have characters), returns 0 if not valid.
int Is_valid_id(char * id);

//checks if age is valid (age more than 7 and less than 20 and doen't have characters), returns 0 if not valid.
int take_valid_age();

//checks if name is valid (consists of characters only), returns null if not valid.
char* take_valid_name();

//searches for a specified id and returns the index of it and if not found returns -1
int search_id(char* id);

//asks the admin repeatidly to enter a correct id , search it and returns its index
int get_id();

//returns the index of the first unoccupied space in the array
int get_first_free_index();

//encrypt student password
void encrypt(char* origin);

//returns the decryption of a student password
char* decrypt(char* encrypted);

//asking if admin wants to save data
void ask_to_save();
	
//save data from student* students to students.txt.
void save_data();


