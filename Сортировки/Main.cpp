
#include <clocale> //Обязательно для функции setlocale()
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>
#include <vector>
using namespace std;

vector<char> comb(vector<char> sort, int &n)// sort-название массива, size-размер массива,если нужно ввести массив с клавиатуры, то нужно создать динамический массив
{
	// количество перестановок
	double fakt = 1.2473309; // фактор уменьшения
	double step = sort.size() - 1;

	while (step >= 1)
	{
		for (int i = 0; i + step < sort.size(); ++i)
		{
			if (sort[i] > sort[i + step])
			{
				swap(sort[i], sort[i + step]);
				n++;
			}
		}
		step /= fakt;
	}
	// сортировка пузырьком
	for (int i = 0; i < sort.size() - 1; i++)
	{
		bool swapped = false;
		for (int j = 0; j < sort.size() - i - 1; j++)
		{
			if (sort[j] > sort[j + 1]) {
				swap(sort[j], sort[j + 1]);
				swapped = true;
				++n;
			}
		}

		if (!swapped)
			break;
	}
	return sort;
}

int main()
{
	srand(time(NULL)*time(NULL));
	setlocale(LC_ALL, "russian");
	cout << "Размер массива: 50";

	int size = 50;// Длинна массива
	std::cout << endl << "-----------------------------------------------------------------------" << endl << "Изначальный массив: ";

	//-----------------------------------------------------------------------------------------
	
	vector<char> arr(size); // Одномерный динамический массив
	for (int counter = 0; counter < size; counter++)
	{
		arr[counter] = char(rand() % 26 + 97);//(int)rand()%10 +1; // Заполняем массив случайными буквами
		cout << setw(3) << arr[counter] << " "; // Вывод массива на экран
	}
	cout << endl << endl;

	//-----------------------------------------------------------------------------------------
	char temp; // Временная переменная для обмена элементов местами
	int counter = 0;
	// Сортировка массива пузырьком

	auto start = chrono::high_resolution_clock::now();
	vector<char> arr2 = comb(arr, counter);
	auto finish = chrono::high_resolution_clock::now();
	auto time = chrono::duration_cast<chrono::microseconds>(finish - start).count();
	cout << "-----------------------------------------------------------------------" << endl;

	//-----------------------------------------------------------------------------------------

	// Вывод отсортированного массива на экран
	cout << "Отсортированный массив: ";
	for (int i = 0; i < size; i++)
	{
		cout << setw(3) << arr2[i] << " ";
	}

	//-----------------------------------------------------------------------------------------

	cout << endl << endl << "-----------------------------------------------------------------------" << endl;
	cout << "Колличество итераций: " << counter << endl;
	cout << "Время: " << time << endl;
	std::fstream file("Одномерный массив буквы точности.txt", std::ios::out | std::ios::app);
	if (file.is_open())
	{
		file << "Количество итераций " << counter << "; Время: " << time << " микросекунд; " << std::endl;
	}
	file.close();
		
	system("pause");
	return 0;
}

