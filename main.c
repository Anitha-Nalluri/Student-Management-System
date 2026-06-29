#include <stdio.h>
#include <stdlib.h>
struct Student{
    int roll;
    char name[50];
    float marks;
};
struct Student s[100];
int count = 0;
int main()
{
    int choice;

    while(1)
    {
        printf("\n");
        printf("=========================================\n");
        printf("      STUDENT MANAGEMENT SYSTEM\n");
        printf("=========================================\n");

        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");

        printf("\nEnter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter Roll Number: ");
                scanf("%d", &s[count].roll);    
                printf("Enter Name: ");
                scanf("%s", s[count].name);
                printf("Enter Marks: ");
                scanf("%f", &s[count].marks);
                count++;
                printf("\nStudent Added Successfully!\n");
                break;

            case 2:
                if(count == 0)
                {
                    printf("\nNo Student Records Found!\n");
                }
                else
                {
                    int i;
                    printf("\n=====================================\n");
                    printf("         STUDENT RECORDS\n");
                    printf("=====================================\n");
                    for(i = 0; i < count; i++)
                    {
                        printf("\nStudent %d\n", i + 1);
                        printf("Roll Number : %d\n", s[i].roll);
                        printf("Name        : %s\n", s[i].name);
                        printf("Marks       : %.2f\n", s[i].marks);
                        printf("-------------------------------------\n");
                    }
                }
                break;

            case 3:         
                int roll, i, found = 0;
                printf("\nEnter Roll Number to Search: ");
                scanf("%d", &roll);
                for(i = 0; i < count; i++)
                {
                    if(s[i].roll == roll)
                    {
                        printf("\nStudent Found!\n");
                        printf("Roll Number : %d\n", s[i].roll);
                        printf("Name        : %s\n", s[i].name);
                        printf("Marks       : %.2f\n", s[i].marks);
                        found = 1;
                        break;
                    }
               }
               if(found == 0)
               {
                    printf("\nStudent Not Found!\n");
               }
               break;
            case 4:
               {
                    int roll, i, found = 0;
                    printf("\nEnter Roll Number to Update: ");
                    scanf("%d", &roll);
                    for(i = 0; i < count; i++)
                    {
                        if(s[i].roll == roll)
                        {
                           printf("\nEnter New Name: ");
                           scanf("%s", s[i].name);
                           printf("Enter New Marks: ");
                           scanf("%f", &s[i].marks);
                           printf("\nStudent Updated Successfully!\n");
                           found = 1;
                           break;
                        }
                    } 
                    if(found == 0)
                    {
                        printf("\nStudent Not Found!\n");
                    }
                    break;
                }    
            case 5:
                { 
                    int roll, i, j, found = 0;
                    printf("\nEnter Roll Number to Delete: ");
                    scanf("%d", &roll);
                    for(i = 0; i < count; i++)
                    {
                        if(s[i].roll == roll)
                        {
                            for(j = i; j < count - 1; j++)
                            {
                                s[j] = s[j + 1];
                            }
                            count--;
                            printf("\nStudent Deleted Successfully!\n");
                            found = 1;
                            break;
                        }
                    }
                    if(found == 0)
                    {
                        printf("\nStudent Not Found!\n");
                    }
                    break;
                }
            case 6:
                printf("\nThank You!\n");
                exit(0);

            default:
                printf("\nInvalid Choice\n");
        }
    }

    return 0;
}