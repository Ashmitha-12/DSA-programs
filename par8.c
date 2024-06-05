#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<conio.h>

struct node
{
    char *name[100];
    int age;
    char *address[100];
    int phone;
    char bloodgroup[100];
    int reg;
    int priority;
    struct node *next;
};
struct node *start= NULL;
struct node *insert(struct node *);
struct node *delete(struct node *);
void display();
void table();
void main()
{

    int option;
    do{
    	system("COLOR 30");//20-GREEN//10-darkBLUE//30-lightblue//50-voilet//
        printf("\t\t\t\t\t-------------------------------\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\n");
        printf("\t\t\t\t\t\t\t\t\t\t\n");
        printf("\t\t\t\t\tWELCOME TO SRI RAM HOSPITAL!\n");
        printf("\t\t\t\t\t\t\t\t\t\t\n");
        printf("\t\t\t\t\t\t\t\t\t\t\n");
        printf("\t\t\t\t\t-------------------------------\n");
        printf("\t\t\t\t\t1.ADD A PATIENT\n");
        printf("\t\t\t\t\t2.DELETE A RECORD\n");
        printf("\t\t\t\t\t3.DISPLAY ALL APPOINTMENTS\n");
        printf("\t\t\t\t\t4.EXIT\n");
        printf("\t\t\t\t\tEnter your choice:");
        scanf("%d",&option);
    switch(option)
    {
    case 1:
        start= insert(start);
        getchar();
        system("cls");
		break;
    case 2:
        start= delete(start);
        getchar();
        system("cls");
        break;
    case 3:
        display(start);
        getchar();
        system("cls");
        break;
    case 4:
        exit(0);
        break;
    default:
    	printf("\t\t\t\t\tinvalid choice");
    }
}while(option!=4);
}
struct node *insert(struct node *start)
{
    int val2,val4,val6,pri;
    char val1,val3,val5;
    struct node *ptr,*p;
    char* name[100];
    char* address[100];
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("\t\t\t\t\tEnter patient Name:");
    scanf(" %s",ptr-> name);
    printf("\t\t\t\t\tEnter the patient's age:");
    scanf("%d",&val2);
    printf("\t\t\t\t\tEnter your home address:");
    scanf(" %s",ptr->address);
    printf("\t\t\t\t\tEnter your phone number:");
    scanf("%d",&val4);
    printf("\t\t\t\t\tEnter the blood group of Patient:");
    scanf(" %s",ptr->bloodgroup);
    printf("\t\t\t\t\tEnter the registered no:");
    scanf("%d",&val6);
    printf("\t\t\t\t\tEnter your disease Number:\n");
    table();
    scanf("%d",&pri);
    //ptr->name=name;
    ptr->age=val2;
    //ptr->address=address;
    ptr->phone=val4;
    ptr->reg=val6;
    ptr->priority=pri;
    if((start==NULL)||pri<start->priority)
    {
        ptr->next=start;
        start=ptr;
    }
    else
        {
            p=start;
            while(p->next!=NULL && p->next->priority <=pri)
            ptr->next=p->next;
            p->next=ptr;
        }
        printf("\n PATIENT DETAILS INSERTED SUCCESSFULLY");
        return start;
};
struct node *delete(struct node *start)
{
    struct node *ptr;
    if(start==NULL)
    {
        printf("\t\t\t\t\tNO PATIENT RECORD TO DELETE");
    }
    else
    {
        ptr= start;
        printf("\n Deleted Record is %d",ptr);
        start=start->next;
        printf("\n patient record deleted succesfully");
        free(ptr);
    }
}
void display(struct node *start)
{
    struct node *ptr;
    ptr=start;
    if(start==NULL)
        printf("\t\t\t\t\tTHERE IS NO PATIENT");
    else
    {
        printf("\t\t\t\t\tPriority wise appointments are\n:");
        while(ptr!=NULL)
        {
            printf("\t\t\t\t\tThe name of patient is:%s\n",ptr->name);
            printf("\t\t\t\t\tThe age of patient is:%d\n",ptr->age);
            printf("\t\t\t\t\tThe address of patient is : %s\n",ptr->address);
            printf("\t\t\t\t\tPhone Number:%d\n",ptr->phone);
            printf("\t\t\t\t\tThe blood group of patient is:%s\n",ptr->bloodgroup);
            printf("\t\t\t\t\t---------------------------------------------------\n");
            ptr=ptr->next;
        }
    }
    getchar();
}
void table()
{
    printf("\t\t\t\t\tPlease Refer this Table for your disease!\n");
    printf("\t\t\t\t\t---------------------------------------------------\n");
    printf("\t\t\t\t\t1.Heart attack\n");
    printf("\t\t\t\t\t2.Severe wound/Bleeding\n");
    printf("\t\t\t\t\t3.Cancer\n");
    printf("\t\t\t\t\t4.Chest pain\n");
    printf("\t\t\t\t\t5.Fracture\n");
    printf("\t\t\t\t\t6.Diabetes Checkup\n");
    printf("\t\t\t\t\t7.Infection\n");
    printf("\t\t\t\t\t8.Viral Fever\n");
    printf("\t\t\t\t\t9.Common Cold\n");
	printf("\t\t\t\t\t10.Head ache\n");
	printf("\t\t\t\t\t11.ENT problems\n");
    printf("\t\t\t\t\t12.exit\n");
    printf("\t\t\t\t\t13.back to main menu\n");
}
