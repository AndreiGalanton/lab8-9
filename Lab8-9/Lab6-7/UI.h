#pragma once

#include "Service.h"
#include "Cos.h"
#include "Repository.h"
#include <iostream>

class UI {
	Service &service;
	Cos &lista;

	// Functie pentru printarea activitatilor din repo
	void printeaza(const std::vector <Activitate>& activitati) const;

	// Fnctie pentr printarea listei de activitati (Cos)
	void printeazaLista();

public:
	UI(Service &service, Cos &l) noexcept : service{ service }, lista{ l } {};
	UI(const UI& ui) = delete;

	void start();

};

