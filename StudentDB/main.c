//
//  main.c
//  StudentDB
//
//  Created by Mohamed Omara on 31/07/2022.
//

//V2

#include <stdio.h>
#include "DB.h"

int main()
{
    database = SDB_CreateDataBase();
    uint8 courses_id[] = {1,2,3};
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
    /*SDB_AddEntry(10, 3, courses_id, degrees, &database);
    printf("%d\n",SDB_GetUsedSize(&database));
    SDB_DeleteEntry(5, &database);
    printf("%d\n",SDB_GetUsedSize(&database));
    
    uint8 courses_out[COUNT];
    uint8 char degrees_out[COUNT];
    uint8 year;
    
    SDB_ReadEntry(4, &year, courses_out, degrees_out, &database);
    SDB_GetIdList(&database, &year, degrees_out);*/
    SDB_DeleteEntry(2);
    printf("%d\n",SDB_IsIdExist2(2));
}
