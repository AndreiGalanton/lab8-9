#include "RepositoryFile.h"
#include <fstream>
using namespace std;
//ifstream in("input.txt");
//ofstream out("output.txt");

void RepositoryFile::loadData() {
	ifstream in(fisier_in);
	string titlu, descriere, tip;
	int id, durata;
	if (!in.is_open())
		throw ActivitateRepoException("Fisierul nu a putut fi deschis pentru citire!");

	while (in >> id >> titlu >> descriere >> durata >> tip) {
		Activitate activitate = Activitate(id, titlu, descriere, durata, tip);
		repositoryList.push_back(activitate);
	}
	in.close();
}
void RepositoryFile::saveData() {
	ofstream out(fisier_out);
	for (auto e : repositoryList) {
		out << e.getId() << " " << e.getTitlu() << " " << e.getDescriere() << " " << e.getDurata() << " " << e.getTip() << endl;
	}
	out.close();
}
