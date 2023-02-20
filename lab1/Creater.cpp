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
	int count = atoi(argv[2]);

	ofstream file(name, ios::binary);

	cout << "Please, enter employees info (number, name, hours) " << count << " times\n";
	for (int i = 0; i < count; i++) {
		employee e1;

		cin >> e1.num >> e1.name >> e1.hours;


		file.write((char*)&e1, sizeof(employee));
	}

	file.close();
	system("pause");
	return 0;
}