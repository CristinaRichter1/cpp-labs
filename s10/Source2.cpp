#include <iostream>
using namespace std;


class Masina {
public:
	virtual float getValoare(int ani) = 0;
};

class MasinaSport : public Masina {
private:
	char* categorie = NULL;
	float valoare = 100;

public:
	MasinaSport() {
		this->categorie = new char[strlen("supersport") + 1];
		strcpy(this->categorie, "supersport");
	}

	float getValoare(int ani) {
		cout << "getValoare MasinaSport" << endl;
		return this->valoare - (this->valoare * 0.20 * ani);
	}
};

class MasinaEpoca : public Masina {
private:
	char* perioada = NULL;
	float valoare;
public:
	MasinaEpoca() {
		this->perioada = new char[strlen("interbelica") + 1];
		strcpy(this->perioada, "interbelica");
		this->valoare = 100;
	}

	float getValoare(int ani) {
		cout << "getValoare MasinaEpoca" << endl;
		return this->valoare + (this->valoare * 0.10 * ani);
	}
};

int main() {
	Masina** masini = new Masina*[3];
	masini[0] = new MasinaSport();
	masini[1] = new MasinaSport();
	masini[2] = new MasinaEpoca();

	int totalValoare = 0;

	for (int i = 0; i < 3; i++) {
		totalValoare = masini[i]->getValoare(3) + totalValoare;
	}

	cout << "Total valoare " << totalValoare;

	return 0;
}