#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>

#define MAX_NAME 30
//ARRAY FUNCTIONS
int size_array;
typedef struct student
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

//LINKED LIST FUNCTIONS
int size_list;

typedef struct node
{
    student data;
    struct node* next;
} node;

typedef struct List
{
    node* head;
    node* tail;
} List;
student create_student()
{
    student stdnt;
    printf("\nenter the name:");
    fflush(stdin);
    gets(stdnt.std_name);
    printf("\nenter the id:");
    scanf("%d", &stdnt.id);
    printf("\nenter the date of birth (day-month-year each separated by enter): ");
    scanf("%d", &stdnt.DoB.day);
    scanf("%d", &stdnt.DoB.month);
    scanf("%d", &stdnt.DoB.year);
    printf("\nenter the student's last year's score: ");
    scanf("%d", &stdnt.score);
    return stdnt;
}
node* create_node()
{
    node* new_node=(node*)malloc(sizeof(node));
    new_node->data=create_student();
    return new_node;
}

List* newList()
{
    List* list=(struct List*)malloc(sizeof(struct List));
    list->head=NULL;
    list->tail=NULL;
    size_list=0;
    return list;
}

List* initialize_list(List* list)
{
    int n; //Initial number of students
    printf("\nEnter the initial number of students: ");
    scanf("%d", &n);
    size_list=n;  //Initial size_list of list
    node *new_node=(node*)malloc(sizeof(node));
    new_node->data=create_student();
    list->head= new_node;
    list->tail=new_node;
    node *current=new_node;
    for(int i=2; i<=n; i++)  //Initialize the list excluding the first node which was already initialized above
    {
        new_node=(node*)malloc(sizeof(node));
        new_node->data=create_student();
        new_node->next=NULL;
        list->tail=new_node;
        current->next=new_node;
        current=new_node;
    }
    return list;
}
List* insert_node(List* list)
{
    size_list++;
    node *new_node=(node*)malloc(sizeof(node));
    new_node->data=create_student();
    int position;  //Position to be inserted in
    printf("\nEnter the position to be inserted in (enter an integer from 1 to %d: ", size_list);
    reposition:
    scanf("%d", &position);
    if(position<1 || position>size_list)
    {
        printf("\nInvalid position,(enter an integer from 1 to %d: ", size_list);
        goto reposition;
    }
    else
    {
        if(position==1)  //Insert at the beginning of the list
        {
            new_node->next=list->head;
            list->head=new_node;
        }
        else if(position==size_list)  //Insert at the end of the list
        {
            new_node->next=NULL;
            list->tail->next=new_node;
            list->tail=new_node;
        }
        else   //Insert somewhere in the middle
        {
            node *prev=list->head;
            for(int i=1; i<position-1; i++)
            {
                prev=prev->next;
            }
            new_node->next=prev->next;
            prev->next=new_node;
        }
    }
    return list;

}
void print_list(List* list)
{
    node* temp=list->head;
    for(int i=1; i<=size_list; i++)
    {
        printf("\nStudent %d: ", i);
        printf("\nName: %s", temp->data.std_name);
        printf("\nID: %d", temp->data.id);
        printf("\nDate of birth: %d/%d/%d", temp->data.DoB.day, temp->data.DoB.month, temp->data.DoB.year );
        printf("\nScore: %d", temp->data.score);
        temp=temp->next;
    }
}

float time_diff(struct timeval *start, struct timeval *end)
{
    return (end->tv_sec - start->tv_sec) + 1e-6*(end->tv_usec - start->tv_usec);
}

int main()
{
    int size_struct=sizeof(student);
    printf("The size of the structure (student) is: %d", size_struct);
    char system;
    resystem:
    printf("\nEnter 'a' to work with array or 'l' to work with linked list: ");
    fflush(stdin);
    scanf("%c", &system);
    if(system=='a')
    {
        char choice;
        struct timeval start;
        struct timeval end;
        printf("\nPlease enter the number of students\n");
        scanf("%d", &size_array);
        student *array =init_array();
        label:
        printf("\nDo you want to enter another student (enter 'y' for YES or 'n' for NO): ");
        fflush(stdin);
        scanf("%c",&choice);
        switch (choice)
        {
            case 'y':
            {
                size_array++;
                gettimeofday(&start, NULL);
                array = insert_std(array);
                gettimeofday(&end, NULL);
                printf("\ninsert function, time spent: %0.8f sec\n", time_diff(&start, &end));
                print_array(array);
                break;
            }
            case 'n': return 0; break;
            default: printf("\nPlease enter a correct symbol"); break;
        }
        goto label;
    }

    else if(system=='l')
    {
        char choice2;
        struct timeval start;
        struct timeval end;
        int size_node=sizeof(node);
        printf("\nThe size of one node is: %d", size_node);
        List* list=newList();
        list=initialize_list(list);
        rechoice:
        printf("\nDo you want to enter another student (enter 'y' for YES or 'n' for NO): ");
        fflush(stdin);
        scanf("%c", &choice2);
        switch(choice2)
        {
            case 'y':
            {
                gettimeofday(&start, NULL);
                list=insert_node(list);
                gettimeofday(&end, NULL);
                printf("\ninsert function, time spent: %0.8f sec\n", time_diff(&start, &end));
                print_list(list);
                break;

            }
            case 'n': {return 0; break;}
            default: {printf("\nInvalid character"); break;}
        }
        goto rechoice;
    }
    else
    {
        printf("\nInvalid character");
        goto resystem;
    }

    return 0;
}
