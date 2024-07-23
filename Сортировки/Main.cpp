
#include <clocale> //����������� ��� ������� setlocale()
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>
#include <vector>
using namespace std;

vector<char> comb(vector<char> sort, int &n)// sort-�������� �������, size-������ �������,���� ����� ������ ������ � ����������, �� ����� ������� ������������ ������
{
	// ���������� ������������
	double fakt = 1.2473309; // ������ ����������
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
	// ���������� ���������
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
	cout << "������ �������: 50";

	int size = 50;// ������ �������
	std::cout << endl << "-----------------------------------------------------------------------" << endl << "����������� ������: ";

	//-----------------------------------------------------------------------------------------
	
	vector<char> arr(size); // ���������� ������������ ������
	for (int counter = 0; counter < size; counter++)
	{
		arr[counter] = char(rand() % 26 + 97);//(int)rand()%10 +1; // ��������� ������ ���������� �������
		cout << setw(3) << arr[counter] << " "; // ����� ������� �� �����
	}
	cout << endl << endl;

	//-----------------------------------------------------------------------------------------
	char temp; // ��������� ���������� ��� ������ ��������� �������
	int counter = 0;
	// ���������� ������� ���������

	auto start = chrono::high_resolution_clock::now();
	vector<char> arr2 = comb(arr, counter);
	auto finish = chrono::high_resolution_clock::now();
	auto time = chrono::duration_cast<chrono::microseconds>(finish - start).count();
	cout << "-----------------------------------------------------------------------" << endl;

	//-----------------------------------------------------------------------------------------

	// ����� ���������������� ������� �� �����
	cout << "��������������� ������: ";
	for (int i = 0; i < size; i++)
	{
		cout << setw(3) << arr2[i] << " ";
	}

	//-----------------------------------------------------------------------------------------

	cout << endl << endl << "-----------------------------------------------------------------------" << endl;
	cout << "����������� ��������: " << counter << endl;
	cout << "�����: " << time << endl;
	std::fstream file("���������� ������ ����� ��������.txt", std::ios::out | std::ios::app);
	if (file.is_open())
	{
		file << "���������� �������� " << counter << "; �����: " << time << " �����������; " << std::endl;
	}
	file.close();
		
	system("pause");
	return 0;
}

