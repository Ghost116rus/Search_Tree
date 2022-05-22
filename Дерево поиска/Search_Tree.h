#pragma once
#include <iostream>


struct Search_Tree
{
	int key;
	int count;
	std::string data;


	Search_Tree* left = nullptr;
	Search_Tree* right = nullptr;
};


void Add_Node(Search_Tree*& pCurrent, int key);
void Changer(Search_Tree*& pCurrent, Search_Tree*& pTemp);
void Delete_Node(Search_Tree*& pCurrent, int key);


Search_Tree** Non_Rec_Search(Search_Tree* head, int key);
void Add_Node_NoR(Search_Tree*& Root, int key);
void Delete_Node_NoR(Search_Tree*& Root, int key);


void forward(Search_Tree* current, int count);
void symmetric(Search_Tree* current, int count);
void show_in_line(Search_Tree* current);


void clean_memory(Search_Tree* current);