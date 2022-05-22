#include "Search_Tree.h"

/*
std::string Random_string()
{
	std::string temp_str = "";

	for (size_t i = 0; i < (rand() % 15 + 5); i++)
	{
		int temp = rand() % 26 + 97;
		temp_str += static_cast<char>(temp);
	}
	return temp_str;
}
*/


void Add_Node(Search_Tree*& pCurrent, int key)
{
	if (pCurrent == nullptr)
	{
		pCurrent = new Search_Tree;
		pCurrent->key = key;
		pCurrent->count = 1;

		pCurrent->left = nullptr;
		pCurrent->right = nullptr;
	}
	else
	{
		if (key < pCurrent->key) { Add_Node(pCurrent->left, key); }
		else if (key > pCurrent->key) { Add_Node(pCurrent->right, key); }
		else { pCurrent->count++; }
	}
}

void Changer(Search_Tree*& pCurrent, Search_Tree*& pTemp)
{
	if (pCurrent->right)
	{
		Changer(pCurrent->right, pTemp);
	}
	else
	{
		pTemp->key = pCurrent->key;
		pTemp->data = pCurrent->data;
		pTemp = pCurrent;
		pCurrent = pCurrent->left;
	}
}

void Delete_Node(Search_Tree*& pCurrent, int key)
{
	Search_Tree* Temp = nullptr;

	if (pCurrent)
	{
		if (key < pCurrent->key) { Delete_Node(pCurrent->left, key); }
		else if (key > pCurrent->key) { Delete_Node(pCurrent->right, key); }
		else
		{
			Temp = pCurrent;
			if (Temp->right == nullptr) { pCurrent = Temp->left; }
			else if (Temp->left == nullptr) { pCurrent = Temp->right; }
			else { Changer(pCurrent->left, Temp); }
			delete Temp;
		}
	}

}



Search_Tree** Non_Rec_Search(Search_Tree* head, int key)
{
	Search_Tree** Temp = &head;

	while (*Temp)
	{
		if (key == (*Temp)->key) { return Temp; }

		if (key < (*Temp)->key) { Temp = &(*Temp)->left; }
		else if (key > (*Temp)->key) { Temp = &(*Temp)->right; }
	}
	return Temp;
}

void Add_Node_NoR(Search_Tree*& Root, int key)
{
	Search_Tree** pCurrent = nullptr;

	if (Root == nullptr) { pCurrent = &Root; }
	else
	{
		pCurrent = Non_Rec_Search(Root, key);

		if (*pCurrent) { (*pCurrent)->count++; return; }
	}

	(*pCurrent) = new Search_Tree;
	(*pCurrent)->key = key;
	(*pCurrent)->count = 1;
	//(*pCurrent)->data = Random_string();

	(*pCurrent)->left = nullptr;
	(*pCurrent)->right = nullptr;
}

void Delete_Node_NoR(Search_Tree*& Root, int key)
{
	Search_Tree** pCurrent = Non_Rec_Search(Root, key);
	if (pCurrent == nullptr) { return; }

	Search_Tree* Temp = *pCurrent;
	if (Temp->right == nullptr) { *pCurrent = Temp->left; }
	else if (Temp->left == nullptr) { *pCurrent = Temp->right; }
	else
	{
		pCurrent = &(*pCurrent)->left;
		while ((*pCurrent)->right) { pCurrent = &(*pCurrent)->right; }
		Temp->key = (*pCurrent)->key;
		Temp->data = (*pCurrent)->data;
		Temp = *pCurrent;
		*pCurrent = (*pCurrent)->left;
	}
	delete Temp;
}


void clean_memory(Search_Tree* current)
{
	if (current != nullptr)
	{

		clean_memory(current->left);
		clean_memory(current->right);
		delete current;
	}
}

void forward(Search_Tree* current, int count)
{
	if (current != nullptr)
	{
		for (size_t i = 0; i < count; i++)
		{
			std::cout << "\t";
		}
		std::cout << current->key << std::endl;
		forward(current->left, count + 1);
		forward(current->right, count + 1);
	}
}

void symmetric(Search_Tree* current, int count)
{
	if (current != nullptr)
	{
		symmetric(current->left, count + 1);
		for (size_t i = 0; i < count; i++)
		{
			std::cout << "\t";
		}
		std::cout << current->key << std::endl;
		symmetric(current->right, count + 1);
	}
}

void show_in_line(Search_Tree* current)
{
	if (current != nullptr)
	{
		show_in_line(current->left);
		std::cout << current->key <<"(" << current->count << ") ";
		show_in_line(current->right);
	}
}