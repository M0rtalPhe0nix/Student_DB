//
//  DB.c
//  StudentDB
//
//  Created by Mohamed Omara on 31/07/2022.
//

#include "DB.h"
#include <stdbool.h>
#define a database.array

DataBase database;
DataBase SDB_CreateDataBase(void)
{
    DataBase database;
    database.enteries = 0;
    return database;
}

bool SDB_IsFull()
{
    return database.enteries == MAX;
}

unsigned char SDB_GetUsedSize()
{
    return database.enteries;
}

bool SDB_AddEntry(uint8 id, uint8 year, uint8 *courses, uint8 *degrees)
{
    student entry = {id,year,courses[0],courses[1],courses[2],
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
    
    if(!SDB_IsFull() && !SDB_IsIdExist(id) && flag)
    {
        a[database.enteries] = entry;
        database.id_list[database.enteries] = entry.student_id;
        database.enteries++;
        return 1;
    }
    else
    {
        return 0;
    }
}

void SDB_DeleteEntry(uint8 id)
{
    for(int i = 0; i < database.enteries;i++)
    {
        if(a[i].student_id == id)
        {
            for(int j = i ; j < database.enteries - 1; j++)
            {
                a[j] = a[j + 1];
                database.id_list[j] = database.id_list[j + 1];
            }
            database.enteries--;
            return;
        }
    }
    printf("the student you are seeking to delete doesn't exist in the database\n");
    return;
}

bool SDB_ReadEntry(uint8 id, uint8 *year, uint8 *courses, uint8 *degrees)
{
    for(int i = 0; i < database.enteries;i++)
    {
        if(a[i].student_id == id)
        {
            *year = a[i].student_year;
            
            for(int j = 0; j < COUNT; j++)
            {
                courses[j] = a[i].courses[j];
            }
            
            for(int j = 0; j < COUNT; j++)
            {
                degrees[j] = a[i].degrees[j];
            }
            
            return 1;
        }
    }
    return 0;
}

void SDB_GetIdList(uint8 *count, uint8 *list)
{
    *count = database.enteries;
    for(int i = 0; i < database.enteries; i++)
    {
        list[i] = database.id_list[i];
    }
}

bool SDB_IsIdExist(uint8 id)
{
    for(int i = 0; i < database.enteries; i++)
    {
        if(database.id_list[i] == id)
        {
            return 1;
        }
    }
    return 0;
}

/*uint8 SDB_IsIdExist2(uint8 id)
{
    if(database.enteries == 0)
    {
        return 0;
    }
    else
    {
        uint8 high = database.enteries - 1;
        uint8 low = 0;
        uint8 mid;
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
}*/
