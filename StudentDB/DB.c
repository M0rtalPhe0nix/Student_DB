//
//  DB.c
//  StudentDB
//
//  Created by Mohamed Omara on 31/07/2022.
//

#include "DB.h"
#include <stdbool.h>
#define a database->array

struct db SDB_CreateDataBase(void)
{
    struct db database;
    database.enteries = 0;
    return database;
}
bool SDB_IsFull(struct db *database)
{
    return database->enteries == MAX;
}

unsigned char SDB_GetUsedSize(struct db *database)
{
    return database->enteries;
}

bool SDB_AddEntry(unsigned char id, unsigned char year, unsigned char *courses,
                  unsigned char* degrees, struct db *database)
{
    struct ent entry = {id,year,courses[0],courses[1],courses[2],
                        degrees[0],degrees[1],degrees[2]};
    bool flag = 1;
    for(int i = 0; i < COUNT; i++)
    {
        if(entry.degrees[i] < 0 || entry.degrees[i] > 100)
        {
            flag = 0;
            break;
        }
    }
    
    if(!SDB_IsFull(database) && !SDB_IsIdExist(id, database) && flag)
    {
        database->array[database->enteries] = entry;
        database->id_list[database->enteries] = entry.student_id;
        database->enteries++;
        return 1;
    }
    else
    {
        return 0;
    }
}

void SDB_DeleteEntry(unsigned char id,struct db *database)
{
    for(int i = 0; i < database->enteries;i++)
    {
        if(database->array[i].student_id == id)
        {
            for(int j = i ; j < database->enteries - 1; j++)
            {
                database->array[j] = database->array[j + 1];
                database->id_list[j] = database->id_list[j + 1];
            }
            database->enteries--;
            return;
        }
    }
    printf("the student you are seeking to delete doesn't exist in the database\n");
    return;
}

bool SDB_ReadEntry(unsigned char id, unsigned char *year, unsigned char *courses,
                   unsigned char *degrees, struct db *database)
{
    for(int i = 0; i < database->enteries;i++)
    {
        if(database->array[i].student_id == id)
        {
            *year = database->array[i].student_year;
            
            for(int j = 0; j < COUNT; j++)
            {
                courses[j] = database->array[i].courses[j];
            }
            
            for(int j = 0; j < COUNT; j++)
            {
                degrees[j] = database->array[i].degrees[j];
            }
            
            return 1;
        }
    }
    return 0;
}

void SDB_GetIdList(struct db *database,unsigned char *count, unsigned char *list)
{
    *count = database->enteries;
    for(int i = 0; i < database->enteries; i++)
    {
        list[i] = database->id_list[i];
    }
}

bool SDB_IsIdExist(unsigned char id, struct db *database)
{
    for(int i = 0; i < database->enteries; i++)
    {
        if(database->id_list[i] == id)
        {
            return 1;
        }
    }
    return 0;
}

char SDB_IsIdExist2(unsigned char id, struct db *database)
{
    if(database->enteries == 0)
    {
        return 0;
    }
    else
    {
        unsigned char high = database->enteries - 1;
        unsigned char low = 0;
        unsigned char mid;
        while (high >= low)
        {
            mid = (high + low) / 2;
            if (id < a[mid].student_id)
            {
                high = mid - 1;
            }
            else if (id > a[mid].student_id)
            {
                low = mid + 1;
            }
            else
            {
                return a[mid].student_id;
            }

        }
        return (a[low].student_id - id) < (id - a[high].student_id) ? a[low].student_id : a[high].student_id;
    }
}
