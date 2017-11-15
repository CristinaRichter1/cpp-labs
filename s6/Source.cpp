// Sa se creeze clasa Card cu atributele: tip - enum typCard;
// numar - vector de char (16 caractere);
// Sa se creeze clasa Client cu atributele : nume - vector de char;
// valoareCumparaturi - float; card - type card
// Pentru fiecare clasa sa se implementeze constructor implicit 
// si explicit, destructor, metode de access si modificare,
// constructor de copiere, operator egal

#include <iostream>
using namespace std;

enum TipCard {
	CardCredit,
	CartDebit
};

class Card {
private:
	TipCard tipCard;
	int numarCard[16];

public:

	Card() {
		this->tipCard = CardCredit;
		for (int i = 0; i < 16; i++) {
			this->numarCard[i] = 1;
		}
	}

	Card(TipCard tipCardNou, int numarCardNou[16]) {
		this->tipCard = tipCardNou;
		for (int i = 0; i < 16; i++) {
			this->numarCard[i] = numarCardNou[i];
		}
	}

	int* getNumarCard() {
		return this->numarCard;
	}

	void setNumarCard(int numarCardNou[16]) {
		bool isValid = true;

		for (int i = 0; i < 16; i++) {
			if (numarCardNou[i] < 0 || numarCardNou[i] > 10) {
				isValid = false;
			}
		}

		if (isValid == true) {
			for (int j = 0; j < 16; j++) {
				this->numarCard[j] = numarCardNou[j];
			}
		}
	}

	Card(Card& cardNou) {
		this->tipCard = cardNou.tipCard;
		for (int i = 0; i < 16; i++) {
			this->numarCard[i] = cardNou.numarCard[i];
		}
	}

	~Card() {
		cout << "Destructor called";
	}
};

class Client {
private:
	char* nume;
	float valoareCumparaturi;
	Card* card;

public:

	Client() {
		this->nume = new char[strlen("ion") + 1];
		strcpy(this->nume, "ion");
		this->valoareCumparaturi = 20;
		this->card = new Card();
	}

	Client(char* numeNou, float valoareNou, Card card) {
		this->nume = new char[strlen(numeNou) + 1];
		strcpy(this->nume, numeNou);
		this->valoareCumparaturi = valoareNou;
		this->card = new Card(card);
	}

	float getValoreCumparaturi() {
		return this->valoareCumparaturi;
	}

	void setValoareCumparaturi(float valoareNou) {
		if(valoareNou > 0){
			this->valoareCumparaturi = valoareNou;
		}
	}

	Client(Client& clientNou) {
		delete this->nume;
		this->nume = new char[strlen(clientNou.nume) + 1];
		strcpy(this->nume, clientNou.nume);
		this->valoareCumparaturi = clientNou.valoareCumparaturi;
		delete this->card;
		this->card = new Card(*clientNou.card);
	}

	void operator=(Client& clientNou) {
		delete this->nume;
		this->nume = new char[strlen(clientNou.nume) + 1];
		strcpy(this->nume, clientNou.nume);
		this->valoareCumparaturi = clientNou.valoareCumparaturi;
		delete this->card;
		this->card = new Card(*clientNou.card);
	}

	~Client() {
		cout << "Destructor Client called";
		delete this->nume;
	}
};

int main() {
	Card c;
	Client client;
	Client client2("vasile", 100, c);

	return 0;
}