#ifndef ADMIN_H
#define ADMIN_H
	#include "..\.\student\student.h"
	#include "..\..\.\types\types.h"
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
#endif
void add_student();
int search_id(int id);
int check_admin_password();
int Edit_admin_password();
int Remove_student_record();
void initialize_students();
char* admin_password;