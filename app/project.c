#include "project.h"

int main(){
	load_data();
	system_init();
	save_data(students,number_of_students);
}


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
    printf("loaded %d students from file successfully!\n",number_of_students);

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
	
