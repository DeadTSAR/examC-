/*������������ ��������� ����, � ������� ���������� ������� ����� 
� �� ���������� ����� �� �����.
������� �� ����� ������� �������� � ����� ������� �������.*/
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <io.h>

using namespace std;

//fstream  - � ������, ������� ����� �������������� ��� �������� ����� - ������;
//ifstream - �������� ����; inPutFile
//ofstream - �������� �����.outPutfile

//	ofstream fout;
//	fout.open("file.txt");
//	fout << "������, ���!";
//	fout.close();


void AddFile();
void readFile();

class sportMANs
{
private:
public:
	string name;
	int yers;
	int result;

	
	//static int countMAN;
	sportMANs()
	{
		name = "empty";
		yers = result = 0;
		//countMAN = 0;
	}
	sportMANs(string name, int yers, int result) {
		this->name = name;
		this->yers = yers;
		this->result = result;
	//	//countMAN++;
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
	string path = "file.txt";//	cin>>path;//������� ����� �������� ����� ���� ����:
	int length;//�����(��� ������� ������)
	cout << "������� ����� ��������� : ";   cin >> length;
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
			//fs << "-----------------------" << endl;
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
	//cin >> path;//������� ����� �������� ����� ���� ����
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
				SetConsoleCP(866);
			}
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
	//---------------����������--file--------------//
	//AddFile();
	//--------------��������--file----------------//
	//readFile();

	system("pause");
	return 0;
}

//string msg;
//int value;
//*cout << "file is open" << endl;
//cout << "swith 1 to add info the file:" << endl; 
//cout <<	"swith 2 to get info the file:"  << endl;*/
//cin >> value;
//if (value == 1) {
//	cout << "������� ���������" << endl;
//	
//	SetConsoleCP(866);
//}
//if (value == 2) {
//	while (!fs.eof())
//	{
//		msg = "";
//		fs >> msg;
//		cout << msg << " " << endl;

/*ofstream fout;

//fout.open(path, ofstream::app); //������� � ��������� ���� ::app ��������� ���� � �� ������������
//if (!fout.is_open())//��������� ������ ����� ������ ����� ���� ����
//	{
//		cout << "error"<<endl;
//	}
//else
//	{
//	cout << "open file" << endl;
//	fout.write((char*)&P, siresulteof(point));
//	}

//fout.close();

ifstream fin;
fin.open(path);

if (!fin.is_open())	{cout << "incorect file name~!" << endl;}
else
{
	cout << "file is open" << endl;
	point virt;
	while (fin.read((char*)&virt, siageeof(point)))
	{
		virt.print();
	}

	//char ch;
	//while (fin.get(ch))
	//{
	//	cout << ch;
	//}
	//string str;
	//
	//cout << "string str;";
	//while (!fin.eof())
	//{
	//	str = "";
	//	getline(fin, str);
	//	//��� char str1[100]; fin.getline(str1, 100);
	//	cout << str << endl;
	//}
}
	fin.close();
	*/

//string msg;
					//int value;
					//*cout << "file is open" << endl;
					//cout << "swith 1 to add info the file:" << endl; 
					//cout <<	"swith 2 to get info the file:"  << endl;*/
					//cin >> value;
					//if (value == 1) {
					//	cout << "������� ���������" << endl;
					//	
					//	SetConsoleCP(866);
					//}
					//if (value == 2) {
					//	while (!fs.eof())
					//	{
					//		msg = "";
					//		fs >> msg;
					//		cout << msg << " " << endl;

//#include <iostream>
//#include <fstream>
//using namespace std;
//#define LINES 100 // ������������ ���������� ����� � �����
//
//														//int main() {
//	setlocale(LC_ALL, "rus");
//	char line[LINES][100];
//	char str[30];
//	char s[] = "|                              |                |                              |";
//							// ���� ������ ��� ����������� ������
//	cout << "���: ";
//	cin.getline(str, 30);	// ������ ���
//	for (int i = 0; str[i] != '\0'; i++) // �������� � ������ ��� 0
//		s[i + 2] = str[i];               // ������� � ��������� �������
//	cout << "����: ";
//	cin.getline(str, 30);
//	for (int i = 0; str[i] != '\0'; i++)
//		s[i + 33] = str[i];
//	cout << "�����: ";
//	cin.getline(str, 30);
//	for (int i = 0; str[i] != '\0'; i++)
//		s[i + 50] = str[i];
//
//	fstream inOut;
//	inOut.open("file3.txt", ios::in); // ��������� ���� ��� �����
//	// ��������� �� ����� ��������� ������
//	int count = 0;
//	while (inOut.getline(line[count], 100)) count++;
//	inOut.close(); // ��������� ����
//
//	inOut.open("file3.txt", ios::out); // ��������� ���� ��� ������
//	inOut << "--------------------------------------------------------------------------------" << endl;
//	inOut << "|               ���            |     ����        |           �����             |" << endl;
//	inOut << "--------------------------------------------------------------------------------" << endl;
//	inOut << s << endl; // ������� �������������� ������
//	inOut << "--------------------------------------------------------------------------------" << endl;
//	// ������� ������� � ���� ��� ������ ����� "�����" (������ 3 ������)
//	for (int j = 3; j < count; j++)
//	{
//		inOut << line[j] << endl;
//	}
//	inOut.close();
//	syersstem("pause");
//	//	return 0;
//	return 0;
//}
//