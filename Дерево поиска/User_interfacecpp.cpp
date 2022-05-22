#include "User_interface.h"

int getValue(int condition, const char* string)
{
	while (true)													// цикл продолжается до тех пор, пока пользователь не введет корректное значение
	{
		int a;
		std::cin >> a;

		if (std::cin.fail())										// если предыдущее извлечение оказалось неудачным,
		{
			std::cout << "Ошибка! Пожалуйста, повторите ввод! \n";
			std::cin.clear();										// то возвращаем cin в 'обычный' режим работы
			std::cin.ignore(32767, '\n');							// и удаляем значения предыдущего ввода из входного буфера
			std::cout << string;
		}
		else // если всё хорошо и выполнятся условия, то возвращаем a
		{
			switch (condition)
			{
			case Natural_number:
				if (a > 0) { return a; }

				std::cout << "Вы должны ввести натуральное число\n";
				std::cin.ignore(32767, '\n');						// и удаляем значения предыдущего ввода из входного буфера
				continue;

			case O_Or_1:												// На будущее

				if ((a == 0) || (a == 1)) { return a; }

				std::cout << "Вы должны ввести либо 0, либо 1\n";
				std::cin.ignore(32767, '\n');						// и удаляем значения предыдущего ввода из входного буфера
				continue;

			case Menu_Commands:

				if (((int)a > 0) && ((int)a < 10)) { return a; }

				std::cout << "У меню всего 8 функций! Повторите ввод: ";
				std::cin.ignore(32767, '\n');						// и удаляем значения предыдущего ввода из входного буфера
				continue;

			default:
				return a;
			}

		}

	}
}



void show_menu()
{
	std::cout << "\n  Функционал программы:\n"
		<< "1. Добавление нового элемента\n"
		<< "2. Удаление заданной вершины\n"
		<< "3. Поиск заданной вершины\n"
		<< "4. Прямой обход дерева\n"
		<< "5. Симметричный обход дерева\n"
		<< "6. Вывести вершины в строчку\n"
		<< "7. Показать главное меню\n"
		<< "8. Вывести автора программы\n"
		<< "9. Завершение работы\n";
}

void write_author()
{
	std::cout << "Работу выполнил Калеев Д.А гр. 4211\n";
}

void search(Search_Tree* root, int key)
{
	Search_Tree* current = nullptr;

	if (current = *Non_Rec_Search(root, key))
	{
		std::cout << "Найденная вершина: адрес - " << current << "\t ключ: " << current->key << "\t Счетчик: " << current->count << std::endl;
	}
	else
	{
		std::cout << "Заданная вершина не найдена\n";
	}
}

void AddNode(Search_Tree*& root)
{
	int user_input;
	if (root)
	{
		std::cout << "Введите ключ новой вершины: ";
		user_input = getValue(Natural_number, "Выберите функцию: ");
		Add_Node_NoR(root, user_input);
	}
	else
	{
		std::cout << "Какое количество вершин добавить? Введите: ";
		user_input = getValue(Natural_number, "Выберите функцию: ");
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
		std::cout << "\nВыберите функцию: ";
		user_input = getValue(Menu_Commands, "Выберите функцию: ");

		if (user_input == Exit) { return; }

		if (user_input == Add_new_element) { AddNode(root); }
		else if ((user_input < 6) && (user_input > 1)) { std::cout << "Дерево пустое!\n"; }
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
		std::cout << "\nВыберите функцию: ";
		user_input = getValue(Menu_Commands, "Выберите функцию: ");

		switch (user_input)
		{

		case Add_new_element:
			AddNode(root);
			break;

		case Delete:
			std::cout << "Введите ключ удаляемой вершины: ";
			user_input = getValue(Natural_number, "Выберите функцию: ");
			Delete_Node(root, user_input);
			break;

		case Find:
			std::cout << "Введите ключ искомой вершины: ";
			user_input = getValue(Natural_number, "Выберите функцию: ");
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
			//std::cout << "У меня только 8 функций!\n";
			break;
		}
	}

	std::cout << "Зaвершение работы!\n";
	clean_memory(root);
}