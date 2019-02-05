#pragma once
#pragma once
#ifndef BOOKLIST_LASTNAME_H
#define BOOKLIST_LASTNAME_H


class Booklist {
public:
	Booklist();
	void insert(int mylist[], int new_element);
	void insert_at(int mylist[], int at_position, int new_element);
	int find_linear(int mylist[],  int element);
	int find_binary(int mylist[], int element, bool sorted);
	void delete_item_position(int mylist[], int position);
	void delete_item_isbn(int mylist[], int element);
	void sort_list_selection(int mylist[], int num_in_list);
	void sort_list_bubble(int a[], int arraySize);
	void Menu();
	void swap(int *testArrayPtr, int smaller, int pass);
	int choice;
	int ISBN;
	int position;
	int order;
	int t;
	int a[20];
	void delete_item_position_insert(int mylist[], int position, int new_element);
	void delete_item_position_insert_at(int mylist[], int position, int at_position, int new_element);
	void insert_delete_item_position(int mylist[], int new_element, int position);
	void numberplus();                                //number++
	void numberminus();                                //number--
	void print(int mylist[], int num_in_list);            
	int getnumber();                     
	void setposition(int);
	int getposition();
private:
	int number = 0;                              //the number of books in booklist
	int bookISBN=0;                               // ISBN input
	int atposition=0;                              //position input
};
#endif 
