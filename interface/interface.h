#ifndef INTERFACE_H
#define INTERFACE_H
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include <ctype.h>
	#include <stdbool.h>
	#include "..\.\user\student\student.h"
	#include "..\.\user\admin\admin.h"
<<<<<<< HEAD
	#define NUMBER_OF_MODES 2
    #define NUMBER_OF_ADMIN_PRIVILEGES 6
    #define NUMBER_OF_USER_PRIVILEGES 3
=======
        #define NUMBER_OF_MODES 2
        #define NUMBER_OF_ADMIN_PRIVILEGES 6
        #define NUMBER_OF_USER_PRIVILEGES 3
>>>>>>> 2c4b5189ebd045a2e4f85e8cf1fe64dad930eb94
#endif
void system_init();
int Choose_Mode();
