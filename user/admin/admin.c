#include "admin.h"

char* admin_password = "1234";


void load_data()
{
    FILE *fp = fopen("students.txt", "r"); // Open file for reading

    // Count number of students in file
    int lines = 0;
    char buffer[1000];
    while (fgets(buffer, 1000, fp) != NULL) 
	{
        if (buffer[0] == '\n') continue; // Ignore blank lines
        lines++;
    }
    number_of_students = lines / 6; // Each student has 6 lines of data

    // Allocate memory for students array
    students = (student*)malloc(number_of_students * sizeof(student));
    // Read each student's data from file
    fseek(fp, 0, SEEK_SET); // Rewind file pointer to beginning
    for (int i = 0; i < number_of_students; i++) 
	{
        // Read student data from lines
        fgets(buffer, 1000, fp);
		students[i].id = (char*) malloc(50);
        sscanf(buffer, "%s", students[i].id);
        fgets(buffer, 1000, fp);
		students[i].name = (char*) malloc(50);		
        sscanf(buffer, "%s", students[i].name);
        fgets(buffer, 1000, fp);
		students[i].gender = (char*) malloc(50);		
        sscanf(buffer, "%s", students[i].gender);
        fgets(buffer, 1000, fp);
		students[i].password = (char*) malloc(50);		
        sscanf(buffer, "%s", students[i].password);
        fgets(buffer, 1000, fp);
        sscanf(buffer, "%d", &students[i].age);
        fgets(buffer, 1000, fp);
        sscanf(buffer, "%d", &students[i].total_grade);
    }

    fclose(fp); // Close file
    printf("Data loaded from file successfully! %d students\n",number_of_students);

    return;

}



// copy data from student to file*.
void save_data(student *students, int count)
{
    FILE *fp = fopen("students.txt", "w"); // Open file for writing
    if(fp == NULL)
	{
        printf("Failed to open file!\n");
        return;
    }

    for(int i=0; i<count; i++)
	{
		if(students[i].id == NULL) continue;
        // Write each student's data to file on a new line
        fprintf(fp, "%s\n%s\n%s\n%s\n%d\n%d\n",
				students[i].id, students[i].name, students[i].gender,
                students[i].password, students[i].age, students[i].total_grade);
    }

    fclose(fp); // Close file
    printf("Data saved to file successfully!\n");
}
	

void encrypt(char* origin){
	int encrypt[256] = {10, 97, 33, -67, -31, 93, -106, -15, -61, 53, -85, 59, 79, 57, 74, -99, -89, 43, -37, 15, -83, -53, 76, 111, -14, -117, 89, 31, 117, 1, 46, -84, -94, -112, -46, 50, -78, -82, -88, -34, 73, 96, -66, 6, 37, 98, -98, 100, -60, 82, -25, -125, 34, 4, 26, -27, 102, 83, -3, 109, -97, -77, 47, 125, 123, -86, 38, -47, 86, 51, 75, 42, -100, 113, 5, 80, 62, -101, -12, -79, 110, -40, -113, 119, -123, 126, -19, -107, 32, 20, -75, -39, 77, 52, 127, 85, 124, 92, -21, -2, -41, -73, -7, 108, 7, 23, 3, 27, 18, -64, -90, -74, 91, -102, 19, 48, -119, -118, -22, -11, -108, -92, -23, 78, 11, -68, -71, -8, 8, 58, -96, 2, -50, -127, -126, -105, -35, -72, -128, -56, -93, 68, -17, -4, -51, -115, 40, -57, 106, 39, 30, -103, 17, 69, -104, 21, 63, -120, 99, -114, 36, 61, 29, -62, 49, -16, -38, 0, -124, -32, 60, -58, 94, -116, 121, 115, -44, -45, 22, 103, 66, 64, 9, 116, -55, -91, 35, -28, 72, -111, -13, 104, 44, 114, -81, -1, -33, 105, 118, -36, 12, 107, 70, -6, 13, 112, -5, 81, 65, -49, -65, 41, 14, -110, 122, -30, 16, 87, -122, -10, 101, -87, 54, 56, -69, -121, -26, 55, -54, 84, -80, -43, -95, 25, 95, 24, 28, -52, 71, 67, -59, -9, -18, -70, -24, 120, -109, -76, -29, -48, -42, 45, 90, 88, -63, -20 };
	for(int i = 0;i < strlen(origin);i++)
	{
		origin[i] = encrypt[origin[i] + 128];
	}
}
void decrypt(char* encrypted){
    int encrypt[256] = {10, 97, 33, -67, -31, 93, -106, -15, -61, 53, -85, 59, 79, 57, 74, -99, -89, 43, -37, 15, -83, -53, 76, 111, -14, -117, 89, 31, 117, 1, 46, -84, -94, -112, -46, 50, -78, -82, -88, -34, 73, 96, -66, 6, 37, 98, -98, 100, -60, 82, -25, -125, 34, 4, 26, -27, 102, 83, -3, 109, -97, -77, 47, 125, 123, -86, 38, -47, 86, 51, 75, 42, -100, 113, 5, 80, 62, -101, -12, -79, 110, -40, -113, 119, -123, 126, -19, -107, 32, 20, -75, -39, 77, 52, 127, 85, 124, 92, -21, -2, -41, -73, -7, 108, 7, 23, 3, 27, 18, -64, -90, -74, 91, -102, 19, 48, -119, -118, -22, -11, -108, -92, -23, 78, 11, -68, -71, -8, 8, 58, -96, 2, -50, -127, -126, -105, -35, -72, -128, -56, -93, 68, -17, -4, -51, -115, 40, -57, 106, 39, 30, -103, 17, 69, -104, 21, 63, -120, 99, -114, 36, 61, 29, -62, 49, -16, -38, 0, -124, -32, 60, -58, 94, -116, 121, 115, -44, -45, 22, 103, 66, 64, 9, 116, -55, -91, 35, -28, 72, -111, -13, 104, 44, 114, -81, -1, -33, 105, 118, -36, 12, 107, 70, -6, 13, 112, -5, 81, 65, -49, -65, 41, 14, -110, 122, -30, 16, 87, -122, -10, 101, -87, 54, 56, -69, -121, -26, 55, -54, 84, -80, -43, -95, 25, 95, 24, 28, -52, 71, 67, -59, -9, -18, -70, -24, 120, -109, -76, -29, -48, -42, 45, 90, 88, -63, -20 };
	for(int i = 0;i < strlen(encrypted);i++)
	{
		for(int j = 0; j < 256; j++){
            if(encrypt[j] == encrypted[i]) 
			{
                encrypted[i] = j - 128;
                break;
            }
		}
	}
}



int check_available()
{
	for (int i = 0; i < number_of_students; i++) 
	{
        if (students[i].id == NULL) 
		{
            return i;
        }
    }
	return number_of_students;
}


void add_student()
{
	char* entered_id;
	do
	{
		printf("\nEnter The Id: ");
		entered_id = takestring_v2();
	}while(search_id(entered_id) != -1 && printf("\nId Found.\n"
												 "Please Make Sure That The Id Is Unique!\n"));
												 
	int index = check_available();
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
	students[index].id = entered_id;
	printf("Enter The Password: ");
    students[index].password = takestring_v2();
    printf("Enter The Name: ");
    students[index].name = takestring_v2();
    printf("Enter The Gender: ");
    students[index].gender = takestring_v2();	
    printf("Enter The Age: ");
    scanf("%d", &students[index].age);
	printf("Enter The Total Grade: ");
	scanf("%d",&students[index].total_grade);
	
	printf("\ni: %d, id : %s, password : %s, name : %s, gender : %s, age : %d, total_grade : %d",index,students[index].id, students[index].password, students[index].name, students[index].gender, students[index].age, students[index].total_grade);
	encrypt(students[index].password);
	printf("\ni: %d, id : %s, password : %s, name : %s, gender : %s, age : %d, total_grade : %d",index,students[index].id, students[index].password, students[index].name, students[index].gender, students[index].age, students[index].total_grade);
	printf("\nDo You Want To Add More Students?\n"
			"Enter 'Y' For \"Yes\", 'N' For \"No\": ");
	fflush(stdin);	   
	char again;
	scanf("%c",&again); fflush(stdin);
	again = tolower(again);
	if(again == 'y') return add_student();
	else return;					

}
	
int check_admin_password()
{

	char* entered_password;
	int tries = 3;
	do
	{
		printf("\nEnter Your Password: ");
		entered_password = takestring_v2();
	}while(strcmp(admin_password,entered_password) && printf("INVALID PASSWORD.\nYou Have %d More Tries.\n",--tries) && tries);
	if(tries) return 1;
	else return 0;
}

int Edit_admin_password()
{
	char *entered_password;
	int tries = 3;
	do
	{
		printf("Enter Old Password: ");
		entered_password = takestring_v2();
	}while(strcmp(admin_password,entered_password) && printf("INVALID PASSWORD.\n"
															 "You Have %d More Tries.\n",--tries) && tries);
	if(tries)
	{
		printf("Enter New Password: ");
		entered_password = takestring_v2();
		admin_password = entered_password;
		return 1;
	}	
	else return 0;
}

int Remove_student_record()
{
	int index = check_id();
	
	students[index].id = NULL;
	students[index].password = NULL;
	students[index].name = NULL;
	students[index].gender = NULL;
	students[index].age = -1;
	students[index].total_grade = -1;
}
void View_all_records()
{
	for(int i = 0; i < number_of_students; i++)
	{
		if(students[i].id == NULL)
		{
			continue;
		}
	printf("Student %d: \n", i+1);
	printf("Name: %s\n", students[i].name);
    printf("ID: %s\n", students[i].id);
	printf("Gender: %s\n", students[i].gender);
    printf("Age: %d\n", students[i].age);
    printf("Total Grade: %d\n", students[i].total_grade);	
	}
}
void Edit_student_grade()
{
	int index = check_id();
	do 
	{	
	printf("Enter the new student's grade from 0~100: ");
	scanf("%d", &students[index].total_grade);
	}while(!(students[index].total_grade >= 0 && students[index].total_grade <=100));
}

	
	