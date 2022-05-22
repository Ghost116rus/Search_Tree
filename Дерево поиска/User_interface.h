#pragma once
#include <iostream>
#include "Search_Tree.h"


enum Options
{

	Add_new_element = 1,
	Delete = 2,
	Find = 3,
	Show_forward = 4,
	Show_symmetric = 5,
	Show_back_symmetric = 6,
	Show_main_menu = 7,
	Write_author = 8,
	Exit = 9,

	Natural_number = 14,
	O_Or_1 = 15,
	Menu_Commands = 16
};

/* ������� �� ���� ��� �� 2 - ��� ��������, ����� �� ��������� ��������� ���������� ������ �� ���� ��������  */
int getValue(int condition, const char* string);


/*  �������� ����������� ���������� ����������  */
void menu();