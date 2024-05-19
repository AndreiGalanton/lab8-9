#include "Cos.h"
#include "RepositoryFile.h"
using namespace std;

const Activitate& Cos::cautaLista(const Activitate& activitate) {
	auto it = find_if(listaActivitati.begin(), listaActivitati.end(), [&activitate](const Activitate& el) {return el == activitate; });
	if (it == listaActivitati.end())
		throw ListaActivitatiException("Nu exista activitatea!\n");
	return *it;
}

//adauga activitate in lista de activitati
void Cos::adaugaLista(const string& titlu) {
	Activitate activitate_fake(1, titlu, "fake", 1, "fake");
	Activitate activitate = repo.find_by_title(activitate_fake);

	try {
		cautaLista(activitate);

	}
	catch (ListaActivitatiException&) {
		listaActivitati.push_back(activitate);
	}
}

//goleste lista de activitati
void Cos::golireLista() noexcept {
	listaActivitati.clear();
}

//adauga activitati random in lista de activitati
void Cos::adaugaRandomLista(const unsigned& nr) {
	if (repo.getAll().size() - dimLista() < nr) throw ListaActivitatiException("Nu exista atatea activitati.\n");
	if (nr == 0) throw ListaActivitatiException("Dati un numar strict pozitiv.\n");
	//Activitate activitate;
	vector<Activitate> list = repo.getAll();
	unsigned i = 0;
	while (i < nr) {
		//auto seed = chrono::system_clock::now().time_since_epoch().count();
		//shuffle(list.begin(), list.end(), default_random_engine(seed));
		//m = Activitate(list.at(0));
		Activitate activitate = Activitate(list.at(rand() % list.size()));
		try {
			cautaLista(activitate); continue;
		}
		catch (ListaActivitatiException&) {
			listaActivitati.push_back(activitate);
			i++;
		}
	}
}

//getter dimensiune lista de activitati
const int Cos::dimLista() const noexcept {
	return static_cast<int>(listaActivitati.size());
}

//getter lista de activitati
const vector<Activitate>& Cos::getListaActivitati() const noexcept {
	return listaActivitati;
}

//suprascriere operator <<
ostream& operator<<(ostream& out, const ListaActivitatiException& ex) {
	out << ex.mesaj;
	return out;
}

