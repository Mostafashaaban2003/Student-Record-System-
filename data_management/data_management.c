#include "data_management.h"

student* students;

int my_id_index;

int number_of_students = INITIAL_NUMBER_OF_STUDENTS;

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
		students[i].id = (char*) malloc(strlen(buffer) + 1);
        sscanf(buffer, "%s", students[i].id);
        fgets(buffer, 1000, fp);
		students[i].name = (char*) malloc(strlen(buffer) + 1);		
        sscanf(buffer, "%s", students[i].name);
        fgets(buffer, 1000, fp);
		students[i].gender = (char*) malloc(strlen(buffer) + 1);		
        sscanf(buffer, "%s", students[i].gender);
        fgets(buffer, 1000, fp);
		students[i].password = (char*) malloc(strlen(buffer) + 1);		
        sscanf(buffer, "%s", students[i].password);
        fgets(buffer, 1000, fp);
        sscanf(buffer, "%d", &students[i].age);
        fgets(buffer, 1000, fp);
        sscanf(buffer, "%d", &students[i].total_grade);
    }

    fclose(fp); // Close file
    printf("loaded %d students from file successfully!\n",number_of_students);

    return;
}

char* takestring_v2(){
    char* s = (char *)calloc(1,sizeof(char));
    int len = 1;
    *s = '\0';
    char t;
    t = getchar();
    int c = 1;
    while(t != '\n'){
        if(c == len)
        {
            s = (char *)realloc(s, (2 * len) * sizeof(char));
            len = 2 * len;
        }
        *(s + c - 1) = t;
        *(s + c) = '\0';
        c++;
        t = getchar();
    }
	fflush(stdin);
	if(len == 1)  return takestring_v2();
	if(*s == ' ') {
		printf("");
		return takestring_v2();
	}

    return s;
}

int Choose_Number(int n){
    int choice;
    do
    {
		char* temp = takestring_v2();
		
		//converting string to intger
		choice = atoi(temp);
		
		//freeing pointer
		free(temp);
		temp = NULL;
    }while(!(choice >= 1 && choice <= n)&& printf("Invalid choice!\n"
                                                  "please enter number between 1~%d: ", n));
	return choice;
}	

int get_id()
{
	char *entered_id;
	int index;
	printf("Please Enter Student's ID, Or -1 To Return To the Previous Screen: ");
	do 
	{
		entered_id = takestring_v2();
		//return -1 when entering -1
		if(!strcmp(entered_id,"-1")) return -1;
		index = search_id(entered_id);
	}while(index == -1 && printf("INVALID ID Please enter correct ID: "));
	return index;
}

int get_first_free_index()
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

void encrypt(char* origin){
    int cipher[96] = {45, 106, 92, 117, 66, 82, 78, 81, 61, 71, 122, 57, 55, 89, 58, 41, 96, 33, 60, 34, 48, 119, 102, 67, 94, 80, 118, 51, 87, 69, 56, 65, 110, 44, 68, 43, 123, 124, 85, 126, 49, 84, 97, 112, 50, 72, 127, 76, 37, 100, 107, 91, 95, 114, 63, 39, 47, 40, 35, 54, 116, 59, 77, 99, 52, 74, 111, 53, 38, 46, 93, 125, 88, 90, 121, 73, 108, 83, 42, 79, 62, 120, 109, 36, 64, 104, 86, 113, 115, 101, 70, 98, 32, 105, 103, 75 };

	for(int i = 0;i < strlen(origin);i++)
	{
		origin[i] = cipher[origin[i] - 32];
	}
}

void decrypt(char* encrypted){
    int cipher[96] = {45, 106, 92, 117, 66, 82, 78, 81, 61, 71, 122, 57, 55, 89, 58, 41, 96, 33, 60, 34, 48, 119, 102, 67, 94, 80, 118, 51, 87, 69, 56, 65, 110, 44, 68, 43, 123, 124, 85, 126, 49, 84, 97, 112, 50, 72, 127, 76, 37, 100, 107, 91, 95, 114, 63, 39, 47, 40, 35, 54, 116, 59, 77, 99, 52, 74, 111, 53, 38, 46, 93, 125, 88, 90, 121, 73, 108, 83, 42, 79, 62, 120, 109, 36, 64, 104, 86, 113, 115, 101, 70, 98, 32, 105, 103, 75 };
	for(int i = 0;i < strlen(encrypted);i++)
	{
		for(int j = 0; j < 256; j++){
            if(cipher[j] == encrypted[i])
			{
                encrypted[i] = j + 32;
                break;
            }
		}
	}
}
        

void ask_to_save(){
	printf("\nDo You Want To Save Data?\n"
			"Enter 'Y' For \"Yes\", 'N' For \"No\": ");
	fflush(stdin);	   
	char again;
	scanf("%c",&again); fflush(stdin);
	again = tolower(again);
	if(again == 'y') save_data();
	return;
}

// copy data from student to file.
void save_data()
{
    FILE *fp = fopen("students.txt", "w"); // Open file for writing
    if(fp == NULL)
	{
        printf("Failed to open file!\n");
        return;
    }

    for(int i = 0; i < number_of_students; i++)
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