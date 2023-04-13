#include "data_management.h"

student* students;

int my_id_index;

int number_of_students = INITIAL_NUMBER_OF_STUDENTS;

void load_data()
{
    FILE *fp = fopen("students.txt", "r"); // Open file for reading

    // Count number of students in file
    int lines = 0;
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) 
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
        fgets(buffer, BUFFER_SIZE, fp);
		students[i].id = (char*) malloc(strlen(buffer) + 1);
        sscanf(buffer, "%s", students[i].id);
        fgets(buffer, BUFFER_SIZE, fp);
		students[i].name = (char*) malloc(strlen(buffer) + 1);	
		for (int j = 0; buffer[j] != '\n'; j++) {
			students[i].name[j] = buffer[j];
		}	
		students[i].name[strlen(buffer)] = '\0';
		
        fgets(buffer, BUFFER_SIZE, fp);
		students[i].gender = (char*) malloc(strlen(buffer) + 1);		
        sscanf(buffer, "%s", students[i].gender);
        fgets(buffer, BUFFER_SIZE, fp);
		students[i].password = (char*) malloc(strlen(buffer) + 1);		
        sscanf(buffer, "%s", students[i].password);
        fgets(buffer, BUFFER_SIZE, fp);
        sscanf(buffer, "%d", &students[i].age);
        fgets(buffer, BUFFER_SIZE, fp);
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
		printf("Cannot Start With Spaces!\nEnter Again: ");
		return takestring_v2();
	}

    return s;
}

int string_to_int(char* string_num){
	if(strlen(string_num) > MAX_INT_LENGTH) return -1;
	int num = 0;
	for(int i = 0; i < strlen(string_num); i++)
	{
		if(!isdigit(string_num[i])) return -1;
		num *= 10;
		num += string_num[i] - '0';
	}	
	return num;
}


//gets number from 1 to n
int Choose_Number(int n){
    int choice;
    do
    {
		char* temp = takestring_v2();
		
		//converting string to intger
		choice = string_to_int(temp);
		
		//freeing pointer
		free(temp);
		temp = NULL;
    }while(!(choice >= 1 && choice <= n)&& printf("\nInvalid choice!\n"
                                                  "please enter number between 1~%d: ", n));
	return choice;
}	


int Is_valid_id(char * id){
	if(strlen(id) > MAX_ID_LENGTH) return 0;
	for(int i = 0; i < strlen(id); i++){
		if(!isdigit(id[i]))return 0;
	}
	return 1;
}

int take_valid_age(){
	char * string_age = NULL;
	int age, valid;
	do{
		printf("\nEnter The Age: ");
		string_age = takestring_v2();
		if(!strcmp(string_age,"-1")) return -1;	
		age = string_to_int(string_age);
	}while(!(age >= MINIMUM_STUDENT_AGE && age <= MAXIMUM_STUDENT_AGE) && printf("\nInvalid Age! \nPlease Enter Age Between 7~20\n"));
	 
	return age;
}

char* take_valid_name(){
	int valid;
	char * entered_name = NULL;
	printf("\n");
	do{
		valid = 1;
		printf("Enter The Name: ");
		entered_name = takestring_v2();
		if(!strcmp(entered_name,"-1")) return NULL;
		for(int i = 0; i < strlen(entered_name); i++)
		{
			if(!isalpha(entered_name[i]) && !isspace(entered_name[i]))
			{
				valid = 0;
				break;
			}
		}	
	}while(!valid && printf("\nName should be characters only\n"));
	return entered_name;
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

int get_id()
{
	char *entered_id = NULL;
	int index;
	printf ("\n----------------( If you want To return To Methods Screen At any Time Enter \"-1\" )----------------\n");
	printf("Please Enter Student's ID: ");
	do 
	{
		entered_id = takestring_v2();
		//return -1 when enter -1
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

void encrypt(char* origin){
    int cipher[96] = {45, 106, 92, 117, 66, 82, 78, 81, 61, 71, 122, 57, 55, 89, 58, 41, 96, 33, 60, 34, 48, 119, 102, 67, 94, 80, 118, 51, 87, 69, 56, 65, 110, 44, 68, 43, 123, 124, 85, 126, 49, 84, 97, 112, 50, 72, 127, 76, 37, 100, 107, 91, 95, 114, 63, 39, 47, 40, 35, 54, 116, 59, 77, 99, 52, 74, 111, 53, 38, 46, 93, 125, 88, 90, 121, 73, 108, 83, 42, 79, 62, 120, 109, 36, 64, 104, 86, 113, 115, 101, 70, 98, 32, 105, 103, 75 };

	for(int i = 0;i < strlen(origin);i++)
	{
		origin[i] = cipher[origin[i] - 32];
	}
}

char* decrypt(char* encrypted){
	char* decrypted = (char *)malloc(strlen(encrypted) + 1);
    int cipher[96] = {45, 106, 92, 117, 66, 82, 78, 81, 61, 71, 122, 57, 55, 89, 58, 41, 96, 33, 60, 34, 48, 119, 102, 67, 94, 80, 118, 51, 87, 69, 56, 65, 110, 44, 68, 43, 123, 124, 85, 126, 49, 84, 97, 112, 50, 72, 127, 76, 37, 100, 107, 91, 95, 114, 63, 39, 47, 40, 35, 54, 116, 59, 77, 99, 52, 74, 111, 53, 38, 46, 93, 125, 88, 90, 121, 73, 108, 83, 42, 79, 62, 120, 109, 36, 64, 104, 86, 113, 115, 101, 70, 98, 32, 105, 103, 75 };
	for(int i = 0;i < strlen(encrypted);i++)
	{
		for(int j = 0; j < 256; j++){
            if(cipher[j] == encrypted[i])
			{
                decrypted[i] = j + 32;
                break;
            }
		}
	}
	decrypted[strlen(encrypted)] = '\0';
	return decrypted;
}
        
void ask_to_save(){
	printf("\nDo You Want To Save Data To File?\n"
			"Enter 'Y' For \"Yes\" And Anything Else For \"No\": ");
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

