#include "admin.h"
char* admin_password = "1234";
int number_of_students = 1;
student* students;
// void initialize_students(){
	// students = (student **)malloc(number_of_students * sizeof(student));

	// FILE *fp = fopen("students.txt", "r");
	// for(int i = 0; i < number_of_students; i++){
		// students[i] = (student *)malloc(sizeof(student));
		// fgets(students[i]->id, 10, fp);
        // fgets(students[i]->password, 20, fp);
        // fgets(students[i]->name, 100, fp);
        // fgets(students[i]->gender, 7, fp);
        // fscanf(fp, "%d\n", &students[i]->age);
        // fscanf(fp, "%d\n", &students[i]->total_grade);
	// }	
    // fclose(fp);

	// for(int i = 0; i < number_of_students; i++){
		// printf("%s\n",students[i].id);
	// }	
// }	

int search_id(int id){
	return 0;
}	

void add_student(){
	int entered_id,age,total_grade;
	char* password;
	char* name;
	char* gender;
	do{
		printf("Enter The Id: ");
		scanf("%d",&entered_id);
	}while(search_id(entered_id) && printf("Id Found Please Make Sure That The Id Is Unique"));
	
	printf("Enter The Password: ");
    password = takestring_v2();
    printf("Enter The Name: ");
    name = takestring_v2();
    printf("Enter The Gender: ");
    gender = takestring_v2();	
    printf("Enter The Age: ");
    scanf("%d", &age);
	printf("Enter The Total Grade: ");
	scanf("%d",&total_grade);

	FILE *fp = fopen("students.txt","a");
	fprintf(fp,"%d\n%s\n%s\n%s\n%d\n%d\n\n",entered_id,password,name,gender,age,total_grade);
	fclose(fp);
}
	
int check_admin_password(){
	char* entered_password;
	int tries = 3;
	do{
		printf("Enter Your Password: ");
		entered_password = takestring_v2();
	}while(strcmp(admin_password,entered_password) && printf("INVALID PASSWORD.\nYou Have %d More Tries.\n",--tries) && tries);
	if(tries) return 1;
	else return 0;
}

int Edit_admin_password(){
	char *entered_password;
	int tries = 3;
	do{
		printf("Enter Old Password: ");
		entered_password = takestring_v2();
	}while(strcmp(admin_password,entered_password) && printf("INVALID PASSWORD.\nYou Have %d More Tries.\n",--tries) && tries);
	if(tries){
		printf("Enter NEW Password: ");
		entered_password = takestring_v2();
		admin_password = entered_password;
		return 1;
	}	
	else return 0;
}
int Remove_student_record(){
	
	char input_file[] = "students.txt";
    char temp_file[] = "temp.txt";
    int start_line = 1;  
    int end_line = 4; 
	
	FILE *fp_in = fopen(input_file, "r");
    FILE *fp_tmp = fopen(temp_file, "w");

	
	char buffer[1024];
    int line_num = 1;


    while (fgets(buffer, 1024, fp_in)) {
        if (line_num < start_line || line_num > end_line) {
            fputs(buffer, fp_tmp);
        }
        line_num++;
    }

    fclose(fp_in);
    fclose(fp_tmp);

    remove(input_file);
    rename(temp_file, input_file);
}