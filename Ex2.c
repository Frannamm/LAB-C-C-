#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    float average;
} Student;

void CreateStudent(Student **stdnt, int n) {
    *stdnt = (Student *)malloc(n * sizeof(Student));  // NOLINT
    if (*stdnt == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Enter ID of student %d : ", i + 1);
        scanf("%d", &(*stdnt)[i].id);
        printf("Enter name of student %d : ", i + 1);
        scanf(" %49s", (*stdnt)[i].name);
        printf("Enter average of student %d : ", i + 1);
        scanf("%f", &(*stdnt)[i].average);
    }
}

int main(void) {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of students must be positive.\n");
        return 1;
    }

    Student *students = NULL;
    CreateStudent(&students, n);

    printf("\nStudent Details:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, Average: %.2f\n", students[i].id, students[i].name, students[i].average);
    }

    int index = 0;
    for (int i = 1; i < n; i++) {
        if (students[i].average > students[index].average) {
            index = i;
        }
    }

    printf("\nStudent with the highest average:\n");
    printf("ID: %d, Name: %s, Average: %.2f\n", students[index].id, students[index].name, students[index].average);

    float sum = 0.0f;
    for (int i = 0; i < n; i++) {
        sum += students[i].average;
    }
    float classAverage = sum / n;
    printf("\nClass Average: %.2f\n", classAverage);

    free(students);
    return 0;
}
