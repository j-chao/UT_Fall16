/* Justin Chao
 * class.c prompts for student names and grades, and outputs the array of
 * students, and the average grade.
 */

#include <stdio.h>

typedef struct Student {
    char name[100];
    double grade;
} Student;

int main() {
    // create array of structures Student called class of size 10
    Student class[10];
    // initiate variables types
    int i;
    double total_grade, min, max;

    // prompt for input of Student name and grade
    // scan input into array
    for (i=0; i<10; i++) {
        printf("\nEnter name of Student %i: \n", i+1);
        scanf(" %[^\n]s", class[i].name);
        printf("Enter grade of Student %i: \n", i+1);
        scanf("%lf", &class[i].grade);
        
        // calculate total_grade by summing all grades
        total_grade += class[i].grade;
    }

    // calculate min/max grades
    min = max = class[0].grade;
    for (i=0; i<10; i++){
        if (class[i].grade < min)
                min = class[i].grade;
        if (class[i].grade > max)
                max = class[i].grade;
    }

    // print names and grades of students
    printf ("\n===== Listing of Student Names and Grades =====\n");
    for (i=0; i<10; i++) {
        if (class[i].grade == min) 
            printf("Name: %-20s Grade: %.2f %-20s \n", class[i].name, class[i].grade, "(lowest score)");
        else if (class[i].grade == max) 
            printf("Name: %-20s Grade: %.2f %-20s \n", class[i].name, class[i].grade, "(highest score)");
        else        
            printf("Name: %-20s Grade: %.2f \n", class[i].name, class[i].grade);
    }

    // print average grade
    printf("\nAverage Grade: %.2f \n", total_grade / 10.0);
    return 0;
}
