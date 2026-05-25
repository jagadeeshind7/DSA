#ifndef INVENTORY_H
#define INVENTORY_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define FILE_NAME "data/products.dat"

typedef struct product
{
	int id;
	char name[50];
	int quantity;
	float price;

	struct product *next;

}PRODUCT;

extern PRODUCT *head;

void add_product();
void view_products();
void search_product();
void update_product();
void delete_product();

void save_to_file();
void load_from_file();

PRODUCT *create_node();

#endif

