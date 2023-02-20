#include <iostream>
#include <fstream>
#include "windows.h"
#include <string>
#pragma warning(disable : 4996)
using namespace std;

struct employee
{
	int num;
	char name[10];
	double hours;
};

void runCreatorProcess(char*& name, int n) {
	char data[200] = "Creator ";
	char* a = strcat(name, " ");
	char* b = strcat(data, a);
	char* creator = new char[100];
	strcpy(creator, strcat(b, to_string(n).c_str()));

	cout << creator << "\n";

	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);

	if (!CreateProcess("C:\\Users\\Professional\\source\\repos\\OS_A\\x64\\Debug\\Creater.exe", creator, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi))
	{
		cout << "The new process is not created.\n";
		return;
	}

	WaitForSingleObject(pi.hProcess, INFINITE);

	CloseHandle(pi.hThread);
	CloseHandle(pi.hProcess);
}

void readBinaryFile(char* name) {
	ifstream fin(name, ios::binary);
	while (fin.peek() != EOF)
	{
		employee o;
		fin.read((char*)&o, sizeof(employee));
		cout << o.num << " " << o.name << " " << o.hours << "\n";
	}
	fin.close();
}

void runReporterProcess(char* name, char* name2, int k) {
	char data[200] = "Reporter ";
	char* a = strcat(data, name);
	char* b = strcat(a, " ");
	char* c = strcat(b, name2);
	char* d = strcat(c, " ");
	char* reporter = new char[200];
	strcpy(reporter, strcat(d, to_string(k).c_str()));

	cout << reporter << "\n";

	STARTUPINFOA si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(STARTUPINFOA));
	si.cb = sizeof(STARTUPINFOA);


	if (!CreateProcess("C:\\Users\\Professional\\source\\repos\\OS_A\\x64\\Debug\\Reporter.exe", data, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi))
	{
		cout << "The reporter process is not created.\n";
		return;
	}

	WaitForSingleObject(pi.hProcess, INFINITE);

	CloseHandle(pi.hThread);
	CloseHandle(pi.hProcess);
}

void readFile(char* name2) {
	ifstream fin(name2);

	char line[200];
	while (!fin.eof())
	{
		fin.getline(line, 200);
		cout << line << "\n";
	}

	fin.close();
}

int main() {
	char* name = new char[100];
	int n;
	cout << "Please, enter binary file name and employees amount \n";
	cin >> name;
	cin >> n;

	runCreatorProcess(name, n);
	cout << "\n";

	readBinaryFile(name);

	char* name2 = new char[100];
	int k;
	cout << "\nPlease, enter output file(txt) name and the price \n";
	cin >> name2;
	cin >> k;

	runReporterProcess(name, name2, k);

	readFile(name2);

	return 0;
}