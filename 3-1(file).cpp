/*—формировать текстовый файл, в который записывает фамилии людей 
и их заработную плату за мес¤ц.
¬ывести на экран фамилию человека с самым высоким доходом.*/
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <io.h>

using namespace std;

void AddFile();
void readFile();

class sportMANs
{
private:
public:
	string name;
	int yers;
	int result;

	sportMANs()
	{
		name = "empty";
		yers = result = 0;

	}
	sportMANs(string name, int yers, int result) {
		this->name = name;
		this->yers = yers;
		this->result = result;
	}	

	void SetsportMANs(sportMANs arr[], int length) 
	{
		for (int i = 0; i < length; i++)
		{
			cout << "name: ";   cin >> arr[i].name; cout << endl;
			cout << "yers: ";   cin >> arr[i].yers; cout << endl;
			cout << "result: "; cin >> arr[i].result; cout << endl;
		}
	};

	void print(sportMANs arr[],int length) 
	{
		for (int i = 0; i < length; i++)
		{
			cout << "name: " << arr[i].name << endl;
			cout << "yers: " << arr[i].yers << endl;
			cout << "result: " << arr[i].result << endl;
			cout << endl;
		}
	}
	friend ostream& operator<<(ostream& os, const sportMANs& point);
	friend istream& operator>>(istream& is, sportMANs& point);
	friend void AddFile();
	friend void readFile();
};

ostream& operator<<(ostream& os, const sportMANs& point)
{
	os << point.name << " " << point.yers << " " << point.result<<"\n";
	return os;
}

istream& operator>>(istream& is, sportMANs& point)
{
	is >> point.name >> point.yers >> point.result;
	return is;
}

void AddFile() {
	string path = "file.txt";//	cin>>path;//создаем новое название файла если надо:
	int length;//число(дл¤ массива  ласса)
	cout << "введите число участиков : ";   cin >> length;
	cout << endl;

	int *arrMan = new int[length];
	sportMANs *addNewMans = new sportMANs[length];

	addNewMans->SetsportMANs(addNewMans, length);

	fstream fs;
	fs.open(path, fstream::in | fstream::out | fstream::app);
	if (!fs.is_open())
	{
		cout << "~incorect file name~!" << endl;
	}
	else
	{
		cout << "~file_is_open~!" << endl;
		for (int j = 0; j < length; j++)
		{
			SetConsoleCP(1251);
			fs << addNewMans[j].name << " " << addNewMans[j].yers << " " <<addNewMans[j].result<< "\n";
			SetConsoleCP(866);
		}
		cout << "value saved!" << endl;
		cout << endl;
	}
	fs.close();
	delete[] addNewMans;
}

void readFile() 
{
	fstream fs1;
	string path = "file.txt";
	cout<<"choise file "<<endl;
	//cin >> path;//создаем новое название файла если надо
	string name = "";
	int years, result, length, sizeM;
	years = result = 0;
	length = 5000;

	char *str = new char[length];
	sizeM = 0;
	ifstream base(path);
	while (true)
	{
		base.getline(str, length, '\n');
		if (base.eof()) { break; }
		sizeM++;
	}
	base.close();
	delete[] str;

	sportMANs *oldMans = new sportMANs[sizeM];

	fs1.open(path, fstream::in | fstream::out | fstream::app);

	if (!fs1.is_open())
	{
		cout << "~file not faund~!" << endl;
	}
	else
	{
		cout << "file opened!" << endl;
		while (true)
		{
			int max, index, xxx=0;
			max = index = 0;
			for (int i = 0; i <= sizeM; i++)
			{
				SetConsoleCP(1251);
				fs1 >> name >> years >> result;
				if (fs1.eof())
				{
					break;
				}
				oldMans[i].name = name;
				oldMans[i].yers = years;
				oldMans[i].result = result;
					if (oldMans[i].result > max) 
					{
					max = oldMans[i].result;
					index = i;
					}
				SetConsoleCP(866);
			}
			cout << "----------------------- " << endl;
				cout << "max num is a player " << endl;
					cout << oldMans[index].name << endl;
					cout << oldMans[index].yers << endl;
					cout << oldMans[index].result << endl;
					cout << "----------------------- " << endl;
			if (fs1.eof())
			{
				break;
			}
		}fs1.close();
	}
	oldMans->print(oldMans, sizeM);
	delete[] oldMans;
};

void welcom() {
	int switch_on, rerollo = true;
	cout << "choise:" << endl;
	cout << "one(1):new file or add write" << endl;
	cout << "one(2):read file" << endl;
	cout << "zero(0):to exit" << endl;
	cin >> switch_on;
	while (rerollo)
	{
		switch (switch_on)
		{
		case 1:AddFile();  rerollo = false; break;
		case 2:readFile(); rerollo = false; break;
		case 0: cout << "zero = goodbye" << endl; rerollo = false; break;
		default:cout << "incorrect Num" << endl;break;
		}
	}
}

int main() 
{	setlocale(LC_ALL, "rus");
welcom();
	system("pause");
	return 0;
}