#ifndef INTERFACE_H
#define INTERFACE_H
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include <ctype.h>
	#include <stdbool.h>
	#include "..\.\user\student\student.h"
	#include "..\.\user\admin\admin.h"
	#define NUMBER_OF_MODES 2
    #define NUMBER_OF_ADMIN_PRIVILEGES 6
    #define NUMBER_OF_USER_PRIVILEGES 3
#endif
void system_init();
int Choose_Mode();