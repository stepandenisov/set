#include "Set.h"
#define menu "1)Добавить элемент\n2)Удалить элемент\n3)Проверить наличие элемента\n4)Вывести множество на экран\n0)Выход\n"
int main()
{
	setlocale(LC_ALL, "Russian");
	Set s;
	unsigned choice = 1;
	double value;
	while (choice)
	{
		cout << menu;
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			cout << "Введите значение для добавления: ";
			cin >> value;
			(s.insert(int(value))) ? cout << "Значение " << int(value)<< " успешно добавлено" << endl : cout << "Значение " << int(value)<< " уже есть" << endl;
			break;
		case 2:
			system("cls");
			cout << "Введите значение для удаления: ";
			cin >> value;
			(s.erase(int(value))) ? cout << "Значение " << int(value) << " успешно удалено" << endl : cout << "Значения " << int(value) << " нет в множестве" << endl;
			break;
		case 3:
			system("cls");
			cout << "Введите значение для проверки: ";
			cin >> value;
			(s.find(int(value))) ? cout << "Значение " << int(value) << " есть" << endl : cout << "Значения " << int(value) << " нет" << endl;
			break;
		case 4:
			system("cls");
			cout << "Множество:\n";
			cout << s;
			cout << endl;
			break;
		case 0:
			system("cls");
			cout << "Продолжить с пустым множеством?\n1)Да\n2)Нет" << endl;
			cin >> value;
			if (value == 1)
			{
				choice = 1;
				s.clear();
				system("cls");
				break;
			}
			else
			{
				choice = 0;
				system("cls");
				break;
			}
		}
	} 
	return 0;
}

