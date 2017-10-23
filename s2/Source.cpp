#include <iostream>
using namespace std;

struct Masina {
	int nrCrt;
	char* model;
	float valoare;
	bool manuala;

	float(*calculValoare)(Masina m, int ani);
};

void incarcaMasina(Masina* masina) {
	cout << "nrCrt :";
	cin >> masina->nrCrt;

	cout << "Model :";
	char buffer[100];
	cin >> buffer;
	masina->model = new char(strlen(buffer) + 1);
	strcpy(masina->model, buffer);

	cout << "Valoare :";
	cin >> masina->valoare;

	cout << "Este manuala? ";
	cin >> masina->manuala;
}

void afiseazaMasina(Masina masina) {
	cout << "nrCrt : " << masina.nrCrt << " Valoare :"
		<< masina.valoare << " model : " << masina.model
		<< " manuala :" << (masina.manuala ? "da" : "nu");

	//(conditie ? adevarat : fals)
	// if(masina.manuala == true) cout<< "da" else cout<<"nu"
}

float calculValoareMasinaSport(Masina m, int ani) {
	return m.valoare - (ani * (0.10 * m.valoare));
}

float calculValoareMasinaEpoca(Masina m, int ani) {
	return m.valoare + (ani * (0.10 * m.valoare));
}
 int main() {
	Masina masinaEpoca;

	masinaEpoca.calculValoare = &calculValoareMasinaEpoca;
	incarcaMasina(&masinaEpoca);
	afiseazaMasina(masinaEpoca);

	Masina masinaSport;
	masinaSport.calculValoare = &calculValoareMasinaSport;
	incarcaMasina(&masinaSport);
	afiseazaMasina(masinaSport);

	cout << "Valoare masina epoca : " << masinaEpoca.calculValoare(masinaEpoca, 5);
	cout << "Valoare masina sport : " << masinaSport.calculValoare(masinaSport, 5);
	return 0;
}