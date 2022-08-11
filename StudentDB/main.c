//
//  main.c
//  StudentDB
//
//  Created by Mohamed Omara on 31/07/2022.
//

//V2

#include <stdio.h>
#include "DB.h"
#include <stdlib.h>
int main()
{
    database = SDB_CreateDataBase();
    printf("Welcome to my DATABASE\nMy DATABASE CAN DO ALOT\n");
    uint8 func = -1;
    uint8 subject_id[3];
    uint8 grades[3];
    uint8 id;
    uint8 year;
    uint8 *list = &func;
    uint8 count;
    while (1)
    {
        printf("Enter a number from 0 to 6 to use My DATABASE\n");
        scanf("%d",&func);
        switch (func) {
            case 0:
                if(SDB_IsFull())
                {
                    printf("Full\n");
                }
                else
                {
                    printf("There is still space\n");
                }
                break;
            case 1:
                printf("Used size is : %d\n",SDB_GetUsedSize());
                break;
            case 2:
                printf("Enter the student Id\n");
                scanf("%d",&id);
                printf("Enter the Year\n");
                scanf(" %d",&year);
                printf("Enter the course Ids\n");
                scanf(" %d %d %d",&subject_id[0],&subject_id[1],&subject_id[2]);
                printf("Enter the grades\n");
                scanf(" %d %d %d",&grades[0],&grades[1],&grades[2]);
                if(SDB_AddEntry(id, year, subject_id, grades))
                {
                    printf("Added\n");
                }
                else
                {
                    printf("Sorry Invalid Entry\n");
                }

                break;
            case 3:
                printf("Enter the student Id to be deleted\n");
                scanf(" %d",&id);
                SDB_DeleteEntry(id);
                printf("deleted\n");
                break;
            case 4:
                printf("Enter the student Id\n");
                scanf(" %d",&id);
                if(SDB_ReadEntry(id, &year, subject_id, grades))
                {
                    printf("Year: %d\n",year);
                    printf("Subjects :   %d   %d   %d\n",subject_id[0],subject_id[1],subject_id[2]);
                    printf("grades :   %d   %d   %d\n",grades[0],grades[1],grades[2]);
                }
                else
                {
                    printf("Not Found\n");
                }
                break;
            case 5:
                SDB_GetIdList(&count, list);
                if (count)
                {
                    printf("Count : %d\n",count);
                    printf("IDs : ");
                    for(int i = 0; i < database.enteries; i++)
                    {
                        printf("%d\t",list[i]);
                    }
                    printf("\n");
                }
                else
                {
                    printf("No Records To show");
                }
                
                break;
            case 6:
                printf("Enter the student Id\n");
                scanf(" %d",&id);
                if(SDB_IsIdExist(id))
                {
                    printf("It Exist\n");
                }
                else
                {
                    printf("It doesn't Exist\n");
                }
                break;
                
            default:
                break;
        }
    }
    /*uint8 courses_id[] = {1,2,3};
    uint8 degrees[] = {100,100,100};
    SDB_AddEntry(1, 3, courses_id, degrees);
    SDB_AddEntry(2, 3, courses_id, degrees);
    SDB_AddEntry(3, 3, courses_id, degrees);
    SDB_AddEntry(4, 3, courses_id, degrees);
    SDB_AddEntry(5, 3, courses_id, degrees);
    SDB_AddEntry(6, 3, courses_id, degrees);
    SDB_AddEntry(7, 3, courses_id, degrees);
    SDB_AddEntry(8, 3, courses_id, degrees);
    SDB_AddEntry(9, 3, courses_id, degrees);
    SDB_AddEntry(10, 3, courses_id, degrees, &database);
    printf("%d\n",SDB_GetUsedSize(&database));
    SDB_DeleteEntry(5, &database);
    printf("%d\n",SDB_GetUsedSize(&database));
    
    uint8 courses_out[COUNT];
    uint8 char degrees_out[COUNT];
    uint8 year;
    
    SDB_ReadEntry(4, &year, courses_out, degrees_out, &database);
    SDB_GetIdList(&database, &year, degrees_out);
    SDB_DeleteEntry(2);
    printf("%d\n",SDB_IsIdExist(2));*/
}
