#pragma once
#include <iostream>
#include <vector>
#include <string>

template<typename T1, typename T2>
class Registry
{
private:
	// Вложенная структура данных;
	struct Data
	{
		T1 key;
		T2 value;
		Data(T1 key, T2 value) 
		{
			this->key = key;
			this->value = value;
		}
	};
	std::vector<Data> datas;
public:
	// Прототип метода добавляющего объект Data;
	void add(const T1& key, const T2& value)
	{
		Data temp(key, value);
		datas.emplace_back(temp);
	}
	// Метод удаляющих все элементы с заданым ключом;
	void remove(const T1& key)
	{
		for (auto it = datas.begin(); it != datas.end();)
		{
			if (it->key == key)
			{
				datas.erase(it);
				it = datas.begin();
			}
			else ++it;
		}
	}
	// Метод поиска объекта;
	void find(const T1& key)
	{
		for (auto it = datas.begin(); it != datas.end(); ++it)
			if (it->key == key)
				std::cout << it->key << " " << it->value << std::endl;
	}
	// Метод выводящий всю информацию в консоль;
	void print()
	{
		for (int i = 0; i < datas.size(); ++i)
			std::cout << datas[i].key << "\t" << datas[i].value << std::endl;
	}
};
