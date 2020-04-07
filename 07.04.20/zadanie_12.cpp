#include <algorithm>
#include <iostream>
#include <vector>

enum class TypRosliny { Owoc, Warzywo };

struct Roslina {
	TypRosliny typ;
	std::string nazwa;
	Roslina() { typ = TypRosliny::Warzywo; nazwa = "warzywo"; }
	Roslina(TypRosliny t, std::string n) { typ = t; nazwa = n; }
};

using Koszyk = std::vector<Roslina>;

Koszyk koszyk = { {TypRosliny::Owoc, "Banan"} };

std::ostream& operator<<(std::ostream& out, const Roslina& roslina)
{
	if (roslina.typ == TypRosliny::Owoc) out << "Owoc: " << roslina.nazwa;
	else out << "Warzywo: " << roslina.nazwa;
	return out;
}

std::ostream& operator<<(std::ostream& out, const Koszyk& koszyk)
{
	for (auto r : koszyk)
	{
		out << r << std::endl;
	}
	return  out;
}

void usun_zaczynajace_sie_od(Koszyk& koszyk, char l)
{
	koszyk.erase(std::remove_if(koszyk.begin(), koszyk.end(), [l](Roslina roslina) {return tolower(roslina.nazwa[0]) == l; }),koszyk.end());
}


int main()
{
	Roslina pomidor;
	pomidor.typ = TypRosliny::Owoc;
	pomidor.nazwa = "Pomidor";
	koszyk.push_back(pomidor);

	Roslina granat(TypRosliny::Owoc, "Granat");
	koszyk.emplace_back(granat);

	Roslina burak(TypRosliny::Warzywo, "Burak");
	koszyk.emplace_back(burak);

	Roslina gruszka(TypRosliny::Owoc, "Gruszka");
	koszyk.emplace_back(gruszka);

	std::cout << koszyk;
	std::cout << "***Marta ukradla owoce***" << std::endl;
	usun_zaczynajace_sie_od(koszyk, 'g');
	std::cout << koszyk;

	return 0;
};