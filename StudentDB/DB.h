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

struct ent
{
    unsigned char student_id;
    unsigned char student_year;
    unsigned char courses[COUNT];
    unsigned char degrees[COUNT];
};
struct db
{
    struct ent array[MAX];
    int enteries;
    unsigned char id_list[MAX];
};

struct db SDB_CreateDataBase(void);
bool SDB_IsFull(struct db *database);
unsigned char SDB_GetUsedSize(struct db *database);
bool SDB_AddEntry(unsigned char id, unsigned char year, unsigned char *courses,
                  unsigned char* degrees, struct db *database);
void SDB_DeleteEntry(unsigned char id,struct db *database);
bool SDB_ReadEntry(unsigned char id, unsigned char *year, unsigned char *courses,
                   unsigned char *degrees, struct db *database);
void SDB_GetIdList(struct db *database,unsigned char *count, unsigned char *list);
bool SDB_IsIdExist(unsigned char id, struct db *database);



#endif /* DB_h */
