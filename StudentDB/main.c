//
//  main.c
//  StudentDB
//
//  Created by Mohamed Omara on 31/07/2022.
//

#include <stdio.h>
#include "DB.h"
int main()
{
    struct db database = SDB_CreateDataBase();
    unsigned char courses_id[] = {1,2,3};
    unsigned char degrees[] = {100,100,100};
    SDB_AddEntry(1, 3, courses_id, degrees, &database);
    SDB_AddEntry(2, 3, courses_id, degrees, &database);
    SDB_AddEntry(3, 3, courses_id, degrees, &database);
    SDB_AddEntry(4, 3, courses_id, degrees, &database);
    SDB_AddEntry(5, 3, courses_id, degrees, &database);
    SDB_AddEntry(6, 3, courses_id, degrees, &database);
    SDB_AddEntry(7, 3, courses_id, degrees, &database);
    SDB_AddEntry(8, 3, courses_id, degrees, &database);
    SDB_AddEntry(9, 3, courses_id, degrees, &database);
    SDB_AddEntry(10, 3, courses_id, degrees, &database);
    printf("%d\n",SDB_GetUsedSize(&database));
    SDB_DeleteEntry(5, &database);
    printf("%d\n",SDB_GetUsedSize(&database));
    
    unsigned char courses_out[COUNT];
    unsigned char degrees_out[COUNT];
    unsigned char year;
    
    SDB_ReadEntry(4, &year, courses_out, degrees_out, &database);
    SDB_GetIdList(&database, &year, degrees_out);
}
