#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

enum Tip { PCR, rapid_Covid, anticorpi_Covid };

class Angajat {
private:
	char* numePrenume;
	int cnp;
	float salariuNet;
	bool areExperientaMinim3Ani;
	string functie;

public:
	Angajat() {
		this->numePrenume = NULL;
		this->cnp = 6050205087731;
		this->salariuNet = 1754;
		this->areExperientaMinim3Ani = 0;
		this->functie = "casier";
	}

	Angajat(const char* numePrenume, int cnp, float salariuNet, bool areExperientaMinim3Ani, string functie) {
		this->numePrenume = new char[strlen(numePrenume) + 1];
		strcpy_s(this->numePrenume, strlen(numePrenume) + 1, numePrenume);
		this->cnp = cnp;
		this->salariuNet = salariuNet;
		this->areExperientaMinim3Ani = areExperientaMinim3Ani;
		this->functie = functie;
	}

	float getSalariuNet() {
		return this->salariuNet;
	}

	void setSalariuNet(float salariuNet) {
		if (salariuNet>1000) {
			this->salariuNet = salariuNet;
		}
	}

	char* getNumePrenume() {
		return numePrenume;
	}

	void setNumePrenume(const char* numePrenume) {
		if (numePrenume && strlen(numePrenume) > 5) {
			if (this->numePrenume) {
				delete[] this->numePrenume;
			}
			this->numePrenume = new char[strlen(numePrenume) + 1];
			strcpy_s(this->numePrenume, strlen(numePrenume) + 1, numePrenume);
		}
	}

	Angajat(const Angajat& ang) {
		if (ang.numePrenume != NULL) {
			this->numePrenume = new char[strlen(ang.numePrenume) + 1];
			strcpy_s(this->numePrenume, strlen(ang.numePrenume) + 1, ang.numePrenume);
		}
		else {
			this->numePrenume = NULL;
		}
		this->cnp = ang.cnp;
		this->salariuNet = ang.salariuNet;
		this->areExperientaMinim3Ani = ang.areExperientaMinim3Ani;
		this->functie = ang.functie;
	}

	const Angajat& operator=(const Angajat& angajat) {
		if (this != &angajat) {
			if (angajat.numePrenume != NULL) {
				if (this->numePrenume != NULL) {
					delete[] this->numePrenume;
				}
				this->numePrenume = new char[strlen(angajat.numePrenume) + 1];
				strcpy_s(this->numePrenume, strlen(angajat.numePrenume) + 1, angajat.numePrenume);
			}
			else {
				this->numePrenume = NULL;
			}
			this->cnp = angajat.cnp;
			this->salariuNet = angajat.salariuNet;
			this->areExperientaMinim3Ani = angajat.areExperientaMinim3Ani;
			this->functie = angajat.functie;
		}
		return *this;
	}

	~Angajat() {
		if (this->numePrenume != NULL) {
			delete[] this->numePrenume;
		}
	}
	friend istream& operator>>(istream& introd, Angajat& ang) {
		char dim[25];
		introd >> dim;
		if (ang.numePrenume != NULL) {
			delete[] ang.numePrenume;
		}
		ang.numePrenume = new char[strlen(dim) + 1];
		strcpy_s(ang.numePrenume, strlen(dim) + 1, dim);
		introd >> ang.cnp;
		introd >> ang.salariuNet;
		introd >> ang.areExperientaMinim3Ani;
		introd >> ang.functie;
		return introd;
	}

	friend ostream& operator<< (ostream & afisare, const Angajat& ang) {
		afisare << "Nume si prenume: " << ang.numePrenume << endl;
		afisare << "CNP: " << ang.cnp << endl;
		afisare << "Salariu net: " << ang.salariuNet << endl;
		afisare << "Are experienta de minim 3 ani? " << (ang.areExperientaMinim3Ani ? "DA" : "NU") << endl;
		afisare << "Functia angajatului: " << ang.functie << endl;
		return afisare;
	}

};


class Medicament {
private:
	string denumire;
	float pret;
	bool cuPrescriptieMedicala;
	int anExpirare;
	char* descriereAdministrare;
	static int TVA;

public:
	Medicament() {
		this->denumire = "Paracetamol";
		this->pret = 5.5f;
		this->cuPrescriptieMedicala = 0;
		this->anExpirare = 2025;
		this->descriereAdministrare = NULL;
	}

	Medicament(string denumire, float pret, bool cuPrescriptieMedicala, int anExpirare, const char* descriereAdministrare) {
		this->denumire = denumire;
		this->pret = pret;
		this->cuPrescriptieMedicala = cuPrescriptieMedicala;
		this->anExpirare;
		this->descriereAdministrare = new char[strlen(descriereAdministrare) + 1];
		strcpy_s(this->descriereAdministrare, strlen(descriereAdministrare) + 1, descriereAdministrare);
	}

	static int getTVA() {
		return TVA;
	}

	void static setTVA(int modificareTVA) {
		if (modificareTVA > 0)
			TVA = modificareTVA;
	}

	char* getDescriereAdministrare() {
		return descriereAdministrare;
	}

	void setDescriereAdministrare(const char* descriereAdministrare) {
		if (descriereAdministrare && (strlen(descriereAdministrare)) > 3) {
			if (this->descriereAdministrare) {
				delete[] this->descriereAdministrare;
			}
			this->descriereAdministrare = new char[strlen(descriereAdministrare) + 1];
			strcpy_s(this->descriereAdministrare, strlen(descriereAdministrare) + 1, descriereAdministrare);
		}
	}

	Medicament(const Medicament& med) {
		this->denumire = med.denumire;
		this->pret = med.pret;
		this->cuPrescriptieMedicala = med.cuPrescriptieMedicala;
		this->anExpirare = med.anExpirare;
		if (med.descriereAdministrare != NULL) {
			this->descriereAdministrare = new char[strlen(med.descriereAdministrare) + 1];
			strcpy_s(this->descriereAdministrare, strlen(med.descriereAdministrare) + 1, med.descriereAdministrare);
		}
		else {
			this->descriereAdministrare = NULL;
		}
	}

	const Medicament& operator=(const Medicament& med) {
		if (this != &med) {
			this->denumire = med.denumire;
			this->pret = med.pret;
			this->cuPrescriptieMedicala = med.cuPrescriptieMedicala;
			this->anExpirare = med.anExpirare;
			if (med.descriereAdministrare != NULL) {
				if (this->descriereAdministrare != NULL) {
					delete[] this->descriereAdministrare;
				}
				this->descriereAdministrare = new char[strlen(med.descriereAdministrare) + 1];
				strcpy_s(this->descriereAdministrare, strlen(med.descriereAdministrare) + 1, med.descriereAdministrare);
			}
			else {
				this->descriereAdministrare = NULL;
			}
		}
		return *this;
	}

	~Medicament() {
		if (this->descriereAdministrare != NULL) {
			delete[] this->descriereAdministrare;
		}
	}

	friend istream& operator>>(istream& citire, Medicament& m) {
		char cuvant[21];
		citire >> m.denumire;
		citire >> m.pret;
		citire >> m.cuPrescriptieMedicala;
		citire >> m.anExpirare;
		citire >> cuvant;
		if (m.descriereAdministrare != NULL) {
			delete[] m.descriereAdministrare;
		}
		m.descriereAdministrare = new char[strlen(cuvant) + 1];
		strcpy_s(m.descriereAdministrare, strlen(cuvant) + 1, cuvant);
		citire >> m.TVA;
		return citire;
	}

	friend ostream& operator<<(ostream& afisare, const Medicament& m) {
		afisare << "Denumire medicament: " << m.denumire << endl;
		afisare << "Pretul medicamentului: " << m.pret << endl;
		afisare << "Trebuie achizitionat doar cu prescriptie medicala?" << (m.cuPrescriptieMedicala ? "DA" : "NU") << endl;
		afisare << "Anul expirarii medicamentului: " << m.anExpirare << endl;
		afisare << "Cum se administreaza medicamentul?" << m.descriereAdministrare << endl;
		afisare << "TVA-ul aplicat medicamentului: " << m.TVA << endl;
		return afisare;
	}

};

int Medicament::TVA = 9;

class TestCovid {
private:
	Tip tip;
	char* simptome;
	bool pozitiv;
	static int nrTotalTeste;
	static int nrTestePozitive;
	static int nrTesteNegative;

public:
	TestCovid() {
		this->tip = PCR;
		this->simptome = NULL;
		this->pozitiv = 1;
		nrTotalTeste++;
		nrTestePozitive++;
	}

	TestCovid( Tip tip, const char* simptome, bool pozitiv) {
		this->tip = tip;
		this->simptome = new char[strlen(simptome) + 1];
		strcpy_s(this->simptome, strlen(simptome) + 1, simptome);
		nrTotalTeste++;
		if (this->pozitiv == 1) {
			nrTestePozitive++;
		}
		else
			if (this->pozitiv == 0) {
				nrTesteNegative++;
			}
	}

	static int getNrTotalTeste() {
		return nrTotalTeste;
	}

	static int getNrTestePozitive() {
		return nrTestePozitive;
	}

	char* getSimptome() {
		return simptome;
	}

	void setSimptome(const char* simptome) {
		if (simptome && strlen(simptome) > 3) {
			if (this->simptome) {
				delete[] this->simptome;
			}
			this->simptome = new char[strlen(simptome) + 1];
			strcpy_s(this->simptome, strlen(simptome) + 1, simptome);
		}
	}

	TestCovid(const TestCovid& test) {
		this->tip = test.tip;
		if (test.simptome != NULL) {
			this->simptome = new char[strlen(test.simptome) + 1];
			strcpy_s(this->simptome, strlen(test.simptome) + 1, test.simptome);
		}
		else {
			this->simptome = NULL;
		}
		this->pozitiv = test.pozitiv;
		nrTotalTeste++;
		if (test.pozitiv == 1) {
			nrTestePozitive++;
		}
		else
			if (test.pozitiv == 0) {
				nrTesteNegative++;
			}
	}

	const TestCovid& operator=(const TestCovid& test) {
		if (this != &test) {
			this->tip = test.tip;
			if (test.simptome != NULL) {
				if (this->simptome != NULL) {
					delete[] this->simptome;
				}
				this->simptome = new char[strlen(test.simptome) + 1];
				strcpy_s(this->simptome, strlen(test.simptome) + 1, test.simptome);
			}
			else {
				this->simptome = NULL;
			}
			this->pozitiv = test.pozitiv;
		}
		return *this;
	}

	~TestCovid() {
		if (this->simptome = NULL) {
			delete[] this->simptome;
		}
	}

	friend istream& operator>>(istream& citire, TestCovid& test) {
		char cuvant[21];

		citire >> cuvant;
		if (test.simptome != NULL) {
			delete[] test.simptome;
		}
		test.simptome = new char[strlen(cuvant) + 1];
		strcpy_s(test.simptome, strlen(cuvant) + 1, cuvant);
		citire>> test.pozitiv;
		return citire;
	}

	friend ostream& operator<<(ostream& afisare, TestCovid& test) {
		afisare << "Tipul testului: ";
		if (test.tip == 0)
			afisare << "PCR" << endl;
		else
			if (test.tip == 1)
				afisare << "test Rapid antigen"<<endl;
			else
				if (test.tip == 2)
					afisare << "test anticorpi Covid"<<endl;
		afisare << test.simptome << endl;
		afisare << test.pozitiv << endl;
		afisare << test.nrTotalTeste << endl;
		afisare << test.nrTestePozitive << endl;
		afisare << test.nrTesteNegative << endl;
		return afisare;
	}

};

 int TestCovid::nrTotalTeste = 0;
 int TestCovid::nrTestePozitive = 0;
 int TestCovid::nrTesteNegative = 0;


class Reteta {
private:
	string numeClient;
	string numeDoctor;
	float pretRetetaFaraCompensare;
	float pretRetetaCompensata;
	char* diagnostic;
	bool areCardSanatate;

public:
	Reteta() {
		this->numeClient = "Surdu David";
		this->numeDoctor = "Anghel Florin";
		this->pretRetetaFaraCompensare = 85.99f;
		this->pretRetetaCompensata = 56.5f;
		this->diagnostic = NULL;
		this->areCardSanatate = 1;
	}

	Reteta(string numeClient, string numeDoctor, float pretRetetaFaraCompensare, float pretRetetaCompensata, const char* diagnostic, bool areCardSanatate) {
		this->numeClient = numeClient;
		this->numeDoctor = numeDoctor;
		this->pretRetetaFaraCompensare = pretRetetaFaraCompensare;
		this->pretRetetaCompensata = pretRetetaCompensata;
		this->diagnostic = new char[strlen(diagnostic) + 1];
		strcpy_s(this->diagnostic, strlen(diagnostic) + 1, diagnostic);
		this->areCardSanatate = areCardSanatate;
	}

	Reteta(const Reteta& r) {
		this->numeClient = r.numeClient;
		this->numeDoctor = r.numeDoctor;
		this->pretRetetaFaraCompensare = r.pretRetetaFaraCompensare;
		this->pretRetetaCompensata = r.pretRetetaCompensata;
		if (r.diagnostic != NULL) {
			this->diagnostic = new char[strlen(r.diagnostic) + 1];
			strcpy_s(this->diagnostic, strlen(r.diagnostic) + 1, r.diagnostic);
		}
		else {
			this->diagnostic = NULL;
		}
		this->areCardSanatate = r.areCardSanatate;
	}

	const Reteta& operator=(const Reteta& reteta) {
		if (this != &reteta) {
			this->numeClient = reteta.numeClient;
			this->numeDoctor = reteta.numeDoctor;
			this->pretRetetaFaraCompensare = reteta.pretRetetaFaraCompensare;
			this->pretRetetaCompensata = reteta.pretRetetaCompensata;
			if (reteta.diagnostic != NULL) {
				if (this->diagnostic != NULL) {
					delete[] this->diagnostic;
				}
				this->diagnostic = new char[strlen(reteta.diagnostic) + 1];
				strcpy_s(this->diagnostic, strlen(reteta.diagnostic) + 1, reteta.diagnostic);
			}
			else {
				this->diagnostic = NULL;
			}
			this->areCardSanatate = reteta.areCardSanatate;
		}
		return *this;
	}

	float getPretRetetaFaraCompensare() {
		return pretRetetaFaraCompensare;
	}

	void setPretRetetaFaraCompensare(float modificarePretRetetaFaraCompensare) {
		if (modificarePretRetetaFaraCompensare > 0)
			pretRetetaFaraCompensare = modificarePretRetetaFaraCompensare;
	}

	float getPretRetetaCompensata() {
		return pretRetetaCompensata;
	}

	void setPretRetetaCompensata(float modificareRetetaCompensata) {
		if (modificareRetetaCompensata > 0)
			pretRetetaCompensata = modificareRetetaCompensata;
	}

	char* getDiagnostic() {
		return diagnostic;
	}

	void setDiagnostic(const char* diagnostic) {
		if (diagnostic && strlen(diagnostic) > 4) {
			if (this->diagnostic) {
				delete[] this->diagnostic;
			}
			this->diagnostic = new char[strlen(diagnostic) + 1];
			strcpy_s(this->diagnostic, strlen(diagnostic) + 1, diagnostic);
		}
	}

	~Reteta() {
		if (this->diagnostic != NULL) {
			delete[] this->diagnostic;
		}
	}

	friend istream& operator>>(istream& citire, Reteta& r) {
		char cuvant[21];
		citire >> r.numeClient;
		citire >> r.numeDoctor;
		citire >> r.pretRetetaCompensata;
		citire >> r.pretRetetaFaraCompensare;
		citire >> cuvant;
		if (r.diagnostic != NULL) {
			delete[] r.diagnostic;
		}
		r.diagnostic = new char[strlen(cuvant) + 1];
		strcpy_s(r.diagnostic, strlen(cuvant) + 1, cuvant);
		citire >> r.areCardSanatate;
		return citire;
	}

	friend ostream& operator<<(ostream& afisare, Reteta& r) {
		afisare << "Numele clientului: " << r.numeClient << endl;
		afisare << "Numele doctorului: " << r.numeDoctor << endl;
		afisare << "Pretul retetei comensate: " << r.pretRetetaCompensata << endl;
		afisare << "Pretul retetei necompensate: " << r.pretRetetaFaraCompensare << endl;
		afisare << "Diagnosticul: " << r.diagnostic << endl;
		afisare << "Are cardul de sanatate la el?" << (r.areCardSanatate ? "NU" : "DA");
		return afisare;
	}

};

class Marfa {
private:
	char* comerciant;
	int nrProduse;
	float* pret;
	bool comandaUrgenta;

public:
	Marfa() {
		this->comerciant = NULL;
		this->nrProduse = 4;
		this->pret = NULL;
		this->comandaUrgenta = 1;
	}

	Marfa(const char* comerciant, int nrProduse, float* pret, bool comandaUrgenta) {
		this->comerciant = new char[strlen(comerciant) + 1];
		strcpy_s(this->comerciant, strlen(comerciant) + 1, comerciant);
		this->nrProduse = nrProduse;
		this->pret = new float[nrProduse];
		for (int i = 0; i < nrProduse; i++) {
			this->pret[i] = pret[i];
		}
		this->comandaUrgenta=comandaUrgenta;
	}

	Marfa(const Marfa& marfa) {
		if (marfa.comerciant != NULL) {
			this->comerciant = new char[strlen(marfa.comerciant) + 1];
			strcpy_s(this->comerciant, strlen(marfa.comerciant) + 1, marfa.comerciant);
		}
		else {
			this->comerciant = NULL;
		}
		this->nrProduse = marfa.nrProduse;
		if (marfa.pret != NULL) {
			this->pret = new float[marfa.nrProduse];
			for (int i = 0; i < marfa.nrProduse; i++) {
				this->pret[i] = marfa.pret[i];
			}
		}
		else {
			this->pret = NULL;
		}
		this->comandaUrgenta = marfa.comandaUrgenta;
	}

	const Marfa& operator=(const Marfa& marfa) {
		if (this != &marfa) {
			if (marfa.comerciant != NULL) {
				if (this->comerciant != NULL) {
					delete[]this->comerciant;
				}
				this->comerciant = new char[strlen(marfa.comerciant) + 1];
				strcpy_s(this->comerciant, strlen(marfa.comerciant) + 1, marfa.comerciant);
			}
			else {
				this->comerciant = NULL;
			}
			this->nrProduse = marfa.nrProduse;
			if (marfa.pret != NULL) {
				if (this->pret != NULL) {
					delete[] this->pret;
				}
				this->pret = new float[marfa.nrProduse];
				for (int i = 0; i < marfa.nrProduse; i++) {
					this->pret[i] = marfa.pret[i];
				}
			}
			else {
				this->pret = NULL;
			}
			this->comandaUrgenta = marfa.comandaUrgenta;
		}
		return *this;
	}

	int getComandaUrgenta() {
		return this->comandaUrgenta;
	}

	void setComandaUrgenta(bool comUrg) {
		if (comUrg == 1 || comUrg == 0) {
			this->comandaUrgenta = comUrg;
		}
	}


	char* getComerciant() {
		return comerciant;
	}

	void setComerciant(const char* comerciant) {
		if (comerciant && strlen(comerciant) > 2) {
			if (this->comerciant) {
				delete[] this->comerciant;
			}
			this->comerciant = new char[strlen(comerciant) + 1];
			strcpy_s(this->comerciant, strlen(comerciant) + 1, comerciant);
		}
	}

	~Marfa() {
		if (this->pret!= NULL) {
			delete[] this->pret;
		}
	}

	friend istream& operator>>(istream& citire, Marfa& m) {
		char cuvant[21];
		citire >> cuvant;
		if (m.comerciant != NULL) {
			delete[] m.comerciant;
		}
		m.comerciant = new char[strlen(cuvant) + 1];
		strcpy_s(m.comerciant, strlen(cuvant) + 1, cuvant);
		citire >> m.nrProduse;
		if (m.pret != NULL) {
			delete[] m.pret;
		}
		m.pret = new float[m.nrProduse];
		for (int i = 0; i < m.nrProduse; i++) {
			citire >> m.pret[i];
		}
		citire >> m.comandaUrgenta;
		return citire;
	}

	friend ostream& operator<<(ostream& afisare, const Marfa& m) {
		afisare << "Numele comerciantului: " <<m.comerciant<< endl;
		afisare << "Numarul produselor comandate: " <<m.nrProduse << endl;
		for (int i = 0; i < m.nrProduse; i++) {
			afisare << "Pretul produsului" << i + 1 << ":" << m.pret[i] << endl;;
		}
		afisare << "Este o comanda care trebuie livrata de urgenta? " << (m.comandaUrgenta ? "NU" : "DA") << endl;;
		return afisare;
	}
};


void main() {

	//CLASA ANGAJAT:
	Angajat ang1("Ciobanu Gabriel", 5040577092231, 2300, false, "casier");
	Angajat ang2;
	Angajat ang3;
	cout << ang1.getNumePrenume() << endl;
	cout << ang1.getSalariuNet() << endl;
	ang1.setSalariuNet(2600);
	cout << ang1.getSalariuNet() << endl;
	ang2 = ang1;
	cout << ang2.getSalariuNet() << endl;
	cin >> ang3;
	cout << ang3;

	//CLASA MEDICAMENT:
	Medicament med1("Nurofen", 20.5f, 0, 2023, "de 2 ori pe zi");
	Medicament med2;
	Medicament med3;
	cout << med1.getDescriereAdministrare() << endl;
	cout << med1.getTVA() << endl;
	med1.setDescriereAdministrare("una la 8 ore");
	cout << med1.getDescriereAdministrare() << endl;
	med2 = med1;
	cout << med2.getDescriereAdministrare() << endl;
	cin >> med3;
	cout << med3;
	

	//CLASA TESTCOVID:
	TestCovid test1(PCR, "tuse, fara miros", 1);
	TestCovid test2;
	TestCovid test3;
	cout << test1.getSimptome() << endl;
	cout << test1.getNrTestePozitive() << endl;
	test1.setSimptome("fara gust si fara miros");
	cout << test1.getSimptome()<<endl;
	test2 = test1;
	cout << test2.getSimptome()<<endl;
	cin >> test3;
	cout << test2;

	//CLASA RETETA:
	Reteta r1("Vlasceanu Elena", "Toma Andreea", 105.6f, 89.5f, "Gripa sezoniera", 1);
	Reteta r2;
	Reteta r3;
	cout << r1.getDiagnostic() << endl;
	cout << r1.getPretRetetaCompensata() << endl;
	r1.setPretRetetaCompensata(87.7f);
	cout << r1.getPretRetetaCompensata() << endl;
	r2 = r1;
	cout << r2.getPretRetetaFaraCompensare() << endl;
	cin >> r3;
	cout << r2;

	//CLASA MARFA:
	Marfa m1("Pfizer", 3, new float[3]{ 20.5, 18, 32.5 }, 0);
	Marfa m2;
	Marfa m3;
	cout << m1.getComerciant() << endl;
	cout << m1.getComandaUrgenta() << endl;
	m1.setComandaUrgenta(1);
	cout << m1.getComandaUrgenta() << endl;
	m2 = m1;
	cout << m2.getComerciant() << endl;
	cin >> m3;
	cout << m2;
}
