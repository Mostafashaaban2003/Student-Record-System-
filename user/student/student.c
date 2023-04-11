#include "student.h"
student* students;
int number_of_students = 0;
void View_student_record()
{
	int index = check_id();	
	printf("Name: %s\n", students[index].name);
    printf("ID: %s\n", students[index].id);
	printf("Gender: %s\n", students[index].gender);
    printf("Age: %d\n", students[index].age);
    printf("Total Grade: %d\n", students[index].total_grade);		
}	
int check_id()
{
	char *entered_id;
	int index;
	printf("Please Enter Student's ID: ");
	do 
	{
	entered_id = takestring_v2();
	index = search_id(entered_id);
	}while(index == -1 && printf("INVALID ID Please enter correct ID: "));
	return index;
}
int search_id(char* id) 
{
    for (int i = 0; i < number_of_students; i++)
		{
        if (students[i].id != NULL && !strcmp(students[i].id, id)) 
		{
            return i;
        }
    }
    return -1;
}
            			
	
	
	