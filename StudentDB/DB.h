//
//  DB.h
//  StudentDB
//
//  Created by Mohamed Omara on 31/07/2022.
//

#ifndef DB_h
#define DB_h

#define MAX 10
#define COUNT 3

#include <stdio.h>
#include <stdbool.h>

typedef unsigned char uint8;
typedef struct ent
{
    uint8 student_id;
    uint8 student_year;
    uint8 courses[COUNT];
    uint8 degrees[COUNT];
} student;
typedef struct db
{
    struct ent array[MAX];
    int enteries;
    uint8 id_list[MAX];
} DataBase;

extern DataBase database;

DataBase SDB_CreateDataBase(void);
bool SDB_IsFull(void);
uint8 SDB_GetUsedSize(void);
bool SDB_AddEntry(uint8 id, uint8 year, uint8 *courses, uint8 *degrees);
void SDB_DeleteEntry(uint8 id);
bool SDB_ReadEntry(uint8 id, uint8 *year, uint8 *courses, uint8 *degrees);
void SDB_GetIdList(uint8 *count, uint8 *list);
bool SDB_IsIdExist(uint8 id);
//uint8 SDB_IsIdExist2(uint8 id);




#endif /* DB_h */
