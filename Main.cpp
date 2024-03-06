#include <iostream>

#include <set>
#include <map>
#include <unordered_set>

#include <vector>
#include <string>
#include <random>


void  DemoBase() 
{
	std::vector<int> initialData;
	initialData.reserve(100);
	//======================================================
	std::random_device rd;                                  // источник истинно случайных чисел
	std::mt19937 provider(rd());                         // генератор случайных чисел похожий на rand, начальное значение задано случайно
	std::uniform_int_distribution<int>distributor(10, 90);// класс доставщик чисел. distributor - для предоставления значений в нужном диапазоне. 
	//======================================================
	for (int i = 0; i < initialData.capacity(); i++)
	{
		initialData.push_back(distributor(provider));
	}
	//======================================================
	//std::vector<int> uniqueData;
	//for (auto& Element : initialData)
	//{
	//	bool flag{ true };
	//	for (auto& uElement : uniqueData) 
	//	{
	//		if (Element == uElement)
	//		{
	//			flag = false;
	//			break;
	//		}
	//	}
	//	if (flag)
	//	{
	//		uniqueData.push_back(Element);						
	//	}
	//}

	//вариант через set работает в ахренеть раз быстрее
	std::set<int> uniqueData;
	for (auto& Element : initialData)
	{
		uniqueData.insert(Element);
	}	
	//=====================================================
	std::cout << "Atall elements: " << initialData.size() << '\n';
	for (auto& i : initialData)
	{
		std::cout << i << ' ';
	}
	std::cout << std::endl;
	std::cout << "Unique elements: " << uniqueData.size() << '\n';
	for (auto& i : uniqueData)
	{
		std::cout << i << ' ';
	}
}

class A{
public:
	bool operator<(const A& other)const { return bool(); }
};

namespace std {  //запись новой штуки в пространство имен std

	template<>
	struct less<A> 
	{
		bool operator()(const A& a, const A& b)const
		{
			return bool();
		}
	};
	// перегрузка свойства типа по признаку сравниваемости, \
	таким образом мы можем научить работать с нашим типом стандартную библиотеку языка не нагружая функционал класса наследуемыми элементами
}


struct MyStruct {
	std:: string id;
	std::string name;
	std::string patrinomyc;
	std:: string surename;
};



int main() {
	setlocale(LC_ALL, "ru");

	//DemoBase();
	std::set<A> obj;
	obj.insert(A());
	A z, x;
	obj.contains(z);

	std::map <std::string, MyStruct> dictionary;
	std::vector <MyStruct> data{
		{"q123r15", "Jack", "Vitalievich", "Frolov"},
		{"q123r15", "Jack", "Vitalievich", "Frolov"},
		{"q123r13", "Black", "Shluhovich", "Prolov"},
		{"q133r117", "Shmack", "Mudovich", "Grolov"},
		{"q193r10", "Chack", "Goblinich", "Rolov"},
		{"q250r55", "Crack", "Mudinich", "Fov"},
		{"q323r90", "Drack", "Zvodinich", "Jhlov"}
	};
	for (size_t i = 0; i < data.size(); i++)
	{
		if (!dictionary.contains(data[i].id))
		{
			dictionary.insert({ data[0].id,data[0] });
		}
		else
		{
			std::cout << "Didn't insert data:\n" <<
				data[i].id << '\n' <<
				data[i].name << '\n' <<
				data[i].patrinomyc << '\n' <<
				data[i].surename << '\n' <<
				" this data already has: \n" <<
				dictionary[data[i].id].id << '\n' <<
				dictionary[data[i].id].name << '\n' <<
				dictionary[data[i].id].patrinomyc << '\n' <<
				dictionary[data[i].id].surename << '\n';
		}
	}


	return 0;
}