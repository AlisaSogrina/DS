#include <iostream>
#include <thread>

using namespace std;

struct Parameter {
	int size;
	double* coefficients;
	double x;
	double result = 0;
};

int main() {

	int time = 15;

	cout << "Please enter up polynom power:" << "\n";
	int Pn;
	cin >> Pn;

	cout << "\n" << "Please enter up polynom coefficients:" << "\n";
	double* Pcoefficients = new double[Pn];
	for (int i = 0; i < Pn; i++) {
		cin >> Pcoefficients[i];
	}

	cout << "\n" << "Please enter down polynom power:" << "\n";
	int Qn;
	cin >> Qn;

	cout << "\n" << "Please enter down polynom coefficients:" << "\n";
	double* Qcoefficients = new double[Qn];
	for (int i = 0; i < Qn; i++) {
		cin >> Qcoefficients[i];
	}

	cout << "\n" << "Please enter x:" << "\n";
	double x;
	cin >> x;

	Parameter parameter1;
	parameter1.x = x;
	parameter1.size = Pn;
	parameter1.coefficients = Pcoefficients;

	thread thread1([&]()
		{
			double result = 0;
			for (int i = 0; i < parameter1.size; i++) {
				double addend = parameter1.coefficients[i];
				for (int j = 0; j < parameter1.size - i; j++) {
					addend *= parameter1.x;
				}
				result += addend;
				this_thread::sleep_for(std::chrono::milliseconds(time));
			}

			parameter1.result = result;
			cout << "\n" << "p(" << parameter1.x << ") = " << result << "\n";
		});

	Parameter parameter2;
	parameter2.x = x;
	parameter2.size = Qn;
	parameter2.coefficients = Qcoefficients;

	thread thread2([&]()
		{
			double result = 0;
			for (int i = 0; i < parameter2.size; i++) {
				double addend = parameter2.coefficients[i];
				for (int j = 0; j < parameter2.size - i; j++) {
					addend *= parameter2.x;
				}
				result += addend;
				this_thread::sleep_for(std::chrono::milliseconds(time));
			}

			parameter2.result = result;
			cout << "\n" << "p(" << parameter2.x << ") = " << result << "\n";
		});

	thread1.join();
	thread2.join();

	cout << "f(" << x << ") = " << parameter1.result / parameter2.result;

	return 0;
}