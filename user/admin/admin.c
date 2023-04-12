#include "admin.h"

char* admin_password = "1234";

int check_admin_password()
{
	printf ("\n----------------( If you want To return To Login Screen At any Time Enter \"-1\" )----------------\n");

	char* entered_password;
	int tries = MAX_TRIES;
	do
	{
		printf("\nEnter Your Password: ");
		entered_password = takestring_v2();
		if(!strcmp("-1",entered_password)) return -1;
	}while(strcmp(admin_password,entered_password) && printf("INVALID PASSWORD.\nYou Have %d More Tries.\n",--tries) && tries);
	if(tries) return 1;
	else return 0;
}


void add_student()
{
	
	printf ("\n----------------( If you want To return To Methods Screen At any Time Enter \"-1\" )----------------\n");
	
	// check that id is unique
	char* entered_id;
	int is_valid;
	do
	{
		printf("\nEnter The Id: ");
		entered_id = takestring_v2();
		if(!strcmp(entered_id,"-1")) return;
		is_valid = Is_valid_id(entered_id);
		if(!is_valid) printf("\nID Is Not Valid. \nPlease Don't Enter Spaces And Make Sure That Length Is Between 1~14\n");
	
	}while( !is_valid || (search_id(entered_id) != -1 && printf("\nId Found.\n"
												 "Please Make Sure That The Id Is Unique!\n")));
			
	//get the index of a free location
	int index = get_first_free_index();
	
	//allocating size
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
	
	//////////////
	//store data//
	//////////////
	students[index].id = entered_id;	
    printf("Enter The Name: ");
    students[index].name = takestring_v2();
	if(!strcmp(students[index].name,"-1")){
		students[index].id = NULL;
		return;
	}	
	printf("Enter The Password: ");
    students[index].password = takestring_v2();
		if(!strcmp(students[index].password,"-1")){
		students[index].id = NULL;
		return;
	}	
	
	//validating gender
    printf("Enter The Gender \n"
			"Enter 1 For \"Male\" And Anything Else For \"Female:\"\n");
	char* gender =  takestring_v2();	
	if(!strcmp(gender,"1")) students[index].gender = "male";
	else if(!strcmp(gender,"-1")){
		students[index].id = NULL;
		return;
	}		
	else students[index].gender = "female";
	
	
	int age = take_valid_age();
	if(age == -1){
		students[index].id = NULL;
		return;
	}
	students[index].age = age;
		
	
	if(!Edit_student_grade(index, ADDING)){
		students[index].id = NULL;
		return;
	}
	
		
	//encrypting password when storing
	encrypt(students[index].password);
	
	printf("\nStudent Added Successfully!\n");
			
	//asking admin if he wants to save data
	ask_to_save();
	
	//asking if admin wants to add more students
	printf("\nDo You Want To Add More Students?\n"
			"Enter 'Y' For \"Yes\" ِAnd Anything Else For \"No\": ");
	fflush(stdin);	   
	char again;
	scanf("%c",&again); fflush(stdin);
	again = tolower(again);
	if(again == 'y') return add_student();
	else return;					

}

void Remove_student_record(int index)
{
	
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
			"Enter 'Y' For \"Yes\" ِAnd Anything Else For \"No\": ");
	fflush(stdin);	   
	char again;
	scanf("%c",&again); fflush(stdin);
	again = tolower(again);
	if(again == 'y') return Remove_student_record(get_id());
	else return;
}

void View_all_records()
{
	int printed = 0;
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
		printed++;		
	}
	if(!printed) printf("\nThere Are No Students To Print!\n");
}
	
void Edit_admin_password()
{
	char *entered_password;
	int tries = MAX_TRIES;
	printf ("\n----------------( If you want To return To Methods Screen At any Time Enter \"-1\" )----------------\n");
	do
	{
		printf("Enter Old Password: ");
		entered_password = takestring_v2();
		if(!strcmp(entered_password,"-1")) return;
	}while(strcmp(admin_password,entered_password) && printf("INVALID PASSWORD.\n"
															 "You Have %d More Tries.\n",--tries) && tries);
	if(tries)
	{
		printf("Enter New Password: ");
		entered_password = takestring_v2();
		if(!strcmp(entered_password,"-1")) return;
		free(admin_password);
		admin_password = entered_password;
		printf("\nPassword Changed Successfully!\n");
		return;
	}	
	printf("\nPassword Not Changed!\n");
	return;
}

int Edit_student_grade(int index, int is_adding)
{
	
	//if the user wants to get to the previous screen
	char* temp_string = NULL;
	if(index == -1) return 0;
	int temp_grade = students[index].total_grade;
	do 
	{	
		printf("Please Enter the new student's grade from 0~100: ");
		temp_string = takestring_v2();
		students[index].total_grade = atoi(temp_string);
		if(!strcmp(temp_string,"-1")){
			students[index].total_grade = temp_grade;
			return 0;
		}	
	}while(((students[index].total_grade == 0 && *temp_string != '0' ) || !(students[index].total_grade >= 0 && students[index].total_grade <= MAXIMUM_GRADE ) )&& printf("INVALID Grade!\n" ));
	free(temp_string);
	temp_string = NULL;
	printf("\nGrade Added Successfully!\n");
	
	// if the admin isn't adding students and just editing thuer grades
	if(!is_adding){
		//asking if admin wants to Change more students Degrees
		printf("\nDo You Want To Change More Students Grades?\n"
			"Enter 'Y' For \" Yes \" And Anything Else For \"No\": ");
		fflush(stdin);	   
		char again;
		scanf("%c",&again); fflush(stdin);
		again = tolower(again);
		if(again == 'y') return Edit_student_grade(get_id(),ADMIN);
		else return 1;
	}
	return 1;
	
}
	