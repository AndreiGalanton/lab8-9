#pragma once
#include "Activitate.h"
#include <vector>

class Repository {
protected:
	vector<Activitate> repositoryList;
public:
	Repository() = default;
	Repository(const Repository& repository) = delete;

	void adaugaActivitate(const Activitate& activitate);

	void modificaActivitate(const Activitate& activitate);

	const vector<Activitate>& getAll() const noexcept;

	void stergeActivitate(const Activitate& activitate);

	const Activitate find(const Activitate& activitate) const;

	const Activitate find_by_title(const Activitate& activitate) const;

	bool exist(const Activitate& activitate);

	// functii pr virtuale ce vor fi imeplementate ulterior
	virtual void loadData() = 0;

	virtual void saveData() = 0;

	~Repository() = default;
};

class ActivitateRepoException {
	string msg;
public:
	ActivitateRepoException(string m) :msg{ m } {}
	friend ostream& operator<<(ostream& out, const ActivitateRepoException& ex);
	string getMsg() {
		return msg;
	}
};

ostream& operator<<(ostream& out, const ActivitateRepoException& ex);

