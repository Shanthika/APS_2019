#ifndef CHOCOLATE_H_INCLUDED
#define CHOCOLATE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

struct choc_fantasy
{
    char choc_name[20];
    int quantity;
    struct choc_fantasy * prev;
    struct choc_fantasy * next;
};
typedef struct choc_fantasy CF;

CF * insert_at_end(CF * process,int value,int q);
CF * gather_requirements(CF *);
void add_strips(CF *process);
void add_egg(CF *process);
void add_sticks(CF *process);
void add_cornstarch(CF *process);
void add_cocoa(CF *process);
CF * delete_node(CF *temp,CF * process);
void melt_and_prepare(CF *);

#endif // CHOCOLATE_H_INCLUDED