#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>

#define MAX_NAME 30
int size_array;
typedef struct 
{
    char std_name[MAX_NAME];
    int id;
    struct DoB { int day, month, year;} DoB;
    int score;
} student;


student* init_array ()
{
    student *p = (student*)malloc(size_array*sizeof(student));
    if (p == NULL)
    {
        printf("Not enough memory, allocation failed\n");
        return NULL;
    }
    else
    {
        printf("\nPlease enter the following data:\n");
            for(int i=0; i<size_array; i++)
            {
                printf("name: ");
                fflush(stdin);
                gets(p[i].std_name);
                printf("ID:");
                scanf("%d",&(p[i].id));
                printf("Date of birth (Day, Month and year each separated by an enter):");
                scanf("%d %d %d",&(p[i].DoB.day),&(p[i].DoB.month), &(p[i].DoB.year));
                printf("Last year score:");
                scanf("%d",&(p[i].score));
            }
     }
    return p;
}
student *insert_std(student *ptr)
{
    int location;
    student *array = (student*)realloc(ptr, size_array*sizeof(student));
    printf("please enter the location where the student is inserted\n (enter an integer from 1 till %d): ", size_array);
    relocate:
    scanf("%d", &location);
    if(location>size_array)
    {
        printf("\nInvalid number, enter an integer from 1 till %d: ", size_array);
        goto relocate;
    }
    printf("please enter student's data:\n");
    if (location == size_array)  //if the insertion is at the end of the array
    {
        printf("name: ");
        fflush(stdin);
        gets(array[size_array-1].std_name);
        printf("ID:");
        scanf("%d",&(array[size_array-1].id));
        printf("Date of birth:");
        scanf("%d %d %d",&array[size_array-1].DoB.day,&array[size_array-1].DoB.month, &array[size_array-1].DoB.year);
        printf("Last year score:");
        scanf("%d",&array[size_array-1].score);
    }
    else
    {
        int m;  //used to shift all data to a higher position
        for (m=size_array-1; m>0; m--)
        {
            strcpy(array[m].std_name,array[m-1].std_name);
            array[m].id = array[m-1].id;
            array[m].DoB.day = array[m-1].DoB.day;
            array[m].DoB.month = array[m-1].DoB.month;
            array[m].DoB.year = array[m-1].DoB.year;
            array[m].score = array[m-1].score;
        }
        printf("name: ");
        fflush(stdin);
        gets(array[location-1].std_name);
        printf("ID:");
        scanf("%d",&array[location-1].id);
        printf("Date of birth:");
        scanf("%d %d %d",&array[location-1].DoB.day,&array[location-1].DoB.month, &array[location-1].DoB.year);
        printf("Last year score:");
        scanf("%d",&array[location-1].score);
    }
    return array;
}

void print_array(student* array)
{
       for(int i=0; i<size_array ;i++)
        {
            printf("\nStudent %d:", i+1);
            printf("\nname: %s",array[i].std_name);
            printf("\nID:%d",array[i].id);
            printf("\ndate of birth: %d/%d/%d", array[i].DoB.day ,array[i].DoB.month , array[i].DoB.year);
            printf("\nscore:%d", array[i].score);
            printf("\n");
        }
}
int main()
{
printf("\twelcome\nteam members:Janna Sallam Rahma Aly Zahrah walid");
return 0;
}
