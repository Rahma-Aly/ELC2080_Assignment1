#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
char std_name[30];
int id;
struct bd { int  day,month,year;};
int score;
struct node* next;
} Node;

int main()
{
printf("welcome\nteam members:\nJanna Sallam\nRahma Aly\nZahrah walid");
Node* n_ptr;
return 0;
}
