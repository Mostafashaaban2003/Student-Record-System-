#include "admin.h"

student* students;

char* admin_password = "1234";
int number_of_students = 0;

void load_data(){
// copy data from file to student*.	
}	

void save_data(){
// copy data from file to student*.	
}	

void encrypt(char* origin){
	for(int i = 0;i < strlen(origin);i++){
		origin[i] += 5; 
	}	
}

int search_id(char* id) {
    for (int i = 0; i < number_of_students; i++) {
        if (students[i].id != NULL && !strcmp(students[i].id, id)) {
            return i;
        }
    }
    return -1;
}

int check_availabe(){
	for (int i = 0; i < number_of_students; i++) {
        if (students[i].id == NULL) {
            return i;
        }
    }
	return number_of_students;
}


void add_student(){

	int index = check_availabe();
	if(index == number_of_students){
        if (number_of_students == 0) {
            students = (student*)malloc(sizeof(student));
        }
        else {
            students = (student*)realloc(students, sizeof(student) * (number_of_students + 1));
        }
		++number_of_students;
	}
	
	char* entered_id;
	do{
		printf("\nEnter The Id: ");
		entered_id = takestring_v2();
	}while(search_id(entered_id) != -1 && printf("\nId Found.\n"
												 "Please Make Sure That The Id Is Unique!\n"));
	
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
	
int check_admin_password(){
	char* entered_password;
	int tries = 3;
	do{
		printf("\nEnter Your Password: ");
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
	}while(strcmp(admin_password,entered_password) && printf("INVALID PASSWORD.\n"
															 "You Have %d More Tries.\n",--tries) && tries);
	if(tries){
		printf("Enter New Password: ");
		entered_password = takestring_v2();
		admin_password = entered_password;
		return 1;
	}	
	else return 0;
}

int Remove_student_record(){
	char *entered_id;
	int index;
	do{
		printf("Enter The Id: ");
		entered_id = takestring_v2();
		index = search_id(entered_id);
	}while(index == -1 && printf("Id Not Found, Please Make Sure That Id Exists! \n"));
	
	students[index].id = NULL;
	students[index].password = NULL;
	students[index].name = NULL;
	students[index].gender = NULL;
	students[index].age = -1;
	students[index].total_grade = -1;
}