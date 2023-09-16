#include "Data.h"

template<typename T1, typename T2>
void command_processing(std::string& command, Registry<T1, T2>& firstTest)
{
	T1 key;
	T2 value;
	std::cout << "Commands:\nAdd.\nRemove\nPrint\nFind\nExit " << std::endl;
	std::cout << "Enter the command: ";
	std::cin >> command;

	if (command == "Add" || command == "add")
	{
		std::cout << "Enter the key: ";
		std::cin >> key;

		std::cout << "Enter the value: ";
		std::cin >> value;

		firstTest.add(key, value);
	}
	else if (command == "Remove" || command == "remove")
	{
		std::cout << "Enter the key: ";
		std::cin >> key;

		firstTest.remove(key);
	}
	else if (command == "Print" || command == "print")
	{
		firstTest.print();
	}
	else if (command == "Find" || command == "find")
	{
		std::cout << "Enter the key: ";
		std::cin >> key;

		firstTest.find(key);
	}
}

int main()
{
	std::string command;
	
	Registry<std::string, int> firstTest;
	while (command != "Exit" && command != "exit")
	{
		std::cout << "First test: <key - std::string, value - int>." << std::endl;

		command_processing(command, firstTest);
	}

	Registry<int, std::string> secondTest;
	while (command != "Exit" && command != "exit")
	{
		std::cout << "First test: <key - int, value - std::string>." << std::endl;

		command_processing(command, secondTest);
	}

	Registry<double, int> thirdTest;
	while (command != "Exit" && command != "exit")
	{
		std::cout << "First test: <key - double, value - int>." << std::endl;

		command_processing(command, thirdTest);
	}

	return 0;
}