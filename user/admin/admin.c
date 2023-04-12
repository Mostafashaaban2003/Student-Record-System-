#include "admin.h"

char* admin_password = "1234";

int check_admin_password()
{

	char* entered_password;
	int tries = MAX_TRIES;
	do
	{
		printf("\nEnter Your Password: ");
		entered_password = takestring_v2();
	}while(strcmp(admin_password,entered_password) && printf("INVALID PASSWORD.\nYou Have %d More Tries.\n",--tries) && tries);
	if(tries) return 1;
	else return 0;
}


void add_student()
{
	
	// check that id is unique
	char* entered_id;
	do
	{
		printf("\nEnter The Id, Or -1 To Return To the Previous Screen: ");
		entered_id = takestring_v2();
		if(!strcmp(entered_id,"-1")) return;
	}while(search_id(entered_id) != -1 && printf("\nId Found.\n"
												 "Please Make Sure That The Id Is Unique!\n"));
			
	//get the index of a free location
	int index = get_first_free_index();
	if(index == number_of_students)
	{
        if (number_of_students == 0) 
	    {
            students = (student*)malloc(sizeof(student));
        }
        else 
	    {
            students = (student*)realloc(students, sizeof(student) * (number_of_students + 1));
        }
		++number_of_students;
	}
	
	//store data
	students[index].id = entered_id;
	printf("Enter The Password: ");
    students[index].password = takestring_v2();
    printf("Enter The Name: ");
    students[index].name = takestring_v2();
	
	//validating gender
    printf("Enter The Gender: \n"
			"1. Male\n"
			"2. Female\n");
	int gender = Choose_Number(GENDERS);	
	if(gender == 1) students[index].gender = "male";
	else students[index].gender = "female";
	
    printf("Enter The Age: ");
    scanf("%d", &students[index].age);
	
	Edit_student_grade(index);
		
	//encrypting password when storing
	//encrypt(students[index].password);
	
	printf("\nStudent Added Successfully!\n");
			
	//asking admin if he wants to save data
	ask_to_save();
	
	//asking if admin wants to add more students
	printf("\nDo You Want To Add More Students?\n"
			"Enter 'Y' For \"Yes\", 'N' For \"No\": ");
	fflush(stdin);	   
	char again;
	scanf("%c",&again); fflush(stdin);
	again = tolower(again);
	if(again == 'y') return add_student();
	else return;					

}

void Remove_student_record()
{
	int index = get_id();
	
	//if the user wants to get to the previous screen
	if(index == -1) return;
	
	//freeing data
	free(students[index].id);
	students[index].id = NULL;
	free(students[index].password);
	students[index].password = NULL;
	free(students[index].name);
	students[index].name = NULL;
	free(students[index].gender);
	students[index].gender = NULL;
	students[index].age = -1;
	students[index].total_grade = -1;
	
	printf("\nStudent Removed Successfully!\n");
	
	//asking admin if he wants to save data
	ask_to_save();
	
	//asking if admin wants to remove more students
	printf("\nDo You Want To Remove More Students?\n"
			"Enter 'Y' For \"Yes\", 'N' For \"No\": ");		
	fflush(stdin);	   
	char again;
	scanf("%c",&again); fflush(stdin);
	again = tolower(again);
	if(again == 'y') return Remove_student_record();
	else return;
}

void View_all_records()
{
	for(int i = 0; i < number_of_students; i++)
	{
		//skip removed students
		if(students[i].id == NULL)
		{
			continue;
		}
		printf("\nStudent %d: \n", i + 1);
		printf("Name: %s\n", students[i].name);
		printf("ID: %s\n", students[i].id);
		printf("Gender: %s\n", students[i].gender);
		printf("Age: %d\n", students[i].age);
		printf("Total Grade: %d\n", students[i].total_grade);	
	}
}
	
void Edit_admin_password()
{
	char *entered_password;
	int tries = MAX_TRIES;
	do
	{
		printf("Enter Old Password, Or -1 To Return To the Previous Screen: ");
		entered_password = takestring_v2();
		if(!strcmp(entered_password,"-1")) return;
	}while(strcmp(admin_password,entered_password) && printf("INVALID PASSWORD.\n"
															 "You Have %d More Tries.\n",--tries) && tries);
	if(tries)
	{
		printf("Enter New Password: ");
		entered_password = takestring_v2();
		free(admin_password);
		admin_password = entered_password;
		printf("\nPassword Changed Successfully!\n");
		return;
	}	
	printf("\nPassword Not Changed!\n");
	return;
}

void Edit_student_grade(int index)
{
	
	//if the user wants to get to the previous screen
	if(index == -1) return;
	do 
	{	
		printf("Please Enter the new student's grade from 0~100: ");
		char* temp = takestring_v2();
		students[index].total_grade = atoi(temp);
		free(temp);
		temp = NULL;
		if(students[index].total_grade == -1) return ;
	}while(!(students[index].total_grade >= 0 && students[index].total_grade <= MAXIMUM_GRADE ) && printf("INVALID Grade!\n" ));
	printf("\nGrade Added Successfully!\n");
	
}
	