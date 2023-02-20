#include <iostream>
#include <fstream>
using namespace std;

struct employee
{
	int num;
	char name[10];
	double hours;
};

int main(int argc, char* argv[]) {
	char* name = argv[1];
	char* name2 = argv[2];
	int money = atoi(argv[3]);

	ifstream fin(name, ios::binary);
	ofstream file(name2);

	employee* e1 = new employee[100];
	int size = 0;
	while (fin.peek() != EOF)
	{
		employee o;
		fin.read((char*)&o, sizeof(struct employee));
		e1[size++] = o;
	}

	file <<"Отчет по файлу \"" <<name<<"\"\n";
	file << "Номер сотрудника\t имя сотрудника\t часы \t зарплата\n";
	for (int i = 0; i < size; i++) {
		file << e1[i].num << "\t" << e1[i].name << "\t" << e1[i].hours << "\t" << e1[i].hours * money << "\n";
	}
	

	fin.close();
	file.close();


	system("pause");
	return 0;
}