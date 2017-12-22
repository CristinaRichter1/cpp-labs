#include <iostream>
using namespace std;


class Masina {
private:
	char* model = NULL;
	float valoare;

public:
	Masina() {
		this->model = new char[strlen("default") + 1];
		strcpy(this->model, "default");
		this->valoare = 100;
	}

	virtual float getValoare(int ani) = 0;

	float getValoare() {
		return this->valoare;
	}
};

class MasinaSport : public Masina {
private:
	char* categorie = NULL;

public:
	MasinaSport() : Masina() {
		this->categorie = new char[strlen("supersport") + 1];
		strcpy(this->categorie, "supersport");
	}

	float getValoare(int ani) {
		cout << "getValoare MasinaSport" << endl;
		return Masina::getValoare() - (Masina::getValoare() * 0.20 * ani);
	}
};

class MasinaEpoca : public Masina {
private:
	char* perioada = NULL;
public:
	MasinaEpoca() : Masina() {
		this->perioada = new char[strlen("interbelica") + 1];
		strcpy(this->perioada, "interbelica");
	}

	float getValoare(int ani) {
		cout << "getValoare MasinaEpoca" << endl;
		return Masina::getValoare() + (Masina::getValoare() * 0.10 * ani);
	}
};

int main2() {
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