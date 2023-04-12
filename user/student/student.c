#include "student.h"

int check_student_password(){
	char *entered_id, *entered_password;
	
	int index, tries = MAX_TRIES;
	do 
	{
		printf("Please Your ID: ");
		entered_id = takestring_v2();
		
		printf("Please Your Password: ");
		entered_password = takestring_v2();
		index = search_id(entered_id);
		encrypt(entered_password);
		//printf("%s\n%s\n",entered_password,students[index].password);
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
	if(index == -1) return;
	printf("Name: %s\n", students[index].name);
    printf("ID: %s\n", students[index].id);
	printf("Gender: %s\n", students[index].gender);
    printf("Age: %d\n", students[index].age);
    printf("Total Grade: %d\n", students[index].total_grade);
	if(is_admin){
		//asking if admin wants to view more students
		printf("\nDo You Want To View More Students?\n"
				"Enter 'Y' For \"Yes\", 'N' For \"No\": ");		
		fflush(stdin);	   
		char again;
		scanf("%c",&again); fflush(stdin);
		again = tolower(again);
		if(again == 'y') return View_student_record(get_id(),ADMIN);
		else return;
	}
}	


int Edit_student_Password() {
    char *entered_password;
    int tries = MAX_TRIES;
    do {
        printf ("Enter old password: ");
        entered_password = takestring_v2();
    }while(strcmp(students[my_id_index].password,entered_password)&&  printf("Invalid password.\n " "you have %d tries.\n",--tries)&&tries);
    if (tries){
        printf ("Enter New password: ");
        entered_password = takestring_v2();
        students[my_id_index].password = entered_password;
		printf("Password Edited Successfully \n");
		ask_to_save();
        return 1;
    }
	return 0;
}	

void Edit_your_name() {
	char* entered_id;
	int tries = MAX_TRIES;
	do{
		printf("Enter Your Id: ");	
		entered_id = takestring_v2();
	}while(strcmp(entered_id,students[my_id_index].id) && printf("Invalid ID.\n" "you have %d tries.\n",--tries) && tries);	
	
	//if the user wants to get to the previous screen
	if(tries){
		printf("Enter the new name : ");	
		char* entered_name = takestring_v2();
		students[my_id_index].name = entered_name;
		printf("Name Edited Successfully \n");
		ask_to_save();
		return;
	}
	printf("Failed To Edit Name!\n");
}



