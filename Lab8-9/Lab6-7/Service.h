#pragma once

#include "Repository.h"
#include "Validator.h"
#include "Undo.h"
#include <functional>

typedef bool(*functie) (const Activitate&, const Activitate&);

class Service {
	Repository& repository;
	ActivitateValidator& validator;
	vector<unique_ptr<ActiuneUndo>> undoActions;

	/*Functie care filtreaza dupa o functie data*/
	std::vector <Activitate> filtreaza(std::function <bool(const Activitate&)> functie) const;

	/*Functie care sorteaza dupa o functie data*/
	std::vector <Activitate> sorteaza(functie f) const;

public:
	Service(Repository& repository, ActivitateValidator validator) noexcept : repository{ repository }, validator{ validator } {};
	Service(const Service& 
	) = delete;

	void adaugaActivitateService(const Activitate& activitate);

	const std::vector <Activitate>& getAllService() const noexcept;

	void stergeActivitateService(const int& id);

	void modificaActivitateService(const Activitate& activitate);

	std::vector <Activitate> filtreazaDupaDescriere(const std::string titlu) const;

	std::vector <Activitate> filtreazaDupaTip(const std::string tip) const;

	std::vector <Activitate> sorteazaDupaTitlu() const;

	std::vector <Activitate> sorteazaDupaDescriere() const;

	std::vector <Activitate> sorteazaDupaTipDurata() const;

	void undo();
	
};

