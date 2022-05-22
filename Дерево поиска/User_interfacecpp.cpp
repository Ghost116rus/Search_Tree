#include "User_interface.h"

int getValue(int condition, const char* string)
{
	while (true)													// ���� ������������ �� ��� ���, ���� ������������ �� ������ ���������� ��������
	{
		int a;
		std::cin >> a;

		if (std::cin.fail())										// ���� ���������� ���������� ��������� ���������,
		{
			std::cout << "������! ����������, ��������� ����! \n";
			std::cin.clear();										// �� ���������� cin � '�������' ����� ������
			std::cin.ignore(32767, '\n');							// � ������� �������� ����������� ����� �� �������� ������
			std::cout << string;
		}
		else // ���� �� ������ � ���������� �������, �� ���������� a
		{
			switch (condition)
			{
			case Natural_number:
				if (a > 0) { return a; }

				std::cout << "�� ������ ������ ����������� �����\n";
				std::cin.ignore(32767, '\n');						// � ������� �������� ����������� ����� �� �������� ������
				continue;

			case O_Or_1:												// �� �������

				if ((a == 0) || (a == 1)) { return a; }

				std::cout << "�� ������ ������ ���� 0, ���� 1\n";
				std::cin.ignore(32767, '\n');						// � ������� �������� ����������� ����� �� �������� ������
				continue;

			case Menu_Commands:

				if (((int)a > 0) && ((int)a < 10)) { return a; }

				std::cout << "� ���� ����� 8 �������! ��������� ����: ";
				std::cin.ignore(32767, '\n');						// � ������� �������� ����������� ����� �� �������� ������
				continue;

			default:
				return a;
			}

		}

	}
}



void show_menu()
{
	std::cout << "\n  ���������� ���������:\n"
		<< "1. ���������� ������ ��������\n"
		<< "2. �������� �������� �������\n"
		<< "3. ����� �������� �������\n"
		<< "4. ������ ����� ������\n"
		<< "5. ������������ ����� ������\n"
		<< "6. ������� ������� � �������\n"
		<< "7. �������� ������� ����\n"
		<< "8. ������� ������ ���������\n"
		<< "9. ���������� ������\n";
}

void write_author()
{
	std::cout << "������ �������� ������ �.� ��. 4211\n";
}

void search(Search_Tree* root, int key)
{
	Search_Tree* current = nullptr;

	if (current = *Non_Rec_Search(root, key))
	{
		std::cout << "��������� �������: ����� - " << current << "\t ����: " << current->key << "\t �������: " << current->count << std::endl;
	}
	else
	{
		std::cout << "�������� ������� �� �������\n";
	}
}

void AddNode(Search_Tree*& root)
{
	int user_input;
	if (root)
	{
		std::cout << "������� ���� ����� �������: ";
		user_input = getValue(Natural_number, "�������� �������: ");
		Add_Node_NoR(root, user_input);
	}
	else
	{
		std::cout << "����� ���������� ������ ��������? �������: ";
		user_input = getValue(Natural_number, "�������� �������: ");
		for (size_t i = 0; i < user_input; i++)
		{
			Add_Node(root, rand() % 99 * 9 * 4 % 121 + 1);
		}
	}
}

void menu()
{
	int user_input = -1;
	Search_Tree* root = nullptr;

	show_menu();
	while (!(root))
	{
		std::cout << "\n�������� �������: ";
		user_input = getValue(Menu_Commands, "�������� �������: ");

		if (user_input == Exit) { return; }

		if (user_input == Add_new_element) { AddNode(root); }
		else if ((user_input < 6) && (user_input > 1)) { std::cout << "������ ������!\n"; }
		switch (user_input)
		{

		case Show_main_menu:
			show_menu();
			break;

		case Write_author:
			write_author();
			break;

		default:
			break;
		}
	}

	//show_menu();
	while (user_input != Exit)
	{
		std::cout << "\n�������� �������: ";
		user_input = getValue(Menu_Commands, "�������� �������: ");

		switch (user_input)
		{

		case Add_new_element:
			AddNode(root);
			break;

		case Delete:
			std::cout << "������� ���� ��������� �������: ";
			user_input = getValue(Natural_number, "�������� �������: ");
			Delete_Node(root, user_input);
			break;

		case Find:
			std::cout << "������� ���� ������� �������: ";
			user_input = getValue(Natural_number, "�������� �������: ");
			search(root, user_input);
			break;

		case Show_forward:
			forward(root, 0);
			break;

		case Show_symmetric:
			symmetric(root, 0);
			break;

		case Show_back_symmetric:
			show_in_line(root); std::cout << std::endl;
			break;

		case Show_main_menu:
			show_menu();
			break;

		case Write_author:
			write_author();
			break;

		default:
			//std::cout << "� ���� ������ 8 �������!\n";
			break;
		}
	}

	std::cout << "�a�������� ������!\n";
	clean_memory(root);
}