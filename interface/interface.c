#include "interface.h"

void system_init()
{
	load_data();
    printf("\n\n"
    "\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="
    "\n\t\t\t        =                  WELCOME                  ="
    "\n\t\t\t        =                    TO                     ="
    "\n\t\t\t        =                 EL-GELBAB'S               ="
    "\n\t\t\t        =               Student Record              ="
    "\n\t\t\t        =                 MANAGEMENT                ="
    "\n\t\t\t        =                   SYSTEM                  ="
    "\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="
    "\n\n");
	
	while(1){
		int tologin = 1;
		
		printf("\nPlease Enter Your Choice:-\n"
			   "1. Admin\n"
			   "2. Student\n");
		
		int choice = Choose_Number(NUMBER_OF_MODES);
		switch(choice)
		{
			case 1:
				if(check_admin_password()) {
					while(1){	
						printf
						(
								"\nChoose any of these privileges: \n"
								"1. Add student record\n"
								"2. Remove student record\n"
								"3. View student record\n"
								"4. View all records\n"
								"5. Edit admin password\n"
								"6. Edit student grade\n"
								"7. Logout\n"
								"8. Exit\n"
						);
						choice = Choose_Number(NUMBER_OF_ADMIN_PRIVILEGES);
						switch(choice)
						{
							case 1: add_student(); break;
							case 2: Remove_student_record(); break;
							case 3: View_student_record(check_id()); break;
							case 4: View_all_records(); break;
							case 5: Edit_admin_password(); break;
							case 6: Edit_student_grade(check_id()); break;
							case 7: tologin = 0; break;
							case 8: return;
						}
						if(!tologin) break;
					}
				}	
				else exit(1); break;
			case 2:
				if (/*check_student()*/1)
				{
					printf
					(
					"\nChoose any of these privileges: \n"
					"1. View your record.\n"
					"2. Edit your password.\n"
					"3. Edit your name\n"
					);
					choice = Choose_Number(NUMBER_OF_USER_PRIVILEGES);
					switch (choice)
					{
						//case 1: View_student_record(); break;
						//case 2: Edit your password() break;
						//case 3: Edit your name() break;
					}
				}
				else exit(1); break;
		}			
	}
	save_data();
}

