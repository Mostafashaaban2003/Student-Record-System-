#include "interface.h"
void system_init()
{
	//initialize_students();
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
    
    int choice = Choose_Mode();
	switch(choice)
    {
		case 1:
            if(check_admin_password())
            {
                printf("Choose any of these privileges: \n");
                printf("1. Add student record\n");
                printf("2. Remove student record\n");
                printf("3. View student record\n");
                printf("4. View all records\n");
                printf("5. Edit admin password\n");
                printf("6. Edit student grade\n");
                choice = Choose_Mode(6);
                switch(choice)
                {
                    case 1: add_student(); break;
                    case 2: Remove_student_record(); break;
                    //case 3: View_student_record(); break;
                    //case 4: View_all_records(); break;
                    case 5:
						if(Edit_admin_password()) break;
						else{
							printf("INVALID\n");
							system_init();
							return;
						}	
                    //case 6: Edit_student_grade; break;
                }
            }
            else
            {
                exit(1);
            }
			break;
		case 2:

			break;
	}

}
int Choose_Mode(int n){
    int choice;
    do
    {
        scanf("%d",&choice);

    }while(!(choice >= 1 && choice <= n)&& printf("Invalid choice. \nplease enter number between 1~%d", n));
    
	return choice;
}