#pragma once
#include "Cos.h"
class HTML_Cos :public Cos {
public:
	HTML_Cos(Repository& r) :Cos{ r } {};
	void scrie_in_fisier() override {
		std::ofstream fout("Cos.html");

		std::string rez = "<!DOCTYPE html>\n";
		rez += "<html>\n";
		rez += "<head>\n";
		rez += "<title>Lista de activitati</title>\n";
		rez += "</head>\n";
		rez += "<body>\n";
		rez += "<table border=\"1\">\n";
		rez += "<tr>\n";
		rez += "<td>Id</td>\n";
		rez += "<td>Titlu</td>\n";
		rez += "<td>Descriere</td>\n";
		rez += "<td>Durata</td>\n";
		rez += "<td>Tip</td>\n";
		rez += "</tr>\n";

		for (auto el : listaActivitati) {
			rez += "<tr>\n";
			rez += "<td>" + std::to_string(el.getId()) + "</td>\n";
			rez += "<td>" + el.getTitlu() + "</td>\n";
			rez += "<td>" + el.getDescriere() + "</td>\n";
			rez += "<td>" + std::to_string(el.getDurata()) + "</td>\n";
			rez += "<td>" + el.getTip() + "</td>\n";
			rez += "</tr>\n";
		}

		rez += "</table>";
		rez += "</body>\n";
		rez += "</html>\n";

		fout << rez;
	}
	void deschide_fisier() override {
		this->scrie_in_fisier();
		//ShellExecuteA(NULL, NULL, "firefox.exe", "Cos.html", NULL, SW_SHOWMAXIMIZED);
	}
	~HTML_Cos() = default;
};
