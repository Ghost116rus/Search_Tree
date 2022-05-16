// Дерево поиска.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>

struct Search_Tree
{
	int key;
	int count;
	std::string data;


	Search_Tree* left = nullptr;
	Search_Tree* right = nullptr;
};

void Random_string(Search_Tree* pCurrent)
{
	std::string temp_str = "";

	for (size_t i = 0; i < (rand() % 15 + 5); i++)
	{
		int temp = rand() % 26 + 97;
		temp_str += static_cast<char>(temp);
	}
	pCurrent->data = temp_str;
}


Search_Tree* Non_Rec_Search(Search_Tree*& previous, int key)
{
	Search_Tree* Temp = previous;

	while (Temp)
	{
		if (key == Temp->key) { return Temp; }

		previous = Temp;
		if (key < Temp->key) { Temp = Temp->left; }
		else if (key > Temp->key) { Temp = Temp->right; }
	}
	return Temp;
}


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

void Add_Node_NoR(Search_Tree*& Root, int key)
{
	Search_Tree** pCurrent = nullptr;
	
	if (Root)
	{
		Search_Tree* pPrevious = Root;
		Search_Tree* pTemp = Non_Rec_Search(pPrevious, key);

		if (pTemp)
		{
			pTemp->key++; return;

		}
		else
		{
			if (key < pPrevious->key) { pCurrent = &pPrevious->left; }
			else if (key > pPrevious->key) { pCurrent = &pPrevious->right; }
		}
	}
	else
	{
		pCurrent = &Root;
	}
	
	(*pCurrent) = new Search_Tree;
	(*pCurrent)->key = key;
	(*pCurrent)->count = 1;

	(*pCurrent)->left = nullptr;
	(*pCurrent)->right = nullptr;



}






int main()
{
	Search_Tree* Root = nullptr;
	Add_Node_NoR(Root, 22);
	Add_Node_NoR(Root, 6);
	Add_Node_NoR(Root, 46);
	Add_Node_NoR(Root, 16);
}

