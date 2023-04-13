#include "student.h"

int check_student_password(){
	char *entered_id = NULL, *entered_password = NULL;
	
	printf ("\n======================================> ADMIN LOGIN SCREEN <====================================== \n");	
	printf ("\n----------------(       If you Forgot The password At any Time Enter \"f\"       )----------------\n");
	printf (  "----------------( If you want To return To Login Screen At any Time Enter \"-1\" )----------------\n");

	int index, tries = MAX_TRIES;
	do 
	{
		printf("Please Your ID: ");
		entered_id = takestring_v2();
		
		// if user entered f then go to forrgot password screen
		if(!strcmp("f",entered_id) || !strcmp("F",entered_id)){
			forgot_my_password();
			return check_student_password();
		}		
		//if User entered - 1 return to Previous screen
		if(!strcmp("-1",entered_id)) return -1;
		
		printf("Please Your Password: ");
		entered_password = takestring_v2();
		
		// if user entered f then go to forrgot password screen
		if(!strcmp("f",entered_password) || !strcmp("F",entered_password)) {
			forgot_my_password();
			return check_student_password();
		}	
		//if User entered - 1 return to Previous screen		
		if(!strcmp("-1",entered_password)) return -1;
		index = search_id(entered_id);
		encrypt(entered_password);
	}while((index == -1 || strcmp(students[index].password,entered_password))&& printf("INVALID Login!.\nYou Have %d More Tries.\n",--tries) && tries);
	if(tries){
		printf("\nLogin Successfully!\n");
		my_id_index = index;
		return 1;
	}	
	return 0;
}

void View_student_record(int index, int is_admin)
{
	//if User entered - 1 return to Previous screen		
	if(index == -1) return;
	printf("\nName: %s\n", students[index].name);
    printf("ID: %s\n", students[index].id);
	printf("Gender: %s\n", students[index].gender);
    printf("Age: %d\n", students[index].age);
    printf("Total Grade: %d\n", students[index].total_grade);
	if(is_admin){
		//asking if admin wants to view more students
		printf("\nDo You Want To View More Students?\n"
			"Enter 'Y' For \"Yes\" And Anything Else For \"No\": ");
		fflush(stdin);	   
		char again;
		scanf("%c",&again); fflush(stdin);
		again = tolower(again);
		if(again == 'y') return View_student_record(get_id(),ADMIN);
		else return;
	}
}	


int Edit_student_Password() {
    char *entered_password = NULL;
    int tries = MAX_TRIES;
	printf ("\n----------------( If you want To return To Login Screen At any Time Enter \"-1\" )----------------\n");
    do {
        printf ("Enter old password: ");
        entered_password = takestring_v2();
		if(!strcmp(entered_password,"-1")) return 0;
		encrypt(entered_password);
    }while(strcmp(students[my_id_index].password,entered_password)&&  printf("Invalid password.\n" "you have %d tries.\n",--tries)&&tries);
    if (tries){
        printf ("Enter New password: ");
        entered_password = takestring_v2();
		if(!strcmp(entered_password,"-1")) return 0;
		encrypt(entered_password);
        students[my_id_index].password = entered_password;
		printf("Password Edited Successfully \n");
		ask_to_save();
        return 1;
    }
	return 0;
}	

void Edit_your_name() {
	char * entered_name;
	
	printf ("\n----------------( If you want To return To Login Screen At any Time Enter \"-1\" )----------------\n");

	printf("\nPlease Make Sure That Your New Name Only Consists Of Characters.\n");	
	entered_name = take_valid_name();
	
	//if the user wants to get to the previous screen
	if(entered_name == NULL) return;
	students[my_id_index].name = entered_name;
	printf("Name Edited Successfully \n");
	ask_to_save();
	return;
}

void forgot_my_password(){
	char* entered_id = NULL;
	char* entered_name = NULL;
 	printf ("\n----------------( If you want To return To Login Screen At any Time Enter \"-1\" )----------------\n");
	printf("Please Your ID: ");
	entered_id = takestring_v2();
	printf("Please Your Name: ");
	entered_name = takestring_v2();
	
	int index = search_id(entered_id);
	if(index == -1 || strcmp(entered_name,students[index].name)) return;
	printf("Your Password is %s",decrypt(students[index].password));
}	



