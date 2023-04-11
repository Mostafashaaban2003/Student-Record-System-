#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <ctype.h> 
	#include "..\..\.\types\types.h"
#endif
void View_student_record();
int check_id();
int search_id(char* id);
int number_of_students;
//void Edit your password();
//void Edit your name();
student* students;
