#pragma once
#include "Activitate.h"
#include "Repository.h"
class ActiuneUndo {
public:
	virtual void doUndo() = 0;
	virtual ~ActiuneUndo() = default;
};

class UndoAdauga : public ActiuneUndo {
	Activitate activitateAdaugata;
	Repository& repo;
public:
	UndoAdauga(Repository& r, const  Activitate& activitate) :repo{ r }, activitateAdaugata{ activitate } {}
	void doUndo() override {
		repo.stergeActivitate(activitateAdaugata);
	}
};

class UndoSterge : public ActiuneUndo {
	Activitate activitateStearsa;
	Repository& repo;
public:
	UndoSterge(Repository& rep, const  Activitate& m) :repo{ rep }, activitateStearsa{ m } {}
	void doUndo() override {
		repo.adaugaActivitate(activitateStearsa);
	}
};

class UndoActualizare : public ActiuneUndo {
	Activitate activitateActualizata;
	Repository& repo;
public:
	UndoActualizare(Repository& rep, const  Activitate& m_a) :repo{ rep }, activitateActualizata{ m_a } {}
	void doUndo() override {
		repo.modificaActivitate(activitateActualizata);
	}
};