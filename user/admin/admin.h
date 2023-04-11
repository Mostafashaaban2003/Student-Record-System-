#ifndef ADMIN_H
#define ADMIN_H
	#include "..\.\student\student.h"
	

#endif
void add_student();
int check_available();


int check_admin_password();
int Edit_admin_password();
int Remove_student_record();
void encrypt(char* origin);
void decrypt(char* encrypted);
void load_data();
void save_data();
void View_all_records();
void Edit_student_grade();
char* admin_password;


