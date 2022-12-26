#include <iostream>

using namespace std;

class Predator
{
public:

	Predator() {

		name = nullptr;

		spdistrib = nullptr;

		amountoffood = 0;
	}
	Predator(const char* name, const char* spdistrib, float amountoffood) {

		this->name = new char[strlen(name) + 1];
		this->spdistrib = new char[strlen(spdistrib) + 1];

		strcpy_s(this->name, strlen(name) + 1, name);

		strcpy_s(this->spdistrib, strlen(spdistrib) + 1, spdistrib);
		this->amountoffood = amountoffood;
	}
	~Predator() {

		cout << "Erased: " << name << " " << spdistrib << endl;

		delete name;

		delete spdistrib;
	}

	void Display() {
		cout << "Name: " << name << endl;

		cout << "Species distribution: " << spdistrib << endl;

		cout << "Amount of food (kg for day): " << amountoffood << endl;

	}

private:

	char* name;

	char* spdistrib;

	float amountoffood;

};

int main()
{
	cout << endl;

	Predator firstPred("Wolf", "Tundra", 10);

	firstPred.Display();

	cout << endl;
	cout << endl;

	Predator secPred("Felis silvestris", "Central and Southern Europe, Asia Minor and the Caucasus", 3.6);

	void (Predator:: * Funcptr) ();

	Funcptr = &Predator::Display;


	(secPred.*Funcptr) ();

	cout << endl;
	cout << endl;

	Predator* instanceptr = new Predator("Phocids", "Along coastlines in cold and temperate waters of both hemispheres", 7);

	instanceptr->Display();

	cout << endl;
	cout << endl;

	delete instanceptr;
}
