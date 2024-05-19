#pragma once
#include "Repository.h"
#include <random>
#include <chrono>
#include <fstream>
#include <Windows.h>
#include <shellapi.h>

using namespace std;
class Cos {
protected:
	vector <Activitate> listaActivitati;
	Repository& repo;

public:
	Cos(Repository& r) :repo{ r } {};
	void adaugaLista(const string& nr);
	void golireLista() noexcept;
	void adaugaRandomLista(const unsigned& nr);
	const int dimLista() const noexcept;
	const vector <Activitate>& getListaActivitati()const noexcept;
	const Activitate& cautaLista(const Activitate& activitate);
	virtual void scrie_in_fisier() = 0;
	virtual void deschide_fisier() = 0;
	~Cos() = default;
};

class ListaActivitatiException {
	string mesaj;
public:
	ListaActivitatiException(string m) : mesaj{ m } {}
	friend ostream& operator<<(ostream& out, const ListaActivitatiException& ex);
};

ostream& operator<<(ostream& out, const ListaActivitatiException& ex);
