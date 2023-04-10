#include "interface.h"
void system_init()
{
	load_data();
    printf("\n\n"
    "\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="
    "\n\t\t\t        =                  WELCOME                  ="
    "\n\t\t\t        =                    TO                     ="
    "\n\t\t\t        =                EL-GELBAB'S                ="
    "\n\t\t\t        =               Student Record              ="
    "\n\t\t\t        =                 MANAGEMENT                ="
    "\n\t\t\t        =                   SYSTEM                  ="
    "\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="
    "\n\n");
    printf("Please Enter Your Choice:-\n"
           "1. Admin\n"
		   "2. Student\n");
    
    int choice = Choose_Mode(NUMBER_OF_MODES);
	switch(choice)
    {
		case 1:
            if(check_admin_password())
            {
            choose_method:    
				printf("\nChoose any of these privileges: \n");
                printf("1. Add student record\n");
                printf("2. Remove student record\n");
                printf("3. View student record\n");
                printf("4. View all records\n");
                printf("5. Edit admin password\n");
                printf("6. Edit student grade\n");
                choice = Choose_Mode(NUMBER_OF_ADMIN_PRIVILEGES);
                switch(choice)
                {
                    case 1: add_student(); break;
                    case 2: Remove_student_record(); break;
                    //case 3: View_student_record(); break;
                    //case 4: View_all_records(); break;
                    case 5:
						if(Edit_admin_password()) break;
						else{
							printf("\nINVALID.\nLoging Out....");
							system_init();
							return;
						}	
                    //case 6: Edit_student_grade; break;
                }
				printf("\n\nDo you Want to Exit Program?\n"
					   "Enter 'Y' For \"Yes\", 'N' For \"No\": ");
				fflush(stdin);	   
				char exit;
				scanf("%c",&exit); fflush(stdin);
				exit = tolower(exit);
				if(exit == 'n') goto choose_method;
				else return;		   
            }
            else
            {
                exit(1);
            }
			break;
		case 2:
			if (/*check_student()*/1)
            {
                printf
                (
                "Choose any of these privileges: \n"
                "1. View your record.\n"
                "2. Edit your password.\n"
                "3. Edit your name\n"
                );
                choice = Choose_Mode(NUMBER_OF_USER_PRIVILEGES);
                switch (choice)
                {
                    //case 1: View_your_record() break;
                    //case 2: Edit your password() break;
                    //case 3: Edit your name() break;
                }
            }
            else
            {
                exit(1);
            }
			break;
	}

}

int Choose_Mode(int n){
    int choice;
    do
    {
        scanf("%d",&choice);

    }while(!(choice >= 1 && choice <= n)&& printf("Invalid choice!\n"
                                                  "please enter number between 1~%d", n));
    
	return choice;
}