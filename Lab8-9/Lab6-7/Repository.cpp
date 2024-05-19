#include "Repository.h"

// Fnctie pentru adagare activitate in repo
void Repository::adaugaActivitate(const Activitate& activitate) {
	if (exist(activitate)) { throw ActivitateRepoException("Activitatea exista deja!\n\n"); }
	repositoryList.push_back(activitate);
}

// Functie pentr returnare toate elementele din repo
const std::vector <Activitate>& Repository::getAll() const noexcept {
	return repositoryList;
}

// Functie pentru stergere activitate
void Repository::stergeActivitate(const Activitate& activitate) {
	if (!exist(activitate)) { throw ActivitateRepoException("Activitatea NU exista!\n\n"); }

	auto it = find_if(repositoryList.begin(), repositoryList.end(), [&activitate](const Activitate& el) {return el == activitate; });
	repositoryList.erase(it);
}

// unctie pentru update activitate
void Repository::modificaActivitate(const Activitate& activitate) {
	if (!exist(activitate)) { throw ActivitateRepoException("Activitatea NU exista!\n\n"); }

	auto it = find_if(repositoryList.begin(), repositoryList.end(), [&activitate](const Activitate& el) {return el == activitate; });
	*it = activitate;
}

// Functie cautare activitate in repo dupa id
const Activitate Repository::find(const Activitate& activitate) const {
	auto it = find_if(repositoryList.begin(), repositoryList.end(), [&activitate](const Activitate& el) {return el.getId() == activitate.getId(); });
	if (it == repositoryList.end())
		throw ActivitateRepoException("Nu exista activitatea cu acest Id!\n\n");
	return *it;
}

// Functie catare activitate in repo dupa titlu
const Activitate Repository::find_by_title(const Activitate& activitate) const {
	auto it = find_if(repositoryList.begin(), repositoryList.end(), [&activitate](const Activitate& el) {return el.getTitlu() == activitate.getTitlu(); });
	if (it == repositoryList.end())
		throw ActivitateRepoException("Nu exista activitatea acest Titlul\n\n");
	return *it;
}

// Functie verificare daca o activitate exista in repo
bool Repository::exist(const Activitate& activitate) {
	try {
		find(activitate);
		return true;
	}
	catch (ActivitateRepoException&) { return false; }
}

//suprascriere operator <<
ostream& operator<<(ostream& out, const ActivitateRepoException& ex) {
	out << ex.msg;
	return out;
}

