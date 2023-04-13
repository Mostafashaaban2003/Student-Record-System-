1. system_init: starts The program interface.

2. check_admin_password: checks admin password 3 times admin and if failed returns 0 and support returning to previous screen by returning -1

3. add_student: adds a student to the array by checking that the id is unique, allocates size for it and stores data, encrypts password before storing and asks if admin wants to add more students then asks to save data to file.

4. Remove_student_record: remove a student record from the array and asks if admin wants to add more students then asks to save data to file.

5. View_student_record: prints a student data and takes the index as argument and isadmin, if user is admin the program asks him if he wants to view more records.

6. View_all_records: view all students records by calling View_student_record function.

7. Edit_admin_password: change admin password and returns 0 if he didn't enter the old password correctly for 3 times

8. Edit_student_grade: change student grade (must be 0 ~ 100) as it takes the index as argument and isaddding, returns 0 if not edited (user entered -1) and if the user is in editing student grade screen then it asks him if he wants to change more students grade

8. check_student_password: checks student password 3 times,and if failed returns 0 and support returning to previous screen by returning -1 and if user entered f redirect him to forgot my password screen

9. Edit_student_Password: asks student for id and password 3 times, returns 0 if the user ran out of tries

10. Edit_your_name: Edits Student Name

11. forgot_my_password: asks user to enter id and name and prints the password decrypted if the id and the name are correct.

12. load data: load data from students.txt to the array.

13. takestring_v2: takes strings from user by allocating size dynamically and returns its pointer.

14. string_to_int: converts string to integer and if the string isn't a number it returns -1.

15. Choose_Number: keeps asking user to enter number between 1 and n.

16. Is_valid_id: checks if id is valid (length less than 14 and doen't have characters), returns 0 if not valid.

17. take_valid_age: checks if age is valid (age more than 7 and less than 20 and doen't have characters), returns 0 if not valid.

18. take_valid_name: checks if name is valid (consists of characters only), returns null if not valid.

19. search_id: searches for a specified id and returns the index of it and if not found returns -1
 
20. get_id: asks the admin repeatidly to enter a correct id , search it and returns its index and returns -1 if usre enters -1

21. get_first_free_index: returns the index of the first unoccupied space in the array

22. encrypt: encrypt student password

23. decrypt: returns the decryption of a student password

24. ask_to_save: asking if admin wants to save data.

25. save_data: save data from student* students to students.txt.








 



