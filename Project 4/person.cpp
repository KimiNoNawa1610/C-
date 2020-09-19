#include<iostream>
using namespace std;
class person {
private:
	string name;
	float salary;
public:
	void setPerson();
	string getName();
	float getSalary();

};

void person::setPerson() {
	cout << "Please enter a name:" << endl;
	cin >> name;
	cout << "Please enter that person salary:" << endl;
	cin >> salary;
}

string person::getName() {
	return name;
}

float person::getSalary() {
	return salary;
}

void order(person** a, person** b) {
	person *temp;
	temp = *a;
	*a = *b;
	*b = temp;

}

void bsort(person** p, int n, bool s) {
	bool isSorted = false;
	while (isSorted == false) {
		isSorted = true;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (s == true) {
					if (p[i]->getName() > p[j]->getName()) {
						order(&p[i], &p[j]);
						isSorted = false;
					}
				}
				else {
					if (p[i]->getSalary() > p[j]->getSalary()) {
						order(&p[i], &p[j]);
						isSorted = false;
					}
				}
			}
		}
	}
}

void bsort_nonOrder(person** p, int n, bool s) {
	bool isSorted = false;
	while (isSorted == false) {
		isSorted = true;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				person* temp;
				if (s == true) {
					if (p[i]->getName() > p[j]->getName()) {
						temp = p[j];
						p[j] = p[i];
						p[i] = temp; 
						isSorted = false;
					}
				}
				else {
					if (p[i]->getSalary() > p[j]->getSalary()) {
						temp = p[j];
						p[j] = p[i];
						p[i] = temp;
						isSorted = false;
					}
				}
			}
		}
	}
}

void Display(person **p, int n) {
	cout << "Name" << " | " << "Salary" << endl;
	cout << "------------" << endl;
	for (int i = 0; i < n; i++) {
		cout << p[i]->getName() << " | " << p[i]->getSalary()<<endl;
	}
}

int main() {
	person** arr;
	int n;
	cout << "please enter the size of the array" << endl;
	cin >> n;
	arr = new person *[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new person();
		arr[i]->setPerson();
	}
	cout << "Unsorted Person Array:" << endl;
	Display(arr, n);
	cout << endl;
	cout << "Sorted Person Array by name" << endl;
	bsort(arr, n, true);
	Display(arr, n);
	cout << endl;
	cout << "Sorted Person Array by salary" << endl;
	bsort(arr, n, false);
	Display(arr, n);
	return 0;
}