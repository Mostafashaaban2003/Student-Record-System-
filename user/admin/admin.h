#ifndef ADMIN_H
#define ADMIN_H
	#include "..\.\student\student.h"
	#include "..\..\.\types\types.h"
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <ctype.h> 

#endif
void add_student();
int check_available();
int search_id(char* id);
int check_admin_password();
int Edit_admin_password();
int Remove_student_record();
void encrypt(char* origin);
void decrypt(char* encrypted);
void load_data();
void save_data();
char* admin_password;
student* students;
int number_of_students;
