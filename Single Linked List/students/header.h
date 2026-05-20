// ======================= header.h =======================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct student
{
    int rollno;
    char name[20];
    float marks;
    struct student *next;

} SLL;

// Function Prototypes
void add_begin(SLL **);
void add_end(SLL **);
void add_middle(SLL **);

void print_node(SLL *);
int count_node(SLL *);

void save_file(SLL *);
void read_file(SLL **);

void reverse_print(SLL *);
void print_rec(SLL *);
void reverse_rec(SLL *);

void delete_all(SLL **);
void delete_node(SLL **);

void search_node(SLL *);
void sort_node(SLL *);

void reverse_link(SLL **);

void release_memory(SLL **);


