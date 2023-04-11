#ifndef TYPES_H
#define TYPES_H
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <ctype.h> 
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

char* takestring_v2();